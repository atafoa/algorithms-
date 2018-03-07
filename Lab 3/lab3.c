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

// Optimal matrix multiplication order using dynamic programming
#include <stdio.h>
#include <stdlib.h>
//void tree(int left,int right,int indent);



struct Test
{
	double probability;
	int symbol;
};

int main()
{
	struct Test *tests;
	int n;
	scanf("%d",&n);
	//double p[n];
	double c[n][n];
	int trace[n][n];
	
	tests = (struct Test *)malloc(n*sizeof(struct Test));
	
	int i,j,k;
	double work;
	
	for (i=0;i<=n;i++)
	{	scanf("%lf",&tests[i].probability);
		tests[i].symbol = i;
	}
	
	for (i=1;i<=n;i++)
		c[i][i]=trace[i][i]=0;
	
	for (i=1;i<n;i++)
		for (j=1;j<=n-i;j++)
		{
			c[j][j+i]=999999;
			for (k=j;k<j+i;k++)
			{
				work=tests[j].probability+c[j][k]+c[k+1][j+i];
				if (c[j][j+i]>work)
				{
					c[j][j+i]=work;
					trace[j][j+i]=k;
				}
			}
		}
	
	printf("   ");
	for (i=1;i<=n;i++)
		printf("   %3d   ",i);
	printf("\n");
	for (i=1;i<=n;i++)
	{
		printf("%2d ",i);
		for (j=1;j<=n;j++)
			if (i>j)
				printf(" ------- ");
			else
				printf(" %.1lf %3d ",c[i][j],trace[i][j]);
		printf("\n");
		
		printf("\n");
	}
}
