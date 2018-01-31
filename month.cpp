/*
Author: Neil Felix
Course: CSCI-136
Instructor:Minh Nguyen
Assignment: Lab 1CD
This program ask the user for a year and a month, then outputs the number of days in that month
taking leap years into consideration.
*/

#include <iostream>
using namespace std;

int main() 
{
	//declaring variables
	int yr, month;
	bool leap;
	int daysOfMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	
	//ask user input
	cout << "Enter year: " << endl;
	cin >> yr;
	cout << "Enter month: " << endl;
	cin >> month;

	//check for leap year
	if(!(yr%4 ==0))
	{	
		leap = false;
	}
	else if(!(yr%100 ==0))
	{
		leap = true;
	}
	else if(!(yr%400 ==0))
	{
		leap = false;
	}
	else
	{	
		leap = true;
	}

	if(daysOfMonth[month] && leap)
	{
		cout <<  "days"
	}
return 0;

}

