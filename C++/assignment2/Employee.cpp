/* o	Eli Allen 
o	eeallen1@go.olemiss.edu 
o	CSCI 390 
o	Lab4 
o	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
o	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */
 
#include <string>
#include <iostream>
#ifndef _EMP_HEAD
#include "Employee.h"
#define _EMP_HEAD
#endif



using namespace std;


Employee::Employee(string job, string name, string phone_num, float wage){
this->name=name;
this->job=job;
this->wage = wage;
this->phone_num = phone_num; 
}

void Employee::setName(string n){
	name = n;
}


void Employee::setWage(float s){
	wage = s;
}

void Employee::setPhone(string p){
	phone_num = p;
} 

void Employee::setJob(string j){
	job = j;
}
	

string Employee::getName(){
	return name;
}


string Employee::getPhone(){
	return phone_num;
}

string Employee::getJob(){
	return job;
}

float Employee::getWage(){
	return wage;
}

void Employee::employeeProfile(){
	cout << "Name: " << name << ", Job: " << job << ", Wage: " << wage << ", Phone number: " << phone_num; 
}
