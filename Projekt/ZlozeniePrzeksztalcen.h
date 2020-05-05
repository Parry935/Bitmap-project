#pragma once
#include "Przeksztalcenie.h"
#include <vector>

using namespace std;

/*
Szablon klasy ZlozeniePrzeksztalcen dziedziczacej po klasie abstrakcyjnej Przeksztalcenie
*/
template<typename T>
class ZlozeniePrzeksztalcen : public Przeksztalcenie
{
	vector<Przeksztalcenie*> transformationsVec;

public:

	//metody skladowe
	ZlozeniePrzeksztalcen() {}

	void dodajPrzeksztalcenie(Przeksztalcenie* p);

	void przeksztalc(Bitmapa & object);

	~ZlozeniePrzeksztalcen() {}
};


template<typename T>
void ZlozeniePrzeksztalcen<T>::dodajPrzeksztalcenie(Przeksztalcenie* p)
{
	transformationsVec.push_back(p);
}

template<typename T>
void ZlozeniePrzeksztalcen<T>::przeksztalc(Bitmapa& object)
{
	for (unsigned i = 0; i < transformationsVec.size(); i++)
	{
		transformationsVec[i]->przeksztalc(object);
	}
}