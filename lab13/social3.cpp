/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 13C
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
    
    bool following[MAX_USERS][MAX_USERS];
  
  public:
    Network();
    bool addUser(string usrn, string dspn);
    bool follow(string usrn1, string usrn2);
    void printDot();
};

//
int main()
{
  Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
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
  for(int i = 0; i < MAX_USERS; i++)
  {
    for(int j = 0; j < MAX_USERS; j++)
    {
      following[i][j] = false;
    }
  }
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
  
  
    profiles[numUsers] = Profile(usrn, dspn);
    numUsers++;    
    return true;

  
}

int Network::findID (string usrn)
{
  for(int i = 0; i < numUsers; i++)
  {
    if(usrn == (profiles[i]).getUsername())
    {
      return i;
    }
  }
  return -1;
}

bool Network::follow(string usrn1, string usrn2)
{
  int i = findID(usrn1);
  if(i == -1)
  {
    return false;
  }
  else
  {
    for(int j = 0; j < numUsers; j++)
    {
      if((profiles[j]).getUsername() == usrn2)
      {
        following[i][j] = true;
        return true;
      }
    }
  }
  
  return false;
}

void Network::printDot()
{
  cout << "digraph {" << endl;
  for(int i = 0; i < numUsers; i++)
  {
    cout << "\t\"@" << profiles[i].getUsername() << "\"" << endl;
  }
  
  for(int i = 0; i < numUsers; i++)
  {
    for(int j = 0; j < numUsers; j++)
    {
      if(following[i][j] == true)
      {
        cout << "\t\"@" << profiles[i].getUsername() << "\"" 
                    << " -> " << "\"@" << profiles[j].getUsername() << "\"" << endl;
      }
    }
  }
  cout << "}" << endl;
}
