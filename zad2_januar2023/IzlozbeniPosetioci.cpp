#include <iostream>
#include <fstream>
#include "IzlozbeniPosetioci.h"
using namespace std;

IzlozbeniPosetioci::IzlozbeniPosetioci() {
	odrasli = 0;
	skolskaDeca = 0;
	malaDeca = 0;
}

IzlozbeniPosetioci::IzlozbeniPosetioci(int od,int sk,int mala) {
	odrasli = od;
	skolskaDeca = sk;
	malaDeca = mala;
}

IzlozbeniPosetioci::~IzlozbeniPosetioci() {}

ifstream& operator>>(ifstream& ucitaj, IzlozbeniPosetioci& ip) {
	ucitaj >> ip.odrasli;
	ucitaj >> ip.skolskaDeca;
	ucitaj >> ip.malaDeca;

	return ucitaj;
}

ofstream& operator<<(ofstream& upisi, IzlozbeniPosetioci& ip) {
	upisi << ip.odrasli << " ";
	upisi << ip.skolskaDeca << " ";
	upisi << ip.malaDeca;

	return upisi;
}

int IzlozbeniPosetioci::operator+(int broj) {
	return (this->UkupnoPosetilaca() + broj);
}

int IzlozbeniPosetioci::UkupnoPosetilaca() {
	return (odrasli + skolskaDeca + malaDeca);
}

ostream& operator<<(ostream& izlaz, IzlozbeniPosetioci& ip) {
	izlaz << "\nBroj odraslih: " << ip.odrasli << endl;
	izlaz << "Broj skolske dece: " << ip.skolskaDeca << endl;
	izlaz << "Broj dece do 7 godina: " << ip.malaDeca;

	return izlaz;
}


bool IzlozbeniPosetioci::operator>(IzlozbeniPosetioci& ip) {
	if (this->UkupnoPosetilaca() > ip.UkupnoPosetilaca())
		return true;
	else
		return false;
}
