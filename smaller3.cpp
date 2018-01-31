/*
Author: Neil Felix
Course: CSCI-136
Instructor:Minh Nguyen
Assignment: Lab1A

The program takes in tthree integers, then prints out the smaller of the two.
*/

#include <iostream>
using namespace std;

int main() 
{
	int number1, number2, number3;

	cout << "Enter first number: " << endl;
	cin >> number1;
	
	cout << "Enter second number: " << endl;
	cin >> number2;
	
	cout << "Enter third number: " << endl;
	cin >> number3;

if(number1 < number2)
{	
	number2 = number1;

	if(number2 < number3)
	{
		number3 = number2;	
	}
}
cout <<"The smaller number is "<< number3 << endl;
return 0;

}

