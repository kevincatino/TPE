#include "arbolesADT.h"
#include <stdio.h>
#include <stdlib.h>
#include "fileManagement.h"
#include "Q1ADT.h"

#define MAX_COLS_VA 16

#define COL_HOOD_VA 13
#define COL_STREET_VA 12
#define COL_TREENAME_VA 7
#define COL_DIAM_VA 16

int main (int args, char * argv[]) {

    arbolesADT adt = newStruct();

    checkArgs(args);

    FILE * hoodsFile;
    FILE * treesFile;
    int error = openFiles(&hoodsFile,&treesFile,argv);
    if (error){
        return error;
    }

    error = readHoods(hoodsFile,adt);
    if (error){
        return error;
    }

    error = readTrees(treesFile,adt,MAX_COLS_VA,COL_HOOD_VA,COL_STREET_VA,COL_TREENAME_VA,COL_DIAM_VA);
    if (error){
        return error;
    }

    error = query4(adt);
    if (error){
        return error;
    }

    TQ23 * auxVec;
    int auxDim;

    error = query23(adt,&auxVec,&auxDim);
    if (error){
        return error;
    }
    error = query1(adt,auxVec,auxDim);
    if (error){
        return error;
    }

    printf("The files were created successfully\n");

    return 0;

}
