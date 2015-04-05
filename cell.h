/*****************************************************************
* Name:					Kayla Fitzsimmons
* Date:					1/18/2015		
* Course:				CS162-400
* File Name: 			cell.h
*
* Over View:  Cell object has a Display character, state (alive 
* or dead), and a cell pointer
*
* Functions List:
*		Cell();	
*		void setDisplay(char a);
*		char getDisplay();
*		void setState(bool b);
*		bool getState();
*		void setCellPointer(Cell* a);
*		Cell* getCellPointer();
*
*****************************************************************/
#ifndef __cell__
#define __cell__
#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;

class Cell{

	private:
		bool state;			//state of cell
		char display;		//character reps dead
		Cell* cellPointer;
		
	public:
		Cell();	
		void setDisplay(char a);
		char getDisplay();
		void setState(bool b);
		bool getState();
		void setCellPointer(Cell* a);
		Cell* getCellPointer();
};
#endif