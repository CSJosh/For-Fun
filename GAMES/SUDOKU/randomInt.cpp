


#include "randomInt.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;

randomInt::randomInt()
{
	int j = 0;
	int temp = 0;
	int index = 0;
	srand(time(NULL));

	numList = new int[9];
	indexList = new int[9];
	listSize = 9;

	for(j = 0; j < 9; ++j)
	{
		numList[j] = j+1;
		indexList[j] = j;
	}

	for(j = 0; j < 9; ++j)
	{
		index = rand() % 9;
		temp = indexList[index];
		indexList[index] = indexList[j];
		indexList[j] = temp;
	}

	currentIndex = 0; 
}


randomInt::randomInt(int length)
{
	int j = 0;
	int temp = 0;
	int index = 0;
	srand(time(NULL));

	if(length < 1)
		length = 9;

	listSize = length;

	numList = new int[length];
	indexList = new int[listSize];


	for(j = 0; j < length; ++j)
	{
		numList[j] = j+1;
		indexList[j] = j;
	}

	for(j = 0; j < length; ++j)
	{
		index = rand() % length;
		temp = indexList[index];
		indexList[index] = indexList[j];
		indexList[j] = temp;
	}

	currentIndex = 0; 
}


randomInt::~randomInt()
{
	delete []numList;
	numList = NULL;

	delete []indexList;
	indexList = NULL;

	listSize = 0;
}



bool randomInt::isEmpty()
{
	if(currentIndex == listSize)
		return true;

	return false;
}


void randomInt::resetNum()
{
	currentIndex = 0;
}



int randomInt::getRandNum()
{
	//int toReturn = 0;

	if(currentIndex == listSize)
		return 0;

	return  numList[indexList[currentIndex++]];
}


