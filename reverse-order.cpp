/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab3D

This program asks the user to input two dates.
The program then reports the West basin elevation for all days
in the interval in the reverse chronological order.

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
  double el[400];
  string dateArr[400];
  int count = 0;

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
      el[count] = westEl;
      dateArr[count] = date;

         if (date1 != date2)
         {
          while(fin >> date >> eastSt >> eastEl >> westSt >> westEl)
          {
            count = count + 1;
            el[count] = westEl;
            dateArr[count] = date;

            if(date == date2){break;}
           }
          }
     }
   }
   fin.close();

  for(int i = count; i>=0; i--)
  {
    cout << dateArr[i] << " ";
    cout << el[i] << " ft" << endl;
  }




  return 0;


}

