#include "arbolesADT.h"
#include <stdio.h>
#include <stdlib.h>

void checkArgs(int args);

void openFiles(FILE * hoodsFile, FILE * treesFile, char * argv[]);

void readHoods(FILE * hoodsFile, arbolesADT adt);

void readTrees(FILE * treesFile, arbolesADT adt, int maxCol, int hoodCol, int streetCol, int treeNameCol, int diamCol);




