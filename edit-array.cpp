/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab2C

The program will create and populate an array with 1.
The user will then be able to edit each element of the array.
The program will create and populate an array with 1.
The user will then be able to edit each element of the array.
 
*/


#include <iostream>
using namespace std;

int main()
{

  int index;
  int value;
  int myData[10]; 

  for(int i=0; i<10; i++)
  {
    myData[i] = 1;
  }


  do
  {
    for(int j=0; j<10; j++)
    {
      cout << myData[j] << " ";
    }
    cout << endl;

    cout << "Enter index: ";
    cin >> index;
    cout << "Enter value: ";
    cin >> value;
    
    if(index<10){ myData[index] = value;}


  }while((index>=0) && (index<10));
  cout << endl;
  return 0;
}
