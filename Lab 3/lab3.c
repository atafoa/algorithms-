/* Lab 3
 
 CSE 2320 - Lab 3
 Created by Atafo Abure 1001442575
 
 This program implements order-preserving Huffman coding using the dynamic programming formulation
 
 How to run
 To compile and run use the following commands
 gcc lab3.c
 a.out < inputFile.txt
 
 inputFile.txt would be the name of the input file you want to work with.
 Note the inputFile has to be in the same directory as the lab3.c file
 */

#include <stdio.h>
#include <stdlib.h>


struct Symbols // Stores all symbols in an order preserving manner
{
	double probability;
	int symbol;
};

void populateSymbols(struct Symbols sentinel[], int size);
void costFunction(struct Symbols sentinel[], int size, double cost[size][size], int trace[size][size]);
void printCostFunction(int size, double cost[size][size], int trace[size][size]);

int main()
{
	struct Symbols *symbols;
	int size;
	scanf("%d",&size);
	double cost[size][size];
	int trace[size][size];
	
	symbols = (struct Symbols *)malloc(size * sizeof(struct Symbols));
	
	populateSymbols(symbols, size);
	costFunction(symbols, size, cost, trace);
	printCostFunction(size, cost, trace);
	
}

//Populates the array with the probability and the symbol for each symbol in the huffman tree
void populateSymbols(struct Symbols sentinel[], int size)
{
	int i;
	
	for (i = 0;i <= size;i++)
	{
		scanf("%lf",&sentinel[i].probability);
		sentinel[i].symbol = i;
	}
}

//This function calculates the optimal matrix multiplication order using dynamic programming
void costFunction(struct Symbols sentinel[], int size, double cost[size][size], int trace[size][size])
{
	double work;
	int i, j, k;
	
	for (i = 1; i <= size; i++)
	{
		cost[i][i] = trace[i][i] = 0;
	}
	
	for (i = 1;i < size; i++)
	{
		for (j = 1; j <= size-i;j ++)
		{
			cost[j][j+i]=999999;
			
			for (k = j; k < j+i; k++)
			{
				work = sentinel[j].probability+cost[j][k]+cost[k+1][j+i];
				
				if (cost[j][j+i] > work)
				{
					cost [j][j+i] = work;
					trace[j][j+i] = k;
				}
			}
		}
	}
}


//This function prints out the optimal matrix multiplication order created in the function costFunction
void printCostFunction(int size, double cost[size][size], int trace[size][size])
{
	int i,j;
	printf("   ");
	for ( i = 1; i <= size; i++)
	{
		printf("   %3d   ",i);
	}
	
	printf("\n");
	
	for (i = 1; i <= size; i++)
	{
		printf("%2d ",i);
		for (j = 1; j <= size; j++)
		{
			if (i>j)
				printf(" ------- ");
			else
				printf(" %.1lf %3d ",cost[i][j],trace[i][j]);
		}
		
		printf("\n");
		printf("\n");
	}
}
