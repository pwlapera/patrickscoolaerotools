#include "Densityequations.h"
#include <iostream>

//these functions get the base data from the user

double getAirTempInF(double x)
{
	
	std::cout << "Enter the air temperature at sea level in Farenheit: ";
	std::cin >> x;
	return x;
}

double getPressureAtSeaLevel(double x)
{
	
	std::cout << "Enter the air pressure at sea level in KpA: ";
	std::cin >> x;
	return x;
}

double getAltOfObject(double x)
{
	
	std::cout << "Enter the altutide of your aircraft: ";
	std::cin >> x;
	return x;
}

void printAtmosphereLayer(double altM)
{
	if (altM <= 11000)
		std::cout << "You are in the troposphere. " << '\n';

	if (altM > 11000 && altM <= 25000)
		std::cout << "You are in the lower stratosphere. " << '\n';

	if (altM > 25000 && altM <= 100000)
		std::cout << "You are in the upper stratosphere. " << '\n';

	if (altM > 100000)
		std::cout << "You are straight-up in outer space bro." << '\n';
}

double getWingArea()
{
	double wingLength{};
	double wingWidth{};

	std::cout << "Enter the length of your wing in M: ";
	std::cin >> wingLength;

	std::cout << "Enter the width of your wing in M: ";
	std::cin >> wingWidth;

	double wingArea{ wingLength * wingWidth };

	return wingArea;
}

void printWingArea(double wingArea)
{
	std::cout << "Your wing is: " << wingArea << " square meters." << '\n';
}

double getSpeedinKnots() //this gets the airspeed from the user
{
	std::cout << " Enter a speed in Knots: ";
	double airSpeedinKnots{};
	std::cin >> airSpeedinKnots;

	return airSpeedinKnots;
}

void printC172Comparison(double liftN) 
{

	std::cout << "At the given altitude and speed, a Cessna 172's wings generate approximately " << liftN << " Newtons of lift.";

}


void printWingLift(double liftN)
{
	double liftBothWings{ liftN * 2 };

	std::cout << "At the given altitude and speed, your plane's main wings generate approximately " << liftBothWings << " Newtons of lift.";

}

double getLiftCoeffecient() //this gets the airspeed from the user
{
	std::cout << " Enter your wing's lift coeffecient: ";
	double Cl{};
	std::cin >> Cl;

	return Cl;
}

