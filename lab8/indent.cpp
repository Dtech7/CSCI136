/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 8B

This program takes in a badly indented c++ file,
then outputs an a properly indented version version.
H
I
H
I

*/

#include <iostream>
#include <cctype>
using namespace std;
string removeLeadingSpaces(string);
int countChar(string line, char c);




int main()
{
    string inLine, new_line;
    char op = '{';
    char cl = '}';
    int openBraket = 0;
    int closeBraket = 0;
    int blocks = 0;
    
    
    while(getline(cin, inLine))
    { 
        new_line = removeLeadingSpaces(inLine);
      
      if (new_line[0] == '}')
        for(int i = 0; i < blocks-1; i++)
        {
          cout <<  "\t";
        }        
      else  
        for(int i = 0; i < blocks; i++)
        {
          cout <<  "\t";
        }

     
      openBraket = countChar(new_line, op);
      closeBraket = countChar(new_line, cl);
      blocks += openBraket - closeBraket;
     
      
      cout << new_line << endl;

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
