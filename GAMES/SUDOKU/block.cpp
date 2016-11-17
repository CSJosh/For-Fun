
#include <iostream>
#include "block.h"
#include "randomInt.h"
#include <stdlib.h>
#include <time.h>


using namespace std;

int block::block_blank_count(int row, int col)
{
	int j = 0;
	int k = 0;
	int toReturn = 0;

	if(row >= 0 && row <= 2)
	{
		if(col >= 0 && col < 3)
		{
			for(j = 0; j < 3; ++j)
			{
				for(k = 0; k < 3; ++k)
				{
					if(numSet[j][k] == 0)
						++toReturn;
				}
			}
		}
		else if(col >= 3 && col < 6)
		{
			for(j = 0; j < 3; ++j)
			{
				for(k = 3; k < 6; ++k)
				{
					if(numSet[j][k] == 0)
						++toReturn;
				}
			}
		}	
		else if(col >= 6 && col < 9)
		{
			for(j = 0; j < 3; ++j)
			{
				for(k = 6; k < 9; ++k)
				{
					if(numSet[j][k] == 0)
						++toReturn;
				}
			}
		}
	}
		
	else if(row >= 3 && row <= 5)
	{
		if(col >= 0 && col < 3)
		{
			for(j = 3; j < 6; ++j)
			{
				for(k = 0; k < 3; ++k)
				{
					if(numSet[j][k] == 0)
						++toReturn;
				}
			}
		}
		else if(col >= 3 && col < 6)
		{
			for(j = 3; j < 6; ++j)
			{
				for(k = 3; k < 6; ++k)
				{
					if(numSet[j][k] == 0)
						++toReturn;
				}
			}
		}	
		else if(col >= 6 && col < 9)
		{
			for(j = 3; j < 6; ++j)
			{
				for(k = 6; k < 9; ++k)
				{
					if(numSet[j][k] == 0)
						++toReturn;
				}
			}
		}
	}

	else if(row >= 6 && row <= 8)
	{
		if(col >= 0 && col < 3)
		{
			for(j = 6; j < 9; ++j)
			{
				for(k = 0; k < 3; ++k)
				{
					if(numSet[j][k] == 0)
						++toReturn;
				}
			}
		}
		else if(col >= 3 && col < 6)
		{
			for(j = 6; j < 9; ++j)
			{
				for(k = 3; k < 6; ++k)
				{
					if(numSet[j][k] == 0)
						++toReturn;
				}
			}
		}	
		else if(col >= 6 && col < 9)
		{
			for(j = 6; j < 9; ++j)
			{
				for(k = 6; k < 9; ++k)
				{
					if(numSet[j][k] == 0)
						++toReturn;
				}
			}
		}
	}

	return toReturn;
}



bool block::match_check(int toCheck, int row, int col)
{
	int j = 0;
	int k = 0;

	if(row >= 0 && row <= 2)
	{
		if(col >= 0 && col < 3)
		{
			for(j = 0; j < 3; ++j)
			{
				for(k = 0; k < 3; ++k)
				{
					if(numSet[j][k] == toCheck)
						return true;
				}
			}
		}
		else if(col >= 3 && col < 6)
		{
			for(j = 0; j < 3; ++j)
			{
				for(k = 3; k < 6; ++k)
				{
					if(numSet[j][k] == toCheck)
						return true;
				}
			}
		}	
		else if(col >= 6 && col < 9)
		{
			for(j = 0; j < 3; ++j)
			{
				for(k = 6; k < 9; ++k)
				{
					if(numSet[j][k] == toCheck)
						return true;
				}
			}
		}
	}
		
	else if(row >= 3 && row <= 5)
	{
		if(col >= 0 && col < 3)
		{
			for(j = 3; j < 6; ++j)
			{
				for(k = 0; k < 3; ++k)
				{
					if(numSet[j][k] == toCheck)
						return true;
				}
			}
		}
		else if(col >= 3 && col < 6)
		{
			for(j = 3; j < 6; ++j)
			{
				for(k = 3; k < 6; ++k)
				{
					if(numSet[j][k] == toCheck)
						return true;
				}
			}
		}	
		else if(col >= 6 && col < 9)
		{
			for(j = 3; j < 6; ++j)
			{
				for(k = 6; k < 9; ++k)
				{
					if(numSet[j][k] == toCheck)
						return true;
				}
			}
		}
	}

	else if(row >= 6 && row <= 8)
	{
		if(col >= 0 && col < 3)
		{
			for(j = 6; j < 9; ++j)
			{
				for(k = 0; k < 3; ++k)
				{
					if(numSet[j][k] == toCheck)
						return true;
				}
			}
		}
		else if(col >= 3 && col < 6)
		{
			for(j = 6; j < 9; ++j)
			{
				for(k = 3; k < 6; ++k)
				{
					if(numSet[j][k] == toCheck)
						return true;
				}
			}
		}	
		else if(col >= 6 && col < 9)
		{
			for(j = 6; j < 9; ++j)
			{
				for(k = 6; k < 9; ++k)
				{
					if(numSet[j][k] == toCheck)
						return true;
				}
			}
		}
	}

	return false;
}



