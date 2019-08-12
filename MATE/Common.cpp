#include "Common.h"
#include <stdlib.h>

//global functions:
int random(int num){
	//you need to put the next line before the random call:
	//srand( (unsigned)time( NULL ) );
	return int(float(rand())/RAND_MAX*num);
}

float Pie(){
	return (float)3.14159;
}

double DegreesToRadians(double angle){
	return (angle * (Pie() / 180));
}

double RandNum(double fMin, double fMax){
	return (fMin + ((double)rand() / RAND_MAX) * (fMax - fMin));
}

double MaxVarValue(double var, double max_value){
	return (var >= max_value ? max_value : var);
}

double MinVarValue(double var, double min_value){
	return (var < min_value ? min_value : var);
}

char* StringToCharArray(std::string str){
	char *cstr = new char[str.length() + 1];
	strcpy(cstr, str.c_str());
	return cstr;
}