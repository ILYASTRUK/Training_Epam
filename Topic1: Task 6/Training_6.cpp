#include <iostream>
#include "Carrier.h"
using namespace std;
//Вариант 2-Транспорт
//Задание на абстракцию и вирутальные функции. Реализовать 3-уровневую иерархию классов.

int main()
{
    Bus bus;
    bus.GetData();
    bus.GetPassData();
    bus.ShowPassData();
    bus.AveragePass();

    Airplane air;
    air.GetData();
    air.GetPassData();
    air.ShowPassData();
    air.AveragePass();

    Train train;
    train.GetData();
    train.GetCargoData();
    train.ShowCargoData();
    train.TotalCost();

    Car car;
    car.GetData();
    car.GetCargoData();
    car.ShowCargoData();
    car.TotalCost();
}
