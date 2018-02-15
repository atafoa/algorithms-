//
//  main.c
//  Lab 2
//
//  Created by Atafo Abure on 2/14/18.

#include <stdio.h>
#include <stdlib.h>

void populateArray( int *array, int arraySize);
void printArray(int *array, int arraySize);

int main() {
	
	int numofBaskets;

	scanf("%d",&numofBaskets);
	
	int *washTime = (int *)malloc((numofBaskets)*sizeof(int));
	int *dryTime = (int *)malloc((numofBaskets)*sizeof(int));
	
	
	populateArray(washTime, numofBaskets);
	populateArray(dryTime, numofBaskets);
	
	printArray(washTime, numofBaskets);
	printArray(dryTime, numofBaskets);
	
	
	
//	int i;
//	for (i = 0; i < numofBaskets; i++)
//	{
//		scanf("%d",&washTime[i]);
//		scanf("%d",&dryTime[i]);
//	}
//
	

	return 0;
}

void populateArray( int *array, int arraySize)
{
	int i;
	for(i = 0;i < arraySize; i++)
	{
		scanf("%d", &array[i]);
	}
}


void printArray(int *array, int arraySize)
{
	int i;
	for(i = 0;i < arraySize; i++)
	{
		printf("%d",array[i]);
	}
}

