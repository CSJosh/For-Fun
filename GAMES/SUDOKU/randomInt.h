

class randomInt
{
	public:
		randomInt();
		randomInt(int);
		~randomInt();
		bool isEmpty();
		void resetNum();
		int getRandNum();
	private:
		int * numList;
		int listSize;
		int * indexList;
		int currentIndex;
};
