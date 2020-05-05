#pragma once
#include "Przeksztalcenie.h"
#include "MyExceptions.h"

/*
Klasa Dylatacja dziedziczaca po klasie abstrakcyjnej Przeksztalcanie
*/
class Dylatacja : public Przeksztalcenie
{
public:

	void przeksztalc(Bitmapa& object);

};