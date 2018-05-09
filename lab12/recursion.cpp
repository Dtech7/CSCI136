/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 12F
h
h
h
h
h
h
h
h
*/
#include <iostream>
using namespace std;


bool nestedParens(string s);
bool isAlphanumeric(string s);
int sumArray(int *arr, int size);
int sumRange(int left, int right);
void printRange(int left, int right);
bool divisible(int *prices, int size);
bool splitable(int *prices, int size, int alice, int bob);


int main()
{
  
  //printRange(-3, 11);
  
  /*int x = sumRange(1, 3);
  cout << "This is " << x << endl;   // 6
  */
  //cout << isAlphanumeric("Abcd1234xyz") << endl; 
  
  return 0;
}

void printRange(int left, int right)
{
  int n = left;
  if(n <= right)
  {
    cout << n << " ";
    printRange(n+1, right);
  }
  else
  {
    cout << endl;
    return;
  }
}


int sumRange(int left, int right)
{
  int n = left;
  int sum;
  if(n <= right)
  {
    sum = n + sumRange(n+1, right);
    return sum;
  }
  else
  {
    return 0;
  }
}

int sumArray(int *arr, int size)
{
  int sum;
  if(size == 1)
  {
    return arr[0];
  }
  else
  {
    sum = arr[size-1] + sumArray(arr, size-1);
    return sum;
  }
}

bool isAlphanumeric(string s)
{
  bool alNum;
  int len = s.length();
  if(s.length() == 0)
  {
    alNum = true;
    return alNum;
  }
  else
  {
    if((isalpha(s[0]) || isdigit(s[0]) ) && isAlphanumeric(s.substr(1, len - 1)))
    {
      alNum = true;
      return alNum;
    }
    else
    {
      alNum = false;
      return alNum;
    }
  }
}

bool nestedParens(string s)
{
  bool nstd;
  int len = s.length();
  if(len == 0)
  {
    nstd = true;
    return nstd;
  }
  else if(len%2 == 1)
  {
    nstd = false;
    return nstd;
  }
  else if(!((s[0] == '(' ) && (s[s.length()-1] == ')')))
  {
    nstd = false;
    return nstd;
  }
  else
  {
    nstd = nestedParens(s.substr(1, s.length()-2));
    return nstd;
  }
}

bool divisible(int *prices, int size)
{
  return splitable(prices, size, 0, 0);
}

bool splitable(int *prices, int size, int alice, int bob)
{
  if(size == 0)
  {
    return (alice == bob);
  }
  else if(splitable(prices, (size-1), (alice + prices[size-1]), bob))
  {
    return true;
  }
  else if(splitable(prices, (size-1), alice, (bob + prices[size-1])))
  {
    return true;
  }
  else
  {
    return false;
  }
}
