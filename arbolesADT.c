#include "arbolesADT.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BLOCK 15

struct TNode1 {
    TQ1 hood;
    struct TNode1 * tail;
};

typedef struct TNode1 * TList1;

struct TNode23 {
    TQ23 Q23;
    TreeStreet * treeVec;
    int dimTreeVec;
    TreeStreet * streetVec;
    int dimStreetVec;
    int pQty;
    int tQty;
    struct TNode23 * tail;
};

typedef struct TNode23 * TList23;

struct TNode4 {
    TQ4 Q4;
    struct TNode4 * tail;
};

typedef struct TNode4 * TList4;

struct arbolesCDT {
    TList1 list1;
    int dim1;

    TList23 list23;
    int dim23;

    TList4 list4;
    int dim4;
};

arbolesADT newStruct () {
    return calloc(1, sizeof(struct arbolesCDT));
}

static TList23 addRecHood (TList23 list, char * hood, int pQty) {
    char c;
    if (list==NULL || (c=strcmp(hood, list->Q23.hood))<0) {
        TList23 aux=calloc(1,sizeof(*aux));
        aux->Q23.hood=hood;
        aux->pQty=pQty;
        aux->tail=list;
        return aux;
    }
    list->tail=addRecHood(list->tail, hood, pQty);
    return list;
}

void addHood (arbolesADT adt, char * hood, int pQty) {
    adt->list23=addRecHood(adt->list23, hood, pQty);
    adt->dim23++;
}

static TreeStreet * addQtyToVec(TreeStreet * vec, int * dim, char * name, TreeStreet * aux) {
    int i;
    for (i=0 ; i<*dim ; i++) {
        if (!strcmp(vec[i].name, name)) {
            vec[i].tQty++;
            *aux=vec[i];
            return vec;
        }
    }
    if (*dim%BLOCK==0) {
        vec=realloc(vec, sizeof(*vec)*(*dim+BLOCK));
    }
    vec[*dim].name=name;
    vec[*dim].tQty=1;
    *aux=vec[(*dim)++];
    return vec;
}

static void searchHood(TList23 list, char * hood, char * street, char * tree) {
    int c;
    if (list==NULL || (c=strcmp(hood, list->Q23.hood))<0)
        return;
    if (c==0) {
        list->tQty++;
        TreeStreet aux;
        list->treeVec=addQtyToVec(list->treeVec, &list->dimTreeVec, tree, &aux);
        if (aux.tQty > list->Q23.popTree.tQty)
            list->Q23.popTree=aux;

        list->streetVec=addQtyToVec(list->streetVec, &list->dimStreetVec, street, &aux);
        if (aux.tQty > list->Q23.popStreet.tQty)
            list->Q23.popStreet=aux;
        return;
    }
    searchHood(list->tail, hood, street, tree);
}

static TList4 addRecTreeQ4(TList4 list, char * name, double diam) {
    int c;
    if (list==NULL || (c=strcmp(name, list->Q4.tree))<0) {
        TList4 aux=malloc(sizeof(*aux));
        aux->Q4.tree=name;
        aux->Q4.dMin=aux->Q4.dMax=diam;
        aux->tail=list;
        return aux;
    }
    if (c==0) {
        if (diam<list->Q4.dMin)
            list->Q4.dMin=diam;
        else if (diam>list->Q4.dMax)
            list->Q4.dMax=diam;
        return list;
    }
    list->tail=addRecTreeQ4(list->tail, name, diam);
    return list;
}

void addTree (arbolesADT adt, char * hood, char * street, char * tree, double diam) {
    adt->list4=addRecTreeQ4(adt->list4, tree, diam);
    searchHood(adt->list23, hood, street, tree);
}

TQ1 * solveQ1(arbolesADT adt);

TQ23 * solveQ23(arbolesADT adt);

TQ4 * solveQ4(arbolesADT adt);

void freeADT (arbolesADT adt);

