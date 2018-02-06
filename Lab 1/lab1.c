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
	
	scanf("%d",&probe);

	ranksByMerge(m, n, probe, a, b);
	return 0;
}

void ranksByMerge(int m, int n, int probe, int *a, int *b) // finds rank of each number at probe
{
	int i,j,k;
	i=j=k=1;
	int found;
	
	while (i<=m && j<=n)
	{
		printf("i is: %d",i);
		printf("j is: %d",j);
		printf("a[%d] is %d",i,a[i]);
		printf("b[%d] is %d",j,b[j]);
		
		if (a[i]<=b[j])
		{
			if( probe == k)
			{
				found = binarySearch(a, m, probe);
				printf("a[%d] has rank %d",i,a[i]);
			}
			k++;
		}
		else
		{
			if(probe == k)
			{
				found = binarySearch(b, n, probe);
				printf("b[%d] has rank %d",j,b[j]);
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
{
	int low,high,mid;
	low=0;
	high=n-1;
	while (low<=high)
	{
		mid=(low+high)/2;
		if (a[mid]==key)
			return mid; // key found
		if (a[mid]<key)
			low=mid+1;
		else
			high=mid-1;
		
		printf("Low is: %d",low);
		printf("High is: %d",high);
	}
	
	return (-1); // key does not appear
}

