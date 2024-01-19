#pragma once
#include <iostream>

template<class T>
class Donacije 
{
private:
	T* spisak;
	int top;
	int maxEl;
public:
	Donacije();
	Donacije(int brel);
	~Donacije();

	void Dodaj(T& podatak);
	void Obrisi(int index);
	void MinMax(T* min, T* max);
	void Ukupno();
	int VeceOd(int svota);

	void Sacuvaj(const char* file);
	void Ucitaj(const char* file);
	void Ispisi();
};

template<class T>
Donacije<T>::Donacije() {
	top = 0;
	maxEl = 0;
	spisak = nullptr;
}

template<class T>
Donacije<T>::Donacije(int brel) {
	top = 0;
	maxEl = brel;
	spisak = new T[maxEl];
}

template<class T>
Donacije<T>::~Donacije() {
	if (spisak != nullptr)
	{
		delete[] spisak;
	}
}

template<class T>
void Donacije<T>::Dodaj(T& podatak) {
	if (top == maxEl) {
		throw "Popunjen je spisak!";
	}
	else
	{
		spisak[top++] = podatak;
	}
}

template<class T>
int Donacije<T>::VeceOd(int svota) {
	int brDonacija = 0;

	for (int i = 0; i < top; i++)
		if (spisak[i] > svota)
			brDonacija++;

	return brDonacija;
}

template<class T>
void Donacije<T>::Sacuvaj(const char* file) {
	ofstream sacuvaj(file);

	if (sacuvaj.good()) {
		sacuvaj << maxEl << endl;
		for (int i = 0; i < top; i++)
			sacuvaj << spisak[i] << endl;
	}
	else
	{
		throw "Greska pri otvaranju fajla!";
	}
}

template<class T>
void Donacije<T>::Ucitaj(const char* file) {
	ifstream ucitaj(file);

	if (ucitaj.good()) {
		ucitaj >> maxEl;
		
		while (!ucitaj.eof())
		{
			ucitaj >> spisak[top++];
		}
		top--;
	}
	else
	{
		throw "Greska pri otvaranju fajla!";
	}
}

template<class T>
void Donacije<T>::Ukupno() {
	int suma = 0;

	for (int i = 0; i < top; i++)
		suma = spisak[i] + suma;

	cout << "Ukupno je prikupljeno " << suma << "RSD kroz donacije." << endl;
}

template<class T>
void Donacije<T>::Obrisi(int index) {
	if (index < 0 || index >= top) {
		throw "Losa pozicija!";
	}
	else
	{
		for (int i = index; i < top - 1; i++)
			spisak[i] = spisak[i + 1];
		top--;
	}
}

template<class T>
void Donacije<T>::MinMax(T* min, T* max) {
	*min = spisak[0];

	for (int i = 0; i < top; i++) {
		if (spisak[i] > *max) {
			*max = spisak[i];
		}
		if (spisak[i] < *min) {
			*min = spisak[i];
		}
	}
}

template<class T>
void Donacije<T>::Ispisi() {
	cout << "Spisak donacija:\n";
	for (int i = 0; i < top; i++)
		cout << spisak[i] << endl;
}
