#ifndef ARBOLESADT_H_INCLUDED
#define ARBOLESADT_H_INCLUDED

typedef struct arbolesCDT * arbolesADT;
/*Generic structure that stores a string and an integer*/
typedef struct {
    char * name;
    int tQty;
}TreeStreet;

/*Structure that will be returned in the form of an array in following functions. "hood" is a string that stores the name of the neighborhood. The following
variables store a value related to the given neighborhood represented by the string "hood".
"popTree" stores the most popular tree name and the quantity. "popStreet" stores the street with the most trees.
"pQty" is an integer that stores the population and "tQty" stores the total amount of trees.*/
typedef struct {
    char * hood;
    TreeStreet popTree;
    TreeStreet popStreet;
    int pQty;
    int tQty;
}TQ23;

/*Structure that will be returned in the form of an array in following functions. "tree" is a string that stores the name of the
species of a given tree. The following variables store a value related to the tree species represented by "tree".
"dMin" stores the minimum diameter recorded. "dMax" stores the maximum diameter recorded.*/
typedef struct {
    char * tree;
    double dMin;
    double dMax;
}TQ4;

/*Returns a pointer to the abstract data type*/
arbolesADT newStruct ();

/* Adds neighborhood name and population to the ADT. Returns 1 if the neighborhood is added correctly.
If an issue is encountered while allocating memory for it, the return value is 0*/
int addHood (arbolesADT adt, const char * hood, int pQty);

/* Adds tree species to the ADT. Returns 1 if the all values are added correctly.
If an issue is encountered while allocating memory for it, the return value is 0*/
int addTree (arbolesADT adt, const char * hood, const char * street, const char * tree, double diam);

/*Returns an array of TQ23 structures that is ordered by neighborhood names in alphabetical order.
The dimension of the array is stored in *dim.
If the array is generated correctly, the pointer returned has a value different from NULL.
If an error is encountered while allocating memory for it, the return value is NULL*/
TQ23 * solveQ23(arbolesADT adt, int * dim);

/*Returns an array of TQ4 structures that is ordered by the name of tree species in alphabetical order.
The dimension of the array is stored in *dim.
If the array is generated correctly, the pointer returned has a value different from NULL.
If an error is encountered while allocating memory for it, the return value is NULL*/
TQ4 * solveQ4(arbolesADT adt, int * dim);

/*Frees all allocated memory utilized to create and maintain the abstract data type*/
void freeADT (arbolesADT adt);




#endif // ARBOLESADT_H_INCLUDED
