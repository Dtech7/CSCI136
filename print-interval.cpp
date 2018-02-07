/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab2B

Asks the user to input two integers n1 and n2 
(which will representing the lower and upper limits of the interval),
 then print out all integers in the range n1 ≤ i < n2 separated by spaces.
*/


#include <iostream>
using namespace std;

int main()
{

  int n1;
  int n2;

  cout << "Enter the lower limit: ";
  cin >> n1;
  cout << "Enter the upper limit: ";
  cin >> n2;

  for(int i=n1; i<n2; i++)
  {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
