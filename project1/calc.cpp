/*
Author: Neil Felix
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1 Task B

This program will accept arbitrarily long mathematical 
formula composed of symbols +, -, and non-negative integers.
Then print out the answer of that formula.
*/
#include <iostream>
using namespace std;

int main()
{
  //declare variables
	int num;
	int p;
	char s;
	
	//initializes num as the first number in file
	cin >> num;
	
	//goes through file
	//starts at first sign
	//first number skipped because it was intialized above
	while(cin >> s >> p)
	{
	  if(s == '+')
    {
	    num += p;
    }
    else if(s == '-')
    {
	    num -= p;
    }
   }

	cout << num << endl;
	return 0;
}
