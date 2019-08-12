#include "CCube.h"
#include "Common.h"

#pragma once
class Penguin{

#pragma region ACTIONS
public:
	void ScaleAndMoveToCenter(double x, double y, double z, double xScale, double yScale, double zScale); // Scales the penguin's model and then move the penguin center
	CPoint GetCenter(); // Return the model center
	double GetCenter(Axis axis);
	double GetRotation(Axis axis); // Return the model rotation
	double GetScale(Axis axis); // Return the model scale
	void ResetRotation(Axis axis); // Reset the model rotation to 0
	double GetPos(Axis axis); // Return the penguin position
	void SetPos(); // Sets the penguin position
	void Draw(); // Draws the penguin model
#pragma endregion

#pragma region ACTIONS-MODEL
public:
	void Blink_Open(); // Makes the eyes open (white)
	void Blink_Close(); // Makes the eyes close (black)
	void Grow(); // Makes the penguin bigger
	void GrowAge(); // If the penguin is old enough, it grows
#pragma endregion

#pragma region STATS
	void SetName(char* Name); // Sets the penguin's name
	char* GetName(); // Return the penguin's name
#pragma endregion

#pragma region CTOR
public:
	Penguin(void);
#pragma endregion

#pragma region VARS
public:
	// Save the penguin's position
	double posX, posY, posZ;
	// Saves the penguin condition (stats)
	double sleep, health;
	int clean, fun, age, hunger;
	// Save if the penguin is sick (True if sick)
	bool sick;
private:
	// Save the penguin's name
	char* name;
	// Saves the penguin rotation values
	double rotationX, rotationY, rotationZ;
	// Saves the penguin's scale vlues
	double scaleX, scaleY, scaleZ;
#pragma endregion

#pragma region MODEL CREATION
private:
	// The model parts
	CCube head;
	CCube beak;
	CCube body;
	CCube hands[2];
	CCube legs[2];
	CCube eyes[2];
	CCube pupils[2];

	// Functions for setting the model
	void Model_Scale();
	void Model_Head();
	void Model_Beak();
	void Model_Body();
	void Model_Hands();
	void Model_Legs();
	void Model_Eyes();
	void Model_Pupils();

public:
	// Calls the setting functions
	void Model();
#pragma endregion

#pragma region MOVEMENT
public:
	// Moves the model by value (posX + move_value)
	void MoveByValue(Axis axis, double move_value);
	void MoveByValue(double x, double y, double z);
	void MoveByValue(CPoint point);
	// Moves the model center to the center_value (posX = center_value)
	void MoveCenterTo(Axis axis, double center_value);
	void MoveCenterTo(CPoint center_point);
	void MoveCenterTo(double x, double y, double z);
	// Moves the pengin center to the center_value even if the model has rotation values
	void MoveCenter(double x, double y, double z);
#pragma endregion

#pragma region MODEL ACTIONS
public:
	// Rotates the model on the given axis by rotate_value
	void RotateSelf(Axis axis, double rotate_value);
	void RotateSelf(double x, double y, double z);
	// Scales the model on the given axis by scale_value
	void Scale(Axis axis, double scale_value);
	void Scale(double x, double y, double z);
#pragma endregion

#pragma region GET FUNCTIONS

#pragma endregion
};