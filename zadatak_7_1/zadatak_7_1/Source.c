#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 30

typedef struct dir* Pos_D;
typedef struct stack* Pos_S;

typedef struct dir {
	char* ime;
	Pos_D brat;
	Pos_D dijete;
}Dir;

typedef struct stack {
	Pos_D directory;

	Pos_S next;
	Pos_S prev;
}Stack;

Pos_D pop(Pos_S);
Pos_D changeDirectory(Pos_D, Pos_S);
Pos_D Back(Pos_D, Pos_S);
int Line(Pos_S, Pos_D, Pos_D);
Pos_S last(Pos_S);
int makeDirectory(Pos_D);
int menu(Pos_D, Pos_S);
int directory(Pos_D);
Pos_D findName(char*, Pos_D);
int push(Pos_S, Pos_D);


int main()
{
	Pos_D root;
	Pos_S head;

	root = (Pos_D)malloc(sizeof(Dir));
	root->dijete = NULL;
	root->brat = NULL;

	
	head = (Pos_S*)malloc(sizeof(Stack));
	head->next = NULL;
	head->prev = NULL;
	root->ime = "C:";

	int status = 110;

	while (status) {
		status = menu(root, head);
	}

	return 0;
}

int Line(Pos_S head, Pos_D root, Pos_D curr)
{
	Pos_S s;

	s = last(head);

	if (head->next == NULL) {
		printf("%s>", root->ime);
		return EXIT_SUCCESS;
	}

	while (s->prev != NULL) {
		printf("%s>", s->directory->ime);
		s = s->prev;
	}

	printf("%s>", curr->ime);

	return EXIT_SUCCESS;
}

Pos_S last(Pos_S head)
{
	Pos_S s;
	s = head->next;

	if (s == NULL) {
		return NULL;
	}

	while (s->next != NULL) {
		s = s->next;
	}

	return s;
}

int menu(Pos_D root, Pos_S head) {
	Pos_D curr = root;
	char a[MAX] = { 0 };

	
	printf("md ime_mape\ncd ime_mape\ncd.. \n dir\n exit\n" );
	

	while (1) {

		Line(head, root, curr);
		scanf("%s", a);

		if (!strcmp(a, "md")) {
			makeDirectory(curr);
		}

		else if (!strcmp(a, "cd")) {
			curr = changeDirectory(curr, head);
		}

		else if (!strcmp(a, "cd..")) {
			curr = Back(curr, head);
		}

		else if (!strcmp(a, "dir")) {
			directory(curr);
		}

		else if (!strcmp(a, "exit")) {
			system("cls");
			return 0;
		}

		else
			printf("\nPogreska n");
	}

	return EXIT_SUCCESS;
}

int makeDirectory(Pos_D curr) {
	Pos_D directory;
	directory = (Pos_D)malloc(sizeof(Dir));
	directory->ime = (char*)malloc(MAX * sizeof(char));

	if (!directory)
		printf("\nGreska pri alokaciji memorije\n");

	if (curr->dijete != NULL) {
		curr = curr->dijete;
		while (curr->brat != NULL) {
			curr = curr->brat;
		}
		curr->brat = directory;
	}

	else
		curr->dijete = directory;

	scanf(" %s", directory->ime);

	directory->brat = NULL;
	directory->dijete = NULL;

	return EXIT_SUCCESS;
}

int directory(Pos_D curr) {
	if (curr->dijete == NULL) {
		printf("Mapa je prazna\n");
		return EXIT_SUCCESS;
	}

	curr = curr->dijete;

	printf("Mape: \n");
	printf("\t%s\n", curr->ime);

	while (curr->brat != NULL) {
		printf("\t%s\n", curr->brat->ime);
		curr = curr->brat;
	}

	return EXIT_SUCCESS;
}

Pos_D findName(char* ime, Pos_D curr) {
	if (curr->dijete == NULL) {
		printf("\nMapa je prazna!\n");
		return EXIT_SUCCESS;
	}

	curr = curr->dijete;

	while (strcmp(ime, curr->ime) != 0 && curr->brat != NULL) {
		curr = curr->brat;
	}

	if (curr->brat == NULL) {
		if (strcmp(ime, curr->ime) != 0)
			return NULL;
		else
			return curr;
	}

	else
		return curr;
}

int push(Pos_S head, Pos_D directory) {

	Pos_S q = (Pos_S)malloc(sizeof(Stack));

	q->next = head->next;
	q->prev = head;

	if (head->next != NULL) {
		head->next->prev = q;
	}

	head->next = q;
	q->directory = directory;

	return EXIT_SUCCESS;
}

Pos_D pop(Pos_S head) {

	Pos_S q = (Pos_S)malloc(sizeof(Stack));
	Pos_D p;

	if (head->next == NULL)
		return NULL;

	q = head->next;
	p = q->directory;
	head->next = head->next->next;

	if (head->next != NULL)
		head->next->prev = head;

	free(q);

	return p;
}

Pos_D Back(Pos_D curr, Pos_S head)
{
	Pos_D s;

	s = pop(head);

	if (s == NULL) {
		printf("\nPogreska\n");
		s = curr;
	}

	return s;
}

Pos_D changeDirectory(Pos_D curr, Pos_S head)
{
	Pos_D s;
	char* ime;
	ime = (char*)malloc(MAX * sizeof(char));

	scanf("%s", ime);

	if (curr->dijete == NULL) {
		printf("Pogreska\n");
		return curr;
	}

	s = findName(ime, curr);

	if (s == 0) {
		printf("Direktorija nema\n");
		return curr;
	}

	push(head, curr);

	return s;
}