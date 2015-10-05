#include <iostream>
#include <sstream>
#include <string>
#include "inputVal.h"

using namespace std;

int ARRAY_LENGTH = 4;

bool GPA(double gpa){
	if(gpa >= 0 && gpa <= 4)
	return true;
	else 
	return false; 

}

bool Age(int age){
	if(age>=0 && age <=200)
	return true;
	else
	return false;
}

bool Major(string major){
	string accepted[] = {"Computer Science", "Physics", "Psychics", "Jigsaw Puzzles"};
	
	for(int i = 0; i < ARRAY_LENGTH; ++i){
		if(major == accepted[i])
			return true; 
	}
	return false; 
}

bool Name(string name){
	//todo
	return true;

}

/*int main() {
	string input;

	cout << "Please input a value" << endl;

	getline(cin, input);

	int i = format_string<int>(input);
	double d = format_string<double>(input);
	string s = format_string<string>(input);

	cout << "String to number for int returned: " << i << endl;
	cout << "String to number for double returned: " << d << endl;
	cout << "String to number for string returned: " << s << endl;
}*/
