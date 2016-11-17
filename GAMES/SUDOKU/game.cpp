#include "game.h"



game::game()
{
	int j = 0;
	
	board_count = 5;
	
	cout << "\nMaking easy board..." << endl;
	easy = new block[5];
	cout << "Easy board COMPLETE." << endl;

	cout << "\nMaking medium board..." << endl;
	medium = new block[5];
	cout << "Medium board COMPLETE." << endl;

	cout << "\nMaking hard board..." << endl;
	hard = new block[5];
	cout << "Hard board COMPLETE." << endl;

	cout << "\nAdding BLANKS to all puzzle boards..." << endl;

	for(j = 0; j < 5; ++j)
	{
		easy[j].make_puzzle_easy();
		medium[j].make_puzzle_medium();
		hard[j].make_puzzle_hard();
	}

	cout << "\nPuzzles COMPLETE." << endl;
}


game::game(int board_number)
{
	int j = 0;

	if(board_number < 1 || board_number > 50)
		board_number = 10;

	board_count = board_number;

	easy = new block[board_number];
	medium = new block[board_number];
	hard = new block[board_number];
	
	for(j = 0; j < board_number; ++j)
	{
		easy[j].make_puzzle_easy();
		medium[j].make_puzzle_medium();
		hard[j].make_puzzle_hard();
	}
}


game::~game()
{
	delete []easy;
	delete []medium;
	delete []hard;
	
	easy = medium = hard = NULL;

	board_count = 0;
}	




void game::display() const
{
	int j = 0;

	cout << "\nEASY PUZZLES: " << endl;
	for(j = 0; j < board_count; ++j)
	{
		cout << "\nEASY # " << j+1 << endl;
		cout << easy[j];
	}

	cout << "\nMEDIUM PUZZLES: " << endl;
	for(j = 0; j < board_count; ++j)
	{
		cout << "\nMEDIUM # " << j+1 << endl;
		cout << medium[j];
	}

	cout << "\nHARD PUZZLES: " << endl;
	for(j = 0; j < board_count; ++j)
	{
		cout << "\nHARD # " << j+1 << endl;
		cout << hard[j];
	}
}




ostream & operator << (ostream & output, const game & to_show)
{
	to_show.display();

	return output;
}


void game::save(const char fileName[])
{
	fstream file_out;
	int j = 0;	

	if(!fileName)
		return;

	file_out.open(fileName, ios::out);
	file_out << "\nSUDOKU PUZZLES by Josh\n";
//	file_out.close();

	if(!file_out)
		return;

	file_out << "\nEASY PUZZLES:\n";
	
	for(j = 0; j < board_count; ++j)
	{
		file_out << "\nEASY # " << j+1;
		easy[j].save(fileName, file_out);
	}

	file_out << "\nMEDIUM PUZZLES:\n";

	for(j = 0; j < board_count; ++j)
	{
		file_out << "\nMEDIUM # " << j+1;
		medium[j].save(fileName, file_out);
	}

	file_out << "\nHARD PUZZLES:\n"; 

	for(j = 0; j < board_count; ++j)
	{
		file_out << "\nHARD # " << j+1;	
		hard[j].save(fileName, file_out);
	}

	file_out.close();
}

	

		



