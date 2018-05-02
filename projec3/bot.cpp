/*
Author: Neil Felix
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3: Space Debris Collection
Bots check cardinal and intercardinal directions for debris.
If no debris is found at any of the direction,
the bot will move in a random direction.
//h
//h
//h
//h
//
*/
#include <cstdlib>
#include <iostream>
#include "bot.h"
#include <stdlib.h>

using namespace std;

const int MAX_ROBOT_NUM = 50;

int NUM;          // to remember number or robots
int ROWS, COLS;   // map dimensions

/* Initialization procedure, called when the game starts: */
void onStart(int num, int rows, int cols, double mpr,
             Area &area, ostream &log)
{
	NUM = num;   // save the number of robots and the map dimensions
	ROWS = rows;
	COLS = cols;

	log << "Start!" << endl;
}

/* Deciding robot's next move */
Action onRobotAction(int id, Loc loc, Area &area, ostream &log)
{
  int scan(int id, Loc loc, Area &area);
	int row = loc.r; // current row and column
	int col = loc.c;

	if (area.inspect(row, col) == DEBRIS)
		return COLLECT;
	else
	{
	
		
		switch(scan(id, loc, area))
		{
		  case 0:
			  return LEFT;
		  case 1:
			  return RIGHT;
		  case 2:
			  return UP;
		  default:
			  return DOWN;
		}
	} 
}

void onRobotMalfunction(int id, Loc loc, Area &area, ostream &log)
{
	log << "Robot " << id << " is damaged." << endl;
}

void onClockTick(int time, ostream &log)
{
	if (time % 100 == 0) log << time << " ";
}

int areaScan(int id, Loc loc, Area &area)
{
  int row = loc.r;
	int col = loc.c;
	int nextMove;
	
	if(area.inspect(nrow-1, ncol) == DEBRIS)
	{
	  
	}
}
//scans large area
int scan(int id, Loc loc, Area &area)
{
  Loc nearestLoc(int id, Loc *locP, Loc loc, int arI);
  
  int row = loc.r;
	int col = loc.c;
	int nextMove;
	int arI = 0;
	Loc tempLoc[25];
	Loc *locAr;
	Loc nrstLoc;
  
  
  for(int nrow = (row-2); nrow <= (row+2); nrow++)
  {
    for(int ncol = (col-2); ncol <= (col+2); ncol++)
    {
      if(area.inspect(nrow, ncol) == DEBRIS)
      {
        tempLoc[arI].r = nrow;
        tempLoc[arI].c = ncol;
        arI += 1;
      } 
    }
  }
  
  locAr = new Loc[arI];
  for(int i = 0; i < arI; i++)
  {
    locAr[i] = tempLoc[i];
  }
  
  nrstLoc = nearestLoc(id, locAr, loc, arI);
  
  if(nrstLoc.r > loc.r)
  {
    nextMove = 4;
  }
  else if(nrstLoc.r < loc.r)
  {
    nextMove = 2;
  }
  else if(nrstLoc.r == loc.r)
  {
    if(nrstLoc.c > loc.c)
    {
      nextMove = 1; 
    }
    else if(nrstLoc.c < loc.c)
    {
      nextMove = 0;
    }
  }
  
  return nextMove;
}

Loc nearestLoc(int id, Loc *locP, Loc loc, int arI)
{
  int curDist;
  int nrstDist = 100;
  Loc nrstLoc;
  
  for(int i=0; i < arI; i++)
  {
    curDist = abs((locP[i].r + locP[i].c) - (loc.r + loc.c));
    if(curDist < nrstDist)
    {
      nrstLoc = locP[i];
      nrstDist = curDist;
    }
  }
  
  return nrstLoc;
}



