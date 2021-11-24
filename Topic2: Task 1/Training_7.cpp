#include <iostream>
#include<array>
#include<vector>
#include<algorithm>
using namespace std;
//Задание 1
//Создать лямбда - выражение для вывода элементов вектора.
//Создать лямбда - выражение для подсчета количества перестановок при выполнении сортировки элементов вектора
//Создать лямбда - выражение для поиска вхождения подстроки, задаваемой пользователем, в строку.
//Задание 2
//Выполнить генерацию вектора из Nпоследовательных элементов(например, 0 1 2 3 4)
//Сформировать новый вектор по следующему правилу : отбросить слева kпервых элементов и добавитьk последовательных элементов в конец вектора(например, k = 2, новый вектор 2 3 4 5 6)

int main()
{
    vector<int> v1;
    vector<int> v2{ 1, 2, 13, 4, 5, 7, 12, 61, 66 };

    v1.insert(v1.begin(), v2.begin() + v2.size() / 2, v2.end());

    //--------------------1.1----------

    for_each(v1.begin(), v1.end(), [](int i)
        {
            cout << i << " ";
        });
    cout << endl;

    //--------------------1.2----------

    int iter = 0;
    sort(v2.begin(), v2.end(), [&iter](int a, int b)
        {
            if (a < b)
            {
                iter++;
            }
            return a < b;
        });

    cout << "\niter: " << iter << endl;

    cout << "After sort: ";
    for (const int& el : v2)
    {
        cout << el << " ";
    }
    //-----------------------------1.3-------------------------------------

    array<string, 3> str{ "test t", "qwerty","testt" };
    string input;

    cout << "\nEnter the string: ";
    cin >> input;

    auto search{find_if(str.begin(), str.end(),
        [input](string s)
        {
            return (s.find(input) != string::npos);
        })};

    if (search == str.end())
    {
        cout << "no" << endl;
    }
    else
    {
        cout << "yes: " << *search << endl;
    }

    //--------------------------2.1----------------------------------------

    vector<int> v3;

    auto task1{ [&v3](int n, int start)
    {
            for (int i = 0; i < n; i++)
            {
                v3.push_back(start);
                start++;
            }

            for (const int& el : v3)
            {
                cout << el << " ";
            }
    } };

    task1(11, 2);
    cout << endl;

    //--------------------------2.2----------------------------------------

    auto task2{ [v2](int k) mutable
        {
            int iter = 1;
            v2.erase(v2.begin(), v2.begin() + k);
            for (int i = 0; i < k; i++)
            {
                v2.push_back(*(v2.end() - 1) + iter);
            }

            for (const int& el : v2)
            {
                cout << el << " ";
            }
    } };

    task2(5);    
}
