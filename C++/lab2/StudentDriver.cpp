#include <iostream>
#include <string>
#include "Student.h"

using namespace std;


int main()
{

	Student s;
	
	string namein, majorin;
	int agein, yearin;
	double gpain;
	
	cout << "Student name?" << endl;
	cin >> namein;
	cin.ignore();
	s.setName(namein);
	
	cout << "Student major?" << endl;
	cin >> majorin;
	cin.ignore();
	s.setMajor(majorin);
	
	cout << "Student age?" << endl;
	cin >> agein;
	cin.ignore();
	s.setAge(agein);
	
	cout << "Student gpa?" << endl;
	cin >> gpain;
	cin.ignore();
	s.setGpa(gpain);
	
	cout << "Student year?" << endl;
	cin >> yearin; 
	cin.ignore();
	s.setYear(yearin);
	
	
	cout << s.getName() << " is a " << s.getAge() << " year old " << s.getMajor() << " major in year " << s.getYear() << " with a GPA of " << s.getGpa() <<"." << endl;
	cout << s.getName() << " is a member of " << s.getRandomOrg() << " and his/her lucky number is " << s.getLucky() << endl;
	}