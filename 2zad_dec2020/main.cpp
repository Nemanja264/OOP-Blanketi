#include <iostream>
#include <fstream>
#include "Preduzeca.h"
#include "Donacije.h"
#include <random>
using namespace std;

int main()
{
	try {
		Donacije<int>* anonimno = new Donacije<int>(6);

		random_device rd;
		mt19937 br(rd());
		uniform_int_distribution<int> range(1000, 50000);

		for (int i = 0; i < 6; i++) {
			int svota = range(br);
			anonimno->Dodaj(svota);
		}

		anonimno->Ispisi();

		anonimno->Sacuvaj("anonimno.txt");
		int min = 0;
		int max = 0;
		anonimno->MinMax(&min, &max);

		cout << "Najmanja donacija: " << min << endl;
		cout << "Najveca donacija: " << max << endl;

		anonimno->Obrisi(4);
		anonimno->Ispisi();

		anonimno->Ukupno();
		int vece = anonimno->VeceOd(10000);
		cout << "Broj donacija vecih od 10000RSD: " << vece << endl;

		delete anonimno;

		Donacije<int>* anonimno2 = new Donacije<int>(6);
		anonimno2->Ucitaj("anonimno.txt");

		anonimno2->Ispisi();

	}
	catch (const char* poruka) {
		cout << poruka << endl;
	}
	try {
		Donacije<Preduzece>* neanonimno = new Donacije<Preduzece>(4);

		cout << endl;
		random_device rd;
		mt19937 br(rd());
		uniform_int_distribution<int> mbr(10000000, 10000100);
		uniform_int_distribution<int> tip(100000, 109000);
		uniform_int_distribution<int> svota(1000, 50000);

		Preduzece* p1 = new Preduzece(mbr(br),tip(br),svota(br));
		Preduzece* p2 = new Preduzece(mbr(br),tip(br),svota(br));
		Preduzece* p3 = new Preduzece(mbr(br),tip(br),svota(br));
		Preduzece* p4 = new Preduzece(mbr(br),tip(br),svota(br));

		neanonimno->Dodaj(*p1);
		neanonimno->Dodaj(*p2);
		neanonimno->Dodaj(*p3);
		neanonimno->Dodaj(*p4);

		neanonimno->Ispisi();

		neanonimno->Sacuvaj("neanonimno.txt");
		Preduzece* min = new Preduzece();
		Preduzece* max = new Preduzece();
		neanonimno->MinMax(min, max);

		cout << "Najmanja donacija: " << endl << *min << endl;
		cout << "Najveca donacija: " << endl << *max << endl;

		neanonimno->Obrisi(2);
		neanonimno->Ispisi();

		neanonimno->Ukupno();
		int vece = neanonimno->VeceOd(8000);
		cout << "Broj donacija veci od 8000RSD: " << vece << endl;

		delete neanonimno;

		cout << endl;
		Donacije<Preduzece>* neanonimno2 = new Donacije<Preduzece>(4);
		neanonimno2->Ucitaj("neanonimno.txt");

		neanonimno2->Ispisi();
	}
	catch (const char* poruka) {
		cout << poruka << endl;
	}
}
