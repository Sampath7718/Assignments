/*

Eli Allen
Lab3 CSCI 390
I didn't cheat

*/


#include <iostream>
#include <string>
#include <stdlib.h>
#include "Student.h"
#include "inputVal.h"

using namespace std;


int main()
{

	Student s;
	
	string namein, majorin, input;
	int agein, yearin;
	double gpain;
	bool cont = false; //to see if the user wants to try again
	
	cout << "Student name?" << endl;
	cin >> namein;
	cin.ignore();
	s.setName(namein);
	
	while(cont==false){
	cout << "Student major?" << endl;
	//cin >> majorin;
	getline(cin, majorin);
	if(Major(majorin)){
	s.setMajor(majorin);
	cont = true;
	}
	else{
		cout << "Bad input. Try again?(y/n)" << endl;
		getline(cin, input);
		if(input == "y" || input == "yes" || input == "Y" || input == "Yes")
			cont=false;
		else
			exit(0);
		}
	}
	
	//reset cont
	cont = false;
	
	while(cont==false){
	cout << "Student age?" << endl;
	//cin >> agein;
	getline(cin, input);
	agein = format_string<int>(input);
	if(Age(agein)){
		s.setAge(agein);
		cont = true;
	}
	else{
		cout << "Bad input. Try again?(y/n)" << endl;
		getline(cin, input);
		if(input == "y" || input == "yes" || input == "Y" || input == "Yes")
			cont=false;
		else
			exit(0);
		}
	}
	
	cont=false;
	
	while(cont==false){
	cout << "Student gpa?" << endl;
	//cin >> gpain;
	getline(cin, input);
	gpain = format_string<double>(input);
	if(GPA(gpain)){
		s.setGpa(gpain);
		cont = true;
	}
	else{
		cout << "Bad input. Try again?(y/n)" << endl;
		getline(cin, input);
		if(input == "y" || input == "yes" || input == "Y" || input == "Yes")
			cont=false;
		else
			exit(0);
		}
	}
	
	cont=false;
	
	//left this from lab2 because it wasn't specifically asked for validation in lab3
	cout << "Student year?" << endl;
	cin >> yearin; 
	cin.ignore();
	s.setYear(yearin);
	
	
	cout << s.getName() << " is a " << s.getAge() << " year old " << s.getMajor() << " major in year " << s.getYear() << " with a GPA of " << s.getGpa() <<"." << endl;
	//cout << s.getName() << " is a member of " << s.getRandomOrg() << " and his/her lucky number is " << s.getLucky() << endl;
	}
	
