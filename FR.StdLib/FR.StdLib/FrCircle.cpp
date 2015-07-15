//-------------------------------------------------------------------------------------------------
// FrCircle.cpp
//
// Appropriate copyright here
//
// FrCircle defines a struct in the FrStdLib library that represents a circle.
//
// There are 2 main usages, based upon construction:
//
// 1. Data Structure
//    a. FrCircle struct is used as a data structure to hold the qualities of a circle.  
//    b. It is constructed with the no argument constructor.
//    c. It initializes to the center set to (0,0) and the background set to transparent.
//    d. Qualities other than center and background are undefined until set.
//    e. All qualities are public and can be set to a provided value.
//							
// 2. Advanced Initialization
//    a. FrCircle struct is used as a completely defined circle.
//    b. Is is constructed with the minimum initialization needed, namely the center and radius.
//    c. It initializes and calculates all other qualities, with background set to transparent.
//    d. No qualitites are initially undefined.
//    e. All qualities are public and can be set to a provided value.
//-------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "FrCircle.h"
#include <sstream>

//-------------------------------------------------------------------------------------------------
// Definitions
//-------------------------------------------------------------------------------------------------
const double PI = 3.1415926;
const double UNDEFINED = -1;

// Note that this construct is to provide UI friendly names for enums.
// It needs to be kept synchronized with the enum in the header file and is 
// therefore a prime candidate for refactoring.
#define STRINGIFY(x) #x
const char* CIRCLE_COLOR_NAMES[] = 
{ 
	STRINGIFY(transparent), STRINGIFY(red), STRINGIFY(green), STRINGIFY(blue), 
	STRINGIFY(white), STRINGIFY(yellow)
};

//-------------------------------------------------------------------------------------------------
// Functions
//-------------------------------------------------------------------------------------------------

//
// Constructor for data structure usage
//
FrCircle::FrCircle() 
{
	center.x = 0;
	center.y = 0;
	radius = UNDEFINED;
	diameter = UNDEFINED;
	area = UNDEFINED;
	circumference = UNDEFINED;
	background = circle_color::transparent;
}

//
// Constructor for advanced initialization usage
//
FrCircle::FrCircle(FrPoint center, double radius) : center(center), radius(radius)
{
	diameter = 2 * radius;
	area =  PI * pow(radius, 2);
	circumference =  2 * PI * radius;
	background = circle_color::transparent;
}

//
// Returns a string with all the qualities of the FrCircle struct
//
string FrCircle::toString()
{
	string strBackground = CIRCLE_COLOR_NAMES[background];
	ostringstream builder;
	builder << "The circle has center at (" << center.x << ", " << center.y << ")" 
		<< " and a radius of " << convertUndefinableForOutput(radius) << "." << endl
		<< "Its diameter is " << convertUndefinableForOutput(diameter) << "." << endl
		<< "Its area is " << convertUndefinableForOutput(area) << "." << endl
		<< "Its circumference is " << convertUndefinableForOutput(circumference) << "." << endl
		<< "Its background is " << strBackground << "." << endl;
	return builder.str();
}

//
// Helper function to handle undefined values for output
//
string convertUndefinableForOutput(const double& undefinable)
{
	return (undefinable == UNDEFINED) ? "undefined" : to_string(undefinable);
}
