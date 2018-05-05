/* 
    CSE 2320 Homework 6
    Atafo Abure
*/


#include <stdio.h>
#include <stdlib.h>

int** array;
int* predecessor;
int sp = 0;
int vertices, flag;

int hasTwoPebbles(int z);
void direct(int x, int y);
void findPebble(int z);
void getPebble(int z, int pebble);
void printVertice(int size);
void mallocFail();

int main() 
{
    int i, x, y;
    scanf("%d", &vertices);

    array = (int**)malloc(sizeof(int*) * vertices);
    predecessor = (int*)malloc(sizeof(int) * vertices);

    if (!array || !predecessor) 
    {
        mallocFail();
    }

    for (i = 0; i < vertices; i++) 
    {
	    array[i] = (int*)malloc(sizeof(int) * 2);

	    if (!array[i]) 
        {
            mallocFail();
        }
	    array[i][0] = array[i][1] = -1;
    }

    for (i = 0; i < (vertices*2)-3; i++)
    {
	    scanf("%d %d", &x, &y);
        printf("Processing {%d, %d}\n", x, y);
        flag = 0;
	    findPebble(x);  // Get 2 pebbles at x location.
        findPebble(y);  // Get 2 pebbles at y loaction.
        printVertice(vertices);

        if (hasTwoPebbles(x) && hasTwoPebbles(y)) 
        {  
            printf("Directing %d to %d\n\n", x, y);
            direct(x, y);
            printVertice(vertices);    
        }
    }
    printVertice(vertices);
    return 0;
}


//Checks if each node has two pebbles
int hasTwoPebbles(int z) 
{
    if (array[z][0] == -1 && array[z][1] == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

// When doing the move directs a pebble in a direction
void direct(int x, int y) 
{
    array[x][0] = y;    // X's pebble will now point to Y.
}


//Goes through all the nodes and finds pebbles for each node
void findPebble(int z) 
{
    if (array[z][0] == -1 && array[z][1] == -1) 
    { // Base case. Pebbles already exist.
        printf("Base case, both pebbles exist at vertex %d.\n", z);
        return;
    }
    if (array[z][0] != -1) { // First pebble does not exist.
        printf("First pebble doesn't exist at %d.\n", z);
        getPebble(z, 0);    // Get a pebble where z,0 points to.
        flag = 1;
    }
    if (array[z][1] != -1) { // Second pebble does not exist.
        printf("Second pebble doesn't exist at %d.\n", z);
        getPebble(z, 1);    // Get a pabble where z,1 points to.
        flag = 1;
    }
}


//Gets pebbles for each node
void getPebble(int z, int pebble) 
{
    printf("Getting a pebble.\n");
    printf("The stack pointer is at %d comparing to %d vertices.\n", sp, vertices);

    if (sp++ > vertices*2) 
    {
        printf("Exiting.\n");
        return;
    }
    // check the direction the pebbles points to
    // if no pebble exists, move to next node

    if (array[array[z][pebble]][0] != -1 && array[array[z][pebble]][1] != -1)
     {
        printf("No pebble existed. Looking at node %d now.\n", array[z][pebble]);
        getPebble(array[z][pebble], 0); // try and grab a single pebble

        if (array[z][pebble] != -1) 
        {
            getPebble(array[z][pebble], 1); // try and grab a single pebble        
        }
        sp++;
    }
    // otherwise, we can pull it back.
    if (array[array[z][pebble]][0] == -1) 
    {
        printf("Returning, with a pebble from node %d.\n", array[z][pebble]);
        array[array[z][pebble]][0] = z;
        array[z][pebble] = -1;
        sp--;
        return;
        // pebble found, bring it back!
    }
    else if (array[array[z][pebble]][1] == -1) 
    {
        printf("Exiting, with a pebble from node %d.\n", array[z][pebble]);
        array[array[z][pebble]][1] = z;
        array[z][pebble] = -1;
        sp--;
        return;
        // pebble found, bring it back!
    }
}


//Print all vertices
void printVertice(int size) 
{
    printf("END\n");
    int i;
    for (i = 0; i < size; i++) {
	    printf("%d maps to %d %d\n", i, array[i][0], array[i][1]);
    }
}

void mallocFail()
 {
    printf("MALLOC FAILED!\n");
    exit(0);
}
