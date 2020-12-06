#include "arbolesADT.h"
#include <stdio.h>
#include <stdlib.h>

//Error codes:
#define WRONG_ARGS 1
#define ERROR_OPENING 2
#define NO_MEMORY 3
#define ERROR_CREATING 4

//Headers for the queries
#define HEADERS_QUERY1 "BARRIO;ARBOLES_POR_HABITANTE"
#define HEADERS_QUERY2 "BARRIO;NOMBRE_CIENTIFICO"
#define HEADERS_QUERY3 "BARRIO;CALLE_CON_MAS_ARBOLES;ARBOLES"
#define HEADERS_QUERY4 "NOMBRE_CIENTIFICO;MIN;MAX"

int checkArgs(int args);

int openFiles(FILE ** hoodsFile, FILE ** treesFile, char * argv[]);

int readHoods(FILE * hoodsFile, arbolesADT adt);

int readTrees(FILE * treesFile, arbolesADT adt, int maxCol, int hoodCol, int streetCol, int treeNameCol, int diamCol);

int createFile(FILE ** f, char * fileName);

int query1(arbolesADT adt, TQ23 * auxVec, int dim);

int query23(arbolesADT adt, TQ23 ** auxVec,int * auxDim);

int query4(arbolesADT adt);







