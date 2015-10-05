/* 	Eli Allen 
	eeallen1@go.olemiss.edu 
	CSCI 390 
	Assignment4 
	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */

#ifndef APP_HEAD
#define APP_HEAD

typedef struct 
{	
	char *name, *description;
	float price;
	
}Appliance;

void new_appliance(char* name, float price, char* description, Appliance* a);
void appliance_set_name(char* n, Appliance* a);
void appliance_set_price(float j,Appliance* a);
void appliance_set_description(char* p,Appliance* a);
	

char * appliance_get_name(Appliance* a);
float appliance_get_price(Appliance* a);
char* appliance_get_description(Appliance* a);
	
char* appliance_to_string(Appliance* a);
#endif