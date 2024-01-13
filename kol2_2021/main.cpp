#include <iostream>
#include <fstream>
#include "Skola.h"
#include "Sport.h"
#include <random>
using namespace std;

int main() {
	try {
		random_device rd;
		mt19937 br(rd());
		uniform_int_distribution<int> range(4, 20);

		Skola<int>* umetnost = new Skola<int>(6);
		
		for (int i = 0; i < 5; i++) {
			int broj = range(br);
			umetnost->Dodaj(broj);
		}
		
		

		umetnost->najvrednija();
		umetnost->najmanje();

		umetnost->Ispisi();
		umetnost->Otkazi(2);
		umetnost->Ispisi();

		delete umetnost;
	}
	catch (const char* poruka) {
		cout << poruka << endl;
	}
	try {
		Skola<Sport>* sport = new Skola<Sport>(6);
		sport->Ucitaj("sport.txt");

		/*Sport* p2 = new Sport(14, 7, "Nike", 23451, (float)0.678);
		Sport* p3 = new Sport(10, 6, "Nike", 2151, (float)0.648);
		Sport* p4 = new Sport(14, 4, "Nike", 2151, (float)0.848);
		Sport* p5 = new Sport(12, 7, "Nike", 43451, (float)0.478);*/
			
		//sport->Dodaj(*p2);
		//sport->Dodaj(*p3);
		//sport->Dodaj(*p4);
		//sport->Dodaj(*p5);
		sport->Ispisi();

		sport->najmanje();
		sport->najvrednija();
		sport->Prosek();
		sport->Otkazi(1);
		
		sport->Ispisi();
		delete sport;
	
	}
	catch (const char* poruka) {
		cout << poruka << endl;
	}
}
