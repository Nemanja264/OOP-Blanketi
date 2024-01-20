#include "Knjiga.h"
#include "CD.h"
#include "Polica.h"
#include <iostream>
#include <fstream>
#include <random>
using namespace std;

int main()
{
	try {
		random_device rd;
		mt19937 br(rd());
		uniform_int_distribution<int> v(100, 500);
		uniform_int_distribution<int> z(50, 100);

		Polica<CD>* pCD = new Polica<CD>(7);

		CD* cd1 = new CD(v(br), z(br));
		CD* cd2 = new CD(v(br), z(br));
		CD* cd3 = new CD(v(br), z(br));
		CD* cd4 = new CD(v(br), z(br));
		CD* cd5 = new CD(v(br), z(br));
		CD* cd6 = new CD(v(br), z(br));
		CD* cd7 = new CD(v(br), z(br));

		pCD->Dodaj(*cd1);
		pCD->Dodaj(*cd2);
		pCD->Dodaj(*cd3);
		pCD->Dodaj(*cd4);
		pCD->Dodaj(*cd5);
		pCD->Dodaj(*cd6);
		pCD->Dodaj(*cd7);

		pCD->Ispisi();

		// pCD->Izbaci(-2); // exception
		pCD->Izbaci(5);
		pCD->Ispisi();

		pCD->Sacuvaj("cd.txt");

		delete pCD;

		Polica<CD>* pCD2 = new Polica<CD>(7);
		pCD2->Ucitaj("cd.txt");

		pCD2->Ispisi();
	}
	catch (const char* poruka) {
		cout << poruka << endl;
	}
	try {
		cout << endl;
		random_device rd;
		mt19937 br(rd());
		uniform_int_distribution<int> str(100, 500);
		uniform_int_distribution<int> tr(200, 600);

		Polica<Knjiga>* pK = new Polica<Knjiga>(5);

		Knjiga* b1 = new Knjiga("The Great Gatsby", "F. Scott Fitzgerald",str(br),tr(br));
		Knjiga* b2 = new Knjiga("To Kill a Mockingbird", "Harper Lee", str(br), tr(br));
		Knjiga* b3 = new Knjiga("1984", "George Orwell", str(br), tr(br));
		Knjiga* b4 = new Knjiga("The Catcher in the Rye", "J.D. Salinger", str(br), tr(br));
		Knjiga* b5 = new Knjiga("Pride and Prejudice", "Jane Austen", str(br), tr(br));

		pK->Dodaj(*b1);
		pK->Dodaj(*b2);
		pK->Dodaj(*b3);
		pK->Dodaj(*b4);
		pK->Dodaj(*b5);

		pK->Ispisi();

		pK->Izbaci(2);
		// pK->Izbaci(7);  // exception
		pK->Ispisi();

		pK->Sacuvaj("knjiga.txt");
		delete pK;

		Polica<Knjiga>* pK2 = new Polica<Knjiga>(5);

		pK2->Ucitaj("knjiga.txt");
		pK2->Ispisi();
	}
	catch (const char* poruka) {
		cout << poruka << endl;
	}
}
