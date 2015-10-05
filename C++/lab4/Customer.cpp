/* o	Eli Allen 
o	eeallen1@go.olemiss.edu 
o	CSCI 390 
o	Lab4 
o	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
o	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */
 
#include <string>
#include <iostream>
#ifndef _Cust_HEAD
#include "Customer.h"
#define _CUST_HEAD
#endif



using namespace std;


Customer::Customer(int age, string name, string phone_num, Food* order){
this->name=name;
this->age=age;
this->order = order;
this->phone_num = phone_num; 
}

void Customer::setName(string n){
	name = n;
}


void Customer::setAge(int s){
	age = s;
}

void Customer::setPhone(string p){
	phone_num = p;
} 

void Customer::setOrder(Food* j){
	order = j;
}
	

string Customer::getName(){
	return name;
}


string Customer::getPhone(){
	return phone_num;
}

int Customer::getAge(){
	return age;
}

Food* Customer::getOrder(){
	return order;
}



