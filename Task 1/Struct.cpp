#include "Training_1.h"
#include <iostream>
using namespace std;

struct student
{
	string name;
	string secondname;
	int scores[3];
};

void const show(student* st, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nName of student: " << st[i].name << endl;

		cout << "Secondname of student: " << st[i].secondname << endl;

		cout << "Scores of student: ";

		for (int j = 0; j <= 2; j++)
		{
			cout << st[i].scores[j] << " ";
		}
		cout << endl;
	}
}

void const sortDescending(student* st, int n)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (st[i].scores[j] < st[i].scores[j + 1])
				{
					temp = st[i].scores[j + 1];
					st[i].scores[j + 1] = st[i].scores[j];
					st[i].scores[j] = temp;
				}
			}
		}
	}
}

int const getBiggest(student* st, int n)
{
	int max = 0;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			if (st[i].scores[j] > max)
			{
				max = st[i].scores[j];
			}
		}
		break;
	}
	return max;
}

void const sortStruct(student* st, int n)
{
	student* temp = new student[n];
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (getBiggest(&st[j], n) < getBiggest(&st[j + 1], n))
			{
				temp[j] = st[j];
				st[j] = st[j + 1];
				st[j + 1] = temp[j];
			}
		}
	}
	delete[] temp;
}