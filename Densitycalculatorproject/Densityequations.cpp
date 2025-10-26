#include "Densityequations.h"
#include <cmath>
#include <iostream>

double calculateTempAtAltitude(double aslK, double altM)// this determines what part of the atmosphere you are in and calculates the temp in K at altitude
{
	if (altM <= 11000)
	{
		double tempalt = aslK - .00649 * altM;

		return tempalt;
	}

	if (altM > 11000 && altM <= 25000)
	{
		double tempalt = 216.69;

		return tempalt;
	}

	if (altM > 25000 && altM <= 100000)
	{
		double tempalt = 141.94 + .00299*altM;

		return tempalt;
	}

}

double calculatekPaAtALT(double aslkPa ,double altTempK, double altM) //determines what part of the atmosphere you are in and calculates the barometric pressure at altitude
{

	if (altM <= 11000) //troposhphere calculation
	{
		double kPaAlt = aslkPa * pow((altTempK / 288.08), 5.256); //this is for the toposphere, which ends at 11000m
		//std::cout << "You are in the troposphere. " <<'\n';
		return kPaAlt;
	}

	if (altM>11000 && altM<=25000)
	{
		double kPaAlt = 22.65 * pow(1, (1.73 - .00157 * altM)); //this is the equation for the lower stratosphere.the temp is constant
		//std::cout << "You are in the lower stratosphere. " << '\n';
		return kPaAlt;
	}
	
	if (altM > 25000 && altM <= 100000)
	{
		double kPaAlt = 2.488 * pow((altTempK/216.6),-11.388); //this is the equation for the upper stratosphere.the temp increases exponentially
		//std::cout << "You are in the upper stratosphere. " << '\n';
		return kPaAlt;
	}

	if (altM > 100000)
	{
		double kPaAlt{ 0 };
		//std::cout << "You are straight-up in outer space bro." << '\n';
		return kPaAlt;
	}

}

double calculateDensityAtALT(double kPaAlt, double kalt) // this gives you the density in kg/cm3
{

	double kgm3 = kPaAlt/(.2869*kalt);

	return kgm3;

}



/*

Full density equations for a given altitude in the troposphere

Step one:
Calculate the temp at altitude
T= local ground temp -.00649altitudeinM
T is the temp in C at altitude

Step two: 
get the pressure in kPa
pressureKpa= 101.29x[(T+237.1)/288.08]^5.526

Step 3:
get the kgm3
pressurekgm3 = pressureKPA / (.2869 * (T+273.1)) 

other idea:
use lapse rate for kPa 
.0012kPa per M

more accurate method for getting kPa at alt
pressure at height h = pressure at sea level^-((mass per air molecule*acceleration due to gravity*height from reference point)/boltzmann constant*tempinK

*/

