#define _CRT_SECURE_NO_WARNINGS
#include "funkcije.h"
#include "funkcije.c"

int main()
{
	char imeDatoteke[20];
	int broj;
	stud* s=NULL;


	printf("\n Kako se zove vasa datoteka?\n");
	scanf(" %s", imeDatoteke);

	broj=redoviDatotekeIAlociranjeMemorije(s,imeDatoteke);
	ucitatiPodatke(s,imeDatoteke);
	apsolutniBodovi(s,broj);
	isprintaj(s,broj);

	return 0;
}