void set_row(int to_build[], int used_numbers[])
{
	//srand(time(NULL));
	int j = 0;
	int k = 0;
	int index = 0;
	bool found = false;
	bool set = false;

	for(j = 3; j < 9; ++j)
	{
		do
		{
			found = false;
			index = rand() % 9 + 1; // 1 - 9

			//cout << "\nIndex: " << index << endl;
			
			for(k = 0; k < 9; ++k)
			{
				if(used_numbers[k] == index){
					found = true;
			//		cout << "\nINDEX ALREADY EXISTS!";
				}
			}
		}
		while(found == true);
		
		to_build[j] = index;

		for(k = 0; k < 9 && !set; ++k)
		{
			if(used_numbers[k] == 0){
				used_numbers[k] = index;
				set = true;
			}
		}
		set = false;

	}
}



block::block()
{
	//srand(time(NULL));
	int j = 0;
	int k = 0;
	int h = 0;
	int i = 0;
	int index = 0;
	int count = 0;
	int resetCount = 0;
	bool found = false;
		
	numSet = new square*[9];
	numList = new int[9];

	for(j = 0; j < 9; ++j)
	{
		numSet[j] = new square[9];
		numList[j] = j+1;
	}

	for(j = 0; j < 9; ++j)
	{
		for(k = 0; k < 9; ++k)
			numSet[j][k] = 0;//OVERLOADED ASSIGNMENT OPERATOR
	}

	for(j = 0; j < 9; ++j)
	{
		for(k = 0; k < 9; ++k)
		{
			do
			{
				index = rand() % 9 + 1;
				found = false;			
//				cout << "\nRandom index: " << index;

				found = match_check(index, j, k);

				if(found){
//					cout << " -- ALREADY EXISTS in 3x3 block!";
					++count;
				}
				else
				{
					for(h = 0; h < 9; ++h)
					{
						if(numSet[j][h] == index)//OVERLOADED EQUALITY OPERATOR
						{
							found = true;
//							cout << " -- ALREADY EXISTS in j row!";
							++count;
						}
					}
				}
				
				if(!found)
				{
					for(h = 0; h < 9; ++h)		
					{
						if(numSet[h][k] == index)//OVERLOADED EQUALITY OPERATOR
						{
							found = true;
//							cout << " -- ALREADY EXISTS in k column!";
							++count;
						}
					}
				}
			

				if(count > 50)//IF REPEAT ATTEMPTS EXCEEDS 20, CLEAR THE ROW
				{
					cout << "\nMAXIMUM ATTEMPTS EXCEEDED! CLEARING ROW. " << endl;

					for(i = 0; i < 9; ++i)
						numSet[j][i] = 0;//SET ALL ELEMENTS IN ROW J TO ZERO
					k = 0;//RESET K; WILL INCREMENT TO '0' AT NEXT ITERATION
					count = 0;
					++resetCount;
				}
				
				if(resetCount > 20)
				{
					cout << "\n\n\nRESETTING BOARD" << endl << endl;
					
					for(j = 0; j < 9; ++j)
					{
						for(k = 0; k < 9; ++k)
							numSet[j][k] = 0;
					}
					k = j = 0;
					resetCount = 0;
				}
			}
			while(found == true);

			numSet[j][k] = index;
			count = 0;
			cout << "\nIndex for numSet[j][k] at position [" << j << "][" << k << "] is: " << index;
		}
	}
}



void block::resetNumList()
{
	for(int j = 0; j < 9; ++j)
		numList[j] = j+1;
}


