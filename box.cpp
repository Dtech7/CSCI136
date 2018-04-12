/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 4A

This program ask the user to input width and height. 
Then prints out a rectangluar box of the requested size,
using asterisks(*).
*/

#include <iostream>
using namespace std;

int main () 
{
  int width, height;
  cout << "Input width: ";
  cin >> width;
  cout << "Input height: ";
  cin >> height;
  cout << " " << endl;
  cout << "Shape:" << endl;
  for(int i=0; i<height; i++) //Controls the height
  {
      for(int j=0; j<width; j++) //Controls the width
      {
        cout << "*";
      }
      cout << endl;
  }

  return 0; 
}
