/* o	Eli Allen 
o	eeallen1@go.olemiss.edu 
o	CSCI 390 
o	Assignment 2 
o	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
o	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */

#include <string>

using namespace std;

class Employee
{

public:
	
	Employee( string job, string name, string phone_num, float wage);
	
	//setters
	void setName(string n);
	void setJob(string j);
	void setPhone(string p);
	void setWage(float s);
	//getters
	string getName();
	string getJob();
	string getPhone();
	float getWage();
	
	void employeeProfile();
	 
private:
	
	string name, job, phone_num;
	float wage;
	
};