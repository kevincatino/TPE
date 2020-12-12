#include "arbolesADT.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <errno.h>
#define BLOCK 15

struct TNode23 {
    TQ23 Q23;
    TreeStreet * treeVec;
    int dimTreeVec;
    TreeStreet * streetVec;
    int dimStreetVec;
    struct TNode23 * tail;
};

typedef struct TNode23 * TList23;

struct TNode4 {
    TQ4 Q4;
    struct TNode4 * tail;
};

typedef struct TNode4 * TList4;

struct arbolesCDT {
    TList23 list23;
    int dim23;

    TList4 list4;
    int dim4;
};

arbolesADT newStruct () {
    arbolesADT tree = calloc(1, sizeof(struct arbolesCDT));
    if (tree == NULL || errno == ENOMEM) {
        fprintf(stderr, "Error! Unable to create new structure\n");
        return NULL;
    }
    return tree;
}

static TList23 addRecHood (TList23 list, const char * hood, int pQty, int *added) {
    if (list==NULL || strcasecmp(hood, list->Q23.hood)<0) {
        TList23 aux=calloc(1,sizeof(*aux));
        if (aux == NULL || errno == ENOMEM) {
            fprintf(stderr, "Error! Unable to add neighbourhood\n");
            return NULL;
        }
        aux->Q23.hood=malloc(sizeof(char)*(strlen(hood)+1));
        if (aux->Q23.hood==NULL || errno == ENOMEM) {
            fprintf(stderr, "Error! Unable to save neighbourhood name\n");
            return NULL;
        }
        strcpy(aux->Q23.hood, hood);
        aux->Q23.pQty=pQty;
        aux->tail=list;
        *added = 1;
        return aux;
    }
    list->tail=addRecHood(list->tail, hood, pQty, added);
    return list;
}

int addHood (arbolesADT adt, const char * hood, int pQty) {
    int added = 0;
    adt->list23=addRecHood(adt->list23, hood, pQty, &added);
    adt->dim23 += added;
    return adt->list23!=NULL;
}

static TreeStreet * addQtyToVec(TreeStreet * vec, int * dim, const char * name) {
    int i;
    for (i=0 ; i<*dim ; i++) {
        if (!strcmp(vec[i].name, name)) {
            vec[i].tQty++;
            return vec;
        }
    }
    if (*dim%BLOCK==0) {
        vec=realloc(vec, sizeof(*vec)*(*dim+BLOCK));
        if (vec==NULL || errno == ENOMEM) {
            fprintf(stderr, "Error! Memory allocation failure\n");
            return NULL;
        }
    }
    vec[*dim].name=malloc(sizeof(char)*(strlen(name)+1));
    strcpy(vec[*dim].name,name);
    vec[(*dim)++].tQty=1;
    return vec;
}

static int searchHood(TList23 list, const char * hood, const char * street, const char * tree) {
    int c;
    if (list==NULL || (c=strcasecmp(hood, list->Q23.hood))<0)
        return 1;
    if (c==0) {
        list->Q23.tQty++;
        list->treeVec=addQtyToVec(list->treeVec, &list->dimTreeVec, tree);
        if (list->treeVec==NULL)
            return 0;

        list->streetVec=addQtyToVec(list->streetVec, &list->dimStreetVec, street);
        if (list->streetVec==NULL)
            return 0;

        return 1;
    }
    return searchHood(list->tail, hood, street, tree);
}

static TList4 addRecTreeQ4(TList4 list, const char * name, double diam, int * added) {
    int c;
    if (list==NULL || (c=strcmp(name, list->Q4.tree))<0) {
        TList4 aux=malloc(sizeof(*aux));
        if (aux==NULL || errno == ENOMEM) {
            fprintf(stderr, "Error! Unable to add tree\n");
            return NULL;
        }
        aux->Q4.tree=malloc(sizeof(char)*(strlen(name)+1));
        if(aux->Q4.tree==NULL || errno == ENOMEM) {
            fprintf(stderr, "Error! Unable to save tree name\n");
            return NULL;
        }
        strcpy(aux->Q4.tree, name);
        aux->Q4.dMin=aux->Q4.dMax=diam;
        aux->tail=list;
        *added = 1;
        return aux;
    }
    if (c==0) {
        if (diam<list->Q4.dMin)
            list->Q4.dMin=diam;
        else if (diam>list->Q4.dMax)
            list->Q4.dMax=diam;
        return list;
    }
    list->tail=addRecTreeQ4(list->tail, name, diam, added);
    return list;
}

int addTree (arbolesADT adt, const char * hood, const char * street, const char * tree, double diam) {
    int added = 0;
    adt->list4=addRecTreeQ4(adt->list4, tree, diam, &added);
    adt->dim4+=added;
    return adt->list4!=NULL && searchHood(adt->list23, hood, street, tree);
}

static TreeStreet popValue(TreeStreet * vec, int dim) {
  TreeStreet aux;
  aux.tQty=0;
  for (int i=0 ; i<dim ; i++) {
    if (vec[i].tQty>aux.tQty)
      aux=vec[i];
  }
  return aux;
}

TQ23 * solveQ23(arbolesADT adt, int * dim) {
    TQ23 *vec = malloc(sizeof(TQ23) * adt->dim23);
    if (vec==NULL)
        return NULL;
    *dim=adt->dim23;
    size_t k = 0;
    TList23 aux = adt->list23;
    while (aux != NULL) {
        aux->Q23.popTree =popValue(aux->treeVec, aux->dimTreeVec);
        aux->Q23.popStreet=popValue(aux->streetVec, aux->dimStreetVec);
        vec[k++]=aux->Q23;
        aux = aux->tail;
    }
    return vec;
}

TQ4 * solveQ4(arbolesADT adt, int * dim) {
    TQ4 *vec = malloc(sizeof(TQ4) * adt->dim4);
    if (vec==NULL)
        return NULL;
    *dim=adt->dim4;
    size_t k = 0;
    TList4 aux = adt->list4;
    while (aux != NULL) {
        vec[k++] = aux->Q4;
        aux = aux->tail;
    }
    return vec;
}

static void freeVecElems(TreeStreet * vec, int dim) {
    for (int i=0 ; i<dim ; i++) {
        free(vec[i].name);
    }
    return;
}

static void freeList23(TList23 list) {
    if (list == NULL)
        return;
    freeVecElems(list->treeVec, list->dimTreeVec);
    free(list->treeVec);
    freeVecElems(list->streetVec, list->dimStreetVec);
    free(list->streetVec);
    free(list->Q23.hood);
    freeList23(list->tail);
    free(list);
}

static void freeList4(TList4 list) {
    if (list == NULL)
        return;
    free(list->Q4.tree);
    freeList4(list->tail);
    free(list);
}

void freeADT (arbolesADT adt) {
    freeList23(adt->list23);
    freeList4(adt->list4);
    free(adt);
    return;
}
