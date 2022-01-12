#ifndef FUNKCIJE_H
#define FUNKCIJE_H

#define MAX_NAME 50
#define MAX_LENGHT 128

typedef struct _list;
typedef struct _list* PositionL;

typedef struct _list
{
	char imeGrada[MAX_NAME];
	int brojStanovnika;
	PositionL next;

}list;


typedef struct _tree;
typedef struct _tree* PositionT;

typedef struct _tree
{
	char imeDrzave[MAX_NAME];
	char imeDatotekeGradova[MAX_NAME];
	PositionL listHead;
	PositionT L;
	PositionT R;

}tree;


int menu(PositionT);

//tree related
PositionT createTreeElement(char*, char*);
PositionT insertTreeElement(PositionT, char*, char*);
PositionT ispisStabla(PositionT);
PositionT connectListAndTree(PositionT);

//list related
PositionL createListElement(char*, int);
int insertListElement(PositionL, char*, int);
int ispisiListu(PositionL );
PositionL createList(PositionT );

#endif