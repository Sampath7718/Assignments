/* 	Eli Allen 
	eeallen1@go.olemiss.edu 
	CSCI 390 
	Assignment4 
	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */

#ifndef FOOD_HEAD
#define FOOD_HEAD


typedef struct 
{
	char *name, *recipe;
	float price;	
}Food;


	void new_food(float price, char* name, char* recipe, Food* f);
	
	void food_set_name(char* n,Food* f);
	void food_set_recipe(char* j,Food* f);
	void food_set_price(float p,Food* f);

	char* food_get_name(Food* f);
	char* food_get_recipe(Food* f);
	float food_get_price(Food* f);

	void food_print_item(Food* f);
	

#endif