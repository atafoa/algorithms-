//
//  main.c
//  Lab 2
//
//  Created by Atafo Abure on 2/14/18.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct laundry
{
	int numofBaskets;
	int *washTime;
	int *dryTime;
	
};

void populateArray(struct laundry sampleLoad);
void printArray(struct laundry sampleLoad);
int cmpfunc(const void *a, const void *b);
void sortArray(int *array, int arraySize);


int main() {
	
	
	struct laundry load;
	scanf("%d",&load.numofBaskets);
	
	load.washTime = (int *)malloc((load.numofBaskets)*sizeof(int));
	load.dryTime = (int *)malloc((load.numofBaskets)*sizeof(int));
	
	
	printf("The total number of baskets we have to process are: %d\n",load.numofBaskets);
	populateArray(load);
	
	printArray(load);
	
	//perform qsort
	
	
	//array after qsort
	
	
	return 0;
}

void populateArray( struct laundry sampleLoad)
{
	int i;
	for(i = 0;i < sampleLoad.numofBaskets; i++)
	{
		scanf("%d", &sampleLoad.washTime[i]);
		scanf("%d", &sampleLoad.dryTime[i]);
	}
}


void printArray(struct laundry sampleLoad)
{
	int i;
	printf("Wash Times\n");
	for(i = 0;i < sampleLoad.numofBaskets; i++)
	{
		printf("%d\n",sampleLoad.washTime[i]);
	}
	printf("\n");
	
	printf("Dry Times\n");
	for(i = 0;i < sampleLoad.numofBaskets; i++)
	{
		printf("%d\n",sampleLoad.dryTime[i]);
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
