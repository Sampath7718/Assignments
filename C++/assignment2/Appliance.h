/* o	Eli Allen 
o	eeallen1@go.olemiss.edu 
o	CSCI 390 
o	Assignment 2 
o	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
o	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */

#include <string>

using namespace std;

class Appliance
{

public:
	
	Appliance( string name, float price, string description);
	
	void setName(string n);
	void setPrice(float j);
	void setDescription(string p);
	

	string getName();
	float getPrice();
	string getDescription();
	
	string toString();
	
	
	 
private:
	
	string name, description;
	float price;
	
};