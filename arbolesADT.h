#ifndef ARBOLESADT_H_INCLUDED
#define ARBOLESADT_H_INCLUDED

typedef struct arbolesCDT * arbolesADT;

typedef struct {
    char * name;
    int tQty;
}TreeStreet;

typedef struct {
    char * hood;
    double density;
}TQ1;

typedef struct {
    char * hood;
    TreeStreet popTree;
    TreeStreet popStreet;
}TQ23;

typedef struct {
    char * tree;
    double dMin;
    double dMax;
}TQ4;

arbolesADT newStruct ();

void addHood (arbolesADT adt, char * hood, int pQty);

void addTree (arbolesADT adt, char * hood, char * street, char * tree, double diam);

TQ1 * solveQ1(arbolesADT adt);

TQ23 * solveQ23(arbolesADT adt);

TQ4 * solveQ4(arbolesADT adt);

void freeADT (arbolesADT adt);




#endif // ARBOLESADT_H_INCLUDED
