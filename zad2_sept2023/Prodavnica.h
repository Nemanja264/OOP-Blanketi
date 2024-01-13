#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

template<class T>
class Prodavnica {
private:
	char* naziv;
	T* spisak;
	int top;
	int brPolica;
	int maxEl;
public:
	Prodavnica();
	Prodavnica(const char* ime, int police);
	~Prodavnica();

	void ZauzmiMem(const char* ime, int police);

	void Dodaj(T& proizvod);
	void Prodaj(int index);
	float SrednjaVr();
	void Ispisi();

	void Ucitaj(const char* file);
	void Upisi(const char* file);

};

template<class T>
void Prodavnica<T>::ZauzmiMem(const char* ime, int police) {
	brPolica = police;
	maxEl = brPolica * 5;

	spisak = new T[maxEl];
	for (int i = 0; i < maxEl; i++)
		spisak[i] = T();

	naziv = new char[strlen(ime) + 1];
	strcpy(naziv, ime);

}

template<class T>
Prodavnica<T>::Prodavnica() {
	naziv = nullptr;
	spisak = nullptr;
	top = 0;
	brPolica = 0;
	maxEl = 0;
}

template<class T>
Prodavnica<T>::~Prodavnica() {
	if (spisak != nullptr) {
		delete[] spisak;
		spisak = nullptr;
	}
	if (naziv != nullptr) {
		delete[] naziv;
		naziv = nullptr;
	}
}

template<class T>
Prodavnica<T>::Prodavnica(const char* ime, int police) {
	top = 0;
	ZauzmiMem(ime, police);
}

template<class T>
float Prodavnica<T>::SrednjaVr() {
	float suma = 0;

	for (int i = 0; i < top; i++)
		suma = (float)(spisak[i] + suma);

	return (suma / top);
}

template<class T>
void Prodavnica<T>::Upisi(const char* file) {
	ofstream upisi(file);

	if (upisi.good()) {
		upisi << naziv << endl;
		upisi << brPolica << endl;
		upisi << top << endl;
		for (int i = 0; i < top; i++)
			upisi << spisak[i] << endl;

		upisi.close();
	}
	else
	{
		throw "Greska pri otvaranju fajla!";
	}
}



template<class T>
void Prodavnica<T>::Ucitaj(const char* file) {
	ifstream ucitaj(file);

	if (ucitaj.good()) {
		char ime[100];
		ucitaj >> ime;
		ucitaj >> brPolica;
		ucitaj >> top;
		ZauzmiMem(ime, brPolica);

		for (int i = 0; i < top; i++)
			ucitaj >> spisak[i];
	}
	else
	{
		throw "Greska pri otvaranju fajla!";
	}
}

template<class T>
void Prodavnica<T>::Prodaj(int index) {
	if (index < 0 && index >= top) {
		throw "Proizvod sa ovim rednim brojem ne postoji!";
	}
	else
	{
		for (int i = index; i < top - 1; i++)
			spisak[i] = spisak[i + 1];

		top--;
		spisak[top] = T();
	}
}

template<class T>
void Prodavnica<T>::Ispisi() {
	cout << naziv << endl;
	cout << "Broj polica: " << brPolica << endl << endl;
	for (int i = 0; i < top; i++)
		cout << spisak[i] << endl;
}

template<class T>
void Prodavnica<T>::Dodaj(T& proizvod) {
	if (top != maxEl) {
		spisak[top++] = proizvod;
	}
	else
	{
		throw "Prodavnica je popunjena!";
	}
}
