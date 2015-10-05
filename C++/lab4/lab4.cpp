/* o	Eli Allen 
o	eeallen1@go.olemiss.edu 
o	CSCI 390 
o	Lab4 
o	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
o	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */


#include <iostream>
#include <string>
#include <stdlib.h>
#ifndef _UNI_HEADER
#include "University.h"
#define _UNI_HEADER
#endif
#ifndef _STUDENT_HEADER
#include "Student.h"
#define _STUDENT_HEADER
#endif

#define ENROLL_NUM 5


using namespace std; 

int main(){

int enrollment = ENROLL_NUM;
string name, location, phone_num;
Student students[ENROLL_NUM]; 
University uni(students, enrollment); 

string student_names[ENROLL_NUM] = {"John", "Joe", "Bo", "Sally", "Susie"};
int student_ages[ENROLL_NUM]; 
student_ages[0]=44;
student_ages[1]=95;
student_ages[2]=17;
student_ages[3]=19;
student_ages[4]=22; 

for(int i = 0; i < ENROLL_NUM; ++i){
students[i].setName( student_names[i]);
students[i].setAge( student_ages[i]);

} 



cout << "University info: " << uni.getName() << "; " << uni.getLocation() << "; " << uni.getPhone() << "; Enrollment: " << uni.getEnrollment() << endl;
cout << "All student names: " << endl;
uni.printNames();
cout << "Student average age: " << uni.avgAge() << endl;
return 0;


}