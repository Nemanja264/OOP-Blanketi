#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Proizvod {
private:
	char* ime;
	int rok;
	int cena;
	int koef;
public:
	Proizvod();
	Proizvod(const char* proizvod,int istek,int price,int koeficijent);
	~Proizvod();

	int Vrednost();

	friend ofstream& operator<<(ofstream& upisi, Proizvod& p);
	friend ifstream& operator>>(ifstream& ucitaj, Proizvod& p);
	friend ostream& operator<<(ostream& ispisi, Proizvod& p);

	int operator+(float broj);
};
