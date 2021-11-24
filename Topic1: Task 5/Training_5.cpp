// var 10
//friend-метод. Найти произведение элементов в тех столбцах и строках, которые не содержат отрицательных элементов
#include <iostream>
#include <ctype.h>
#include "Dvector.h"
using namespace std;

int main()
{
	Dvector dv1(3, 6); //(row, column)
	dv1.fillWithNumbers();
	dv1.show();
	cout << "~~~~~~~~~~~~~~~~~~~~ROWS~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	multiplyPositiveElemRow(dv1);
	cout << "~~~~~~~~~~~~~~~~~~~~COLUMNS~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	multiplyPositiveElemColumn(dv1);
	return 0;
}
