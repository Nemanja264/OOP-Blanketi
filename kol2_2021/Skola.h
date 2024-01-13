#pragma once
#include "Sport.h"
#include <iostream>
#include <fstream>
using namespace std;

template<class T>
class Skola {
private:
	int top;
	int maxSala;
	T* sale;
public:
	Skola();
	Skola(int maxel);
	~Skola();

	void Sort();

	void Ispisi();
	void Otkazi(int brsale);
	float Prosek();
	void najvrednija();
	void najmanje();
	void Dodaj(T& podatak);
	void Ucitaj(const char* file);

};

template<class T>
Skola<T>::Skola() {
	top = 0;
	maxSala = 0;
	sale = nullptr;
}

template<class T>
Skola<T>::Skola(int maxel) {
	top = 0;
	maxSala = maxel;
	sale = new T[maxSala];
	
}

template<class T>
Skola<T>::~Skola() {
	if (sale != nullptr) {
		delete[] sale;
	}
	sale = nullptr;
}

template<class T>
void Skola<T>::Dodaj(T& podatak) {
	if (top!=maxSala) { 
		sale[top++] = podatak; 
		
		if (top > 2) {
			for (int i = 0; i < top - 1; i++) {
				for (int j = i + 1; j < top; j++) {
					if (sale[i] > sale[j]) {
						T pom;
						pom = sale[i];
						sale[i] = sale[j];
						sale[j] = pom;
					}
				}
			}
		}
		
	}
	else
	{
		throw "Sve sale su popunjene!";
	}
}

template<class T>
void Skola<T>::Otkazi(int brsale) {

	if (brsale<0 && brsale>top - 1) {
		throw "Sala sa ovim brojem ne postoji!";
	}
	else
	{
		for (int i = brsale; i < top - 1; i++) {
			sale[i] = sale[i + 1];
		}
		top--;
	}
}

template<class T>
void Skola<T>::Ucitaj(const char* file) {
	ifstream ucitaj(file);

	if (ucitaj.good()) {
		while(!ucitaj.eof()) {
			ucitaj >> sale[top++];
		}
		
		Sort();
		ucitaj.close();
	}
	else
	{
		throw "Greska pri otvaranju fajla!";
	}
}

template<class T>
float Skola<T>::Prosek() {
	float suma = 0;
	for (int i = 0; i < top; i++)
		suma = sale[i] + suma;

	cout << "Prosek: " << (float)(suma / top) << endl;
	return (float)(suma / top);
}

template<class T>
void Skola<T>::najvrednija() {
	cout << sale[0] << endl;
}

template<class T>
void Skola<T>::najmanje() {
	cout << sale[top - 1] << endl;
}

template<class T>
void Skola<T>::Ispisi() {
	cout << "Sale:\n\n";
	for (int i = 0; i < top; i++)
		cout << "Sala" << i << endl << sale[i] << endl;
}

template<class T>
void Skola<T>::Sort() {
	int i;
	int j;
	for (i = 0; i < top - 1; i++) {
		for (j = i + 1; j < top; j++) {
			if (sale[i] > sale[j]) {
				T pom;
				pom = sale[i];
				sale[i] = sale[j];
				sale[j] = pom;
			}
		}
	}
}
