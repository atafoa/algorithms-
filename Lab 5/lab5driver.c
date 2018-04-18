/*
	CSE 2320 Lab 5
	Atafo Abure

	This program reads a string for a serialized red black tree, deserializes it and perfoorms some insersertions, then serializes the revised tree
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "RB.lab5.h"

int main()
{

	int inputBytes;
	char * inputString, * outputString;
	char formatString[100];
	int insertKeys, i, key;

	scanf(" %d ", &inputBytes);

	inputString = (char *)malloc(inputBytes+1);

	if (!inputString) 
	{
	  printf("malloc failed %d\n",__LINE__);
	  exit(0);
	}

	sprintf(formatString,"%%%ds",inputBytes);

	scanf(formatString,inputString);
	STinit();
	STdeserialize(inputString);
	free(inputString);

	//STprintTree();
	scanf("%d",&insertKeys);
	for ( i = 0; i < insertKeys; i++) 
	{
	  scanf("%d",&key);
	  STinsert(key);
	}

	//STprintTree();
	outputString = STserialize();
	printf("%lu %s\n",strlen(outputString)+1,outputString);
	free(outputString);
}
