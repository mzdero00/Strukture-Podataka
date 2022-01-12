#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student;


int redoviDatotekeIAlociranjeMemorije(_student* s, char* imeDatoteke);

int ucitatiPodatke(_student* s, char* imeDatoteke);


int apsolutniBodovi(_student* s, int broj);


int isprintaj(_student* s, int broj);