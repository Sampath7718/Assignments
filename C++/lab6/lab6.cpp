/* o	Eli Allen 
o	eeallen1@go.olemiss.edu 
o	CSCI 390 
o	Lab6 
o	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
o	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */
 
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;
void printValue(int*); 
void printAddress(int*);
void printAddressPointedTo(int*);
void swapValues(int*, int*);
void assignInt(int*, int);

 int main(){
 
 int intArray[10]; 
 
 for(int i = 0; i < 10; ++i){
	intArray[i] = i+1; 
 }
 
 int* pointer = &intArray[0];
 

 
 for(int i = 0; i < 10; ++i){
	cout << "Value of number " << (i+1) <<": "; 
	printValue((int*)(pointer+i));  
 }
 
for(int i = 0; i < 10; ++i){
	cout << "Addresses of index number " << (i+1) << ": ";
	printAddressPointedTo((int*)(pointer+i));
}

cout << "\nAddress of pointer is " << &pointer <<"\n" << endl;


cout << "\nSwapping the 3rd and 7th numbers, which are " << intArray[3] <<  " and " << intArray[7] << " respectively " << endl;
swapValues((int*)(pointer+3), (int*)(pointer+7)); 
cout << "After the swap, the 3rd and 7th numbers are " << intArray[3] <<  " and " << intArray[7] << " respectively " << endl;
 
assignInt((int*)(pointer+9), 77); 
cout << "\nThe last value in the array is now " << intArray[9] << endl; 
  
}
 
 
 void printAddress(int* num){
 
 cout << &num << endl; 
 
 }
 
 void printAddressPointedTo(int* num){
 cout <<  num << endl;
 }
 
 void printValue(int* num){
  cout << *num << endl;
 }
 
 void swapValues(int* num, int* otherNum){
 int *temp = num;
 *num = *otherNum; 
 *otherNum = *temp; 
 
 }
 
 void assignInt(int* num, int newNum){
 *num = newNum; 
 
 }
 
 