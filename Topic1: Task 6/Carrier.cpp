#include <iostream>
#include "Carrier.h"
using namespace std;

//----------------------------------абстракиця LVL1--------------------------



//----------------------------------абстракиця LVL2--------------------------
// 
//-------------------------Пассажирский-------------------
    Passenger::Passenger() {}
    Passenger::Passenger(int all, string  comp) : unit_all(all), company(comp) {}
    Passenger::~Passenger() {}

    void const Passenger::ShowData()
    {
        cout << "\n---------------------------Passenger-------------------------" << endl;
        cout << "Name of company: " << company << "\nNumber of units: " << unit_all << endl;
    }

    void const Passenger::GetData()
    {
        company = "TurboPig";
        unit_all = 33;
    }

//-------------------------Грузовой-------------------
    Cargo::Cargo() {}
    Cargo::Cargo(int all, string  comp) : unit_all(all), company(comp) {}
    Cargo::~Cargo() {}

     void const Cargo::ShowData()
     {
         cout << "\n------------------------Cargo----------------------------" << endl;
         cout << "Name of company: " << company << "\nNumber of units: " << unit_all << endl;
     }

     void const Cargo::GetData()
     {
         company = "BIG CARGO LTD";
         unit_all = 735;
     }


//----------------------------------абстракиця LVL3 --------------------------
// 
//-------------------------Пассажирский-------------------

//----Автобус
     Bus::Bus() {}
     Bus::Bus(int bus, int all_p) : bus(bus), all_pass(all_p) {}
     Bus::~Bus() {}

     void const Bus::GetPassData()
     {
         all_pass = 3;
         bus = 23;
     }

     void const Bus::ShowPassData()
     {
         Passenger::ShowData();
         cout << "\nBus" << endl;
         cout << "Number of buses: " << bus << "\nNumber of passengers per day: " << all_pass << endl;

     }


     void Bus::AveragePass()
     {
         cout << "Average passenger per bus: " << static_cast<float>(all_pass) / bus << endl;
     }



//----Самолет

     Airplane::Airplane() {}
     Airplane::Airplane(int air, int all_p) : air(air), all_pass(all_p) {}
     Airplane::~Airplane() {}

    void const Airplane::GetPassData()
    {
        all_pass = 1;
        air = 13;
    }

    void const Airplane::ShowPassData()
    {
        Passenger::ShowData();
        cout << "\nAirplan: " << endl;
        cout << "Number of airplans: " << air << "\nNumber of passengers per day: " << all_pass << endl;
    }
    
    void Airplane::AveragePass()
    {
        cout << "Average passenger per air: " << static_cast<float>(all_pass) / air << endl;
    }


//-------------------------Грузовой-------------------

//----Поезд
    Train::Train() {}
    Train::Train(int train, int all_c) : train(train), all_cargo(all_c) {}
    Train::~Train() {}

    void const Train::GetCargoData()
    {
        train = 135;
        all_cargo = 1;
    }

    void const Train::ShowCargoData()
    {
        Cargo::ShowData();
        cout << "\nTrain: " << endl;
        cout << "Number of trains: " << train << "\nNumber of cargo(ton) per day: " << all_cargo << endl;
    }

    void Train::TotalCost()
    {
        cout << "Total cost: " << train * all_cargo << endl;
    }



//----Машина
    Car::Car() {}
    Car::Car(int car, int all_c) : car(car), all_cargo(all_c) {}
    Car::~Car() {}

    void const Car::GetCargoData()
    {
        car = 600;
        all_cargo = 1;
    }

    void const Car::ShowCargoData()
    {
        Cargo::ShowData();
        cout << "\nCar: " << endl;
        cout << "Number of trains: " << car << "\nNumber of cargo(ton) per day: " << all_cargo << endl;
    }

    void Car::TotalCost()
    {
        cout << "Total cost: " << car * all_cargo << endl;
    }
