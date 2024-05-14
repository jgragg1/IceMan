#include "StudentWorld.h"
#include <string>
#include <vector>
using namespace std;
vector<vector<Ice*>> k(60, vector<Ice*>(60));
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
			if ((i-28)>0&&(i-28)<5) {
				
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
 int StudentWorld::move() {
	/* billx = bill->getX();
	 billy = bill->getY();
	 setGameStatText(to_string(billx) + "  " + to_string(billy));
	 int templives= getLives();
	 getLevel();
	 int sss = 0;
	 getKey(sss);
	 
	 if (sss == 1001) {
		 bill->moveTo(bill->getX() + 1, bill->getY());
		 billx += 4;
		 if (bill->getDirection() != GraphObject::right) {
			 bill->setDirection(GraphObject::right);
			
		 }
		 for (int i = 4; i != 0; i--) {
			 if (billx >= 0 && billx <= 59 && billy <= 59 && billy >= 0)
				 if (k[billx][billy] != nullptr) {
					 delete k[billx][billy];
					 k[billx][billy] = nullptr;

				 }
			 billy++;
		 }
	 }
	 if (sss == 1002) {
		 bill->moveTo(bill->getX(), bill->getY()+1);
		 billy += 4;
		 if (bill->getDirection() != GraphObject::up) {
			 bill->setDirection(GraphObject::up);
		 }

		 if (billx >= 0 && billx <= 59 && billy <= 59 && billy >= 0) {
			 
			 for (int i = 4; i != 0; i--) {
				 if (billx >= 0 && billx <= 59 && billy <= 59 && billy >= 0)
				 if (k[billx][billy] != nullptr) {
					 delete k[billx][billy];
					 k[billx][billy] = nullptr;

				 }
				 billx++;
			}

		 }
	 }
	 if (sss == 1003) {
		 bill->moveTo(bill->getX(), bill->getY() - 1);
		 if (bill->getDirection() != GraphObject::down) {
			 bill->setDirection(GraphObject::down);
		 }
		 billy -= 1;
		 for (int i = 4; i != 0; i--) {
			 if (billx >= 0 && billx <= 59 && billy <= 59 && billy >= 0)
				 if (k[billx][billy] != nullptr) {
					 delete k[billx][billy];
					 k[billx][billy] = nullptr;

				 }
			 billx++;
		 }
	 }
	 if (sss == 1000) {
		 bill->moveTo(bill->getX() - 1, bill->getY());
		 if (bill->getDirection() != GraphObject::left) {
			 bill->setDirection(GraphObject::left);
		}
		 billx -= 1;
		 for (int i = 4; i != 0; i--) {
			 if (billx >= 0 && billx <= 59 && billy <= 59 && billy >= 0)
				 if (k[billx][billy] != nullptr) {
					 delete k[billx][billy];
					 k[billx][billy] = nullptr;

				 }
			 billy++;
		 }

	 }*/
	 int key;
	 bill->doSomething();
	 
	
	 
	 // This code is here merely to allow the game to build, run, and terminate after you hit enter a few times.
	 // Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
	 

	 return GWSTATUS_CONTINUE_GAME;
 }