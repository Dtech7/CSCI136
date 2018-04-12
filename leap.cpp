/*
Author: Neil Felix
Course: CSCI-136
Instructor:Minh Nguyen
Assignment: Lab 1C

This program ask the user for a year then checks if that year is a leap year.
Then outputs "Leap year" if it is or "Common year" if it isn't.
*/

#include <iostream>
using namespace std;

int main() 
{
	//variable for year
	int yr;
	
	//ask user for year
	cout << "Enter year: " << endl;
	cin >> yr;

	if(!(yr%4 ==0))
	{	
		cout <<"Common year"<< endl;
	}
	else if(!(yr%100 ==0))
	{
		cout <<"Leap year"<< endl;
	}
	else if(!(yr%400 ==0))
	{
		cout <<"Common year"<< endl;
	}
	else
	{	
		cout <<"Leap year"<< endl;
	}
return 0;

}

