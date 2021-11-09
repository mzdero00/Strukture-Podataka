#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAXS (50)
#define MAXL (1024)

struct _polinom;
typedef struct _polinom* Position;
typedef struct _polinom
{
	int koef;
	int expo;
	Position next;
}polinom;

int ImeDatoteke(char* imedatoteke);
int ProcitajDatoteku(Position head1 ,Position head2 ,char* imedatoteke);
int StringUListu(Position head,char* buffer);
int IzbrisiIza(Position previous);
int DodajIza(Position previous,Position Novi_Element);
int DodajSortirano(Position head, Position Novi_Element);
int SpojiIza(Position previous, Position Novi_Element);
Position CreateElement(int koef, int expo);
int IspisiPolinom(char* ime, Position first);
int KreirajIDodajiza(int koef,int expo, Position previous);
int ZbrojiPolinom(Position rez,Position head1, Position head2);
int PomnoziPolinom(Position rez,Position head1, Position head2);
int OslobodiMemoriju(Position head);
int main()
{
	polinom head1={.koef=0, .expo=0, .next=NULL};
	polinom head2={.koef=0, .expo=0, .next=NULL};
	polinom DodajRez={.koef=0, .expo=0, .next=NULL};
	polinom MnoziRez={.koef=0, .expo=0, .next=NULL};
	char imedatoteke[MAXS]={0};
	
	ImeDatoteke(imedatoteke);
	if(ProcitajDatoteku(&head1,&head2,imedatoteke)==EXIT_SUCCESS)
	{
		IspisiPolinom("p1",head1.next);
		IspisiPolinom("p2",head2.next);
		
		ZbrojiPolinom(&DodajRez,&head1,&head2);
		PomnoziPolinom(&MnoziRez,&head1,&head2);
		IspisiPolinom("pAdd",DodajRez.next);
		IspisiPolinom("pMult",MnoziRez.next);
		
		FreeMemory(&head1);
		FreeMemory(&head2);
		FreeMemory(&DodajRez);
		FreeMemory(&MnoziRez);		
	}
	return 0;
}

