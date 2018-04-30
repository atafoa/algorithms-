/*
	CSE 2320 Lab 6
	Atafo Abure

	This program uses the “pebble game” technique to test if an input graph is minimally rigid (in two dimensions).
*/

#include <stdio.h>


int main()
{
    int n;
    scanf("%d",&n);
    int edgeSize = 2*n - 3;
    int undirectedEdges[n][2];
    int i = 0;
    for(i = 0; i < edgeSize; i++)
    {
        scanf("%d %d",&undirectedEdges[i][0], &undirectedEdges[i][1]);
        printf("%d %d\n",undirectedEdges[i][0], undirectedEdges[i][1]);
    }

    return 0;
}
