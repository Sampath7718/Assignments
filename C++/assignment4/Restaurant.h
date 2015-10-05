/* 	Eli Allen 
	eeallen1@go.olemiss.edu 
	CSCI 390 
	Assignment4 
	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */
 
 
#ifndef REST_HEAD
#define REST_HEAD
#include "Appliance.h"
#include "Customer.h"
#include "Employee.h"
#include "Food.h"


typedef struct
{

	 
	char *name, *special, *phone_num;
	Food *menu;
	Employee *employees;
	Appliance * appliances;
	Customer* customers;
	int menu_size, employees_num, appliance_num;
	
}Restaurant;

	void new_restaurant( Employee *employees, Food * menu, char * name,  char * phone_num, char * special, Appliance * appliances, Customer* customers, Restaurant* r);
	
	void restaurant_set_name(char * n, Restaurant*r);
	void restaurant_set_food(Food *f, int menu_size, Restaurant* r);
	void restaurant_set_employees(Employee *e, int num, Restaurant*r);
	void restaurant_set_special(char * s, Restaurant*r);
	void restaurant_set_phone(char * p, Restaurant*r);
	void restaurant_set_appliances(Appliance *a, Restaurant*r);
	void restaurant_set_customers(Customer* c, Restaurant*r);
	void restaurant_set_menuSize(int ms, Restaurant*r);
	void restaurant_set_employees_num(int en, Restaurant*r);
	
	Appliance* restaurant_get_appliances(Restaurant*r);
	char * restaurant_get_name(Restaurant*r);
	Food* restaurant_get_food(Restaurant*r);
	Employee* restaurant_get_employees(Restaurant*r);
	char * restaurant_get_special(Restaurant*r);
	char * restaurant_get_phone(Restaurant*r);
	Customer* restaurant_get_customers(Restaurant*r);
	
	int restaurant_get_employeesNum(Restaurant*r);
	int restaurant_get_menuSize(Restaurant*r);
	void restaurant_print_menu(Restaurant*r);
	float restaurant_highest_paid(Restaurant*r); //return salary of highest paid employee
	void restaurant_list_appliances(Restaurant*r);
	
#endif