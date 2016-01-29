#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class coordinate{/*{{{*/
	private:
		int X;
		int Y;
		int population;
	public:
		coordinate(int x, int y, int pop):X(x), Y(y), population(pop){};
		coordinate(){population = 0;};
		int getX(){ return X;}
		int getY(){ return Y;}
		int inWhichQuadrant(coordinate target){
			/*let this become ZERO, Compare target with it
			  return 1,2,3,4 which represent target is in which Quadrant
			  return 0 when is equal(which should not appear
			  return -1, -2, -3 ,4 which represent +X Axis, +Y Axis, -X Axis, -Y Axis*/
			if (target.getX() ==  X && target.getY() == Y ) 
				return 0; 
			else if (target.getX() >  X && target.getY() == Y ) 
				return -1; 
			else if (target.getX() == X && target.getY() > Y ) 
				return -2;
			else if (target.getX() <  X && target.getY() == Y ) 
				return -3; 
			else if (target.getX() == X && target.getY() < Y ) 
				return -4;
			else if (target.getX() >  X && target.getY() > Y ) 
				return 1; 
			else if (target.getX() <  X && target.getY() > Y ) 
				return 2; 
			else if (target.getX() <  X && target.getY() < Y ) 
				return 3; 
			else if (target.getX() >  X && target.getY() < Y ) 
				return 4; 
			return 0;
		}
		bool isUnderAttack(coordinate target, int strength){
			if (abs(target.getX() - X) <= strength && abs(target.getY() - Y) <= strength)
				return true;	
			return false;
		}
		void setX(int X){this->X=X;}
		void setY(int Y){this->Y=Y;}
		void setPopulation(int Population){this->population=Population;}
		void addPoppulation(int value){population += value;}
		int getPopulation(){ return population;};
};/*}}}*/
int main(void)
{
	int caseNum, strength, ratNum;
	coordinate bomb;
	vector<coordinate> ratMap;
	scanf("%d\n", &caseNum);
	for (int i = 0; i < caseNum; ++i) {
		scanf("%d\n%d\n", &strength, &ratNum);	
		for (int j = 0; j  < ratNum; j++) {
			int x, y, population;	
			cin >> x >> y >> population;
			ratMap.push_back(coordinate(x,y,population));
		}
	}
	return 0;
}
int calculateBombDamage(coordinate bomb, vector<coordinate>& ratMap, const int& strength){
	int returnValue = 0;
	for (int i = 0; i < (int)ratMap.size(); ++i) {
		if (bomb.isUnderAttack(ratMap[i], strength)) {
			returnValue += ratMap[i].getPopulation();
		}
	}

}
