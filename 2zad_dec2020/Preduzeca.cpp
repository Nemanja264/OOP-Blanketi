#include <iostream>
#include <fstream>
#include "Preduzeca.h"
using namespace std;

Preduzece::Preduzece() {
	mbr = 0;
	tip = 0;
	novac = 0;
}

Preduzece::Preduzece(int MBR, int oznaka, int svota) {
	if (MBR >= 10000000 && MBR < 100000000 && oznaka>=100000 && oznaka<1000000)	{
		mbr = MBR;
		tip = oznaka;
		novac = svota;
	}
	else
	{
		throw "MBR mora biti 8-cifren broj,a Oznaka tipa 6-cifren broj!";
	}
}

Preduzece::~Preduzece() {}

bool Preduzece::operator>(Preduzece& p) {
	if (this->novac > p.novac)
		return true;
	else
		return false;
}

bool Preduzece::operator<(Preduzece& p) {
	if (this->novac < p.novac)
		return true;
	else
		return false;
}

bool Preduzece::operator>(int broj) {
	if (this->novac > broj)
		return true;
	else
		return false;
}

int Preduzece::operator+(int broj) {
	return this->novac + broj;
}

Preduzece& Preduzece::operator=(Preduzece& p) {
	if (this != &p) {
		this->mbr = p.mbr;
		this->novac = p.novac;
		this->tip = p.tip;
	}

	return *this;
}

ofstream& operator<<(ofstream& sacuvaj, Preduzece& p) {
	sacuvaj << p.mbr << endl;
	sacuvaj << p.tip << endl;
	sacuvaj << p.novac << endl;

	return sacuvaj;
}

ifstream& operator>>(ifstream& ucitaj, Preduzece& p) {
	ucitaj >> p.mbr;
	ucitaj >> p.tip;
	ucitaj >> p.novac;

	return ucitaj;
}

ostream& operator<<(ostream& izlaz, Preduzece& p) {
	izlaz << "MBR: " << p.mbr << endl << "Oznaka tip delatnosti: " << p.tip << endl;
	izlaz << "Svota novca: " << p.novac << endl << endl;

	return izlaz;
}
