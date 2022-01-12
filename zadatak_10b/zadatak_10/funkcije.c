#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "funkcije.h"


int menu(PositionT root, PositionL head)
{
	FILE* datoteka=NULL;
	FILE* datoteka1 = NULL;
	char buffer_nazivdrzave[MAX_NAME] = { " " };
	char buffer_imedatoteke2[MAX_NAME] = { " " };

	datoteka = fopen("drzave.txt", "r");
	if (!datoteka)
	{
		printf("\n Datoteka nije otvorena!\n");
		return -2;
	}

	while (!feof(datoteka))
	{
		fscanf(datoteka, "%s %s", buffer_nazivdrzave, buffer_imedatoteke2);
		root = insertTreeElement(root, buffer_nazivdrzave, buffer_imedatoteke2);
	}

	printf("\n\n");

	fclose(datoteka);

	connectListAndTree(root);

	ispisStabla(root);
	return 0;
}

PositionT createTreeElement(char* naziv_drzave,char* ime_datoteke_gradova)
{
	PositionT t = NULL;

	t = (PositionT)malloc(sizeof(tree));
	if (!t)
	{
		printf("\n Memorija nije uspjesno alocirana!");
		return EXIT_FAILURE;
	}

	strcpy(t->imeDrzave,naziv_drzave);
	strcpy(t->imeDatotekeGradova, ime_datoteke_gradova);
	t->L = NULL;
	t->R = NULL;

	return t;
}

PositionT insertTreeElement(PositionT root, char* nazivDrzave, char* imeDatoteke)
{
	PositionT newElement = createTreeElement(nazivDrzave, imeDatoteke);
	PositionT current = root;

	if (current == NULL)
	{
		return newElement;
	}
	else if (strcmp(current->imeDrzave,nazivDrzave)<0)
	{
		current->R = insertTreeElement(current->R, nazivDrzave, imeDatoteke);
	}
	else if (strcmp(current->imeDrzave, nazivDrzave) > 0)
	{
		current->L = insertTreeElement(current->L, nazivDrzave, imeDatoteke);
	}
	else
		printf("\n Element vec postoji!\n");

	return current;
}


PositionT ispisStabla(PositionT root)
{
	if (root == NULL)
	{
		return NULL;
	}
	ispisStabla(root->L);
	printf("\n %s \n", root->imeDrzave);
	ispisiListu(root->listHead);
	ispisStabla(root->R);

	return NULL;
}

PositionL createListElement(char* nazivGrada, int brojStanovnika)
{
	PositionL q = NULL;

	q = (PositionL)malloc(sizeof(list));
	if (!q)
	{
		printf("\n Memorija nije alocirana!");
		return -4;
	}


	strcpy(q->imeGrada, nazivGrada);
	q->brojStanovnika = brojStanovnika;
	q->next = NULL;

	return q;
}

int insertListElement(PositionL head, char* nazivGrada, int brojStanovnika)
{
	PositionL newElement = createListElement(nazivGrada, brojStanovnika);
	PositionL current = head;
	PositionL temp = NULL;
	while (current != NULL)
	{
		if (current->next == NULL)
		{
			current->next = newElement;
			newElement->next = NULL;
			return 0;
		}
		else if ((current->next->brojStanovnika) < brojStanovnika)
		{
			temp = current->next;
			current->next = newElement;
			newElement->next = temp;

			return 0;
		}
		else if ((current->next->brojStanovnika) > brojStanovnika)
		{
			current = current->next;
		}
		else if ((current->next->brojStanovnika) == brojStanovnika && strcmp(current->next->imeGrada, nazivGrada) > 0)
		{
			temp = current->next;
			current->next = newElement;
			newElement->next = temp;

			return 0;
		}
		else if ((current->next->brojStanovnika) == brojStanovnika && (strcmp(current->next->imeGrada, nazivGrada) < 0))
		{
			current=current->next;
		}
	}
	return 0;
}

PositionL createList(PositionT current)
{
	char buffer_imeDatoteke[MAX_NAME] = {' '};
	char buffer_imeGrada[MAX_NAME] = {' '};
	int brojStanovnika = 0;
	FILE* f = NULL;
	int br = 1;
	list head12 = { .next = NULL,.imeGrada = " ",.brojStanovnika = 0 };
	current->listHead = &head12;
	PositionL head1 = current->listHead;


	strcpy(buffer_imeDatoteke,current->imeDatotekeGradova);

	f = fopen(buffer_imeDatoteke, "r");
	if (!f)
	{
		printf("\n Datoteka nije otvorena !");
		return EXIT_FAILURE;
	}

	while (!feof(f))
	{
		if (fgetc(f) == '\n')
			br++;
	}

	rewind(f);

	if (!head1)
	{
		printf("\n Memorija nije alocirana");
		return EXIT_FAILURE;
	}

	while (!feof(f))
	{
		fscanf(f, "%s %d", buffer_imeGrada, &brojStanovnika);
		insertListElement(head1, buffer_imeGrada, brojStanovnika);
	}
	return NULL;
}

int ispisiListu(PositionL head)
	{
		PositionL current = head->next;
		while (current)
		{
			printf("%s %d\n", current->imeGrada, current->brojStanovnika);
			current = current->next;
		}
		return 0;
	}



PositionT connectListAndTree(PositionT root)
{
	PositionT current = root;
	if (current == NULL)
	{
		return NULL;
	}
	connectListAndTree(current->L);
	createList(current);
	connectListAndTree(current->R);

	return NULL;
}