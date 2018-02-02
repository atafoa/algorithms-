#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int rankNumbers(int l[],int ll[],int m,int n,int p);
int cmpfunc (const void * a, const void * b);


int main(){
	
	int m, n, p;
	scanf("%d",&m);
	scanf("%d",&n);
	scanf("%d",&p);
	
	int i, j, *a, *b, rank;
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
	
//	int probe;
//	qsort(a,m,sizeof(int),cmpfunc);
//	qsort(b,m,sizeof(int),cmpfunc);
//
//
//	scanf("%d", &probe);
//	rank = rankNumbers(a, b, m, n, probe);
//	printf("Rank is : %d \n",rank);
	
	return 0;
}


//int cmpfunc (const void * a, const void * b)
//{
//	return ( *(int*)a - *(int*)b );
//}
//
//int rankNumbers(int l[],int ll[],int m,int n,int p)
//{
//	while (1){
//		int i = (int)((float)m/(m+n)*(p-1));
//		int j = p-1-i;
//
//		int Ai_1 = (i == 0) ? INT_MIN : l[i-1];
//		int Ai = (i == m) ? INT_MAX : l[i];
//		int Bj_1 = (j == 0) ? INT_MIN : ll[j-1];
//		int Bj = (j == n) ? INT_MAX : ll[j];
//
//		if (Bj_1 < Ai && Bj > Ai) return Ai;
//		if (Ai_1 < Bj && Ai > Bj) return Bj;
//
//		if (Ai < Bj){
//			l = l + i + 1;
//			m = m - i - 1;
//			p = p - i - 1;
//		}
//		else{
//			ll = ll + j + 1;
//			n = n - j - 1;
//			p = p - j - 1;
//		}
//	}
//}
//
//
//
