#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funkcije.h"


int main()
{
	osoba head = { .next = NULL, .ime = "default", .prezime = "default",.godinaRodjenja = 0 };
	Position p = &head;

	menu(p);

	return 0;
}