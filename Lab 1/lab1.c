/* Lab 1
 
 Created By Atafo Abure
 Feb 6 2018

 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void inputArray(int size, int *array);
int binarySearch(int *a,int *b, int low, int high, int rank);

int main(){
	
	int m, n, p;
	scanf("%d",&m);
	scanf("%d",&n);
	scanf("%d",&p);
	
	int k, *a = 0, *b = 0, rank = 0, smallestSize = 0, biggestSize = 0;
	int high, low;
	
	inputArray(m,a);
	inputArray(n,b);
	
	if(m > n)
	{	smallestSize = n;
		biggestSize = m;
	}
	else
	{	smallestSize = m;
		biggestSize = n;
	}
	
	if(rank > smallestSize)
		high = smallestSize;
	else
		high = rank;
	
	low = rank - biggestSize;
	if(low < 0)
		low = 0;
	
	for(k = 0; k < p; k++) // fix this line to collect probe after probe
	{
		scanf("%d",&rank);
		printf("Low is: %d High is: %d",low, high);
		rank = binarySearch(a, b, low, high, rank);
	   }
	return 0;
}

void inputArray(int size, int *array)
{
	array = (int *)malloc((size+2) * sizeof(int));
	int i;
	for(i = 1; i <size+1; i++)
	{
		scanf("%d",&array[i]);
	}
	array[0] = -99999999;
	array[size+1] = 99999999;
}


int binarySearch(int *a,int *b, int low, int high, int rank)
{
	
	int i, j;
	int mid;

	while (low<=high)
	{
		i = (low+high)/2;
		j = rank - i;
		
		printf("i is: %d j is: %d",i,j);
		printf("a[%d] is: %d b[%d] is: %d",i,a[i],j,b[j]);
		
		mid=(low+high)/2;
		
		if(i + j ==  rank)
		{
			if(b[j] < a[i])
			{
				if(a[i] <= b[j+1])
				{
					printf("a[%d] has rank: %d\n",a[i],rank);
					return a[i];
				}
				else
				{
					high = mid - 1;
				}
			}
			else
			{
				if(b[j] <= a[i+1])
				{
					printf("b[%d] has rank: %d\n",b[j],rank);
					return b[j];
				}
				else
				{
					low = mid+1;
				}
			}
		}
		
	}
	
	return (-1); // rank does not appear
}

