#pragma once

class Dvector
{
private:
	int** mas;
	int rows;
	int cols;
public:
	Dvector();
	Dvector(int rows, int cols);
	~Dvector();
	void const show();
	void const fillWithNumbers();
	friend void const multiplyPositiveElemRow(Dvector&);
	friend void const multiplyPositiveElemColumn(Dvector&);
};
