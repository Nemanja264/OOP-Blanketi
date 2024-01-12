#include "IzlozbeniPosetioci.h"
#include "Kolekcija.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	try {
		int dan1;
		int dan2;
		Kolekcija<int> interaktivni(10);
		interaktivni.Unesi(11);
		interaktivni.Unesi(2);
		interaktivni.Unesi(34);
		interaktivni.Unesi(33);
		interaktivni.Unesi(44);

		interaktivni.Sacuvaj("interaktivni.txt");
		//interaktivni.Obrisi(6); // exception
		interaktivni.brPosetilaca();
		interaktivni.Ispisi();

		interaktivni.brPosetilaca(); // probati ovde exception napraviti

		interaktivni.NajmZarada(&dan1, &dan2);
		cout << "Dva dana sa najmanjoj zaradom su: " << dan1 << " i " << dan2 << endl;
		interaktivni.Obrisi(2);
		//cout << interaktivni << endl;
		interaktivni.Ispisi();
		
	}
	catch (const char* recenica) {
		cout << recenica;
	}
	try {
		Kolekcija<IzlozbeniPosetioci> izlozbeni(6);
		izlozbeni.Unesi(IzlozbeniPosetioci(1, 2, 3));
		izlozbeni.Unesi(IzlozbeniPosetioci(4, 2, 10));
		izlozbeni.Unesi(IzlozbeniPosetioci(1, 2, 0));
		izlozbeni.Unesi(IzlozbeniPosetioci(3, 1, 0));
		izlozbeni.Unesi(IzlozbeniPosetioci(4, 4, 4));
		izlozbeni.Unesi(IzlozbeniPosetioci(0, 0, 0));
		izlozbeni.Unesi(IzlozbeniPosetioci(1, 12, 0));

		izlozbeni.Ispisi();
		
		izlozbeni.Sacuvaj("cuvanje.txt");
		
		//izlozbeni.Obrisi(10); // exception

		izlozbeni.Obrisi(5);
		izlozbeni.Ispisi();
		izlozbeni.brPosetilaca();

		izlozbeni.Ucitaj("cuvanje.txt"); // ucitavamo podatke za prva dva dana(koja su bila pre brisanja) koje smo sacuvali pre toga u txt fajlu
		izlozbeni.Ispisi();
	}
	catch (const char* recenica) {
		cout << recenica;
	}
}
