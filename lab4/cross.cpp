/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 4C

This program ask the user to input a size. 
Then prints out a diagonal cross with the given size,
using asterisks(*) and spaces( ).
*/

#include <iostream>
using namespace std;

int main () 
{
  int size, tpbtm;
  cout << "Input size: ";
  cin >> size;
  cout << " " << endl; 
  cout << "Shape:" << endl;
  
  for(int i=0; i<size; i++) 
  {
    for(int j = 0; j<size; j++)
    {
      if((i==j)||(j==(size-i-1)))
      {
        cout << "*";
      }
      else
      {
        cout << " ";
      }
    }
    cout << endl;
  }

  return 0; 
}
