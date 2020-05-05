#include "Dylatacja.h"

void Dylatacja::przeksztalc(Bitmapa& object)
{
	//zmienne pomocnicze
	unsigned rows = object.get_length();
	unsigned columns = object.get_width();

	//tworzenie tymczasowej bitmapy
	bool** tmpBitMapa = createBooleanTable2D(rows, columns);

	//przypisanie do niej wstepnie takich same wartosci jak w oryginalnej bitmapie
	for (unsigned i = 0; i < rows; i++)
	{
		for (unsigned j = 0; j < columns; j++)
		{
			tmpBitMapa[i][j] = object(i, j);
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			//jesli pixel p jest false sprawdzamy wszystkie mozliwe piksele z 4 stron  wokol niego czy jest jakikolwiek true i zmieniamy na p na true
			if (object(i, j) == false)
			{
				//dla gornego elementu
				if ((i - 1) >= 0)
				{
					if (object(i - 1, j) != false)
					{
						tmpBitMapa[i][j] = true;
						continue;
					}
				}

				//dla lewego elementu
				if ((j - 1) >= 0)
				{
					if (object(i, j - 1) != false)
					{
						tmpBitMapa[i][j] = true;
						continue;
					}
				}

				//dla dolnego elementu
				if ((i + 1) < rows)
				{
					if (object(i + 1, j) != false)
					{
						tmpBitMapa[i][j] = true;
						continue;
					}
				}
				//dla prawego elementu
				if ((j + 1) < columns)
				{
					if (object(i, j + 1) != false)
					{
						tmpBitMapa[i][j] = true;
						continue;
					}
				}
			}
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
