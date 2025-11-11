#include "coolaerotoolsmasterheader.h"
#include "pcatconstants.h"
#include <string_view>
#include <limits>
#include <cstdlib>
#include <iostream>

//these functions get the base data from the user, text like titles is in the densityequations header file
//note: the UI Commands for the Atmosphere Maker is in "Atmosphere Maker Tool Functions.cpp"
void printProgramTitle(std::string_view programTitle)
{
	std::cout<< programTitle << '\n';
}

void printUILine(std::string_view x) 
{
	std::cout << x << '\n';
}


void clearUserInputStream() //clears extra text from std::cin
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool didUserInputFail()
{
	if (!std::cin)
	{
		if (std::cin.eof())
		{
			std::exit(0);
		}
		std::cin.clear();
		clearUserInputStream();

		return true;
	}
	return false;
}

double getAirTempInF()
{
	std::cout << "Enter the air temperature at sea level in Farenheit: ";
	
	double tempF{};
	getErrorCheckedInput(tempF);
	return tempF;
	
}

double getPressureAtSeaLevel()
{

	std::cout << "Enter the air pressure at sea level in KpA: ";
	double kPa{};
	getErrorCheckedInput(kPa);
	return kPa;

}
double getAltOfObject()
{
	double x{};
	std::cout << "Enter the altutide of your aircraft: ";
	double alt{};
	getErrorCheckedInput(alt);
	return alt;

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
	
	double wingWidth{};
	double wingLength{};
	//double& widthRef{ wingWidth };
	std::cout << "Enter the length of your wing in M: ";
	getErrorCheckedInput(wingLength);


	std::cout << "Enter the width of your wing in M: ";
	getErrorCheckedInput(wingWidth);

	double wingArea{ wingLength * wingWidth };

	return wingArea;
}

double getWeightLbs()
{
	double planeWeightlbs{};
	std::cout << "Enter the weight of your plane in lbs: ";
	getErrorCheckedInput(planeWeightlbs);
	return planeWeightlbs;
}

double getWeightkg()
{
	double planeWeightkg{};
	std::cout << "Enter the weight of your plane in kilograms: ";
	getErrorCheckedInput(planeWeightkg);
	return planeWeightkg;
}


void printWingArea(double wingArea)
{
	std::cout << "Your wing is: " << wingArea << " square meters." << '\n';
}

double getSpeedinKnots() //this gets the airspeed from the user
{
	std::cout << "Enter a speed in Knots: ";
	double airSpeedinKnots{};
	getErrorCheckedInput(airSpeedinKnots);
	return airSpeedinKnots;
}

void printC172Comparison(double liftN) 
{

	std::cout << "At the given altitude and speed, a Cessna 172's wings generate approximately " << liftN << " Newtons of lift." << '\n';

}


void printWingLift(double liftN)
{
	double liftBothWings{ liftN * 2 };

	std::cout << "At the given altitude and speed, your plane's main wings will generate approximately " << liftBothWings << " Newtons of lift." << '\n';
	std::cout << "Note: this calculation assumes that your wing uses the same lift calculation most game engines use. "<< '\n';

}

double getLiftCoeffecient() //this gets the airspeed from the user
{
	std::cout << "Enter your wing's lift coeffecient: ";
	double Cl{};
	getErrorCheckedInput(Cl);
	return Cl;
}

void printAtmoInfAtAlt(double objectALT, double altitudeInMeters, double F, double groundTempInC, double groundTempInK, double airTempInK, double airkPa, double airkgm3)
{
	std::cout << objectALT << " ft. is " << altitudeInMeters << " M. " << '\n';
	std::cout << F << " F. is " << groundTempInC << " C. " << '\n';
	std::cout << groundTempInC << " C. is " << groundTempInK << " K. " << '\n';
	std::cout << "The air temperature at " << altitudeInMeters << " is " << airTempInK - 273.1 << " C. " << '\n';
	std::cout << "The air pressure at " << altitudeInMeters << " is " << airkPa << " kPa. " << '\n';
	std::cout << "The air density at " << altitudeInMeters << " is " << airkgm3 << " kg/m3. " << '\n';

}

int startMenu()
{
	int shouldLeaveMenu{};
	int menu{};
	std::cout << "1 - Air density calculator" << '\n' << "2 - Wing Maker Tool" << '\n' << "3 - Plane Brainstorming Tool (Under Construction)" << '\n' << "4 - Atmosphere Maker - not yet implemented\n";
	getErrorCheckedInput(menu);
		switch (menu)
		{

		case 1:
		{
			mainFunc::g_pCoolDensityCalc();
			shouldLeaveMenu = 1;
			break;
		}
		case 2:
		{
			mainFunc::g_pCoolWingTool();
			shouldLeaveMenu = 1;
			break;
		}
		case 3:
		{
			shouldLeaveMenu = 1;
			break;
		}
		case 4:
		{
			shouldLeaveMenu = 1;
			break;
		}
		default:
		{
			shouldLeaveMenu = 0;
			std::cout << "Invalid input. Reenter selection." << '\n';
		}
			
		}
return shouldLeaveMenu;
	
}

//getErrorCheckedInput is an overloaded function. It's basically cin plus error handling for incorrect value types i.e entering "A" instead of a number
void getErrorCheckedInput(int& x)
{
	bool hasUserEnteredProperInput(false);

	while (!hasUserEnteredProperInput)
	{
		int boundsCheckedInput{};
		std::cin >> boundsCheckedInput;


		if (didUserInputFail())
		{
			std::cout << "Invalid input detected. Reenter: \n ";
			continue;
		}

	clearUserInputStream();
	x = boundsCheckedInput;
	return;
	}
}

void getErrorCheckedInput(double& x)
{
	bool hasUserEnteredProperInput(false);

	while (!hasUserEnteredProperInput)
	{
		double boundsCheckedInput{};
		std::cin >> boundsCheckedInput;


		if (didUserInputFail())
		{
			std::cout << "Invalid input detected. Reenter: \n ";
			continue;
		}

		clearUserInputStream();
		x = boundsCheckedInput;
		return;
	}
}

void getErrorCheckedInput(std::string& x)
{
	bool hasUserEnteredProperInput(false);

	while (!hasUserEnteredProperInput)
	{
		std::string boundsCheckedInput{};
		std::cin >> boundsCheckedInput;


		if (didUserInputFail())
		{
			std::cout << "Invalid input detected. Reenter: \n ";
			continue;
		}

		clearUserInputStream();
		x = boundsCheckedInput;
		return;
	}
}
