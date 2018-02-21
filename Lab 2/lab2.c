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
	int basketNumber;
	int washTime;
	int dryTime;
	
};

void populateArray(struct laundry sampleLoad[], int size);
void printArray(struct laundry sampleLoad[] , int size);
int cmpfunc(const void *p, const void *q);
void sortByLowestValue(struct laundry sampleLoad[], int size);
int findMin(int a, int b);
void johnsonsRule(struct laundry sampleLoad[], int size);


int main() {
	
	
	int numofBaskets;	//Gets total number of baskets
	scanf("%d",&numofBaskets);
	struct laundry baskets[numofBaskets];

	
	
	printf("The total number of baskets we have to process are: %d\n",numofBaskets);
	populateArray(baskets,numofBaskets);
	printArray(baskets,numofBaskets);
	qsort(baskets, numofBaskets, sizeof(struct laundry), cmpfunc);
	printf("The schedule is \n");
	johnsonsRule(baskets, numofBaskets);
	
	return 0;
}

void populateArray( struct laundry sampleLoad[], int size)
{
	int i;
	for(i = 0;i < size; i++)
	{
		sampleLoad[i].basketNumber = i;
		scanf("%d", &sampleLoad[i].washTime);
		scanf("%d", &sampleLoad[i].dryTime);
	}
}


void printArray(struct laundry sampleLoad[] , int size)
{
	int i;
	for(i = 0;i < size; i++)
	{
		printf("For basket %d\n", sampleLoad[i].basketNumber);
		printf("Washtime: %d Drytime: %d\n",sampleLoad[i].washTime,sampleLoad[i].dryTime);
		printf("\n");
	}
	printf("\n");
}

int cmpfunc(const void *p, const void *q) //compares two basket values for qsort and then  returns an integer expected by q
{
	struct laundry *basketp = (struct laundry *)p;
	struct laundry *basketq = (struct laundry *)q;
	
	int min1 = findMin(basketp -> washTime, basketp -> dryTime);
	int min2 = findMin(basketq -> washTime, basketq -> dryTime);
	
	if(min1 < min2)
		return -1;
	if(min1 == min2)
		return 0;
	if(min1 > min2)
		return 1;
	
	return 0;
}

 int findMin(int a, int b) // find the minimum value of 2 integers
{
	if(a < b)
	{
		return a;
	}
	else return b;
}

//
//
//
void johnsonsRule(struct laundry sampleLoad[], int size)
{
	struct laundry sampleBaskets[size];
	
	int index = 0;
	int left = 0;
	int right = size - 1;
	int washerTime = 0;
	int dryerTime = 0;
	
	while(index < size)
	{
		if(sampleLoad[index].washTime < sampleLoad[index].dryTime)
		{
			sampleBaskets[left] = sampleLoad[index];
			left++;
		}
		else
		{
			sampleBaskets[right] = sampleLoad[index];
			right--;
		}
		index++;
	}
	
	index = 0;
	//Perform first dryertime calculation before entering the loop.
	dryerTime = sampleBaskets[index].washTime;
	
	while(index < size)
	{
		if(dryerTime < sampleBaskets[index].washTime + washerTime)
		{
			//dryer is idle
			printf("The dryer is inactive from %d  to %d\n", dryerTime, sampleBaskets[index].washTime + washerTime);
			dryerTime = sampleBaskets[index].washTime + washerTime;
		}
		
		printf("Basket %d Wash Time: %d Dry Time: %d, Washer Start: %d Dryer Start: %d\n",sampleBaskets[index].basketNumber, sampleBaskets[index].washTime, sampleBaskets[index].dryTime,washerTime,dryerTime);
		
		washerTime = washerTime + sampleBaskets[index].washTime;
		dryerTime = dryerTime + sampleBaskets[index].dryTime;
		index++;
	}
	
	printf("Makespan is: %d\n",dryerTime);
}
