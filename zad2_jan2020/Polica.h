#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template<class T>
class Polica
{
private:
	T* niz;
	int maxEl;
	int top;
public:
	Polica();
	Polica(int brel);
	~Polica();

	void Dodaj(T& podatak);
	void Izbaci(int index);
	void Ispisi();
	void Ucitaj(const char* file);
	void Sacuvaj(const char* file);
};

template<class T>
Polica<T>::Polica() {
	top = 0;
	maxEl = 0;
	niz = nullptr;
}

template<class T>
Polica<T>::Polica(int brel) {
	maxEl = brel;
	top = 0;
	niz = new T[maxEl];
}

template<class T>
Polica<T>::~Polica() {
	if (niz != nullptr)
		delete[] niz;
}

template<class T>
void Polica<T>::Dodaj(T& podatak) {
	if (top == maxEl) {
		throw "Polica je puna!";
	}
	else
	{
		bool duplikat = false;
		for (int i = 0; i < top; i++) {
			if (niz[i] == podatak)
				duplikat = true;
		}
		if (!duplikat) {
			niz[top++] = podatak;

			for(int i=0;i<top-1;i++)
				for (int j = i + 1; j < top; j++) {
					T pom;
					if (niz[j] > niz[i])
					{
						pom = niz[i];
						niz[i] = niz[j];
						niz[j] = pom;
					}
				}
		}
		else
		{
			throw "Duplikat!";
		}
		
	}
}

template<class T>
void Polica<T>::Izbaci(int index) {
	if (index < 0 || index >= top || top == 0) {
		throw "Nepostojeci index!";
	}
	else
	{
		for (int i = index; i < top - 1; i++)
			niz[i] = niz[i + 1];
		top--;
	}
}

template<class T>
void Polica<T>::Ucitaj(const char* file) {
	ifstream ucitaj(file);

	if (ucitaj.good()) {
		ucitaj >> maxEl;

		while (!ucitaj.eof() && top < maxEl) {
			ucitaj >> niz[top++];

			if (top > 1) {
				bool duplikat = false;
				for (int i = 0; i < top - 1; i++)
					if (niz[i] == niz[top - 1])
						duplikat = true;
				if (duplikat) {
					throw "Duplikat!";
				}
			}
		}
		top--;
		for (int i = 0; i < top - 1; i++)
			for (int j = i + 1; j < top; j++) {
				T pom;
				if (niz[j] > niz[i])
				{
					pom = niz[i];
					niz[i] = niz[j];
					niz[j] = pom;
				}
			}
	}
	else
	{
		throw "Greska pri otvaranju fajla!";
	}
}

template<class T>
void Polica<T>::Ispisi() {
	cout << "Polica:\n";
	for (int i = 0; i < top; i++)
		cout << niz[i] << endl;
}

template<class T>
void Polica<T>::Sacuvaj(const char* file) {
	ofstream sacuvaj(file);

	if (sacuvaj.good()) {
		sacuvaj << maxEl << endl;
		for(int i=0;i<top;i++)
			sacuvaj<<niz[i]<<endl;
	}
	else
	{
		throw "Greska pri otvaranju fajla!";
	}
}
