#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "funkcije.h"


int main()
{
	double result = 0;


	if (filePostFix(&result, "Text.txt") == EXIT_SUCCESS)
	{
		printf("Rezultat =  %0.2lf", result);
	}
	else
	{
		printf("Greska!");
		return -3;
	}
	return 0;
}