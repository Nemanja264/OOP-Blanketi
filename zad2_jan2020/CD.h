#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class CD
{
private:
	int velicina;
	int zauzeto;
	int slobodno;
public:
	CD();
	CD(int v,int z);
	~CD();

	friend ifstream& operator>>(ifstream& ucitaj, CD& cd);
	friend ofstream& operator<<(ofstream& sacuvaj, CD& cd);
	friend ostream& operator<<(ostream& izlaz, CD& cd);

	CD& operator=(CD& cd);
	bool operator>(CD& cd);
	bool operator==(CD& cd);
};
