
#include "block.h"
#include <fstream>




class game
{
	public:
		game();
		game(int);
		~game();
		void save(const char []);
		void load(char *);
		friend ostream & operator << (ostream &, const game &);

	private:
		void display() const;
		block * easy;
		block * medium;
		block * hard;
		int board_count;
};
	
