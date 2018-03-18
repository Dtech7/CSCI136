/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 7A

This program will ask the user to input a line of text,
then print out the input in ascii code.
*/
#include <iostream>
#include <string>
using namespace std;

void changeToAscii(string inS)
{
  for(int i = 0; i < inS.length(); i++)
  {
    cout << inS[i] << " " << (int) inS[i] << endl;
  }

}

int main()
{
  string inString;
  
  cout << "Input text: " << endl;
  getline(cin, inString);
  changeToAscii(inString);
   
return 0;
}
