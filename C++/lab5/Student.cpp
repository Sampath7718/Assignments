/* o	Eli Allen 
o	eeallen1@go.olemiss.edu 
o	CSCI 390 
o	Lab5 
o	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
o	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */

#ifndef _STUDENT_HEADER
#include "Student.h"
#define _STUDENT_HEADER
#endif
#include <string>
#include <stdlib.h>
#include <iostream>
#include <ctime>

using namespace std;

//Student::Student() {}
Student::Student(string name, int age, int year, string major, double gpa){
	this->name = name;
	this-> age=age;
	this->year = year;
	this-> major = major;
	this-> gpa = gpa;
}

void Student::setName(string n){
	name = n;
}

int Student::getLucky(){
	srand(time(0));
	return rand() % 1000;
}

string Student::getRandomOrg(){
	srand(time(0));
	int choice = rand() % 4;
	cout << choice << endl;
	if(choice == 1)
		return "NAACP";
	if(choice == 2)
		return "ACM";
	if (choice == 3)
		return "Students for the Preservation of the Oxford Comma";
	else 
		return "Something went horribly wrong. This student is a member of nothing";

}
string Student::getName(){
	return name;
}

void Student::setMajor(string m){
	major = m;
} 

double Student::getGpa(){
	return gpa; 
}
string Student::getMajor(){
	return major;
}

void Student::setAge(int a){
	age = a;
}

int Student::getAge(){
	return age;
}

void Student::setYear(int y){
	year = y; 
}

int Student::getYear(){
	return year;
}

void Student::setGpa(double g){
	gpa = g; 
}


 void Student::printInfo(){
	cout <<"Name: " << name << ", Age: "<< age<< ", Year: "<<year << ", Major: " << major << ", GPA: " << gpa << endl;
	
}