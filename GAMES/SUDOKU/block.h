
#include <iostream>
#include <fstream>
#include "square.h"

using namespace std;


class block
{
	public:
		block();
		block(int);
		~block();
		void save(const char *, fstream &);
		bool match_check(int, int, int);
		void display() const;
	//	void display_easy() const;
	//	void display_med() const;
	//	void display_hard() const;
		void make_puzzle_easy();
		void make_puzzle_medium();
		void make_puzzle_hard();
		void print_puzzles_easy(int);
		void print_puzzles_medium(int);
		void print_puzzles_hard(int);
		void show() const;
		bool solve();
		void set_choices();
		void display_choices() const;
		friend ostream & operator << (ostream &, const block &);
		block & operator = (const block &);
		void remove_all(); 
		//bool operator == (const block &) const;
		//bool operator != (const block &) const;
	private:
		void set_row_choices(int row, int col);
		void set_column_choices(int row, int col);
		void set_block_choices(int row, int col);
		void copy(const block &);
		int blank_count();
		int block_blank_count(int, int);
		void resetNumList();
		int getNumber();
		square ** numSet;
		int * numList;
};
