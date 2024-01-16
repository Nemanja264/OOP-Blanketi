#include "MuzickiNastup.h"
#include "Festival.h"
#include <iostream>
#include <fstream>
#include <random>
#include <string.h>
using namespace std;

int main() 
{
	try {
		Festival<int>* FilmskiNastup = new Festival<int>("Filmski", 4);
		random_device rd;
		mt19937 br(rd());
		uniform_int_distribution<int> range(40, 120);

		for (int i = 0; i < 6; i++) {
			int podatak = range(br);

			FilmskiNastup->Dodaj(podatak);
		}

		FilmskiNastup->Ispisi();
		float SrVrednost = FilmskiNastup->SrednjaVr();
		cout << "Srednja vrednost repertoara: " << SrVrednost << endl;

		FilmskiNastup->Otkazi(4);
		FilmskiNastup->Ispisi();
		FilmskiNastup->Otkazi(2);
		FilmskiNastup->Ispisi();

		FilmskiNastup->Upisi("filmski.txt");

		delete FilmskiNastup;
	}
	catch (const char* poruka) {
		cout << poruka << endl;
	}
	try {
		Festival<MuzickiNastup>* muzicki = new Festival<MuzickiNastup>("Muzicki", 4);

		MuzickiNastup* mn1 = new MuzickiNastup("Coldplay", 4, 80, (float)2.4);
		MuzickiNastup* mn2 = new MuzickiNastup("Travis", 2, 60, (float)2.8);
		MuzickiNastup* mn3 = new MuzickiNastup("Kanye", 1, 40, (float)3.5);
		MuzickiNastup* mn4 = new MuzickiNastup("Drake", 1, 100, (float)4.6);

		muzicki->Dodaj(*mn1);
		muzicki->Dodaj(*mn2);
		muzicki->Dodaj(*mn3);
		muzicki->Dodaj(*mn4);

		cout << endl;

		muzicki->Ispisi();

		float vrednost = muzicki->SrednjaVr();
		cout << "Srednja vrednost repertoara: " << vrednost << endl;

		muzicki->Otkazi(2);
		muzicki->Ispisi();

		muzicki->Upisi("muzicki.txt");

		delete muzicki;
	}
	catch (const char* poruka) {
		cout << poruka << endl;
	}
}
