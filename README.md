IMPORTANT WARNING DISCLAIMER: Pilots should not under any circumstances use patrickscoolaerotools to set their altimeter or do any sort of calculaton related to the operation of an aircraft or any other sort of vehicle. patrickscoolaerotools does NOT use the FAA formulas for atmospheric density and therefore is almost certain to result in an incorrect altimeter setting. patrickscoolaerotools is a tool to help people create plausible behaviors in video games, not to predict real-world phenomenon. 

patrickscoolaerotools currently a work in progress with very limited functionality

The goal of patrickscoolaerotools is not total accuracy. The goal is to get approximate answers which can be used to create plausible behaviors in things like video games. 

The main purpose of patrickscoolaerotools is to tell you the air density for a given altitude based on the ground temperature and barometer reading. 
It currently uses the 1976 US standard atmosphere model to do so. 

You can also calculate the lift of a theoretical wing at a given speed and compare it to a Cessna 172. 
It is also a tool to practice my C++ skills, which are also a work in progress. 

The long term goal for patrickscoolaerotools is to become something game devs can plug into popular game engines to make their aircraft behave plausibly.

October 26 update:
-Fixed a bug which caused the temperature to be thousands of degrees C in the upper atmosphere
-The program no longer displays calculation for your wing and the Cessna wing comparison on the same command line

Planned features:
- Answers that are less flagrantly wrong (low priority)
- I will learn what a class is in the context of C++ and implement it in my program
- I will learn what an array is and implement it (unlikely)
- A function which will tell you if your craft will have generate enough lift to stay airborne at a given weight, speed, and altitude
- Density calculations that can incorporate humidity
- Density calculations from any ground level, not just sea level
- The ability to create your own atmospheres for custom planets
- Headwind and tailwind calculations
- Drag calculations
