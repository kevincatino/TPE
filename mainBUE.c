#include "arbolesADT.h"
#include <stdio.h>
#include <stdlib.h>
#include "fileManagement.h"
#include "Q1ADT.h"

// Error codes
#define NO_MEMORY 3
//#define ERROR_CREATING 4

// Columns for trees data
#define MAX_COLS_BA 13 // (Starting at 1)

#define COL_HOOD_BA 3
#define COL_STREET_BA 5
#define COL_TREENAME_BA 8
#define COL_DIAM_BA 12

//Headers for the queries
#define HEADERS_QUERY1 "BARRIO;ARBOLES_POR_HABITANTE"
#define HEADERS_QUERY2 "BARRIO;NOMBRE_CIENTIFICO"
#define HEADERS_QUERY3 "BARRIO;CALLE_CON_MAS_ARBOLES;ARBOLES"
#define HEADERS_QUERY4 "NOMBRE_CIENTIFICO;MIN;MAX"

int query1(arbolesADT adt, TQ23 * auxVec, int dim){

    FILE * Q1File; 
    int error = createFile(Q1File,"query1.csv"); // An empty file is created.
    if (error){
        return error;
    }

    fputs(HEADERS_QUERY1,Q1File); // The headers are added to the file.

    Q1ADT Q1 = newQ1struct(); // The q1 adt is created

    for (int i=0;i<dim;i++){
        // Q1 adt is pupulated with the data requested, extracted from the auxVec (from queries 2 and 3).
        int ok = addQ1hood(Q1,auxVec[i].hood, (double)auxVec[i].tQty/auxVec[i].pQty);
        if (!ok){
            return NO_MEMORY;
        }
    }
    
    TQ1 * vec1 = solveQ1(Q1, &dim); // The query 1 is solved and the data is stores in vec1.

    if (vec1==NULL){
        return NO_MEMORY;
    }

    for (int i=0;i<dim;i++){
        // Each element on vec1 is added to the file in the form of a line.
        fprintf(Q1File,"%s;%.2f\n", vec1[i].hood, vec1[i].density);
    }

    free(vec1);
    free(auxVec); 
    freeQ1(Q1); // The adt used to solve the first query is freed.
    fclose(Q1File); // The file is closed after being written.

    return 0;

}

 int query23(arbolesADT adt, TQ23 ** auxVec,int * auxDim){

    TQ23 * vec23 = solveQ23(adt,auxDim);

    if (vec23==NULL){
        return NO_MEMORY;
    }

    FILE * Q2File; // The file for the query 2 is created
    int error = createFile(Q2File,"query2.csv");
    if (error){
        return error;
    }
    fputs(HEADERS_QUERY2,Q2File); // The headers are added

    // The Q2File is populated with the data
    for (int i=0;i<auxDim;i++){
        // The data requested for each element on vec23 is added to the file in the form of a line.
        fprintf(Q2File,"%s;%s\n", vec23[i].hood, vec23[i].popTree.name);
    }

    fclose(Q2File);

    FILE * Q3File; 
    int error = createFile(Q3File,"query3.csv");
    if (error){
        return error;
    }
    fputs(HEADERS_QUERY3,Q3File);

    for (int i=0;i<auxDim;i++){
        fprintf(Q3File,"%s;%d\n", vec23[i].popStreet.name, vec23[i].popStreet.tQty);
    }

    fclose(Q3File);
    *auxVec = vec23; // The pointer to the vector vec23 is saved because it will be used to solve the query 1.

    return 0;

}

int query4(arbolesADT adt){

    int dim;
    TQ4 * vec4 = solveQ23(adt,&dim);

    if (vec4==NULL){
        return NO_MEMORY;
    }

    FILE * Q4File;
    int error = createFile(Q4File,"query4.csv");
    if (error){
        return error;
    }
    fputs(HEADERS_QUERY4,Q4File);

    for (int i=0;i<dim;i++){
        fprintf(Q4File,"%s;%.2f,%.2f\n", vec4[i].tree, vec4[i].dMin, vec4[i].dMax);
    }
    free(vec4);
    fclose(Q4File);
    return 0;

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
    int error = openFiles(hoodsFile,treesFile,argv);
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

    TQ23 * auxVec;
    int auxDim;

    error = query23(adt,&auxVec,&auxDim);
    if (error){
        return error;
    }
    error = query4(adt);
    if (error){
        return error;
    }
    error = query1(adt,&auxVec,&auxDim);
    if (error){
        return error;
    }
    
    printf("The files were created successfully");

    return 0;
    


}
