#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


void ranksByMerge(int m, int n, int probe, int *a, int *b);
int binarySearch(int *a,int n,int key);



int main(){
	
	int m, n, p;
	scanf("%d",&m);
	scanf("%d",&n);
	scanf("%d",&p);
	
	int i, j, *a, *b, probe;
	a = (int *)malloc((m+2) * sizeof(int));
	b = (int *)malloc((n+2) * sizeof(int));
	
	for(i = 1; i < m+1; i++)
	{
		scanf("%d",&a[i]);
	}
	a[0] = -99999999;
	a[m+1] = 99999999;
	
	for(j = 1; j < n+1; j++)
	{
		scanf("%d",&b[j]);
	}
	b[0] = -99999999;
	b[n+1] = 99999999;
	
	for( i = 0; i < m+2; i++)
	{
		printf("%d",a[i]);
	}
	
	scanf("%d",&probe);
	
	return 0;
}
void ranksByMerge(int m, int n, int probe, int *a, int *b) // finds rank of each number at probe
{
	int i,j,k;
	i=j=k=1;
	
	while (i<=m && j<=n)
	{	if (a[i]<=b[j])
		{ if( probe == k)
			{
				binarySearch(a, m, probe);
			}
			k++;
		}
		else
		{
			if(probe == k)
			{
				binarySearch(b, n, probe);
			}
			k++;
		}
		
		i++;
		j++;
	}
	while (i<=m)
		k++;
	while (j<=n)
		k++;
}
int binarySearch(int *a,int n,int key)
// Input: int array a[] with n elements in ascending order.
//        int key to find.
// Output: Returns some subscript of a where key is found.
//         Returns -1 if not found.
// Processing: Binary search.
{
	int low,high,mid;
	low=0;
	high=n-1;
	// subscripts between low and high are in search range.
	// size of range halves in each iteration.
	while (low<=high)
	{
		mid=(low+high)/2;
		if (a[mid]==key)
			return mid; // key found
		if (a[mid]<key)
			low=mid+1;
		else
			high=mid-1;
	}
	
	return (-1); // key does not appear
}

