/*****************************************************************
* Name:					Kayla Fitzsimmons
* Date:					1/18/2015		
* Course: 				CS162-400
* File Name: 			matrix.cpp
*
* Over View:  Matrix class has an array of Cells 500 x 500
*
* Functions List:
*		Matrix();
*		Cell* getCellPointer(int i, int j);
*		void setCellPointer(int i, int j);
*		bool getCellState(int i, int j);
*		void setCellState(int i, int j, bool a);
*		void printRow(int a);
*
*****************************************************************/

#include"matrix.h"
#include<iostream>

using std::cout;
using std::cin;
using std::endl;


/****************************************
*			Matrix		 				*
* constructor							*
****************************************/
Matrix::Matrix(){}
/****************************************
*			setCellPointer				*
* Parameters: coordinates of cell       *
* sets cellPointer to a cell 			*
****************************************/
void Matrix::setCellPointer(int i, int j)
{
	Cell* a;
	a = &(matrix[i][j]);
	matrix[i][j].setCellPointer(a);
}
/****************************************
*			getCellPointer				*
* Parameters: coordinates of cell		*
* returns pointer to cell				*
****************************************/
Cell* Matrix::getCellPointer(int i, int j)
{	
	Cell *a;
	a = matrix[i][j].getCellPointer();	
	return a;
}
/****************************************
*			printRow					*
* Parameters: takes a row				*
* prints out row (up to 80 cells)		*
****************************************/
void Matrix::printRow(int a){

	for(int i=0; i < 80 ; i++)
	{
		cout << matrix[a][i].getDisplay() << " ";
	}
	cout << endl;
}
/****************************************
*			getCellState				*
* wrapper function takes coordinates of *
* cell and returns state				*
****************************************/
bool Matrix::getCellState(int i, int j)
{
	bool p;
	p = matrix[i][j].getState();
	return p;
}
/****************************************
*			setCellState				*	
* wrapper function takes coordinates of *
* cell and updates state				*
****************************************/
void Matrix::setCellState(int i, int j, bool a)
{
	Cell* p;
	p = matrix[i][j].getCellPointer();
	p->setState(a);	
}
