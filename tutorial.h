#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include "fighter.h"
#include "monster.h"
using namespace std;


class tutorial
{
public:
	int characterClass;

	//actual constructor
	tutorial(int passed)
	{
		characterClass = passed;
		// cout << "tutorial called"<< passed << endl;
		if (characterClass == 1)
		{
			wizardTutorial();
		}
		else if(characterClass == 2)
		{
			fighterTutorial();
		}
		else if(characterClass == 3)
		{
			rogueTutorial();
		}
		else if(characterClass == 4)
		{
			rangerTutorial();
		}
	}
	//wizard tutorial
	void wizardTutorial()
	{
		cout << "Wizard tutorial called" << endl;
		



	}

	//fighter tutorial
	void fighterTutorial()
	{
		cout << "Fighter tutorial called" << endl;
		fighter fighterT = fighter(20, 5, 40000, 14);
		monster monsterT = monster(0);

		while(true)
  		{
  			char choice;
  			cout << "Welcome to the tutorial for fighter, we will simulate a ";
  			cout << "simple combat against an Imp" << endl << endl;
  			cout << "Ready to continue? [Y/N]" << endl;
  			cin >> choice;
  			if(tolower(choice) == 'y')
  			{
  				break;
  			}
  		}

  		while(true)
  		{
  			char choice;
  			cout << "/*******************************************************" << endl;
  			cout << "* ^(*(oo)*)^ <---------- enemy" <<endl;
  			cout << "*" << endl;
  			cout << "*" << endl;
  			cout << "*" << endl;
  			cout << "*" << endl;
  			cout << "*" << endl;
  			cout << "*" << endl;
  			cout << "*" << endl;
  			cout << "*" << endl;
  			cout << "* d[ o_0 ]b <--------- you" << endl;
  			cout << "*******************************************************/" << endl;
  			cout << endl;
  			cout << "Typically you will be fighting more then one monster, as well as having party mates.";
  			cout << " For simplification this tutorial will only contain one of each. You can clearly see ";
  			cout << "the top picture represents the enemy while the bottom is you. The top enemies will always ";
  			cout << "go in order from left to right [1, 2, ......, X] to target, so 1 would be the left ";
  			cout << "most enemy and X the right most. " << endl << endl;
  			cout << "Ready to continue? [Y/N]" << endl;
  			cin >> choice;
  			if(tolower(choice) == 'y')
  			{
  				break;
  			}
  		}
  		while(true)
  		{
  			char choice;
  			cout << "/*******************************************************" << endl;
  			cout << "* ^(*(oo)*)^ " <<endl;
  			cout << "*" << endl;
  			cout << "*" << endl;
  			cout << "*" << endl;
  			cout << "*" << endl;
  			cout << "*" << endl;
  			cout << "*" << endl;
  			cout << "*" << endl;
  			cout << "*" << endl;
  			cout << "* d[ o_0 ]b " << endl;
  			cout << "*******************************************************/" << endl;
  			cout << endl;
  			cout << "Type 1 to attack "<< endl << endl;
  			cin >> choice;
  			if(choice == '1')
  			{
  				if (monsterT.isHit(fighterT.attack()) == true)
  				{
  					cout << "HIT!" << endl;
  					monsterT.loseHP(fighterT.doDamage(0));

  					if(monsterT.isAlive() == false)
  					{
  						cout << "You won! Monster is dead" << endl;
  						break;
  					}
  				}
  				else
  				{
  					cout << "missed!" << endl;
  				}
  				
  				cout << monsterT.getName() << " attempts to attack you! " << endl;
  				if (fighterT.isHit(monsterT.attack()) == true)
  				{
  					cout << "You were hit!" << endl;

  					fighterT.loseHP(monsterT.doDamage());

  					if(fighterT.isAlive() == false)
  					{
  						cout << "You died and lost! :(<" << endl;
  						break;
  					}
  				}
  			}
  		}


	}


	//rogue turtorial
	void rogueTutorial()
	{
		cout << "Rogue tutorial called" << endl;
	}

	//ranger tutorial
	void rangerTutorial()
	{
		cout << "Ranger tutorial called" << endl;
	}

	~tutorial()
	{

	}
};