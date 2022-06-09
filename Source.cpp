#include "header.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int arr[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	LIST list(arr, 12);

	list.PRINTLIST();

	list.MAKENULL();

	for (int i = 1; i <= 10; i++)
	{
		list.push_back(i);
	}

	cout << list.FIRST() << endl;
	cout << list.END() << endl;

	list.pop_back();
	list.pop_front();

	cout << list.FIRST() << endl;
	cout << list.END() << endl;

	list.INSERT(3, 2);

	cout << "[" << list.LOCATE(3) << "]" << list.RETRIVE(list.LOCATE(3)) << endl;

	list.PRINTLIST();
}
