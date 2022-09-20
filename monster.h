#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <typeinfo>

using namespace std;

class monster
{

	int type;
	int health;
	int damage;
	int armorClass;
	int modifier;
	string attackType = "";		
	string mName = "";


	public:
		//monster constructor

		monster(int type)
		{
			//cout << "monster made" << endl;
			monsterList(type);
		}

		//monster list has a list of monsters and will assign them based on input
		void monsterList(int t)
		{

			type = t;

			switch(type)
			{
				case 0:
					//cout << "Enemy type Imp created" << endl;
					health = 20;
					damage = 4;
					armorClass = 10;
					mName = "Imp";
					attackType = "Claws";
					modifier = 1;
			}


		}

		bool isHit(int i)
		{
			if (i >= armorClass)
			{
				return true;
			}
			return false;
		}

		//i is the damage taken and bool returns 1 or true if alive and 0 if dead
		void loseHP(int i)
		{
			health = health - i;
			cout << mName << " took " << i << " damage! " << endl;
			

		}
		//checks if the entity is alive
		bool isAlive()
		{
			if(health > 0)
			{
				return true;
			}
			return false;
		}

		int attack()
		{
			int attempt = (rand() %20 + 1) + modifier + 1;
			cout << "Monster " << mName << " attempted to attack with a " << attempt << " to hit!" << endl;

			return attempt;
		}
		int doDamage()
		{
			int does;

				does = (rand() % does + 1) + modifier;
				cout << mName << " attacked with " << attackType << " for "<< does <<  " damage!" << endl;
				return does;
		}

		string getName()
		{
			return mName;
		}
	
};