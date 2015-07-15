//-------------------------------------------------------------------------------------------------
// TimeDemoDateTime.cpp
//
// Appropriate copyright here
//
// Demonstrates the datetime usage of FrTime class.
//-------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "TimeDemoDateTime.h"
#include "FrTime.h"
#include <iostream>

//
// Demonstrate datetime usage
//
void demoDateTime()
{	
	// FrTime object to manipulate
	FrTime time(14, 30, 0, 7, 12, 111);
	cout << "\n\nCreated time object for demo datetime usage.\n";

	// Demo Initialization
	cout << "Time object initialized via constructor (14, 30, 0, 7, 12, 111)\n";
	cout << "Time object is: " << time.toStringDateTime() << endl;

	// Demo Mutation
	cout << "Time object mutated to current time\n";
	time.reset();
	cout << "Time object is: " << time.toStringDateTime() << endl;

	cout << "Time object mutated to yesterday (day - 1)\n";
	time.setDay(time.getDay() - 1);
	cout << "Time object is: " << time.toStringDateTime() << endl;	

	// Demo copy constructor
	FrTime timeCopyCtor(time);
	cout << "2nd time object initialized via copy constructor using 1st time object\n";
	cout << "1st time object is: " << time.toStringDateTime();
	cout << "2nd time object is: " << timeCopyCtor.toStringDateTime() << endl;

	cout << "1st time object mutated to 3 years ago (year - 3)\n";
	cout << "3rd time object set via copy assignment operator using 1st time object\n";
	time.setYear(time.getYear() - 3);
	FrTime timeCopyAssignmentOp = time;
	cout << "1st time object is: " << time.toStringDateTime();
	cout << "3rd time object is: " << timeCopyAssignmentOp.toStringDateTime() << endl;

	cout << "Reset 1st time object\n";
	time.reset();
	cout << "1st time object is: " << time.toStringDateTime();
	cout << "2nd time object is: " << timeCopyCtor.toStringDateTime();
	cout << "3rd time object is: " << timeCopyAssignmentOp.toStringDateTime();
}
