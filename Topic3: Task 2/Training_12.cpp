#include<iostream>
#include<exception>
#include<string>
#include<fstream>
#include<limits>
using namespace std;


struct MyStruct
	{
		unsigned int BDay;
		unsigned int BMonth;
		unsigned int BYear;
		string FIO;
		string gender;
	};

bool myis_empty(MyStruct& mas) //проверка на пустоту
{
	if (mas.BYear == 0)
	{
		return true;
	}
}

int main()
{
	MyStruct mas[10] = {}; //инициализация "0" для будущей проверки
	int number;
	int n = 0;

	while (true)// бесконечное меню
	{
		cout << "\n-------------------------------------------------------------------------" << endl;
		cout << "1-Download files from the file" << endl;
		cout << "2-Displaying data on the screen" << endl;
		cout << "3-Sort alphabetically(by last name)" << endl;
		cout << "4-Output: a list of people born in a given month" << endl;
		cout << "5-Output: last name of the oldest man" << endl;
		cout << "6-Output: all surnames starting with a given letter" << endl;
		cout << "0-EXIT" << endl;
		cout << "Enter number of menu: ";
		cin >> number;

		int countPerson = 0;
		int bufAge, bufMonth, bufDay;
		string bufName;
		string firstLetter;

		ifstream myin("D:\\prog.txt");
		switch (number)
		{
		case 1:

			if (myin.is_open())
			{
				while (!myin.eof())
				{
					getline(myin, mas[n].FIO, ';');
					myin >> mas[n].BDay;
					myin >> mas[n].BMonth;
					myin >> mas[n].BYear;
					myin >> mas[n].gender;
					n++;
				}
			}
			myin.close();
			break;
		case 2:
			if (myis_empty(mas[0]) == true)
			{
				cout << "ERROR: empty struct\nAt first fill the struct" << endl;
			}
			else
			{
				for (int i = 0; i < n; i++)
				{
					cout << mas[i].FIO << " " << mas[i].BDay << " " << mas[i].BMonth << " " << mas[i].BYear << " " << mas[i].gender << endl;
				}
			}

			break;
		case 3:
			if (myis_empty(mas[0]) == true)
			{
				cout << "ERROR: empty struct\nAt first fill the struct" << endl;
			}
			else
			{
				for (int i = 0; i < n; ++i)
				{
					for (int j = 0; j < n - 1; j++)
					{
						if (mas[j].FIO > mas[j + 1].FIO)
						{
							string buf;
							buf = mas[j].FIO;
							mas[j].FIO = mas[j + 1].FIO;
							mas[j + 1].FIO = buf;
						}
					}
				}	
			}

			break;
		case 4:
			if (myis_empty(mas[0]) == true)
			{
				cout << "ERROR: empty struct\nAt first fill the struct" << endl;
			}
			else
			{
				cout << "Enter number of month: ";
				int numMonth;

				cin >> numMonth;
				for (int i = 0; i < n; i++)
				{
					if (numMonth == mas[i].BMonth)
					{
						cout << mas[i].FIO << " " << mas[i].BDay << " " << mas[i].BMonth << " " << mas[i].BYear << " " << mas[i].gender << endl;
						countPerson++;
					}
				}

				if (countPerson == 0)
				{
					cout << "NOBODY HERE!" << endl;
				}
				else
				{
					cout << "Number of persons: " << countPerson << endl;
				}
			}

			break;
		case 5:
			if (myis_empty(mas[0]) == true)
			{
				cout << "ERROR: empty struct\nAt first fill the struct" << endl;
			}
			else
			{
				bufAge = numeric_limits<int>::max();
				bufMonth = numeric_limits<int>::max();
				bufDay = numeric_limits<int>::max();
				for (int i = 0; i < n; i++)
				{
					if (mas[i].BYear < bufAge)
					{
						bufName = mas[i].FIO;
						bufAge = mas[i].BYear;
						bufMonth = mas[i].BMonth;
						bufDay = mas[i].BDay;
					}
					else if (mas[i].BYear == bufAge && mas[i].BMonth < bufMonth)
					{
						bufName = mas[i].FIO;
						bufAge = mas[i].BYear;
						bufMonth = mas[i].BMonth;
						bufDay = mas[i].BDay;
					}
					else if (mas[i].BMonth == bufMonth && mas[i].BDay < bufDay)
					{
						bufName = mas[i].FIO;
						bufAge = mas[i].BYear;
						bufMonth = mas[i].BMonth;
						bufDay = mas[i].BDay;
					}
				}
				cout << "Oldest men in the world: " << bufName << " " << bufAge << endl;
			}

			break;
		case 6:
			if (myis_empty(mas[0]) == true)
			{
				cout << "ERROR: empty struct\nAt first fill the struct" << endl;
			}
			else
			{
				cout << "Enter the letter: ";
				cin >> firstLetter;

				for (int i = 0; i < n; i++)
				{
					bufName = mas[i].FIO[1];
					if (firstLetter == bufName)
					{
						cout << mas[i].FIO << " " << endl;
						countPerson++;
					}
				}

				if (countPerson == 0)
				{
					cout << "NOBODY HERE!" << endl;
				}
				else
				{
					cout << "Number of persons: " << countPerson << endl;
				}
			}

			break;
		case 0:
			return false;
		default:
			break;
		}
	}
}
