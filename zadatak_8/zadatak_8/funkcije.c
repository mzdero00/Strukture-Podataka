#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "funkcije.h"


int menu(Position root)
{
	int n = 0;
	int element = 0;
	int b = 0;

	printf("\nOdaberite opciju koju zelite: ");
	printf("\nDodaj element u stablo ::::::: 1 \nIspisi stablo in order nacinom ::::::: 2\n ");
	printf("Ispisi stablo pre order nacinom ::::::: 3 \nIspisi stablo post order nacinom ::::::: 4\n ");
	printf("Ispisi stablo level order nacinom :::::: 5\n");
	printf("\n Izbrisi odredjeni element iz stabla ::::::: 8 \n Izbrisi cijelo stablo :::::: 9\n Exit ::::::: 0\n");

	scanf("%d", &n);

	switch (n)
	{
	case 1:
		printf("\n Unesite broj koji zelite unijeti u stablo: \n");
		scanf("%d", &element);
		root=insertElement(root,element);
		system("cls");
		menu(root);
		
		break;
	case 2:
		printInOrder(root);
		menu(root);
		break;
	case 3:
		printPreOrder(root);
		menu(root);
		break;
	case 4:
		printPostOrder(root);
		menu(root);
		break;
	case 5:
		printLevelOrder(root);
		menu(root);
		break;

	case 8:
		printf("\n Unesite koji element zelite izbrisati: ");
		scanf("%d", &b);
		deleteElement(root, b);
		menu(root);
		break;
	case 9:
		deallocTree(root);
		if (root == NULL)
		{
			printf("\n Stablo uspjesno obrisano!\n");
		}
		menu(root);
		break;
	case 0:
		return 0;
		break;

	default:
		printf("\nPogresan unos!\n");
		menu(root);
			break;
	}

}

Position createElement(int element)
{
	Position q = NULL;

	q = (Position)malloc(sizeof(tree));
	if (!q)
	{
		printf("\n Memorija nije alocirana!");
		return -1;
	}

	q->element = element;
	q->R = NULL;
	q->L = NULL;

	return q;
}

Position insertElement(Position root,int element)
{
	Position newElement = createElement(element);
	Position current = root;

	if (current == NULL)
	{
		return newElement;
	}
	else if ((current->element) < element)
	{
		current->R = insertElement(current->R, element);
	}
	else if ((current->element) > element)
	{
		current->L = insertElement(current->L, element);
	}
	else
		printf("\n Element vec postoji!\n");

	return current;
}

Position printInOrder(Position root)
{
	if (root == NULL)
	{
		return 0;
	}
	printInOrder(root->L);
	printf(" %d ", root->element);
	printInOrder(root->R);

	return 0;
}

Position printPreOrder(Position root)
{
	if (root == NULL)
	{
		return 0;
	}
	printf(" %d ", root->element);
	printInOrder(root->L);
	printInOrder(root->R);

	return 0;
}


Position printPostOrder(Position root)
{
	if (root == NULL)
	{
		return 0;
	}
	printInOrder(root->L);
	printInOrder(root->R);
	printf(" %d ", root->element);

	return 0;
}

Position deallocTree(Position root)
{
	if ( root == NULL) 
			return 0;

	deallocTree(root->L);
	deallocTree(root->R);

	free(root);

	return 0;
}

Position printCurrentLevel(Position root, int dubina)
{
	if (root == NULL)
		return 0;
	if (dubina == 1)
		printf("%d ", root->element);
	else if (dubina > 1) {
		printCurrentLevel(root->L, dubina - 1);
		printCurrentLevel(root->R, dubina - 1);
	}
	return 0;
}

int dubina(Position root)
{
	if (root == NULL)
		return 0;
	else {
		int dubina_lijevo = dubina(root->L);
		int dubina_desno = dubina(root->R);

		if (dubina_lijevo > dubina_desno)
			return (dubina_lijevo + 1);
		else
			return (dubina_desno + 1);
	}
}

Position printLevelOrder(Position root)
{
	int d = dubina(root);
	int i=0;
	for (i = 1; i <= d; i++)
		printCurrentLevel(root, i);
	return 0;
}

Position findElement(Position root, int element)
{
	if (root == NULL)
		return root;

	if (element < root->element)
		root->L = deleteElement(root->L, element);

	else if (element > root->element)
		root->R = deleteElement(root->R, element);

	return root;
}

Position minElement(Position root)
{
	Position current = root;

	while (current && current->L != NULL)
		current = current->L;

	return current;
}

Position deleteElement(Position root, int element)
{
	root=findElement(root, element);

		if (root->L == NULL)
		{
			Position temp = root->R;
			free(root);
			return temp;
		}
		else if (root->R == NULL)
		{
			Position temp = root->L;
			free(root);
			return temp;
		}

		Position temp = minElement(root->R);

		root->element = temp->element;

		root->R = deleteElement(root->R, temp->element);

	return root;
}
