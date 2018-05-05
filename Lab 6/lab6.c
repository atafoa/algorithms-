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
void directEdge(int x, int y);
void find(int z);
void getPebble(int z, int pebble);
void print(int size);
void mallocError();

int main() 
{
    int i, x, y;
    scanf("%d", &vertices);

    array = (int**)malloc(sizeof(int*) * vertices);
    predecessor = (int*)malloc(sizeof(int) * vertices);

    if (!array || !predecessor) 
    {
        mallocError();
    }

    for (i = 0; i < vertices; i++) 
    {
	    array[i] = (int*)malloc(sizeof(int) * 2);

	    if (!array[i]) 
        {
            mallocError();
        }
	    array[i][0] = array[i][1] = -1;
    }

    for (i = 0; i < (vertices*2)-3; i++)
    {
	    scanf("%d %d", &x, &y);
        printf("Looking into {%d, %d}\n", x, y);
        flag = 0;
	    find(x);  // find 2 pebbles at x.
        find(y);  // find 2 pebbles at y.
        print(vertices);

        if (hasTwoPebbles(x) && hasTwoPebbles(y)) 
        {  
            printf("Directing %d to %d\n\n", x, y);
            directEdge(x, y);
            print(vertices);    
        }
    }
    print(vertices);
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

// When doing the move a pebble in a direction
void directEdge(int x, int y) 
{
    array[x][0] = y;    // X's pebble will point to Y.
}


//Goes through all the nodes and finds pebbles for each node
void find(int i) 
{
    if (array[i][0] == -1 && array[i][1] == -1) 
    { // Base case.
        printf("Base case, both pebbles exist at vertex %d.\n", i);
        return;
    }

    if (array[i][0] != -1) 
    { // First pebble does not exist.
        printf("First pebble doesn't exist at %d.\n", i);
        getPebble(i, 0);    // Get a pebble where i,0 points to.
        flag = 1;
    }

    if (array[i][1] != -1) 
    { // Second pebble does not exist.
        printf("Second pebble doesn't exist at %d.\n", i);
        getPebble(i, 1);    // Get a pabble where i,1 points to.
        flag = 1;
    }
}


//Gets pebbles for each node
void getPebble(int i, int pebble) 
{
    if (sp++ > vertices*2) 
    {
        printf("Exiting.\n");
        return;
    }
    // check the directEdgeion the pebbles points to
    // if no pebble exists, move to next node

    if (array[array[i][pebble]][0] != -1 && array[array[i][pebble]][1] != -1)
     {
        printf("No pebble existed. Looking at node %d now.\n", array[i][pebble]);
        getPebble(array[i][pebble], 0); // try and get a single pebble

        if (array[i][pebble] != -1) 
        {
            getPebble(array[i][pebble], 1); // try and get a single pebble        
        }
        sp++;
    }

    if (array[array[i][pebble]][0] == -1) 
    {
        printf("Returning, with a pebble from node %d.\n", array[i][pebble]);
        array[array[i][pebble]][0] = i;
        array[i][pebble] = -1;
        sp--;
        return;
        // pebble found
    }
    else if (array[array[i][pebble]][1] == -1) 
    {
        printf("Exiting, with a pebble from node %d.\n", array[i][pebble]);
        array[array[i][pebble]][1] = i;
        array[i][pebble] = -1;
        sp--;
        return;
        // pebble found
    }
}


//Print all vertices
void print(int size) 
{
    int i;
    for (i = 0; i < size; i++) {
	    printf("%d maps to %d %d\n", i, array[i][0], array[i][1]);
    }
}

void mallocError()
 {
    printf("ERROR!\n");
    exit(0);
}
