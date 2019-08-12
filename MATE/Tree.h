#include "Pyramid.h"
#include "CCube.h"

class Tree{
#pragma region CONSTURCTOR
public:
	Tree(); // Constructor
#pragma endregion

#pragma region MODEL
private:
	CCube log;
	Pyramid Leafs;

	void Model_Tree(); // Create the tree model
#pragma endregion

#pragma region ACTIONS
public:
	void RotateSelf(Axis axis, double rotate_value); // Rotates the model without moving it (stay on the axis)
	void MoveByValue(Axis axis, double move_value); // Moves the model by a value (x + move_value)
	void MoveByValue(double x, double y, double z);
	void MoveCenterTo(Axis axis, double center_value); // Moves the model center to the center_value
	void MoveCenterTo(double x, double y, double z);
	void SetColor(int index, double red, double green, double blue); // Sets the model color
	void Draw(); // Draws the model
#pragma endregion
};