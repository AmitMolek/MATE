#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "Common.h"

using namespace std;

class Scoreboard{
#pragma region CONSTRUCTOR
public:
	Scoreboard(); // The constructor
#pragma endregion

#pragma region ACTIONS
	void AddScore(std::string name, int score); // Adds a score to the scoreboard file
	bool isBiggerScore(int score); // Return true if the score is biggerthen the saved one
	int BestScore(); // Returns the best score
	std::string BestScoreName(); // Returns the best score name
#pragma endregion
};

