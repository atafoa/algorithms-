/* Lab 4
 
 CSE 2320 - Lab 4
 Created by Atafo Abure 1001442575
 
 This program implements order-preserving Huffman coding using the dynamic programming formulation
 
 How to run
 To compile and run use the following commands
 gcc lab3.c
 ./a.out 

 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <limits.h>

struct Stack
{
	int top;
	int size;
	int* array;
};

int cnt = 0;

float elapsedCPU(void);
void generateTree(int n, int k, struct Stack* stack);
void printInfo(int n, int k, int cnt, float startCPU);
struct Stack* createStack(int n);
int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, int item);
int pop(struct Stack* stack);


int main()
{
	float startCPU;
	startCPU = elapsedCPU();
	int n; int k;
	scanf("%d", &n);
	scanf("%d", &k);

	struct Stack* stack = createStack(n);
	generateTree(n,k,stack);
	printInfo(n,k,cnt,startCPU);

	return 0;
	
}


//creates a stack to store all possible minheaps for a certain n
struct Stack* createStack(int n)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack -> size = n;
	stack -> top = -1;
	stack -> array = (int *)malloc(stack->size * sizeof(int));
	return stack;
	
}

//checks if stack is full
int isFull(struct Stack* stack)
{
	return stack->top == stack -> size - 1;
}

//checks if stack is empty
int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}


//pushes an element to the bottom of the stack
void push(struct Stack* stack, int item)
{
	if(isFull(stack))
		return;

	return stack -> array[stack->top++] = item;
}


//pops an element from the stack by removing the element and decreasing the size of the stack by 1
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}


//generates all possible minheap trees for a non negative n. and then prints out all combination of the minheaps depending on the k value
void generateTree(int n, int k, struct Stack* stack)
{
	int p[2] = {100,2};
	int i,j;

	if(stack -> size == n)
	{
		cnt++;
		if(cnt % k == 0)
		{
			printf("%d: ",cnt);
			for(j = 0; j < stack -> size; j++ )
			{
				printf("%d ",stack -> array[j]);
			}
			printf("\n");
		}
	}
	else
	{
		for(i = 1; i <= n; i++)
		{
			if(stack -> size && stack -> array[0] != 1)
			{
				return;
			}
			if(p[i])
				continue;

			int size = stack -> size;
			int parent;
			if(size & 1)
			{
				parent = (size - 1)/2;
			}
			else
				parent = (size-2)/2;

			if(size == 0)
				parent = 0;

			if(stack -> size &&  stack -> array[parent] > i)
			{
				continue;
			}

			p[i] = 1;
			push(stack,i);
			generateTree(n,k, stack);
			p[i] = 0;
			pop(stack);
		}
	}
}

//Print out relative information about the cpu time and the total number of heaps created for a certain n value
void printInfo(int n, int k, int cnt, float startCPU)
{
	if(k == 0)
	{
		return;
	}

	printf("%d heaps for n= %d, CPU= %.2f\n",cnt,n,elapsedCPU()-startCPU);
}


//calculate the cpu time taken to generate all heaps
float elapsedCPU()
{
	struct rusage rusage;
	getrusage(RUSAGE_SELF,&rusage);
	return rusage.ru_utime.tv_sec+rusage.ru_utime.tv_usec/1000000.0
	+ rusage.ru_stime.tv_sec+rusage.ru_stime.tv_usec/1000000.0;
}
