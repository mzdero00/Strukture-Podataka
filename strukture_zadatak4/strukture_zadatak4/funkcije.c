#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "funkcije.h"

int fileScan(char* fileName, Position p1, Position p2)
{
    char buffer1[MAX_SIZE] = { 0 };
    char buffer2[MAX_SIZE] = { 0 };
    FILE* dat = NULL;
    dat = fopen(fileName, "r");

    if (!dat) {
        printf("Datoteka nije otvorena! \n");
        return -1;
    }

    fgets(buffer1, MAX_SIZE, dat);
    readP(buffer1, p1);

    fgets(buffer2, MAX_SIZE, dat);
    readP(buffer2, p2);

    fclose(dat);


    return 0;
}
int readP(char* buffer, Position p)
{
    int koef = 0, expo = 0, br = 0, n = 0;
    Position current = NULL;

    while (buffer[br] != '\0') {
        sscanf(buffer + br, " %d %d %n", &koef, &expo, &n);
        br += n;

        current = newP(koef, expo);

        if (current == NULL) {
            printf("Memorija nije alocirana!\n");
            return -2;
        }

        sortP(current, p);

    }
    return EXIT_SUCCESS;
}
Position newP(int k, int e)
{
    Position newtemp = NULL;
    newtemp = (Position)malloc(sizeof(poli));

    if (!newtemp)
    {
        printf("Memorija nije alocirana!\n");
        return EXIT_FAILURE;
    }

    newtemp->koef = k;
    newtemp->expo = e;
    newtemp->next = NULL;

    return newtemp;
}

int sortP(Position temp, Position head)
{
    Position current = head->next;
    Position prev = NULL;

    while ((current != NULL) && ((temp->expo) < (current->expo)))
        current = current->next;

    if (current != NULL && (temp->expo == current->expo)) {

        if (current->koef + temp->koef)
        {
            current->koef = current->koef + temp->koef;
        }

        else
        {
            deleteP(current, head);
            free(temp);
        }
    }

    else
    {

        prev = findBefore(head, current);
        insertAfter(prev, temp);
    }

    return 0;

}


int insertAfter(Position current, Position newtemp)
{
    newtemp->next = current->next;
    current->next = newtemp;
    return 0;
}



int deleteP(Position p, Position temp)
{
    Position delete = temp;
    Position current = NULL;


    if (delete)
    {
        current = findBefore(p, delete);
        current->next = delete->next;
        free(temp);

    }

    return 0;

}
Position findBefore(Position p, Position temp)
{
    Position current = NULL;
    current = p;
    while (current->next != temp)current = current->next;

    return current;
}

int printP(Position first)
{
    printf("\n");
    Position current = first;
    while (current != NULL)
    {
        printf("  %d x^%d", current->koef, current->expo);
        current = current->next;
    }
    return EXIT_SUCCESS;
}
int addP(Position Zbroj, Position p1, Position p2)
{
    Position current1 = p1->next;
    Position current2 = p2->next;
    Position newtemp = NULL;
    Position poliMul = NULL;
    while (current1 != NULL && current2 != NULL)
    {
        if (current1->expo == current2->expo)
        {
            newtemp = newP(current1->koef + current2->koef, current1->expo);
            sortP(newtemp, Zbroj);
            current1 = current1->next;
            current2 = current2->next;
        }
        else if (current1->expo < current2->expo)
        {
            newtemp = newP(current1->koef, current1->expo);
            sortP(newtemp, Zbroj);
            current1 = current1->next;
        }
        else
        {
            newtemp = newP(current2->koef, current2->expo);
            sortP(newtemp, Zbroj);
            current2 = current2->next;
        }

    }

    if (current1 == NULL)
    {
        poliMul = current2;
    }
    else
        poliMul = current1;


    while (poliMul != NULL)
    {
        newtemp = newP(poliMul->koef, poliMul->expo);

        sortP(newtemp, Zbroj);
        poliMul = poliMul->next;
    }
    return 0;
}
int mulP(Position mulRes, Position p1, Position p2)
{
    Position current1 = p1->next;
    Position current2 = p2->next;
    Position newtemp = NULL;
    while (current1)
    {
        current2 = p1;
        while (current2)
        {
            newtemp = newP(current1->koef * current2->koef, current1->expo + current2->expo);
            sortP(newtemp, mulRes);
            current2 = current2->next;
        }
        current1 = current1->next;

    }
    return 0;
}