#include "arbolesADT.h"
#include <stdio.h>
#include <stdlib.h>


//Error codes:
#define WRONG_ARGS 1
#define ERROR_OPENING 2
#define NO_MEMORY 3
#define ERROR_CREATING 4

//Headers for the queries
#define HEADERS_QUERY1 "BARRIO;ARBOLES_POR_HABITANTE\n"
#define HEADERS_QUERY2 "BARRIO;NOMBRE_CIENTIFICO\n"
#define HEADERS_QUERY3 "BARRIO;CALLE_CON_MAS_ARBOLES;ARBOLES\n"
#define HEADERS_QUERY4 "NOMBRE_CIENTIFICO;MIN;MAX\n"

void errorMsg (int code);

int checkArgs(int args);

int openFiles(FILE ** hoodsFile, FILE ** treesFile, const char * argv[]);

int readHoods(FILE * hoodsFile, arbolesADT adt);

int readTrees(FILE * treesFile, arbolesADT adt, int maxCol, int hoodCol, int streetCol, int treeNameCol, int diamCol);

int solveQuerys (arbolesADT adt, const char * folder);
