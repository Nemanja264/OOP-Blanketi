#include "Film.h"
#include "Bioskop.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <random>
using namespace std;

int main()
{
	try {
		random_device rd;
		mt19937 br(rd());
		uniform_real_distribution<double> range(5.00, 10.00);

		Bioskop<double>* prvi = new Bioskop<double>(6, 5.00);

		for (int i = 0; i < 4; i++) {
			double MinOcena = range(br);
			prvi->Dodaj(MinOcena);
		}
		double ocena = 5.65;
		double min = 0;
		double max = 0;

		prvi->Dodaj(ocena);
		prvi->Ispisi();

		prvi->MinMax(&min, &max);
		cout << "Minimalna ocena " << min << endl;
		cout << "Maximalna ocena " << max << endl;

		prvi->Obrisi(2);
		prvi->Ispisi();

		prvi->PromeniOcenu(1, 4.85);
		prvi->Ispisi();

		prvi->PromeniOcenu(0, 5.65);
		prvi->Ispisi();

		int IstaOcena = prvi->brFilmova(5.65);
		cout << "Broj filmova sa istom ocenom: " << IstaOcena << endl;

		prvi->Sacuvaj("prvi.txt");

		delete prvi;

		Bioskop<double>* drugi = new Bioskop<double>(6, 5.00);
		
		drugi->Ucitaj("prvi.txt");
		drugi->Ispisi();
	}
	catch (const char* poruka) {
		cout << poruka << endl;
	}
	try {
		Bioskop<Film>* film = new Bioskop<Film>(6, 6.5);

		Film* f1 = new Film(101,"Inception",2010,8.8);
		Film* f2 = new Film(102, "The Shawshank Redemption",1994,9.3);
		Film* f3 = new Film(103, "La La Land",2016,8.0);
		Film* f4 = new Film(104, "Jurassic Park",1993,8.1);

		Film* f5 = new Film(105, "Now You See Me", 2013, 7.3);

		film->Dodaj(*f1);
		film->Dodaj(*f2);
		film->Dodaj(*f3);
		film->Dodaj(*f4);

		film->Dodaj(*f5);

		film->Ispisi();

		int oc = film->brFilmova(8.8);
		cout << "Broj filmova sa ocenom 8.8: " << oc << endl;

		
		film->MinMax(f1, f2);
		cout << "Minimalna ocena " << endl << *f1 << endl;
		cout << "Maximalna ocena " << endl << *f2 << endl;

		film->Sacuvaj("film.txt");

		film->Obrisi(2);
		film->Ispisi();

		film->PromeniOcenu(2, 6.4);
		film->Ispisi();

		delete film;	
	}
	catch (const char* poruka) {
		cout << poruka << endl;
	}
}
