#include "Actor.h"
#include "StudentWorld.h"
#include <vector>

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp

Iceman::Iceman(std::vector<std::vector<Ice*>> ice, GameWorld* m) :Actor(30, 60, IID_PLAYER), k(ice), world(m), hitpoints(10), water(5),sonar(1),gold(0) {  };
  void Iceman::doSomething() {

	  if (!checkIfAlive()) {
		  return;
	  }
	  
	  int key;
	  world->getKey(key);
	Iceman *bill = this;
	int billx;
	int billy;
	billx = bill->getX();
	billy = bill->getY();
	//clears ice if iceman is ontop of it
	for (int i = 4; i != 0; i--) {
		billy = bill->getY();
		for (int i = 4; i != 0; i--) {
			if (billx >= 0 && billx <= 59 && billy <= 59 && billy >= 0)
				if (k[billx][billy] != nullptr) {
					delete k[billx][billy];
					k[billx][billy] = nullptr;

				}
			billy++;

		}billx++;
	}

	//resets ice man current coordinates
	billx = bill->getX();
	billy = bill->getY();
	if (key == 1001) {
		if (bill->getDirection() != GraphObject::right) {
			bill->setDirection(GraphObject::right);
			return;
		}
		bill->moveTo(bill->getX() + 1, bill->getY());
		billx += 4;
		
		for (int i = 4; i != 0; i--) {
			if (billx >= 0 && billx <= 59 && billy <= 59 && billy >= 0)
				if (k[billx][billy] != nullptr) {
					delete k[billx][billy];
					k[billx][billy] = nullptr;

				}
			billy++;
		}
	}
	if (key == 1002) {
		if (bill->getDirection() != GraphObject::up) {
			bill->setDirection(GraphObject::up);
			return;
		}
		bill->moveTo(bill->getX(), bill->getY() + 1);
		billy += 4;
		

	

			for (int i = 4; i != 0; i--) {
				if (billx >= 0 && billx <= 59 && billy <= 59 && billy >= 0)
					if (k[billx][billy] != nullptr) {
						delete k[billx][billy];
						k[billx][billy] = nullptr;

					}
				billx++;
			}

		
	}
	if (key == 1003) {
		if (bill->getDirection() != GraphObject::down) {
			bill->setDirection(GraphObject::down);
			return;
		}
		bill->moveTo(bill->getX(), bill->getY() - 1);
		
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
	if (key == 1000) {
		if (bill->getDirection() != GraphObject::left) {
			bill->setDirection(GraphObject::left);
			return;
		}
		bill->moveTo(bill->getX() - 1, bill->getY());
		
		billx -= 1;
		for (int i = 4; i != 0; i--) {
			if (billx >= 0 && billx <= 59 && billy <= 59 && billy >= 0)
				if (k[billx][billy] != nullptr) {
					delete k[billx][billy];
					k[billx][billy] = nullptr;

				}
			billy++;
		}

	}

}


  GameObject::GameObject(int imageID, int startX, int startY, Direction dir = right, double size = 1.0, unsigned int depth = 0) :
	  GraphObject(imageID, startX, startY, dir, size, depth), annoyed(false), alive(true) {
	  setVisible(true);
  }
	  bool GameObject::checkIfAnnoyed() {
		  return annoyed;
	  }
	  bool  GameObject::checkIfAlive() {
		  return alive;
	  }
	  void GameObject::kill() {
		  alive = false;
	  }
	  void GameObject::annoy() {
		  annoyed = true;
	  }
  