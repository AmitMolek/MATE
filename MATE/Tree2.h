#include "Pyramid.h"
#include "CCube.h"

class Tree2{
#pragma region CONSTURCTOR
public:
	Tree2(); // Constructor
#pragma endregion

#pragma region MODEL
private:
	CCube log;
	Pyramid topLeafs, middleLeafs, bottomLeafs;

	void Model_Tree(); // Create the tree model
#pragma endregion

#pragma region ACTIONS
public:
	void RotateSelf(Axis axis, double rotate_value); // Rotates the model on a axis without moving
	void MoveByValue(Axis axis, double move_value); // Moves the model by value (x + move_value)
	void MoveByValue(double x, double y, double z);
	void MoveCenterTo(Axis axis, double center_value); // Moves the model center to the center_value
	void MoveCenterTo(double x, double y, double z);
	void SetColor(int index, double red, double green, double blue); // Sets the model color
	void Draw(); // Draws the model
#pragma endregion
};