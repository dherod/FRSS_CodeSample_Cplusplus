// TestLibraryExe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//#include "PrintableInt.h"
#include "FrCircle.h"
#include "FrTime.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[]) 
{
	/*PrintableInt test(5);
	std::cout << test.toString() << std::endl;

	Circle kfd;
	kfd.radius = 3;
	kfd.area = 28.1f;
	cout << "Circle:" << endl;
	cout << "\tradius: " << kfd.radius << endl;
	cout << "\tarea: " << kfd.area << endl << endl;*/

	/*FrTime time1(5);
	cout << time1.toString() << endl;

	cout << endl;*/





	FrCircle c1;
	FrCircle c3 = c1;
	cout << c3.toString() << endl;
	c1.area = 100;
	cout << c1.toString() << endl;

	FrPoint center;
	center.x = 10;
	center.y = 20;
	double radius = 30;
	FrCircle c2(center, radius);
	cout << c2.toString() << endl;

	cout << endl;

	double test = -1;
	cout << convertUndefinableForOutput(test) << endl;
	test = 1.234;
	cout << convertUndefinableForOutput(test) << endl;

	FrTime time1;
	cout << time1.toStringTime() << endl;
	cout << time1.toStringDateTime() << endl;

	time1.setDay(time1.getDay() - 2);
	time1.setHour(time1.getHour() - 4);
	cout << time1.toStringTime() << endl;
	cout << time1.toStringDateTime() << endl;

	return 0;
}
