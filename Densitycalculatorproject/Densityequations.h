#include <iostream>
#ifndef DENSITY_EQUATIONS101325
#define DENSITY_EQUATIONS101325

//UI stuff
double getAirTempInF(double x);
double getPressureAtSeaLevel(double x);
double getAltOfObject(double x);
void printAtmosphereLayer(double altM);
double getWingArea();
void printWingArea(double wingArea);
double getSpeedinKnots();
void printC172Comparison(double liftN);
void printWingLift(double liftN);
double getLiftCoeffecient();


// unit conversions
double convertFeetToMeters(double feet);
double convertFarenheitToCelsius(double tempF);
double convertCtoK(double CASL);
double convertKnotsToMS(double x);

//density calculations

double calculateTempAtAltitude(double aslK, double altM);
double calculatekPaAtALT(double aslkPa, double altTempK, double altM);
double calculateDensityAtALT(double kPaAlt, double kalt);

namespace liftCalculations
{
	double calculateLiftOfACessna172(double speedMS, double airDensity);
	double calculateLift(double liftCoeffecient, double wingArea, double speedMS, double airDensity);
}

#endif