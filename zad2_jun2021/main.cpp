#include "Kolekcija.h"
#include "Banana.h"
#include <iostream>
#include <random>
using namespace std;

int main() {
	try {
		random_device rd;
		mt19937 br(rd());
		uniform_real_distribution<float> range(20, 150);

		Kolekcija<float>* realni = new Kolekcija<float>(6);

		for (int i = 0; i < 6; i++) {
			float tezina = range(br);
			realni->Dodaj(tezina);
		}

		realni->Ispisi();
		float prosek = realni->Prosek();
		cout << endl << "Prosek: " << prosek << endl << endl;

		realni->Izbaci(5);
		realni->Ispisi();
		cout << endl;

		delete realni;
	}
	catch (const char* poruka) {
		cout << poruka << endl;
	}
	try {
		Kolekcija<Banana>* plantaza = new Kolekcija<Banana>(4);

		Banana* b1 = new Banana(145,true,false);
		Banana* b2 = new Banana(110,true,false);
		Banana* b3 = new Banana(120,true,true);
		Banana* b4 = new Banana(175,false,false);

		plantaza->Dodaj(*b1);
		plantaza->Dodaj(*b2);
		plantaza->Dodaj(*b3);
		plantaza->Dodaj(*b4);

		plantaza->Ispisi();
		float pr = plantaza->Prosek();

		cout << "Prosek na plantazi: " << pr << endl << endl;

		plantaza->Izbaci(5);
		plantaza->Ispisi();

		delete plantaza;
	}
	catch (const char* poruka) {
		cout << poruka << endl;
	}
}
