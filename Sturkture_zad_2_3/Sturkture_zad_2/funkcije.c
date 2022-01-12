#define _CRT_SECURE_NO_WARNINGS
#include "funkcije.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int menu(Position head)
{
	int n = 0;
	Position p = head;
	printf("\n\n\nOdaberite opciju : \t\n");
	printf("\n Dodaj element na pocetak :::::: 1\nIspisi listu :::::: 2\nElement na kraj :::::: 3\nNadi element u listi :::::: 4\nIzbrisi element iz liste :::::: 5");
	printf("\n Dodaj element iza odredenog :::::: 6\nDodaj element ispred odredenog :::::: 7\nSortirani unos :::::: 8\nUpisati listu u datoteku :::::: 9\nIspisati listu iz datoteke ::::: 10\n--------------");
	printf("\n Izadi iz programa ::::: 0\n ------------");


	scanf("%d", &n);
	

	switch (n)
	{
		case 1:
			system("cls");
			elementNaPocetak(head);
			menu(head);
			break;
		
		case 2:
			system("cls");
			ispisiListu(head);
			menu(head);
			break;
		
		case 3:
			system("cls");
			elementNaKraj(head);
			menu(head);
			break;

		case 4:
			system("cls");
			p = nadiElement(head);
			ispisiElement(p);
			menu(head);
			break;

		case 5:
			system("cls");
			izbrisiElement(head);
			menu(head);
			break;

		case 6:
			system("cls");
			dodatiIzaOdredenog(head);
			menu(head);
			break;

		case 7:
			system("cls");
			dodatiIspredOdredenog(head);
			menu(head);
			break;

		case 8:
			system("cls");
			sortiraniUnos(head);
			menu(head);
			break;

		case 9:
			system("cls");
			datotekaUpis(head);
			menu(head);
			break;

		case 10:
			system("cls");
			datotekaIspis(head);
			menu(head);
			break;

		case 0:
			system("cls");
			break;

	}
}

Position stvoriElement(char* Ime,char* Prezime,int Godina)
{
	Position q = NULL;
	
	q = (Position)malloc(sizeof(osoba));


	strcpy(q->ime, Ime);
	strcpy(q->prezime, Prezime);
	q->godinaRodjenja = Godina;

	q->next = NULL;

	return q;
}

int elementNaPocetak(Position head)
{
	Position q = NULL;
	Position temp = NULL;
	char buffer_ime[20];
	char buffer_prezime[20];
	int buffer_godinaRodjenja = 0;

	printf("\n Unesite ime:");
	scanf(" %s", buffer_ime);
	printf("\n Unesite prezime:");
	scanf(" %s", buffer_prezime);
	printf("\n Unesite godinu rodjenja:");
	scanf("%d", &buffer_godinaRodjenja);

	q = stvoriElement(buffer_ime, buffer_prezime, buffer_godinaRodjenja);

	temp = head->next;
	head->next = q;
	q->next = temp;

	system("cls");

	return 0;
}


int ispisiListu(Position head)
{
	Position q = head->next;
	while ( q!= NULL)
	{
		printf("\n %s %s %d \n-------------\n", q->ime, q->prezime, q->godinaRodjenja);
		q = q->next;
	}

	return 0;
}

int ispisiElement(Position el)
{
	printf("\n %s %s %d\n--------", el->ime, el->prezime, el->godinaRodjenja);

	return 0;

}

int elementNaKraj(Position head)
{
	Position q = NULL;
	Position temp = NULL;
	Position p = head;
	char buffer_ime[20];
	char buffer_prezime[20];
	int buffer_godinaRodjenja = 0;

	printf("\n Unesite ime:");
	scanf(" %s", buffer_ime);
	printf("\n Unesite prezime:");
	scanf(" %s", buffer_prezime);
	printf("\n Unesite godinu rodjenja:");
	scanf("%d", &buffer_godinaRodjenja);

	q = stvoriElement(buffer_ime, buffer_prezime, buffer_godinaRodjenja);

	while (p->next != NULL)
	{
		p = p->next;
	}

	p->next = q;
	q->next = NULL;

	system("cls");
	
	return 0;
}

Position nadiElement(Position head)
{
	Position p = head;
	char buffer_prezime[20];


	printf("\n Unesite prezime :");
	scanf(" %s", buffer_prezime);

	while (strcmp(p->prezime, buffer_prezime) != 0)
	{
		p = p->next;
	}


	return p;
}

int izbrisiElement(Position head)
{
	Position p = head;
	Position temp = NULL;
	char buffer_prezime[20];

	printf("\n---------\n Unesite prezime covjeka kojeg zelite izbrisati: ");
	scanf(" %s", buffer_prezime);

	while (strcmp(p->next->prezime, buffer_prezime) != 0)
	{
		p = p->next;
	}

	temp = p->next;
	p->next = temp->next;
	
	free(temp);

	return 0;

}

