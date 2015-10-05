/* 	Eli Allen 
	eeallen1@go.olemiss.edu 
	CSCI 390 
	Lab Practical 
	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */
#include <stdio.h>
void boolPrint(int x)
{
	printf("BoolPrint will print: %d\n", x);
}

int main()
{
    int classNum = 34;

    double namespaceNum = 4.4;

    printf("ClassNum: %d, NamespaceNum: %f\n", classNum, namespaceNum);
	
	boolPrint(55);
	
	float tryNum,toNum,startNum,usingNum,thisNum,newNum,virtualNum,friendNum;
	
	tryNum = 5.5;
	toNum = 4.3;
	startNum = 3.3;
	usingNum = 1.4;
	thisNum = 6.7;
	newNum = 7.6;
	virtualNum = 2.2;
	friendNum = 7.0;

	printf("Here we go: %f %f %f %f %f %f %f %f\n", tryNum,toNum,startNum,usingNum,thisNum,newNum,virtualNum,friendNum);
	
    return 0;
}
