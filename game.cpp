/************************************************************************************
* Name:					Kayla Fitzsimmons											*
* Date:					1/18/2015													*
* Course: 				CS162-400													*
* File Name: 			game.cpp													*
*																					*
* Over View:  Contains two Matrix Objects 											*
*																					*
* Functions List:																	*
*		Game();										void firstRule(int i, int j);	*
*		void setAllPointers();  					void secondRule(int i, int j);	*
*		void setTimeZeroPointer();					void thirdRule(int i, int j);	*
*		Matrix* getTimeZeroPointer();				void count(int x, int y);		*
*		void setTimeOnePointer();					void print();					*		
*		Matrix* getTimeOnePointer();				void printZero();				*
*		void updateTimeZero(int a, int b);			void clean();					*
*		void naRule(int i, int j);													*
*																					*
*		void pulsar(int x, int y);													*
*		void gliderGun(int x, int y);												*
*		void theCross(int x, int y);												*
*		void glider(int x, int y);													*
*************************************************************************************/
#include"game.h"
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

/****************************************
*			Game::Game					*
* constructor- sets all pointers		*
****************************************/
Game::Game(){
	
	setAllPointers();
	
}
/***************T0*&*T1******************		
*			setAllPointers				*
* 	populates arrays of Cell objects	*
*	with pointers to themselves			*
****************************************/
void Game::setAllPointers()
{
	setTimeZeroPointer();
	setTimeOnePointer();
	
	for(int i =0; i < 500; i++)
	{
		for(int j=0; j < 500; j++)
		{
			timeZeroPointer->setCellPointer(i,j);
			timeOnePointer->setCellPointer(i,j);
		}
	}
}
/***************T0***********************								*			
*			setTimeZeroPointer			*
* 	pointer to T0 Matrix class			*	
*										*
****************************************/
void Game::setTimeZeroPointer()
{
	timeZeroPointer = &(timeZero);
}
/****************T0**********************
*			getTimeZeroPointer			*
* 	returns pointer to the timeZero 	*
*	object								*
****************************************/
Matrix* Game::getTimeZeroPointer()
{
	return timeZeroPointer;	
}
/*****************T1*********************
*			setTimeOnePointer			*
* 	sets pointer to TimeOne Matrix		*
*										*
****************************************/
void Game::setTimeOnePointer()
{
	timeOnePointer = &(timeOne);
}
/*****************T1*********************
*			getTimeOnePointer			*
* 	returns pointer to TimeOne Matrix	*
*										*
****************************************/
Matrix* Game::getTimeOnePointer()
{
	return timeOnePointer;	
}

/******************T0********************
*			updateTimeZero				*
* Copies cell states at timeOne to time	*
* Zero after the rules are all applied  *									*
****************************************/
void Game::updateTimeZero(int a, int b){
	
	timeZero.setCellState(a,b,timeOne.getCellState(a,b));

}
/******************T0********************
*				count					*
* Parameters: coordinates to Cell		*
* calls Rule functions					*
****************************************/
void Game::count(int x, int y){
	int countDead=0;
	int countAlive;

	//(x-1,y-1)
	if(timeZeroPointer->getCellState(x-1,y-1) == 0)
	{
		countDead++;
	}
	//(x-1,y)
	if(timeZeroPointer->getCellState(x-1,y)== 0)
	{
		countDead++;
	}
	//(x-1,y+1)
	if(timeZeroPointer->getCellState(x-1,y+1)== 0)
	{
		countDead++;
	}	
	//(x,y-1)
	if(timeZeroPointer->getCellState(x,y-1)== 0)
	{
		countDead++;
	}	
	//(x,y+1)
	if(timeZeroPointer->getCellState(x,y+1)== 0)
	{
		countDead++;
	}
	//(x+1,y-1)
	if(timeZeroPointer->getCellState(x+1,y-1)== 0)
	{
		countDead++;
	}
	//(x+1,y)
	if(timeZeroPointer->getCellState(x+1,y)== 0)
	{
		countDead++;
	}
	//(x+1,y+1)
	if(timeZeroPointer->getCellState(x+1,y+1)== 0)
	{
		countDead++;
	}
	
  //(x-1,y-1) 	//(x-1,y)	//(x-1,y+1)
  //(x,y-1)		//(x,y)		//(x,y+1)
  //(x+1,y-1)	//(x+1,y)	//(x+1,y+1)
	

	countAlive = 8-countDead;
	
	//if the cell is alive: check for first, second, or no rule
	if(timeZeroPointer->getCellState(x,y)==1)
	{
		if(countAlive == 0 || countAlive == 1) 
		{
			firstRule(x,y);
		}
		else if(countAlive > 3)
		{
			secondRule(x,y);	
		} 
		else 
		{
			naRule(x, y);
		}
	}
	else if(timeZeroPointer->getCellState(x,y)==0) //if dead: third, or no rule
	{
		if(countAlive == 3)
		{
			thirdRule(x,y);
		} else {
			naRule(x, y);
		}
	}
}