int dodatiIzaOdredenog(Position head)
{
	Position p = head;
	Position q = NULL;
	Position temp = NULL;
	char buffer_ime[20];
	char buffer_prezime[20];
	char buffer_prezime1[20];
	int buffer_godinaRodjenja;


	printf("\n Unesite prezime iza kojeg zelite unijeti element:\n-------------");
	scanf(" %s",buffer_prezime);


	printf("\n Unesite ime:");
	scanf(" %s", buffer_ime);
	printf("\n Unesite prezime:");
	scanf(" %s", buffer_prezime1);
	printf("\n Unesite godinu rodjenja:");
	scanf("%d", &buffer_godinaRodjenja);

	q = stvoriElement(buffer_ime, buffer_prezime1, buffer_godinaRodjenja);

	while (strcmp(p->prezime, buffer_prezime) != 0)
	{
		p = p->next;
	}

	temp = p->next;
	p->next = q;
	q->next = temp;

	return 0;
}


int dodatiIspredOdredenog(Position head)
{
	Position p = head;
	Position q = NULL;
	Position temp = NULL;
	char buffer_ime[20];
	char buffer_prezime[20];
	char buffer_prezime1[20];
	int buffer_godinaRodjenja;


	printf("\n Unesite prezime iza kojeg zelite unijeti element:\n-------------");
	scanf(" %s", buffer_prezime);


	printf("\n Unesite ime:");
	scanf(" %s", buffer_ime);
	printf("\n Unesite prezime:");
	scanf(" %s", buffer_prezime1);
	printf("\n Unesite godinu rodjenja:");
	scanf("%d", &buffer_godinaRodjenja);
	q = stvoriElement(buffer_ime, buffer_prezime1, buffer_godinaRodjenja);

	while (strcmp(p->next->prezime, buffer_prezime) != 0)
	{
		p = p->next;
	}

	temp = p->next;
	p->next = q;
	q->next = temp;

	return 0;
}

int sortiraniUnos(Position head)
{
	Position p = head;
	Position q = NULL;
	Position temp = NULL;
	char buffer_ime[20];
	char buffer_prezime[20];
	int buffer_godinaRodjenja;

	printf("\n-----------\n Unesite podatke osobe koju zelite dodati u listu:\n");

	printf("\n Unesite ime:");
	scanf(" %s", buffer_ime);

	printf("\n Unesite prezime:");
	scanf(" %s", buffer_prezime);

	printf("\n Unesite godinu rodjenja:");
	scanf("%d", &buffer_godinaRodjenja);

	q = stvoriElement(buffer_ime, buffer_prezime, buffer_godinaRodjenja);

	while (p!= NULL)
	{
		if (p->next == NULL)
		{
			temp = p->next;
			p->next = q;
			q->next = temp;
			return 0;
		}
		else if (strcmp(p->next->prezime, buffer_prezime) < 0)
		{
			p = p->next;
		}

		else {
			temp = p->next;
			p->next = q;
			q->next = temp;
			return 0;
		}
	}

	return 0;

}

int datotekaUpis(Position head)
{
	Position p = head->next;
	char buffer_imedatoteke[30] = {' '};
	FILE* datoteka = NULL;


	printf("\n\n Unesite zeljeno ime datoteke:   ");
	scanf(" %s", buffer_imedatoteke);

	datoteka = fopen(buffer_imedatoteke, "w");

	while (p!=NULL)
	{
		fprintf(datoteka, "\n\t %s %s %d\n", p->ime, p->prezime, p->godinaRodjenja);
		p = p->next;

	}
	
	fclose(datoteka);

	return 0;
}

int datotekaIspis(Position head)
{
	FILE* datoteka = NULL;
	int br = 0,i=0;
	char buffer_ime[30] = {' '};
	char buffer_prezime[30] = {' '};
	int buffer_godinaRodjenja=0;
	char buffer_imedatoteke[30] = {' '};
	char* buffer_redak = NULL;
	Position temp = NULL;
	Position p = head->next;
	Position q = NULL;

	printf("\n\n  Unesite ime datoteke:  ");
	scanf(" %s", buffer_imedatoteke);

	datoteka = fopen(buffer_imedatoteke, "r");

	while (!feof(datoteka))
	{
		if (fgetc(datoteka) == '\n')
			br++;
	}

	rewind(datoteka);

	q = (Position)malloc(sizeof(osoba)*br);

	for (i = 0; i < br; i++)
	{
		fscanf(datoteka, " %s %s %d", buffer_ime, buffer_prezime, &buffer_godinaRodjenja);

			q = stvoriElement(buffer_ime, buffer_prezime, buffer_godinaRodjenja);

			while (p != NULL)
			{
				if (p->next == NULL)
				{
					temp = p->next;
					p->next = q;
					q->next = temp;
					return 0;
				}
				else if (strcmp(p->next->prezime, buffer_prezime) < 0)
				{
					p = p->next;
				}

				else {
					temp = p->next;
					p->next = q;
					q->next = temp;
					return 0;
				}
			}

			return 0;

	}

	fclose(datoteka);

	return 0;
}