int block::getNumber()
{
	int j = 0;
	int toReturn = 0;

	for(j = 0; j < 9; ++j)
	{
		if(numList[j] != 0)
		{
			toReturn = numList[j];
			numList[j] = 0;
			return toReturn;
		}
	}
	return 0;
}


int block::blank_count()
{
	int count = 0;

	for(int j = 0; j < 9; ++j)
	{
		for(int k = 0; k < 9; ++k)
		{
			if(numSet[j][k] == 0)
				++count;
		}
	}
	return count;
}


block::~block()
{
	int j = 0;

	for(j = 0; j < 9; ++j)
	{
		delete []numSet[j];
		numSet[j] = NULL;
	}

	delete []numList;
	numList = NULL;
	delete []numSet;
	numSet = NULL;
}



void block::display() const
{
	int j = 0;
	int k = 0;


	for(j = 0; j < 9; ++j)
	{
		cout << endl;

		if(j == 3 || j == 6)
			cout << "*********************" << endl;

		for(k = 0; k < 9; ++k)
		{
			if(numSet[j][k] != 0)
				cout << numSet[j][k];
			else
				cout << "_";
			cout << " ";
			
			if(k == 2 || k == 5)
				cout << "| ";
		}
	}
	cout << endl;
}


/*
void block::display_easy() const
{
	int array[9];//0-8
	int rand_num = 0;
	int j = 0;
	int k = 0;
	int i = 0;
	srand(time(NULL));
	
	
	for(j = 0; j < 9; ++j)
	{
		for(i = 0; i < 9; ++i)
		{
			rand_num = rand() % 9;//0-8
	
			if(rand_num > 2)//3-8
				array[i] = 1;
			else//0-2
				array[i] = 0;
		}


		cout << endl;

		if(j == 3 || j == 6)
			cout << "*********************" << endl;

		
		for(k = 0; k < 9; ++k)
		{
			if(array[k] == 1)
				cout << numSet[j][k] << " ";
			else
				cout << "_ ";
			if(k == 2 || k == 5)
				cout << "| ";

		}
	}
	cout << endl;
}


	
void block::display_med() const
{
	int array[9];//0-8
	int rand_num = 0;
	int j = 0;
	int k = 0;
	int i = 0;
	srand(time(NULL));
	
	
	for(j = 0; j < 9; ++j)
	{
		for(i = 0; i < 9; ++i)
		{
			rand_num = rand() % 9;//0-8
	
			if(rand_num > 4)//3-8
				array[i] = 1;
			else//0-2
				array[i] = 0;
		}


		cout << endl;

		if(j == 3 || j == 6)
			cout << "*********************" << endl;


		for(k = 0; k < 9; ++k)
		{
			if(array[k] == 1)
				cout << numSet[j][k] << " ";
			else
				cout << "_ ";
			if(k == 2 || k == 5)
				cout << "| ";

		}
	}
	cout << endl;
}


void block::display_hard() const
{
	int array[9];//0-8
	int rand_num = 0;
	int j = 0;
	int k = 0;
	int i = 0;
	srand(time(NULL));
		
	for(j = 0; j < 9; ++j)
	{
		for(i = 0; i < 9; ++i)
		{
			rand_num = rand() % 9;//0-8
	
			if(rand_num > 5)//3-8
				array[i] = 1;
			else//0-2
				array[i] = 0;
		}

		cout << endl;

		if(j == 3 || j == 6)
			cout << "*********************" << endl;		

		for(k = 0; k < 9; ++k)
		{
			if(array[k] == 1)
				cout << numSet[j][k] << " ";
			else
				cout << "_ ";

			if(k == 2 || k == 5)
				cout << "| ";
		}
	}
	cout << endl;
}
*/

ostream & operator << (ostream & output, const block & toShow)
{
	toShow.display();

	return output;
}

/*
fstream & operator << (fstream & output, const block & toShow)
{
	toShow.display();
	return output;
}
*/


void block::show() const
{
	int j = 0;
	int k = 0;


	for(j = 0; j < 9; ++j)
	{
		cout << endl;

		if(j == 3 || j == 6)
			cout << "*********************" << endl;

		for(k = 0; k < 9; ++k)
		{
			if(numSet[j][k] == 0)
				cout << "_ ";
			else
				cout << numSet[j][k] <<" ";
			if(k == 2 || k == 5)
				cout << "| ";
		}
	}
	cout << endl;
}


