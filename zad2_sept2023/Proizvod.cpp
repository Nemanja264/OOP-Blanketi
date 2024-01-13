#include <iostream>
#include <fstream>
#include <string.h>
#include "Proizvod.h"
using namespace std;

Proizvod::Proizvod() {
	ime = nullptr;
	koef = 0;
	cena = 0;
	rok = 4;
}

Proizvod::Proizvod(const char* proizvod, int istek, int price, int koeficijent) {
	
	if (istek > 3 && price <= 10000) {
		ime = new char[strlen(proizvod) + 1];
		strcpy(ime, proizvod);
		rok = istek;
		cena = price;
		koef = koeficijent;
		
	}
	else
	{
		throw "Nevalidne vrednosti!";
	}
}

Proizvod::~Proizvod() {
	if (ime != nullptr) 
		delete[] ime;
	
	ime = nullptr;
}

int Proizvod::Vrednost() {
	return cena * koef;
}

int Proizvod::operator+(float broj) {
	return this->Vrednost() + (int)broj;
}

ifstream& operator>>(ifstream& ucitaj, Proizvod& p) {
	char tmpIme[100];
	ucitaj >> tmpIme;
	ucitaj >> p.rok;
	ucitaj >> p.koef;
	ucitaj >> p.cena;
	p.ime = new char[strlen(tmpIme) + 1];
	strcpy(p.ime, tmpIme);

	return ucitaj;
}

ofstream& operator<<(ofstream& upisi, Proizvod& p) {
	upisi << p.ime << endl;
	upisi << p.rok << endl;
	upisi << p.koef << endl;
	upisi << p.cena;

	return upisi;
}

ostream& operator<<(ostream& ispisi, Proizvod& p) {
	ispisi << p.ime << endl;
	ispisi << "Rok: " << p.rok << endl;
	ispisi << "Koeficijent: " << p.koef << endl;
	ispisi << "Cena: "  << p.cena << endl;

	return ispisi;
}

