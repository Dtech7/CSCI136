/*
Author: Neil Felix
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 9E
A
A
A
A

*/
#include <iostream>
#include <string>
using namespace std;

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

struct Time {
    int h;
    int m;
};

struct Movie {
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};


struct TimeSlot {
    Movie movie;     // what movie
    Time startTime;  // when it starts
};


void printMovie(Movie mv);
void printTimeSlot(TimeSlot ts);
int minutesUntil(Time t1, Time t2);
int minutesSinceMidnight(Time time);
Time addMinutes(Time time0, int min);
bool timeOverlap(TimeSlot ts1, TimeSlot ts2);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);


int main()
{
/*
  Time t1;
  Time t2;
  int w, x, y, z;
 
  cout << "Enter first time: " << endl;
  cin >> t1.h >> t1.m;
  cout << "Enter second time: " << endl;
  cin >> t2.h >> t2.m;
  cout << "Enter Minutes: "<< endl;
  cin >> w;
  
  t1 = {10, 20};
  t2 = {12, 50};
 
  x = minutesSinceMidnight(t1);
  y = minutesSinceMidnight(t2);
  z = minutesUntil(t1, t2);
  
  cout << "These moments of time are " << x << " and " << y << " minutes after midnight." <<endl;
  cout << "The interval between them " << z << " minutes." << endl;
  
  
  Movie movie1 = {"Back to the Future", COMEDY, 116};
  Movie movie2 = {"Black Panther", ACTION, 134};
  Movie movie3 = {"Blockers", COMEDY, 102};
  Movie movie4 = {"Truth or Dear", THRILLER, 103};
  
  TimeSlot morning = {movie1, {9, 15}};  
  TimeSlot daytime = {movie2, {12, 15}}; 
  TimeSlot evening = {movie2, {16, 45}}; 
  TimeSlot morning2 = {movie3, {8, 25}};
  TimeSlot evening2 = {movie4, {17, 30}};
  */
  
  
  return 0;
}

int minutesSinceMidnight(Time time)
{
  int nMin;
  nMin = (time.h * 60) + time.m;
  return nMin;
}

int minutesUntil(Time t1, Time t2)
{
  int oMin;
  oMin = ((t2.h * 60) + t2.m) - ((t1.h * 60) + t1.m);
  return oMin;
}

Time addMinutes(Time t1, int min)
{
  int nH, nM, tM;
  tM = (t1.h * 60) + min + t1.m;
  
  nH = tM/60;
  t1.h = nH;
  nM = tM%60;
  t1.m = nM;

  return t1;
}

void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}


void printTimeSlot(TimeSlot ts)
{
  Time endTm;
  endTm = addMinutes(ts.startTime, ts.movie.duration);
  
  printMovie(ts.movie);
  cout << " [starts at " << ts.startTime.h << ":"<< ts.startTime.m; 
  cout << ", ends by " << endTm.h << ":" << endTm.m << "]"; 
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
  TimeSlot nxTmSlt;
  nxTmSlt.startTime = addMinutes(ts.startTime, ts.movie.duration);
  nxTmSlt.movie = nextMovie;
  return nxTmSlt;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
	int mv1Stime, mv2Stime, mv1TtlDur, mv2TtlDur;
	Time mv1Etime, mv2Etime;
	
	mv1Stime = minutesSinceMidnight(ts1.startTime);
	mv2Stime = minutesSinceMidnight(ts2.startTime);
	mv1Etime = addMinutes(ts1.startTime, ts1.movie.duration);
	mv2Etime = addMinutes(ts2.startTime, ts2.movie.duration);
	mv1TtlDur = mv1Stime + minutesUntil(ts1.startTime, mv1Etime);
	mv2TtlDur = mv2Stime + minutesUntil(ts2.startTime, mv2Etime);
	
	if(mv1Stime == mv2Stime)
	{
		return true;
	}
	else if(mv2Stime < mv1Stime)
	{
		if(mv1Stime < mv2TtlDur)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if(mv1Stime < mv2Stime)
	{
		if(mv2Stime < mv1TtlDur)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
}
