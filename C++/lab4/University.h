/* o	Eli Allen 
o	eeallen1@go.olemiss.edu 
o	CSCI 390 
o	Lab4 
o	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
o	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */

#include <string>
#ifndef _STUDENT_HEADER
#include "Student.h"
#define _STUDENT_HEADER
#endif
using namespace std;

class University
{

public:
	
	University( Student *students, int enrollment, string name = "Flagship University",  string location = "South Side, USA", string phone_num="1800-111-1111");
	
	void setName(string n);
	void setEnrollment(int e);
	void setStudents(Student *s);
	void setLocation(string l);
	void setPhone(string p);
	
	string getName();
	int getEnrollment();
	Student* getStudents();
	string getLocation();
	string getPhone();
	
	void printNames();
	int avgAge(); 
	 
private:
	
	string name, location, phone_num;
	int enrollment;
	Student *students;
	
};
	