#include "arbolesADT.h"
#include "fileManagement.h"
#include "Q1ADT.h"

// Columns for trees data
#define MAX_COLS_BA 12 // (Starting at 1)

#define COL_HOOD_BA 3
#define COL_STREET_BA 5
#define COL_TREENAME_BA 8
#define COL_DIAM_BA 12


int main (int args, const char * argv[]) {

    // Useful information:
    // argv[0] -> program name
    // argv[1] -> hoods file (.csv)
    // argv[2] -> trees file (.csv)

    int error = checkArgs(args);
    if (error)
        return error;

    FILE * hoodsFile;
    FILE * treesFile;
    error = openFiles(&hoodsFile,&treesFile,argv);
    if (error)
        return error;

    arbolesADT adt = newStruct();

    error = readHoods(hoodsFile,adt);
    if (error)
        return error;

    error = readTrees(treesFile,adt,MAX_COLS_BA,COL_HOOD_BA,COL_STREET_BA,COL_TREENAME_BA,COL_DIAM_BA);
    if (error)
        return error;


    error=solveQuerys (adt);
    if (error)
      return error;


    return 0;
}
