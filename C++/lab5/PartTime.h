/* o	Eli Allen 
o	eeallen1@go.olemiss.edu 
o	CSCI 390 
o	Lab5 
o	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
o	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */

#ifndef _STUDENT_HEADER
#include "Student.h"
#define _STUDENT_HEADER
#endif
class PartTime : public Student {
public:
	
	PartTime(string name, int age, int year, string major, double gpa,  string occupation, int hours, int tuitionPerClass = 1400 );
	
	
	void setOccupation(string o);
	void setHours(int h);
	void setTuitionPerClass(int t);
	
	string getOccupation();
	int getHours();
	int getTuitionPerClass();
	
	int calculateBill();
	void calculateBudget(int salary); 

	void printInfo();
	 
private:
	
	string name, major, occupation;
	int age, year, hours, tuitionPerClass;
	double gpa;
	bool onCampus;
};