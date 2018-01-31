/*
Author: Neil Felix
Course: CSCI-136
Instructor:Minh Nguyen
Assignment: Lab1A

The program takes in two integers, then prints out the smaller of the two.
*/

#include <iostream>
using namespace std;

int main() 
{
	int number1, number2;

	cout << "Enter first number: " << endl;
	cin >> number1;
	
	cout << "Enter second number: " << endl;
	cin >> number2;

if(number1 < number2)
	number2 = number1;
	cout <<"The smaller number is "<< number2 << endl;

return 0;

}

