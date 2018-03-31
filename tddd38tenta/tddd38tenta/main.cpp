#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Score_Variant
{
public:
	~Score_Variant() = default; //Destructor

	virtual string name() const = 0;
	virtual int score(std::vector<int>& v) const = 0;

protected:
	Score_Variant() = default; //Cosntructor
private:
	Score_Variant(Score_Variant const &) = delete;
	Score_Variant & operator=(Score_Variant const &) = delete;
};


class Counted_Dice : public Score_Variant
{
public:
	int score(std::vector<int>& v) const override
	{
		int found{};
		for (auto die : v) //Loop through all elements in vector v
		{
			if (die == value)
				++found;
		}
		return value*found;
	}
	int get_number() const { return value; };

	Counted_Dice(int val) : value{ val } {}
private:
	int value;
};

class Ones : public Counted_Dice
{
public:
	Ones() : Counted_Dice(1) {}; //Delegate to base class constructor

	string name() const override
	{
		return std::string{ "Ones" };
	}

	int score(std::vector<int>& v) const override
	{
		//Sum all 1s in vector v.
	}


};

class Twos : public Counted_Dice
{
public:
	Twos() : Counted_Dice(2) {} //Delegate to base class constructor

	string name() const override
	{
		return std::string{ "Twos" };
	}
};


class Pair : public Score_Variant
{
	string name() const override
	{
		return std::string{ "Pair" };
	}

	int score(std::vector<int>& v) const override
	{
		auto d = v;
		sort(begin(d), end(d), greater<int>{});
		auto it = adjacent_find(begin(d), end(d));
		if (it != end(d))
		{
			return (*it) * 2;
		}
		return 0;
	}
};

int main()
{// should really use some smart pointer, but fine without...
	const vector<Score_Variant*> score_variants{ new Ones, new Twos, new Pair };
	vector<int> dice{ 1,4,1,5,4 };
	for (auto && variant : score_variants)
	{
		auto points = variant->score(dice);
		if (points != 0)
		{
			cout << variant->name() << ": " << points;
			if (auto ptr = dynamic_cast<Counted_Dice*>(variant))
			{
				cout << " (" << points / ptr->get_number() << ")";
			}
			cout << endl;
		}
	}
	// deallocate pointers
	for (auto & variant : score_variants)
	{
		delete variant;
	}
}