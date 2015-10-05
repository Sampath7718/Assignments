/* 	Eli Allen 
	eeallen1@go.olemiss.edu 
	CSCI 390 
	Lab Practical 
	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */
#include <iostream>
#include <string>

using namespace std;

class JungleCreature
{
public:
	JungleCreature();

	virtual string call();
};

JungleCreature::JungleCreature(){}

string JungleCreature::call() {
	return "Generic animal call";
}

class Jaguar: JungleCreature
{
public:
	Jaguar();
	string call(){
		return "Meow"; } 
}; 
 
Jaguar:: Jaguar(){}

int main()
{
	JungleCreature c;
	Jaguar j;

	cout << c.call() << endl;
	cout << j.call() << endl;
}