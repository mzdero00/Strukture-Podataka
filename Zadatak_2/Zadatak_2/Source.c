#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 50


typedef struct _osoba;
typedef struct _osoba* Position;
typedef struct _osoba
{
	char ime[MAX_SIZE];
	char prezime[MAX_SIZE];
	int godina_rodjenja;
	Position next;

}osoba;

Position StvoriOsobu(char*, char*, int);
int DodajNaPocetak(char*,char*,int,Position);
int IsprintajListu(Position);
int DodajNaKraj(char*, char*, int, Position);
Position PronadiElement(char*, Position);
int IzbrisiElement(char*, Position);
int DodajElementIzaOdreðenog(char*, char*, char*, int, Position);
int DodajElementIspredOdreðenog(char*, char*, char*, int, Position);
int SortiraniUnos(char*, char*, int, Position);

int main()
{
	osoba head = { .ime = " ", .prezime = " ", .godina_rodjenja = 0, .next=NULL};
	Position p = &head;
	/*DodajNaPocetak("Ime", "Preziime", 50, p);
	DodajNaPocetak("Ime", "Preziiime", 50, p);
	DodajNaKraj("Imee", "Prezime", 50, p);
	DodajElementIzaOdreðenog("Preziime", "Marin", "Maric", 50, p);
	DodajElementIspredOdreðenog("Preziime", "Marino", "Maricko", 50, p);*/
	SortiraniUnos("Karlo","Karlic",100,p);
	SortiraniUnos("Zdero", "Zderic", 100, p);
	SortiraniUnos("Ante", "Antic", 100, p);
	//IzbrisiElement("Preziiime", p);
	//PronadiElement("Preziime",p);
	IsprintajListu(p);

	return 0;
}

Position StvoriOsobu(char* Ime, char* Prezime, int Godina)
{
	Position q;

	q = (Position)malloc(sizeof(osoba));

	q->godina_rodjenja = Godina;
	strcpy(q->ime, Ime);
	strcpy(q->prezime, Prezime);

	q->next = NULL;

	return q;
}

int DodajNaPocetak(char* Ime, char* Prezime, int Godina, Position head)
{
	Position temp = NULL;
	Position q=StvoriOsobu(Ime, Prezime, Godina);
	temp = head->next;
	head->next = q;
	q->next = temp;
	return 0;
}

int IsprintajListu(Position head)
{
	Position first = head->next;
	while (first != NULL)
	{
		printf(" %s %s %d\n", first->ime, first->prezime, first->godina_rodjenja);
		first = first->next;
	}
	return 0;
}

int DodajNaKraj(char* Ime, char* Prezime, int Godina, Position head)
{
	Position q = head;
	while (q->next != NULL)
		q = q->next;
	Position temp = NULL;
	Position b = StvoriOsobu(Ime, Prezime, Godina);
	q->next = b;
	b->next = NULL;
	return 0;
}

Position PronadiElement(char* Prezime, Position head)
{
	Position q = head;
	while (strcmp(q->prezime, Prezime) != 0)
		q = q->next;
	printf(" %s", q->prezime);
	return q;
}

int IzbrisiElement(char* Prezime, Position head)
{
	Position q = head;
	Position temp = NULL;
	while (strcmp(q->next->prezime, Prezime) != 0)
		q = q->next;
	temp = q->next;
	q->next = temp->next;
	temp->next = NULL;
	free(temp);
	return 0;
}
int DodajElementIzaOdreðenog(char* PrezimeIza, char* Ime, char* Prezime,int Godina, Position head)
{
	Position q = head->next;
	Position b = StvoriOsobu(Ime, Prezime, Godina);
	Position temp = NULL;
	while (strcmp(q->prezime, PrezimeIza) != 0)
		q = q->next;
	temp = q->next;
	q->next = b;
	b->next = temp;

	return 0;
}

int DodajElementIspredOdreðenog(char* PrezimeIspred, char* Ime, char* Prezime, int Godina, Position head)
{
	Position q = head;
	Position b = StvoriOsobu(Ime, Prezime, Godina);
	Position temp = NULL;
	while (strcmp(q->next->prezime, PrezimeIspred) != 0)
		q = q->next;
	temp = q->next;
	q->next = b;
	b->next = temp;

	return 0;
}

int SortiraniUnos(char* Ime, char* Prezime, int Godina, Position head)
{
	Position q = head;
	Position temp = NULL;
	Position b = StvoriOsobu(Ime, Prezime, Godina);
	if (q->next == NULL)
	{
		q->next = b;
		b->next = NULL;
	}
	else()

	return 0;
}