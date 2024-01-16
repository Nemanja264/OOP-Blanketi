#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class MuzickiNastup {
private:
	char* naziv;
	int izvodjaci;
	int trajanje;
	float koef;
public:
	MuzickiNastup();
	MuzickiNastup(const char* ime,int brizv,int vreme,float popularnost);
	~MuzickiNastup();

	float Vrednost();

	friend ofstream& operator<<(ofstream& upisi, MuzickiNastup& mn);
	friend ostream& operator<<(ostream& izlaz, MuzickiNastup& mn);
	MuzickiNastup& operator=(MuzickiNastup& mn);
	float operator+(float broj);

};
