#include <iostream>
#include "pcatMainFunctions.h"
#ifndef MASTER_HEADER_PCAT103125
#define MASTER_HEADER_PCAT103125

//Titles and other text that might be used over and over
inline const std::string g_ProgramTitle{ "Welcome to patricksCoolAeroTools v0.0000000001\n\n\n" };
inline const std::string g_DensityCalcTitle{ "patricksCoolDensityCalculator\nThis tool will find the air density at a given altitude.\nYou can use this to map your game's atmosphere against Earth's. \n" };
inline const std::string g_LiftCalcTitle{ "paticksCoolLiftCalculator\nThis tool will help give you some context as to how much lift your plane's wings should create\n" };
inline const std::string g_AtmoMakerTitle{ "\npatricksCoolAtmosphereMaker\n This tool will help you create the equations for an atmosphere that's right for your game,\n" };

//UI functions 
void printProgramTitle(std::string_view programTitle);
void printUILine(std::string_view x);
void clearUserInputStream();
bool didUserInputFail();

double getAirTempInF();
double getPressureAtSeaLevel();
double getAltOfObject();
void printAtmosphereLayer(double altM);
double getWingArea();
double getWeightLbs();
double getWeightkg();
void printWingArea(double wingArea);
double getSpeedinKnots();
void printC172Comparison(double liftN);
void printWingLift(double liftN);
double getLiftCoeffecient();
void printAtmoInfAtAlt(double objectALT, double altitudeInMeters, double F, double groundTempInC, double groundTempInK, double airTempInK, double airkPa, double airkgm3);
int startMenu();
void getErrorCheckedInput(int& x);
void getErrorCheckedInput(double& x);
void getErrorCheckedInput(std::string& x);



// unit conversions
double convertFeetToMeters(double feet);
double convertFarenheitToCelsius(double tempF);
double convertCtoK(double CASL);
double convertKnotsToMS(double x);
double convlbsToKg(double weightlbs);
double convKgTolbs(double weightKg);

//density calculations

double calculateTempAtAltitude(double aslK, double altM);
double calculatekPaAtALT(double aslkPa, double altTempK, double altM);
double calculateDensityAtALT(double kPaAlt, double kalt);
double calcAirDensityStandardModel(double altM);

namespace liftCalculations
{
	double calculateLiftOfACessna172(double speedMS, double airDensity);
	double calculateLift(double liftCoeffecient, double wingArea, double speedMS, double airDensity);
}

//Atmosphere Maker Tool 


#endif 