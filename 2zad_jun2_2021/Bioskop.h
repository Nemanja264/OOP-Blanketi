#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template<class T>
class Bioskop
{
private:
	int maxEl;
	int top;
	T* filmovi;
	double ocena;
public:
	Bioskop();
	Bioskop(int brel,double rate);
	~Bioskop();

	void Dodaj(T& podatak);
	void Obrisi(int index);
	void PromeniOcenu(int index, double rate);
	int brFilmova(double rate);
	void MinMax(T* min, T* max);

	void Sacuvaj(const char* file);
	void Ucitaj(const char* file);
	void Ispisi();
};

template<class T>
Bioskop<T>::Bioskop() {
	ocena = 0;
	top = 0;
	maxEl = 0;
	filmovi = nullptr;
}

template<class T>
Bioskop<T>::Bioskop(int brel, double rate) {
	maxEl = brel;
	top = 0;
	ocena = rate;
	filmovi = new T[maxEl];
}

template<class T>
Bioskop<T>::~Bioskop() {
	if (filmovi != nullptr)
		delete[] filmovi;
}

template<class T>
void Bioskop<T>::Dodaj(T& podatak) {
	if (podatak >= ocena) {
		if (top == maxEl) {
			throw "Spisak filmova je popunjen!";
		}
		else
		{
			filmovi[top++] = podatak;
		}
	}
	else
	{
		throw "Ocena film je manja od minimalne!";
	}
}

template<class T>
void Bioskop<T>::Obrisi(int index) {
	if (index < 0 || index >= top) {
		throw "Losa pozicija!";
	}
	else
	{
		for (int i = index; i < top-1; i++)
			filmovi[i] = filmovi[i + 1];
		top--;
	}
}

template<class T>
void Bioskop<T>::PromeniOcenu(int index, double rate) {
	if (index < 0 || index >= top) {
		throw "Losa pozicija!";
	}
	else
	{
		if (ocena > rate) {
			for (int i = index; i < top-1; i++)
				filmovi[i] = filmovi[i + 1];
			top--;
		}
		else
		{
			filmovi[index] = rate;
		}
		
	}
}

template<class T>
void Bioskop<T>::Sacuvaj(const char* file) {
	ofstream sacuvaj(file);

	if (sacuvaj.good()) {
		for (int i = 0; i < top; i++)
			sacuvaj << filmovi[i] << endl;

		sacuvaj.close();
	}
	else
	{
		throw "Greska pri otvaranju fajla!";
	}
}

template<class T>
void Bioskop<T>::Ucitaj(const char* file) {
	ifstream ucitaj(file);

	if (ucitaj.good()) {
		
		while(!ucitaj.eof()) {
			ucitaj >> filmovi[top++];
		}
		top--;
		maxEl = maxEl * 1.2;

		ucitaj.close();
	}
	else
	{
		throw "Greska pri otvaranju fajla!";
	}
}

template<class T>
int Bioskop<T>::brFilmova(double rate) {
	int BrFilmova = 0;

	for (int i = 0; i < top; i++)
		if (filmovi[i] == rate)
			BrFilmova++;

	return BrFilmova;
}

template<class T>
void Bioskop<T>::MinMax(T* min, T* max) {
	int minInd = 0;
	int maxInd = 1;
	*min = filmovi[minInd];
	*max = filmovi[maxInd];

	for (int i = 0; i < top; i++) {
		if (*min > filmovi[i]) {
			minInd = i;
		}
		if (*max < filmovi[i]) {
			maxInd = i;
		}
	}

	*min = filmovi[minInd];
	*max = filmovi[maxInd];
}

template<class T>
void Bioskop<T>::Ispisi() {
	cout << "Bioskop lista filmova, minimalne ocene " << ocena << ":" << endl;
	for (int i = 0; i < top; i++)
		cout << filmovi[i] << endl;
}
