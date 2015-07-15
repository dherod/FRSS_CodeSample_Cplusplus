//-------------------------------------------------------------------------------------------------
// FrTime.h
//
// Appropriate copyright here
//
// FrTime defines a class in the FrStdLib library that represents a time.
//
// There are 2 types supported:
//
// 1. Time
//    a. FrTime objects can be constructed with the no argument constructor and are initialized
//       with the current time.
//    b. FrTime objects can be constructed with hour, minute, and second, and are 
//       initialized to that time provided.
//    c. There are accessors and mutators provided for hour, minute, and second, and they update
//       the FrTime object with the values provided and get the values represented.
//    d. The FrTime object can be reset to the current time.
//    e. The FrTime object can output a string representing its time.
//							
// 2. DateTime
//    a. FrTime objects can be constructed with the no argument constructor and are initialized
//       with the current time.
//    b. FrTime objects can be constructed with hour, minute, second, day, month, and year,
//       and are initialized to that datetime provided.
//    c. There are accessors and mutators provided for hour, minute, second, day, month, and year,
//       and they update the FrTime object with the values provided and get the values represented.
//    d. The FrTime object can be reset to the current time.
//    e. The FrTime object can output a string representing its datetime.
//-------------------------------------------------------------------------------------------------

#include <string>
using namespace std;

#ifdef COMPILE_FRSTDLIB
  #define FRSTDLIB_EXPORT __declspec(dllexport)
#else
  #define FRSTDLIB_EXPORT __declspec(dllimport)
#endif

//-------------------------------------------------------------------------------------------------
// Prototypes
//-------------------------------------------------------------------------------------------------
class FRSTDLIB_EXPORT FrTime
{
private:
	// Encapsulated members and functions
	time_t rawTime;
	struct tm timeInfo;
	void setCurrentTime();
	void update();

public:
	// Constructors
    FrTime();
	FrTime(int, int, int);
	FrTime(int, int, int, int, int, int);
	// Implement if need more functionality than what the implicitly generated copy constructor 
	// and copy assignment operator provide.  Note that the current version does not.
	//FrTime(const FrTime&);            
    //FrTime &operator=(const FrTime&) 

	// Accessors and Mutators
	int getYear();
	void setYear(int);
	int getMonth();
	void setMonth(int);
	int getDay();
	void setDay(int);
	int getHour();
	void setHour(int);
	int getMinute();
	void setMinute(int);
	int getSecond();
	void setSecond(int);

	// Functions
	void reset();
	string toStringDateTime();
	string toStringTime();
};
