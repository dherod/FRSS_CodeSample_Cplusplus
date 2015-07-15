//-------------------------------------------------------------------------------------------------
// CircleMain.cpp
//
// Appropriate copyright here
//
// Defines the entry point for the console application.
//-------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "CircleDemoDataStructure.h"
#include "CircleDemoAdvancedInitialization.h"
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
			cout << "\n\nFrCircle Demos:\n";
			cout << "--------------------------------\n";
			cout << "1 - Data Structure Usage\n";
			cout << "2 - Advanced Initialization Usage\n";
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
                demoDataStructure();
                break;

            case 2:
                demoAdvancedInitialization();
                break;

            default:
                break;
        }
	}
	while (menuOption != 0);

	return 0;
}
