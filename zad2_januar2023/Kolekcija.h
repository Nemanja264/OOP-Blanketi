#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template<class T>
class Kolekcija {
private:
	T* dani;
	int top;
	int maxDana;
public:
	Kolekcija();
	Kolekcija(int maxel);
	~Kolekcija();

	friend ostream& operator<<(ostream& izlaz, Kolekcija<T>& t);

	void Unesi(T podaci);
	void Prosiri();
	void Obrisi(int X);
	int brPosetilaca();
	void NajmZarada(int* dan1,int* dan2);
	void Sacuvaj(const char* file);
	void Ucitaj(const char* file);
	void Ispisi();
};

template<class T>
Kolekcija<T>::Kolekcija() {
	top = 0;
	maxDana = 0;
	dani = nullptr;
}

template<class T>
Kolekcija<T>::Kolekcija(int maxel) {
	top = 0;
	maxDana = maxel;
	dani = new T[maxDana];
	for (int i = 0; i < maxDana; i++)
		dani[i] = T();
}

template<class T>
Kolekcija<T>::~Kolekcija() {
	if (dani != nullptr) {
		delete[] dani;
		dani = nullptr;
	}
}

template<class T>
int Kolekcija<T>::brPosetilaca() {
	int dan1, dan2;
	cout << "Unesi rbr 2 dana: ";
	cin >> dan1 >> dan2;

	if (dan1<0 || dan2>top - 1) {
		throw "Uneli ste nevalidne dane!\n";
	}
	else
	{
		int ukupno = 0;
		for (int i = dan1; i < dan2+1; i++)
			ukupno = dani[i] + ukupno;

		cout << "Ukupan broj posetilaca izmedju " << dan1 << " i " << dan2 << ": " << ukupno << endl;

		return ukupno;
	}
}

template<class T>
void Kolekcija<T>::Obrisi(int X) {
	if (X > top - 1) {
		throw "Broj dana koje treba obrisati je veci od trenutnog broja dana u kolekciji!\n";
	}
	else {
		for (int i = 0; i < top - X; i++)
			dani[i] = dani[i + X];
		top = top - X;
	}
}

template<class T>
void Kolekcija<T>::Unesi(T podaci) {
	dani[top++] = podaci;
	
	if (top == maxDana) {
		Prosiri();
	}
}

template<class T>
void Kolekcija<T>::Prosiri() {
	int newMax = maxDana + maxDana / 2;
	T* dani2;
	dani2 = new T[newMax];

	for (int i = 0; i < top; i++)
		dani2[i] = dani[i];

	delete[] dani;
	maxDana = newMax;
	dani = new T[maxDana];

	for (int i = 0; i < top; i++)
		dani[i] = dani2[i];

	delete[] dani2;
}

template<class T>
void Kolekcija<T>::NajmZarada(int* dan1, int* dan2) {
	*dan1 = 0;

	for (int i = 1; i < top; i++)
		if (dani[*dan1] > dani[i])
			*dan1 = i;

	*dan2 = 0;
	if (*dan2 == *dan1)
		*dan2 = 1;
	for (int i = 1; i < top; i++) {
		if (i != *dan1 && dani[*dan2] > dani[i]) 
				*dan2 = i;
	}
}

template<class T>
void Kolekcija<T>::Ucitaj(const char* file) {
	ifstream ucitaj(file);
	if (ucitaj.good()) {
		for (int i = 0; i < top; i++)
			ucitaj >> dani[i];
	}
	else
	{
		throw "Greska pri otvaranju fajla!\n";
	}
}

template<class T>
void Kolekcija<T>::Sacuvaj(const char* file) {
	ofstream upisi(file);
	if (upisi.good()) {
		for (int i = 0; i < top; i++)
			upisi << dani[i] << " ";
	}
	else
	{
		throw "Greska pri otvaranju fajla!\n";
	}
}

template<class T>
ostream& operator<<(ostream& izlaz, Kolekcija<T>& t) {
	izlaz << "Sadrzaj kolekcije:\n";
	for (int i = 0; i < t.top; i++)
		izlaz << "Dan" << i << " broj posetioca:\n" << t.dani[i] << endl;
}

template<class T>
void Kolekcija<T>::Ispisi() {
	cout << "Sadrzaj kolekcije:\n";
	for (int i = 0; i < top; i++)
		cout << "\nDan" << i << " broj posetioca:\n" << dani[i] << endl;
}
