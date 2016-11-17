

class piece
{
	public:
		piece(char color_to_set);
		~piece();
		virtual void display() = 0;
	
	protected:
		char color;
};


class pawn : public piece
{
	pawn(char color_to_set, char * type_to_set): piece(color_to_set)
	~pawn();
	void display();

	protected:
		char * type;
};


