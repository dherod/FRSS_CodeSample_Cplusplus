//-------------------------------------------------------------------------------------------------
// TimeDemoTime.cpp
//
// Appropriate copyright here
//
// Demonstrates the time usage of FrTime class.
//-------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "TimeDemoTime.h"
#include "FrTime.h"
#include <iostream>
#include <sstream>

//
// Helper function to get int from UI
// Protects against malformed entry
//
int getIntFromUi()
{
	int entry;
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
// Demonstrate time usage
//
void demoTime()
{
	// FrTime object to manipulate
	FrTime time;
	cout << "\n\nCreated time object for demo time usage.\n";	

	// Menu
	int menuOption;
	string strMenuOption;
	do
	{
		cout << "\nUpdated time:";
		cout << endl << time.toStringTime() << endl;

		while (true)
		{
			cout << "\nTime Options:\n";
			cout << "---------------------------\n";
			cout << "1 - Change hour\n";
			cout << "2 - Change minute\n";
			cout << "3 - Change second\n";
			cout << "4 - Reset\n";
			cout << "0 - Quit\n";
			cout << "Please select property to mutate: ";
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
                // Hour;
				cout << "Please enter hour (Example: 4): ";
				time.setHour(getIntFromUi());
                break;

            case 2:
				// Minute;
				cout << "Please enter minute (Example: 30): ";
				time.setMinute(getIntFromUi());
                break;

			case 3:
				// Second;
				cout << "Please enter second (Example: 1): ";
				time.setSecond(getIntFromUi());
                break;

			case 4:
				// Reset;
				time.reset();
                break;

            default:
                break;
        }
	}
	while (menuOption != 0);
}
