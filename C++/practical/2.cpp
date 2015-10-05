/* 	Eli Allen 
	eeallen1@go.olemiss.edu 
	CSCI 390 
	Lab Practical 
	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */
#include <iostream>
#define ARRAY_SIZE 5
using namespace std;

void print_array(int arr[]){
	cout <<"array: " << endl;
	for(int i = 0; i < ARRAY_SIZE; ++i){
		cout << arr[i] << endl; 
	}
}
int main()
{
	//INITIALIZE arr2 HERE (USE PREPROCESSOR DIRECTIVE FOR ARRAY SIZE)
	int arr2[ARRAY_SIZE]; 
	for(int i=0;i<ARRAY_SIZE;i++)
	{
		cout << "Enter Array value for index " << i << endl;
		cin >> arr2[i];
	}

	print_array(arr2);
}