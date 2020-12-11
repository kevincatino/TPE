#include "arbolesADT.h"
#include "Q1ADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "fileManagement.h"

#define MAX_LINE 256 // Max number of chars to read on each line when using fgets.

#define ARG_QTY 3

#define SEPARATOR ";"

void errorMsg (int code) {
    switch (code) {
        case WRONG_ARGS:
            fprintf(stderr,"2 files expected. Please check the README file.\n");
            break;
        case ERROR_OPENING:
            fprintf(stderr,"The file(s) could not be opened\n");
            break;
        case NO_MEMORY:
            fprintf(stderr,"Memory allocation failure\n");
            break;
        case ERROR_CREATING:
            fprintf(stderr,"The file(s) could not be created\n");
            break;
    }
}

int checkArgs(int args){
    if (args!=ARG_QTY){
        errorMsg(WRONG_ARGS);
        return WRONG_ARGS;
    }
    return 0;
}

int openFiles(FILE ** treesFile, FILE ** hoodsFile, const char * argv[]){
    *treesFile = fopen(argv[1],"r");
    *hoodsFile = fopen(argv[2],"r");
    if (hoodsFile==NULL||treesFile==NULL){
        errorMsg(ERROR_OPENING);
        return ERROR_OPENING;
    }
    return 0;
}

static int createFile(FILE ** f, const char * fileName){
    *f = fopen(fileName,"w");
    if (*f==NULL){
        errorMsg(ERROR_CREATING);
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
    fgets(entireLine,MAX_LINE,hoodsFile);
    while (fgets(entireLine,MAX_LINE,hoodsFile)!=NULL){
        // for each line, the first col is the hood name and the second one the population.
        read = strtok(entireLine,SEPARATOR);
        hoodName=read; // The name is read and stored.
        read = strtok(NULL,SEPARATOR);
        hoodPop = atol(read); // The population is read, converted to long and stored.
        int ok = addHood(adt,hoodName,hoodPop);
        if (!ok){
            // The hood is added to the ADT. If there's no memory, the execution aborts.
            errorMsg(NO_MEMORY);
            return NO_MEMORY;
        }
    }
    fclose(hoodsFile); // After the file was used, it's closed.
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

    fgets(entireLine,MAX_LINE,treesFile); // The first line (header) is ignored.
    while (fgets(entireLine,MAX_LINE,treesFile)!=NULL){
        //Each line in the cvs file is read
        read=strtok(entireLine,SEPARATOR);
        for (int i=1;i<=maxCol; i++,read=strtok(NULL,SEPARATOR)){
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
                diam = strtod(read,NULL); // The function converts the string to a double.
            }
        }
        //After all the data was retrieved, the tree is added.
        int ok = addTree(adt,hood,street,tree,diam);
        if (!ok){
            errorMsg(NO_MEMORY);
            return NO_MEMORY;
        }
    }
    fclose(treesFile); //After the file was used, it's closed.
    return 0;
}

static int query1(arbolesADT adt, TQ23 * auxVec, int dim){
    FILE * Q1File;
    int error = createFile(&Q1File,"query1.csv"); // An empty file is created.
    if (error){
        return error;
    }

    fputs(HEADERS_QUERY1,Q1File); // The headers are added to the file.

    Q1ADT Q1 = newQ1struct(); // The q1 adt is created

    for (int i=0;i<dim;i++){
        // Q1 adt is filled with the data requested, extracted from auxVec (from queries 2 and 3).
        int ok = addQ1hood(Q1,auxVec[i].hood, (double)auxVec[i].tQty/auxVec[i].pQty);
        if (!ok){
            errorMsg(NO_MEMORY);
            return NO_MEMORY;
        }
    }

    TQ1 * vec1 = solveQ1(Q1, &dim); // The query 1 is solved and the data is stored in vec1.

    if (vec1==NULL){
        errorMsg(NO_MEMORY);
        return NO_MEMORY;
    }

    for (int i=0;i<dim;i++){
        // Each element on vec1 is added to the file in the form of a line.
        fprintf(Q1File,"%s;%.2f\n", vec1[i].hood, vec1[i].density);
    }

    free(vec1);
    free(auxVec);
    freeQ1(Q1); // The adt used to solve the first query is freed.
    freeADT(adt);
    fclose(Q1File); // The file is closed after being written.

    return 0;

}

 static int query23(arbolesADT adt, TQ23 ** auxVec, int * auxDim){

    TQ23 * vec23 = solveQ23(adt,auxDim);

    if (vec23==NULL){
        errorMsg(NO_MEMORY);
        return NO_MEMORY;
    }

    FILE * Q2File; // The file for the query 2 is created
    int error = createFile(&Q2File,"query2.csv");
    if (error){
        return error;
    }
    fputs(HEADERS_QUERY2,Q2File); // The headers are added

    // The Q2File is populated with the data
    for (int i=0;i<*auxDim;i++){
        // The data requested for each element on vec23 is added to the file in the form of a line.
        char * treeName="No trees";
        if (vec23[i].tQty>0)
          treeName=vec23[i].popTree.name;
        fprintf(Q2File,"%s;%s\n", vec23[i].hood,treeName);
    }

    fclose(Q2File);
    FILE * Q3File;
    error = createFile(&Q3File,"query3.csv");
    if (error){
        return error;
    }


    fputs(HEADERS_QUERY3,Q3File);

    for (int i=0;i<*auxDim;i++){
      char * streetName="No trees";
      if (vec23[i].tQty>0)
        streetName=vec23[i].popStreet.name;
      fprintf(Q3File,"%s;%s;%d\n", vec23[i].hood, streetName, vec23[i].popStreet.tQty);
    }

    fclose(Q3File);
    *auxVec = vec23; // The pointer to the vector vec23 is saved because it will be used to solve the query 1.

    return 0;

}

static int query4(arbolesADT adt){

    int dim;
    TQ4 * vec4 = solveQ4(adt,&dim);
    if (vec4==NULL){
        errorMsg(NO_MEMORY);
        return NO_MEMORY;
    }

    FILE * Q4File;
    int error = createFile(&Q4File,"query4.csv");
    if (error){
        return error;
    }
    fputs(HEADERS_QUERY4,Q4File);

    for (int i=0;i<dim;i++){
        fprintf(Q4File,"%s;%.2f;%.2f\n", vec4[i].tree, vec4[i].dMin, vec4[i].dMax);
    }
    free(vec4);
    fclose(Q4File);
    return 0;

}

int solveQuerys (arbolesADT adt) {
  int error;
  error = query4(adt);
  if (error)
      return error;

  TQ23 * auxVec;
  int auxDim;

  error = query23(adt,&auxVec,&auxDim);
  if (error)
      return error;

  error = query1(adt,auxVec,auxDim);
  if (error)
      return error;

  printf("The files were created successfully\n");
  return 0;
}
