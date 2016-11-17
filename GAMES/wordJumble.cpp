
#include "wordJumble.h"
#include <iostream>
#include <cstring>
#include <cctype>
#include <time.h>
#include <stdlib.h>

using namespace std;
const int SIZE = 101;

wordJumble::wordJumble()
{

	rear = new player;
	rear->name = NULL;
	rear->score = 0;
	rear->next = new player;
	rear->next->next = rear;
	rear = rear->next;
	rear->name = NULL;
	rear->score = 0;
	
	yourTurn = rear->next;	

	player_guess = NULL;
	secretWord = NULL;
	jumble = NULL;
	tries = 3;
	round = 1;
	temp_array = new char[SIZE];
	
}

wordJumble::~wordJumble()
{
	if(rear)
	{
		if(rear->next->name)
			delete []rear->next->name;
		delete rear->next;
	}

	if(rear->name)
		delete []rear->name;
	
	delete rear;
	rear = NULL;
	yourTurn = NULL;

	if(player_guess)
	{
		delete []player_guess;
		player_guess = NULL;
	}

	if(secretWord)
	{
		delete []secretWord;
		secretWord = NULL;
	}

	if(jumble)
	{
		delete []jumble;
		jumble = NULL;
	}

	delete []temp_array;
	temp_array = NULL;
}	

int wordJumble::name_prompt()
{
	
	cout << "\n\t\tEnter player 1's name here: ";
	cin.get(temp_array,100,'\n');
	cin.ignore(100,'\n');

	yourTurn->name = new char[strlen(temp_array) +1];
	strcpy(yourTurn->name, temp_array);

 	cout << "\n\t\tEnter player 2's name here: ";
	cin.get(temp_array,100,'\n');
	cin.ignore(100,'\n');

	rear->name = new char[strlen(temp_array) +1];
	strcpy(rear->name, temp_array);
}


int wordJumble::display_rules()
{
	cout << "\nRULES:" << "\nEach game consists of 3 rounds."
	<< "\nEach player will be the word selecter OR guesser once per round."
	<< "\nEach guesser gets 3 chances to guess a word."
	<< "\n50pts awarded for guessing on the 1st try."
	<< "\n30pts awarded for guessing on the 2nd try."
	<< "\n15pts awarded for guessing on the 3rd try."
	<< "\n25pts awarded to other player if word cannot be guessed."
	<< "\nHighest score after 3 rounds WINS." << endl;
}
	
int wordJumble::wordPrompt()
{
	int j = 0;
	int len = 0;

	
	cout << "\n\t\t" << yourTurn->name << ", enter a word to scramble: ";
	cin.get(temp_array,100,'\n');
	cin.ignore(100,'\n');

	if(secretWord)
		delete []secretWord;

	secretWord = new char[strlen(temp_array) +1];
	strcpy(secretWord,temp_array);
	
	len = strlen(secretWord);
	
	for(j=0; j<len; ++ j)
		secretWord[j] = toupper(secretWord[j]);
}




int wordJumble::scramble()
{
	int * index;
	int length = 0;
	int j = 0;
	int k = 0;

	srand(time(NULL));

	if(!secretWord)
		return 0;

	length = strlen(secretWord);

	jumble = new char[length + 1];
	index = new int[length];

	for(k=0; k<length; ++k)
		index[k] = k;


	for(k=0; k<length; k)
	{
		j = rand() % length;
		
		if(index[j] != -1)
		{
			jumble[k] = secretWord[index[j]];
			index[j] = -1;
			++k;
		}
	}

	if(index)
		delete []index;
}


int wordJumble::check_match()
{
	int j = 0;
	int len = 0;

	if(!player_guess || !secretWord)
		return 0;

	len = strlen(player_guess);

	for(j=0; j<len; ++j)
		player_guess[j] = toupper(player_guess[j]);
	
	if(strcmp(player_guess, secretWord) == 0)
		return 1;
	else
		return 0;
}
	

int wordJumble::again()
{
	char choice = 'N';	
	
	do
	{
		cout << "\nPlay Again? Y/N?: ";
		cin >> choice;
		cin.ignore(100,'\n');

		choice = toupper(choice);
	
		if(choice == 'Y')
			return 1;

		else if(choice == 'N')
			return 0;
	}
	while(choice);
}

int wordJumble::display_word()
{
	if(!secretWord)
		return 0;

	cout << "\n\t\tSecret Word: " << secretWord << endl;
	return 1;
}

int wordJumble::display_jumble()
{
	if(!jumble)
		return 0;

	cout << "\n\t\tJumbled Word: " << jumble << endl;
	return 1;
}


int wordJumble::display_scores()
{
	if(!rear)
		return 0;

	cout << "\n\t\t" << rear->next->name << "'s score: " << rear->next->score;
	cout << "\n\t\t" << rear->name << "'s score: " << rear->score;
}

int wordJumble::player_guess_prompt()
{
	cout << "\n\t\t" << yourTurn->next->name << "'s turn to guess the word: ";
	cin.get(temp_array,100,'\n');
	cin.ignore(100,'\n');

	if(player_guess)
		delete []player_guess;

	player_guess = new char[strlen(temp_array)+1];
	strcpy(player_guess, temp_array);
}

int wordJumble::tries_left()
{
	if(tries > 0)
		return 1;
	return 0;
}


int wordJumble::add_score_good_guess()
{
	if(!yourTurn  || !yourTurn->next)
		return 0;

	if(tries == 3)
	{
		yourTurn->next->score += 50;
		cout << "\n\t\t+50 PTS for " << yourTurn->next->name << ".";
	}

	else if(tries == 2)
	{
		yourTurn->next->score += 30;
		cout << "\n\t\t+30 PTS for " << yourTurn->next->name << ".";
	}
	
	else if(tries == 1)
	{	
		yourTurn->next->score += 15;
		cout << "\n\t\t+15 PTS for " << yourTurn->next->name << ".";
	}
}

int wordJumble::add_score_no_guess()
{
	if(!yourTurn  || !yourTurn->next)
		return 0;
	
	yourTurn->score += 25;
	cout << "\n\t\t+25 PTS for " << yourTurn->name << ".";

	return 1;
}

int wordJumble::display_round()
{
	cout << "\n\n\t\tROUND: " << round; 
	return 1;
}

int wordJumble::reset_tries()
{
	tries = 3;
	return 1;
}

int wordJumble::minus_tries()
{
	--tries;
	return 1;
}

int wordJumble::zero_tries()
{
	tries = 0;
	return 1;
}

int wordJumble::reset_round()
{
	round = 1;
	return 1;

}

int wordJumble::adjust_turn_round()
{
	yourTurn = yourTurn->next;
	
	if(yourTurn == rear->next)	
		++round;
	return 1;
}

int wordJumble::rounds_left()
{
	if(round > 3)
		return 0;

	return 1;
}



int wordJumble::clear()
{
	int j = 0;

	for(j=0; j<100; ++j)
		cout << endl;
	return 1;
}

