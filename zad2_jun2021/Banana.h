#pragma once
#include <iostream>
using namespace std;

class Banana 
{
private:
	int tezina;
	bool zrela;
	bool trula;
public:
	Banana();
	Banana(int weight, bool zr, bool tr);
	~Banana();

	float Vrednost() {
		return (float)tezina;
	}

	friend ostream& operator<<(ostream& izlaz, Banana& b);
	Banana& operator=(Banana& b);
	float operator+(float broj);
	float operator/(float broj);
};
