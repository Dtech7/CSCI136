/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab2A

Asks the user to input an integer in the range 0 < n < 100. 
If the number is out of range, the program will keep asking to re-enter 
until a valid number is inputed.
After a valid value is obtained, It will print that number squared.
*/


#include <iostream>
using namespace std;

int main()
{

  int num = 0;
  
  while((num<=0) || (num>=100))
  {
    cout << "Please Enter number between 0 and 100. " << endl;
    cin>> num;
  }
  
  int sqr = num*num;
  cout << "The number squared is ";
  cout << sqr << endl;

  return 0;
}
