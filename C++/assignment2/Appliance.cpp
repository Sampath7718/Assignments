/* o	Eli Allen 
o	eeallen1@go.olemiss.edu 
o	CSCI 390 
o	Lab4 
o	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
o	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */
 
#include <string>
#include <iostream>
#ifndef _APP_HEAD
#include "Appliance.h"
#define _APP_HEAD
#endif



using namespace std;


Appliance::Appliance( string name, float price, string description){
this->name=name;
this->price=price;
this->description=description;
}

void Appliance::setName(string n){
	name = n;
}


void Appliance::setPrice(float s){
	price = s;
}

void Appliance::setDescription(string d){
	description = d;
} 
	

string Appliance::getName(){
	return name;
}


string Appliance::getDescription(){
	return description;
}

float Appliance::getPrice(){
	return price;
}


string Appliance::toString(){
return "Name: " + name + ", Description: " + description; 

}



