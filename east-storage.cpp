/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab3A

This program asks the user to input a date (in MM/DD/YYYY format), 
and prints out the East basin storage on that day.


*/


#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{


  ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail())
  {
    cerr << "File cannot be opened for reading." << endl;
    exit(1); // exit if failed to open the file
  }
  
  string junk;        // new string variable
  getline(fin, junk); // read one line from the file 

  string date, date1;
  double eastSt, eastEl, westSt, westEl;

  cout << "Enter Date: ";
  cin >> date1;

  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl)
  { 
    // this loop reads the file line-by-line
    // extracting 5 values on each iteration 
    // for example, to print the date and East basin storage:

    if(date == date1)
      cout << "East basin Storage: " << eastSt << "billion gallons" << endl;
  }
  fin.close();

  return 0;


}

