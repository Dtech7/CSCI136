/*
Author: Neil Felix
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1 Task A

This program reads a sequence of integers from an input,
then reports their sum.
*/

#include <iostream>
using namespace std;


int main() 
{
  int n = 0;
  int p;
  while(cin >> p)
  {
    n = n+p;
  }
  cout << n << endl;
}

