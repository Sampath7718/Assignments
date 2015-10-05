/* o	Eli Allen 
o	eeallen1@go.olemiss.edu 
o	CSCI 390 
o	Lab4 
o	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
o	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */
 
#include <string>
#include <iostream>
#ifndef _REST_HEAD
#include "Restaurant.h"
#define _REST_HEAD
#endif



using namespace std;


Restaurant::Restaurant( Employee *employees, Food * menu, string name,  string phone_num, string special, Appliance * appliances, Customer* customers){
this ->name=name;
this->employees = employees;
this->menu = menu;
this->appliances = appliances;
this->special = special;
this->phone_num = phone_num; 
this->customers = customers;
menu_size = 0;
employees_num = 0;
appliance_num = 0;
}

void Restaurant::setName(string n){
	name = n;
}

void Restaurant::setCustomers(Customer* c){
	customers = c;
}

void Restaurant::setEmployees(Employee* e, int num){
	employees = e; 
	employees_num = num;
}

void Restaurant::setEmployeesNum(int en){
	employees_num = en;
}
void Restaurant::setFood(Food * s, int menuSize){
	menu = s;
	this->menu_size = menu_size;
}
void Restaurant::setAppliances(Appliance* a){
	appliances = a;
}

void Restaurant::setPhone(string p){
	phone_num = p;
} 


string Restaurant::getName(){
	return name;
}

Customer* Restaurant::getCustomers(){
	return customers;
}
int Restaurant::getEmployeesNum(){
	return employees_num;
}
Employee* Restaurant::getEmployees(){
	return employees;
}

Food* Restaurant::getFood(){
	return menu;
}
 
int Restaurant::getMenuSize(){
	return menu_size;
}

Appliance* Restaurant::getAppliances(){
	return appliances;
}

string Restaurant::getPhone(){
	return phone_num;
}

string Restaurant::getSpecial(){
	return special;
}

void Restaurant::setMenuSize(int ms){
	menu_size = ms;
}
void Restaurant::printMenu(){
	for(int i = 0; i < menu_size; ++i){
		cout << "" << menu[i].getName()<< endl; 

	}

}

float Restaurant::highestPaid(){
	float highest = 0; 
	for(int i = 0; i < employees_num; ++i){
		if(employees[i].getWage() >= highest)
			highest = employees[i].getWage();
	}
	return highest;
}

void Restaurant::listAppliances(){
for(int i = 0; i < appliance_num; ++i){
	cout << i << ": " << appliances[i].toString() << "\n" << endl;
}
}
