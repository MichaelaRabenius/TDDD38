#pragma once
#include <string>
class Score_Variant
{
public:
	Score_Variant();
	virtual ~Score_Variant();

	//
	virtual std::string name() = 0;
	virtual int score() {};
};

