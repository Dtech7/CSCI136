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
using namespace std;

//prototypes for functions
string capWord(string);
int countPhone(string);
bool wordCheck(string);
bool lineCheck(string);
string splitString(string, string&);
void splitString(string, string&, string&);
void printOut(string, string, string, string, string);
//
void identical(string, string, string, string, string&);
void addPhon(int, string, string, string, string&);
void rmvPhon(int, string, string, string, string&);
void rplPhon(int, string, string, string, string&);
void pronoun(string, string, string&, string&, bool&);




int main()
{
  
  string w, word, fileString, beforeSpace, afterSpace, newBeforeSpace, newAfterSpace;
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
    if(!lineCheck(fileString))
    {
      pronoun(word, fileString, beforeSpace, afterSpace, found);
    } 
  }
  
  cmuDict.clear();//clears info from getline()
  cmuDict.seekg(0);//sets the position to the begining of the file
  if(found)
  {
    pron = afterSpace;
    phoneCount = countPhone(afterSpace);
    
    
    while(!cmuDict.eof())
    {
      getline(cmuDict, fileString);
      if(!lineCheck(fileString))
      {
        splitString(fileString, newBeforeSpace, newAfterSpace);
        identical(pron, word, newBeforeSpace, newAfterSpace, iden);
        addPhon(phoneCount, pron, newBeforeSpace, newAfterSpace, addPhones);
        rmvPhon(phoneCount, pron, newBeforeSpace, newAfterSpace, remPhones);
        rplPhon(phoneCount, pron, newBeforeSpace, newAfterSpace, repPhones);
      }
    }
    
    printOut(pron, iden, addPhones, remPhones, repPhones);  
  }
  else
  {
    cout << endl;
    cout << "Not found" << endl;
  }
  cmuDict.close();
  
  return 0;
}

/***************************************
Assist functions:                     **
capWord():                            **
wordCheck()                           **
splitString()                         **
countPhone()                          **
printOut()                            **
lineCheck()                           **
****************************************/

//checks if the word has numbers
bool wordCheck(string w)
{
  bool hasBadChar;
  for(int i = 0; i < w.length(); i++)
  {
    if(isdigit(w[i]))
    {
      hasBadChar = true;
      break;
    }
    else if(w[i] == ( '(' || ')' ||'-' || '&' || '%' || '.' || '!') )
    {
      hasBadChar = true;
      break;
    }
    else
    {
      hasBadChar = false;
    }
  }
  return hasBadChar;
}

//used to set the input word to all caps
string capWord(string word)
{
  string caps;
  for(int i=0; i < word.length(); i++)
  {
    caps += toupper(word[i]);
  }
  return caps;
}

//Used to split strings on space
void splitString(string s, string &bSpace, string &afSpace)
{
  bSpace = ""; 
  afSpace = "";
  int i = 0;
  while (i < s.size() && !isspace(s[i])) 
  {
    bSpace += s[i]; 
    i++;
  }
  
  i++;
  i++;
  
  while (i < s.size())
  {
    afSpace += s[i]; 
    i++;
  }
}

// overloded splitString 
string splitString(string s, string &after)
{
  string bf;
  after = "";
  int i = 0;
  while (i < s.size() && !isspace(s[i])) 
  {
    bf += s[i]; 
    i++;
  }
  
  i++;
  
  while (i < s.size())
  {
    after += s[i]; 
    i++;
  }
  
  return bf;
  
}

//count the amount of phonemes in the pronounciations
int countPhone(string word)
{
  int num = 0;
  for(int i = 0; i<word.length(); i++)
  {
    if(isspace(word[i]))
    {
      num+=1;
    }
  }
  return num+1;
}

//skips lines that start with special char
bool lineCheck(string fileString)
{
  string specialChar = ";!#&%.()-/:?";
  specialChar += '"';
  specialChar += "\\";
  bool hasSpecialChar;
  for(int i = 0; i < specialChar.length(); i++)
  {
    if(fileString[0] == specialChar[i])
    {
      hasSpecialChar = true;
      break;
    }
    else
    {
      hasSpecialChar = false;
    }
  }
  
  return hasSpecialChar;
}

