/* o	Eli Allen 
o	eeallen1@go.olemiss.edu 
o	CSCI 390 
o	Lab5 
o	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
o	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */

#ifndef _PartTime_HEADER
#include "PartTime.h"
#define _PartTime_HEADER
#endif
#include <string>
#include <stdlib.h>
#include <iostream>

PartTime::PartTime(string name, int age, int year, string major, double gpa, string occupation,int hours, int tuitionPerClass) 
: Student(name, age, year, major, gpa){
this->hours = hours;
this->tuitionPerClass = tuitionPerClass;
this->occupation = occupation;
}

	void PartTime::setOccupation(string o){
	occupation = o;
	}
	void PartTime::setHours(int h){
		hours = h;
	}
	void PartTime::setTuitionPerClass(int t){
		tuitionPerClass = t;
	}
	
	string PartTime::getOccupation(){
		return occupation;
	}
	int PartTime::getHours(){
		return hours;
	}
	int PartTime::getTuitionPerClass(){
		return tuitionPerClass;
	}
	
	int PartTime::calculateBill(){
		return hours*tuitionPerClass;
	}
	void PartTime::calculateBudget(int salary){
		int budget = salary - calculateBill();
		cout << "After paying your tuition, you will have $" << budget << " to spend this year" << endl;

	
}

void PartTime::printInfo(){
	Student::printInfo();
	cout <<"occupation: "<<occupation<< ", hours: " << hours << ", Tuition per class: " <<tuitionPerClass << endl;
	
	}