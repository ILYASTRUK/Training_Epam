#pragma once
using namespace std;

//----------------------------------абстракиця LVL1--------------------------
class Carrier
{
    virtual const void ShowData() = 0;
    virtual const void GetData() = 0;
};

//----------------------------------абстракиця LVL2--------------------------
class Passenger :public Carrier
{
protected:
    string company;
    int unit_all;
public:
    Passenger();
    Passenger(int all, string  comp);
    ~Passenger();

    void const ShowData() override;
    void const GetData() override;
    virtual const void GetPassData() = 0;
    virtual const void ShowPassData() = 0;
};

class Cargo :public Carrier
{
protected:
    string company;
    int unit_all;
public:
    Cargo();
    Cargo(int all, string  comp);
    ~Cargo();

    void const ShowData() override;
    void const GetData() override;
    virtual const void GetCargoData() = 0;
    virtual const void ShowCargoData() = 0;
};


//----------------------------------абстракиця LVL3--------------------------
class Bus :public Passenger
{
protected:
    int bus;
    int all_pass;
public:
    Bus();
    Bus(int bus, int all_p);
    ~Bus();

    virtual const void GetPassData() override;
    virtual const void ShowPassData() override;
    void AveragePass();
};

class Airplane :public Passenger
{
protected:
    int air;
    int all_pass;
public:
    Airplane();
    Airplane(int bus, int all_p);
    ~Airplane();

    virtual const void GetPassData() override;
    virtual const void ShowPassData() override;
    void AveragePass();
};

class Train :public Cargo
{
protected:
    int train;
    int all_cargo;
public:
    Train();
    Train(int bus, int all_c);
    ~Train();

    virtual const void GetCargoData() override;
    virtual const void ShowCargoData() override;
    void TotalCost();
};

class Car :public Cargo
{
protected:
    int car;
    int all_cargo;
public:
    Car();
    Car(int bus, int all_c);
    ~Car();

    virtual const void GetCargoData() override;
    virtual const void ShowCargoData() override;
    void TotalCost();
};
