#include <iostream>
#include "Lumber.h"
using namespace std;

Oak::Oak() : pricePerPiece(31.0) {}
Oak::Oak(float pricePerPiece) : pricePerPiece(pricePerPiece) {}
Oak::~Oak() {}

int const Oak::amountPiece()
{
	return ceil((1 / volumePerPiece()));
}

float const Oak::pricePerVolume()
{
	return  amountPiece() * pricePerPiece;
}

void const Oak::show()
{
	cout << "\nAverage price per cubic meter of Oak: " << pricePerVolume() << endl;
}