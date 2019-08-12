#include "CCube.h"

class Fence{
#pragma region CONSTRUCTOR
public:
	Fence(); // Contrcutor
#pragma endregion

#pragma region MODEL
private:
	CCube fence[4];

	void Model_Fence(); // Creating th fence model
#pragma endregion

#pragma region ACTIONS
public:
	void RotateSelf(Axis axis, double rotate_value); // Rotates the fence
	void MoveByValue(Axis axis, double move_value); // Moves the fence plus the given value
	void MoveCenterTo(Axis axis, double center_value); // Moves the fence's center to the given point
	void MoveCenterTo(double x, double y, double z);
	void SetColor(double red, double green, double blue); // Sets the gence color
	void Draw(); // Draws the fence
#pragma endregion

};