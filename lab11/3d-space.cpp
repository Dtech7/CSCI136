/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 11 A, B, C, E
h
h
h
*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Coord3D
{
  double x;
  double y;
  double z;
};


double length(Coord3D *p);
void deleteCoord3D(Coord3D *p);
void move(Coord3D *ppos, Coord3D *pvel, double dt);
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2);
Coord3D* createCoord3D(double x, double y, double z);





int main()
{

  /*Task A test 
  Coord3D pointP = {10, 20, 30};
  cout << length(&pointP) << endl; // would print 37.4166
  */
  
  /*Task B test
  Coord3D pointP = {10, 20, 30};
  Coord3D pointQ = {-20, 21, -22};
  cout << "Address of P: " << &pointP << endl;
  cout << "Address of Q: " << &pointQ << endl << endl;
  Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
  cout << "ans = " << ans << endl; // So which point is farther?
  */
  
  /*Task c
  Coord3D pos = {0, 0, 100.0};
  Coord3D vel = {1, -5, 0.2};
  move(&pos, &vel, 2.0); // struct pos gets changed
  cout << pos.x << " " << pos.y << " " << pos.z << endl;
  // prints: 2 -10 100.4
  */
  
  double x, y, z;
  cout << "Enter position: ";
  cin >> x >> y >> z;
  Coord3D *ppos = createCoord3D(x,y,z);
    
  cout << "Enter velocity: ";
  cin >> x >> y >> z;
  Coord3D *pvel = createCoord3D(x,y,z);

  move(ppos, pvel, 10.0);

  cout << "Coordinates after 10 seconds: " 
       << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;

  deleteCoord3D(ppos); // release memory
  deleteCoord3D(pvel);
  
  return 0;
}

double length(Coord3D *p)
{
  double length, sqrd;
  sqrd = pow(p->x, 2) + pow(p->y, 2) + pow(p->z, 2);
  length = sqrt(sqrd);
  
  return length;
}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2)
{
  double l1, l2;
  l1 = length(p1);
  l2 = length(p2);
  
  if(l1 > l2)
  {
    return p1;
  }
  else
  {
    return p2;
  }
  
}

void move(Coord3D *ppos, Coord3D *pvel, double dt)
{
  ppos->x = ppos->x + (pvel->x * dt);
  ppos->y = ppos->y + (pvel->y * dt);
  ppos->z = ppos->z + (pvel->z * dt);
}

Coord3D* createCoord3D(double x, double y, double z)
{
  Coord3D *p = new Coord3D;
  
  p->x = x;
  p->y = y;
  p->z = z;
  
  return p;
}

void deleteCoord3D(Coord3D *p)
{
  delete p;
}
