/* Lab 4
 
 CSE 2320 - Lab 4
 Created by Atafo Abure 1001442575
 
 This program implements order-preserving Huffman coding using the dynamic programming formulation
 
 How to run
 To compile and run use the following commands
 gcc lab3.c
 ./a.out 
 
 inputFile.txt would be the name of the input file you want to work with.
 Note the inputFile has to be in the same directory as the lab3.c file
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

float elapsedCPU()
{
	struct rusage rusage;
	getrusage(RUSAGE_SELF,&rusage);
	return rusage.ru_utime.tv_sec+rusage.ru_utime.tv_usec/1000000.0
	+ rusage.ru_stime.tv_sec+rusage.ru_stime.tv_usec/1000000.0;
}

int main()
{
	float startCPU;
	startCPU=elapsedCPU();
	printf("CPU== %.2f\n", elapsedCPU()-startCPU);
	startCPU=elapsedCPU();
	printf("CPU== %.2f\n", elapsedCPU()-startCPU);
	
	
	int n; int start;
	
	return 0;
	
}

// This function takes in the start value form the user and prints out all the heaps from this start value
void printHeapsFrom(int start)
{
	
}
