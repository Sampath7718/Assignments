/* o	Eli Allen 
o	eeallen1@go.olemiss.edu 
o	CSCI 390 
o	Lab4 
o	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
o	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */


#include <iostream>
#include <string>
#include <stdlib.h>

#ifndef _EMP_HEAD
#include "Employee.h"
#define _EMP_HEAD
#endif

#ifndef _FOOD_HEAD
#include "Food.h"
#define _FOOD_HEAD
#endif

#ifndef _APP_HEAD
#include "Appliance.h"
#define _APP_HEAD
#endif

#ifndef _REST_HEAD
#include "Restaurant.h"
#define _REST_HEAD
#endif

#ifndef _CUST_HEAD
#include "Customer.h"
#define _CUST_HEAD
#endif

 
using namespace std;


int main()
{

const int EMP_NUM =2;
 const int MENU_SIZE = 2;
 const int APP_NUM =3;
 const int CUST_NUM =2;

Employee employees[EMP_NUM] = { Employee("Fry Cook", "Spongebob", "18005555555", 2.05), Employee("Cashier", "Squidward", "18005555555", 7.25)};

Food menu [MENU_SIZE] = { Food(11.25, "Krabby Patty", "Low grade beef, bun"), Food(5.50, "Drink", "toilet water, food coloring")};

Appliance appliances[APP_NUM] = {Appliance("Grill", 0.00, "Stolen electric grill. If Plankton comes to ask about it, don't tell him we have it" ), Appliance("Cash Register", 2.00, "Low quality toy cash register. Funny munny not included"), Appliance("Drink fountain", 6.00, "Cleverly disguised pump system that takes flushed toilet water, injects food coloring, and dispenses soda")};

Customer customers[CUST_NUM] = {Customer( 29, "Patrick", "1111111111", &menu[0]), Customer(19, "Sandy", "12345678", menu)}; 

Restaurant restaurant(employees, menu, "Krusty Krab", "18001234567", "Buy 2 Krabby Patties for $30.00, get a free drink!", appliances, customers);

restaurant.setMenuSize(MENU_SIZE);


cout << "Restaurant info:\n" << "Name: " << restaurant.getName() << "\nPhone number: " << restaurant.getPhone() << "\nSpecial: " << restaurant.getSpecial() << endl;


cout << "Menu: " << endl;
for(int i = 0; i< MENU_SIZE; ++i){
	cout << i+1 << ": " << endl;
	menu[i].printItem();
	cout << "" << endl;
	}

cout << "Employees " << endl;
for(int i = 0; i < EMP_NUM; ++i){
	cout << i+1 << ": " << endl;
	employees[i].employeeProfile();
	cout << "" << endl;
	}
	
restaurant.setEmployeesNum(EMP_NUM);	
cout << "Highest wage among employees:" << restaurant.highestPaid()<< endl;


cout << "Appliances in use" << endl;
for(int i = 0; i < APP_NUM; ++i){
	
	cout << i+1 << ": \n" << appliances[i].toString() << endl;
	cout << "" << endl;
	}

cout << "Customers in store:" << endl; 
for(int i = 0; i < CUST_NUM; ++i){
	cout << i+1 << ": " << endl;
	customers[i].customerProfile();
	cout << "" << endl;
	}


return 1;
	
	}
	
