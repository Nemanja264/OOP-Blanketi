#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Preduzece
{
private:
	int mbr;
	int tip;
	int novac;
public:
	Preduzece();
	Preduzece(int MBR,int oznaka,int svota);
	~Preduzece();

	friend ofstream& operator<<(ofstream& sacuvaj, Preduzece& p);
	friend ifstream& operator>>(ifstream& ucitaj, Preduzece& p);
	friend ostream& operator<<(ostream& izlaz, Preduzece& p);

	bool operator>(Preduzece& p);
	bool operator>(int broj);
	bool operator<(Preduzece& p);
	Preduzece& operator=(Preduzece& p);
	int operator+(int broj);

};
