#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include <vector>
#include"GameWorld.h"

class GameObject : public GraphObject {
public:
	GameObject(int imageID, int startX, int startY, Direction dir, double size, unsigned int depth);// : GraphObject(imageID, startX, startY, dir, size, depth), annoyed(false), alive(true) {}

	virtual void doSomething() = 0;
	bool checkIfAnnoyed();
	bool checkIfAlive();
	void kill();
	void annoy();
private:
	bool annoyed;
	bool alive;
	
};
class Actor :public GameObject {
public:
	Actor(int startingx, int startingy, int gameid, Direction dir) : GameObject(gameid, startingx, startingy, dir, 1.0, 0) {}

	virtual void doSomething() = 0;
	
};

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp
class Ice: public GameObject {
public:
	Ice(int startingx, int startingy) :GameObject(IID_ICE, startingx, startingy, right, 0.25, 3) { };//GraphObject(int imageID, int startX, int startY, Direction dir = right, double size = 1.0, unsigned int depth = 0)

	virtual void doSomething() {}
	
	
	~Ice() {};
};
class Protestor :public Actor {
	public:
		Protestor(std::vector<std::vector<Ice*>> ice, GameWorld* m, std::vector<GameObject*> stuff);
	virtual void doSomething();
	~Protestor() {

	}
	virtual void annoy() {
		hitpoints -= 2;
		if (hitpoints <= 0) {
			kill();
		}
	}
private:
	
	std::vector<GameObject*> worldStuff;
	int tickcounter;
	int ticks;
	bool leave_the_oilfield;
	std::vector<std::vector<Ice*>> k;
	GameWorld* world;
	int hitpoints;
	int numSquaresToMoveInCurrentDirection;
};
class Iceman: public Actor {
public:
	//Iceman() :GraphObject(IID_PLAYER, 30, 60, right, 1, 0) { setVisible(true); };//GraphObject(int imageID, int startX, int startY, Direction dir = right, double size = 1.0, unsigned int depth = 0)
	Iceman(std::vector<std::vector<Ice*>> ice,GameWorld* m);// : Actor(30, 60, IID_PLAYER), k(ice) { setVisible(true); };
	
	virtual void doSomething();
	~Iceman() {
	
	}
private:
	std::vector<std::vector<Ice*>> k;
	GameWorld* world;
	int hitpoints;
	int water;
	int sonar;
	int gold;
};
#endif // ACTOR_H_
