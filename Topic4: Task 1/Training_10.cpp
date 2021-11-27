#include<iostream>
#include<exception>
using namespace std;
template<typename T>
class myQueue
{
private:
    T* mas;
    int countEl;
    int first;
    int last;
    int sizeQ;
public:
    myQueue() :sizeQ(0) {}
    myQueue(int max) :sizeQ(max)
    {
        try
        {
            first = 0;
            last = -1;
            countEl = 0;
            mas = new T[sizeQ];
        }
        catch (bad_alloc error)
        {
            cerr << error.what() << endl;
        }
    }
    ~myQueue()
    {
        delete[]mas;
    }

    //вставка в конец очереди
    void insert(T a)
    {
        if (last == sizeQ - 1)// проверка на конец очереди
        {
            throw exception("Queue is FULL!!!!!");
        }
        mas[++last] = a;
        countEl++;
    }

    //удаление элемента(из начала очереди)
    void myPop()
    {
        T* temp;

        if (countEl == 0)
        {
            throw exception("EMPTY QUEUE, try another func!");
        }
        else if (countEl >= 1)
        {
            --countEl;
            temp = new T[countEl];
            ++first;
            for (int i = 0; i < countEl; i++)
            {
                temp[i] = mas[first];
            }
            last--;
            delete[] mas;
            mas = temp;
            first = 0;
            temp = nullptr;
        }
    }

    //возвращает первый элемент очереди
    void ShowFirst() const
    {
        if (countEl == 0)
        {
            cout << "Nothing here_LOL!";

        }
        else
        {
            cout << "First element: " << mas[first];
        }
    }

    int ShowCountEl() const
    {
        return countEl;
    }

    bool isEmpty() const
    {
        return countEl == 0;
    }

    void Display()
    {
        int bufEl = first;
        cout << "first: " << first << endl;
        cout << "last: " << last << endl;
        if (countEl == 0)
        {
            cout << "Queue is empty, sorry!" << endl;
            return;
        }
        do
        {
            cout << mas[bufEl] << " ";
            bufEl++;
        } while (bufEl != (last + 1));
        cout << endl;
    }

};

int main()
{
    setlocale(LC_ALL, "Russian");
    int choice;

    myQueue<int> q1(2);
    cout << "1-Вставить элемент\n2-Удалить элемент из начала очереди\n3-Показать первый элемент\n4-Показать количество элементов в очереди\n5-Проверка на пустоту очереди\n6-Вывести очередь\n7-Выход" << endl;

    while (true)
    {
        try
        {
            int number;
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "Enter the number of element: ";
                cin >> number;
                q1.insert(number);
                cout << endl;
                break;
            case 2:
                q1.myPop();
                cout << endl;
                cout << "---------------------------------------------" << endl;
                break;
            case 3:
                q1.ShowFirst();
                cout << endl;
                cout << "---------------------------------------------" << endl;
                break;
            case 4:
                cout << "Count: " << q1.ShowCountEl();
                cout << endl;
                cout << "---------------------------------------------" << endl;
                break;
            case 5:
                cout << "Empty?(1-yes, 0-no): " << q1.isEmpty();
                cout << endl;
                cout << "---------------------------------------------" << endl;
                break;
            case 6:
                q1.Display();
                cout << "---------------------------------------------" << endl;
                break;
            case 0:
                return false;
            default:
                break;
            }
        }

        catch (const exception& err)
        {
            cerr << "Error: " << err.what() << endl;
        }
    }
    return 0;
}
