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

int addHood (arbolesADT adt, char * hood, int pQty);

int addTree (arbolesADT adt, char * hood, char * street, char * tree, double diam);

TQ23 * solveQ23(arbolesADT adt, int * dim);

TQ4 * solveQ4(arbolesADT adt, int * dim);

void freeADT (arbolesADT adt);




#endif // ARBOLESADT_H_INCLUDED
