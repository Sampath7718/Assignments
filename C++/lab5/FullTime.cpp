/* o	Eli Allen 
o	eeallen1@go.olemiss.edu 
o	CSCI 390 
o	Lab5 
o	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
o	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */

#ifndef _FULLTIME_HEADER
#include "FullTime.h"
#define _FULLTIME_HEADER
#endif
#include <string>
#include <stdlib.h>
#include <iostream>

FullTime::FullTime(string name, int age, int year, string major, double gpa,  int scholarship, bool onCampus, int tuitionPerSemester) 
: Student(name, age, year, major, gpa)
{
this->onCampus = onCampus;
this->tuitionPerSemester = tuitionPerSemester;
this->scholarship=scholarship;
this->dorm = "off campus"; 
}

void FullTime::setOnCampus(bool c){
	this->onCampus = c;
}
void FullTime::setScholarship(int s){
	this->scholarship = s;
}

void FullTime::setTuitionPerSemester(int t){
	this->tuitionPerSemester = t;
}
	
bool FullTime::isOnCampus(){
	return onCampus;
}
int FullTime::getScholarship(){
	return scholarship;
}
int FullTime::getTuitionPerSemester(){
	return tuitionPerSemester;
}
string FullTime::getDorm(){
	return dorm;
}
	
void FullTime::payTuitionWithScholarship(){
	int balance;
	cout << "Current scholarship balance is $" << scholarship << " and tuition for this semester is $" << tuitionPerSemester << endl;
	balance = tuitionPerSemester - scholarship;
	if(balance < 0)
	balance = 0; 
	cout << "After scholarships are applied, this semester's tuition balance is $" << balance << endl;
	}
	
void FullTime::moveOnCampus(string d){
	setOnCampus(true);
	dorm = d; 

}

void FullTime::printInfo(){
	Student::printInfo();
	cout <<"Scholarship: "<<scholarship<< ", on campus: " << onCampus << ", Tuition per semester: " <<tuitionPerSemester << endl;
	
}