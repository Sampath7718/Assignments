#include "Student.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <ctime>

using namespace std;


Student::Student(){
}

void Student::setName(string n){
	name = n;
}

int Student::getLucky(){
	srand(time(0));
	return rand() % 1000;
}

string Student::getRandomOrg(){
	srand(time(0));
	int choice = rand() % 4;
	cout << choice << endl;
	if(choice == 1)
		return "NAACP";
	if(choice == 2)
		return "ACM";
	if (choice == 3)
		return "Students for the Preservation of the Oxford Comma";
	else 
		return "Something went horribly wrong. This student is a member of nothing";

}
string Student::getName(){
	return name;
}

void Student::setMajor(string m){
	major = m;
} 

double Student::getGpa(){
	return gpa; 
}
string Student::getMajor(){
	return major;
}

void Student::setAge(int a){
	age = a;
}

int Student::getAge(){
	return age;
}

void Student::setYear(int y){
	year = y; 
}

int Student::getYear(){
	return year;
}

void Student::setGpa(double g){
	gpa = g; 
}


