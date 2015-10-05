/* 	Eli Allen 
	eeallen1@go.olemiss.edu 
	CSCI 390 
	Lab7 
	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
	int flag = 0;
    int num_chars;
	char cont; 
	char* buffer; 
	while(!flag){
		printf("HOW MANY CHARS YOU GOT?\n");
		scanf("%i", &num_chars);
		buffer = (char*)malloc(num_charsz+1);
		if(buffer== NULL) 
			exit(1); 
		printf("\nWHAT THE NAME IS?\n");
		//trust the user to not enter something too big
		scanf("%s", buffer); 
		printf("\nTHE NAME IS %s\n", buffer); 
		free(buffer); 
		printf("CONTINUE?(y/n)\n"); 
		scanf("%s", &cont);
		if(cont == 'y')
			flag = 0; 
		else 
			flag = 1; 
	}
	
		return 1; 
		





}