/* 	Eli Allen 
	eeallen1@go.olemiss.edu 
	CSCI 390 
	Assignment4 
	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */
 
#include "Customer.h"
#include <stdio.h>
void new_customer( int age, char *name, char *phone_num, Food* order, Customer* c)
{
c->name=name;
c->age=age;
c->order = order;
c->phone_num = phone_num; 
}

void customer_set_name(char *n, Customer* c){
	c->name = n;
}


void customer_set_age(int a,Customer* c){
	c->age = a;
}

void customer_set_phone(char *p, Customer* c){
	c->phone_num = p;
} 

void customer_set_order(Food* s, Customer* c){
	c->order = s;
}
	

char* customer_get_name(Customer* c){
	return c->name;
}


int customer_get_age(Customer* c){
	return c->age;
}

char* customer_get_phone(Customer* c){
	return c->phone_num; 
}

Food* customer_get_order(Customer* c){
	return c->order;
}

void customer_profile(Customer* c){
	printf("Name: %s, Age: %i, Phone: %s", c->name, c->age, c->phone_num); 
}



