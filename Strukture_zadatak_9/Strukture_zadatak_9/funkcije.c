#define CRT_SECURE_NO_WARNINGS
#include "funkcije.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


Position createElement(int el)
{
	Position newElement = NULL;

	newElement = (Position)malloc(sizeof(tree));
	if (!newElement)
	{
		printf("\n Pogreška!");
		return -1;
	}

	newElement->el = el;
	newElement->L = NULL;
	newElement->R = NULL;

	return newElement;
}

Position insertElement(Position current, Position newElement)
{
	if (current == NULL)
	{
		current = newElement;
	}
	else if ((current->el) <= (newElement->el))
	{
		current->R = insertElement(current->R, newElement);
	}
	else if ((current->el) >= (newElement->el))
	{
		current->L = insertElement(current->L, newElement);
	}

	return current;
}

int replace(Position current)
{
	int Left_1 = 0;
	int Left_2 = 0;
	int Right_1 = 0;
	int Right_2 = 0;

	if (current)
	{
		if (current->L->el)
			Left_1 = current->L->el;
		if (current->R->el)
			Right_1 = current->R->el;

		replace(current->L);
		replace(current->R);

		if (current->L)
			Left_2 = current->L->el;
		if (current->R)
			Right_2 = current->R->el;

		return current->el = Right_1 + Right_2 + Left_1 + Left_2;

	}
	return 0;
}


int printInOrder(Position current)
{

	if (current)
	{
		printInOrder(current->L);
		printf(" %d ", current->el);
		printInOrder(current->R);
	}

	return 0;
}