int ImeDatoteke(char* imedatoteke)
{
	printf("Unesi ime datoteke ---->\n");
	scanf(" %s",imedatoteke);
	return EXIT_SUCCESS;
}
int ProcitajDatoteku(Position head1 ,Position head2 ,char* imedatoteke)
{
	FILE* file=NULL;
	char buffer[MAXL]={0};
	int status=EXIT_SUCCESS;
	
	file=fopen(imedatoteke,"r");
	if(!file)
		{
			perror("Datoteka nije uspjesno otvorena!\n");
			return -1;
		}
	fgets(buffer,MAXL,file);
	status=StringUListu(head2,buffer);
	if (status !=EXIT_SUCCESS)
	{
		return EXIT_FAILURE;
	}
	fclose(file);
	
	return EXIT_SUCCESS;
}
int StringUListu(Position head,char* buffer)
{
	char* tempbuffer=buffer;
	int koef=0;
	int expo=0;
	int byte=0;
	int status=0;
	Position Novi_Element=NULL;
	
	while(strlen(tempbuffer)>0)
	{
		status=sscanf(tempbuffer," %d %d %n",&koef,&expo,&byte);
		if (status!=2)
		{
			printf("Podaci u datoteci nisu zapisani u dobrom formatu!\n");
			return EXIT_FAILURE;
		}
		Novi_Element=CreateElement(koef,expo);
		if(!Novi_Element)
		{
			return EXIT_FAILURE;
		}
		UnesiSortirano(head,Novi_Element);
		tempbuffer=tempbuffer+byte;
	}
	return EXIT_SUCCESS;
}
int IzbrisiIza(Position previous)
{
	Position zaIzbrisati=NULL;
	
	zaIzbrisati=previous->next;
	previous->next=zaIzbrisati->next;
	free(zaIzbrisati);
	
	return EXIT_SUCCESS;
}
int DodajIza(Position position,Position Novi_Element)
{
	Novi_Element->next=position->next;
	position->next=Novi_Element;
	
	return EXIT_SUCCESS;
}
int DodajSortirano(Position head, Position Novi_Element)
{
	Position temp=head;
	while(temp->next!=NULL && temp->next->expo < Novi_Element->expo)
	{
		temp=temp->next;
	}
	
	SpojiIza(temp,Novi_Element);
	
	return EXIT_SUCCESS;
}
int SpojiIza(Position position, Position Novi_Element)
{
	if(position->next == NULL || position->next->expo != Novi_Element->expo)
	{
		InsertAfter(position, Novi_Element);
	}
	else
	{
		int rezKoef=position->next->koef + Novi_Element->koef;
		if (rezKoef == 0)
		{
			IzbrisiIza(position);
		}
		else
		{
			position->next->koef = rezKoef;
		}
		free(Novi_Element);
	}
	return EXIT_SUCCESS;
}
Position CreateElement(int koef, int expo)
{
	Position polinom = NULL;
	polinom = (Position)malloc(sizeof(polinom));
	if(!polinom)
	{
		perror("Memorija nije alocirana!\n");
		return polinom;
	}
	polinom->koef=koef;
	polinom->expo=expo;
	polinom->next=NULL;
	
	return polinom;
}
int IspisiPolinom(char* ime, Position first)
{
	printf(" %s = ",ime);
	if (first)
		{
			if(first->expo < 0)
				{
					if(first->koef==1)
					{
						printf("x^(%d)",first->expo);
					}
					else
					{
						printf("%dx^(%d)",first->koef,first->expo);
					}
					
				}
			else
			{
				if(first->koef==1)
				{
					printf("x^%d",first->expo);
				}
				else
				{
					printf("%dx^%d", first->koef,first->expo);
				}
			}
		first=first->next;
		}
	for(;first!=NULL;first=first->next)
	{
		if(first->koef < 0)
		{
			if(first->expo < 0)
			{
				printf("- %dx^(%d)",abs(first->koef),first->expo);
			}
			else
			{
				printf("- %dx^(%d)",abs(first->koef),first->expo);
			}
		}
		else
		{
			if(first->expo < 0)
			{
				if(first->koef==1)
				{
					pritnf("+ x^(%d)",first->expo);
				}
				else
				{
					printf("+ %dx^(%d)",first->koef,first->expo);
				}
			}
		}
	}
	printf("\n");
	return EXIT_SUCCESS;
}
int KreirajIDodajiza(int koef,int expo, Position position)
{
	Position Novi_Element=CreateElement(koef,expo);
	if(!Novi_Element)
	{
		return EXIT_FAILURE;
	}
	DodajIza(position,Novi_Element);
	position=position->next;
	return EXIT_SUCCESS;
}
int ZbrojiPolinom(Position rez,Position head1, Position head2)
{
	Position i= head1->next;
	Position j=head2->next;
	Position k=rez;
	Position temp= NULL;
	
	while(i!=NULL&&j!=NULL)
	{
		if(i->expo==j->expo)
		{
			KreirajIDodajIza(i->koef + j->koef,i->expo,k);
			i=i->next;
			j=j->next;
		}
		else if(i->expo < j->expo)
		{
			KreirajIDodajIza(i->koef,i->expo,k);
			i=i->next;
		}
		else
		{
			KreirajIDodajIza(j->koef,j->expo,k);
			j=j->next;
		}
		
	}

	if(i==NULL)
	{
		temp=j;
	}
	else
	{
		temp=i;
	}
	while(temp!=NULL)
	{
		KreirajIDodajIza(temp->koef,temp->expo,k);
		temp=temp->next;
	}
	return EXIT_SUCCESS;
}
int PomnoziPolinom(Position rez,Position head1, Position head2)
{
	Position i= NULL;
	Position j=NULL;
	
	for(i=head1->next;i!=NULL;i->next);
	{
		for(j=head2->next;j!=NULL;j->next)
		{
			Position Novi_Element =CreateElement(i->koef * j->koef, i->expo);
			if(!Novi_Element)
			{
				return EXIT_FAILURE;
			}
			UnesiSortirano(rez,Novi_Element);
		}
		return EXIT_SUCCESS;
	}
}
int OslobodiMemoriju(Position head)
{
	Position temp= head;
	while(temp->next)
	{
		IzbrisiIza(temp);
	}
	return EXIT_SUCCESS;
}
 
