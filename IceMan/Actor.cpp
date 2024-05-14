#include "Actor.h"
#include "StudentWorld.h"
#include <vector>

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp

Iceman::Iceman(std::vector<std::vector<Ice*>> ice,GameWorld* m) :Actor(30, 60, IID_PLAYER), k(ice),world(m) { setVisible(true); };
  void Iceman::doSomething() {
	  int sss;
	  world->getKey(sss);
	Iceman *bill = this;
	int billx;
	int billy;
	billx = bill->getX();
	billy = bill->getY();
	
	

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
		bill->moveTo(bill->getX(), bill->getY() + 1);
		billy += 4;
		if (bill->getDirection() != GraphObject::up) {
			bill->setDirection(GraphObject::up);
		}

	

			for (int i = 4; i != 0; i--) {
				if (billx >= 0 && billx <= 59 && billy <= 59 && billy >= 0)
					if (k[billx][billy] != nullptr) {
						delete k[billx][billy];
						k[billx][billy] = nullptr;

					}
				billx++;
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

	}

}