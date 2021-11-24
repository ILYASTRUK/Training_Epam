#include <iostream>
#include "Vector.h"

using namespace std;

Vector::Vector() : size{ 0 }, mas{ new double[0] }
{}
Vector::Vector(unsigned int s) : size(s), mas{ new double[s] }
{
    cout << "Fill the massive with numbers!" << endl;
    double tmp;
    for (int i = 0; i < size; i++)
    {
        cout << "number[" << i << "]: ";
        cin >> tmp;
        mas[i] = tmp;
    }
}
Vector::Vector(unsigned int s, double firstElem) : size(s), mas{ new double[s] }
{
    for (int i = 0; i < size; i++, firstElem -= 2.07)
    {
        mas[i] = firstElem;
    }
}
Vector::~Vector()
{
    delete[] mas;
}

void const Vector::showData()
{
    cout << "\nVector: ";
    for (int i = 0; i < size; i++)
    {
        cout << mas[i] << " | ";
    }
    cout << endl;
}

void const Vector::srtAscending()
{
    double buff = 0.0;
    for (int i = 1; i < size; i++)
    {
        buff = mas[i];
        int j = i;
        while (j > 0 && mas[j - 1] > buff)
        {
            mas[j] = mas[j - 1];
            --j;
        }
        mas[j] = buff;
    }
}

void const Vector::findMin()
{
    double tmp = numeric_limits<double>::max();
    for (int i = 0; i < size; i++)
    {
        if (tmp > mas[i])
        {
            tmp = mas[i];
        }
    }
    cout << "Min: " << tmp << endl;
}

int const Vector::findMax()
{
    int index = 0;
    double tmp = numeric_limits<double>::lowest();
    for (int i = 0; i < size; i++)
    {
        if (tmp < mas[i])
        {
            tmp = mas[i];
            index = i;
        }
    }
    cout << "Max: " << tmp << endl;
    cout << "index: " << index << endl;
    return index;
}

void const Vector::findAverage()
{
    double summ = 0;
    for (int i = 0; i < size; i++)
    {
        summ += mas[i];
    }
    cout << "Average: " << summ / (size + 1.0) << endl;
}

void const Vector::findSummAfterMaxNumber()
{
    double summ = 0;
    for (int i = findMax() + 1; i < size; i++)
    {
        summ += mas[i];
    }
    cout << "SummAfterMaxNumber: " << summ << endl;
}
