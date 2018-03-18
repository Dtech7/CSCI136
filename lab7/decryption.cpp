/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 7D

This program implements both caesar and vigenere cipher
to encrypt the user input, then 
Caesar:
User inputs string and a shift amount. 
The program will shift the letters by an amount the user entered.

Vigenere:
User inputs string and a keyword. 
The program will shift each char from the first input to the right,
depending on the keyword.

Non-alphebetic chars remain the same,
and the alphabet is wrapped for both. 
*/

#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

//Prototypes for all functions
string trueKey(string);
char shiftChar(char, int);
char shiftChar(char, char);
string encryptCaesar(string, int);
string encryptVigenere(string, string);
char revShift(char, int);
char revShift(char, char);
string decryptCaesar(string, int);
string decryptVigenere(string, string);


//=====================================================
//Main function

int main()
{
  string inString, key, cEncrypt, vEncrypt;
  int rShift;
  
  
  cout << "Input text : ";
  getline(cin, inString);
  
  cout << endl;
  cout << "= Caesar =" << endl;
  cout << "Input shift: ";
  cin >> rShift;
  cEncrypt = encryptCaesar(inString, rShift);
  cout << "Ciphertext : " << cEncrypt << endl;
  cout << "Decrypted  : " << decryptCaesar(cEncrypt, rShift) << endl;
  
  cout << endl;
  cout << "= Vigenere =" << endl;
  cout << "Input keyword: ";
  cin >> key;
  vEncrypt = encryptVigenere(inString, key);
  cout << "Ciphertext : " << vEncrypt << endl;
  cout << "Decrypted  : " << decryptVigenere(vEncrypt, key) << endl;
   
  return 0;
}

//======================================================
//functions for Caesar cipher

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

//reverses the shift done by shiftChar(char, int)
char revShift(char c, int rShift)
{
  char newC;
  if(isalpha(c))
  {
    if(isupper(c))
    {
      if((c-rShift) < 65)
      {
        newC = (c+26) - rShift;
        return newC;
      }
      else
      {
        newC = c - rShift;
        return newC;
      }
    }
    else
    {
      if((c-rShift) < 97)
      {
        newC = (c+26) - rShift;
        return newC;
      }
      else
      {
        newC = c - rShift;
        return newC;
      }
    }
  }
  else
    return c;  
}

//calls shiftChar(char, int) to enctypt input
string encryptCaesar(string inS, int rShift)
{
  string encrypted;
  for(int i = 0; i < inS.length(); i++)
  {
    encrypted += shiftChar(inS[i], rShift);
  }
  return encrypted;
}

//calls revShift(char, int) to undo encryption
string decryptCaesar(string inS, int rShift)
{
  string encrypted;
  for(int i = 0; i < inS.length(); i++)
  {
    encrypted += revShift(inS[i], rShift);
  }
  return encrypted;
}

//==============================================================
//functions for Vigenere cipher

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

//reverses the shift done by shiftChar(char, char)
char revShift(char c, char k)
{
  char newC;
  
  if(isupper(c))
  {
    if((c - k) < 65)
    {
      newC = (c + 26) - k;
      return newC;
    }
    else
    {
      newC = c - k;
      return newC;
    }
  }
  else
  {
    if((c - k) < 97)
    {
      newC = (c + 26) - k;
      return newC;
    }
    else
    {
      newC = c - k;
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

//calls shiftChar(char, char) to enctypt input
string encryptVigenere(string inS, string key)
{
  string encrypted;
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

//calls revShift(char, char) to undo enctyption
string decryptVigenere(string inS, string key)
{
  string encrypted;
  string newKey = trueKey(key);
  int keyChange = 0;
  
  for(int i = 0; i < inS.length(); i++)
  {
    if(isalpha(inS[i]))
    {
      if(keyChange < newKey.length())
      {
        encrypted += revShift(inS[i], newKey[keyChange]);
      }
      else
      {
        keyChange = 0;
        encrypted += revShift(inS[i], newKey[keyChange]);
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



