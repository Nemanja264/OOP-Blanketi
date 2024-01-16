#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

template<class T>
class Festival {
private:
	char* naziv;
	T* repertoar;
	int maxEl;
	int top;
	int trajanje;
public:
	Festival();
	Festival(const char* ime,int brdana);
	~Festival();

	void Dodaj(T& podatak);
	void Upisi(const char* file);
	float SrednjaVr();
	void Otkazi(int index);

	void Ispisi();
};

template<class T>
Festival<T>::Festival() {
	naziv = nullptr;
	trajanje = 0;
	repertoar = nullptr;
	maxEl = 0;
	top = 0;
}

template<class T>
Festival<T>::Festival(const char* ime, int brdana) {
	trajanje = brdana;
	maxEl = trajanje * 2;
	top = 0;

	naziv = new char[strlen(ime) + 1];
	strcpy(naziv, ime);

	repertoar = new T[maxEl];
}

template<class T>
Festival<T>::~Festival() {
	if (naziv != nullptr) {
		delete[] naziv;
	}
	if (repertoar != nullptr) {
		delete[] repertoar;
	}
}

template<class T>
float Festival<T>::SrednjaVr() {
	float suma = 0;
	for (int i = 0; i < top; i++)
		suma = repertoar[i] + suma;

	return (float)(suma / top);
}

template<class T>
void Festival<T>::Dodaj(T& podatak) {
	if (top == maxEl) {
		throw "Pun je repertoar!";
	}
	else
	{
		repertoar[top++] = podatak;
	}
}

template<class T>
void Festival<T>::Upisi(const char* file) {
	ofstream upisi(file);

	if (upisi.good()) {
		upisi << this->naziv << endl;
		upisi << this->trajanje << endl;

		for (int i = 0; i < top; i++)
			upisi << repertoar[i] << endl;
	}
	else
	{
		throw "Greska pri upisivanju u fajl!";
	}
}

template<class T>
void Festival<T>::Otkazi(int index) {
	if (index < 0 || index >= top) {
		throw "Ne postoji dogadjaj sa ovim rednim brojem!";
	}
	else
	{
		for (int i = index; i < top - 1; i++)
			repertoar[i] = repertoar[i + 1];
		top--;
	}
}

template<class T>
void Festival<T>::Ispisi() {
	cout << naziv << endl;
	cout << "Traje " << trajanje << " dana" << endl;

	cout << "Repertoar dogadjaja:" << endl;
	for (int i = 0; i < top; i++)
		cout << repertoar[i] << endl;
}
