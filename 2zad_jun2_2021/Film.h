#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Film
{
private:
	int jbr;
	char* naziv;
	int godina;
	double ocena;
public:
	Film();
	Film(int id,const char* ime,int year,double rate);
	~Film();

	friend ifstream& operator>>(ifstream& ucitaj, Film& f);
	friend ofstream& operator<<(ofstream& upisi, Film& f);
	friend ostream& operator<<(ostream& izlaz, Film& f);

	bool operator>=(double broj);
	bool operator>(Film& f);
	bool operator<(Film& f);
	Film& operator=(double broj);
	bool operator==(double broj);
	Film& operator=(Film& f);
};
