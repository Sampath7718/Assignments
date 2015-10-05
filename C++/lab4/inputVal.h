#include <string>
#include <iostream>
#include <sstream>
using namespace std;

bool GPA(double gpa);
bool Age(int age);
bool Major(string major);
bool Name(string name);



template <typename T>
T format_string ( const string &Text )
{
    stringstream ss(Text);
    T result;
    return ss >> result ? result : 0;


    /*if(ss >> result)
        return ss >> result;
    else
        return 0;*/
}