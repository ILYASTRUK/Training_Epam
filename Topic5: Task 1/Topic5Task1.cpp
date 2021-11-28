#include <iostream>
using namespace std;
//----------------5задание--------------изучить организацию статических/динамических массивов, арифметику указателей в C++
/*
* 1) Определить комбинированный (структурный) тип, содержащий информацию о студенте: фамилия, имя, факультет, группа, e-mail.
2) Выделить статический массив памяти для 30 студентов.
3) Выделить динамический массив памяти для заранее неизвестного количества студентов.
4) Получить доступ к первому студенту из массива, используя разыменование указателя.
5) Вычислить размер памяти, занимаемый массивом студентов.
6) Проитерироваться по массиву студентов, используя инкремент указателя. Вывести в консоль адрес каждой структуры студента в памяти. Вывести сообщение о величине, на которую изменяется значение указателя при инкременте.
7) Вывести на консоль адреса соседних полей структуры.
8) Создать структуру с таким же набором полей, но другой последовательностью. Сравнить размеры структур. Вывести на консоль адреса каждого поля для обеих структур. Сделать выводы.
*/

struct student
{
 double group;
 char fakultet;
 string name;	
 string email;
};

struct student2
{
	char fakultet;
	string name;		
	string email;
	double group;
};

void funk7(student& s, int pole)
{
	switch (pole)
	{
	case  1: //group
		cout << (void*)&s.fakultet << endl;
		break;
	case  2: //fakultet
		cout << &s.group << endl;
		cout << &s.name << endl;
		break;
	case  3: //name
		cout << (void*)&s.fakultet << endl;
		cout << &s.email << endl;
		break;
	case  4: //email
		cout << &s.name << endl;
		break;
	default:
		break;
	}
}

int main()
{
	int str=0;
	//---2
	student s[30];
	student2 s2[30];
	//---3
	student* s1 = new student;
	
	//воод данных для статического массива
	//cout << "name: "; 
	//cin >> s[2].name;
	s[2].name = "Bin";
	//cout << "fakultet[char]: "; 
	//cin >> s[2].fakultet;
	s[2].fakultet = 'B';
	//cout << "group[int]: "; 
	//cin >> s[2].group;
	s[2].group = 11;
	//cout << "email: "; 
	//cin >> s[2].email;
	s[2].email = "afsfd@sdf.com";

 
	//---4
	cout << "\nname: " << s[2].name << "\nfakultet: " << (s+2)->fakultet << "\ngroup: " << (s+2)->group << "\nemail: " << (s+2)->email << endl;


	//---5
	cout << "\nsize of mas1: " << sizeof(s[0]) << "*" << "30=" << sizeof(s) << endl;
	cout << "adress1.1: " << s << endl;
	cout << "adress1.2: " << &s[0] << endl;


	//---6
	for (student* i = s; i < &s[30]; i++)
	{
		cout << i << "   ";
		cout <<"Raznitsa: " << (i+1)-i << endl;
	}
	cout << "raznitsa adress: " << &s[3] - &s[2] << endl;
	 
	 
	//---7
	cout << "Enter Number\n(1-group || 2-fakultet || 3-name || 4-email: ";
	cin >> str;
	funk7(*s, str);
	 
	 
	//---8
	cout << "raznitsa mas1 mas2 :" << sizeof(s2) - sizeof(s);
	//Вывод: расположение данных при объявлении влияет на количество выделенной памяти
	//В нашем случае разницы нет, так как идет оптимизация по большему объему (double)
}
