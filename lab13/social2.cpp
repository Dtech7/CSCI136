/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 13B
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

class Profile
{
  private:
    string username;
    string displayname;
  public:
    Profile(string usrn, string dspn);
    Profile();
    string getUsername();
    string getFullName();
    void setDisplayName(string dspn);
};

class Network
{
  private:
    static const int MAX_USERS = 20;
    int numUsers;
    Profile profiles[MAX_USERS];
    int findID (string usrn);
  
  public:
    Network();
    bool addUser(string usrn, string dspn);
};


int main()
{
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     // true (1)
  cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

  cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
  cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
  cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i), 
                 "Mario" + to_string(i)) << endl;   // true (1)

  cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}

//Functions for Profile class
Profile::Profile(string usrn, string dspn)
{
  username = usrn;
  displayname = dspn;
}

Profile::Profile()
{
  username = "";
  displayname = "";
}

string Profile::getUsername()
{
  return username;
}

string Profile::getFullName()
{
  string fllNam = displayname+" (@" + username + ")";
  return fllNam;
}

void Profile::setDisplayName(string dspn)
{
  displayname = dspn;
}

//Funstions for Network class
Network::Network()
{
  numUsers = 0;
}

bool Network::addUser(string usrn, string dspn)
{
  for(int i = 0; i < usrn.length(); i++)
   {
      if(!(isalpha(usrn[i])) && !(isdigit(usrn[i])))
      {
        return false;
      }
   }
   
   for(int i = 0; i < MAX_USERS; i++)
   {
      if((profiles[i]).getUsername() == usrn)
      {
        return false;
      }
   }
 
  if(numUsers == MAX_USERS)
  {
    return false;
  }
  else
  {
    profiles[numUsers] = Profile(usrn, dspn);
    numUsers++;    
    return true;
  }
  
}

int Network::findID (string usrn)
{
  for(int i = 0; i < MAX_USERS; i++)
  {
    if(usrn == (profiles[i]).getUsername())
    {
      return i;
    }
  }
}
