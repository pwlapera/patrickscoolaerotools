// Densitycalculatorproject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//this program gets calculates the density of the atmosphere in kg/cm3 from external outputs

#include "Densityequations.h" // the header file for this project
#include <cmath>
#include <iostream>

int main()
{
	double F{ getAirTempInF(0.0)};
	double airPressureASL{ getPressureAtSeaLevel(0.0)};
	double objectALT{ getAltOfObject(0.0) };
	std:: cout << "You entered " << F << " F, " << airPressureASL << " kPa, and " << objectALT << "ft ASL" << '\n' <<'\n';

	double altitudeInMeters{ convertFeetToMeters(objectALT) };
	double groundTempInC{ convertFarenheitToCelsius(F) };
	double groundTempInK{ convertCtoK(groundTempInC) };
	double airTempInK{ calculateTempAtAltitude(groundTempInK, altitudeInMeters) };
	double airkPa{ calculatekPaAtALT(airPressureASL,airTempInK, altitudeInMeters) };
	double airkgm3{ calculateDensityAtALT(airkPa, airTempInK) };

	
	//Outputs the atmpspheric calculations to the user
	std::cout << objectALT << " ft. is " << altitudeInMeters << " M. " << '\n';
	std::cout << F << " F. is " << groundTempInC << " C. " << '\n';
	std::cout << groundTempInC << " C. is " << groundTempInK << " K. " << '\n';
	std::cout <<  "The air temperature at " << altitudeInMeters << " is " << airTempInK - 273.1 << " C. " << '\n';
	std::cout << "The air pressure at " << altitudeInMeters << " is " << airkPa << " kPa. " << '\n';
	std::cout << "The air density at " << altitudeInMeters << " is " << airkgm3 << " kg/cm3. " << '\n';

	printAtmosphereLayer(altitudeInMeters); '\n';

	double speedKnots{ getSpeedinKnots() };
	double speedMS{convertKnotsToMS(speedKnots)};

	//gets info about your cool plane
	double wingArea{ getWingArea() };
	printWingArea(wingArea);
	double Cl{ getLiftCoeffecient() };

	//gets lift info
	double liftN{ liftCalculations::calculateLift(Cl,wingArea,speedMS,airkgm3) };
	double liftNC{ liftCalculations::calculateLiftOfACessna172(speedMS,airkgm3) };
	printWingLift(liftN);
	printC172Comparison(liftNC);

	return 0;
}

//ball weight for a 1m cube should be the local kgm3