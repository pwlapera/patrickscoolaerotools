#include "coolaerotoolsmasterheader.h"
#include "pcatMainFunctions.h"
#include "pcatconstants.h"


//these are the main functions like the aero calculator, lift calculator. etc
namespace mainFunc {

	inline double g_pCoolDensityCalc()
	{
		printUILine(g_DensityCalcTitle); //calculates air dentity (wrongly)

		double F{ getAirTempInF() };
		double airPressureASL{ getPressureAtSeaLevel() };
		double objectALT{ getAltOfObject() };
		std::cout << "You entered " << F << " F, " << airPressureASL << " kPa, and " << objectALT << "ft ASL" << '\n' << '\n';

		double altitudeInMeters{ convertFeetToMeters(objectALT) };
		double groundTempInC{ convertFarenheitToCelsius(F) };
		double groundTempInK{ convertCtoK(groundTempInC) };
		double airTempInK{ calculateTempAtAltitude(groundTempInK, altitudeInMeters) };
		double airkPa{ calculatekPaAtALT(airPressureASL,airTempInK, altitudeInMeters) };
		double airkgm3{ calculateDensityAtALT(airkPa, airTempInK) };

		printAtmoInfAtAlt(objectALT, altitudeInMeters, F, groundTempInC,
			groundTempInK, airTempInK, airkPa, airkgm3);

		printAtmosphereLayer(altitudeInMeters); '\n';
		std::cout << '\n';

		return airkgm3;
	}

	inline double g_pCoolWingTool() 
	{
		double wingArea{ getWingArea() };
		printWingArea(wingArea);
		double Cl{ getLiftCoeffecient() };
		std::cout << "Let's see how that wing performs. " << '\n';
		double wingALT{ getAltOfObject()};
		double wingALTm{ convertFeetToMeters(wingALT) };
		double speedKnots{ getSpeedinKnots() };
		double speedMS{convertKnotsToMS(speedKnots)};
		double wingALTDensity{ calcAirDensityStandardModel(wingALTm) };
		double liftN{ liftCalculations::calculateLift(Cl, wingArea, speedMS, wingALTDensity) };//fix
		printWingLift(liftN);
		return 1; //remove and change to actual value later
	}
	// in progress and need to add to pcatMainFunctions.h
	inline double g_AtmoMaker()
	{
		printUILine(g_AtmoMakerTitle);

	}



}