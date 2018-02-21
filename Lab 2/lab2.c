/* Lab 2

 CSE 2320 - Lab 2
 Created By Atafo Abure 1001442575
 This program implements a greedy method to optimally solve the
 Feb 20 2018

 How to run
 To compile and run use the following commands
 gcc lab2.c
 a.out < inputFile.txt

 inputFile.txt would be the name of the input file you want to work with.
 Note the inputFile has to be in the same directory as the lab2.c file
 */

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
	struct laundry baskets[numofBaskets]; // array of structs to handle each basket

	printf("The total number of baskets we have to process are: %d\n",numofBaskets);
	populateArray(baskets,numofBaskets);
	printArray(baskets,numofBaskets);
	qsort(baskets, numofBaskets, sizeof(struct laundry), cmpfunc);
	johnsonsRule(baskets, numofBaskets);

	return 0;
}

void populateArray( struct laundry sampleLoad[], int size) //populates the array to get washtime and drytime from the file
{
	int i;
	for(i = 0;i < size; i++)
	{
		sampleLoad[i].basketNumber = i;
		scanf("%d", &sampleLoad[i].washTime);
		scanf("%d", &sampleLoad[i].dryTime);
	}
}


void printArray(struct laundry sampleLoad[] , int size) //prints out values for each basket
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



 //compares two basket values for qsort()
//Returns a value expected for qsort() based on the smallest time between the washtime and drytime for each basket
int cmpfunc(const void *p, const void *q)
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

//Performs johnsons rule to greedily determine the shedule for a sorted array
//Accepts an array of structs and the size of the array of structs
void johnsonsRule(struct laundry sampleLoad[], int size)
{
	struct laundry sampleBaskets[size];

	int index = 0;
	int left = 0;
	int right = size - 1;
	int washerTime = 0;
	int dryerTime = 0;


	//Creates a schedule of the baskets
	//If washtime is greater than the drytime then schedule at the front else schedule at the back
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

	printf("The schedule is: ");
	index = 0;
	while(index < size)
	{
		printf("%d ", sampleBaskets[index].basketNumber);
		index++;
	}
	printf("\n");

	index = 0;
	//Perform first dryertime calculation before entering the loop. Helps with optimization.
	dryerTime = sampleBaskets[index].washTime;

	//run through schedule and output
	while(index < size)
	{
		if(dryerTime < sampleBaskets[index].washTime + washerTime)
		{
			//dryer is idle
			printf("The dryer is inactive from %d  to %d\n", dryerTime, sampleBaskets[index].washTime + washerTime);
			dryerTime = sampleBaskets[index].washTime + washerTime;
		}
		//prints out sorted information
		printf("Basket %d Wash Time: %d Dry Time: %d, Washer Start: %d Dryer Start: %d\n",sampleBaskets[index].basketNumber, sampleBaskets[index].washTime, sampleBaskets[index].dryTime,washerTime,dryerTime);
		washerTime += sampleBaskets[index].washTime;
		dryerTime += sampleBaskets[index].dryTime;
		index++;
	}
	//Print out total time taken
	printf("Makespan is: %d\n",dryerTime);
}
