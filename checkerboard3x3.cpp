/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 4G

This program ask the user to input width and height. 
Then prints out a rectangluar checkerboard of 3X3 squares
from the requested size,using asterisks(*) and spaces( ).
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

  cout << "shape:" << endl;
  for(int i=0; i<height; i++) 
  {
    for(int j=0; j<width; j++) 
    {
          if(((i/3)%2)==((j/3)%2))
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
