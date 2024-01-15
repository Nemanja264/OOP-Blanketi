#include "Skup.h"
#include "Student.h"
#include <string.h>
#include <iostream>
using namespace std;

int main() {
	try {
		Skup<int>* s1 = new Skup<int>(4);
		Skup<int>* s2 = new Skup<int>(6);
		Skup<int>* s3 = new Skup<int>(10);

		for (int i = 0; i < 4; i++) {
			cout << "Unesi broj: ";
			int broj;
			cin >> broj;
			s1->Dodaj(broj);
		}
		for (int i = 0; i < 6; i++) {
			cout << "Unesi broj: ";
			int broj;
			cin >> broj;
			s2->Dodaj(broj);
		}

		s1->Ispisi();
		int obrisi = 4;
		s1->Obrisi(obrisi);
		s1->Ispisi();

		s2->Ispisi();

		*s3 = s1->Unija(*s1, *s2); // rezultat
		s3->Ispisi();

	}
	catch (const char* poruka) {
		cout << poruka << endl;
	}
	try {
		Skup<Student>* st1 = new Skup<Student>(3);
		Skup<Student>* st2 = new Skup<Student>(4);
		Skup<Student>* st3 = new Skup<Student>(7);

		Student* student1 = new Student("Danilo", "Mitrovic", "Branko", (float)6.00);
		Student* student2= new Student("Marija", "Mitrovic", "Sinisa", (float)8.00);
		Student* student3 = new Student("Milos", "Todorovic", "Dusan", (float)7.00);
		Student* student4 = new Student("Branka", "Ilic", "Stevan", (float)9.00);
		Student* student5 = new Student("Darija", "Nikolic", "Dusan", (float)8.88);
		Student* student6 = new Student("Andrija", "Milosevic", "Tadija", (float)9.5);

		st1->Dodaj(*student1);
		st1->Dodaj(*student2);
		st1->Dodaj(*student6);
		st2->Dodaj(*student3);
		st2->Dodaj(*student1);
		st2->Dodaj(*student4);
		st2->Dodaj(*student5);

		st1->Ispisi();
		st2->Ispisi();

		*st3 = st1->Unija(*st1, *st2); // rezultat
		st3->Ispisi();
	}
	catch (const char* poruka) {
		cout << poruka << endl;
	}
}
