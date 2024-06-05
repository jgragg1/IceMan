#include "Actor.h"
#include "StudentWorld.h"
#include <vector>

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp
Protestor::Protestor(std::vector<std::vector<Ice*>> ice, GameWorld* m, std::vector<GameObject*> stuff) :Actor(30,55 , IID_PROTESTER,left),
k(ice), world(m), hitpoints(5), numSquaresToMoveInCurrentDirection(rand()%52+8 ), leave_the_oilfield(false), 
ticks(0),worldStuff(stuff){};
/*
void Protestor::doSomething() {
	if (getX() < 1) {
		setDirection(right);
		moveTo(getX() + 1, getY());
	}
	if (getX() > 55) {
		setDirection(left);
		moveTo(getX() - 1, getY());
	}
	if (getY() < 1) {
		setDirection(up);
		moveTo(getX(), getY()+1);
	}
	if (getY() > 55) {
		setDirection(down);
		moveTo(getX(), getY()-1);
	}
	if(numSquaresToMoveInCurrentDirection>0) {
		world->setGameStatText(std::to_string(numSquaresToMoveInCurrentDirection));
		if (this->getDirection() == left) {
			for (int i = 4; i >= 0; --i) {
				if ((k[getX() - 1][getY()-i]->isVisible())) {
				//	numSquaresToMoveInCurrentDirection = 0;
					setDirection(down);
					return;
				}
			}
			moveTo(this->getX() - 1, this->getY());
		}
		if (this->getDirection() == right) {
			for (int i = 4; i >= 0; --i) {
				if ((k[getX() + 1][getY()+i]->isVisible())) {
					//numSquaresToMoveInCurrentDirection = 0;
					setDirection(up);
					return;
				}
				moveTo(this->getX() + 1, this->getY());
			}
		}
		if (this->getDirection() == up) {
			for (int i = 4; i >= 0; --i) {
				if (k[getX()+i][getY() + 1]->isVisible()) {
					setDirection(left);
					return;
				}
			}
			moveTo(this->getX() , this->getY()+1);
		}
		if (this->getDirection() == down) {
			for (int i = 4; i >= 0; --i) {
				if (k[getX()+i][getY() - 1]->isVisible()) {
					setDirection(right);
					return;
				}
			}
			moveTo(this->getX(), this->getY() - 1);
		}
		
		
	}
	if (numSquaresToMoveInCurrentDirection == 0) {
		numSquaresToMoveInCurrentDirection--;
		numSquaresToMoveInCurrentDirection = rand() % 52 + 8;
		if (getDirection() == left) {
			setDirection(down);
			return;

		}
		if (getDirection() == down) {
			setDirection(right);
			return;

		}
		if (getDirection() == right) {
			setDirection(up);
			return;
		}
		if (getDirection() == up) {
			setDirection(left);
			return;
		}
		
	}
	
	numSquaresToMoveInCurrentDirection--;
}

*/

