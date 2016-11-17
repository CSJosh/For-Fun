




#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <time.h>
//#include "randomInt.h"
//#include "block.h"
#include "game.h"
#include <fstream>

using namespace std;


int main()
{

	srand(time(NULL));
/*
	int *** array = NULL;
	int j = 0;
	int k = 0;
	int i = 0;

	array = new int **[3];
	
	for(j = 0; j < 3; ++j)
		array[j] = new int*[3];

	for(j = 0; j < 3; ++j)
	{
		for(k = 0; k < 3; ++k)
			array[j][k] = new int[3];
	}

	for(j = 0; j < 3; ++j)
	{
		for(k = 0; k < 3; ++k)
		{
			for(i = 0; i < 3; ++i)
				array[j][k][i] = i+1;
		}
	}

	for(j = 0; j < 3; ++j)
	{
		for(k = 0; k < 3; ++k)
		{
			for(i = 0; i < 3; ++i)
				cout << "\narray[" << j << "][" << k << "][" << i << "]: " << array[j][k][i];
		}
	}
*/
/*	randomInt myNum(100);
	int number = 0;
	int count = 0;

	cout << endl;
	while(!myNum.isEmpty())
	{

		if(count == 10)
		{
			cout << endl;
			count = 0;
		}

		number = myNum.getRandNum();
		cout << " " << number;
		++count;
	}
	cout << endl;
*/

//	block toTest;
/*	block med;
	block hard;
	block copy;

	cout << "\nEASY SOLUTIONS:" << toTest << "\nMEDIUM SOLUTIONS:" << med << "\nHARD SOLUTIONS:" << hard << endl;	

	toTest.make_puzzle_easy();
	copy = toTest;
	med.make_puzzle_medium();
	hard.make_puzzle_hard();

	cout << "\nEASY: " << endl;
	toTest.show();
	cout << "\nMEDIUM: " << endl;
	med.show();
	cout << "\nHARD: " << endl;
	hard.show();
*/

	//toTest.set_choices();
	//toTest.display_choices();
	


//	toTest.solve();
/*

	if(toTest.solve() && med.solve() && hard.solve())
		cout << "\nHere are ALL the SOLVED puzzles: " << endl;
	else
		cout << "\nAt least one of the puzzles was NOT solved..." << endl;
*/
//	toTest.display_choices();
	
//	cout << "\nEASY: " << toTest << "\nMEDIUM: " << med << "\nHARD: " << hard << endl;

//	cout << "\nHere is a copy of the EASY puzzle: " << copy << endl;
/*
	cout << "\nHere is the list of the EASY puzzles: " << endl;
	
	toTest.print_puzzles_easy(3);

	cout << "\nHere is the list of the MEDIUM puzzles: " << endl;
	
	toTest.print_puzzles_medium(3);

	cout << "\nHere is the list of the HARD puzzles: " << endl;
	
	toTest.print_puzzles_hard(3);
*/

	//creates easy, medium, and diffcult sudoku puzzles. The argument represents the number of puzzles in each difficulty level
	game sudoku(2);
	char temp[101];
	char * file = NULL;

	cout << "\nEnter the file name: ";
	cin >> temp;
	cin.ignore(100, '\n');
	file = new char[strlen(temp)+1];
	strcpy(file, temp);

//	ofstream out("/Users/joshuaaldridge/Desktop/test.txt");

//	FILE * f = fopen("/Users/ashleyaldridge/Desktop/test.txt", "w");
//	fclose(f);


	cout << "Here is the file name " << file << endl;	

	sudoku.save(file);

	delete []file;
	file = NULL;


//	cout << sudoku;



//	cout << toTest;
	

//	toTest.display_easy();
//	toTest.display_easy();
	
/*
	cout << "\nMEDIUM: " << endl;
	toTest.display_med();
//	toTest.display_med();

	cout << "\nHARD: " << endl;
	toTest.display_hard();
//	toTest.display_hard();
*/
	cout << endl;
	return 0;
}


