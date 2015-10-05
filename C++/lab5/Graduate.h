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
class Graduate : public Student {
public:
	
	Graduate(string name, int age, int year, string major, double gpa,  string thesisTopic, string job, int jobHoursPerWeek, int tuition = 10500 );
	
	
	void setThesisTopic(string t);
	void setJob(string j);
	void setjobHoursPerWeek(int h);
	void setTuition(int t);
	
	string getThesisTopic();
	string getJob();
	int getJobHoursPerWeek();
	int getTuition();
	
	int calculatePaycheck();
	void calculateMoneyOwed(int weeksWorked); 

	void printInfo();
	 
private:
	
	string name, major, job, thesisTopic;
	int age, year, jobHoursPerWeek, tuition;
	double gpa;
	bool onCampus;
};