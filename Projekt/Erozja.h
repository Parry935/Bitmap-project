#pragma once
#include "Przeksztalcenie.h"

/*
Klasa Erozja dziedziczaca po klasie abstrakcyjnej Przeksztalcanie
*/
class Erozja : public Przeksztalcenie
{
public:

	void przeksztalc(Bitmapa& object);

};