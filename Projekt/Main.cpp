#include <iostream>
#include "Bitmapa.h"
#include "BitmapaExt.h"
#include "Dylatacja.h"
#include "Erozja.h"
#include "Zerowanie.h"
#include "Usrednianie.h"
#include "Inwersja.h"
#include "ZlozeniePrzeksztalcen.h"
#include "MyExceptions.h"

using namespace std;

ostream& operator<<(ostream& screen, BitmapaExt& object)
{
	screen << "BITMAPA:" << endl << endl;

	for (unsigned i = 0; i < object.get_length(); i++)
	{
		for (unsigned j = 0; j < object.get_width(); j++)
		{
			screen << object(i, j) << " ";
		}

		screen << endl;
	}

	return screen;
}

int main()
{
	//zmienne pomocnicze
	unsigned length;
	unsigned width;
	unsigned x;
	unsigned y;
	int howManyTrue;

	cout << "MENU BITMAPY" << endl << endl;
	cout << "*****************************" << endl;

	cout << "Podaj dlugosc bitmapy: " << endl;
	length = loadNaturalNumber();
	cout << endl;

	cout << "Podaj szerokosc bitmapy: " << endl;
	width = loadNaturalNumber();

	//stworzenie obiektu typu BitmapaExt z podana szrekoscia idlugoscia od uzytkownika
	BitmapaExt object(length, width);

	cout << "*****************************" << endl << endl;
	cout << "ILE POL CHCESZ ZAMIENIC NA WARTOSC -> TRUE" << endl;
	howManyTrue = sprawdzLiczbe<int>();

	for (int i = 0; i < howManyTrue; i++)
	{
		cout << "Podaj wspolzedne dla pola " << i + 1 << endl;
		cout << "X: ";
		x = loadNaturalNumberFromRanges(0, length - 1);

		cout << "Y: ";
		y = loadNaturalNumberFromRanges(0, width - 1);

		object(x, y) = true;
	}

	//utworzenie obiektow, aby na nich przeprowadzac operacje filtrowania bitmapy
	Inwersja inw;
	Erozja ero;
	Dylatacja dyl;
	Zerowanie zer;
	Usrednianie usr;

	//utworzenie obiektu typu ZlozeniePrzeksztalcen
	ZlozeniePrzeksztalcen<Przeksztalcenie> transformations;

	cout << endl << "JAKIE PRZEKSZTALCENIE CHCESZ DODAC: " << endl << endl;

	cout << "1. Inwersja" << endl;
	cout << "2. Erozja" << endl;
	cout << "3. Dylatacja" << endl;
	cout << "4. Zerowanie" << endl;
	cout << "5. Usrednianie " << endl;
	cout << "6. Zakoncz przeksztalcenia " << endl;

	int choice{};

	do
	{
		choice = sprawdzLiczbe<int>();

		switch (choice)
		{
		case 1:
			transformations.dodajPrzeksztalcenie(&inw);
			break;

		case 2:
			transformations.dodajPrzeksztalcenie(&ero);
			break;

		case 3:
			transformations.dodajPrzeksztalcenie(&dyl);
			break;

		case 4:
			transformations.dodajPrzeksztalcenie(&zer);
			break;

		case 5:
			transformations.dodajPrzeksztalcenie(&usr);
			break;

		case 6:
			cout << "Koniec przeksztalcen" << endl << endl;
			break;

		default:
			cout << "Niepoprawny wybor" << endl;
			break;
		}



	} while (choice != 6);

	for (unsigned i = 0; i < width; i++)
	{
		cout << "==";
	}
	cout << endl;
	cout << object;

	transformations.przeksztalc(object);
	cout << endl;
	cout << object;

	for (unsigned i = 0; i < width; i++)
	{
		cout << "==";
	}

	getchar();

	return 0;
}