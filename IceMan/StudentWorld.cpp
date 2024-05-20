#include "StudentWorld.h"
#include <string>
#include <vector>
using namespace std;
//vector<vector<Ice*>> k(60, vector<Ice*>(60)); remove later
GameWorld* createStudentWorld(string assetDir)
{
	return new StudentWorld(assetDir);
}

// Students:  Add code to this file (if you wish), StudentWorld.h, Actor.h and Actor.cpp
 int StudentWorld::init() {
	
	vector<vector<Ice*>> s(60,vector<Ice*>(60));
	for (int i = 0; i < 60; i++) {
		for (int j = 0; j < 60; j++) {
			if(j>4)
			if ((i-29)>0&&(i-30)<4) {
				
				s[i][j] = nullptr;
					continue;
				
				
			}
			s[i][j] = new Ice(i,j);
			
		}
	}
	
	k = s;
	bill = new Iceman(k,this);
	return 0;
}

 int ss = 100;
 int StudentWorld::move() {
	
	 bill->doSomething();
	 
	 
	 if (ss-- == 12) {
		 decLives();
		 ss = 70;
		 return 0;
	 }
	 
	 // This code is here merely to allow the game to build, run, and terminate after you hit enter a few times.
	 // Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
	 

	 return GWSTATUS_CONTINUE_GAME;
 }

 void StudentWorld::cleanUp() {
	
	 
	 int x = 0;
	 int y = 0;
	 for ( x = 59; x != 0; x--) {
		 if (x >= 0 && x <= 59 && y <= 59 && y >= 0)
			 if (k[x][y] != nullptr) {
				 delete k[x][y];
				 k[x][y] = nullptr;

			 }
		 y++;
	 }



	
	 delete bill;
 }