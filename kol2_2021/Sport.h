#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Sport {
private:
	int naTerenu, rezervni, budzet;
	char* obuca;
	float koef;
public:
	Sport();
	//Sport(Sport& s);
	Sport(int teren, int rez, const char* patike, int budz, float koeficijent);
	~Sport();

	Sport& operator=(const Sport& s);
	friend ifstream& operator>>(ifstream& ucitaj, Sport& s);
	friend ostream& operator<<(ostream& ispisi, Sport& s);
	float operator+(float broj);
	bool operator>(Sport& s);

	float Vrednost();
};
