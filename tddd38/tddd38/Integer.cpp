#include "Integer.h"

Integer Integer::operator-()
{
	return Integer(-i_); //Do we create a new Integer initializing it with -i_?
}

Integer Integer::operator+()
{
	return Integer(i_); //Why this? What is returned? //TYPE CONVERTING CONSTRUCTOR
}

Integer & Integer::operator++()
{
	++i_;
	return *this;
}

Integer & Integer::operator--()
{
	--i_;
	return *this;
}

Integer Integer::operator++(int)
{
	int i = i_;
	++i_;
	return Integer(i);
}

Integer Integer::operator--(int)
{
	int i = i_;
	--i_;
	return Integer(i);
}

Integer operator+(const Integer & a, const Integer & b)
{
	return Integer(a.i_ + b.i_);
}

Integer operator-(const Integer & a, const Integer & b)
{
	return Integer(a.i_ - b.i_);
}

Integer operator*(const Integer & a, const Integer & b)
{
	return Integer(a.i_ * b.i_);
}

Integer operator/(const Integer & a, const Integer & b)
{
	return Integer(a.i_ / b.i_);
}

Integer operator%(const Integer & a, const Integer & b)
{
	return Integer(a.i_ % b.i_);
}

ostream & operator<<(ostream & os, const Integer & i)
{
	os << i.i_;
	return os;
}

istream & operator >> (istream & is, Integer & i)
{
	is >> i.i_;
	return is;
}
