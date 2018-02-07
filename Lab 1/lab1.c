/* Lab 1
 
 Created By Atafo Abure
 Feb 6 2018

 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void binarySearch(int *a,int *b, int low, int high, int rank);

int main(){
	
	int m, n, p;
	scanf("%d",&m);
	scanf("%d",&n);
	scanf("%d",&p);
	
	int k, *a = 0, *b = 0, rank = 0, smallestSize = 0, biggestSize = 0;
	int high, low;
	int x,y;
	
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
	
	for(k = 0; k < p; k++) // fix this line to collect probe after probe
	{
		scanf("%d",&rank);
		
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
		
		binarySearch(a, b, low, high, rank);
	   }
	return 0;
}

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
		
		mid=(low+high)/2;
		
		if(i + j ==  rank)
		{
			if(b[j] < a[i])
			{
				if(a[i] <= b[j+1])
				{
					printf("a[%d] = %d has rank %d\n",i,a[i],rank);
					break;
				}
				else
				{
					high = mid - 1;
				}
			}
			else if(a[i] <= b[j])
			{
				if(b[j] < a[i+1])
				{
					printf("b[%d] = %d has rank %d\n",j,b[j],rank);
					break;
				}
				else
				{
					low = mid+1;
				}
			}
		}
		
	}

}

