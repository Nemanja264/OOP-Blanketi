#pragma once
#include <iostream>
using namespace std;

class Student 
{
private:
	char* ime;
	char* prezime;
	char* roditelj;
	float prosek;
public:
	Student();
	Student(const char* i, const char* p, const char* r, float pr);
	~Student();

	bool operator==(Student& s);
	friend ostream& operator<<(ostream& izlaz, Student& s);

};
