/* 	Eli Allen 
	eeallen1@go.olemiss.edu 
	CSCI 390 
	Lab7 
	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */

#include <stdio.h>
#include <stdlib.h>

void print_int(int i){
	printf("Your int is: [%d]\n", i); 
}

void print_float(float f){
	printf("Your float is: [%f]\n", f);
}

void print_string(char* s){
	printf("Your string is: [%s]\n", s); 
}


int main(int argc, char** argv){
	int i;
	//this logic assumes that floats will not be in the form x.0 and that numerical values will be greater than 0
	for(i = 1; i <= (argc-1); ++i){
		if(atof(argv[i]) !=0 && atof(argv[i]) > atoi(argv[i])){ 
			print_float(atof(argv[i])); 
		}
	    else if(atoi(argv[i]) !=0){ 
			print_int(atoi(argv[i])); 
		}
		else{
			print_string(argv[i]); 
		}
	}

return 0; 
}

