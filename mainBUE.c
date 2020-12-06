#include "arbolesADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Error codes:
#define WRONG_ARGS 1
#define ERROR_OPENING 2
#define NO_MEMORY 3

#define MAX_LINE 128 // Max number of chars to read on each line.

//trees
#define MAX_COLS 5
#define COL_TREENAME 2
// etc

#define SEPARATOR ";"

void checkArgs(int args){
    //Checks if number of arguments is correct
    if (args != 3){
        fprintf(stderr, "Error! Incorrect amount of arguments.\n");
        return;
    } 
}

void openFiles(FILE * hoodsFile, FILE * treesFile, char * argv[]){
    hoodsFile = fopen(argv[1],"r");
    treesFile = fopen(argv[2],"r");
    if (hoodsFile == NULL || treesFile == NULL) {
        fprintf(stderr, "Error! File(s) could not be opened.\n");
        return;
    }
}

void readHoods(FILE * hoodsFile, arbolesADT adt) {
    char entireLine[MAX_LINE];
    char * read;
    char * hoodName;
    long hoodPop;
    while (fgets(entireLine,MAX_LINE,hoodsFile)){
        // for each line, the first col is the hood name and the second one the population.
        read = strtok(hoodsFile,SEPARATOR);
        strcpy(hoodName,read); // The name is read and stored.
        read = strtok(NULL,SEPARATOR);
        hoodPop = atol(read); // The population is read, converted to long and stored.
        if (!addHood(adt,hoodName,hoodPop)){
            // The hood is added to the ADT. If there's no memory, function returns 0.
            fprintf(stderr, "Error! Neighbourhood could not be added.\n");
            return;
        }
    }
}

int main (int args, char * argv[]) {

    // Useful information:
    // argv[0] -> program name
    // argv[1] -> hoods file (csv)
    // argv[2] -> trees file (csv)

    // AT THIS POINT THE ADT MUST HAVE BEEN CREATED. 
    // The assumed name is "adt".
    
    checkArgs(args);
    FILE * hoodsFile;
    FILE * treesFile;
    openFiles(hoodsFile,treesFile,argv);
    
    arbolesADT adt = newStruct();
    
    if (adt == NULL) {
        fprintf(stderr, "Error! Structure could not be created.\n");
        return NO_MEMORY;
    }

    readHoods(hoodsFile,adt);
}


