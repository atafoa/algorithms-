/*
	CSE 2320 Lab 6
	Atafo Abure

	This program uses the “pebble game” technique to test if an input graph is minimally rigid (in two dimensions).
*/

int** sentinel(int size);

int main()
{
    int n;
    scanf("%d",&n);
    int undirectedEdges = sentinel(n);

    return 0;
}

int** sentinel(int size)
{
    int edgeSize = 2*size - 3;
    int undirectedEdges[size][2];
    int i = 0;
    for(i = 0; i < size; i++)
    {
        scanf("%d %d",undirectedEdges[i][0], undirectedEdges[i][1]);
    }

    return undirectedEdges;

}