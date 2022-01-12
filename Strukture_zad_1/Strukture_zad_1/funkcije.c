#define _CRT_SECURE_NO_WARNINGS
#include "funkcije.h"

typedef struct _student
{
	char ime[20];
	char prezime[20];
	int brojBodova;
	float apsolutniBodovi;

}stud;

int redoviDatotekeIAlociranjeMemorije(stud* s, char* imeDatoteke)
{
	int br = 0;
	FILE* datoteka = NULL;

	datoteka = fopen(imeDatoteke, "r");
	if (!datoteka)
	{
		printf("\n Datoteka nije uciatana!\n");
		return -1;
	}

	while (!feof(datoteka))
	{
		if (fgetc(datoteka) == '\n')
			br++;
	}

	s = (stud*)malloc(sizeof(stud) * br);

	fclose(datoteka);

	return br;
}

int ucitatiPodatke(stud* s, char* imeDatoteke)
{
	char ime[20];
	char prezime[20];
	int brojBodova;
	FILE* datoteka = NULL;

	datoteka = fopen(imeDatoteke, "r");

	if (!datoteka)
	{
		printf("\n Datoteka nije uciatana!\n");
		return -1;
	}

	while (!feof(datoteka))
	{
		if (fscanf(datoteka, " %s %s %d", ime, prezime, &brojBodova) == 3)
		{
			strcpy(s->ime, ime);
			strcpy(s->prezime, prezime);
			s->brojBodova = brojBodova;
		}

	}

	fclose(datoteka);
	return 0;

}

int apsolutniBodovi(stud* s, int broj)
{
	int i = 0;
	int max = 0;

	for (i = 0; i < broj; i++)
	{
		if (s[i].brojBodova > max)
			max = s[i].brojBodova;
	}

	for (i = 0; i < broj; i++)
	{
		s[i].apsolutniBodovi = (s[i].brojBodova * 100) / (max);
	}

	return 0;
}

int isprintaj(stud* s, int broj)
{
	int i = 0;
	for (i = 0; i < broj; i++)
	{
		printf("\n \t%s\t%s\t%d\t%f\n", s[i].ime, s[i].prezime, s[i].brojBodova, s[i].apsolutniBodovi);
	}
	return 0;
}