/* o	Eli Allen 
o	eeallen1@go.olemiss.edu 
o	CSCI 390 
o	Lab5 
o	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
o	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */
#include <string>

using namespace std;

class Student
{

public:
	//Student();
	Student(string name, int age, int year, string major, double gpa);
	
	void setName(string n);
	void setAge(int a);
	void setYear(int y);
	void setMajor(string m);
	void setGpa(double g);
	
	string getName();
	string getMajor();
	int getAge();
	int getYear();
	double getGpa();
	string getRandomOrg();
	int getLucky();

	virtual void printInfo();
	 
private:
	
	string name, major;
	int age, year;
	double gpa;
	
};
	