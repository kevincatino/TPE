#include "arbolesADT.h"
#include "Q1ADT.h"
#include <assert.h>
#include <stdio.h>

int main () {
    arbolesADT tree=newStruct();
    assert(addHood(tree, "Campana", 10));
    assert(addHood(tree, "Tokyo", 200));
    assert(addHood(tree, "Buenos Aires", 100));

    assert(addTree(tree, "Campana", "Paso", "B", 5));
    assert(addTree(tree, "Campana", "Paso", "A", 20));
    assert(addTree(tree, "Campana", "Paso", "A", 10));
    assert(addTree(tree, "Tokyo", "Harajuku", "C", 5));
    assert(addTree(tree, "Buenos Aires", "9 de Julio", "C", 20));
    assert(addTree(tree, "Tokyo", "Shinjuku", "A", 35));
    assert(addTree(tree, "Tokyo", "Shinjuku", "C", 35));
    assert(addTree(tree, "Campana", "Rawson", "C", 40));
    assert(addTree(tree, "Buenos Aires", "Moreno", "A", 10));
    assert(addTree(tree, "Buenos Aires", "Rivadavia", "B", 15));
    assert(addTree(tree, "Buenos Aires", "Moreno", "A", 15));
    assert((tree, "Ciudad inexistente", "Moreno", "A", 15));

    int dim;
    TQ4 * vec4=solveQ4(tree, &dim);
    assert(dim==3);
    TQ4 test4[]={{"A", 10, 35}, {"B", 5, 15},{"C", 5, 40}};

    printf("Query4 should be:\n");
    for (int i=0 ; i<dim ; i++) {
        printf("%s;%.2f,%.2f\n", test4[i].tree, test4[i].dMin, test4[i].dMax);
    }
    printf("\n");

    printf("Query4 is:\n");
    for (int i=0 ; i<dim ; i++) {
        printf("%s;%.2f,%.2f\n", vec4[i].tree, vec4[i].dMin, vec4[i].dMax);
    }
    printf("\n");

    TQ23 * vec23=solveQ23(tree, &dim);
    assert(dim==3);
    TQ23 test23[]= {{"Buenos Aires", {"A",2},{"Moreno", 2},100,4},{"Campana", {"A",2},{"Paso", 3},10,5},{"Tokyo", {"C",2},{"Shinjuku", 2},200,4}};

    printf("Query2 and 3 should be:\n");
    for (int i=0 ; i<dim ; i++) {
        printf("%s;%s con %d;%s con %d;%d people;%d trees\n", vec23[i].hood, vec23[i].popTree.name, vec23[i].popTree.tQty, vec23[i].popStreet.name, vec23[i].popStreet.tQty, vec23[i].pQty, vec23[i].tQty);
    }
    printf("\n");

    printf("Query2 and 3 is:\n");
    for (int i=0 ; i<dim ; i++) {
        printf("%s;%s con %d;%s con %d;%d people;%d trees\n", test23[i].hood, test23[i].popTree.name, test23[i].popTree.tQty, test23[i].popStreet.name, test23[i].popStreet.tQty,vec23[i].pQty, vec23[i].tQty);
    }
    printf("\n");


    Q1ADT q1=newQ1struct();
    for (int i=0 ; i<dim ; i++) {
        assert(addQ1hood(q1, vec23[i].hood, (double)vec23[i].tQty/vec23[i].pQty));
    }

    TQ1 * vec1=solveQ1(q1, &dim);
    assert(dim==3);
    TQ1 test1[]={{"Campana", 0.4}, {"Buenos Aires", 0.04}, {"Tokyo", 0.015}};

    printf("Query1 should be:\n");
    for (int i=0 ; i<dim ; i++) {
        printf("%s;%.2f\n", test1[i].hood, test1[i].density);
    }
    printf("\n");

    printf("Query1 is:\n");
    for (int i=0 ; i<dim ; i++) {
        printf("%s;%.2f\n", vec1[i].hood, vec1[i].density);
    }
    printf("\n");

    freeQ1(q1);
    freeADT(tree);

      free(vec1);
      free(vec23);
      free(vec4);



}
