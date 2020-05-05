#pragma once
#include "Bitmapa.h"
#include "MyExceptions.h"

/*
Klasa BitmapaExt dziedziczaca po klasie abstrakcyjnej Bitmapa
*/
class BitmapaExt : public Bitmapa
{
	//atrybuty pomocnicze
	unsigned length;
	unsigned width;
	bool **bitmapa;

	public:

	//konstruktor domyslny
	BitmapaExt() : length(0), width(0), bitmapa(nullptr) {}

	//kostruktor
	BitmapaExt(unsigned x, unsigned y) : length(x), width(y), bitmapa(nullptr)
	{
		bitmapa = createBooleanTable2D(length, width);
	}

	//metody dziedziczone z klasy wirtualnej
	bool & operator() (unsigned x, unsigned y);

	unsigned get_length() const;

	unsigned get_width() const;

	bool operator() (unsigned x, unsigned y) const;

	~BitmapaExt()
	{
		delete[] bitmapa;
	}
};

