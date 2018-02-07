/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab2D

once the number reaches the upper limit of what can be handled by an "int",
the program begins to wrap the  numbers

*/


#include <iostream>
using namespace std;

int main()
{
  int fib[60];
  fib[0] = 0;
  fib[1] = 1;

  for(int i=2; i<60; i++)
  {
    fib[i] = fib[i-1] + fib[i-2];
  }

  for(int j=0; j<60; j++)
  {
    cout << fib[j] << endl;
  }

  return 0;
}
