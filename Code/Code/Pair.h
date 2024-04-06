#pragma once

#include <iostream>

using namespace std;

class Pair
{
private:
	int First;
	double Second;

public:

	Pair(){}

	Pair(int first, double second)
	{
		setFirst(first);
		setSecond(second);
	}

	void setFirst(int first) { First = first; }

	void setSecond(double second) { Second = second; }

	int getFirst() { return First; }

	double getSecond() { return Second; }

	Pair& operator -= (Pair& anotherPair)
	{
		First -= anotherPair.First;
		Second -= anotherPair.Second;

		return *this;
	}

	Pair& operator += (double variable)
	{
		int fullPart = variable;

		if (variable - fullPart == 0)
			First += variable;
		else
			Second += variable;

		return *this;
	}

	Pair& operator*=(Pair& anotherPair) 
	{
		First *= anotherPair.First;
		Second *= Second;

		return *this;
	}

	friend istream& operator>>(istream& stream, Pair& pair);

	friend ostream& operator<<(ostream& stream, Pair& pair);
};

istream& operator>>(istream& stream, Pair& pair)
{
	cout << endl <<"Число один?"; stream >> pair.First;
	cout << "Число два?"; stream >> pair.Second;

	return stream;
}

ostream& operator<<(ostream& stream, Pair& pair)
{
	return { stream << pair.First << ":" << pair.Second };
}

