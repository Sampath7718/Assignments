/* 	Eli Allen 
	eeallen1@go.olemiss.edu 
	CSCI 390 
	Lab Practical 
	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */
#include <iostream>
#include <exception>

using namespace std;

void exception_function() {
	exception e;

	throw e;
}

int main() {
	try{
	exception_function();
	}
	catch(exception e)
	{
		cout << "Caught exception" << endl; 
	}
}