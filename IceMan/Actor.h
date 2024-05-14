#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include <vector>
#include"GameWorld.h"
class Actor :public GraphObject {
public:
	Actor(int startingx, int startingy, int gameid) : GraphObject(gameid, startingx, startingy, right, 1.0, 0) {}

	virtual void doSomething() = 0;
};

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp
class Ice: public GraphObject {
public:
	Ice(int startingx, int startingy) :GraphObject(IID_ICE, startingx, startingy, right, 0.25, 3) { setVisible(true); };//GraphObject(int imageID, int startX, int startY, Direction dir = right, double size = 1.0, unsigned int depth = 0)


	
	
	
};

class Iceman: public Actor {
public:
	//Iceman() :GraphObject(IID_PLAYER, 30, 60, right, 1, 0) { setVisible(true); };//GraphObject(int imageID, int startX, int startY, Direction dir = right, double size = 1.0, unsigned int depth = 0)
	Iceman(std::vector<std::vector<Ice*>> ice,GameWorld* m);// : Actor(30, 60, IID_PLAYER), k(ice) { setVisible(true); };
	
	virtual void doSomething();

private:
	std::vector<std::vector<Ice*>> k;
	GameWorld* world;
};
#endif // ACTOR_H_
