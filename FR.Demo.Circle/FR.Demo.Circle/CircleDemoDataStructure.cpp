//-------------------------------------------------------------------------------------------------
// CircleDemoDataStructure.cpp
//
// Appropriate copyright here
//
// Demonstrates the data structure usage of FrCircle struct.
//-------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "CircleDemoDataStructure.h"
#include "FrCircle.h"
#include <iostream>
#include <sstream>

//
// Helper function to get double from UI
// Protects against malformed entry
//
double getDoubleFromUi()
{
	double entry;
	string strEntry;

	while (true)
	{
		// Protect against malformed entry
		getline(cin, strEntry);
		stringstream streamEntry(strEntry);
		if (streamEntry >> entry)
			break;
		cout << "ERROR ENTERING VALUE\n" << "Please try again: ";
	}

	return entry;
}

//
// Helper function to get point from UI
// Protects against malformed entry
//
FrPoint getPointFromUi()
{
	string strPoint;
	FrPoint frPoint;

	while (true)
	{
		// Protect against malformed entry
		getline(cin, strPoint);
		stringstream steamPoint(strPoint);
		if (steamPoint >> frPoint.x && steamPoint >> frPoint.y)
			break;
		cout << "INVALID POINT\n" << "Please try again: ";
	}

	return frPoint;
}

//
// Helper function to get color from UI
// Protects against malformed entry
//
circle_color getColorFromUi()
{
	circle_color background;
	int menuOption;
	string strMenuOption;
	while (true)
	{
		cout << "\nBackground colors:\n";
		cout << "---------------------------\n";
		cout << "1 - Transparent\n";
		cout << "2 - Red\n";
		cout << "3 - Green\n";
		cout << "4 - Blue\n";
		cout << "5 - White\n";
		cout << "6 - Yellow\n";
		cout << "Please select color to set: ";
		// Protect against malformed entry
		getline(cin, strMenuOption);
		stringstream streamMenuOption(strMenuOption);
		if (streamMenuOption >> menuOption && menuOption >= 1 && menuOption <= 6 )
			break;
		cout << "\nERROR SELECTING MENU OPTION\n\n";
	}

	switch (menuOption)
	{
        case 1:
            // Transparent
			background = circle_color::transparent;
            break;

        case 2:
			// Red
			background = circle_color::red;
            break;

		case 3:
			// Green
			background = circle_color::green;
            break;

		case 4:
			// Blue
			background = circle_color::blue;
            break;

        case 5:
			// White
			background = circle_color::white;
            break;

		case 6:
            // Yellow
			background = circle_color::yellow;
            break;

        default:
            break;
    }

	return background;
}

//
// Demonstrate data structure usage
//
void demoDataStructure()
{
	// FrCircle struct to fill
	FrCircle demoCircle;
	cout << "\n\nCreated circle for demo data structure usage.\n";	

	// Menu
	int menuOption;
	string strMenuOption;
	do
	{
		cout << "\nUpdated Circle:";
		cout << endl << demoCircle.toString() << endl;

		while (true)
		{
			cout << "\nMutatable Qualities:\n";
			cout << "---------------------------\n";
			cout << "1 - Center\n";
			cout << "2 - Radius\n";
			cout << "3 - Diameter\n";
			cout << "4 - Area\n";
			cout << "5 - Circumference\n";
			cout << "6 - Background\n";
			cout << "0 - Quit\n";
			cout << "Please select quality to mutate: ";
			// Protect against malformed entry
			getline(cin, strMenuOption);
			stringstream streamMenuOption(strMenuOption);
			if (streamMenuOption >> menuOption)
				break;
			cout << "\nERROR SELECTING MENU OPTION\n\n";
		}

		switch (menuOption)
		{
            case 1:
                // Center;
				cout << "Please enter x and y coordinates of center point (Example: 10 20): ";
				demoCircle.center = getPointFromUi();
                break;

            case 2:
				// Radius
				cout << "Please enter the radius (Example: 5): ";
				demoCircle.radius = getDoubleFromUi();
                break;

			case 3:
				// Diameter
				cout << "Please enter the diameter (Example: 5): ";
                demoCircle.diameter = getDoubleFromUi();
                break;

			case 4:
				// Area
				cout << "Please enter the area (Example: 5): ";
                demoCircle.area = getDoubleFromUi();
                break;

            case 5:
				// Circumference
				cout << "Please enter the circumference (Example: 5): ";
                demoCircle.circumference = getDoubleFromUi();
                break;

			case 6:
                // Background
				demoCircle.background = getColorFromUi();				
                break;

            default:
                break;
        }
	}
	while (menuOption != 0);
}
