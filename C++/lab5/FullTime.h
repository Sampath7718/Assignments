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


class FullTime : public Student {

public:
	
	FullTime(string name, int age, int year, string major, double gpa,  int scholarship, bool onCampus =false, int tuitionPerSemester = 6150 );
	
	
	void setOnCampus(bool c);
	void setScholarship(int s);
	void setTuitionPerSemester(int t);
	
	bool isOnCampus();
	int getScholarship();
	int getTuitionPerSemester();
	string getDorm();
	
	void payTuitionWithScholarship();
	void moveOnCampus(string d); 

	void printInfo();
	 
private:
	
	string name, major, dorm;
	int age, year, scholarship, tuitionPerSemester;
	double gpa;
	bool onCampus;
};