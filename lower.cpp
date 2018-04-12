/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 4D

This program ask the user to input the length of side of a squre. 
Then prints out the bottom left of that square,
using asterisks(*) and spaces( ).
*/

#include <iostream>
using namespace std;

int main () 
{
  int side;
  cout << "Input side length: ";
  cin >> side;
  cout << " " << endl; 
  cout << "Shape:" << endl;
  
  for(int i=0; i<side; i++) 
  {
    for(int j = 0; j<side; j++)
    {
      if(j<=i)
      {cout << "*";}
      else
      {cout << " ";}
    }
    cout << endl;
  }

  return 0; 
}
