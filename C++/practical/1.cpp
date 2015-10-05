/* 	Eli Allen 
	eeallen1@go.olemiss.edu 
	CSCI 390 
	Lab Practical 
	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */
#include <iostream>
#include <string>

using namespace std;
class Chair
{
public:
	Chair(double w,string m);

	void setMaterial(string m);
	void setWeightLimit(double m);

	string getMaterial();
	double getWeightLimit();
private:
	string material; 
	double weightLimit; 
};


Chair::Chair(double w,string m){
this->weightLimit = w;
this->material = m;
}

void Chair::setMaterial(string m)
{
	material = m;
}

void Chair::setWeightLimit(double w)
{
	weightLimit = w;
}

string Chair::getMaterial()
{
	return material;
}

double Chair::getWeightLimit()
{
	return weightLimit;
}

int main()
{
	Chair d(12.3, "rock");

	cout << "initial values: " << d.getMaterial() << ", " << d.getWeightLimit() << endl;
	
	double WeightLimit_input;
	string Material_input;

	cout << "How heavy is this Chair?" << endl;
	cin >> WeightLimit_input;

	cin.ignore();

	cout << "What is the Chair's Material?" << endl;
	getline(cin,Material_input);

	d.setWeightLimit(WeightLimit_input);
	d.setMaterial(Material_input);

	//lolwut
	cout << d.getMaterial() << " is " << d.getWeightLimit() << " years old!" << endl;
}