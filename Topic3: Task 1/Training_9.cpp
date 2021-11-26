#include <iostream>
#include <algorithm>
#include<random>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

// Задача о рюкзаке
//Задача состоит в том, чтобы выбрать, какие предметы, имеющие вес и стоимость, поместить в рюкзак ограниченной ёмкости W.
//Мы можем определить соотношение стоимости предмета к его весу, а затем сортировать их по этим критериям. В задаче с дробным рюкзаком нам разрешено брать дробные части предмета.


struct Item {
    int value;
    int weight;
    string str;
};

bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double Fill_Backpack(int sizeBag, struct Item arr[], int n)
{
    sort(arr, arr + n, cmp);
    int cur_weight = 0; int tot_value = 0; //double tot_value = 0.0 для дробной части
    for (int i = 0; i < n; ++i)
    {
        if (cur_weight + arr[i].weight <= sizeBag)
        {
            cur_weight += arr[i].weight;
            tot_value += arr[i].value;
            cout << arr[i].str << " ";
        }
        //else
        //{   // Добавляем часть следующего предмета
        //    int rem_weight = W - cur_weight;
        //    tot_value += arr[i].value *
        //        ((double)rem_weight / arr[i].weight);
        //      cout << "Part of: "arr[i].str << " ";
        //    break;
        //}
    }
    return tot_value;
}
int main()
{
    random_device rd;
    mt19937 mlg(rd());
    uniform_int_distribution<int> weight(10, 30);
    uniform_int_distribution<int> price(300, 1200);
    uniform_int_distribution<int> max(20, 80);

    int sizeBag = max(mlg); // вместительность рюкзака
    Item arr[5]; // {стоимость, вес}

    ifstream myin("Obj.txt");
    if (!myin.is_open())
    {
        cout << "ne otkril";
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            arr[i].value = price(mlg);
            arr[i].weight = weight(mlg);
            myin >> arr[i].str;
        }
    }
    myin.close();
    cout << "Backpack size: " << sizeBag << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << setw(8) << arr[i].str << " ";
        cout << setw(8) <<"Value: " << arr[i].value << " ";
        cout << setw(8) << "Weight: " << arr[i].weight << endl;
    }

    int n = sizeof(arr) / sizeof(arr[0]); //количество элементов массива
    cout << "---------------------------------------------------------" << endl;
    cout << "MAX VALUE: " << Fill_Backpack(sizeBag, arr, n) << endl;
    return 0;
}
