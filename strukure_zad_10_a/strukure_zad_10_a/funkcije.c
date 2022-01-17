#include "funkcije.h"
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS


PositionList createListElement(char* nazivDrzave, char* nazivDatoteke) //stvaranje drzave
{
	PositionList q = NULL;

	q = (PositionList)malloc(sizeof(list));

	if (!q)
	{
		printf("\n Element nije alociran!");
		return -1;
	}

	strcpy(q->nazivDrzave, nazivDrzave);
	strcpy(q->nazivDatotekeGrada, nazivDatoteke);

	q->next = NULL;
	q->treeRoot = NULL;


	return q;
}

PositionTree createTreeElement(char* nazivGrada, int brojStanovnika)  //stvaranje grada
{
	PositionTree q = NULL;

	q = (PositionTree)malloc(sizeof(tree));

	if (!q)
	{
		printf("\n Element nije alociran!");
		return -2;
	}

	strcpy(q->nazivGrada, nazivGrada);
	q->brojStanovnika = brojStanovnika;

	q->L = NULL;
	q->R = NULL;

	return q;
}



int insertListElement(char* nazivDrzave, char* nazivDatoteke, PositionList head)// unosenje drzave u listu
{
	PositionList newElement = createListElement(nazivDrzave,nazivDatoteke);

	if (!newElement)
	{
		printf("\n Element nije napravljen!");
		return -3;
	}

	PositionList current = head;
	PositionList temp = NULL;


	while (current)
	{
		if (current->next == NULL)
		{
			current->next = newElement;
			newElement->next = NULL;
			return 0;
		}
		else if (strcmp(current->next->nazivDrzave, nazivDrzave) < 0)
		{
			current = current->next;
		}

		else if(strcmp(current->next->nazivDrzave,nazivDrzave)>0)
		{
			temp = current->next;
			current->next = newElement;
			newElement->next = temp;

			return 0;
		}
		else
		{
			printf("\nVec ste unijeli tu drzavu!\n");
			return -4;
		}
	}

	return 0;
}

PositionTree insertTreeElement(char* nazivGrada, int brojStanovnika , PositionTree treeRoot)
{
	PositionTree root = treeRoot;
	PositionTree newElement = createTreeElement(nazivGrada, brojStanovnika);
	
	if (!newElement)
	{
		printf("\n Element nije napravljen!");
		return -5;
	}

	if (!root)
	{
		return newElement;
	}

	else if (root->brojStanovnika<brojStanovnika)
	{
		root->R=insertTreeElement(nazivGrada, brojStanovnika, root->R);
	}
	else if (root->brojStanovnika > brojStanovnika)
	{
		root->L=insertTreeElement(nazivGrada, brojStanovnika, root->L);
	}
	else if (root->brojStanovnika == brojStanovnika)
	{
		if (strcmp(root->nazivGrada, nazivGrada) < 0)
		{
			root->R=insertTreeElement(nazivGrada, brojStanovnika, root->R);
		}
		else if (strcmp(root->nazivGrada, nazivGrada) > 0)
		{
			root->L=insertTreeElement(nazivGrada, brojStanovnika, root->L);
		}
	}

	return root;
}


int fileScanList(char* nazivDatoteke, PositionList head)
{
	FILE* dat = NULL;
	PositionList current = head->next;
	char buffer1[MAX] = { ' ' };
	char buffer2[MAX] = { ' ' };


	dat = fopen(nazivDatoteke, "r");
	
	if (!dat)
	{
		printf("\n Datoteka nije ucitana!");
		return -6;
	}

	while (!feof(dat))
	{
		fscanf(dat, " %s %s",buffer1,buffer2,head);
		insertListElement(buffer1, buffer2,head);
	}

	fclose(dat);
	return 0;
}

int fileScanTree(PositionList head)
{
	FILE* dat = NULL;
	PositionList current = head->next;
	char buffer1[MAX] = {' '};
	int brojStanovnika = 0;

	while (current)
	{
		dat = fopen(current->nazivDatotekeGrada, "r");

		if (!dat)
		{
			printf("\n Datoteka nije ucitana!");
			return -7;
		}

		while (!feof(dat))
		{
			fscanf(dat, " %s %d", buffer1, &brojStanovnika, head);
			current->treeRoot=insertTreeElement(buffer1, brojStanovnika, current->treeRoot);
		}

		fclose(dat);

		current = current->next;

	}
	
	return 0;
}


int displayList(PositionList head)
{
	head = head->next;
	while (head)
	{
		printf("\n\n %s\n", head->nazivDrzave);
		displayTree(head->treeRoot);
		head = head->next;
	}

	return 0;
}

PositionTree displayTree(PositionTree root)
{
	if (!root)
	{
		return NULL;
	}

	displayTree(root->L);
	printf("\n %s", root->nazivGrada);
	displayTree(root->R);

	return NULL;
}


int findCitiesInRange(PositionList head, int rangemin)
{
	PositionList current = head->next;

	while (current)
	{
		
		findCity(current->treeRoot, rangemin);
		current = current->next;
	}

	return 0;

}

/*PositionTree findMin(PositionTree root, int rangemin)
{
	PositionTree current = root;

	if (current->brojStanovnika == rangemin)
	{
		return current;
	}

	else if (current->brojStanovnika > rangemin)
	{
		current = findCity(current->L, rangemin);
	}

	else if (current->brojStanovnika < rangemin)
	{
		current = findCity(current->R, rangemin);
	}
	return NULL;
}*/

PositionTree findCity(PositionTree root, int rangemin)
{
	PositionTree current = root;

	if (!current)
	{
		return NULL;
	}
	if (rangemin < current->brojStanovnika)
	{
		findCity(current->L, rangemin);
	}
	if (rangemin <= current->brojStanovnika)
	{
		printf("\n %s %d", current->nazivGrada, current->brojStanovnika);
	}

	findCity(current->R, rangemin);

}