//Finds all numbers in this row, and removes options from the numbers choice list
void block::set_row_choices(int row, int col)
{
	int j = 0;
	int number = numSet[row][col].get_number();

	if(number != 0)
	{
		numSet[row][col].clear_choices();
		return;
	}

	for(j = 0; j < 9; ++j)
	{
		if(numSet[row][j] != 0)
			numSet[row][col].remove_choice(numSet[row][j].get_number());
	}
}		

void block::set_column_choices(int row, int col)
{
	int j = 0;

	int number = numSet[row][col].get_number();

	if(number != 0)
	{
		numSet[row][col].clear_choices();
		return;
	}

	for(j = 0; j < 9; ++j)
	{
		if(numSet[j][col] != 0)
			numSet[row][col].remove_choice(numSet[j][col].get_number());
	}
}


void block::set_block_choices(int row, int col)
{
	int j = 0;
	int k = 0;

	int number = numSet[row][col].get_number();

	if(number != 0)
	{
		numSet[row][col].clear_choices();
		return;
	}
	

	if(row >= 0 && row <= 2)
	{
		if(col >= 0 && col < 3)
		{
			for(j = 0; j < 3; ++j)
			{
				for(k = 0; k < 3; ++k)
				{
					if(numSet[j][k] != 0)
						numSet[row][col].remove_choice(numSet[j][k].get_number());
				}
			}
		}
		else if(col >= 3 && col < 6)
		{
			for(j = 0; j < 3; ++j)
			{
				for(k = 3; k < 6; ++k)
				{
					if(numSet[j][k] != 0)
						numSet[row][col].remove_choice(numSet[j][k].get_number());
				}
			}
		}	
		else if(col >= 6 && col < 9)
		{
			for(j = 0; j < 3; ++j)
			{
				for(k = 6; k < 9; ++k)
				{
					if(numSet[j][k] != 0)
						numSet[row][col].remove_choice(numSet[j][k].get_number());
				}
			}
		}
	}
		
	else if(row >= 3 && row <= 5)
	{
		if(col >= 0 && col < 3)
		{
			for(j = 3; j < 6; ++j)
			{
				for(k = 0; k < 3; ++k)
				{
					if(numSet[j][k] != 0)
						numSet[row][col].remove_choice(numSet[j][k].get_number());
				}
			}
		}
		else if(col >= 3 && col < 6)
		{
			for(j = 3; j < 6; ++j)
			{
				for(k = 3; k < 6; ++k)
				{
					if(numSet[j][k] != 0)
						numSet[row][col].remove_choice(numSet[j][k].get_number());
				}
			}
		}	
		else if(col >= 6 && col < 9)
		{
			for(j = 3; j < 6; ++j)
			{
				for(k = 6; k < 9; ++k)
				{
					if(numSet[j][k] != 0)
						numSet[row][col].remove_choice(numSet[j][k].get_number());
				}
			}
		}
	}

	else if(row >= 6 && row <= 8)
	{
		if(col >= 0 && col < 3)
		{
			for(j = 6; j < 9; ++j)
			{
				for(k = 0; k < 3; ++k)
				{
					if(numSet[j][k] != 0)
						numSet[row][col].remove_choice(numSet[j][k].get_number());
				}
			}
		}
		else if(col >= 3 && col < 6)
		{
			for(j = 6; j < 9; ++j)
			{
				for(k = 3; k < 6; ++k)
				{
					if(numSet[j][k] != 0)
						numSet[row][col].remove_choice(numSet[j][k].get_number());
				}
			}
		}	
		else if(col >= 6 && col < 9)
		{
			for(j = 6; j < 9; ++j)
			{
				for(k = 6; k < 9; ++k)
				{
					if(numSet[j][k] != 0)
						numSet[row][col].remove_choice(numSet[j][k].get_number());
				}
			}
		}
	}
}



void  block::display_choices() const
{
	int j = 0;
	int k = 0;
	int number = 0;

	for(j = 0; j < 9; ++j)
	{
		for(k = 0; k < 9; ++k)
		{
			number = numSet[j][k].get_number();
			cout << "\n numSet[" << j << "][" << k << "], value: " << number;
			cout << "\nChoices: ";
			numSet[j][k].display_choices();
		}
	}
} 

