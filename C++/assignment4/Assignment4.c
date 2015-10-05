/* 	Eli Allen 
	eeallen1@go.olemiss.edu 
	CSCI 390 
	Assignment4 
	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */


#include "Appliance.h"
#include "Customer.h"
#include "Employee.h"
#include "Food.h"
#include "Restaurant.h"
#include <stdio.h>

int main()
{

 const int EMP_NUM =2;
 const int MENU_SIZE = 2;
 const int APP_NUM =3;
 const int CUST_NUM =2;

Employee employees[EMP_NUM];
new_employee("Fry Cook", "Spongebob", "18005555555", 2.05, &employees[0]);
new_employee("Cashier", "Squidward", "18005555555", 7.25, &employees[1]); 

Food menu [MENU_SIZE];
new_food(11.25, "Krabby Patty", "Low grade beef, bun", &menu[0]);
new_food(5.50, "Drink", "toilet water, food coloring", &menu[1]);

Appliance appliances[APP_NUM];
new_appliance("Grill", 0.00, "Stolen electric grill. If Plankton comes to ask about it, don't tell him we have it", &appliances[0]);
new_appliance("Cash Register", 2.00, "Low quality toy cash register. Funny munny not included", &appliances[1]);
new_appliance("Drink fountain", 6.00, "Cleverly disguised pump system that takes flushed toilet water, injects food coloring, and dispenses soda", &appliances[2]);

Customer customers[CUST_NUM];
new_customer( 29, "Patrick", "1111111111", &menu[0], &customers[0]);
new_customer(19, "Sandy", "12345678", menu, &customers[1]); 

Restaurant restaurant;
new_restaurant(employees, menu, "Krusty Krab", "18001234567", "Buy 2 Krabby Patties for $30.00, get a free drink!", appliances, customers, &restaurant);

restaurant_set_menu_size(MENU_SIZE, restaurant);

printf("Restaurant info:\nName: %s\nPhone number: %s\nSpecial: %s\n", restaurant_get_name(&restaurant), restaurant_get_phone(&restaurant), restaurant_get_special(&restaurant)); 


int i; 


puts("Menu: "); 
for(i = 0; i< MENU_SIZE; ++i){
	printf("%d: ", i+1); 
	food_print_item(&menu[i]); 
    puts(""); 
	}


puts("Employees: "); 
for(i = 0; i < EMP_NUM; ++i){
	printf("%d: ", i+1); 
	employee_profile(&employees[i]); 
	puts(""); 
	}
	
restaurant_set_employees_num(EMP_NUM, &restaurant);	
printf("Highest wage among employees: %f\n", restaurant_highest_paid(&restaurant)); 

puts("Appliances in use:"); 
for(i = 0; i < APP_NUM; ++i){
	printf("%d:\n%s\n", i+1, appliance_to_string(&appliances[i]));
	}

puts("Customers in store:"); 
for(i = 0; i < CUST_NUM; ++i){
	printf("%d:", i+1);
	customer_profile(&customers[i]); 
	puts(""); 
	}


return 0;
	
	}
	
