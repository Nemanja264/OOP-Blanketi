#include "Student.h"
#include <iostream>
#include <string.h>
using namespace std;

Student::Student() {
	ime = nullptr;
	prezime = nullptr;
	roditelj = nullptr;
	prosek = 0;
}

Student::Student(const char* i, const char* p, const char* r, float pr) {
	ime = new char[strlen(i) + 1];
	strcpy(ime, i);
	
	prezime = new char[strlen(p) + 1];
	strcpy(prezime, p);
	
	roditelj = new char[strlen(r) + 1];
	strcpy(roditelj, r);

	prosek = pr;
}

Student::~Student() {
	if (ime != nullptr) {
		delete[] ime;
	}

	if (prezime != nullptr) {
		delete[] prezime;
	}

	if (roditelj != nullptr) {
		delete[] roditelj;
	}
}

bool Student::operator==(Student& s) {
	if (!strcmp(this->ime, s.ime) && !strcmp(this->prezime, s.prezime) && !strcmp(this->roditelj, s.roditelj)) {
		return true;
	}
	else
	{
		return false;
	}
}

ostream& operator<<(ostream& izlaz, Student& s) {
	izlaz << s.ime << " " << s.roditelj << " " << s.prezime << " " << s.prosek;
	return izlaz;
}
