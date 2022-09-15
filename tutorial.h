#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <typeinfo>
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