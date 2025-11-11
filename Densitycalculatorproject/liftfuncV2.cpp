#include "coolaerotoolsmasterheader.h"
#include "pcatconstants.h"
#include <iostream>

//This document contains the functions that takes the user input and returns the lift number


namespace liftCalculations {

	double calculateLiftOfACessna172(double speedMS, double airDensity) //this function calculates the lift from the speed given for a cessna 172
	{
		double c{ 1.7 };				//Cl
		double A = 16.17;


		double LiftinNewtons = c * A * .5 * airDensity * (speedMS * speedMS);

		return LiftinNewtons;

	}

	double calculateLift(double liftCoeffecient, double wingArea, double speedMS, double airDensity) //this function calculates the lift from the speed given for a cessna 172
	{
		double c{ 1.7 };				//Cl
		double A = 16.17;


		double LiftinNewtons = liftCoeffecient * wingArea * .5 * airDensity * (speedMS * speedMS);

		return LiftinNewtons;

	}

	double calcTotalGravForce(double weightKg)
	{
		double gravForceN{ weightKg * aeroConst::earthGrav };
		return gravForceN;
	}


	//todo below
	//double calcDragForce
	//Drag= drag coeffecient * reference area* .5 * (velocity*velocity) 

	//double calcDragCoeffecient
	//dragCd=drag/(reference area*.5*density*(velocity*velocity)

	//double calcInducedDrag
	//induceddragcoefCdi=(liftcoefCl^2)/(pi*aspect ratio*effeciency factor)

	//double calcAspectRatio
	//aspect ratio=span/wingarea

	//double calcTotalDragCoef
	//totaldragCd=drag coef at zero lift Cdo + induced drag coef Cdi



}

/*

Cessna 172 lift coeffecient is approx 1.7
lift equation is L = Cl * A * .5 * r * V^2
L = lift: can be in Newtons
Cl = lift coeffecient. This is a dimensionless quantity and is expressed in a number not in units
A = wing area can be in m2
r = air density - expressed in Kg/cm3. Air at 59F at sea level is 1.2250 Kg/cm3
V = velocity

*/