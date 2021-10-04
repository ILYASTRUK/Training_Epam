// var 5
//Динамический массив
//Найти сумму после максимального числа
#include <iostream>
#include <ctype.h>
#include <limits>
#include "Vector.h"
using namespace std;

int main()
{
    Vector v1(5);
    v1.showData();

    Vector v2(10, 31.11);
    v2.showData();
    v2.findSummAfterMaxNumber();
    v2.srtAscending();
    cout << "\n                                             SORTED!";
    v2.showData();
    v2.findMin();
    v2.findMax();
    v2.findAverage();

    return 0;
}
