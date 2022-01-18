#ifndef FUNKCIJE_H
#define FUNKCIJE_H


#define MAX_SIZE 128


typedef struct _poli;
typedef struct _poli* Position;


typedef struct _poli
{
    int koef;
    int expo;
    Position next;

}poli;



int fileScan(char* fileName, Position p1, Position p2);

int readP(char* buffer, Position p);

int sortP(Position newtemp, Position p);

Position newP(int k, int e);

int insertAfter(Position current, Position newtemp);

Position findBefore(Position p, Position temp);

int deleteP(Position p, Position temp);

int printP(Position first);

int addP(Position Zbroj, Position p1, Position p2);

int mulP(Position mulRes, Position p1, Position p2);


#endif