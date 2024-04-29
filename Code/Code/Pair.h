#pragma once

#include <iostream>

using namespace std;

class Pair //Класс пары
{
private:

	//Первое и второе числа
	int First;
	double Second;

public:

	//Конструкторы
	Pair(){}
	Pair(int first, double second)
	{
		setFirst(first);
		setSecond(second);
	}

	//Сеттеры и геттеры
	void setFirst(int first) { First = first; }
	void setSecond(double second) { Second = second; }
	int getFirst() { return First; }
	double getSecond() { return Second; }

	Pair& operator -= (Pair& anotherPair) //Оператор вычитания пары и пары
	{
		First -= anotherPair.First;
		Second -= anotherPair.Second;

		return *this;
	}

	Pair& operator += (double variable) //Оператор добавления константы к паре
	{
		int fullPart = variable;

		if (variable - fullPart == 0)
			First += variable;
		else
			Second += variable;

		return *this;
	}

	Pair& operator*=(Pair& anotherPair) //Оператор умножения пары на пару 
	{
		First *= anotherPair.First;
		Second *= Second;

		return *this;
	}

	//Операторы потокового ввода - вывода
	friend istream& operator>>(istream& stream, Pair& pair);
	friend ostream& operator<<(ostream& stream, Pair& pair);
};

istream& operator>>(istream& stream, Pair& pair) //Оператор ввода
{
	cout << endl <<"Число один?"; stream >> pair.First;
	cout << "Число два?"; stream >> pair.Second;

	return stream;
}

ostream& operator<<(ostream& stream, Pair& pair) //Оператор вывода
{
	return { stream << pair.First << ":" << pair.Second };
}

