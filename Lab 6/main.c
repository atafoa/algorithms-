#include <stdio.h>
#include <stdlib.h>

int** array;
int* predecessorStack;
int stackPointer = 0;
int vertices, invert;

int hasTwoPebbles(int z);
void direct(int x, int y);
void findPebble(int z);
void getPebble(int z, int pebble);
void printVertice(int size);
void mallocFail();

int main() {
    int i, x, y;
    scanf("%d", &vertices);
    array = (int**)malloc(sizeof(int*) * vertices);
    predecessorStack = (int*)malloc(sizeof(int) * vertices);
    if (!array || !predecessorStack) {mallocFail();}
    for (i = 0; i < vertices; i++) {
	    array[i] = (int*)malloc(sizeof(int) * 2);
	    if (!array[i]) {mallocFail();}
	    array[i][0] = array[i][1] = -1;
    }
    for (i = 0; i < (vertices*2)-3; i++) {
	    scanf("%d %d", &x, &y);
        printf("Processing {%d, %d}\n", x, y);
        invert = 0;
	    findPebble(x);  // Get 2 pebbles at x.
        findPebble(y);  // Get 2 pebbles at y.
        printVertice(vertices);
        if (hasTwoPebbles(x) && hasTwoPebbles(y)) {
            printf("\t\t\t\t\t\t\t\tHIT\n");
            //if (!invert) {    
                printf("Directing %d to %d\n\n", x, y);
                direct(x, y);
                printVertice(vertices);    
            //}
            /*else {
                printf("Inverted directing %d to %d\n\n", y, x);
                direct(y, x);
                printVertice(vertices);
            }*/
            
        }
        else {
            printf("\t\t\t\t\t\t\t\tMISS\n");
        }
    }
    printVertice(vertices);
    return 0;
}

int hasTwoPebbles(int z) {
    if (array[z][0] == -1 && array[z][1] == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

void direct(int x, int y) {
    array[x][0] = y;    // X's pebble now points to Y.
}

void findPebble(int z) {
    if (array[z][0] == -1 && array[z][1] == -1) { // Base case. Pebbles already exist.
        printf("Base case, both pebbles exist at vertex %d.\n", z);
        return;
    }
    if (array[z][0] != -1) { // First pebble does not exist.
        printf("First pebble doesn't exist at %d.\n", z);
        getPebble(z, 0);    // Get a pebble where z0 points to.
        invert = 1;
    }
    if (array[z][1] != -1) { // Second pebble does not exist.
        printf("Second pebble doesn't exist at %d.\n", z);
        getPebble(z, 1);    // Get a pabble where z1 points to.
        invert = 1;
    }
}

void getPebble(int z, int pebble) {
    printf("Getting a pebble.\n");
    printf("The stack pointer is currently %d compared to %d vertices.\n", stackPointer, vertices);
    if (stackPointer++ > vertices*2) {
        printf("Returning.\n");
        return;
    }
    // check where pebble points to!
    // if no pebble exists, go deeper.

    if (array[array[z][pebble]][0] != -1 && array[array[z][pebble]][1] != -1) {
        printf("No pebble existed. Looking at %d now.\n", array[z][pebble]);
        getPebble(array[z][pebble], 0); // try and grab a single pebble
        if (array[z][pebble] != -1) {
            getPebble(array[z][pebble], 1); // try and grab a single pebble        
        }
        stackPointer++;
    }
    // otherwise, we can pull it back.
    if (array[array[z][pebble]][0] == -1) {
        printf("Returning, with a pebble from position %d.\n", array[z][pebble]);
        array[array[z][pebble]][0] = z;
        array[z][pebble] = -1;
        stackPointer--;
        return;
        // pebble found, bring it back!
    }
    else if (array[array[z][pebble]][1] == -1) {
        printf("Returning, with a pebble from position %d.\n", array[z][pebble]);
        array[array[z][pebble]][1] = z;
        array[z][pebble] = -1;
        stackPointer--;
        return;
        // pebble found, bring it back!
    }
    printf("Returning at end of statement.\n");
}

void printVertice(int size) {
    printf("END RESULT\n");
    int i;
    for (i = 0; i < size; i++) {
	    printf("%d goes to %d %d\n", i, array[i][0], array[i][1]);
    }
}

void mallocFail() {
    printf("ERROR: malloc failed!\n");
    exit(0);
}
