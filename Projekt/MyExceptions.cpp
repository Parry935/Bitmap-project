#include "MyExceptions.h"

using namespace std;

bool** createBooleanTable2D(int length, int width)
{
	bool** tab = nullptr;

	try
	{
		if (length > 0)
			tab = new bool* [length];
		else
			throw MyRuntimeExceptions::BadAllocateException("Nie udalo sie zaalokowac pamieci na tablice boolowska!");
	}
	catch (std::runtime_error & e)
	{
		cerr << e.what();
		exit(0);
	}


	for (unsigned i = 0; i < length; i++)
	{
		try
		{
			if (width > 0)
				tab[i] = new bool[width];
			else
				throw MyRuntimeExceptions::BadAllocateException("Nie udalo sie zaalokowac pamieci na tablice boolowska!");
		}
		catch (std::runtime_error & e)
		{
			cerr << e.what();
			exit(0);
		}
	}

	for (unsigned i = 0; i < length; i++)
	{
		for (unsigned j = 0; j < width; j++)
		{
			tab[i][j] = false;
		}
	}


	return tab;
}

unsigned loadNaturalNumber()
{
	int number{};
	unsigned result{};

	do
	{
		try
		{
			number = sprawdzLiczbe<int>();
			if (number < 1)
				throw MyRuntimeExceptions::NotNaturalNumberException("Podana liczba musi byc naturalna!");
		}
		catch (const std::exception& e)
		{
			cerr << e.what() << endl;
		}
	} while (number < 1);

	result = number;

	return result;
}

unsigned loadNaturalNumberFromRanges(int lowBound, int highBound)
{
	int number{};
	unsigned result{};
	string warning = "Podana liczba musi byc z zakresu ";
	warning += to_string(lowBound);
	warning += " do ";
	warning += to_string(highBound);

	do
	{
		try
		{
			number = sprawdzLiczbe<int>();
			if (number < lowBound || number > highBound)
				throw MyRuntimeExceptions::NotNaturalNumberException(warning);
		}
		catch (const std::exception & e)
		{
			cerr << e.what() << endl;
		}
	} while (number < lowBound || number > highBound);

	result = number;

	return result;

}