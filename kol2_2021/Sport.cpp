#include <iostream>
#include <fstream>
#include <string.h>
#include "Sport.h"
using namespace std;

Sport::Sport() {
	naTerenu = 0;
	obuca = nullptr;
	rezervni = 0;
	koef = 0;
	budzet = 0;
}

Sport::Sport(int teren, int rez, const char* patike, int budz, float koeficijent) {
	if (koeficijent >= 0 && koeficijent <= 1 && rez <= 10 && teren <= 20 && budz <= 50000) {
		koef = koeficijent;
		naTerenu = teren;
		rezervni = rez;
		budzet = budz;
		obuca = new char[strlen(patike) + 1];
		strcpy(obuca, patike);
	}
	else
	{
		throw "Kreiranje aktivnosti nije moguce zbog nevalidnih podataka!";
	}
}

/*Sport::Sport(Sport& s) {
	this->koef = s.koef;
	this->naTerenu = s.naTerenu;
	this->rezervni = s.rezervni;
	this->budzet = s.budzet;
	this->obuca = new char[strlen(s.obuca) + 1];
	strcpy(obuca, s.obuca);

}*/

Sport::~Sport() {
	if (obuca != nullptr) {
		delete[] obuca;
	}
	obuca = nullptr;
}

ifstream& operator>>(ifstream& ucitaj, Sport& s) {
	ucitaj >> s.naTerenu;
	ucitaj >> s.rezervni;
	ucitaj >> s.budzet;
	ucitaj >> s.koef;
	
	char naziv[10];
	ucitaj >> naziv;
	s.obuca = new char[strlen(naziv) + 1];
	strcpy(s.obuca, naziv);

	return ucitaj;
}

ostream& operator<<(ostream& ispisi, Sport& s) {
	ispisi << "Broja igraca na terenu: " << s.naTerenu << "\nBroj rezervnih: " << s.rezervni << "\nBudzet: " << s.budzet;
	ispisi << "\nObuca: " << s.obuca << "\nKoeficijent popularnosti: " << s.koef << endl;

	return ispisi;
}

float Sport::Vrednost() {
	return (naTerenu + rezervni) * budzet * koef;
}

bool Sport::operator>(Sport& s) {
	if (this->Vrednost() > s.Vrednost())
		return true;
	else
		return false;
}

float Sport::operator+(float broj) {
	return this->Vrednost() + broj;
}

Sport& Sport::operator=(const Sport& s) {
	if (this != &s) {
		naTerenu = s.naTerenu;
		budzet = s.budzet;
		koef = s.koef;
		rezervni = s.rezervni;

		obuca = new char[strlen(s.obuca) + 1];
		strcpy(obuca, s.obuca);
	}
	return *this;
}
