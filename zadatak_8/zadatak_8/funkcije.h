#ifndef FUNKCIJE_H
#define FUNKCIJE_H

typedef struct _tree;
typedef struct _tree* Position;

typedef struct _tree
{
	int element;
	Position L;
	Position R;
}tree;

//izbornik
int menu(Position);
//unosenje elementa
Position createElement(int);
Position insertElement(Position, int);
//ispisi
Position printInOrder(Position );
Position printPreOrder(Position);
Position printPostOrder(Position );
//brisanje stabla
Position deallocTree(Position );
//level order
Position printCurrentLevel(Position , int);
int dubina(Position);
Position printLevelOrder(Position );

//brisanje odredenog elementa (treba usavrsiti)
Position findElement(Position, int);
Position minElement(Position);
Position deleteElement(Position ,int );


#endif
