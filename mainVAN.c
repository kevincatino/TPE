#include "arbolesADT.h"
#include "fileManagement.h"
#include "Q1ADT.h"

#define MAX_COLS_VA 16

#define COL_HOOD_VA 13
#define COL_STREET_VA 12
#define COL_TREENAME_VA 7
#define COL_DIAM_VA 16


int main (int args, const char * argv[]) {

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

    error = readTrees(treesFile,adt,MAX_COLS_VA,COL_HOOD_VA,COL_STREET_VA,COL_TREENAME_VA,COL_DIAM_VA);
    if (error)
        return error;

    error=solveQuerys (adt);
    if (error)
      return error;

    return 0;

}
