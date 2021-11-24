#include <iostream>
#include "Lumber.h"
using namespace std;

Pine::Pine() : pricePerPiece(31.0) {}
Pine::Pine(float pricePerPiece) : pricePerPiece(pricePerPiece) {}
Pine::~Pine() {}

int const Pine::amountPiece()
{
	return ceil((1 / volumePerPiece()));
}

float const Pine::pricePerVolume()
{
	return  amountPiece() * pricePerPiece;
}

void const Pine::show()
{
	cout << "\nAverage price per cubic meter of Pine: " << pricePerVolume() << endl;
}
