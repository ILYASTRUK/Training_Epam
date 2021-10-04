#pragma once


class String
{
private:
    enum { SIZE = 80 };
    char str[SIZE];
public:
    String();
    ~String();
    void const show();
    void const getData();
    void const swapsymbol();
    
};