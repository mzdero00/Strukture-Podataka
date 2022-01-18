#ifndef FUNKCIJE_H
#define FUNKCIJE_H


struct _stack;
typedef struct _stack* Position;
typedef struct _stack {
	double number;
	Position next;
} stack;



Position makeStack(double number);
int insertAfter(Position position, Position newElement);
int pushStack(Position head, double number);
int deleteElement(Position position);
int popStack(double* destination, Position head);
int doOperation(Position head, char operation);
int filePostFix(double* destination, char* fileName);



#endif
