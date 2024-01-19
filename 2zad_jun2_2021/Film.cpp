#include "Film.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

Film::Film() {
	jbr = 0;
	godina = 0;
	naziv = nullptr;
	ocena = 0;

}

Film::Film(int id, const char* ime, int year, double rate) {
	jbr = id;
	godina = year;
	ocena = rate;
	naziv = new char[strlen(ime) + 1];
	strcpy(naziv, ime);
}

Film::~Film() {
	if (naziv != nullptr) {
		delete[] naziv;
	}
	naziv = nullptr;
}

ostream& operator<<(ostream& izlaz, Film& f) {
	izlaz << f.jbr << " " << f.naziv << " " << f.godina << " " << f.ocena << endl;

	return izlaz;
}

ofstream& operator<<(ofstream& upisi, Film& f) {
	upisi << f.jbr << endl << f.naziv << endl << f.godina << endl << f.ocena << endl;

	return upisi;
}

ifstream& operator>>(ifstream& ucitaj, Film& f) {
	ucitaj >> f.jbr;
	char tmp[20];
	ucitaj >> tmp;
	f.naziv = new char[strlen(tmp) + 1];
	strcpy(f.naziv, tmp);
	ucitaj >> f.godina;
	ucitaj >> f.ocena;

	return ucitaj;
}

Film& Film::operator=(double broj) {
	if (this->ocena != broj)
	{
		this->ocena = broj;
	}
	
	return *this;
}

Film& Film::operator=(Film& f) {
	if (this != &f)
	{
		this->ocena = f.ocena;
		this->godina = f.godina;
		this->jbr = f.jbr;
		//delete[] this->naziv;
		this->naziv = new char[strlen(f.naziv) + 1];
		strcpy(this->naziv, f.naziv);
	}
	
	return *this;
}

bool Film::operator>=(double broj) {
	if (this->ocena >= broj)
		return true;
	else
		return false;
}

bool Film::operator<(Film& f) {
	if (this->ocena < f.ocena)
		return true;
	else 
		return false;
}

bool Film::operator>(Film& f) {
	if (this->ocena > f.ocena)
		return true;
	else 
		return false;
}

bool Film::operator==(double broj) {
	if (this->ocena == broj)
		return true;
	else
		return false;
}
