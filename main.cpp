#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <typeinfo>
using namespace std;
int characterClass;
int saveState[20]; //see guide for info, so far state 0 is character class

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