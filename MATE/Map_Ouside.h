#include "Tree.h"
#include "Tree2.h"
#include "Fence.h"

class Map_Ouside{
	
#pragma region CONSTRUCTOR
public:
	Map_Ouside();
#pragma endregion

#pragma region CLASS VARS
private:
	Fence rightFence[10];
	Fence leftFence[10];
	Fence ForwardFence[6];
	CCube grass;
	Tree trees[10];
	Tree2 trees2[5];
#pragma endregion

#pragma region MAP CREATION
	void Fences(); // Orginize (place) the fences
	void Grass(); // Orginize (place) the grass platform
	void Trees(); // Orginize (place) the trees
#pragma endregion

#pragma region ACTIONS
public:
	void MoveCenterTo(Axis axis, double center_value);  // Moves the map center to the center_value
	void MoveCenterTo(double x, double y, double z);
	void RotateTrees(Axis axis, double rotate_value); // Rotates the trees in the map
	void DrawMap(); // Draws the map
#pragma endregion
};