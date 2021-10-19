#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXC 128
#define MAXL 1024

typedef struct student
{
	char ime[MAXC];
	char prezime[MAXC];
	double bodovi;
}stud;


int Prebroji();
stud* AlociratIUpisat(int, stud*);
double maxbr(stud*, int);



int main()
{
	//FILE* datoteka = NULL;
	stud* s = NULL;
	double max_br;
	int Broj_Studenata;
	int i;

	/*datoteka = fopen("datoteka.txt", "r");
	if (!datoteka)
		printf("\n Datoteka nije uspjesno ucitana\n");*/

	Broj_Studenata = Prebroji();

	s = AlociratIUpisat(Broj_Studenata, s);

	max_br = maxbr(s, Broj_Studenata);

	for (i = 0; i < Broj_Studenata; i++)
		printf(" %s     %s     %lf      %lf\n", s[i].ime, s[i].prezime, s[i].bodovi, (s[i].bodovi / max_br) * 100);

	/*fclose(datoteka);*/

	return 0;
}

int Prebroji()
{
	int br = 0;
	char a[MAXL] = { 0 };
	
	FILE* datoteka = NULL;
	datoteka = fopen("datoteka.txt", "r");
	if (!datoteka)
		printf("\n Datoteka nije uspjesno ucitana\n");

	while (!feof(datoteka))
	{
		fgets(a, MAXL, datoteka);
		br++;
	}
	printf("%d", br);
	fclose(datoteka);
	return br;
}

stud* AlociratIUpisat(int Broj_Studenata, stud* s)
{
	int i;
	FILE* datoteka;
	datoteka = fopen("datoteka.txt", "r");
	if (!datoteka)
		printf("\n Datoteka nije uspjesno ucitana\n");

	s = (stud*)malloc(sizeof(stud) * Broj_Studenata);

	for (i = 0; i < Broj_Studenata; i++)
		fscanf(datoteka, " %s %s %lf", s[i].ime, s[i].prezime, &s[i].bodovi);
	fclose(datoteka);

	return s;
}

double maxbr(stud* s, int Broj_Studenata)
{
	int i;
	double max=0;
	for (i = 0; i < Broj_Studenata; i++)
		if (s[i].bodovi > max)
			max = s[i].bodovi;
	return max;
}