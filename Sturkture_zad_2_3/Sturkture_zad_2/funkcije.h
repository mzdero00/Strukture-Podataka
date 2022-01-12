#ifndef FUNKCIJE_H
#define FUNKCIJE_H

typedef struct _osoba;
typedef struct _osoba* Position;
typedef struct _osoba
{
	char ime[20];
	char prezime[20];
	int godinaRodjenja;
	Position next;

}osoba;

int menu(Position);

int elementNaPocetak(Position);

Position stvoriElement(char*, char*, int);

int ispisiElement(Position);

int ispisiListu(Position);

int elementNaKraj(Position);

Position nadiElement(Position);

int izbrisiElement(Position);

int dodatiIzaOdredenog(Position);

int dodatiIspredOdredenog(Position);

int sortiraniUnos(Position);

int datotekaUpis(Position);

int datotekaIspis(Position);

#endif