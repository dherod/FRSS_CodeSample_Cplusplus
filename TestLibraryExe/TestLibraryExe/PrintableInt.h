// PrintableInt.h
#pragma once

#include <string>

#ifdef COMPILE_MYLIBRARY
  #define MYLIBRARY_EXPORT __declspec(dllexport)
#else
  #define MYLIBRARY_EXPORT __declspec(dllimport)
#endif

class MYLIBRARY_EXPORT PrintableInt {
public:
  // Constructor
  PrintableInt(int value);
  // Converts the int into a string.
  std::string toString() const;
private:
  int m_value;
};

enum MYLIBRARY_EXPORT color {red, green, blue};

struct MYLIBRARY_EXPORT Circle
{
	float radius;
	float area;
	color background;	
};
