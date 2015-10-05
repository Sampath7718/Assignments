/* 	Eli Allen 
	eeallen1@go.olemiss.edu 
	CSCI 390 
	Lab Practical 
	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */
#include <stdio.h>

typedef struct{
	int RAM; 
	double speed; 
}PC; 

void setRam(int r, PC* p){
	p->RAM = r; 
}

void setSpeed(double s, PC* p){
	p->speed = s; 
}

int getRam(PC p){
	return p.RAM;  
}

double getSpeed(PC p){
	return p.speed;  
}

int main()
{
	PC p;

	setRam(2048, &p);
	setSpeed(7.5, &p);

	printf("This computer has %d MBs of memory and a %f GHz processor!", getRam(p), getSpeed(p));
}
