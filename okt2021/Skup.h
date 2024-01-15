#pragma once
#include <iostream>
using namespace std;

template<class T>
class Skup 
{
private:
	T* skup;
	int top;
	int maxEl;
public:
	Skup();
	Skup(int brEl);
	~Skup();

	void Dodaj(T& podatak);
	void DodajUniji(T& podatak);
	void Obrisi(T& element);
	Skup<T>& Unija(Skup<T>& skup1, Skup<T>& skup2);

	void Ispisi();
};

template<class T>
Skup<T>::Skup() {
	skup = nullptr;
	top = 0;
	maxEl = 0;
}

template<class T>
Skup<T>::Skup(int brEl) {
	top = 0;
	maxEl = brEl;
	skup = new T[maxEl];

	for (int i = 0; i < maxEl; i++)
		skup[i] = T();
}

template<class T>
Skup<T>::~Skup() {
	if (skup != nullptr) {
		delete[] skup;
		skup = nullptr;
	}
}

template<class T>
void Skup<T>::Dodaj(T& podatak) {
	if (top > 0) {
		bool dupl = false;
		for (int i = 0; i < top; i++) {
			if (skup[i] == podatak) {
				dupl = true;
			}
		}

		if (dupl) {
			throw "Duplikat!";
		}
		else
		{
			skup[top++] = podatak;
		}
	}
	else
	{
		skup[top++] = podatak;
	}
}

template<class T>
void Skup<T>::Obrisi(T& element) {
	bool ima = false;
	int index;
	for (int i = 0; i < top; i++) {
		if (skup[i] == element) {
			ima = true;
			index = i;
		}
	}
	if (ima) {
		for (int j = index; j < top - 1; j++)
			skup[j] = skup[j + 1];
		top--;
	}
	else
	{
		throw "Ne postoji takav element u skupu!";
	}
}

template<class T>
Skup<T>& Skup<T>::Unija(Skup<T>& skup1, Skup<T>& skup2) {
	Skup<T>* unija = new Skup<T>(skup1.top + skup2.top);

	for (int i = 0; i < skup1.top; i++) {
		unija->DodajUniji(skup1.skup[i]);
	}

	for (int i = 0; i < skup2.top; i++) {
			unija->DodajUniji(skup2.skup[i]);
	}

	return *unija;
}

template<class T>
void Skup<T>::Ispisi() {
	cout << "Skup:\n";
	for (int i = 0; i < top; i++)
		cout << skup[i] << endl;
}

template<class T>
void Skup<T>::DodajUniji(T& podatak) {
	if (top > 0) {
		bool dupl = false;
		for (int i = 0; i < top; i++) {
			if (skup[i] == podatak) {
				dupl = true;
			}
		}

		if (!dupl) {
			skup[top++] = podatak;
		}
		
	}
	else
	{
		skup[top++] = podatak;
	}
}
