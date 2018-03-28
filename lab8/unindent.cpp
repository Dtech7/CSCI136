/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 8A

This program takes in a badly indented c++ file,
then outputs an unindented version.
example:

"     int x = 1; " will be outputed as "int x = 1; "


*/

#include <iostream>
#include <cctype>
using namespace std;
string removeLeadingSpaces(string);



int main()
{
    string inLine;
    
    
    while(getline(cin, inLine))
    {
      cout << removeLeadingSpaces(inLine) << endl;
    }

}


string removeLeadingSpaces(string line)
{
  string newLine;
  bool found = false;
  for(int i = 0; i < line.length(); i++)
  {
    if(!isspace(line[i]))
    {
      found = true;
    }
    
    if(found)
    {
      newLine+= line[i];
    }
  }
  return newLine;
}
