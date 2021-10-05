#include <iostream>
#include "Lumber.h"
using namespace std;

Lumber::Lumber() : width(0), heigth(0) {}
Lumber::Lumber(unsigned int width, unsigned int heigth) : width(width), heigth(heigth) {}
Lumber::~Lumber() {}

void Lumber::setData(unsigned int width1, unsigned int heigth1)
{
	width = width1;
	heigth = heigth1;
}

const float Lumber::volumePerPiece()
{
	return (static_cast<float>(length * width * heigth) / 1000000000);
}

void const Lumber::show()
{
	cout << "length: " << length << " ";
	cout << "width: " << width << " ";
	cout << "heigth: " << heigth << endl;
	cout << "Final Volume: " << volumePerPiece() << endl;
}
