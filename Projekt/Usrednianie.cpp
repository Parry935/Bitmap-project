#include "Usrednianie.h"

void Usrednianie::przeksztalc(Bitmapa& object)
{
	//zmienne pomocnicze
	unsigned rows = object.get_length();
	unsigned columns = object.get_width();
	int counterOfBlackPixels{};
	int counterOfWhitePixels{};

	//torzymy tymczasowa bitmape
	bool** tmpBitMapa = createBooleanTable2D(rows, columns);

	//przypisujemy do niej wstepnie takie same wartosci jak w oryginalnej bitmapie
	for (unsigned i = 0; i < rows; i++)
	{
		for (unsigned j = 0; j < columns; j++)
		{
			tmpBitMapa[i][j] = object(i, j);
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++, counterOfBlackPixels = 0, counterOfWhitePixels = 0)
		{
			//dla gornego elementu
			if ((i - 1) >= 0)
			{
				if (object(i - 1, j) == true)
					counterOfBlackPixels++;
				else
					counterOfWhitePixels++;
			}

			//dla lewego elementu
			if ((j - 1) >= 0)
			{
				if (object(i, j - 1) == true)
					counterOfBlackPixels++;
				else
					counterOfWhitePixels++;
			}

			//dla dolnego elementu
			if ((i + 1) < rows)
			{
				if (object(i + 1, j) == true)
					counterOfBlackPixels++;
				else
					counterOfWhitePixels++;
			}
			//dla prawego elementu
			if ((j + 1) < columns)
			{
				if (object(i, j + 1) == true)
					counterOfBlackPixels++;
				else
					counterOfWhitePixels++;
			}

			/*
			Jesli obok pixela p sa 3 lub 4 czarne pixele zamieniamy p na czarny
			analogicznie dla pixeli bialych
			*/
			if (counterOfBlackPixels > 2)
				tmpBitMapa[i][j] = true;
			else if (counterOfWhitePixels > 2)
				tmpBitMapa[i][j] = false;
		}
	}

	//przypisanie wartosci z tymczasowej bitmapy do przyslanej przez referencje
	for (unsigned i = 0; i < rows; i++)
	{
		for (unsigned j = 0; j < columns; j++)
		{
			object(i, j) = tmpBitMapa[i][j];
		}
	}

	delete[] tmpBitMapa;
}
