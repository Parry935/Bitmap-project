#pragma once
#include "Przeksztalcenie.h"
#include "MyExceptions.h"

/*
Klasa Usrednianie dziedziczaca po klasie abstrakcyjnej Przeksztalcanie
*/
class Usrednianie : public Przeksztalcenie
{
public:

	void przeksztalc(Bitmapa& object);

};