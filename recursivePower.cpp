// Author: Avery VanAusdal
// Assignment Number: Lab 3
// File Name: recursivePower.cpp
// Course/Section: COSC 1337 Section 3
// Date: 9/25/2018
// Instructor: Bernard Ku
/* Requirements:
Recursive power function
Base double, exponent int
Basic positive & negative power required
Exception handling for wrong data types	*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;


double recursivePower(double base, int exponent)
{
	if (exponent < 0) return 1/recursivePower(base, -exponent);
	if (exponent == 0) return 1; //base case
	return base * recursivePower(base, exponent-1);
}

//Just for getting input
template <typename T>
T get_input(const string& prompt="", const string& error_msg="", 
T min=-numeric_limits<T>::max(), T max=numeric_limits<T>::max()) {
	T value{};
	while (not(cout<<prompt && cin>>value && value>=min && value<=max)) {
		cout<<error_msg;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
	}
	return value;
}
	
int main()
{
	char choice = 'y';
	double base;
	int exponent;
	while (choice == 'y')
	{
		base = get_input<double>("Enter the base: ");
		exponent = get_input<int>("Enter the exponent: ");
		cout<<base<<" to the power of "<<exponent<<" = "<<recursivePower(base, exponent);
		choice = tolower(get_input<char>("\n\nContinue? (Y/N): "));
	}
}