void block::set_choices()
{
	int j = 0;
	int k = 0;
	
	for(j = 0; j < 9; ++j)
	{
		for(k = 0; k < 9; ++k)
		{
			set_row_choices(j, k);
			set_column_choices(j, k);
			set_block_choices(j, k);
		}
	}
}


bool block::solve()
{
	int j = 0;
	int k = 0;
	int blanks = 0;
	int max_count = 0;
	int num = 0;
	int choiceCount = 0;
	int toSet = 0;

	blanks = blank_count();
	max_count = blanks * 20;

	while(blanks > 0 && max_count > 0)
	{
		set_choices();

		for(j = 0; j < 9; ++j)
		{
			for(k = 0; k < 9; ++k)
			{
				num = numSet[j][k].get_number();
				
				if(num == 0)//if there is an empty slot
				{
					choiceCount = numSet[j][k].choice_count();
					--max_count;					

					if(choiceCount == 1)
					{
						toSet = numSet[j][k].get_remaining();
						
						if(toSet != 0){
							numSet[j][k] = toSet;
							--blanks;
						}
					}
				}
			}
		}					
	}

	if(blanks == 0)
		return true;
	
	return false;			
}



void block::remove_all()
{
	int j = 0;

	for(j = 0; j < 9; ++j)
	{
		delete []numSet[j];
		numSet[j] = NULL;
	}
	
	delete []numSet;
	numSet = NULL;
}


void block::copy(const block & toCopy)
{
	int j  = 0;
	int k = 0;
	
	for(j = 0; j < 9; ++j)
	{
		for(k = 0; k < 9; ++k)
			numSet[j][k] = toCopy.numSet[j][k];
	}
}


block & block::operator = (const block & toCopy)
{
	copy(toCopy);

	return *this;
}



void block::make_puzzle_easy()
{
	int array[9];//0-8
	int rand_num = 0;
	int j = 0;
	int k = 0;
	int i = 0;
	bool success = false;
	block tempSolutions;
	block tempPuzzle;
	//srand(time(NULL));
	
	do
	{
		tempSolutions = *this;//make copy of the completed grid
		
		for(j = 0; j < 9; ++j)
		{
			for(i = 0; i < 9; ++i)
			{
				rand_num = rand() % 9;//0-8
		
				if(rand_num > 2)//3-8
					array[i] = 1;
				else//0-2
					array[i] = 0;
			}
			
			for(k = 0; k < 9; ++k)
			{
				if(array[k] == 0)
					 numSet[j][k] = 0;//set random number to 0 (blank)
			}
		}
			
		tempPuzzle = *this;//make copy of puzzled version of grid

		success = tempPuzzle.solve();//try to solve copy of puzzle

		if(!success)//if could not solve the copy
			*this = tempSolutions;//copy the original complete grid back into this object
	}
	while(!success);//do all this while there is an unsolvable puzzle produced
}
	

void block::make_puzzle_medium()
{
	int array[9];//0-8
	int rand_num = 0;
	int j = 0;
	int k = 0;
	int i = 0;
	bool success = false;
	block tempSolutions;
	block tempPuzzle;
	//srand(time(NULL));
	
	do
	{
		tempSolutions = *this;//make copy of the completed grid
		
		for(j = 0; j < 9; ++j)
		{
			for(i = 0; i < 9; ++i)
			{
				rand_num = rand() % 9;//0-8
		
				if(rand_num > 3)//3-8
					array[i] = 1;
				else//0-2
					array[i] = 0;
			}
			
			for(k = 0; k < 9; ++k)
			{
				if(array[k] == 0)
					 numSet[j][k] = 0;//set random number to 0 (blank)
			}
		}
			
		tempPuzzle = *this;//make copy of puzzled version of grid

		success = tempPuzzle.solve();//try to solve copy of puzzle

		if(!success)//if could not solve the copy
			*this = tempSolutions;//copy the original complete grid back into this object
	}
	while(!success);//do all this while there is an unsolvable puzzle produced
}
	



