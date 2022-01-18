#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "funkcije.h"




Position makeStack(double number)
{
	Position newElement;

	newElement = (Position)malloc(sizeof(stack));
	if (!newElement)
	{
		printf("Memorija nije alocirana\n");
		return NULL;
	}
	newElement->number = number;
	newElement->next = NULL;

	return newElement;
}

int insertAfter(Position position, Position newElement)
{
	newElement->next = position->next;
	position->next = newElement;

	return EXIT_SUCCESS;
}

int pushStack(Position head, double number)
{
	Position newElement = NULL;
	newElement = makeStack(number);
	if (!newElement)
	{
		return -1;
	}

	insertAfter(head, newElement);

	return EXIT_SUCCESS;
}
int deleteElement(Position position)
{
	Position temp = position->next;
	if (!temp)
	{
		return EXIT_SUCCESS;
	}

	position->next = temp->next;
	free(temp);

	return EXIT_SUCCESS;
}
int popStack(double* destination, Position head)
{
	Position first = head->next;
	if (!first)
	{
		printf("Datoteka u pogresnom formatu!\n");
		return -1;
	}
	*destination = first->number;
	deleteElement(head);

	return EXIT_SUCCESS;
}
int doOperation(Position head, char operation)
{
	double temp2 = 0;
	double temp1 = 0;
	double result = 0;
	int status1 = EXIT_SUCCESS;
	int status2 = EXIT_SUCCESS;

	status2 = popStack(&temp2, head);
	if (status2 != EXIT_SUCCESS)
	{
		return -1;
	}

	status1 = popStack(&temp1, head);
	if (status1 != EXIT_SUCCESS)
	{
		return -2;
	}

	switch (operation)
	{
	case '+':
	{
		result = temp1 + temp2;
		break;
	}
	case '-':
	{
		result = temp1 - temp2;
		break;
	}
	case '*':
	{
		result = temp1 * temp2;
		break;
	}
	case '/':
	{
		if (temp2 == 0)
		{
			printf("Greska! Ne mozemo dijeliti sa nulom!\n");
			return -3;
		}
		result = temp1 / temp2;
		break;
	}
	default:
		printf("Greska! Operacija ne postoji!\n");
		return -4;
	}
	pushStack(head, result);

	return EXIT_SUCCESS;
}
int filePostFix(double* destination, char* fileName)
{
	FILE* file = NULL;
	char* buffer = NULL;
	int fileLength = 0;
	char* currentBuffer = NULL;
	int numBytes = 0;
	char operation = 0;
	double number = 0;
	stack head = { .number = 0, .next = NULL };
	int status = 0;

	file = fopen(fileName, "rb");
	if (!file)
	{
		printf("Greska! Datoteka nije otvorena\n");
		return -1;
	}

	fseek(file, 0, SEEK_END);
	fileLength = ftell(file);

	buffer = (char*)calloc(fileLength + 1, sizeof(char));
	if (!buffer)
	{
		printf("Memorija nije alocirana!\n");
		return -2;
	}

	rewind(file);

	fread(buffer, sizeof(char), fileLength, file);

	printf("%s\n", buffer);
	fclose(file);

	currentBuffer = buffer;

	while (strlen(currentBuffer) > 0)
	{
		status = sscanf(currentBuffer, "%lf %n", &number, &numBytes);
		if (status == 1)
		{
			pushStack(&head, number);
			currentBuffer += numBytes;
		}
		else
		{
			sscanf(currentBuffer, " %c %n", &operation, &numBytes);

			status = doOperation(&head, operation);
			if (status != EXIT_SUCCESS)
			{
				free(buffer);
				while (head.next != NULL)
				{
					deleteElement(&head);
				}
				return -1;
			}
			currentBuffer += numBytes;
		}
	}
	free(buffer);
	status = popStack(destination, &head);
	if (status != EXIT_SUCCESS)
	{
		while (head.next)
		{
			deleteElement(&head);
		}
		return -4;
	}

	if (head.next)
	{
		printf("Greska!");

		while (head.next)
		{
			deleteElement(&head);
		}
		return -5;
	}
	return EXIT_SUCCESS;
}