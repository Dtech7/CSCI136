/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 4B

This program ask the user to input width and height. 
Then prints out a rectangluar checkerboard of the requested size,
using asterisks(*) and spaces( ) alternating.
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
        if((i%2==0)&&(j%2==0)){cout << "*";}
        if((i%2==0)&&(j%2>0)){cout << " ";}
        if((i%2>0)&&(j%2==0)){cout << " ";}
        if((i%2>0)&&(j%2>0)){cout << "*";}

      }
      cout << endl;
  }

  return 0; 
}
