/* 	Eli Allen 
	eeallen1@go.olemiss.edu 
	CSCI 390 
	Assignment4 
	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */
 
 
#ifndef CUST_HEAD
#define CUST_HEAD
#include "Food.h"
typedef struct
{	
	char *name, *phone_num;
	int age;
	Food* order;
	
}Customer;


void new_customer( int age, char *name, char *phone_num, Food* order, Customer* c);
	
//setters
void customer_set_name(char *n, Customer* c);
void customer_set_age(int a,Customer* c);
void customer_set_phone(char* p, Customer* c);
void customer_set_order(Food* s, Customer* c);

//getters
char* customer_get_name(Customer* c);
int customer_get_age(Customer* c);
char* customer_get_phone(Customer* c);
Food* customer_get_order(Customer* c);
	
//toString
void customer_profile(Customer* c);
#endif