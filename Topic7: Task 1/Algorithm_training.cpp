#include <iostream>
#include<vector>
#include<random>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

//список рассылки не больше 500
//количество проходов по базе sort
//определить всех наиболее частых покупателей для создания списка рассылки для оправки рекламных материалов по почте.

struct database
{
	double Price;
	unsigned int PurchaseCount;
	string Name;
	string Email;
};

void FillDatabase(vector<database>& _data)
{
	random_device rseed;
	mt19937	rng(rseed());
	uniform_real_distribution<double> rPrice(20000, 300000); //Для общей суммы rPrice(rng)
	uniform_int_distribution<int> rPurchase(1, 100); //количество покупок
	uniform_int_distribution<int> rClient(6, 9); //количество клиентов
	int n = rClient(rng);
	_data.resize(n);
	string num;

	for (int i = 0; i < n; ++i)
	{
		_data[i].Name = "Lewis Hamilton";
		num = to_string(i);
		_data[i].Name += " [" + num + "]";
		_data[i].Email = "Job@mail.com";
		_data[i].Email += " [" + num + "]";
		_data[i].PurchaseCount = rPurchase(rng);
		_data[i].Price = rPrice(rng);
	}
}

void ShowData(const vector<database>& _data)
{
	cout << setw(21) << "Client\t" << setw(18) << "E-mail\t" << setw(15) << "PurchaseCount\t" << setw(15) << "Price" << endl;

	for (unsigned int i = 0; i < _data.size(); ++i)
	{
		cout << setw(23) << _data[i].Name << "\t" << setw(21) << _data[i].Email << "\t" << setw(15) << _data[i].PurchaseCount << "\t" << setw(15) << setprecision(7) << _data[i].Price << endl;
	}
}

bool cmp(database a, database b) //компоратор для сорта
{
	return a.PurchaseCount > b.PurchaseCount;
}

void mysort(vector<database>& v) //обычный пузырек
{
	unsigned int PurchaseSort = 0;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i; j > 0 && v[j - 1].PurchaseCount < v[j].PurchaseCount; j--)
		{
			swap(v[j - 1], v[j]);
			++PurchaseSort;
		}
	}
	cout << "Count: " << PurchaseSort << endl;
}

void task1(vector<database>& _data) //нахождение наиболее частых покупателей
{
	//sort(_data.begin(), _data.end(), cmp);
	mysort(_data);
	//ShowData(_data);
	unsigned int FrequencyNumber;
	vector<string> FrequencyBuyers;
	cout << "\tEnter the purchase threshold: ";
	cin >> FrequencyNumber; //от скольки покупок покупатель становится частым
	string buf;

	for (unsigned int i = 0; i < _data.size(); i++)
	{
		if (_data[i].PurchaseCount >= FrequencyNumber)
		{
			FrequencyBuyers.push_back(_data[i].Name + "  " + _data[i].Email);
			cout << FrequencyBuyers[i] << endl;
		}
		else if (FrequencyBuyers.size() == 0)
		{
			cout << "There are no frequent buyers with such a threshold!!!" << endl;
			break;
		}

		if (FrequencyBuyers.size() == 500)
		{
			cout << "Reach the limit(500): " << FrequencyBuyers.size();
			break;
		}
	}

	ofstream myout; //запись в файл для последующей обработки
	myout.open("D:\\Most_frequent_buyers.txt");
	for (int i = 0; i < FrequencyBuyers.size(); i++)
	{
		myout << FrequencyBuyers[i] << endl;
	}
	myout.close();
}

int main()
{
	vector<database> database1;

	//----------------------------Task 1----------------------
	FillDatabase(database1);
	ShowData(database1);
	cout << "\n----------------------------Most frequent buyers--------------------" << endl;
	task1(database1);
}
