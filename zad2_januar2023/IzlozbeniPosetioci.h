#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class IzlozbeniPosetioci {
private:
	int odrasli, skolskaDeca, malaDeca;
public:
	IzlozbeniPosetioci();
	IzlozbeniPosetioci(int od, int sk, int mala);
	~IzlozbeniPosetioci();

	int UkupnoPosetilaca();
	
	friend ifstream& operator>>(ifstream& ucitaj, IzlozbeniPosetioci& ip);
	friend ofstream& operator<<(ofstream& upisi, IzlozbeniPosetioci& ip);
	friend ostream& operator<<(ostream& izlaz, IzlozbeniPosetioci& ip);
	bool operator>(IzlozbeniPosetioci& ip);
	int operator+(int broj);
};
