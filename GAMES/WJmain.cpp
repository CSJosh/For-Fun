

#include "wordJumble.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>


using namespace std;


const int SIZE = 101;



int main()
{
	wordJumble game;
	
	char array[SIZE];
	char * name;
	int * index;
	int length = 0;
	int j = 0;
	int k = 0;
	int round = 0;
	int guesses = 0;

	game.name_prompt();
	game.display_rules();
	
	do
	{
		do
		{
			game.display_round();
			game.wordPrompt();
			game.scramble();
			game.clear();
			
			do
			{
				game.display_jumble();
				game.player_guess_prompt();
			
				if(game.check_match())
				{
					cout << "\n\t\tGOOD GUESS!!!" << endl;
					game.add_score_good_guess();
					game.zero_tries();
					++j;
				}
				
				else if(j <= 0)
					game.minus_tries();

				if(!game.tries_left() && j <= 0)
					game.add_score_no_guess();

			}while(game.tries_left());

			j = 0;
			game.reset_tries();
			game.adjust_turn_round();
			game.display_scores();
			game.display_word();
			
		}while(game.rounds_left());

		game.reset_round();	
	
	}while(game.again());

	return 0;
}
