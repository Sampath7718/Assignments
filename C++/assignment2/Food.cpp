/* o	Eli Allen 
o	eeallen1@go.olemiss.edu 
o	CSCI 390 
o	Lab4 
o	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
o	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */
 
#include <string>
#include <iostream>
#ifndef _FOOD_HEAD
#include "Food.h"
#define _FOOD_HEAD
#endif



using namespace std;


Food::Food(float price, string name, string recipe){
this->name=name;
this->price = price;
this->recipe=recipe; 
}

void Food::setName(string n){
	name = n;
}


void Food::setPrice(float s){
	price = s;
}

void Food::setRecipe(string p){
	recipe = p;
} 

string Food::getName(){
	return name;
}


string Food::getRecipe(){
	return recipe;
}

float Food::getPrice(){
	return price;
}


void Food::printItem(){
cout << "Food name: " << name << "\nFood recipe: " << recipe << endl;
}
