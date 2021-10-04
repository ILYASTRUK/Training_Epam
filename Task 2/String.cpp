#include "String.h"
#include <iostream>
using namespace std;

String::String()
{
    str[0] = '\0';
}

String::~String()
{
    cout << "DONE!";
}

void const String::show()
{
    cout << "New string: " << str << endl;
}

void const String::getData()
{
    cout << "Enter the string: ";
    cin.get(str, SIZE);
}

void const String::swapsymbol()
{
    char key = '!';
    char keyS = 'g';

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == key)
        {
            keyS = '?';
            break;
        }
    }

    switch (keyS)
    {

    case '?':
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == key)
            {
                str[i] = '?';
            }
        }
        break;

    case 'g':
        for (int i = 0; i < strlen(str) / 2; i++)
        {
            char temp = str[i];
            str[i] = str[strlen(str) - i - 1];
            str[strlen(str) - i - 1] = temp;
        }

    default:
        break;
    }
}