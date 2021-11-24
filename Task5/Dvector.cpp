#include <iostream>
#include "Dvector.h"
#include <iomanip>
#include <random>
using namespace std;

Dvector::Dvector() : mas{ new int* [0] }, cols(0) {}

Dvector::Dvector(int rows, int cols) : rows(rows), cols(cols), mas{new int* [rows]}
{
    for (int i = 0; i < rows; i++)
    {
        mas[i] = new int[cols];
    }
}

Dvector::~Dvector()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] mas[i];
    }
    delete[] mas;
}

void const Dvector::fillWithNumbers()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            mas[i][j] = 1;
            random_device rseed;
            mt19937 rng(rseed());
            uniform_int_distribution<int> dist(-1, 8);
            mas[i][j] = dist(rng);
        }
    }
}

void const Dvector::show()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(4) << mas[i][j] << "   ";
        }
        cout << endl;
    }
}

void const multiplyPositiveElemRow(Dvector& test)
{     
    for (int i = 0; i < test.rows; i++)
    {
        int result = 1;
        int key = 0;
        for (int j = 0; j < test.cols; j++)
        {
            if (test.mas[i][j] <= 0)
            {
                cout << "can't decide row " << setw(7) << "[" << i+1 << "]" << endl;
                break;
            }
            key++;

        }        
        if (key == test.cols)
        {
            for (int j = 0; j < test.cols; j++)
            {
                result *= test.mas[i][j];
            }
            cout << "Multiplication result " << setw(2) << "[" << i+1 << "] : " << result << endl;
        }
    }
}

void const multiplyPositiveElemColumn(Dvector& test)
{
    int j = 0;
    for (int i = 0; i < test.cols; i++)
    {
        int result = 1;
        int key = 0;
        for (int i = 0; i < test.rows; i++)
        {
            if (test.mas[i][j] <= 0)
            {
                cout << "can't decide column " << setw(4) << "[" << j+1 << "]" << endl;
                break;
            }
            key++;
        }        
        
        if (key == test.rows)
        {
            for (int i = 0; i < test.rows; i++)
            {
                result *= test.mas[i][j];
            }
            cout << "Multiplication result " << setw(2) << "[" << j+1 << "] : " << result << endl;
        }
        j++;
    }
}
