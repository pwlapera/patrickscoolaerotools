#include "Densityequations.h"
#include <iostream>

// these change any non metric values the user enters to the metric values we are using in our density calculations

double convertFeetToMeters(double feet) //this converts the altitude in ft to m
{

	double altm =  feet * .3048 ;

	return altm;

}

double convertFarenheitToCelsius(double tempF) //converts the number the user entered from farenheit to celsius mango energy units
{

	double C = (tempF - 32.0) / 1.8 ;

	return C;

}

double convertCtoK(double CASL) //converts the  temp in c to Kelvin. makes other equations less verbose
{
	double K =  CASL + 273.1;
	return K;
}

double convertKnotsToMS(double x) // converts the speed to m/s
{

	double airSpeedinMS = x * .51444; // this converts from knots to ms as 1 knot is .5144 m/s

	return airSpeedinMS;

}