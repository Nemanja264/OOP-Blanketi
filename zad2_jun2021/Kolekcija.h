#pragma once
#include <iostream>
using namespace std;

template<class T>
class Kolekcija 
{
private:
	int maxEl;
	int top;
	T* kolekcija;
public:
	Kolekcija();
	Kolekcija(int brel);
	~Kolekcija();

	void Dodaj(T& podatak);
	void Izbaci(int procenat);
	float Prosek();

	void Ispisi();
};

template<class T>
Kolekcija<T>::Kolekcija() {
	top = 0;
	maxEl = 0;
	kolekcija = nullptr;
}

template<class T>
Kolekcija<T>::Kolekcija(int brel) {
	top = 0;
	maxEl = brel;
	kolekcija = new T[maxEl];
}

template<class T>
Kolekcija<T>::~Kolekcija() {
	if (kolekcija != nullptr) {
		delete[] kolekcija;
	}
}

template<class T>
void Kolekcija<T>::Dodaj(T& podatak) {
	if (top == maxEl) {
		throw "Kolekcija je puna!";
	}
	else
	{
		kolekcija[top++] = podatak;
	}
}

template<class T>
float Kolekcija<T>::Prosek() {
	float suma = 0;
	for (int i = 0; i < top; i++)
		suma = kolekcija[i] + suma;

	return (float)(suma / top);
}

template<class T>
void Kolekcija<T>::Izbaci(int procenat) {
	float prosek = Prosek();
	float proc = (float)procenat / 100;

	for (int i = 0; i < top; i++) {
		float odstupanje;
		odstupanje = kolekcija[i] / prosek;
		
		if (odstupanje >= 1)
			odstupanje = odstupanje - 1;
		else if (odstupanje < prosek)
			odstupanje = 1 - odstupanje;

		if (odstupanje > proc) {
			for (int j = i; j < top - 1; j++)
				kolekcija[j] = kolekcija[j + 1];
			top--;
			i--;
		}
	}
}

template<class T>
void Kolekcija<T>::Ispisi() {
	cout << "Kolekcija:\n";
	for (int i = 0; i < top; i++)
		cout << kolekcija[i] << endl;
}
