#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funkcije.h"


int main()
{
	int i = 0;
	tree Root = { .el = 0, .L = NULL, .R = NULL };
	Position t = NULL;
	Position temp = NULL;
	Position head = NULL;

	t = (Position)malloc(sizeof(tree));

	int array[] = { 2, 5, 7, 8, 11, 1, 4, 2, 3, 7 };

	for (i = 0; i < 10; i++)
	{
		temp = CreateElement(array[i]);
		if (i == 0)
		{
			head = temp;
		}
		else
		{
			insertElement(head , temp);
		}
	}

	printInOrder(head);

	return 0;
}