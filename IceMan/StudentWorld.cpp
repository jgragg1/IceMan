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
			s[i][j] = new Ice(i, j);
			if(j>4)
			if ((i-29)>0&&(i-30)<4) {
				
			//	s[i][j] = nullptr;
				//	continue;
				s[i][j]->setVisible(false);
				
			}
			//s[i][j] = new Ice(i,j);
			
		}
	}
	
	k = s;
	bill = new Iceman(k,this);
	
	vector<GameObject*> stuff;
	
	worldStuff = stuff;worldStuff.push_back(bill);
	Protestor* mike = new Protestor(k, this, worldStuff);
	
	worldStuff.push_back(mike);
	
	
	return 0;
}

 int ss = 100;
 int StudentWorld::move() {
	
	 bill->doSomething();
	 for (auto g : worldStuff) {
		 if (g == bill) {
			 continue;
		 }
		 g->doSomething();
		 if (g->checkIfAlive() == false) {
			 delete g;
		 }
	 }
	 //testing script for clean up currently there is a know bug when clean up 
	 // is called if ice has been broken best solution make ice not visible and
	 //  only delete when the oil field is being deleted will clarify in person if that is allowed
	/*
	 if (ss-- == 12) {
		 decLives();
		 ss = 70;
		 return 0;
	 }
	 */
	 // This code is here merely to allow the game to build, run, and terminate after you hit enter a few times.
	 // Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
	 
	// setGameStatText(to_string(bill->checkIfAlive()));
	 return GWSTATUS_CONTINUE_GAME;
 }

 void StudentWorld::cleanUp() {
	/*
	 
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
	 */
	 
	 for (auto& row : k) {
	
		 for (auto& blockInColumn : row) {
			
			 try {
				 delete blockInColumn;
				 blockInColumn = nullptr; // Set to nullptr after deletion
			 }
			 catch (...) {
				 cout << "Error occurred while deleting pointer.\n";
				 blockInColumn = nullptr;
			 }
		 }
		 row.clear();
	 }
	 k.clear();

	
	 delete bill;
 }

 StudentWorld::~StudentWorld() {
	
	 delete bill;
	 for (auto& row : k) {

		 for (auto& blockInColumn : row) {
			 
			 try {
				 delete blockInColumn;
				 blockInColumn = nullptr; // Set to nullptr after deletion
			 }
			 catch ( ...) {
				 cout << "Error occurred while deleting pointer.\n";
				 blockInColumn = nullptr;
			 }
		 }
		 row.clear();
	 }
	 k.clear();
 }