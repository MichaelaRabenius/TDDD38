#pragma once
#include <string>
#include "Score_Variant.h"
class Pair : public Score_Variant
{
public:
	Pair();
	~Pair();

	std::string name() override
	{
		return std::string{ "Pair" };
	}

	int score(std::vector<int>& v) override
	{
		return 0;
	}
};

