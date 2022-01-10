#ifndef FUNKCIJE_H
#define FUNKCIJE_H

typedef struct _Tree;
typedef struct _Tree* Position;

typedef struct _Tree
{
	int el;
	Position L;
	Position R;

}tree;


Position createElement(int el);   //Stvara novi element

Position insertElement(Position current, Position new); //Dodaje element u stablo

int replace(Position current);		//Funkcija koja zamjenjuje sve elemente u stablu sa zborojm njegove djece

//int randomNumber(int min, int max);

int printInOrder(Position current);	//Ispisuje cijelu listu in order nacinom

//int toFile(Position current, char* fileName);

#endif
