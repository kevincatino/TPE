#include "arbolesADT.h"
#include <stdio.h>
#include <stdlib.h>
#include "fileManagement.h"

#define MAX_LINE 128 // Max number of chars to read on each line when using fgets.

#define SEPARATOR ";"

int checkArgs(int args){
    if (!args==3){
        fprintf(stderr,"2 files expected. Please check the README file.\n");
        return WRONG_ARGS;
    }
    return 0;
}

int openFiles(FILE * hoodsFile, FILE * treesFile, char * argv[]){
    hoodsFile = fopen(argv[1],"r");
    treesFile = fopen(argv[2],"r");
    if (hoodsFile==NULL||treesFile==NULL){
        fprintf(stderr,"The file(s) couldn't be opened\n");
        return ERROR_OPENING;
    }
    return 0;
}

int createFile(FILE * f, char * fileName){
    f = fopen(fileName,"w");
    if (f==NULL){
        fprintf(stderr,"The file could't be created\n");
        return ERROR_CREATING;
    }
    return 0;
}

int readHoods(FILE * hoodsFile, arbolesADT adt){
    // Aux variables are defined
    char entireLine[MAX_LINE];
    char * read;
    char * hoodName;
    long hoodPop;
    // The first line (header) is ignored.
    fgets(NULL,MAX_LINE,hoodsFile);
    while (fgets(entireLine,MAX_LINE,hoodsFile)){
        // for each line, the first col is the hood name and the second one the population.
        read = strtok(entireLine,SEPARATOR);
        hoodName=read; // The name is read and stored.
        read = strtok(NULL,SEPARATOR);
        hoodPop = atol(read); // The population is read, converted to long and stored.
        int ok = addHood(adt,hoodName,hoodPop);
        if (!ok){
            // The hood is added to the ADT. If there's no memory, the execution aborts.
            fprintf(stderr,"There is no memory to save the hood.\n");
            return NO_MEMORY;
        }
        fclose(hoodsFile); // After the file was used, it's closed.
    }
    return 0;
}

int readTrees(FILE * treesFile, arbolesADT adt, int maxCol, int hoodCol, int streetCol, int treeNameCol, int diamCol){
    // void addTree (arbolesADT adt, char * hood, char * street, char * tree, double diam);
    // Aux variables defined
    char entireLine[MAX_LINE];
    char * read;
    char * hood;
    char * street;
    char * tree;
    double diam;

    fgets(NULL,MAX_LINE,treesFile); // The first line (header) is ignored.
    while (fgets(entireLine,MAX_LINE,treesFile)){
        //Each line in the cvs file is read
        for (int i=1,read=strtok(entireLine,SEPARATOR);i<maxCol;i++){
            // Every column of the line until maxCol is checked to extract the required data.
            if (i==hoodCol){
                hood=read;
            }
            if (i==streetCol){
                street=read;
            }
            if (i==treeNameCol){
                tree=read;
            }
            if (i==diamCol){
                diam = trtod(read,NULL); // The function converts the string to a double.
            }
        }
        //After all the data was retrieved, the tree is added.
        int ok = addTree(adt,hood,street,tree,diam);
        if (!ok){
            fprintf(stderr,"There is no memory to save the tree.\n");
            return NO_MEMORY;
        }
        fclose(treesFile); //After the file was used, it's closed.
    }
    return 0;
}




