/*
Name: Eli Alen
E-mail address: eeallen1@go.olemiss.edu 
Course number and section: 390 section 1
Program number and title: Assignment 1 - Calculator
Honor Code: "In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
Description of the program: A calculator that takes two integers and performs an arithmetic operation (specified by the user) on them.  

*/


#include <iostream>
using namespace std; 

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b); 
void decide();

int main()
{
 int choice; 
 cout << "Welcome to Calculator. Select option from menu so you can Calulator.\n" << endl;
 cout << "Options with which you can Calculator:\n1: Addition\n2:Subtraction\n3:Mutiplication\n4:Division\n" << endl;
decide();

 
 }
 
 void decide(){
 int a, b, choice, result;
 char again;

 cout << "\nWhich two numbers do you want to Calculator please?\n" << endl; 
 cin >> a >> b; 
 cin.ignore();

 cout << "\nEnter your number choice of Caculator option to Calculator your number." << endl;
 cin >> choice;
 
 if(choice == 1){
 	result = add(a,b);
 }
 else if(choice == 2){
 	result = subtract(a,b);
}
 else if(choice == 3){
 	result = multiply(a,b);
 }
 else if (choice == 4){
 	result = divide(a,b);
 }
  else{
 cout << "\nWrong choice, Calculator again." << endl;
 decide(); 
}
if(result==0 && choice==4)
	cout <<"\nYou divided by 0, so Calculator can't Calculator." << endl;
else
cout <<"\nThe result of Calculator is: " << result << endl;
cout <<"\nCalculator again? (y/n)" << endl;
cin >> again;
if(again=='y' || again =='Y')
main();
}

int add(int a, int b){
return a + b; 
}

int subtract(int a, int b){
return a - b;
}

int multiply(int a, int b){
return a * b; 
}

int divide(int a, int b){
if(b != 0)
return a / b;
else{
cout << "\nCALCULATOR DIVIDE BY 0 ERROR" << endl;
return 0; 
}

}

