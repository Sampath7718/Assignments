/* 	Eli Allen 
	eeallen1@go.olemiss.edu 
	CSCI 390 
	Lab Practical 
	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* arr;

    arr = malloc(5 * sizeof(int)); 
	
	arr[0] = 1; 
	arr[1] = 2; 
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5; 	
    int i;
	puts("Starting first one"); 
    for(i=0;i<5;i++)
    {
        printf("array[%d]: %d\n", i, arr[i]);
    }

	
    //RELEASE DYNAMIC MEMORY
	free(arr); 
	
	puts("Starting second one"); 
    //NOW, ALLOCATE A NEW ARRAY (still use arr) OF SIZE 15
	 arr = malloc(15 * sizeof(int)); 
	//FILL IT IN WITH SOME VALUES
	for(i = 0; i < 15; ++i)
		arr[i] = i + 1; 
    for(i=0;i<15;i++)
    {
        printf("array[%d]: %d\n", i, arr[i]);
    }
	
	//RELEASE YOUR ALLOCATED MEMORY!
	free(arr); 
    return 0;
}
