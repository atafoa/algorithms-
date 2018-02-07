/* Lab 1
 
 CSE 2320 - Lab 1
 Created By Atafo Abure 1001442575
 This program is going to help you predict the outcome of a mergesort using binary search. It will required the inputs for the two arrays and the number of probes
 Feb 6 2018

 How to run
 To compile and run use the following commands
 gcc lab1.c
 a.out < inputFile.txt
 
 inputFile.txt would be the name of the input file you want to work with.
 Note the inputFile has to be in the same directory as the lab1.c file
 */

#include <stdio.h>
#include <stdlib.h>

void binarySearch(int *a,int *b, int low, int high, int rank);


//main function
int main(){
	
	int m, n, p;
	scanf("%d",&m);
	scanf("%d",&n);
	scanf("%d",&p);
	
	int k, *a = 0, *b = 0, rank = 0, smallestSize = 0, biggestSize = 0;
	int high, low;
	int x,y;
	
	//dynamic allocation for arrays
	a = (int *)malloc((m+2) * sizeof(int));
	b = (int *)malloc((n+2) * sizeof(int));
	
	for(x = 1; x < m+1; x++)
	{
		scanf("%d",&a[x]);
	}
	a[0] = -99999999;
	a[m+1] = 99999999;
	
	for(y = 1; y < n+1; y++)
	{
		scanf("%d",&b[y]);
	}
	b[0] = -99999999;
	b[n+1] = 99999999;
	
	// Test case to account for the number of probes being larger than the size of both arrays
	if(p > m || p > n)
	{
		printf("Number of probes given are larger than the sizes of every array");
		free(a);
		free(b);
		return 0; // quits the program
	}
	
	// run the binary search function for the given number of ranks
	for(k = 0; k < p; k++)
	{
		scanf("%d",&rank);
		
		//if statement to find which array is the larger array
		if(m > n)
		{	smallestSize = n;
			biggestSize = m;
		}
		else
		{	smallestSize = m;
			biggestSize = n;
		}
		
		// if rank is greater than the size of the smallest array then high value should be set to the smallest array and m has to be greater than or equal to n
		if(rank > smallestSize && m <= n)
			high = smallestSize;
		else
			high = rank;
	
		low = rank - biggestSize; // low should be the rank minus the biggestSize if the value is negative your lowest value should be 0
		if(low < 0)
			low = 0;
		
		binarySearch(a, b, low, high, rank); // call binary search function and predict the merge sort
	   }
	
	//free dynamically allocated arrays
	free(a);
	free(b);
	return 0;
}

//binary search function used to predict the outcome of a mergesort
void binarySearch(int *a,int *b, int low, int high, int rank)
{
	
	int i, j;
	int mid;

	while (low<=high)
	{
		i = (low+high)/2;
		j = rank - i;
		
		printf("Low is: %d High is: %d ",low, high);
		printf("i is: %d j is: %d ",i,j);
		printf("a[%d] is: %d b[%d] is: %d\n",i,a[i],j,b[j]);
		
		
		mid=(low+high)/2; //mid splits the array in half for the purpose of binary search
		
		if(i + j ==  rank)
		{
			if(b[j] < a[i])
			{
				if(a[i] <= b[j+1])
				{
					printf("a[%d] = %d has rank %d\n",i,a[i],rank); // the given rank is in arrayA at position i
					break;
				}
				else
				{
					high = mid - 1; // reset high value to mid - 1
				}
			}
			else if(a[i] <= b[j])
			{
				if(b[j] < a[i+1])
				{
					printf("b[%d] = %d has rank %d\n",j,b[j],rank); // the given rank is in arrayB at position j
					break;
				}
				else
				{
					low = mid+1; // reset low value to mid + 1
				}
			}
		}
		
	}

}

