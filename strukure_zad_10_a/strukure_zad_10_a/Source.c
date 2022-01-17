//listu drzava i stablo gradova
//search i ucitavanje iz datoteka

#define _CRT_SECURE_NO_WARNINGS
#include "funkcije.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	list head = { .next = NULL, .nazivDatotekeGrada = {"default"}, .nazivDrzave = {"default"},.treeRoot = NULL };
	PositionList h = &head;
	PositionTree root = NULL;
	int rangeMin = 1000000;

	fileScanList("drzave.txt", h);
	fileScanTree(h);
	displayList(h);
	findCitiesInRange(h, rangeMin);
	return 0;
}