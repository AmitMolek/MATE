#pragma once
#include "CCube.h"

class Bowl{
#pragma region CTOR
public:
	// The dafault class constructor
	Bowl();
#pragma endregion

#pragma region VARS
private:
	// Holds the model rotation values
	double rotationX, rotationY, rotationZ;
	// Holds the model scale values
	double scaleX, scaleY, scaleZ;
	// Holds the current food amount
	int foodAmount;
#pragma endregion

#pragma region MODEL CREATION
	// The model
	CCube floor, walls[4], food;

	// Scales the model by the same proportion
	void Model_Scale();
	// Handling the model walls
	void Model_Walls();
	// Handling the model floor
	void Model_Floor();
	// Handling the model food
	void Model_Food();
public:
	// Calls all the model handling function
	void Model();
#pragma endregion

#pragma region MOVEMENT
public:
	// Moves the model selected axis by value (posAxis + move_value)
	void MoveByValue(Axis axis, double move_value);
	// Moves the model on all axis by value (posX + x, posY + y, posZ + z)
	void MoveByValue(double x, double y, double z);
	// Moves the model selected axis center to the given center value (posAxis = center_value)
	void MoveCenterTo(Axis axis, double center_value);
	// Moves the model on all axis to the given center values (posX = x, posY = y, posZ = z)
	void MoveCenterTo(double x, double y, double z);
#pragma endregion

#pragma region MODEL ACTIONS
public:
	// Rotates the model on the given axis, without moving the model, by value (rotAxis + rotate_value)
	void RotateSelf(Axis axis, double rotate_value);
	// Scales the model on the given axis, by value (scaleAxis * scale_value)
	void Scale(Axis axis, double scale_value);
	// Scales the model on all axis, by the given values (scaX * x, scaY * y, scaZ * z)
	void Scale(double x, double y, double z);
#pragma endregion

#pragma region GET FUNCTIONS
	// Returns the model center point
	CPoint GetCenter();
	// Returns the model center value of the given axis
	double GetCenter(Axis axis);
	// Returns the model rotation value of the given axis
	double GetRotation(Axis axis);
	// Returns the model scale value of the given axis
	double GetScale(Axis axis);
	// Returns the amount of food
	int AmountLeft();
#pragma endregion

#pragma region FOOD
	// Fill the bowl with food
	void Fill();
	// Decrease the food amount
	bool Eat();
#pragma endregion

#pragma region DRAW
	// Draws the model
	void Draw();
#pragma endregion

};

