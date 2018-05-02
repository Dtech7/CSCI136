/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 11F
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

struct Particle
{
  Coord3D pos;
  Coord3D vel;
};

Coord3D getPosition(Particle *p);
void move(Particle *p, double dt);
void deleteParticle(Particle *p);
Particle* createParticle(double x, double y, double z, 
                         double vx, double vy, double vz);
void setVelocity(Particle *p, double vx, double vy, double vz);

int main()
{
  // make new particle
  Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
  double time = 0.0;
  double dt = 0.1;
  while(time < 3.0)
  {
    // update its velocity
    setVelocity(p, 10.0 * time, 0.3, 0.1);
    
    // move the particle
    move(p, dt);
    time += dt;

    // reporting its coordinates
    cout << "Time: " << time << " \t";
    cout << "Position: "
         << getPosition(p).x << ", "
         << getPosition(p).y << ", "
         << getPosition(p).z << endl;
  }
  // remove the particle, deallocating its memory
  deleteParticle(p);

  return 0;
}

Particle* createParticle(double x, double y, double z, 
                         double vx, double vy, double vz)
{
  Particle *p = new Particle;
  
  (p->pos).x = x;
  (p->pos).y = y;
  (p->pos).z = z;
  
  (p->vel).x = vx;
  (p->vel).y = vy;
  (p->vel).z = vz;
 
  return p;
}

void setVelocity(Particle *p, double vx, double vy, double vz)
{
  (p->vel).x = vx;
  (p->vel).y = vy;
  (p->vel).z = vz;
}

Coord3D getPosition(Particle *p)
{
  return p->pos;
}

void move(Particle *p, double dt)
{
  (p->pos).x = (p->pos).x + ((p->vel).x * dt);
  (p->pos).y = (p->pos).y + ((p->vel).y * dt);
  (p->pos).z = (p->pos).z + ((p->vel).z * dt);
}

void deleteParticle(Particle *p)
{
  delete p;
}                
