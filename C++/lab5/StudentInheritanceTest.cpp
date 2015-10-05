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

#ifndef _GRADUATE_HEADER
#include "Graduate.h"
#define _GRADUATE_HEADER
#endif

#ifndef _PartTime_HEADER
#include "PartTime.h"
#define _PartTime_HEADER
#endif

#ifndef _FULLTIME_HEADER
#include "FullTime.h"
#define _FULLTIME_HEADER
#endif

#include <string>
#include <stdlib.h>
#include <iostream>

int main(){
Student *students[3];
students[0] = new PartTime("Megaman Allen", 22, 4, "Robotics", 4.0, "Vigilante Robot",9);
students[1] = new FullTime("Rockman Allen", 25, 3, "Geology", 2.2,  2200);
students[2] = new Graduate("Manman Allen", 44, 2, "Cooking", 1.2,  "Frozen Burritos", "Microwave operator",4);



for(int i = 0; i < 3; ++i){
	cout<< "Student number " << (i+1) << endl;
	students[i]->printInfo();
	cout<<endl;
}


}