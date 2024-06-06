#include "Actor.h"
#include "StudentWorld.h"
#include <vector>
#include <queue>

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp
Protestor::Protestor(std::vector<std::vector<Ice*>> ice, GameWorld* m, std::vector<GameObject*> stuff,int id) :Actor(30,55 , id,left),
k(ice), world(m), hitpoints(5), numSquaresToMoveInCurrentDirection(rand()%52+8 ), leave_the_oilfield(false), 
ticks(0),worldStuff(stuff),isthereotherescapeoptions(true) 
{
	annoyNumber = (100 - world->getLevel() * 10);
	if (annoyNumber > 50) {
		annoyNumber = 50;
}
for (int i = 0; i != 61; i++) {
	for (int j = 0; j != 61; j++) {
		pathfinder[i][j] = -1;
		
	}
}
};
HardcoreProtestor::HardcoreProtestor(std::vector<std::vector<Ice*>> ice, GameWorld* m, std::vector<GameObject*> stuff,int id):Protestor(ice, m, stuff,id)
,k(ice), world(m), hitpoints(5), numSquaresToMoveInCurrentDirection(rand() % 52 + 8), leave_the_oilfield(false),
ticks(0), worldStuff(stuff), isthereotherescapeoptions(true)
{
	annoyNumber = (100 - world->getLevel() * 10);
	if (annoyNumber > 50) {
		annoyNumber = 50;
	}
	for (int i = 0; i != 61; i++) {
		for (int j = 0; j != 61; j++) {
			pathfinder[i][j] = -1;

		}
	}
};
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
 void Protestor::findpath(pathnode node) {
	
	std::queue<pathnode> q;
	pathnode b;
	
	
	q.push(node);
	while (!q.empty()) {

		b = q.front();

		q.pop();
	
		if (b.x == getX() && b.y == getY()) {
			//std::cout << "\n found " << getX() << " " <<getY()<<" " << std::endl;
			
			return ;
		}
		if (b.x > 60 || b.x < 0 || b.y>60 || b.y < 0) {
			//std::cout << "\n out of bounds " << getX() << " " << getY() << " " << std::endl;
			b.pos = -2;
			pathfinder[b.x][b.y] = -2;
		}
		if (b.x <= 59 && b.x >= 0 && b.y <= 59 && b.y >= 0&&b.pos>0) {
			std::cout << b.x << b.y << std::endl;
			if (k[b.x][b.y]->isVisible()) {

				b.pos = -2;
				pathfinder[b.x][b.y] = -2; 
				continue;
				
			}
		}

		
	//	std::cout << std::endl;
	//	std::cout << pathfinder[b.x-1][b.y-1]<< "   " << b.x << "\n" << std::endl;
	//	std::cout << std::endl;
		
		pathfinder[b.x][b.y] = b.pos;
		if (pathfinder[b.x][b.y+1] == -1) {
			pathnode up;
			up.x = b.x;
			up.y = b.y + 1;
			up.pos = b.pos + 1;
			
			q.push(up);
		}
		if (pathfinder[b.x][b.y - 1] == -1) {
			pathnode down;
			down.x = b.x;
			down.y = b.y - 1;
			down.pos = b.pos + 1;
			pathfinder[down.x][down.y]=down.pos;
			q.push(down);
		}
		if (pathfinder[b.x+1][b.y] == -1) {
			pathnode right;
			right.x = b.x+1;
			right.y = b.y;
			right.pos = b.pos + 1;
			pathfinder[right.x][right.y]=right.pos;
			q.push(right);
		}
		if (pathfinder[b.x-1][b.y] == -1) {
			pathnode left;
			left.x = b.x-1;
			left.y = b.y;
			left.pos = b.pos + 1;
			pathfinder[left.x][left.y]=left.pos;
			q.push(left);
		}
		//if(q.empty())
		//std::cout << "hi";
	}
	
	
}


 void HardcoreProtestor::findpath(pathnode node) {

	std::queue<pathnode> q;
	pathnode b;


	q.push(node);
	while (!q.empty()) {

		b = q.front();

		q.pop();

		if (b.x == getX() && b.y == getY()) {
			//std::cout << "\n found " << getX() << " " <<getY()<<" " << std::endl;

			return;
		}
		if (b.x > 60 || b.x < 0 || b.y>60 || b.y < 0) {
			//std::cout << "\n out of bounds " << getX() << " " << getY() << " " << std::endl;
			b.pos = -2;
			pathfinder[b.x][b.y] = -2;
		}
		if (b.x <= 59 && b.x >= 0 && b.y <= 59 && b.y >= 0 && b.pos > 0) {
			std::cout << b.x << b.y << std::endl;
			if (k[b.x][b.y]->isVisible()) {

				b.pos = -2;
				pathfinder[b.x][b.y] = -2;
				continue;

			}
		}


		//	std::cout << std::endl;
		//	std::cout << pathfinder[b.x-1][b.y-1]<< "   " << b.x << "\n" << std::endl;
		//	std::cout << std::endl;

		pathfinder[b.x][b.y] = b.pos;
		if (pathfinder[b.x][b.y + 1] == -1) {
			pathnode up;
			up.x = b.x;
			up.y = b.y + 1;
			up.pos = b.pos + 1;

			q.push(up);
		}
		if (pathfinder[b.x][b.y - 1] == -1) {
			pathnode down;
			down.x = b.x;
			down.y = b.y - 1;
			down.pos = b.pos + 1;
			pathfinder[down.x][down.y] = down.pos;
			q.push(down);
		}
		if (pathfinder[b.x + 1][b.y] == -1) {
			pathnode right;
			right.x = b.x + 1;
			right.y = b.y;
			right.pos = b.pos + 1;
			pathfinder[right.x][right.y] = right.pos;
			q.push(right);
		}
		if (pathfinder[b.x - 1][b.y] == -1) {
			pathnode left;
			left.x = b.x - 1;
			left.y = b.y;
			left.pos = b.pos + 1;
			pathfinder[left.x][left.y] = left.pos;
			q.push(left);
		}
		//if(q.empty())
		//std::cout << "hi";
	}


}
void Protestor::doSomething() {
	/*
	if (ticks == 2) {
		pathnode node;
		//pathfinder[23][40] = 5;
		node.pos = 1;
		node.x = 60;
		node.y = 60;

		findpath(node);
	for (int i = 60; i != 25; i--) {
		for (int j = 60; j != 25; j--) {
			if (pathfinder[i][j] != -1) {
				//std::cout << std::endl;
			}
			std::cout << "  "<<pathfinder[i][j];
		}std::cout << std::endl;
	}
}
*/
	ticks++;
	if (!(ticks % (3 - (world->getLevel()) / 4) == 0)) {

		return;
	}
	if (checkIfAnnoyed()) {
		static int ann = 0;
		ann++;
		if (ann % annoyNumber != 0) {
			return;
		}
		world->playSound(SOUND_PLAYER_ANNOYED);
		unannoy();
	}
	int yy=worldStuff.front()->getY();
	
	if (leave_the_oilfield) {
		world->setGameStatText(std::to_string(getY()));
		int current = pathfinder[getX()][getY()];
		int up1 = pathfinder[getX()][getY() + 1];
		int down1 = pathfinder[getX()][getY() - 1];
		int left1 = pathfinder[getX() - 1][getY()];
		int right1 = pathfinder[getX() + 1][getY()];
		if (getX() != 60&&getY()==60) {
			moveTo(getX() + 1, 60);
			if (getX() == 60) {
				kill();
			}
			return;
		}
		

		//  world->setGameStatText("pursuit" + std::to_string(up) + std::to_string(down) + std::to_string(right)+std::to_string(left));
		if (current > down1 && down1 >= 0) {
			setDirection(down);
			moveTo(getX(), getY() - 1);
			return;
		}
		if (current > left1 && left1 >= 0) {
			setDirection(left);
			moveTo(getX() - 1, getY());
			return;
		}
		if (current > right1 && right1 >= 0) {
			setDirection(right);
			moveTo(getX() + 1, getY() + 1);
			return;
		}
		if (current > up1 && up1 >= 0) {
			setDirection(up);
			moveTo(getX(), getY() + 1);
			return;
		}
		std::cout << current;
		std::cout << up;
		std::cout << down;
		std::cout << right;
		std::cout << left;



		/*
		if (isthereotherescapeoptions) {
			for (int top = 0; top != 60; top++) {
				if (top > 29 && top < 34) {
					top = 34;
				}
				if (!(k[top][59]->isVisible())); {
					isthereotherescapeoptions = false;
					moveTo(30, getY());
				}


			}
		}
		if (!isthereotherescapeoptions) {
			
			if (getY() != 60) {
				moveTo(getX(), getY() + 1);
				return;
			}
			if (getX() != 60) {
				moveTo(getX() + 1, 60);
				return;
			}
		}
	*/
		
		
		
	}
	
	
	if (hitpoints <= 0) {
			leave_the_oilfield = true;
			pathnode p;
			p.x = 60; p.y = 60; p.pos = 1;
			findpath(p);
			return;
		}
	//ticks++;
	int d = ticks % 15;
	if (leave_the_oilfield) {
		return;
	}
	//world->setGameStatText(std::to_string(d));
	
	if (!checkIfAlive()) {
		return;
	}
	int billx = getX() - worldStuff.front()->getX();
	int billy = getY() - worldStuff.front()->getY();
	world->setGameStatText(std::to_string(getX()) + "  " + std::to_string(worldStuff.front()->getY()) + "\n"
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
world->playSound(SOUND_PLAYER_ANNOYED);
	if (hitpoints <= 0) {
		world->playSound(SOUND_PLAYER_GIVE_UP);
		kill();
		return;
	}
	
}

  GameObject::GameObject(int imageID, int startX, int startY, Direction dir = right, double size = 1.0, unsigned int depth = 0) :
	  GraphObject(imageID, startX, startY, dir, size, depth), annoyed(false), alive(true) {
	  setVisible(true);
  }
	  bool GameObject::checkIfAnnoyed() {
		  
		  return annoyed;
	  }
	  void GameObject::unannoy() {
		  annoyed = false;
		  
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
	

	  void HardcoreProtestor::doSomething() {
		  
		
	  
	  
		  ticks++;
		  if (!(ticks % (3 - (world->getLevel()) / 4) == 0)) {

			  return;
		  }
		  if (checkIfAnnoyed()) {
			  static int ann = 0;
			  ann++;
			  if (ann % annoyNumber != 0) {
				  return;
			  }
			  world->playSound(SOUND_PLAYER_ANNOYED);
			  unannoy();
		  }
		  int yy = worldStuff.front()->getY() - getY();
		  int xx = worldStuff.front()->getX() - getX();

		  if (yy < 0) {
			  yy *= -1;
		  }
		  if (xx < 0) {
			  xx *= -1;
		  }

		 


		  if (leave_the_oilfield) {
			  world->setGameStatText(std::to_string(getY()));
			  int current = pathfinder[getX()][getY()];
			  int up = pathfinder[getX()][getY() + 1];
			  int down = pathfinder[getX()][getY() - 1];
			  int left = pathfinder[getX() - 1][getY()];
			  int right = pathfinder[getX() + 1][getY()];
			  if (getX() != 60 && getY() == 60) {
				  moveTo(getX() + 1, 60);
				  if (getX() == 60) {
					  kill();
				  }
				  return;
			  }

			  if (current > down && down >= 0) {
				  moveTo(getX(), getY() - 1);
				  return;
			  }
			  if (current > left && left >= 0) {
				  moveTo(getX() - 1, getY());
				  return;
			  }
			  if (current > right && right >= 0) {
				  moveTo(getX() + 1, getY() + 1);
				  return;
			  }
			  if (current > up && up >= 0) {
				  moveTo(getX(), getY() + 1);
				  return;
			  }
			


			  /*
			  if (isthereotherescapeoptions) {
				  for (int top = 0; top != 60; top++) {
					  if (top > 29 && top < 34) {
						  top = 34;
					  }
					  if (!(k[top][59]->isVisible())); {
						  isthereotherescapeoptions = false;
						  moveTo(30, getY());
					  }


				  }
			  }
			  if (!isthereotherescapeoptions) {

				  if (getY() != 60) {
					  moveTo(getX(), getY() + 1);
					  return;
				  }
				  if (getX() != 60) {
					  moveTo(getX() + 1, 60);
					  return;
				  }
			  }
		  */



		  }


		  if (hitpoints <= 0) {
			  leave_the_oilfield = true;
			  pathnode p;
			  p.x = 60; p.y = 60; p.pos = 1;
			  findpath(p);
			  return;
		  }
		  //ticks++;
		  int d = ticks % 15;
		  if (leave_the_oilfield) {
			  return;
		  }
		  //world->setGameStatText(std::to_string(d));

		  if (!checkIfAlive()) {
			  return;
		  }
		  int billx = getX() - worldStuff.front()->getX();
		  int billy = getY() - worldStuff.front()->getY();
		//  world->setGameStatText(std::to_string(getX()) + "  " + std::to_string(worldStuff.front()->getY()) + "\n"
			//  + std::to_string(getDirection()) + "  " + std::to_string(billx) + "  " + std::to_string(d));
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
					  //world->setGameStatText(std::to_string(billx));
					  if (d == 3) {
						//  world->setGameStatText("heeeeeeeeeeeeeeeeeeeeeeeeey");
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
						//  world->setGameStatText("heeeeeeeeeeeeeeeeeeeeeeeeey");
						  world->playSound(SOUND_PROTESTER_YELL);
						  worldStuff.front()->annoy();
						  return;
					  }
					  return;
				  }
				  return;

			  }
		  }
		  if ((billx == 4) && billy == 0) {
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
		  if ((billx == -4) && billy == 0) {
			  if (getDirection() == right) {

				  //world->setGameStatText(std::to_string(billx));
				  if (billx == -4) {
				//	  world->setGameStatText(std::to_string(billx));
					  if (d == 3) {
					//	  world->setGameStatText("heeeeeeeeeeeeeeeeeeeeeeeeey");
						  world->playSound(SOUND_PROTESTER_YELL);
						  worldStuff.front()->annoy();
						  return;
					  }
					  return;
				  }
				  return;

			  }
		  }

		  
		  if ((xx <= 16 || yy <=16)&&(xx!=0||yy!=0)&&getY()<60&&worldStuff.front()->getY()<60) {
			  for (int i = 0; i != 61; i++) {
				  for (int j = 0; j != 61; j++) {
					  pathfinder[i][j] = -1;

				  }
			  }
			  //world->setGameStatText("pursuit");
			  pathnode p;
			  p.x = worldStuff.front()->getX();
			  p.y = worldStuff.front()->getY();
			  p.pos = 1;
			  findpath(p);
			  
			  int current = pathfinder[getX()][getY()];
			  int up1 = pathfinder[getX()][getY() + 1];
			  int down1 = pathfinder[getX()][getY() - 1];
			  int left1 = pathfinder[getX() - 1][getY()];
			  int right1 = pathfinder[getX() + 1][getY()];
			  
			//  world->setGameStatText("pursuit" + std::to_string(up) + std::to_string(down) + std::to_string(right)+std::to_string(left));
			  if (current > down1 && down1 >= 0) {
				  setDirection(down);
				  moveTo(getX(), getY() - 1);
				  return;
			  }
			  if (current > left1 && left1 >= 0) {
				  setDirection(left);
				  moveTo(getX() - 1, getY());
				  return;
			  }
			  if (current > right1 && right1 >= 0) {
				  setDirection(right);
				  moveTo(getX() + 1, getY() + 1);
				  return;
			  }
			  if (current > up1 && up1 >= 0) {
				  setDirection(up);
				  moveTo(getX(), getY() + 1);
				  return;
			  }
			  return;
		  }
		  if (billx == 0 || billy == 0) {
			  if (billx == 0 && billy != 0) {
				  if (billy > 0) {


					  if (!(getX() > 0 || getX() < 60 || getY() > 0 || getY() < 60)) {

						  //world->setGameStatText("ss");
						  setDirection(down);

						  return;

					  }
					  for (int i = 0; i <= 3; i++) {
						  if (getY() - 1 <= 0 || getX() + i > 60) {
							  return;
						  }
						  if (k[getX() + i][getY() - 1]->isVisible()) {
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
						  if (getY() + 4 >= 60 || getX() + i >= 60) {
							  return;
						  }

						  if (k[getX() + i][getY() + 4]->isVisible()) {
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
						  if (getX() - 1 <= 0 || getY() + i <= 0) {
							  return;
						  }
						  if (k[getX() - 1][getY() + i]->isVisible()) {
							  setDirection(left);
							  return;
						  }
					  }
					  moveTo(getX() - 1, getY());
					  numSquaresToMoveInCurrentDirection = 1;
					  return;
				  }
				  if (billx < 0) {
					  setDirection(right);
					  if (!(getX() > 0 || getX() < 60 || getY() > 0 || getY() < 60)) {
						  return;
					  }
					  for (int i = 0; i <= 3; i++) {
						  if (getX() + 4 > 60 || getY() + i >= 60) {
							  return;
						  }
						  if (k[getX() + 4][getY() + i]->isVisible()) {
							  setDirection(right);
							  return;
						  }
					  }
					  moveTo(getX() + 1, getY());

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
				  moveTo(getX(), getY() + 3);
			  }
			  if (getY() >= 60) {
				  moveTo(getX(), getY() - 2);
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
				  if (k[getX() + 4][getY()]->isVisible() == false) {
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




	  }
