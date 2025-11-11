// Densitycalculatorproject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//this program gets calculates the density of the atmosphere in kg/cm3 from external outputs

#include "coolaerotoolsmasterheader.h" // the header file for this project
#include <string_view>
#include <cmath>
#include <iostream>

int main()
{
	printProgramTitle(g_ProgramTitle);

	bool isMenuSelectionValid(false);
	while (!isMenuSelectionValid) {
		isMenuSelectionValid=startMenu();
		isMenuSelectionValid = startMenu();
	}



//	double speedKnots{ getSpeedinKnots() };
//	double speedMS{convertKnotsToMS(speedKnots)};

	//gets info about your cool plane
	/*
	double wingArea{ getWingArea() };
	printWingArea(wingArea);
	double Cl{ getLiftCoeffecient() };
	*/
	//gets lift info
	/*
	double liftN{ liftCalculations::calculateLift(Cl,wingArea,speedMS,airkgm3) };
	double liftNC{ liftCalculations::calculateLiftOfACessna172(speedMS,airkgm3) };
	printWingLift(liftN);
	printC172Comparison(liftNC);
	*/
	return 0;
}

//ball weight for a 1m cube should be the local kgm3