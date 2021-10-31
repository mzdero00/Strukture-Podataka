#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct _osoba;
typedef struct _osoba* Position;

typedef struct _osoba
{
	char ime[50];
	char prezime[50];
	int godina_rodjenja;
	Position next;

}osoba;

Position StvoriOsobu(char* ime, char* prezime, int godina_rodjenja);
int ElementNaPocetakListe(Position head, char* ime, char* prezime, int godina_rodjenja);
int IspisiListu(Position first);
int ElementNaKrajListe(Position head, char* ime, char* prezime, int godina_rodjenja);
Position NadiZadnji(Position head);
Position NadiElement(Position first, char* prezime);
int IzbrisiElement(Position head, char* surname);
Position NadiIspred(Position head, char* surname);
int DodajIzaOdredenog(Position head, char* prezime, char* ime, char* prezime1, int godina_rodjenja);
int DodajIspredOdredenog(Position head, char* prezime, char* ime, char* prezime1, int godina_rodjenja);
int Sortiraj(Position p);
int UpisiUdatoteku(Position first,char* datoteka);
int CitanjeIzDatoteke(Position head,char* datoteka);
//int SortiraniUnos(Position head,char* ime, char* prezime, int broj_godina);
int UbaciIza(Position pozicija, Position nova_osoba);

int main()
{
	osoba Head = { .next = NULL, .ime = {0}, .prezime = {0}, .godina_rodjenja = 0 };
	Position p = &Head;
	char* datoteka = "datoteka.txt";
	/*SortiraniUnos(p, "Zorana", "Pajic", 1998);
	SortiraniUnos(p, "Josip", "Ivancic", 2002);
	SortiraniUnos(p, "Ivan", "Zdero", 2001);
	SortiraniUnos(p, "Jakov", "Mostarcic", 2006);
	SortiraniUnos(p, "Ivica", "Ivanovic", 2005);
	SortiraniUnos(p, "Stevan", "Jovanovic", 2003);
	SortiraniUnos(p, "Bogdan", "Kraljevic", 2003);
	SortiraniUnos(p, "Ante", "Starcevic", 2003);*/

	//IzbrisiElement(p, "Zdo");
	//NadiElement(p->next, "Zdeo");
	//Sortiraj(p);
	//SortiraniUnos(p, "Karla", "Jonjic", 2000);
	//UpisiUdatoteku(p->next,datoteka);
	//CitanjeIzDatoteke(p,datoteka);

	IspisiListu(p->next);
	return 0;
}
Position StvoriOsobu(char* ime, char* prezime, int godina_rodjenja)
{
	Position q = NULL;
	q = (osoba*)malloc(sizeof(osoba));
	if (!q)
	{
		perror("\nNe mozemo alocirati memoriju!\n");
		return NULL;
	}
	strcpy(q->ime, ime);
	strcpy(q->prezime, prezime);
	q->godina_rodjenja = godina_rodjenja;
	q->next = NULL;

	return q;

}

int ElementNaPocetakListe(Position head, char* ime, char* prezime, int godina_rodjenja)
{
	Position p = head;
	Position q = StvoriOsobu(ime, prezime, godina_rodjenja);
	q->next = p->next;
	p->next = q;
	return 0;

}

int IspisiListu(Position first)
{
	Position q = first;
	while (q != NULL)
	{
		printf(" %s	%s		%d\n", q->ime, q->prezime, q->godina_rodjenja);
		q = q->next;
	}
	return 0;
}

Position NadiZadnji(Position head)
{
	Position q = head;
	while (q->next != NULL)
		q = q->next;
	return q;
}

int ElementNaKrajListe(Position head, char* ime, char* prezime, int godina_rodjenja)
{
	Position q = head;
	Position o = NULL;
	q = NadiZadnji(q);
	o = StvoriOsobu(ime, prezime, godina_rodjenja);
	q->next = o;
	return 0;

}

