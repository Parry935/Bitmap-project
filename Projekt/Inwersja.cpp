#include "Inwersja.h"

void Inwersja::przeksztalc(Bitmapa& object)
{
	//prosta petla sprawdzajaca watosc i zamieniajaca ja na przeciwna
	for (unsigned i = 0; i < object.get_length(); i++)
	{
		for (unsigned j = 0; j < object.get_width(); j++)
		{
			if (object(i, j) == true)
				object(i, j) = false;
			else
				object(i, j) = true;
		}
	}

}
