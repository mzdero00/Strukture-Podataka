#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "funkcije.h"


int main()
{

    poli Poli1 = { .next = NULL, .koef = 0, .expo = 0 };
    poli Poli2 = { .next = NULL , .koef = 0, .expo = 0 };
    poli _zbroj = { .next = NULL , .koef = 0, .expo = 0 };
    poli _mulRes = { .next = NULL , .koef = 0, .expo = 0 };
    Position p1 = &Poli1;
    Position p2 = &Poli2;
    Position zbroj = &_zbroj;
    Position mulRes = &_mulRes;

    char nazivDat[] = "polinomi.txt";

    fileScan(nazivDat, p1, p2);

    printP(p1->next);
    printP(p2->next);

    addP(zbroj, p1, p2);
    printP(zbroj->next);

    mulP(mulRes, p1, p2);
    printP(mulRes->next);

    return 0;
}