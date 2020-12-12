#ifndef Q1ADT_H_INCLUDED
#define Q1ADT_H_INCLUDED

typedef struct Q1CDT * Q1ADT;

/*Structure used to return in array. "hood" is a string that contains the name of the neighborhood.
"density" is a double that stores the density of trees/population for a given neighborhood*/
typedef struct {
    const char * hood;
    double density;
}TQ1;

/*Creates structure and returns pointer to it*/
Q1ADT newQ1struct ();

/* Adds neighborhood name and density to the ADT. Returns 1 if the neighborhood is added correctly.
If an issue is encountered while allocating memory for it, the return value is 0*/
int addQ1hood(Q1ADT adt, const char * hood, double density);

/*Returns array of TQ1 structures that is in descending density order. If two neighborhoods have the same density, the order is in ascending alphabetical order*/
TQ1 * solveQ1(Q1ADT adt, int *dim);

/*Frees all allocated memory utilized to create and maintain the abstract data type*/
void freeQ1 (Q1ADT adt);


#endif // Q1ADT_H_INCLUDED
