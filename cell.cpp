/*****************************************************************
* Name:					Kayla Fitzsimmons
* Date:					1/18/2015		
* Course: 				CS162-400
* File Name: 			cell.cpp
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
#include"cell.h"

/****************************************
*			Cell Constructor			*
* Parameters: n/a						*
* Returns: n/a 							*
*										*
* Comments: Sets state to false auto 	*
* for each cell.						*
*										*
****************************************/
Cell::Cell(){

	state = false;
}
/****************************************
*			setDisplay					*
* Parameters: char						*
* Returns: n/a 							*
*										*
****************************************/
void Cell::setDisplay(char a){

	if(a == false)
	{
		display = '.';
	}
	else if(a == true)
	{
		display = 'O';
	}
}
/****************************************
*			getDisplay					*
* Parameters: None						*
* Returns: Char for display Characters	*
*										*
****************************************/
char Cell::getDisplay(){

	if(state == false)
	{
		display = '.';
	}
	else if(state == true)
	{
		display = 'O';
	}
	return display;
}
/****************************************
*			setDisplay					*
* Parameters: char						*
* Returns: n/a 							*
*										*
****************************************/
void Cell::setState(bool b){

	state = b;
}
/****************************************
*			getState					*
* Parameters: char						*
* Returns: n/a 							*
*										*
****************************************/
bool Cell::getState(){

	return state;
}
/****************************************
*			setCellPointer				*
*										*
****************************************/
void Cell::setCellPointer(Cell* a){
	
	cellPointer = a;
	
}
/****************************************
*			getCellPointer				*
* sets cellPointer to a cell as 		*
* specified by the coordinates that are *
* fed to the pa							*
****************************************/
Cell* Cell::getCellPointer(){
	
	return cellPointer;
}
