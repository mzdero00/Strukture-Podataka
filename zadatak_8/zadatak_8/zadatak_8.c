
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct cvorStabla* Position;
typedef struct cvorStabla* Stablo;
typedef struct cvorStabla {
	int El;
	Position L;
	Position D;
}Cvor;

Stablo insert(int X, Position root);
Stablo delete(int X, Position root);
Position findEl(int X, Position root);
Position findMin(Position root);
int InOrder(Position root);
int PostOrder(Position root);
int PreOrder(Position root);

int main()
{
	Stablo root = NULL;
	int element = 0;
	int odabir;
	FILE* dat = NULL;

	dat = fopen("Text.txt", "r");
	if (dat == NULL)
		printf("\tDatoteka se nije otvorila!\n");

	while (!feof(dat))
	{
		fscanf(dat, "%d", &element);
		root = insert(element, root);
	}

	delete(6, root);

	printf("\tIspis stabla\n");
	printf("1-InOrder, 2-PostOrder, 3-PreOrder, 4-Izlaz\n");
	scanf("%d", &odabir);
	while (1) {
		switch (odabir) {

		case 1:
			InOrder(root);
			printf("\n");
			break;
		case 2:
			PostOrder(root);
			printf("\n");
			break;
		case 3:
			PreOrder(root);
			printf("\n");
			break;
		default:
			printf("Krivi odabir!\n");
			printf("\n");
			break;
		}
		scanf("%d", &odabir);
		if (odabir == 4)
			break;
	}

	return 0;
}

Stablo insert(int X, Position Tree) {

	if (NULL == Tree)
	{
		Tree = (Position)malloc(sizeof(Cvor));
		Tree->El = X;
		Tree->L = NULL;
		Tree->D = NULL;
		return Tree;
	}

	if (X > Tree->El) {
		Tree->D = insert(X, Tree->D);
		return Tree;
	}

	if (X < Tree->El) {
		Tree->L = insert(X, Tree->L);
		return Tree;
	}

}

Position findEl(int X, Position root) {

	if (NULL == root)
		return NULL;
	else if (X > root->El)
		return findEl(X, root->D);
	else if (X < root->El)
		return findEl(X, root->L);
	else
		return root;
}

Position findMin(Position root) {
	if (NULL == root)
		return NULL;
	else if (NULL == root->L)
		return root;
	else
		return findMin(root->L);
}

int InOrder(Position root) {
	if (NULL == root)
		return;
	InOrder(root->L);
	printf("%d ", root->El);
	InOrder(root->D);
}

int PreOrder(Position root)
{
	if (NULL == root)
		return;
	printf("%d ", root->El);
	PreOrder(root->L);
	PreOrder(root->D);
}

int PostOrder(Position root)
{
	if (NULL == root)
		return;
	PostOrder(root->L);
	PostOrder(root->D);
	printf("%d ", root->El);
}

Stablo delete(int X, Position root) {

	Position temp = NULL;
	if (NULL == root)
		printf("\tElement ne postoji!\n");
	else if (X < root->El)
		root->L = delete(X, root->L);
	else if (X > root->El)
		root->D = delete(X, root->D);
	else if (root->L != NULL && root->D != NULL)
	{
		temp = findMin(root->D);
		root->El = temp->El;
		root->D = delete(root->El, root->D);
	}
	else
	{
		temp = root;
		if (NULL == root->L)
			root = root->D;
		else
			root = root->L;
		free(temp);
	}

	return root;
}