#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


struct _tree;
typedef struct _tree* Position;

typedef struct _tree
{
	int element;
	Position L;
	Position R;
} tree;


struct _List;
typedef struct _List* PositionList;

typedef struct _List
{
	int element;
	PositionList next;
}list;


//tree related
Position insert(Position , Position);
Position createNewElement(int);
int printInOrder(Position);
int replace(Position);
Position deallocateTree(Position);

//list related
int printIntoList(Position , PositionList);
int elementFirst(PositionList , int);
PositionList CreateNewListElement(int);
int insertAfter(PositionList , PositionList) ;
int intoFile(PositionList,char* );
PositionList FindLast(PositionList);

int main()
{
	
	int array[] = { 2, 5, 7, 8, 11, 1, 4, 2, 3, 7 };
	int i = 0;

	Position root = NULL;
	Position temp = NULL;

	root = (Position)malloc(sizeof(tree));
	if (!root)
	{
		printf("\n Memorija nije alocirana!");
		return -1;
	}

	root->element = array[0];
	root->L = NULL;
	root->R = NULL;


	for (i = 1; i < 10; i++)
	{
		temp = createNewElement(array[i]);
		if (!temp)
		{
			printf("\n Memorija nije alocirana!");
			return -2;
		}
		root = insert(root, temp);
	}

	printInOrder(root);
	printf("\n");

	root->element = replace(root);

	printInOrder(root);
	printf("\n");
	
	deallocateTree(root);

	srand(time(NULL));
	char dat[50] = { 0 };
	list head = { .next = NULL, .element = {0} };
	Position p = &head;

	root = (Position)malloc(sizeof(tree));
	if (!root)
	{
		printf("\n Memorija nije alocirana!");
		return -1;
	}


	root->element = rand() % 80 + 10;

	root->L = NULL;
	root->R = NULL;

	for (i = 1; i < 10; i++)
	{
		temp = createNewElement(rand() % 80 + 10);
		if (!temp)
		{
			printf("\nMemorija nije alocirana!");
			return -3;
		}
		root = insert(root, temp);
	}

	printf("\n Upisite ime datoteke :");
	scanf(" %s", dat);
	printf("\n");

	printIntoList(root, p);
	printf("\n");

	intoFile(p, dat);
	printf("\n");

	root->element = replace(root);
	printIntoList(root, p);
	printf("\n");

	intoFile(p, dat);

	return 0;
}
Position insert(Position root, Position temp)
{
	if (root == NULL)
	{
		return temp;
	}
	if (root->element <= temp->element)
	{
		root->L = insert(root->L, temp);
	}
	else if (root->element > temp->element)
	{
		root->R = insert(root->R, temp);
	}


	return root;
}
Position createNewElement(int element)
{
	Position temp = NULL;

	temp = (Position)malloc(sizeof(tree));

	if (!temp)
	{
		printf("\n Memorija nije alocirana!");
		return -1;
	}

	temp->element = element;
	temp->L = NULL;
	temp->R = NULL;

	return temp;
}
int printInOrder(Position root)
{
	if (!root)
	{
		return 0;
	}
	printInOrder(root->L);
	printf("%d ", root->element);
	printInOrder(root->R);

	return 0;
}
int replace(Position root)
{
	int temp;
	if (!root)
	{
		return 0;
	}
	else 
	{
		temp = root->element;
		root->element = replace(root->R) + replace(root->L);
	}

	return temp + root->element;
}

Position deallocateTree(Position root)
{
	if (!root)
		return root;
	deallocateTree(root->L);
	deallocateTree(root->R);

	free(root);

	return root;
}

int printIntoList(Position root, PositionList head)
{
	if (root == NULL)
		return 0;
	printIntoList(root->R, head);
	printf("%d ", root->element);
	elementFirst(head, root->element);
	printIntoList(root->L, head);

	return 0;
}
int elementFirst(PositionList head, int element)
{
	PositionList newListElement = NULL;
	PositionList last = NULL;

	newListElement = CreateNewListElement(element);
	if (!newListElement) {
		return -1;
	}
	last = FindLast(head);
	insertAfter(last, newListElement);

	return 0;


}
PositionList FindLast(PositionList head)
{
	PositionList temp = head;

	while (temp->next) {
		temp = temp->next;
	}

	return temp;
}
PositionList CreateNewListElement(int element)
{
	PositionList newListElement = NULL;
	newListElement = (PositionList)malloc(sizeof(list));
	if (!newListElement)
	{
		perror("Can't allocate memory!");
		return -1;
	}

	newListElement->element = element;
	newListElement->next = NULL;

	return newListElement;
}
int insertAfter(PositionList position, PositionList newListElement)
{
	newListElement->next = position->next;
	position->next = newListElement;

	return 0;
}
int intoFile(PositionList head, char* FileName)
{
	int i = 0;
	PositionList position = head->next;

	FILE* f = fopen(FileName, "w");
	if (!f) {
		printf("\n Datoteka nije otvorena!");
	}


	while (position != NULL)
	{
		i++;
		fprintf(f, "%d.\t %d \n ",i, position->element);
		position = position->next;
	}

	fclose(f);

	return 0;
}