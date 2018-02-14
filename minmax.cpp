/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab3B

This program finds the minimum and maximum storage in East basin in 2016.


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

  string date;
  double eastSt, eastEl, westSt, westEl;
  double min = 1000;
  double max = -1;
  

  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl)
  { 
    // this loop reads the file line-by-line
    // extracting 5 values on each iteration 
    // for example, to print the date and East basin storage:

    if(min > eastSt) {min = eastSt;}
    if(max < eastSt) {max = eastSt;}
  }
  fin.close();

  cout << "Minimum storage in East basin: " << min << " billion gallons" << endl;
  cout << "Maximum storage in East basin: " << max << " billion gallons" << endl;


  return 0;


}

