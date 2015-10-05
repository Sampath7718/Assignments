/* 	Eli Allen 
	eeallen1@go.olemiss.edu 
	CSCI 390 
	Assignment4 
	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */
 

#include "Appliance.h"
#include <stdio.h>
#include <string.h>


void new_appliance(char* name, float price, char* description, Appliance* a){
a->name=name;
a->price=price;
a->description=description;
}

void appliance_set_name(char* n, Appliance* a){
	a->name = n;
}

void appliance_set_price(float j,Appliance* a){
	a->price = j;
}

void appliance_set_description(char* p,Appliance* a){
	a->description = p;
} 
	

char * appliance_get_name(Appliance* a){
	return a->name;
}


char* appliance_get_description(Appliance* a){
	return a->description;
}

float appliance_get_price(Appliance* a){
	return a->price;
}


char* appliance_to_string(Appliance* a){
char str[1000]; 
strcpy(str, "Name "); 
strcat(str, a->name); 
strcat(str, ", Description: ");
strcat(str, a->description); 

}



