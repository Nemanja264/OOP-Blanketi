#include "Knjiga.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

Knjiga::Knjiga() {
	autor = nullptr;
	tiraz = 200;
	naslov = nullptr;
	BrStr = 1;
}

Knjiga::Knjiga(const char* naziv, const char* pisac, int str, int tr) {
	if (str > 0 && tr >= 200) {
		BrStr = str;
		tiraz = tr;
		
		naslov = new char[strlen(naziv) + 1];
		strcpy(naslov, naziv);
		autor = new char[strlen(pisac) + 1];
		strcpy(autor, pisac);
	}
	else
	{
		throw "Broj strana mora biti pozitivan, a tiraz >= 200!";
	}
}

Knjiga::~Knjiga() {
	if (naslov != nullptr) {
		delete[] naslov;
		naslov = nullptr;
	}
	if (autor != nullptr) {
		delete[] autor;
		autor = nullptr;
	}
}


ifstream& operator>>(ifstream& ucitaj, Knjiga& b) {
	int str, tr;
	ucitaj >> str;
	ucitaj >> tr;

	if (str > 0 && tr >= 200) {
		b.BrStr = str;
		b.tiraz = tr;
		char tmpa[20];
		char tmpn[20];
		ucitaj >> tmpa;
		ucitaj >> tmpn;

		delete[] b.naslov;
		b.naslov = new char[strlen(tmpn) + 1];
		strcpy(b.naslov, tmpn);

		delete[] b.autor;
		b.autor = new char[strlen(tmpa) + 1];
		strcpy(b.autor, tmpa);
	}
	else
	{
		throw "Broj strana mora biti pozitivan, a tiraz >= 200!";
	}

	return ucitaj;
}

ofstream& operator<<(ofstream& sacuvaj, Knjiga& b) {
	sacuvaj << b.BrStr << endl;
	sacuvaj << b.tiraz << endl;
	sacuvaj << b.naslov << endl;
	sacuvaj << b.autor << endl;

	return sacuvaj;
}

ostream& operator<<(ostream& izlaz, Knjiga& b) {
	izlaz << "Knjiga: " << b.naslov << " | Autor: " << b.autor << " | " << b.BrStr << " strana |" << b.tiraz << " broj primeraka" << endl;

	return izlaz;
}

bool Knjiga::operator==(Knjiga& b) {
	if (!strcmp(this->naslov, b.naslov) && !strcmp(this->autor, b.autor) && this->BrStr == b.BrStr && this->tiraz == b.tiraz)
		return true;
	else
		return false;
}

bool Knjiga::operator>(Knjiga& b) {
	if (!strcmp(this->naslov, b.naslov)) {
		if (!strcmp(this->autor, b.autor)) {

			if (this->BrStr == b.BrStr) {
				if (this->tiraz > b.tiraz)
					return true;
				else
					return false;
			}
			else if (this->BrStr > b.BrStr)
				return true;
			else
				return false;
		}
		else if (strcmp(this->autor, b.autor) < 0) {
			return true;
		}
		else
			return false;
	}
	else if (strcmp(this->naslov, b.naslov) < 0) {
		return true;
	}
	else
		return false;
}


Knjiga& Knjiga::operator=(Knjiga& b) {
	if (this != &b) {
		this->BrStr = b.BrStr;
		this->tiraz = b.tiraz;

		this->naslov = new char[strlen(b.naslov) + 1];
		strcpy(this->naslov, b.naslov);

		this->autor = new char[strlen(b.autor) + 1];
		strcpy(this->autor, b.autor);
	}

	return *this;
}
