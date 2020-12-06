#include "arbolesADT.h"
#include <stdio.h>
#include <stdlib.h>
#include "fileManagement.h"
#include "Q1ADT.h"

//Columns for trees data
#define MAX_COLS_BA 13 // (Starting at 1)

#define COL_HOOD_BA 3
#define COL_STREET_BA 5
#define COL_TREENAME_BA 8
#define COL_DIAM_BA 12

#define HEADERS_QUERY1 "BARRIO;ARBOLES_POR_HABITANTE"


void query1(arbolesADT adt){

    FILE * Q1File; 
    createFile(Q1File); // An empty file is created.

    fputs(HEADERS_QUERY1,Q1File); // The headers are added to the file.

    Q1ADT Q1 = newQ1struct();
    int dim;
    TQ1 * vec1 = solveQ1(Q1, &dim); // The query 1 is solved and the data is stores in vec1.

    for (int i=0;i<dim;i++){
        // Each element on vec1 is added to the file in the form of a line.
        fprintf("%s;%.2f\n", vec1[i].hood, vec1[i].density);
    }

    freeQ1(Q1); // The adt used to solve the first query is freed.
    fclose(Q1File); // The file is closed after being written.

}


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

    query1(adt);


}
