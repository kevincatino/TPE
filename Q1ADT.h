#ifndef Q1ADT_H_INCLUDED
#define Q1ADT_H_INCLUDED


typedef struct {
    char * hood;
    double density;
}TQ1;

typedef struct Q1CDT * Q1ADT;

Q1ADT newQ1struct ();

int addQ1hood(Q1ADT adt, char * hood, double density);

TQ1 * solveQ1(Q1ADT adt, int *dim);

void freeQ1 (Q1ADT adt);


#endif // Q1ADT_H_INCLUDED
