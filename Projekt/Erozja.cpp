#include "Erozja.h"
#include "MyExceptions.h"

void Erozja::przeksztalc(Bitmapa& object)
{
	//zmienne pomocnicze
	unsigned rows = object.get_length();
	unsigned columns = object.get_width();
	
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
		for (int j = 0; j < columns; j++)
		{
			//jesli pixel p jest true sprawdzamy wszystkie mozliwe piksele z czterech stron wokol niego czy jest jakikolwiek false i zmieniamy na p na false
			if(object(i, j) == true)
			{
				//dla gornego elementu
				if ((i - 1) >= 0)
				{
					if (object(i - 1, j) == false)
					{
						tmpBitMapa[i][j] = false;
						continue;
					}
				}

				//dla lewego elementu
				if ((j - 1) >= 0)
				{
					if (object(i, j - 1) == false)
					{
						tmpBitMapa[i][j] = false;
						continue;
					}
				}

				//dla dolnego elementu
				if ((i + 1) < rows)
				{
					if (object(i + 1, j) == false)
					{
						tmpBitMapa[i][j] = false;
						continue;
					}
				}
				//dla prawego elementu
				if ((j + 1) < columns)
				{
					if (object(i, j + 1) == false)
					{
						tmpBitMapa[i][j] = false;
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
