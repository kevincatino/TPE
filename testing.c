#include "arbolesADT.h"
#include <assert.h>

int main () {
    arbolesADT tree=newStruct();
    addHood(tree, "Campana", 10);
    addHood(tree, "Tokyo", 200);
    addHood(tree, "Buenos Aires", 100);

    addTree(tree, "Campana", "Paso", "B", 5);
    addTree(tree, "Campana", "Paso", "A", 20);
    addTree(tree, "Campana", "Paso", "A", 10);
    addTree(tree, "Tokyo", "Harajuku", "C", 5);
    addTree(tree, "Buenos Aires", "9 de Julio", "C", 20);
    addTree(tree, "Tokyo", "Shinjuku", "A", 35);
    addTree(tree, "Tokyo", "Shinjuku", "C", 35);
    addTree(tree, "Campana", "Rawson", "C", 40);
    addTree(tree, "Buenos Aires", "Moreno", "A", 10);
    addTree(tree, "Buenos Aires", "Rivadavia", "B", 15);
    addTree(tree, "Buenos Aires", "Moreno", "A", 15);
    addTree(tree, "Ciudad inexistente", "Moreno", "A", 15);

    int dim;

    TQ23 * vec23=solveQ23(tree, &dim);
    assert(dim==3);
    TQ23 test23[]= {{"Buenos Aires", {"A",2},{"Moreno", 2}},{"Campana", {"A",2},{"Paso", 3}},{"Tokyo", {"C",2},{"Shinjuku", 2}}};

    printf("Query2 and 3 should be:\n");
    for (int i=0 ; i<dim ; i++) {
        printf("%s;%s con %d;%s con %d\n", vec23[i].hood, vec23[i].popTree.name, vec23[i].popTree.tQty, vec23[i].popStreet.name, vec23[i].popStreet.tQty);
    }
    printf("\n");

    printf("Query2 and 3 is:\n");
    for (int i=0 ; i<dim ; i++) {
        printf("%s;%s con %d;%s con %d\n", test23[i].hood, test23[i].popTree.name, test23[i].popTree.tQty, test23[i].popStreet.name, test23[i].popStreet.tQty);
    }
    printf("\n");


    TQ4 * vec4=solveQ4(tree, &dim);
    assert(dim==3);
    TQ4 test4[]={{"A", 10, 35}, {"B", 5, 15},{"C", 5, 40}};

    printf("Query4 should be:\n");
    for (int i=0 ; i<dim ; i++) {
        printf("%s;%f,%f\n", test4[i].tree, test4[i].dMin, test4[i].dMax);
    }
    printf("\n");

    printf("Query4 is:\n");
    for (int i=0 ; i<dim ; i++) {
        printf("%s;%f,%f\n", vec4[i].tree, vec4[i].dMin, vec4[i].dMax);
    }
    printf("\n");
    /*
    TQ1 * vec1=solveQ4(tree, &dim);
    assert(dim==3);
    TQ1 test1[]={{"Campana", 0.4}, {"Buenos Aires", 0.05}, {"Tokyo", 0.015};

    printf("Query1 should be:");
    for (int i=0 ; i<dim ; i++) {
        printf("%s;%2.f\n", test1[i].hood, test1[i].density);
    }
    printf("\n");

    printf("Query1 is:");
    for (int i=0 ; i<dim ; i++) {
        printf("%s;%2.f\n", vec1[i].hood, vec1[i].density);
    }
    printf("\n");
    */



}
