#pragma once
#include "Score_Variant.h"
class Counted_Dice : public Score_Variant
{
public:
	Counted_Dice(Counted_Dice&) = delete;
	Counted_Dice(Counted_Dice&&) = delete;
	Counted_Dice(int i); //Constructor taking an int
	~Counted_Dice();

	int get_number() const { return dice; }

private:
	int dice;
};

