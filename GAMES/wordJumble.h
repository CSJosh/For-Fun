



struct player
{
	char * name;
	int score;
	player * next;
};


class wordJumble
{
	public:

		wordJumble();//constructor
		~wordJumble();//deconstructor
		int name_prompt();//prompts user for name, and saves to private member
		int display_rules();//displays game rules
		int wordPrompt();//prompts player for secret word
		int player_guess_prompt();//prompts player for guess
		int scramble();//jumbles up secret word
		int check_match();//checks if guess matches secret word
		int again();//play again function
		int display_word();//display secret word
		int display_jumble();//display jumbled word
		int display_scores();//display scores
		int display_round();
		int tries_left();//returns true if there are tries remaining
		int rounds_left();//returns true if there are rounds remaining
		int add_score_good_guess();//increments score if correct guess
		int add_score_no_guess();//increments score if could not guess word
		int reset_tries();//resets tries to 3
		int adjust_turn_round();//increments turn and round
		int minus_tries();
		int zero_tries();
		int reset_round();
		int clear();
		//int game_manage(int round, int guesses);
	private:
		player * rear;
		player * yourTurn;
		char * player_guess;
		char * secretWord;
		char * jumble;
		char * temp_array;
		int tries;
		int round;
		
};



class round_manager
{
	public:
		


	private:
		int roundNum;
		int guessNum;
};
