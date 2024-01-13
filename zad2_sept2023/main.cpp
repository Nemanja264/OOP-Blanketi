#include "Prodavnica.h"
#include "Proizvod.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <random>
using namespace std;

int main() {
	try {
		random_device rd;
		mt19937 br(rd());
		uniform_real_distribution<float> range(10.0, 400.00);

		Prodavnica<float>* p1 = new Prodavnica<float>("Hrana_za_pse", 1);

		for (int i = 0; i < 5; i++) {
			float cena = range(br);

			p1->Dodaj(cena);
		}

		p1->Ispisi();
		p1->Prodaj(2);

		float srVr = p1->SrednjaVr();
		cout << "Srednja vrednost proizvoda: " << srVr << endl;

		p1->Ispisi();
		p1->Upisi("hrana_za_pse.txt");
		delete p1;

		Prodavnica<float>* p2 = new Prodavnica<float>();
		p2->Ucitaj("hrana_za_pse.txt");

		p2->Ispisi();


	}
	catch (const char* poruka) {
		cout << poruka << endl;
	}
	try {
		Prodavnica<Proizvod>* s1 = new Prodavnica<Proizvod>("Supermarket", 3);
		Proizvod* pro1 = new Proizvod("ZutiCvet", 5, 955, 1);
		Proizvod* pro2 = new Proizvod("Heba", 20, 100, 3);
		Proizvod* pro3 = new Proizvod("Zvake", 19, 58, 8);
		Proizvod* pro4 = new Proizvod("Snickers", 10, 90, 4);
		Proizvod* pro5 = new Proizvod("Jaffa", 19, 120, 4);

		s1->Dodaj(*pro1);
		s1->Dodaj(*pro2);
		s1->Dodaj(*pro3);
		s1->Dodaj(*pro4);
		s1->Dodaj(*pro5);

		s1->Ispisi();
		s1->Prodaj(0);
		s1->Prodaj(4);
		s1->Upisi("supermarket.txt");
		delete s1;

		Prodavnica<Proizvod> s2;
		s2.Ucitaj("supermarket.txt");
		s2.Ispisi();
	}
	catch (const char* poruka)
	{
		cout << poruka << endl;
	}
}
