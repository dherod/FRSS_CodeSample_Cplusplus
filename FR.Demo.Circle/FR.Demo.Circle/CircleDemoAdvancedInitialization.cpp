//-------------------------------------------------------------------------------------------------
// CircleDemoAdvancedInitialization.cpp
//
// Appropriate copyright here
//
// Demonstrates the advanced initialization usage of FrCircle struct.
//-------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "CircleDemoAdvancedInitialization.h"
#include "FrCircle.h"
#include <iostream>
#include <sstream>
#include <exception>

//
// Demonstrate advanced initialization usage
//
void demoAdvancedInitialization()
{
	string strCenter;
	FrPoint ptCenter;
	string strRadius;
	double radius;

	cout << "\n\nCreating a fully defined circle using input of center point and radius...\n";

	// Get center point
	while (true)
	{
		cout << "Please enter x and y coordinates of center point (Example: 10 20): ";
		getline(cin, strCenter);
		stringstream steamCenter(strCenter);
		if (steamCenter >> ptCenter.x && steamCenter >> ptCenter.y)
			break;
		cout << "INVALID CENTER POINT\n";
	}

	// Get radius
	while (true)
	{
		cout << "Please enter the radius (Example: 5): ";
		getline(cin, strRadius);
		stringstream steamRadius(strRadius);
		if (steamRadius >> radius)
			break;
		cout << "INVALID RADIUS\n";
	}
	cout << endl;

	// Construct the circle using values entered
	// Protect the application where memory allocation is concerned
	FrCircle* pCircle;
	try
	{
		pCircle = new FrCircle(ptCenter, radius);
	}
	catch (exception& exc)
	{
		cout << "AN ERROR OCCURRED CREATING THE CIRCLE: " << exc.what() << endl;
		return;
	}

	// Show the circle
	cout << "Circle created:\n";
	cout << pCircle->toString() << endl;

	// Clean up
	delete pCircle;
}
