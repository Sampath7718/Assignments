/* 	Eli Allen 
	eeallen1@go.olemiss.edu 
	CSCI 390 
	Assignment4 
	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */
 
#include "Food.h"
#include <stdio.h>

void new_food( float price, char* name, char* recipe, Food* f){

f->name=name;
f->price=price;
f->recipe=recipe; 
}

void food_set_name(char* n,Food* f){
	f->name = n;
}


void food_set_price(float p,Food* f){
	f->price = p;
}

void food_set_recipe(char* r,Food* f){
	f->recipe = r;
} 


char* food_get_name(Food* f){
	return f->name;
}


char* food_get_recipe(Food* f){
	return f->recipe;
}

float food_get_price(Food* f){
	return f->price;
}


void food_print_item(Food* f){
printf("Food name: %s\nFood recipe: %s", f->name, f->recipe); 
}
