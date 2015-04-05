/*****************************************************************
* Name:					Kayla Fitzsimmons
* Date:					1/18/2015		
* Course: 				CS162-400
* File Name: 			matrix.h
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
#ifndef __matrix__
#define __matrix__
#include<iostream>
#include"cell.h"

using std::cout;
using std::cin;
using std::endl;


class Matrix{
	
	private:
		Cell matrix[500][500];
	public:
		Matrix();
		Cell* getCellPointer(int i, int j);
		void setCellPointer(int i, int j);
		bool getCellState(int i, int j);
		void setCellState(int i, int j, bool a);
		void printRow(int a);
};
#endif

