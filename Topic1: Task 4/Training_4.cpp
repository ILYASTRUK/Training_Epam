// var 19
//Пиломатериалы
//Стоимость кубометра
#include <iostream>
#include <ctype.h>
#include "Lumber.h"
using namespace std;

int main()
{
	Oak oak1(3.1);
	oak1.setData(100, 30);
	oak1.show();

	Pine pine1(5.1);
	pine1.setData(100, 30);
	pine1.show();

	Birch birch1(1.14);
	birch1.setData(100, 30);
	birch1.show();

	return 0;
}
