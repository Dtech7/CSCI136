/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 7C

This program implements a vigenere cipher.
User inputs string and a keyword. 
The program will shift each char from the first input to the right,
depending on the keyword.
Non-alphebetic chars remain the same,
and the alphabet is wrapped. 
*/

#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

//shift the input char
char shiftChar(char c, char k)
{
  char newC;
  
  if(isupper(c))
  {
    if((c + k) > 90)
    {
      newC = (c - 26) + k;
      return newC;
    }
    else
    {
      newC = c + k;
      return newC;
    }
  }
  else
  {
    if((c + k) > 122)
    {
      newC = (c - 26) + k;
      return newC;
    }
    else
    {
      newC = c + k;
      return newC;
    }
  }
}

/*
changes key so a = 0, b = 1, c = 2,....
instead of normal ascii a = 97, b = 98,...
*/ 
string trueKey(string key)
{
  string nKey;
  for(int i = 0; i < key.length(); i++)
  {
    nKey += key[i] - 97;
  }
  return nKey;
}

//calls shiftChar() to encrypt string
string encryptVigenere(string inS, string key)
{
  string encrypted;
  string test = "test";
  string newKey = trueKey(key);
  int keyChange = 0;
  
  for(int i = 0; i < inS.length(); i++)
  {
    if(isalpha(inS[i]))
    {
      if(keyChange < newKey.length())
      {
        encrypted += shiftChar(inS[i], newKey[keyChange]);
      }
      else
      {
        keyChange = 0;
        encrypted += shiftChar(inS[i], newKey[keyChange]);
      }
      
      keyChange += 1;
      
    }
    else
    {
      encrypted += inS[i];
    }
  }
  return encrypted;
}



int main()
{
  string inString, key;
  
  
  cout << "Input text : ";
  getline(cin, inString);
  cout << "Input keyword: ";
  getline(cin, key);
  
  cout << "Ciphertext : " << encryptVigenere(inString, key) << endl;
   
  return 0;
}
