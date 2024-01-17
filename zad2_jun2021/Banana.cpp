#include "Banana.h"
#include <iostream>
using namespace std;

Banana::Banana() {
	zrela = false;
	trula = false;
	tezina = 0;
}

Banana::Banana(int weight, bool zr, bool tr) {
	zrela = zr;
	trula = tr;
	if (trula) {
		tezina = -1;
	}
	else
	{
		tezina = weight;
	}
}

Banana::~Banana() {}

ostream& operator<<(ostream& izlaz, Banana& b) {
	izlaz << "Tezina banane: " << b.tezina << endl;
	if (b.trula)
		izlaz << "trula" << endl;
	else
		izlaz << "nije trula" << endl;

	if (b.zrela)
		izlaz << "zrela" << endl;
	else
		izlaz << "nije zrela" << endl;

	return izlaz;
}

float Banana::operator+(float broj) {
	return (this->Vrednost() + broj);
}

Banana& Banana::operator=(Banana& b) {
	if (this != &b) {
		this->tezina = b.tezina;
		this->trula = b.trula;
		this->zrela = b.zrela;
	}
	return *this;
}

float Banana::operator/(float broj) {
	return (this->Vrednost() / broj);
}
