#include "CD.h"
#include <iostream>
#include <fstream>
using namespace std;

CD::CD() {
	velicina = 1;
	zauzeto = 1;
	slobodno = 1;
}

CD::CD(int v, int z) {
	if (v > 0 && z > 0 && v>z) {
		velicina = v;
		zauzeto = z;
		slobodno = velicina - zauzeto;
	}
	else
	{
		throw "Bad space manipulation!";
	}
}

CD::~CD() {}

bool CD::operator==(CD& cd) {
	if (this->velicina == cd.velicina && this->slobodno == cd.slobodno && this->zauzeto == cd.zauzeto)
		return true;
	else
		return false;
}

bool CD::operator>(CD& cd) {
	if (this->velicina == cd.velicina) {
		if (this->slobodno > cd.slobodno)
			return true;
		else
			return false;
	}
	else if (this->velicina > cd.velicina)
	{
		return true;
	}
	else
		return false;
}

CD& CD::operator=(CD& cd) {
	if (this != &cd) {
		this->velicina = cd.velicina;
		this->zauzeto = cd.zauzeto;
		this->slobodno = cd.slobodno;
	}

	return *this;
}

ifstream& operator>>(ifstream& ucitaj, CD& cd){
	ucitaj >> cd.velicina;
	ucitaj >> cd.zauzeto;
	ucitaj >> cd.slobodno;

	return ucitaj;
}

ofstream& operator<<(ofstream& sacuvaj, CD& cd){
	sacuvaj << cd.velicina << endl;
	sacuvaj << cd.zauzeto << endl;
	sacuvaj << cd.slobodno << endl;

	return sacuvaj;
}

ostream& operator<<(ostream& izlaz, CD& cd) {
	izlaz << "CD: " << cd.zauzeto << "GB " << cd.slobodno << "GB free of " << cd.velicina << "GB" << endl;

	return izlaz;
}
