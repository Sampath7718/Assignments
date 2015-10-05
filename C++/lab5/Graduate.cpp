/* o	Eli Allen 
o	eeallen1@go.olemiss.edu 
o	CSCI 390 
o	Lab5 
o	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
o	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */

#ifndef _GRADUATE_HEADER
#include "Graduate.h"
#define _GRADUATE_HEADER
#endif
#include <string>
#include <stdlib.h>
#include <iostream>

Graduate::Graduate(string name, int age, int year, string major, double gpa,  string thesisTopic, string job, int jobHoursPerWeek, int tuition) 
: Student(name, age, year, major, gpa){
this->jobHoursPerWeek = jobHoursPerWeek;
this->tuition = tuition;
this->thesisTopic = thesisTopic;
this->job = job;
}

	void Graduate::setThesisTopic(string t){
		thesisTopic = t;
	}
	void Graduate::setJob(string j){
		job = j;
	}
	void Graduate::setjobHoursPerWeek(int h){
		jobHoursPerWeek = h;
	}
	void Graduate::setTuition(int t){
		tuition = t;
	}
	
	string Graduate::getThesisTopic(){
		return thesisTopic;
	}
	string Graduate::getJob(){
		return job;
	}
	int Graduate::getJobHoursPerWeek(){
		return jobHoursPerWeek;
	}
	int Graduate::getTuition(){
		return tuition;
	}
	
	int Graduate::calculatePaycheck(){
		
		return jobHoursPerWeek * 10; 
		}
	void Graduate::calculateMoneyOwed(int weeksWorked){
		cout << "Because this university is great, you get paid for every hour you work, and we take that much off of your tuition bill" << endl;
		int balance = tuition - (weeksWorked * calculatePaycheck()); 
		cout << "And since you worked " << weeksWorked << ", your tuition cost is now $" << balance << endl;

	}

	void Graduate::printInfo(){
		Student::printInfo();
	cout <<"Thesis Topic:  "<<thesisTopic<< ", job: " << job << ", job hours per week: " <<jobHoursPerWeek << ", Tuition: " << tuition << endl;
	

}