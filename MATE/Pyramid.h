#include "CModel.h"

#pragma once
class Pyramid{
#pragma region CONSTRUCTOR
public:
	Pyramid(); // Constructor
#pragma endregion

#pragma region MODEL
private:
	CModel pyramid;

	void Model_Pyramid(); // Create the pyramid model
#pragma endregion

#pragma region ACTIONS
public:
	void RotateSelf(Axis axis, double rotate_value); // Rotates the pyramid on a axis without moving
	void Scale(Axis axis, double scale_value); // Scale the model
	void Scale(double scale_value_x, double scale_value_y, double scale_value_z);
	void MoveByValue(Axis axis, double move_value); // Moves the model by value (x + move_value)
	void MoveByValue(CPoint point);
	void MoveCenterTo(Axis axis, double center_value); // Moves the model center to the center_value
	void MoveCenterTo(double x, double y, double z);
	void SetColor(double red, double green, double blue); // Sets the model color
	void SetColor(int polygon_index, double red, double green, double blue); // Sets the one polygon from the model color
	void Draw(); // Draws the model
#pragma endregion
};