/****************************************
*			naRule						*
* Parameters: coordinates to cell		*
* Returns: n/a 							*
* updates cells that do not have rules	*
* applied to them						*
****************************************/
void Game::naRule(int i, int j)
{
	int state = timeZeroPointer->getCellState(i,j);
	timeOnePointer->setCellState(i,j,state);
}

/****************************************
*			firstRule					*
* Parameters: coordinates to cell		*
* Returns: n/a 							*
* Sets cell state in Time One to dead	*
*										*
****************************************/
void Game::firstRule(int i, int j)
{
	timeOnePointer->setCellState(i,j,0);
}
/****************************************
*			secondRule					*
* Parameters: coordinates to cell		*
* Returns: n/a 							*
* Sets cell state in Time One to dead	*
*										*
****************************************/
void Game::secondRule(int i, int j)
{
	timeOnePointer->setCellState(i,j,0);
}
/****************************************
*			thirdRule					*
* Parameters: coordinates to cell		*
* Returns: n/a 							*
* Sets cell state in Time One to alive	*
*										*
****************************************/
void Game::thirdRule(int i, int j)
{
	timeOnePointer->setCellState(i,j,1);
}
/****************************************
*			printZero					*
* Parameters: n/a						*
* Returns: n/a 							*
* prints time zero row 					*
****************************************/
void Game::printZero() 
{
		
	for(int i = 10; i < 33; i++)
	{
		
		timeZeroPointer->printRow(i);
			
	}	
	
}
/****************************************
*				print					*
* Parameters: n/a						*
* Returns: n/a 							*
* prints time one row 					*
****************************************/
void Game::print() 
{	
	for(int i = 10; i < 33; i++)
	{	
		timeOnePointer->printRow(i);		
	}	
}
/****************************************
*				glider					*
* Parameters: coordinates to first cell	*
* Returns: n/a 							*
* creates glider pattern in matrix from	*
* a user defined location				*
****************************************/
void Game::glider(int x, int y)
{	
				//    X
				// X  X
				//	X X

	bool a = 1;
	timeZeroPointer->setCellState(x+1,y,a);
	timeZeroPointer->setCellState(x+2,y+1,a); 
	timeZeroPointer->setCellState(x+2,y+2,a); 
	timeZeroPointer->setCellState(x+1,y+2,a); 
	timeZeroPointer->setCellState(x,y+2,a); 
}
/****************************************
*				gliderGun				*
* Parameters: coordinates to first cell	*
* Returns: n/a 							*
* creates gliderGun pattern in matrix 	*
* from a user defined location			*
****************************************/
void Game::gliderGun(int x, int y)
{	                    
				//  VISUAL REP OF GLIDER GUN	        	      1,25
	        //     WITH EXAMPLE COORDINATES                 2,23  2,25
	//			  3,13 3,14              	    	 3,21 3,22               3,35 3,36
	//			4,12             4,16           	 4,21 4,22               4,35 4,36
	//5,1 5,2  5,11                 5,17   			 5,21 5,22
	//6,1 6,2  6,11           6,15  6,17 6,18    			6,23  6,25
	//		   7,11                 7,17              			  7,25
	//			8,12             8,16
	//			  9,13 9,14

	bool a = 1;
	//ROW 1
	timeZeroPointer->setCellState(x+1,y+25,a); 
	//ROW 2
	timeZeroPointer->setCellState(x+2,y+23,a); 
	timeZeroPointer->setCellState(x+2,y+25,a); 
	//ROW 3
	timeZeroPointer->setCellState(x+3,y+13,a);
	timeZeroPointer->setCellState(x+3,y+14,a); 
	timeZeroPointer->setCellState(x+3,y+21,a); 
	timeZeroPointer->setCellState(x+3,y+22,a); 
	timeZeroPointer->setCellState(x+3,y+35,a); 
	timeZeroPointer->setCellState(x+3,y+36,a); 
	//ROW4
	timeZeroPointer->setCellState(x+4,y+12,a); 
	timeZeroPointer->setCellState(x+4,y+16,a); 
	timeZeroPointer->setCellState(x+4,y+21,a); 
	timeZeroPointer->setCellState(x+4,y+22,a);
	timeZeroPointer->setCellState(x+4,y+35,a); 
	timeZeroPointer->setCellState(x+4,y+36,a); 
	//ROW5
	timeZeroPointer->setCellState(x+5,y+1,a);
	timeZeroPointer->setCellState(x+5,y+2,a); 
	timeZeroPointer->setCellState(x+5,y+11 ,a); 
	timeZeroPointer->setCellState(x+5,y+17,a); 
	timeZeroPointer->setCellState(x+5,y+21,a); 
	timeZeroPointer->setCellState(x+5,y+22,a);
	//ROW6
	timeZeroPointer->setCellState(x+6,y+1,a);
	timeZeroPointer->setCellState(x+6,y+2,a);
	timeZeroPointer->setCellState(x+6,y+11,a); 
	timeZeroPointer->setCellState(x+6,y+15,a); 
	timeZeroPointer->setCellState(x+6,y+17,a); 
	timeZeroPointer->setCellState(x+6,y+18,a);
	timeZeroPointer->setCellState(x+6,y+23,a); 
	timeZeroPointer->setCellState(x+6,y+25,a); 
	//ROW7
	timeZeroPointer->setCellState(x+7,y+11 ,a);
	timeZeroPointer->setCellState(x+7,y+17,a); 
	timeZeroPointer->setCellState(x+7,y+25,a); 
	//ROW8
	timeZeroPointer->setCellState(x+8,y+12,a); 
	timeZeroPointer->setCellState(x+8,y+16,a); 
	//ROW9
	timeZeroPointer->setCellState(x+9,y+13,a); 
	timeZeroPointer->setCellState(x+9,y+14,a); 

}
/****************************************
*				pulsar					*
* Parameters: coordinates to first cell	*
* Returns: n/a 							*
* creates pulsar pattern in matrix	 	*
* from a user defined location			*
****************************************/
void Game::pulsar(int x, int y)
{	
	bool a = 1;
	
	timeZeroPointer->setCellState(x+2,y,a);
	timeZeroPointer->setCellState(x+3,y,a); 
	timeZeroPointer->setCellState(x+4,y,a);
	
	timeZeroPointer->setCellState(x+2,y+5,a);
	timeZeroPointer->setCellState(x+3,y+5,a); 
	timeZeroPointer->setCellState(x+4,y+5,a); 
	
	timeZeroPointer->setCellState(x+2,y+7,a);
	timeZeroPointer->setCellState(x+3,y+7,a); 
	timeZeroPointer->setCellState(x+4,y+7,a); 
	
	timeZeroPointer->setCellState(x+2,y+12,a);
	timeZeroPointer->setCellState(x+3,y+12,a); 
	timeZeroPointer->setCellState(x+4,y+12,a); 
	
	timeZeroPointer->setCellState(x+8,y,a);
	timeZeroPointer->setCellState(x+9,y,a); 
	timeZeroPointer->setCellState(x+10,y,a);
	
	timeZeroPointer->setCellState(x+8,y+5,a);
	timeZeroPointer->setCellState(x+9,y+5,a); 
	timeZeroPointer->setCellState(x+10,y+5,a); 
	
	timeZeroPointer->setCellState(x+8,y+7,a);
	timeZeroPointer->setCellState(x+9,y+7,a); 
	timeZeroPointer->setCellState(x+10,y+7,a); 
	
	timeZeroPointer->setCellState(x+8,y+12,a);
	timeZeroPointer->setCellState(x+9,y+12,a); 
	timeZeroPointer->setCellState(x+10,y+12,a); 

	timeZeroPointer->setCellState(x,y+2,a);
	timeZeroPointer->setCellState(x,y+3,a); 
	timeZeroPointer->setCellState(x,y+4,a);
	
	timeZeroPointer->setCellState(x,y+8,a);
	timeZeroPointer->setCellState(x,y+9,a); 
	timeZeroPointer->setCellState(x,y+10,a); 
	
	timeZeroPointer->setCellState(x+5,y+2,a);
	timeZeroPointer->setCellState(x+5,y+3,a); 
	timeZeroPointer->setCellState(x+5,y+4,a);
	
	timeZeroPointer->setCellState(x+5,y+8,a);
	timeZeroPointer->setCellState(x+5,y+9,a); 
	timeZeroPointer->setCellState(x+5,y+10,a); 
	
	timeZeroPointer->setCellState(x+7,y+2,a);
	timeZeroPointer->setCellState(x+7,y+3,a); 
	timeZeroPointer->setCellState(x+7,y+4,a);
	
	timeZeroPointer->setCellState(x+7,y+8,a);
	timeZeroPointer->setCellState(x+7,y+9,a); 
	timeZeroPointer->setCellState(x+7,y+10,a); 
	
	timeZeroPointer->setCellState(x+12,y+2,a);
	timeZeroPointer->setCellState(x+12,y+3,a); 
	timeZeroPointer->setCellState(x+12,y+4,a);
	
	timeZeroPointer->setCellState(x+12,y+8,a);
	timeZeroPointer->setCellState(x+12,y+9,a); 
	timeZeroPointer->setCellState(x+12,y+10,a); 

	
}
/****************************************
*				theCross				*
* Parameters: coordinates to first cell	*
* Returns: n/a 							*
* creates what I call the cross pattern *
* in matrix	from a user defined 		*
* location (I found this pattern by 	*
* accident, it might exist somewhere	*
* else under a different description)	*
****************************************/
void Game::theCross(int x, int y)
{	
		
	bool a = 1;
	for(int i = 1; i < 10; i++)
	{
		for(int j = 1; j <20; j++){
		timeZeroPointer->setCellState(x+i,y+j,a);
		}
	}
}
/****************************************
*				clean					*
* Parameters: n/a						*
* Returns: n/a 							*
* cleans board of pre-set configs		*
****************************************/
void Game::clean()
{
	int state = 0;
	for(int i = 0; i < 500; i++)
	{
		for(int j = 0; j < 500; j++)
		{
			timeZeroPointer->setCellState(i,j,state);
		}
	}
}