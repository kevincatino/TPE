#include "arbolesADT.h"
#include <stdio.h>
#include <stdlib.h>
#include "fileManagement.h"

//Columns for trees data
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
    openFiles(hoodsFile,treesFile,argv);

    readHoods(hoodsFile,adt);
    readTrees(treesFile,adt,MAX_COLS_BA,COL_HOOD_BA,COL_STREET_BA,COL_TREENAME_BA,COL_DIAM_BA);
    




}
