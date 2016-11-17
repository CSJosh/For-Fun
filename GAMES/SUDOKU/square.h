#include <iostream>

using namespace std;


class square
{
	public:
		square();
		square(int);
		square(const square &);
		~square();
		friend ostream & operator << (ostream &, const square &);
		bool operator == (const square &) const;
		bool operator != (const square &) const;
		square & operator = (const square &);
		square & operator = (int);
		int remove_choice(int);
		int choice_count();
		int * & get_choices();
		int get_number();
		int get_remaining();
		void clear_choices();
		void display_choices() const;
	private:
		int number;
		int * choices;		
		void display() const;
		bool compare(const square &) const;
		void copy(const square &);
		void copy(int);
};