//Prints out everything;
void printOut(string pron, string iden, string addP, string rmP, string rpP)
{ 
  cout << endl;
  cout << "Pronounciation    :" << pron << endl;
  cout << endl;
  cout << "Identical         :" << iden << endl;
  cout << "Add Phoneme       :" << addP << endl;
  cout << "Remove Phoneme    :" << rmP << endl;
  cout << "Replace Phoneme   :" << rpP << endl; 
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
void pronoun(string word, string fileString, string& beforeSpace,
                                    string& afterSpace, bool& found)
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
void identical(string pron,string word, string newBeforeSpace, string newAfterSpace, string &iden)
{
  
  if(newBeforeSpace == word)
  {
    iden +="";
  }
  else if(newAfterSpace == pron)
  {
    if(!wordCheck(newBeforeSpace))
    {
      iden += newBeforeSpace + " ";
    }
  }
}

//finds words that are similar but has more phoneme than the original
void addPhon(int pCount, string pron, string newBeforeSpace, 
                        string newAfterSpace, string &addPhones)
{
  int newPcount;
  int matches = 0;
  newPcount = countPhone(newAfterSpace);
  string str1, aftr1, str2, aftr2;
  str1 = pron;
  str2 = newAfterSpace; 
   

  if((newPcount == (pCount + 1)) && !wordCheck(newBeforeSpace))
  {
    for(int i = 0; i < pron.length(); i++)
    {
      if(splitString(str1, aftr1) == splitString(str2, aftr2))
      {
        matches += 1;
        str1 = aftr1;
        str2 = aftr2;
      }
    }
  }

  if(matches == pCount)
  {
    addPhones += newBeforeSpace + " ";
  }
}

//finds words that are similar but has one less phoneme than the original
void rmvPhon(int pCount, string pron, string newBeforeSpace, 
                        string newAfterSpace, string &remPhones)
{
  int newPcount;
  int matches = 0;
  newPcount = countPhone(newAfterSpace);
  string str1, str11, aftr1, str2, str22, aftr2, junk, ofset;
  str1 = pron;
  str2 = newAfterSpace;
  int matcheN = pCount - 1;
  
  if((newPcount == (pCount - 1)) && !wordCheck(newBeforeSpace))
  {
    if(pron[0] != newAfterSpace[0]) //if removed from the begining of the word
    {
      junk = splitString(pron, ofset);
      for(int i = 0; i < newPcount; i++)
      {
        if(splitString(ofset, aftr1) == splitString(str2, aftr2))
        {
          matches += 1;
        }
        ofset = aftr1;
        str2 = aftr2;
      }
    }
    else if(pron[pron.length()-1] != newAfterSpace[newAfterSpace.length()-1]) // if removed from the end of the word
    {
      for(int i = 0; i < newPcount; i++)
      {
        if(splitString(str1, aftr1) == splitString(str2, aftr2))
        {
          matches += 1;
          str1 = aftr1;
          str2 = aftr2;
        }
      }
    }
    else // if removed from anywhere else
    {
      for(int i = 0; i < pCount; i++)
      {
        if(splitString(str1, aftr1) == splitString(str2, aftr2))
        {
          matches += 1;
          str1 = aftr1;
          str2 = aftr2;
        }
        else
        {
          junk = splitString(str1, ofset);
          str1 = ofset;
        }
      }
    }
  }

  if(matches == matcheN)
  {
    remPhones += newBeforeSpace + " ";
  }
}

//Finds words that are similar but with one phoneme replaced
//Finds words that are similar but with one phoneme replaced
void rplPhon(int pCount, string pron, string newBeforeSpace, 
                        string newAfterSpace, string &repPhones)
{
  int newPcount;
  int matches = 0;
  newPcount = countPhone(newAfterSpace);
  string str1, str11, aftr1, str2, str22, aftr2;
  str1 = pron;
  str2 = newAfterSpace;
  int matchesN = pCount - 1;
  
  
  if((newPcount == pCount) && !wordCheck(newBeforeSpace))
  {
    for(int i = 0; i < pCount; i++)
    {
      if(splitString(str1, aftr1) == splitString(str2, aftr2))
      {
        matches += 1;
      }
      str1 = aftr1;
      str2 = aftr2;
    }
  }
  
  
  if(matches == matchesN )
  {
    repPhones += newBeforeSpace + " ";
  }
}

