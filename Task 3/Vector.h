#pragma once

class Vector
{
private:
    double* mas;
    unsigned int size;
public:
    Vector();
    Vector(unsigned int s);
    Vector(unsigned int s, double firstElem);
    ~Vector();
    void const showData();
    void const srtAscending();
    void const findMin();
    int const findMax();
    void const findAverage();
    void const findSummAfterMaxNumber();
};