#pragma once
#include <string>

int random(int num); // Return random number
float Pie(); // Return PI value
double DegreesToRadians(double angle); // Convert from degrees to radians
double RandNum(double fMin, double fMax); // Returns a random number between the region given
double MaxVarValue(double var, double max_value); // Makes a max limit to the given value
double MinVarValue(double var, double min_value); // Makes a min limit to the given value
char* StringToCharArray(std::string str); // Convert from string to char*