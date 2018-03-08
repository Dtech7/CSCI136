/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 5A, B, C, D, E, F, G

5A
This program ask the user to input two numbers,
then output true if the first number is divisible 
by the first, if not it out puts false.

5B
This program ask the user to input a number,
then output true if that number is prime 
or false if it isn't.

5C
This program ask the user to input a number,
then outputs the smallest prime that is greater than the input.

5D
This program ask the user to input two numbers,
then output the number of prime numbers between them. 

5E
This program ask the user to input a number,
then outputs true the number is a twin prime else,
false if it isn't. 

5F
This program ask the user to input a number,
then outputs the smallest twin prime greater than the input. 


5G
This program ask the user to input two numbers,
then outputs the largest twin prime that between the inputs,
if there is no twin primes returns -1. 

*/

#include <iostream>
using namespace std;


//5A
bool isDivisibleBy(int numbr, int numbr2)
{
  if(numbr2 == 0)
  {
    return false;
  }
  else if(numbr % numbr2 == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
} 

//5B
bool isPrime(int num)
{
 bool test;
 if(num <= 1 )
 {
  test = false;
 }
 else if((num == 2) || (num == 3))
 {
  test = true;
 }
 else
 {
  for (int i = 2; i < num; i++)
  {
    if(num % i == 0)
    {
      test = false;
      goto label;
    }
    else
    {
      test = true;
    }  
  } 
 }
 label:
 return test; 
}

//5C
int nextPrime(int num)
{
    
    int ind = num + 1;
    while(isPrime(ind) == false)
    {
      ind+=1;
    }
    return ind;
}

//5D
int countPrimes(int numbr, int numbr1)
{
  int count = 0;
  int ind = numbr;
  while(ind <= numbr1)
  {
    if(isPrime(ind))
    {
      count += 1;
      ind+=1;
    }
    else
    {
      ind+=1;
    }
  }
  return count;
}

//5E
bool isTwinPrime(int n)
{
  //bool twin;
  if(isPrime(n) && ((isPrime(n-2)) || (isPrime(n+2))))
  {
    return true;
  }
  else 
  {
    return false;
  }
  //return twin;
}

//5F
int nextTwinPrime(int n)
{
  label:
  int ind = nextPrime(n);
  
  if(isTwinPrime(ind))
  {
    return ind;
  }
  else
  {
    n+=1;
    goto label;
  }
}

//5G
int largestTwinPrime(int numbr, int numbr2)
{

  int noTwin = -1;
  
  for(int i = numbr2; i>=numbr; i--)
  {
    if(isTwinPrime(i))
    {
      return i;
    }
    else if(i == numbr)
    {
      return noTwin;
    }
  }
}

int main()
{
//cin and cout should be adjusted accordingly
  int numbr, numbr2;
  
   cout << "Enter number:" << endl;
   cin >> numbr;
   cout << "Enter Second number:" << endl;
   cin >> numbr2;
   
   cout << largestTwinPrime(numbr, numbr2) << endl;

 return 0; 
}
