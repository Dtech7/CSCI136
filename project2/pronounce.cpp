/*
Author: Neil Felix
Course: CSCI-135 // 136 
Instructor: Genady Maryash // Minh Nguyen
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

*/
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

string capWord(string);
void pronoun(string);
string identical();
string addPhon();
string rmvPhon();
string rplPhon();

int main()
{
  
  string w, word;
  
  cout << "Enter word: ";
  cin >> w;
  word = capWord(w);
  //cout << word;
  pronoun(word);
  
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

void pronoun();
{
  ifstream cmuDict;
  cmuDict.open("cmudict.0.7a");
  
  
}
