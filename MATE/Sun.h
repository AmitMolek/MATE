#include "CCube.h"

class Sun{
#pragma region CONSTRUCTOR
public:
	Sun(); // Constructor
#pragma endregion

#pragma region MODEL
private:
	CCube sun;

	void Model_Sun(); // Create the sun model
#pragma endregion

#pragma region ACTIONS
public:
	CPoint GetCenter(); // Returns the sun center point
	void RotateSelf(Axis axis, double rotate_value); // Rotates the sun without moving it from the axis
	void Rotate(Axis axis, double rotate_value); // Rotates the sun (circle like motion)
	void Rotate(double x, double y, double z);
	void MoveByValue(Axis axis, double move_value); // Moves the sun by value (x + move_value)
	void MoveByValue(double x, double y, double z);
	void MoveCenterTo(Axis axis, double center_value); // Moves the sun center to the center_value
	void MoveCenterTo(double x, double y, double z);
	void SetColor(double red, double green, double blue); // Sets the sun color
	void Draw(); // Draws the sun
#pragma endregion
};