Position NadiElement(Position first, char* prezime)
{
	Position q = first;
	while (q != NULL)
	{
		if (strcmp(q->prezime, prezime) == 0)
			return q;
		else
			q = q->next;
	}
}

Position NadiIspred(Position head, char* prezime)
{
	Position q = head;
	while (q->next != NULL)
	{
		if (strcmp(q->next->prezime, prezime) == 0)
			return q;
		else
			q = q->next;
	}
	return NULL;
}

int IzbrisiElement(Position head, char* surname)
{
	Position p = head;
	Position q = NULL;
	Position temp = NULL;
	q = NadiElement(p, surname);
	temp = NadiIspred(p, surname);
	temp->next = q->next;
	free(q);
	return 0;
}

int DodajIzaOdredenog(Position head, char* prezime, char* ime, char* prezime1, int godina_rodjenja)
{
	Position p = head;
	Position q = NULL;
	Position z = NULL;

	q = NadiElement(p, prezime);
	z = StvoriOsobu(ime, prezime1, godina_rodjenja);
	z->next = q->next;
	q->next = z;

	return 0;
}

int DodajIspredOdredenog(Position head, char* prezime, char* ime, char* prezime1, int godina_rodjenja)
{
	Position p = head;

	//Position n = NadiElement(p->next, prezime);
	Position u = NadiIspred(p, prezime);
	Position z = StvoriOsobu(ime, prezime1, godina_rodjenja);
	z->next = u->next;
	u->next = z;

	return 0;

}

int UbaciIza(Position pozicija, Position nova_osoba)
{
	nova_osoba->next = pozicija->next;
	pozicija->next = nova_osoba;
	return EXIT_SUCCESS;
}


int Sortiraj(Position p)
{
	Position j, prev_j, temp, end;

	end = NULL;
	while (p->next != end)
		{
			prev_j = p;
			j = p->next;
			while (j->next != end)
				{
				if (strcmp(j->prezime, j->next->prezime) > 0)
					{
					temp = j->next;
					prev_j->next = temp;
					j->next = temp->next;
					temp->next = j;

					j = temp;
					}
				prev_j = j;
				j = j->next;
				}
			end = j;
		}
}

int UpisiUdatoteku(Position first,char* datoteka)
{
	datoteka = fopen("datoteka.txt", "w");
	if (!datoteka)
	{
		printf("\nDatoteka nije otvorena!");
		return -1;
	}
	Position q = first;
	while (q != NULL)
	{
		fprintf(datoteka," %s	%s		%d\n", q->ime, q->prezime, q->godina_rodjenja);
		q = q->next;
	}
	fclose(datoteka);
	return 0;
}

int CitanjeIzDatoteke(Position head, char* datoteka)
{
	char ime[50] = { 0 };
	char prezime[50] = { 0 };
	int godina_rodjenja = 0;
	Position q = head;
	datoteka = fopen("datoteka.txt", "r");
	if (!datoteka)
	{
		printf("\nDatoteka nije otvorena!");
		return -1;
	}
	while (!feof(datoteka))
		while (fscanf(datoteka, " %s %s %d", ime, prezime, &godina_rodjenja) == 3)
			ElementNaKrajListe(q, ime, prezime, godina_rodjenja);

	fclose(datoteka);

	return 0;
}

/*int SortiraniUnos(Position head, char* ime, char* prezime, int godina_rodjenja)
{
	Position p = head;
	Position q = p->next;
	Position s = StvoriOsobu(ime, prezime, godina_rodjenja);
	if (q != 0)
	{
		while (q != NULL)
		{
			if (strcmp(q->prezime, prezime) > 0)
			{
				UbaciIza(p, s);
				return 0;
			}
			else if (q->next == NULL)
			{
				ElementNaKrajListe(p, ime, prezime, godina_rodjenja);
				return 0;
			}
			else
				p = p->next;
				q = q->next;
		}
	}
	else
		ElementNaPocetakListe(p, ime,prezime,godina_rodjenja);
	return 0;
}*/
