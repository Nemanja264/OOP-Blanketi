#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Knjiga
{
private:
	char* naslov;
	char* autor;
	int BrStr;
	int tiraz;
public:
	Knjiga();
	Knjiga(const char* naziv,const char* pisac, int str, int tr);
	~Knjiga();

	friend ifstream& operator>>(ifstream& ucitaj, Knjiga& b);
	friend ofstream& operator<<(ofstream& sacuvaj, Knjiga& b);
	friend ostream& operator<<(ostream& izlaz, Knjiga& b);

	Knjiga& operator=(Knjiga& b);
	bool operator==(Knjiga& b);
	bool operator>(Knjiga& b);
};
