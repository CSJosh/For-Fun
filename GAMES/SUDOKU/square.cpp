

#include "square.h"



square::square()
{
	int j = 0;

	number = 0;
	
	choices = new int[9];

	for(j = 0; j < 9; ++j)
		choices[j] = j+1;

}

square::square(int toCopy)
{
	int j = 0;
	number = toCopy;

	choices = new int[9];

	for(j = 0; j < 9; ++j)
		choices[j] = j+1;
}

square::square(const square & toCopy)
{
	int j = 0;
	number = toCopy.number;

	choices = new int[9];

	for(j = 0; j < 9; ++j)
		choices[j] = toCopy.choices[j];
}

square::~square()
{
	number = 0;
	
	delete []choices;
	choices = NULL;
}
	

void square::display() const
{
	cout << number;
}


bool square::compare(const square & toCompare) const
{
	return (number == toCompare.number);
}


void square::copy(const square & toCopy)
{
	int j = 0;
	number = toCopy.number;

	for(j = 0; j < 9; ++j)
		choices[j] = toCopy.choices[j];
}

void square::copy(int toCopy)
{
	int j = 0;
	number = toCopy;

	for(j = 0; j < 9; ++j)
		choices[j] = (j+1);
}


ostream & operator << (ostream & output, const square & toShow)
{
	toShow.display();
	
	return output;
}


bool square::operator == (const square & toCompare) const
{
	return compare(toCompare);
}



bool square::operator != (const square & toCompare) const
{
	return !(compare(toCompare));
}


square & square::operator = (const square & toCopy)
{
	if(this == &toCopy)
		return *this;

	copy(toCopy);

	return *this;
}


square & square::operator = (int toCopy)
{
	copy(toCopy);
	
	return *this;
}


int square::remove_choice(int toRemove)
{
	int j = 0;

	for(j = 0; j < 9; ++j)
	{
		if(choices[j] == toRemove)
		{
			choices[j] = 0;
			return toRemove;
		}
	}
	return 0;
}


int square::choice_count()
{
	int j = 0;
	int count = 0;

	for(j = 0; j < 9; ++j)
	{
		if(choices[j] != 0)
			++count;
	}

	return count;
}


int * & square::get_choices()
{
	return choices;
}


int square::get_number()
{
	return number;
}



void square::display_choices() const
{
	int j = 0;

	for(j = 0; j < 9; ++j)
	{
		if(choices[j] != 0)
			cout << choices[j] << " ";
	}
}


void square::clear_choices()
{
	int j = 0;

	for(j = 0; j < 9; ++j)
		choices[j] = 0;
}	


int square::get_remaining()
{
	int j = 0;
	int toReturn = 0;
	int count = 0;

	for(j = 0; j < 9; ++j)
	{
		if(choices[j] !=0){
			toReturn = j;
			++count;
		}

		if(count > 1)
			return 0;
	}
	
	return choices[toReturn];
}








	
