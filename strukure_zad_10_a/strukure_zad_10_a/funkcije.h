#ifndef FUNKCIJE_H
#define FUNKCIJE_H
#define _CRT_SECURE_NO_WARNINGS
#define MAX 50


typedef struct tree* PositionTree;

typedef struct tree
{
	char nazivGrada[MAX];
	int brojStanovnika;
	PositionTree L;
	PositionTree R;
}tree;


typedef struct list* PositionList;

typedef struct list
{
	char nazivDrzave[MAX];
	char nazivDatotekeGrada[MAX];
	PositionList next;
	PositionTree treeRoot;
	
}list;

//Lista
PositionList createListElement(char*, char*);
int insertListElement(char*, char*, PositionList);
int fileScanList(char*, PositionList);
int displayList(PositionList);


//Tree
PositionTree createTreeElement(char*, int);
PositionTree insertTreeElement(char*, int, PositionTree);
int fileScanTree(PositionList);
PositionTree displayTree(PositionTree);

//find
int findCitiesInRange(PositionList head, int rangemin);
PositionTree findCity(PositionTree root, int rangemin);
// findMin(PositionTree root, int rangemin);










#endif