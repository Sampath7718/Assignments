/* o	Eli Allen 
o	eeallen1@go.olemiss.edu 
o	CSCI 390 
o	Assignment 2 
o	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
o	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */

#include <string>

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

#ifndef _Cust_HEAD
#include "Customer.h"
#define _CUST_HEAD
#endif

using namespace std;

class Restaurant
{

public:
	
	Restaurant( Employee *employees, Food * menu, string name,  string phone_num, string special, Appliance * appliances, Customer* customers);
	
	void setName(string n);
	void setFood(Food *f, int menu_size);
	void setEmployees(Employee *e, int num);
	void setSpecial(string s);
	void setPhone(string p);
	void setAppliances(Appliance *a);
	void setCustomers(Customer* c);
	void setMenuSize(int ms);
	void setEmployeesNum(int en);
	
	Appliance* getAppliances();
	string getName();
	Food* getFood();
	Employee* getEmployees();
	string getSpecial();
	string getPhone();
	Customer* getCustomers();
	
	int getEmployeesNum();
	int getMenuSize();
	void printMenu();
	float highestPaid(); //return salary of highest paid employee
	void listAppliances();
	 
private:
	
	string name, special, phone_num;
	Food *menu;
	Employee *employees;
	Appliance * appliances;
	Customer* customers;
	int menu_size, employees_num, appliance_num;
	
};
	