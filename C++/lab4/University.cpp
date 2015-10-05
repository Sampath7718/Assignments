/* o	Eli Allen 
o	eeallen1@go.olemiss.edu 
o	CSCI 390 
o	Lab4 
o	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
o	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */

#ifndef _UNI_HEADER
#include "University.h"
#define _UNI_HEADER
#endif
#include <string>
#include <stdlib.h>
#include <iostream>


using namespace std;


University::University(Student *students, int enrollment, string name,  string location, string phone_num){
this ->name=name;
this->enrollment = enrollment;
this->students = students;
this->location = location;
this->phone_num = phone_num; 
}

void University::setName(string n){
	name = n;
}

void University::setEnrollment(int e){
	enrollment = e; 
}

void University::setStudents(Student *s){
	students = s;
}
void University ::setLocation(string s){
	location = s;
}

void University::setPhone(string p){
	phone_num = p;
} 
string University::getName(){
	return name;
}

int University::getEnrollment(){
	return enrollment;
}

Student* University::getStudents(){
	return students;
}

string University::getLocation(){
	return location;
}

string University::getPhone(){
	return phone_num;
}

void University::printNames(){
	for(int i = 0; i < enrollment; ++i){
		cout << students[i].getName() << endl; 

	}

}

int University::avgAge(){
	double total = 0; 
	for(int i = 0; i < enrollment; ++i){
		total+= students[i].getAge();
	}
	return total/enrollment; 
}

