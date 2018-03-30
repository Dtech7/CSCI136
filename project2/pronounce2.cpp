/*
Author: Neil Felix
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 2

This program ask the user input a word,
it then searches the 'cmudict.0.7a' file for the word,
if the word is found it then prints out: 
Pronunciation : the pronunciation of the word (as given in the dictionary),
Identical     : other words from the dictionary with the same pronunciation as W,
Add phoneme   : words that can be obtained from W by adding one phoneme,
Remove phoneme: words that can be obtained from W by removing one phoneme,
Replace phoneme: words that can be obtained from W by replacing one phoneme.
If the word is not found in the dictionary, it prints “Not found”.        


=========================== */

#include <iostream>
#include <fstream>
#include <string>
//#include <bits/stdc++.h>
using namespace std;

//prototypes for functions
string capWord(string);
string identical(string, string);
string addPhon(int, string, string);
string rmvPhon(int, string, string);
string rplPhon(int, string, string);
void splitString(string, string&, string&);
void pronoun(string, string, string&, string&, bool&);


int main()
{
  
  string w, word, fileString, beforeSpace, afterSpace;
  string pron, iden, addPhones, remPhones, repPhones;
  bool found;
  int phoneCount;
    
  cout << "Enter word: ";
  cin >> w;
  if(!wordCheck(w))
  {
    word = capWord(w);
  }
  else
  {
    cout<< endl;
    cout << "Not found" << endl;
  }
  
  ifstream cmuDict;
  cmuDict.open("cmudict.0.7a");
  
  found = false;
  while(!cmuDict.eof() && !found)
  {
    getline(cmuDict, fileString);
    pronoun(word, fileString, beforeSpace, afterSpace, found);
  }
  
  if(found)
  {
    pron = afterSpace;
    phoneCount = countPhone(afterSpace);
    
    
    while(!cmuDict.eof())
    {
      getline(cmuDict, fileString);
      
      iden += identical(pron, fileString);
      addPhones += addPhon(phoneCount, pron, fileString);
      remPhones += rmvPhon(phoneCount, pron, fileString);
      repPhones += rplPhon(phoneCount, pron, fileString);
      
    }
     
  }
  else
  {
    cout << endl;
    cout << "Not found" << endl;
  }
  cmuDict.close();
  
  return 0;
}


/******************************
Functions:                   **
pronoun()                    **
identical()                  **
addPhon()                    **
rmvPhon()                    **
rplPhon()                    **
*******************************/

//finds the pronounciation of the word
void pronoun(string word, string fileString, string& afterSpace, 
                          string& beforeSpace, bool& found)
{
  string bSpace, afSpace;
  splitString(fileString, bSpace, afSpace);
  
  if(bSpace == word)
  {
    afterSpace = afSpace;
    beforeSpace = bSpace;
    found = true;
  }
}

//finds identical words
string identical(string pron, string fileString)
{
  string before, after;
  splitString(fileString, before, after);
  
  if(after == pron)
  {
    if(!wordCheck(before))
    {
      return before + " ";
    }
  }
}

//finds words that are similar but has more phoneme than the original
string addPhon(int pCount, string pron, string fileString)
{
  int newPcount;
  int matches = 0;
  string word = "";
  string before, after;
  
  splitString(fileString, before, after);
  newPcount = countPhone(after);
  
  if(newPcount > pCount)
  {
    for(int i = 0; i < pron.length(); i++)
    {
      if(pron[i] == after[i])
      {
        matches += 1;
      }
    }
  }
  else
  {
    return word;
  }
  
  if(matches >= (pCount/2))
  {
    return before + " ";
  }
  else
  {
    return word;
  }
}

//finds words that are similar but has one less phoneme than the original
string rmvPhon(int pCount, string pron, string fileString)
{
  int newPcount;
  int matches = 0;
  string word = "";
  string before, after;
  
  splitString(fileString, before, after);
  newPcount = countPhone(after);
  
  if(newPcount < pCount)
  {
    for(int i = 0; i <after.length(); i++)
    {
      if(after[i] == pron[i])
      {
        matches += 1;
      }
    }
  }
  else
  {
    return word;
  }
  
  if(matches >= (pCount/2))
  {
    return before + " ";
  }
  else
  {
    return word;
  }
}

//Finds words that are similar but with one phoneme replaced
string rplPhon(int pCount, string pron, string fileString)
{
  int newPcount;
  int matches = 0;
  string word = "";
  string before, after;
  
  splitString(fileString, before, after);
  newPcount = countPhone(after);
  
  if(newPcount == pCount)
  {
    for(int i = 0; i <after.length(); i++)
    {
      if(after[i] == pron[i])
      {
        matches += 1;
      }
    }
  }
  else
  {
    return word;
  }
  
  if(matches >= (pCount/2))
  {
    return before + " ";
  }
  else
  {
    return word;
  }
}


