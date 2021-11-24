#pragma once
using namespace std;

class Lumber
{
private:
	unsigned int length = 6000;
	unsigned int width;
	unsigned int heigth;
public:
	Lumber();
	Lumber(unsigned int width, unsigned int heigth);
	~Lumber();

	void setData(unsigned int width1, unsigned int heigth1);
	float const volumePerPiece();
	void const show();
};

class Oak :public Lumber
{
private:
	float pricePerPiece;
public:
	Oak();
	Oak(float pricePerPiece);
	~Oak();

	int const amountPiece();
	float const pricePerVolume();
	void const show();
};

class Pine :public Lumber
{
private:
	float pricePerPiece;
public:
	Pine();
	Pine(float pricePerPiece);
	~Pine();

	int const amountPiece();
	float const pricePerVolume();
	void const show();
};

class Birch :public Lumber
{
private:
	float pricePerPiece;
public:
	Birch();
	Birch(float pricePerPiece);
	~Birch();

	int const amountPiece();
	float const pricePerVolume();
	void const show();
};
