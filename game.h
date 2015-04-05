/************************************************************************************
* Name:					Kayla Fitzsimmons											*
* Date:					1/18/2015													*
* Course: 				CS162-400													*
* File Name: 			game.h														*
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
#ifndef __game__
#define __game__
#include<iostream>
#include"matrix.h"
using std::cout;
using std::cin;
using std::endl;

class Game{
	
	private:
		Matrix timeZero; //matrix object
		Matrix timeOne;	 //matrix object
		Matrix* timeZeroPointer;	//pointer to matrix
		Matrix* timeOnePointer;		//pointer to matrix
		
	public:
		Game();
			//timeZero and timeOne
		void setAllPointers();
			//timeZero
		void setTimeZeroPointer();
		Matrix* getTimeZeroPointer();
			//timeOne
		void setTimeOnePointer();
		Matrix* getTimeOnePointer();
		void updateTimeZero(int a, int b);
			//rules
		void naRule(int i, int j);
		void firstRule(int i, int j);
		void secondRule(int i, int j);
		void thirdRule(int i, int j);
		
		void count(int x, int y);
		//print row of TimeOne
		void print();
		//print row of TimeZero
		void printZero();
		//configurations
		void glider(int x, int y);
		void pulsar(int x, int y);
		void gliderGun(int x, int y);
		void theCross(int x, int y);
		void clean();
	
};
#endif
