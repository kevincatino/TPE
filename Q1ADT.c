#include "Q1ADT.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct TNode {
    TQ1 Q1;
    struct TNode * tail;
};

typedef struct TNode * TList;

struct Q1CDT {
    TList list;
    int dim;
};

Q1ADT newQ1struct () {
    Q1ADT newQ1 = calloc(1, sizeof(struct Q1CDT));
    if (newQ1 == NULL)
        return NULL;
    return newQ1;
}

static TList addRec(TList list, char * hood, double density) {
    if (list==NULL || density > list->Q1.density) { //if two hoods have the same density, the one that is already on the list remains on that position.
        TList aux=malloc(sizeof(*aux));
        if (aux==NULL) {
            return NULL;
        }
        aux->Q1.hood=hood;
        aux->Q1.density=density;
        aux->tail=list;
        return aux;
    }
    list->tail=addRec(list->tail, hood, density);
    return list;
}

/*
static void truncate (double *val) {
    *val *= 100;
    int aux = (int)*val;
    *val = aux/100.0;
};
*/

static void addToVec(TList list, TQ1 * vec) {
    if (list==NULL)
        return;
    vec[0]=list->Q1;
    addToVec(list->tail, vec+1);
}

int addQ1hood(Q1ADT adt, char * hood, double density) {
    adt->list=addRec(adt->list, hood, density);
    (adt->dim)++;
    return adt->list != NULL;
}

TQ1 *solveQ1(Q1ADT adt, int * dim) {
    TQ1 * vec =malloc(sizeof(*vec)*(adt->dim));
    if (vec==NULL)
        return NULL;
    *dim=adt->dim;
    addToVec(adt->list, vec);
    return vec;
}

static void freeQ1Rec(TList list) {
    if (list==NULL)
        return;
    freeQ1Rec(list->tail);
    free(list);
}

void freeQ1 (Q1ADT adt) {
    freeQ1Rec(adt->list);
    free(adt);
}

