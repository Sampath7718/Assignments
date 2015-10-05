#include <string>

using namespace std;

class Student
{

public:
	
	Student();
	
	void setName(string n);
	void setAge(int a);
	void setYear(int y);
	void setMajor(string m);
	void setGpa(double g);
	
	string getName();
	string getMajor();
	int getAge();
	int getYear();
	double getGpa();
	string getRandomOrg();
	int getLucky();
	 
private:
	
	string name, major;
	int age, year;
	double gpa;
	
};
	