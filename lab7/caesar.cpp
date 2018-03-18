/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 7B

This program implements a ceaser cipher.
User inputs string and a shift amount. 
The program will shift the letters by an amount the user entered.
Non-alphebetic chars remain the same,
and the alphabet is wrapped. 
*/

#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

//shift the input char
char shiftChar(char c, int rShift)
{
  char newC;
  if(isalpha(c))
  {
    if(isupper(c))
    {
      if((c+rShift) > 90)
      {
        newC = (c-26) + rShift;
        return newC;
      }
      else
      {
        newC = c + rShift;
        return newC;
      }
    }
    else
    {
      if((c+rShift) > 122)
      {
        newC = (c-26) + rShift;
        return newC;
      }
      else
      {
        newC = c + rShift;
        return newC;
      }
    }
  }
  else
    return c;  
}

//calls shiftChar() to encrypt string
string encryptCaesar(string inS, int rShift)
{
  string encrypted;
  for(int i = 0; i < inS.length(); i++)
  {
    encrypted += shiftChar(inS[i], rShift);
  }
  return encrypted;
}


int main()
{
  string inString;
  int rShift;
  
  cout << "Input text : ";
  getline(cin, inString);
  cout << "Input shift: ";
  cin >> rShift;
  cout << "Ciphertext : " << encryptCaesar(inString, rShift) << endl;
   
  return 0;
}