void block::make_puzzle_hard()
{
	int array[9];//0-8
	int rand_num = 0;
	int j = 0;
	int k = 0;
	int i = 0;
	bool success = false;
	block tempSolutions;
	block tempPuzzle;
	//srand(time(NULL));
	
	do
	{
		tempSolutions = *this;//make copy of the completed grid
		
		for(j = 0; j < 9; ++j)
		{
			for(i = 0; i < 9; ++i)
			{
				rand_num = rand() % 9;//0-8
		
				if(rand_num > 4)//3-8
					array[i] = 1;
				else//0-2
					array[i] = 0;
			}
			
			for(k = 0; k < 9; ++k)
			{
				if(array[k] == 0)
					 numSet[j][k] = 0;//set random number to 0 (blank)
			}
		}
			
		tempPuzzle = *this;//make copy of puzzled version of grid

		success = tempPuzzle.solve();//try to solve copy of puzzle

		if(!success)//if could not solve the copy
			*this = tempSolutions;//copy the original complete grid back into this object
	}
	while(!success);//do all this while there is an unsolvable puzzle produced
}
	



void block::print_puzzles_easy(int puzzle_count)
{
//	block temp;
	block ** epuzzle = NULL;
	int j = 0;
//	bool success = false;
		

	if(puzzle_count < 1)
		puzzle_count = 10;

	epuzzle = new block*[puzzle_count];

	for(j = 0; j < puzzle_count; ++j)
	{
	//	do
	//	{
			epuzzle[j] = new block;
			epuzzle[j]->make_puzzle_easy();
	//		temp = *epuzzle[j];
			
	//		success = epuzzle[j]->solve();
				
	//		if(!success)
	//			cout << "\nBAD PUZZLE" << endl;
	
	//	}
	//	while(!success);
		
		cout << "\nPUZZLE # " << j+1 << endl;

		cout << *epuzzle[j];
		delete epuzzle[j];
		epuzzle[j] = NULL;
	}

	delete []epuzzle;
	epuzzle = NULL;
}



void block::print_puzzles_medium(int puzzle_count)
{
//	block temp;
	block ** epuzzle = NULL;
	int j = 0;
//	bool success = false;
		

	if(puzzle_count < 1)
		puzzle_count = 10;

	epuzzle = new block*[puzzle_count];

	for(j = 0; j < puzzle_count; ++j)
	{
	//	do
	//	{
			epuzzle[j] = new block;
			epuzzle[j]->make_puzzle_medium();
	//		temp = *epuzzle[j];
			
	//		success = epuzzle[j]->solve();
				
	//		if(!success)
	//			cout << "\nBAD PUZZLE" << endl;
	
	//	}
	//	while(!success);
		
		cout << "\nPUZZLE # " << j+1 << endl;

		cout << *epuzzle[j];
		delete epuzzle[j];
		epuzzle[j] = NULL;
	}

	delete []epuzzle;
	epuzzle = NULL;
}





void block::print_puzzles_hard(int puzzle_count)
{
//	block temp;
	block ** epuzzle = NULL;
	int j = 0;
//	bool success = false;
		

	if(puzzle_count < 1)
		puzzle_count = 10;

	epuzzle = new block*[puzzle_count];

	for(j = 0; j < puzzle_count; ++j)
	{
	//	do
	//	{
			epuzzle[j] = new block;
			epuzzle[j]->make_puzzle_hard();
	//		temp = *epuzzle[j];
			
	//		success = epuzzle[j]->solve();
				
	//		if(!success)
	//			cout << "\nBAD PUZZLE" << endl;
	
	//	}
	//	while(!success);
		
		cout << "\nPUZZLE # " << j+1 << endl;

		cout << *epuzzle[j];
		delete epuzzle[j];
		epuzzle[j] = NULL;
	}

	delete []epuzzle;
	epuzzle = NULL;
}


void block::save(const char * fileName, fstream & file_out)
{
	//ofstream file_out;
	int j = 0;
	int k = 0;
	int num = 0;

	if(!fileName)
		return;

	//file_out.open(fileName, ios::app);

	if(!file_out)
		return;

	for(j = 0; j < 9; ++j)
	{
		file_out << "\n";

		if(j == 3 || j == 6)
			file_out << "*********************\n";

		for(k = 0; k < 9; ++k)
		{
			if(numSet[j][k] == 0)
				file_out << "_ ";
			else
			{
				num = numSet[j][k].get_number();
				file_out << num <<" ";
			}
			if(k == 2 || k == 5)
				file_out << "| ";
		}
	}
	file_out << "\n";

//	file_out.close();
}









	
