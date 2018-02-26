/*
Author: Neil Felix
Course: CSCI-135 // 136 
Instructor: Genady Maryash // Minh Nguyen
Assignment: Project 1 Task D

This program will accept multiple lines of arbitrarily long mathematical 
formula composed of symbols +, -, ^, and non-negative integers,
and uses semi-colons end of expression.
Then print out the answer of that formula.
*/
#include <iostream>
using namespace std;

int main()
{
  //declare variables
	int num = 0;
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
    else if(s == '^')
    {
      int sqr = p*p;
      
      
    }
    
    //used to end one line and start the other
	  if(s==';')
    {
      cout << num << endl;
      num = p; 
    } 
  }

	cout << num << endl;
	return 0;
}
