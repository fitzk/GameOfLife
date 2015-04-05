/*****************************************************************
* Name:					Kayla Fitzsimmons
* Date:					1/18/2015		
* Course: 				CS162-400
* File Name: 			menu.cpp
*
* Over View:  Menu runs program, contains non class functions.
*
* Functions List:
*		void clearIgnore();
*		void countAndUpdate();
*		void countAndUpdate(Game* onePointer);
*		int getX();
*		int getY();
*		int getIterations();
*		void displayMenu();
*		int main();
*****************************************************************/


#include<iostream>
#include<cstdlib>
#include <unistd.h>

#include"game.h"

using std::cout;
using std::cin;
using std::endl;


/****************************************
*			 clearIgnore				*
* Parameters: n/a						*
* Returns: n/a							*
* Clears error flags and ignores		*
* 100 chars or/& up to newline char		*
****************************************/
void clearIgnore()
{
	cin.clear();
	cin.ignore(100, '\n');
}
/****************************************
*				countAndUpdate			*
* Parameters: pointer to Game			*
* Returns: n/a							*
* iterates over array of Cells, calls	*
* functions count and updateTimeZero, 	*
* which update the cells with the rules	*
* then updates matrixT-0 with the new	*
* cell states. 
****************************************/
void countAndUpdate(Game* onePointer){

	for(int i = 0; i < 500; i++)
	{
		for(int j = 0; j < 500; j++)
		{
			onePointer->count(i,j);
		}
	}
	for(int i = 0; i < 500; i++)
	{
		for(int j = 0; j < 500; j++)
		{
			onePointer->updateTimeZero(i,j);
		}
	}

}
/****************************************
*			printAndClear				*
* Parameters: count int,				*
*	pointer to Game						*
* Returns: n/a							*
* prints out each arrays and clears 	*
* screen 								*
****************************************/
void printAndClear(int c, Game* onePointer){
	system("clear");
	
	if(c == 0)
	{
		cout << "Phase: " << c << endl;
		onePointer->printZero();
		cout << endl;
	}
	else
	{
		cout << "Phase: " << c << endl;
		onePointer->print();
		cout << endl;
	}
	usleep(300000);

}
/****************************************
*				getX					*
* Parameters: n/a						*
* Returns: the x coordinate				*
* Get's the x coordinate from the user	*
* validates the user's input			*
****************************************/
int getX()
{	
	int i;
	cout << "Please enter location coordinates ";
	cout << "of the Configuration - Recommends(X:15 Y:15)" << endl;
	cout << "X: ";	
	cin >> i;

	while (i < 0 || i > 500 || cin.fail() || (cin.peek() != '\r' && cin.peek() != '\n'))
	{
		cout << "Invalid Input! Please input a positive integer for the X coordinate (X < 500):  " << endl;
		cin.clear();
		while (cin.get() != '\n'); // or cin.ignore(1000, '\n');
		cin >> i;
	}	
	return i;
}
/****************************************
*				getY					*
* Parameters: n/a						*
* Returns: the y coordinate				*
* Get's the y coordinate from the user	*
* validates the user's input			*
****************************************/	
int getY(){
	
	int j;
	cout << "Y: ";		
	cin >> j;
	
	while (j < 0 || j > 500 ||cin.fail() || (cin.peek() != '\r' && cin.peek() != '\n'))
	{
		cout << "Invalid Input! Please input a positive integer for the Y coordinate (Y < 500):  " << endl;
		cin.clear();
		while (cin.get() != '\n'); // or cin.ignore(1000, '\n');
		cin >> j;
	}
	return j;
}
/****************************************
*				getIterations			*
* Parameters: n/a						*
* Returns: the # of iterations for the  *
* configuration to run					*
* Performs input validation				*
****************************************/
int getIterations(){
	
	int iterations;
	cout << "Please enter the number of phases (60+) recommended for Glider Gun: ";		
	cin >> iterations;
	
	while (iterations < 0 ||cin.fail() || (cin.peek() != '\r' && cin.peek() != '\n'))
	{
		cout << "Invalid Input! Please input a positive integer: " << endl;
		cin.clear();
		while (cin.get() != '\n'); 
		cin >> iterations;
	}
	return iterations;	
}
/****************************************
*			displayMenu					*
*****************************************/
void displayMenu()
{
	system("clear");	// clears the screen
	cout << endl;
	cout << endl;
	cout << "              CHOOSE A CONFIGURATION!\n\n";
	cout << "                    1) GLIDER\n";
	cout << "                    2) GLIDER GUN\n";
	cout << "                    3) PULSAR\n";
	cout << "                    4) THE CROSS\n";	
	cout << "                    5) QUIT\n\n";
	cout << endl;
}

int main()
{

	Game One;  //creates game
	
	Game* onePointer;
	onePointer = &One;
	
	displayMenu();			//displays the menu
	int choice;
	
	do
	{
		cout << "              Choice: ";
		cin >> choice;		//stores user's choice
		
		clearIgnore();
	
		cout << endl;
		cout << endl;
		
		switch(choice)
		{
			case 1:	{	
			
						int i,j;
						i = getX();
						j = getY();
	
						int iterations;
						iterations = getIterations();
						
						One.glider(i,j);
						
						int c = 0;
						do{
							countAndUpdate(onePointer);
							printAndClear(c, onePointer);
							c++;
							
							}while(c < iterations);
						clearIgnore();
						cout << endl;					
						cout << "Press the ENTER KEY to return to the menu" << endl;
						One.clean();
					}
					break;
			case 2: {
						int i,j;
						i = getX();
						j = getY();
	
						int iterations;
						iterations = getIterations();
						
						One.gliderGun(i,j);
						
						int c = 0;
						do{
							countAndUpdate(onePointer);
							printAndClear(c, onePointer);
							c++;
							
							}while(c < iterations);
							
						clearIgnore();
						cout << endl;					
						cout << "Press the ENTER KEY to return to the menu" << endl;
						One.clean();
					}
					break;
			case 3: {
						int i,j;
						i = getX();
						j = getY();
	
						int iterations;
						iterations = getIterations();
						
						One.pulsar(i,j);
						
						int c = 0;
						do{
							countAndUpdate(onePointer);
							printAndClear(c, onePointer);
							c++;
							
							}while(c < iterations);
							
						clearIgnore();
						cout << endl;					
						cout << "Press the ENTER KEY to return to the menu" << endl;
						One.clean();
					}
					break;
			case 4:	{
						int i,j;
						i = getX();
						j = getY();
	
						int iterations;
						iterations = getIterations();

						One.theCross(i,j);
						
						int c = 0;
						do{
							countAndUpdate(onePointer);
							printAndClear(c, onePointer);
							c++;
							
							}while(c < iterations);
						
						clearIgnore();
						cout << endl;					
						cout << "Press the ENTER KEY to return to the menu" << endl;
						One.clean();
					}
					break;					
			case 5: {
					cout << "Good Bye!";
					cout << endl;
					}
					return 0;
			default: cout << "Invalid choice please try again!" << endl;
					break;
		}
		
		
		cin.get();
		displayMenu();		//displays the menu
	}while(choice !=5);

	return 0;
}
