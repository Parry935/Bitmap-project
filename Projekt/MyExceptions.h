#pragma once

#include <fstream>
#include <exception>
#include <string>
#include <iostream>

namespace MyRuntimeExceptions {

	/*
	Klasa obslugujaca blad zaalokowania pamieci
	*/
	class BadAllocateException : public std::runtime_error
	{
	public:
		BadAllocateException() : runtime_error("Nie udalo sie zaalokowac pamieci")
		{}

		BadAllocateException(std::string msg) : runtime_error(msg.c_str())
		{}
	};


	/*
	Klasa obslugujaca wyjatek w przypadku wystapienia liczby innej niz naturalna
	*/
	class NotNaturalNumberException : public std::runtime_error
	{
	public:
		NotNaturalNumberException() : runtime_error("Liczba nie jest naturalna")
		{}

		NotNaturalNumberException(std::string msg) : runtime_error(msg.c_str())
		{}
	};

}



using namespace std;

template <typename T>

T sprawdzLiczbe()
{
	T liczba;
	int ok, podglad;

	do
	{
		ok = 1;
		cin >> liczba;
		if (cin.fail())                    //jesli wczytanie sie nie powiodlo
		{
			ok = 0;
			cin.clear();                   //czysci flage bledu strumienia
			cin.ignore(INT_MAX, '\n');     //usuwa wszystkie znaki z buforu strumienia a¿ do napotkania znaku '\n' 
		}
		else
		{
			while ((podglad = cin.get()) != '\n')  //cin.get() - pobierz znak ze strumienia 
			{
				if (podglad != ' ')            // Szukanie zbêdnych danych w strumieniu
				{
					ok = 0;
					cin.ignore(INT_MAX, '\n'); // czyszczenie strumienia
					break;
				}
			}
		}
		if (ok == 0) cout << "\n Nie podano wlasciwego typu danych. Sprobuj wpisac ponownie...\n\n ";
	} while (ok == 0);

	return liczba;
}


/*
Funkcja tworzaca tablice boolowska dynamiczna dwuwymiarowa
@param size rozmiar tablicy do utworzenia
@return adres tablicy dynamicznej
*/
bool** createBooleanTable2D(int length, int width);

/*
Funkcja zajmujaca sie pobraniem od uzytkownika liczby naturalnej
@return liczba naturalna
*/
unsigned loadNaturalNumber();

/*
Funkcja zajmujaca sie pobraniem od uzytkownika liczby naturalnej z danego zakresu
@param lowBound dolna granica wczytywania liczby
@param highBound gorna granica wczytywania liczby
@return liczba naturalna
*/
unsigned loadNaturalNumberFromRanges(int lowBound, int highBound);