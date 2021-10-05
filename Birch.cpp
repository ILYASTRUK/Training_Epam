#include <iostream>
#include "Lumber.h"
using namespace std;

Birch::Birch() : pricePerPiece(31.0) {}
Birch::Birch(float pricePerPiece) : pricePerPiece(pricePerPiece) {}
Birch::~Birch() {}

int const Birch::amountPiece()
{
	return ceil((1 / volumePerPiece()));
}

float const Birch::pricePerVolume()
{
	return  amountPiece() * pricePerPiece;
}

void const Birch::show()
{
	cout << "\nAverage price per cubic meter of Birch: " << pricePerVolume() << endl;
}