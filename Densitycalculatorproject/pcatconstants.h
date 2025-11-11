#ifndef PHYSICS_VALUES102525
#define PHYSICS_VALUES102525

namespace aeroConst //things like gravity etc.
{
	inline constexpr double earthGrav{ 9.80665 }; //gravity on earth is 9.80665 m/s2
	inline constexpr double g_avogadrosNumber{ 6.02214076e23 };
	inline constexpr double g_universalGasConstant{ 8.31432e3 }; // in n/m(kmol/k)
	inline constexpr double g_meanMolecularWeightOfAirASL{ 28.9644 }; //in kg/kmol
	inline constexpr double g_seaLevStandardAtmosPressurekPa{ 101.325 }; //in kPa
	inline constexpr double g_seaLevStandardTempK{ 288.15 };		//in K
	inline constexpr double g_universalGasConst{ 8.314462618 }; // in J/(mol*K)
	inline constexpr double g_seaLevStandardDensitykgm3{ 1.2250 }; // in kg/m3



}

namespace unitConv //numbers that convert units to other units, for example the ratio of kilograms to pounds
{
		inline constexpr double g_KgTolbs{ 0.45359237 };
		inline constexpr double g_lbsToKg{ 2.204623 };
}
#endif // !PHYSICS_VALUES102525
