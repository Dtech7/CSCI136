/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab3C

This program asks the user to input two dates. 
The program then checks each day in the interval and report which basin
had higher elevation on that day by printing “East” or “West”,
or print “Equal” if both basins are at the same level.

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

  string date, date1, date2;
  double eastSt, eastEl, westSt, westEl;

  cout << "Enter starting date: ";
  cin >> date1;
  cout << "Enter ending date: ";
  cin >> date2;


  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl)
  { 
    // this loop reads the file line-by-line
    // extracting 5 values on each iteration 
    // for example, to print the date and East basin storage:

    if(date == date1)
    {
         if(eastEl > westEl)
         {cout << date << " East" << endl;}
         else if(westEl > eastEl)
         {cout << date << " West" << endl;}
         else if(eastEl == westEl)
         {cout << date << " Equal" << endl;}

      while(fin >> date >> eastSt >> eastEl >> westSt >> westEl)
      {

	      if(date1 != date2)
        {
         if(eastEl > westEl)
         {cout << date << " East" << endl;}
         else if(westEl > eastEl)
         {cout << date << " West" << endl;}
         else if(eastEl == westEl)
         {cout << date << " Equal" << endl;}
        }

         if(date == date2){break;}
       }
    }
  }
  fin.close();

  return 0;


}

