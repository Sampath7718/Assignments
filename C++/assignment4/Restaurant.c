/* 	Eli Allen 
	eeallen1@go.olemiss.edu 
	CSCI 390 
	Assignment4 
	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */

#include <stdio.h>
#include "Restaurant.h"




void new_restaurant( Employee *employees, Food * menu, char * name,  char * phone_num, char * special, Appliance * appliances, Customer* customers, Restaurant* r){
r->name=name;
r->employees = employees;
r->menu = menu;
r->appliances = appliances;
r->special = special;
r->phone_num = phone_num; 
r->customers = customers;
r->menu_size = 0;
r->employees_num = 0;
r->appliance_num = 0;
}

void restaurant_set_name(char * n, Restaurant*r){
	r->name = n;
}

void restaurant_set_customers(Customer* c, Restaurant* r){
	r->customers = c;
}
void restaurant_set_food(Food *f, int menu_size, Restaurant* r){
	r->menu = f;
	r->menu_size = menu_size; 
}

void restaurant_set_employees(Employee *e, int num, Restaurant*r){
	r->employees = e; 
	r->employees_num = num;
}

void restaurant_set_employees_num(int en, Restaurant*r){
	r->employees_num = en;
}

void restaurant_set_appliances(Appliance *a, Restaurant*r){
	r->appliances = a;
}

void restaurant_set_phone(char * p, Restaurant*r){
	r->phone_num = p;
} 

void restaurant_set_menu_size(int s, Restaurant*r){
	r->menu_size = s; 
}
char * restaurant_get_name(Restaurant*r){
	return r->name;
}

Customer* restaurant_get_customers(Restaurant*r){
	return r->customers;
}
int restaurant_get_employeesNum(Restaurant*r){
	return r->employees_num;
}
Employee* restaurant_get_employees(Restaurant*r){
	return r->employees;
}

Food* restaurant_get_food(Restaurant*r){
	return r->menu;
}
 
int restaurant_get_menuSize(Restaurant*r){
	return r->menu_size;
}

Appliance* restaurant_get_appliances(Restaurant*r){
	return r->appliances;
}

char * restaurant_get_phone(Restaurant*r){
	return r->phone_num;
}

char * restaurant_get_special(Restaurant*r){
	return r->special;
}

void restaurant_set_menuSize(int ms, Restaurant*r){
	r->menu_size = ms;
}
void restaurant_print_menu(Restaurant*r){
	int i; 
	for( i = 0; i < r->menu_size; ++i){
		 printf("%s\n",food_get_name(&(r->menu[i]))); 

	}

}

float restaurant_highest_paid(Restaurant*r){
	int i; 
	float highest = 0; 
	for( i = 0; i < r->employees_num; ++i){
		if(employee_get_wage(&(r->employees[i])) >= highest)
			highest = employee_get_wage(&(r->employees[i]));
	}
	return highest;
}

void restaurant_list_appliances(Restaurant*r){
int i; 
for(i = 0; i < r->appliance_num; ++i){
	printf("%d: %s \n", i, appliance_to_string(&(r->appliances[i]))); 
}
}
