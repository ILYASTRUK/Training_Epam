//struk 5 - нечетное
//отсортировать студентов по убыванию (по наибольшему баллу)
#include <iostream>
#include <ctype.h>
#include <conio.h>
#include "Training_1.h"
#include <cstring>
using namespace std;

struct student
{
	string name;
	string secondname;
	int scores[3];
};

int main()
{
	int n;
	do {
		cout << "Enter the number of students 5 or more: ";
		cin >> n;
	} while (n < 5);

	student* st = new student[n];

	for (int i = 0; i < n; i++)
	{
		cout << "\nEnter the Name of student: ";
		cin >> st[i].name;

		cout << "Enter the Secondname of student: ";
		cin >> st[i].secondname;

		cout << "Enter the Score of student: ";

		for (int j = 0; j <= 2; j++)
		{
			cin >> st[i].scores[j];
		}
	}
	student** q = new student * [n];
	for (int i = 0; i < n; i++)
	{
		q[i] = &st[i];
	}

	show(st, n);
	cout << "\n_______sortDescending________ ";
	sortDescending(st, n);
	show(st, n);
	cout << "\n_______getBiggest________ ";
	sortStruct(st, n);
	show(st, n);

	delete[] st;
	return 0;
}
