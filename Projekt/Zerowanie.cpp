#include "Zerowanie.h"


void Zerowanie::przeksztalc(Bitmapa& object)
{
	for (unsigned i = 0; i < object.get_length(); i++)
	{
		//prosta funkcja zerujaca wszystkie elementy w bitmapie
		for (unsigned j = 0; j < object.get_width(); j++)
		{
				object(i, j) = false;
		}
	}
}
