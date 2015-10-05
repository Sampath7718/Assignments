/* o	Eli Allen 
o	eeallen1@go.olemiss.edu 
o	CSCI 390 
o	Assignment 2 
o	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
o	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */

#include <string>
#ifndef _FOOD_HEAD
#include "Food.h"
#define _FOOD_HEAD
using namespace std;

class Customer
{

public:
	
	Customer( int age, string name, string phone_num, Food* order);
	
	void setName(string n);
	void setAge(string j);
	void setPhone(string p);
	void setOrder(Food* s);

	string getName();
	int getAge();
	string getPhone();
	Food* getOrder();
	
	 
private:
	
	string name, phone_num;
	int age;
	Food* order;
	
};