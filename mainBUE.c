#include "arbolesADT.h"
#include <stdio.h>
#include <stdlib.h>
#include "fileManagement.h"
#include "Q1ADT.h"

// Columns for trees data
#define MAX_COLS_BA 13 // (Starting at 1)

#define COL_HOOD_BA 3
#define COL_STREET_BA 5
#define COL_TREENAME_BA 8
#define COL_DIAM_BA 12

int main (int args, char * argv[]) {

    // Useful information:
    // argv[0] -> program name
    // argv[1] -> hoods file (csv)
    // argv[2] -> trees file (csv)

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

    error = readTrees(treesFile,adt,MAX_COLS_BA,COL_HOOD_BA,COL_STREET_BA,COL_TREENAME_BA,COL_DIAM_BA);
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