void Protestor::doSomething() {
	
	ticks++;
	int d = ticks % 15;
	//world->setGameStatText(std::to_string(d));
	if (!(ticks % (3 - (world->getLevel()) / 4) == 0)) {

		return;
	}
	if (!checkIfAlive()) {
		return;
	}
	int billx = getX() - worldStuff.front()->getX();
	int billy = getY() - worldStuff.front()->getY();
	world->setGameStatText(std::to_string(getX()) + "  " + std::to_string(worldStuff.front()->getX()) + "\n"
		+ std::to_string(getDirection()) + "  " + std::to_string(billx) + "  " + std::to_string(d));
/*
	if (billx >= 4 || billx <= -4 && billy == 0) {
		if (getDirection() == left) {
			if (billy == 0) {
				//world->setGameStatText(std::to_string(billx));
				if (billx == 4) {
					world->setGameStatText(std::to_string(billx));
					if (d == 3) {
						world->setGameStatText("heeeeeeeeeeeeeeeeeeeeeeeeey");
						world->playSound(SOUND_PROTESTER_YELL);
						worldStuff.front()->annoy();
						return;
					}
					return;
				}
				return;
			}return;
		}
		if (getDirection() == right) {
			if (billy == 0) {
				//world->setGameStatText(std::to_string(billx));
				if (billx == -4) {
					world->setGameStatText(std::to_string(billx));
					if (d == 3) {
						world->setGameStatText("heeeeeeeeeeeeeeeeeeeeeeeeey");
						world->playSound(SOUND_PROTESTER_YELL);
						worldStuff.front()->annoy();
						return;
					}
					return;
				}
				return;
			}return;
		}
	}

	*/

	if ((billy == 4) && billx == 0) {
		if (getDirection() == down) {

			//world->setGameStatText(std::to_string(billx));
			if (billy == 4) {
				world->setGameStatText(std::to_string(billx));
				if (d == 3) {
					world->setGameStatText("heeeeeeeeeeeeeeeeeeeeeeeeey");
					world->playSound(SOUND_PROTESTER_YELL);
					worldStuff.front()->annoy();
					return;
				}
				return;
			}
			return;

		}
	}
	if ((billy == -4) && billx == 0) {
		if (getDirection() == up) {

			//world->setGameStatText(std::to_string(billx));
			if (billy == -4) {
				world->setGameStatText(std::to_string(billx));
				if (d == 3) {
					world->setGameStatText("heeeeeeeeeeeeeeeeeeeeeeeeey");
					world->playSound(SOUND_PROTESTER_YELL);
					worldStuff.front()->annoy();
					return;
				}
				return;
			}
			return;

		}
	}
	if ((billx ==4) && billy == 0) {
		if (getDirection() == left) {

			//world->setGameStatText(std::to_string(billx));
			if (billx == 4) {
				//world->setGameStatText(std::to_string(billx));
				if (d == 3) {
					//world->setGameStatText("heeeeeeeeeeeeeeeeeeeeeeeeey");
					world->playSound(SOUND_PROTESTER_YELL);
					worldStuff.front()->annoy();
					return;
				}
				return;
			}
			return;

		}
	}
	if (( billx == -4) && billy == 0) {
			if (getDirection() == right) {
				
					//world->setGameStatText(std::to_string(billx));
					if (billx == -4) {
						world->setGameStatText(std::to_string(billx));
						if (d == 3) {
							world->setGameStatText("heeeeeeeeeeeeeeeeeeeeeeeeey");
							world->playSound(SOUND_PROTESTER_YELL);
							worldStuff.front()->annoy();
							return;
						}
						return;
					}
					return;
				
			}
		}
	if (billx == 0 || billy == 0) {
		if (billx == 0&& billy!=0) {
			if (billy>0) {
				
				
				if (!(getX() > 0 || getX() < 60 || getY() > 0 || getY() < 60)) {
					
						//world->setGameStatText("ss");
						setDirection(down);

						return;
					
				}
				for (int i = 0; i <= 3; i++) {
					if (getY() - 1 <= 0||getX()+i>60) {
						return;
					}
					if (k[getX()+i][getY() - 1]->isVisible()) {
						setDirection(down);
						return;
					}
				}setDirection(down);
				moveTo(getX(), getY() - 1);
				numSquaresToMoveInCurrentDirection = 1;
				return;
			}
			if (billy < 0) {
				setDirection(up);
				if (!(getX() > 0 || getX() < 60 || getY() > 0 || getY() < 60)) {
					return;
				}
				for (int i = 0; i <= 3; i++) {
					if (getY() + 4 >= 60||getX()+i>=60) {
						return;
					}
				
					if (k[getX()+i][getY() + 4]->isVisible()) {
						setDirection(up);
						return;
					}
				}
				moveTo(getX(), getY() + 1);
				numSquaresToMoveInCurrentDirection = 1;
				return;
			}
		}
		if (billy == 0 && billx != 0) {
			if (billx > 0) {
				setDirection(left);
				if (!(getX() > 0 || getX() < 60 || getY() > 0 || getY() < 60)) {
					
					return;
				}
				for (int i = 0; i <= 3; i++) {
					if (getX() - 1 <= 0||getY()+i<=0) {
						return;
					}
					if (k[getX() - 1][getY()+i]->isVisible()) {
						setDirection(left);
						return;
					}
				}
				moveTo(getX()-1, getY());
				numSquaresToMoveInCurrentDirection = 1;
				return;
			}
			if (billx < 0) {
				setDirection(right);
				if (!(getX() > 0 || getX() < 60 || getY() > 0 || getY() < 60)) {
					return;
				}
				for (int i = 0; i <= 3; i++) {
				if (getX() + 4 > 60||getY()+i>=60) {
					return;
				}
				if (k[getX() + 4][getY()+i]->isVisible()) {
					setDirection(right);
					return;
				}
			}
				moveTo(getX()+1, getY());
				
				numSquaresToMoveInCurrentDirection = 1;
				return;
			}
		}

	}
		numSquaresToMoveInCurrentDirection--;
		if (numSquaresToMoveInCurrentDirection == 0) {
			if (getDirection() == down) {
				setDirection(left);
				numSquaresToMoveInCurrentDirection = (rand() % 52 + 8);
				return;

			}
			if (getDirection() == left) {
				setDirection(up);
				numSquaresToMoveInCurrentDirection = (rand() % 52 + 8);
				return;

			}

			if (getDirection() == up) {
				setDirection(right);
				numSquaresToMoveInCurrentDirection = (rand() % 52 + 8);
				return;

			}
			if (getDirection() == right) {
				setDirection(down);
				numSquaresToMoveInCurrentDirection = (rand() % 52 + 8);
				return;

			}
		}

		if (getX() <= 0 || getY() <= 0 || getX() >= 60 || getY() >= 60) {
			if (getX() <= 0) {
				moveTo(getX() + 2, getY());
			}
			if (getX() >= 60) {
				moveTo(getX() - 2, getY());
			}
			if (getY() <= 0) {
				moveTo(getX(), getY()+3);
			}
			if (getY() >= 60) {
				moveTo(getX() , getY()-2);
			}
			numSquaresToMoveInCurrentDirection = 5;
			return;
		}
		if (getDirection() == down) {
			//	world->setGameStatText(std::to_string(getDirection()) + "downfacing" + std::to_string(getX()));
			if (getY() > 0 || getY() < 60) {
				if (k[getX()][getY() - 1]->isVisible() == false) {
					moveTo(getX(), getY() - 1);

					return;
				}
				else {
					numSquaresToMoveInCurrentDirection = 1;
				}
			}
		}
		if (getDirection() == right) {
			//world->setGameStatText(std::to_string(getDirection()) + "rightfacing" + std::to_string(getX()));
			if (getX() > 0 || getX() < 60) {
				if (k[getX()+4][getY()]->isVisible() == false) {
					moveTo(getX() + 1, getY());

					return;
				}
				else {
					numSquaresToMoveInCurrentDirection = 1;
				}

			}
		}
		if (getDirection() == left) {
			//world->setGameStatText(std::to_string(getDirection()) + "leftfacing" + std::to_string(getX()));
			if (getY() > 0 || getY() < 60) {
				if (getX() <= 0) {
					moveTo(getX() - 1, getY());
					return;
				}
				if (k[getX() - 1][getY()]->isVisible() == false) {
					moveTo(getX() - 1, getY());
				}
				else {
					numSquaresToMoveInCurrentDirection = 1;
				}
			}

		}
		if (getDirection() == up) {
			//world->setGameStatText(std::to_string(getDirection()) + "upfacing" + std::to_string(getX()));
			if (getY() > 0 && getY() < 59) {
				
				
				if (getY() + 4 > 59) {
					return;
				}
				if (k[getX()][getY() + 4]->isVisible() == false) {
					moveTo(getX(), getY() + 1);
					return;
				}
				else {
					numSquaresToMoveInCurrentDirection = 1;
				}
			}

		}


		else {
			leave_the_oilfield = true;
		}
		if (leave_the_oilfield == true) {
			//find path to 60,60 then die
			if (getX() == 60 && getY() == 60) {
				kill();
			}
		}

	}

