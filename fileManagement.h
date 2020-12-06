#include "arbolesADT.h"
#include <stdio.h>
#include <stdlib.h>

//Error codes:
#define WRONG_ARGS 1
#define ERROR_OPENING 2
#define NO_MEMORY 3
#define ERROR_CREATING 4

int checkArgs(int args);

int openFiles(FILE * hoodsFile, FILE * treesFile, char * argv[]);

int readHoods(FILE * hoodsFile, arbolesADT adt);

int readTrees(FILE * treesFile, arbolesADT adt, int maxCol, int hoodCol, int streetCol, int treeNameCol, int diamCol);








