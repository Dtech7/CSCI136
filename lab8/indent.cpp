/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 8B

This program takes in a badly indented c++ file,
then outputs an a properly indented version version.

*/

#include <iostream>
#include <cctype>
using namespace std;
string removeLeadingSpaces(string);
int countChar(string line, char c);




int main()
{
    string inLine;
    char op = '{';
    char cl = '}';
    int openBraket = 0;
    int closeBraket = 0;
    int blocks = 0;
    
    
    while(getline(cin, inLine))
    { 
      
      openBraket += countChar(inLine, op);
      closeBraket += countChar(inLine, cl);
      blocks = openBraket - closeBraket;
      for(int i = 0; i < blocks; i++)
      {
        cout <<  "\t";
      }
      cout << removeLeadingSpaces(inLine) << endl;
      
    }

}

int countChar(string line, char c)
{
  int count = 0;
  for(int i = 0; i < line.length(); i++)
  {
    if(line[i] == c)
    {
      count += 1;
    }
  }
  return count;
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
      newLine += line[i];
    }
  }
  
  return newLine;
}
