/*
* This program file contains from scratch implementations of several popular DSP algorithms. 
* The purpose of this notebook is to get a through understanding of basic DSP algorithms. 
* Samarth Ganesh Thopaiah - Carnegie Mellon University 
* FIR Input sample implementation 
*/

#include<iostream>
#include "FIR.h"

int main()
{
	float tempCoeff[5] = { 0.2,0.3, 0.3, 0.5, 0.6 };
	float tempHistory[5] = { 1.2,1.3, 1.3, 1.5, 1.6 };
	int out = fir_filter(0.23, tempCoeff, 5, tempHistory);
	std::cout << out << std::endl; 
}