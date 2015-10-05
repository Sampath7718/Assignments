/* 	Eli Allen 
	eeallen1@go.olemiss.edu 
	CSCI 390 
	Lab Practical 
	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int* p1, int* p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{
    int x = 54;
	int i; 
    int arr[] = {10,9,8,1,2,3};

    int* p1;
    int* p2;

	p1 = &x; 
	*p1 = 42;   
	
	
	p2 = arr; 
	for( int i = 0; i < 6; ++i){
		for(int j = 0; j < 6; ++j){
			if(p2[j] > p2[i])
			{
				swap(p2[j], p2[i]); 
			}
	}	}

	cout << "X: " << x << endl;
	
    for(i=0;i<6;i++)
    {
        cout << "Array[" << i << "]: " << arr[i] << endl;
    }
}
