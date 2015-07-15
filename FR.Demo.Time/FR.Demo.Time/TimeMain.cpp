//-------------------------------------------------------------------------------------------------
// TimeMain.cpp
//
// Appropriate copyright here
//
// Defines the entry point for the console application.
//-------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "TimeDemoTime.h"
#include "TimeDemoDateTime.h"
#include <iostream>
#include <sstream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int menuOption;
	do
	{
		while (true)
		{
			cout << "\n\nFrTime Demos:\n";
			cout << "--------------------------------\n";
			cout << "1 - Time Usage\n";
			cout << "2 - DateTime Usage\n";
			cout << "0 - Quit\n";
			cout << "Please select demo option: ";
			// Protect against malformed entry
			string strMenuOption;
			getline(cin, strMenuOption);
			stringstream streamMenuOption(strMenuOption);
			if (streamMenuOption >> menuOption)
				break;
			cout << "\nERROR SELECTING MENU OPTION\n" << endl;
		}

		switch (menuOption)
		{
            case 1:
                demoTime();
                break;

            case 2:
                demoDateTime();
                break;

            default:
                break;
        }
	}
	while (menuOption != 0);

	return 0;
}
