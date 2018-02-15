//
//  main.c
//  Lab 2
//
//  Created by Atafo Abure on 2/14/18.

#include <stdio.h>
#include <stdlib.h>

void populateArray( int *arrayA,int *arrayB, int arraySize);
void printArray(int *array, int arraySize);
int cmpfunc(const void *a, const void *b);
void sortArray(int *array, int arraySize);

int main() {
	
	int numofBaskets;

	scanf("%d",&numofBaskets);
	
	int *washTime = (int *)malloc((numofBaskets)*sizeof(int));
	int *dryTime = (int *)malloc((numofBaskets)*sizeof(int));
	
	
	printf("The total number of baskets we have to process are: %d\n",numofBaskets);
	populateArray(washTime,dryTime,numofBaskets);
	
	printArray(washTime, numofBaskets);
	printArray(dryTime, numofBaskets);
	
	//perform qsort
	sortArray(washTime, numofBaskets);
	sortArray(dryTime, numofBaskets);
	
	//array after qsort
	printArray(washTime, numofBaskets);
	printArray(dryTime, numofBaskets);
	
	return 0;
}

void populateArray( int *arrayA,int *arrayB, int arraySize)
{
	int i;
	for(i = 0;i < arraySize; i++)
	{
		scanf("%d", &arrayA[i]);
		scanf("%d", &arrayB[i]);
	}
}


void printArray(int *array, int arraySize)
{
	int i;
	for(i = 0;i < arraySize; i++)
	{
		printf("%d\n",array[i]);
	}
	printf("\n");
}

int cmpfunc(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

void sortArray(int *array, int arraySize)
{
	qsort(array, arraySize, sizeof(int), cmpfunc);
}
