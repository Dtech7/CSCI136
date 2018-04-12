/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 4F

This program ask the user to input width and height. 
Then prints out an upside-down trapezoid,
using asterisks(*) and spaces( ).
The program will report "impossible shape!" 
if the height is too large for the given width
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
  cout << endl; 
  
  if((width%2==0)&&(height>(width/2)))
  {
    cout << "Impossible shape!" << endl;
  }
  else if((width%2>0)&&(height>((width/2)+1)))
  {
    cout << "Impossible shape!" << endl;
  }
  else
  {
    cout << "Shape:" << endl;
    for(int i=0; i<height; i++) 
    {
      for(int h=0; h<i; h++)
      {
        cout << " ";
      }
      for(int j=width-(i*2); j>0; j--)
      {
        cout << "*";
      }
      cout << endl;
    }
  }
  return 0; 
}
