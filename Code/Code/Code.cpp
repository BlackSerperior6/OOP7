#include "List.h"

int main()
{
	system("chcp 1251");

	cout << endl;

	//Четыре спписка разных типов
	List<int> IntegerList;
	List<float> FloatList;
	List<double> DoubleList;
	List<Pair> PairList;

	//Ввод данных во все списки
	cout << "Ввод в список int:" << endl;

	cin >> IntegerList;

	cout << endl << "Ввод в список float:" << endl;

	cin >> FloatList;

	cout << endl << "Ввод в список double:" << endl;

	cin >> DoubleList;

	cout << endl << "Ввод в список Pair:" << endl;

	cin >> PairList;

	//Вывод всех списков
	cout << endl <<"Список int: " << IntegerList << endl;
	cout << "Список float: " << FloatList << endl;
	cout << "Список double: " << DoubleList << endl;
	cout << "Список Pair: " << PairList << endl;

	cout << endl  << "Возводим все списки в квадрат: " << endl;

	//Возведение всех списков в квадрат
	IntegerList *= IntegerList;
	FloatList *= FloatList;
	DoubleList *= DoubleList;
	PairList *= PairList;

	//Вывод всех списков
	cout << "Список int: " << IntegerList << endl;
	cout << "Список float: " << FloatList << endl;
	cout << "Список double: " << DoubleList << endl;
	cout << "Список Pair: " << PairList << endl;
}