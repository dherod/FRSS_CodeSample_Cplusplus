//-------------------------------------------------------------------------------------------------
// FrTime.cpp
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

#include "stdafx.h"
#include "FrTime.h"
#include <sstream>
#include <ctime>
#include <iomanip>

//
// Construct object with current time
//
FrTime::FrTime()
{
	// Initialize members
	setCurrentTime();
}

//
// Construct object with specified time
//
FrTime::FrTime(int hour, int minute, int second)
{
	// Initialize members
	setCurrentTime();

	// Change to provided values
	timeInfo.tm_hour = hour;
	timeInfo.tm_min = minute;
	timeInfo.tm_sec = second;

	// Update members
	update();
}

//
// Construct object with specified datetime
//
FrTime::FrTime(int hour, int minute, int second, int month, int day, int year)
{
	// Initialize members
	setCurrentTime();

	// Change to provided values
	timeInfo.tm_hour = hour;
	timeInfo.tm_min = minute;
	timeInfo.tm_sec = second;
	timeInfo.tm_mon = month;
	timeInfo.tm_mday = day;
	timeInfo.tm_year = year;

	// Update members
	update();
}

//
// Fill members with current time
// private
//
void FrTime::setCurrentTime()
{
	// Set current time
	time(&rawTime);
	// Set timeinfo struct
	localtime_s(&timeInfo, &rawTime);
}

//
// Update members with new timeinfo struct
// Use this to update day and month names, etc.
// private
//
void FrTime::update()
{
	// Set time from timeinfo struct
	rawTime = mktime(&timeInfo);
	// Set (update) timeinfo struct
	localtime_s(&timeInfo, &rawTime);
}

//
// Year accessor / mutator
//
int FrTime::getYear()
{
	return timeInfo.tm_year;
}
void FrTime::setYear(int year)
{
	timeInfo.tm_year = year;
	update();
}

//
// Month accessor / mutator
//
int FrTime::getMonth()
{
	return timeInfo.tm_mon;
}
void FrTime::setMonth(int month)
{
	timeInfo.tm_mon = month;
	update();
}

//
// Day accessor / mutator
//
int FrTime::getDay()
{
	return timeInfo.tm_mday;
}
void FrTime::setDay(int day)
{
	timeInfo.tm_mday = day;
	update();
}

//
// Hour accessor / mutator
//
int FrTime::getHour()
{
	return timeInfo.tm_hour;
}
void FrTime::setHour(int hour)
{
	timeInfo.tm_hour = hour;
	update();
}

//
// Minute accessor / mutator
//
int FrTime::getMinute()
{
	return timeInfo.tm_min;
}
void FrTime::setMinute(int minute)
{
	timeInfo.tm_min = minute;
	update();
}

//
// Second accessor / mutator
//
int FrTime::getSecond()
{
	return timeInfo.tm_sec;
}
void FrTime::setSecond(int second)
{
	timeInfo.tm_sec = second;
	update();
}

//
// Reset with current time
//
void FrTime::reset()
{
	setCurrentTime();
}

//
// Returns string representing object in datetime format
//
string FrTime::toStringDateTime() 
{
	char buffer[26];
	errno_t errNum;
	errNum = asctime_s(buffer, &timeInfo);
	if (errNum)
	{
		return "There was an error converting the time stored.";
	}	

	return buffer;
}

//
// Returns string representing object in time format: HH:MM:SS
//
string FrTime::toStringTime() 
{
	ostringstream builder;
	// Format with leading 0s
	builder << setw(2) << setfill('0') << getHour() << ":" 
		<< setw(2) << setfill('0') << getMinute() << ":" 
		<< setw(2) << setfill('0')<< getSecond();

	return builder.str();
}
