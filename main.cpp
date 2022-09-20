#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <stdio.h>
#include "tutorial.h"
using namespace std;
int saveState[20]; //see guide for info, so far state 0 is character class
string playerName;

int main(int argc,char * argv[])
{
	char choice; //used for our class choice
	int tracker = 0; //used for choice while loop
	string fileName = "saveData.txt";//savefile name

	//loading in the file
	try
	{
		ifstream myFile(fileName);
		
		//myfile is not hoping 
		if(!myFile)
		{
			throw std::string(fileName);
		}
		myFile >> saveState[0];
		myFile >> saveState[1];
		myFile.close();
	}
	catch(string str)
	{
		cout << "Huge error with savefile, trouble shooting required" << endl;
		return -1;
	}

	while (tracker == 0)
	{	
		cout << "Welcome to the text game" << endl;
		cout << "Make a choice" << endl;
		cout << "|             |" << endl;
		cout << "|             |" << endl;
		cout << "|             |" << endl;
		cout << "|             |" << endl;
		cout << "|             |" << endl;
		cout << "Choose a class" << endl;
		cout << "Wizard    [A]" << endl;
		cout << "Fighter   [B]" << endl;
		cout << "Rogue     [C]" << endl;
		cout << "Ranger    [D]" << endl;

  		cin >> choice;

  		if(tolower(choice) == 'a')
  		{
  			saveState[0] = 1; //Wizard
  			tracker = 1;
  			cout << "Choice accepted you are a Wizard!" << endl;
  		} 
 	 	else if(tolower(choice) == 'b')
 	 	{
 	 		saveState[0] = 2; //Fighter
 	 		tracker = 1;
  			cout << "Choice accepted you are a Fighter!" << endl;
 	 	}
 	 	else if(tolower(choice) == 'c')
 	 	{
 	 		saveState[0] = 3; //Rogue
 	 		tracker = 1;
  			cout << "Choice accepted you are a Rogue!" << endl;
 	 	}
 	 	else if(tolower(choice) == 'd')
 	 	{
  			saveState[0] = 4; //Ranger
  			tracker = 1;
  			cout << "Choice accepted you are a Ranger!" << endl;
  		}
  		else
  		{
  			cout << "Invalid choice please try again" << endl;
  		}
  	}

  
  	while(true) //get player name 
  	{
  		cout << "Please enter your name for your character name: " << endl;
  		cin >> playerName;
  		if(playerName.length() <= 50)
  		{
  			cout << "Name accepted as \"" << playerName << "\" are you sure this is the name you want, you can not change it later [Y/N]" << endl;
  			cin >> choice;
  			if(tolower(choice) == 'y')
  			{
  				break; //breaks loop when acceptable length and the user likes it.
  			}
  			
  		}
  		else
  		{
  			cout << "Please keep character limit under 50 characters" << endl;
  		}
  	} 

  	while(true)
  	{
  		cout << "Would you like to play the tutorial? [Y/N]" << endl;
  		cin >> choice;
  		if(tolower(choice) == 'y')
  		{
  			tutorial tObj(saveState[0]);
  			tObj.~tutorial();
  			break;
  		}
  		else if(tolower(choice) == 'n')
  		{
  			break;
  		}
  		else
  		{
  			cout << "Please enter Y (yes) or N (no) only " << endl;
  		}

  	}

  	try	//closing statement
	{
		ofstream myFile;
		myFile.open(fileName);
		if(!myFile)
		{
			throw std::string(fileName);
		}
		myFile << saveState[0];
		myFile << " ";
		myFile << saveState[1];

		myFile.close();
	}
	catch(string str)
	{
		cout << "Huge error with savefile, trouble shooting required" << endl;
		return -1;
	}
}