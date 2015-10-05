/* 	Eli Allen 
	eeallen1@go.olemiss.edu 
	CSCI 390 
	Assignment4 
	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */
 

#include "Employee.h"
#include <stdio.h>

void new_employee( char* job,  char* name, char* phone_num, float wage, Employee* e){
e->name=name;
e->job=job;
e->wage = wage;
e->phone_num = phone_num; 
}

void employee_set_name(char* n, Employee* e){
	e->name = n;
}


void employee_set_wage(float s, Employee* e){
	e->wage = s;
}

void employee_set_phone(char* p, Employee* e){
	e->phone_num = p;
} 

	void employee_set_job(char* j, Employee* e){
	e->job = j;
}
	

char* employee_get_name(Employee* e){
	return e->name;
}


char* employee_get_phone(Employee* e){
	return e->phone_num;
}

char* employee_get_job(Employee* e){
	return e->job;
}

float employee_get_wage(Employee* e){
	return e->wage;
}

void employee_profile(Employee* e){
	printf("Name: %s, Job: %s  Wage: %f, Phone number: %s", e->name, e->job, e->wage, e->phone_num); 
}
