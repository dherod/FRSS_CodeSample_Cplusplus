//-------------------------------------------------------------------------------------------------
// FrCircle.h
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

#ifdef COMPILE_FRSTDLIB
  #define FRSTDLIB_EXPORT __declspec(dllexport)
#else
  #define FRSTDLIB_EXPORT __declspec(dllimport)
#endif

#include <string>
using namespace std;

//-------------------------------------------------------------------------------------------------
// Prototypes
//-------------------------------------------------------------------------------------------------
enum circle_color { transparent, red, green, blue, white, yellow };

// Refactor: Move to own file to satisfy Single Responsibility Principle
// and allow to be reused with other shape objects, etc.
struct FRSTDLIB_EXPORT FrPoint
{
	double x;
	double y;
};

struct FRSTDLIB_EXPORT FrCircle
{
	FrPoint center;
	double radius;	
	double diameter;
	double area;
	double circumference;
	circle_color background;

	FrCircle();
	FrCircle(FrPoint, double);
	string toString(void);
};

string FRSTDLIB_EXPORT convertUndefinableForOutput(const double&);
