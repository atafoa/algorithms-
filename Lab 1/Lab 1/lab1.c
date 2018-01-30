#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main(){
	
	int m, n, p;
	scanf("%d",&m);
	scanf("%d",&n);
	scanf("%d",&p);
	
	int i, j, l, *a, *b,*probe;
	a = (int *)malloc((m+2) * sizeof(int));
	b = (int *)malloc((n+2) * sizeof(int));
	probe = (int *)malloc(p * sizeof(int));
	
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
	
	for(l = 0; l < p; l++)
	{
		scanf("%d",&probe[p]);
	}
	
	
	return 0;
}

int rankNumbers(int l[],int ll[],int m,int n,int p)
{
	while (1){
		int i = (int)((float)m/(m+n)*(p-1));
		int j = p-1-i;
		
		int Ai_1 = (i == 0) ? INT_MIN : l[i-1];
		int Ai = (i == m) ? INT_MAX : l[i];
		int Bj_1 = (j == 0) ? INT_MIN : ll[j-1];
		int Bj = (j == n) ? INT_MAX : ll[j];
		
		if (Bj_1 < Ai && Bj > Ai) return Ai;
		if (Ai_1 < Bj && Ai > Bj) return Bj;
		
		if (Ai < Bj){
			l = l + i + 1;
			m = m - i - 1;
			p = p - i - 1;
		}
		else{
			ll = ll + j + 1;
			n = n - j - 1;
			p = p - j - 1;
		}
	}
}



