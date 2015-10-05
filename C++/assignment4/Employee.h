/* 	Eli Allen 
	eeallen1@go.olemiss.edu 
	CSCI 390 
	Assignment4 
	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */

#ifndef EMP_HEAD
#define EMP_HEAD

typedef struct 
{	
	char *name, *job, *phone_num;
	float wage;
	
}Employee;


void new_employee( char* job,  char* name, char* phone_num, float wage, Employee* e);
	
	//setters
	void employee_set_name(char* n, Employee* e);
	void employee_set_job(char* j, Employee* e);
	void employee_set_phone(char* p, Employee* e);
	void employee_set_wage(float s, Employee* e);
	//getters
	char* employee_get_name(Employee* e);
	char* employee_get_job(Employee* e);
	char* employee_get_phone(Employee* e);
	float employee_get_wage(Employee* e);
	
	void employee_profile(Employee* e);
#endif