#pragma once
#include <iostream>
using namespace std;
class Integer
{
public:
	Integer(int i) : i_(i) {}
	Integer(const Integer& value) : i_(value.i_) {}

	//unary + and - (takes no arguments i.e, we can write -Integer and get the negative of the Integer value. 
	Integer operator-();
	Integer operator+();

	//increment / decrement operators
	Integer& operator++(); //why return reference?
	Integer& operator--();
	Integer operator++(int); //postfix
	Integer operator--(int); //postfix

	//arithmetic operators //why make these non-members? //To follow assignment?
	friend Integer operator+(const Integer& a, const Integer& b);
	friend Integer operator-(const Integer& a, const Integer& b);
	friend Integer operator*(const Integer& a, const Integer& b);
	friend Integer operator/(const Integer& a, const Integer& b);
	friend Integer operator%(const Integer& a, const Integer& b);


	//stream operators
	friend ostream& operator<<(ostream& os, const Integer& i);
	friend istream& operator >> (istream& is, Integer& i);


private:
	int i_;
};