Iceman::Iceman(std::vector<std::vector<Ice*>> ice, GameWorld* m) :Actor(30, 60, IID_PLAYER,right), k(ice), 
world(m), hitpoints(10), water(5),sonar(1),gold(0) {  };
  void Iceman::doSomething() {

	  if (!checkIfAlive()) {
		  return;
	  }
	  
	  int key;
	  world->getKey(key);
	Iceman *bill = this;
	int billx;
	int billy;

	bool soundcheck = false;
	billx = bill->getX();
	billy = bill->getY();
	//clears ice if iceman is ontop of it
	for (int i = 4; i != 0; i--) {
		billy = bill->getY();
		for (int i = 4; i != 0; i--) {
			if (billx >= 0 && billx <= 59 && billy <= 59 && billy >= 0)
				if (k[billx][billy] != nullptr) {
					if (k[billx][billy]->isVisible() == true) {
						k[billx][billy]->setVisible(false);
						if (soundcheck == false) {
							world->playSound(SOUND_DIG);
							soundcheck = true;
						}
					}
					
					//delete k[billx][billy];
					k[billx][billy] = nullptr;

				}
			billy++;

		}billx++;
	}

	//resets ice man current coordinates
	billx = bill->getX();
	billy = bill->getY();
	
	if (key == KEY_PRESS_SPACE) {
		//make squirt later
		
		world->playSound(SOUND_PLAYER_SQUIRT);
	}
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
					if (k[billx][billy]->isVisible() == true) {
						k[billx][billy]->setVisible(false);
						if (soundcheck == false) {
							world->playSound(SOUND_DIG);
							soundcheck = true;
						}
					}
					//delete k[billx][billy];
					k[billx][billy] = nullptr;
		//			std::cout << billx << "    " << billy << "   " <<k[billx][billy]<< std::endl;
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
						if (k[billx][billy]->isVisible() == true) {
							k[billx][billy]->setVisible(false);
							if (soundcheck == false) {
								world->playSound(SOUND_DIG);
								soundcheck = true;
							}
						}
						//delete k[billx][billy];
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
					if (k[billx][billy]->isVisible() == true) {
						k[billx][billy]->setVisible(false);
						if (soundcheck == false) {
							world->playSound(SOUND_DIG);
							soundcheck = true;
						}
					}
					//delete k[billx][billy];
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
					if (k[billx][billy]->isVisible() == true) {
						k[billx][billy]->setVisible(false);
						if (soundcheck == false) {
							world->playSound(SOUND_DIG);
							soundcheck = true;
						}
					}
					//delete k[billx][billy];
					k[billx][billy] = nullptr;

				}
			billy++;
		}

	}

}

void Iceman::annoy() {
	hitpoints -= 2;
	if (hitpoints <= 0) {
		kill();
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
	 