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
	STdeserialize(inputString); //Deserializes the input string
	verifyRBproperties();		//Checks if the deserialized tree is a valid RB tree
	free(inputString);

	printf("Tree before inserting new keys \n\n");
	STprintTree();
	printf("\n");

	scanf("%d",&insertKeys);
	for ( i = 0; i < insertKeys; i++) 
	{
	  scanf("%d",&key);
	  STinsert(key); //Insert new keys 
	}

	printf("\nTree after inserting new keys \n\n");
	STprintTree();
	printf("\n");
	
	outputString = STserialize(); //serialize new RB tree after inserting new keys
	printf("%lu %s\n",strlen(outputString)+1,outputString);
	free(outputString);
}
