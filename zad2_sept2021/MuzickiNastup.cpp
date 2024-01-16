#include "MuzickiNastup.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

MuzickiNastup::MuzickiNastup() {
	naziv = nullptr;
	trajanje = 0;
	koef = 0;
	izvodjaci = 0;
}

MuzickiNastup::MuzickiNastup(const char* ime, int brizv, int vreme, float popularnost) {
	if (izvodjaci <= 10 && trajanje <= 120) {
		izvodjaci = brizv;
		trajanje = vreme;
		koef = popularnost;

		naziv = new char[strlen(ime) + 1];
		strcpy(naziv, ime);
	}
	else
	{
		throw "Ne validna vrednost je unesena!";
	}
	
}

MuzickiNastup::~MuzickiNastup() {
	if (naziv != nullptr) {
		delete[] naziv;
	}
	naziv = nullptr;
}

float MuzickiNastup::Vrednost() {
	return (trajanje * koef);
}

float MuzickiNastup::operator+(float broj) {
	return this->Vrednost() + broj;
}

ostream& operator<<(ostream& izlaz, MuzickiNastup& mn) {
	izlaz << mn.naziv << "\nBroj izvodjaca: " << mn.izvodjaci << "\nTrajanje: " << mn.trajanje << "\nKoeficijent: " << mn.koef << endl;

	return izlaz;
}

ofstream& operator<<(ofstream& upisi, MuzickiNastup& mn) {
	upisi << mn.naziv << endl;
	upisi << mn.izvodjaci << endl;
	upisi << mn.trajanje << endl;
	upisi << mn.koef << endl;

	return upisi;
}

MuzickiNastup& MuzickiNastup::operator=(MuzickiNastup& mn) {
	if (this != &mn) {
		this->izvodjaci = mn.izvodjaci;
		this->koef = mn.koef;
		this->trajanje = mn.trajanje;

		delete[] this->naziv;
		this->naziv = new char[strlen(mn.naziv) + 1];
		strcpy(this->naziv, mn.naziv);
	}
	
	return *this;
}

