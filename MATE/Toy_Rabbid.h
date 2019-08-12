#pragma once
#include "CCube.h"

class Toy_Rabbid{
#pragma region CONSTRUCTOR
public:
	Toy_Rabbid(); // Constructor
#pragma endregion

#pragma region VARS
private:
	double rotationX, rotationY, rotationZ; // Holds the toy rotation values
	double scaleX, scaleY, scaleZ; // Holds the toy scale values
#pragma endregion

#pragma region MODEL
private:
	CCube body, head, stomach, hands[2], legs[2], eyes[2], pupils[2], ears[2];
	bool isPlayed;

	void Model_Scale();
	void Model_Body();
	void Model_Stomach();
	void Model_Head();
	void Model_Hands();
	void Model_Legs();
	void Model_Eyes();
	void Model_Pupils();
	void Model_Ears();
public:
	void Model();
#pragma endregion

#pragma region ACTIONS
	void RotateSelf(Axis axis, double rotate_value); // Rotates the toy on a axis (without moving it)
	void RotateSelf(double x, double y, double z);
	void Scale(Axis axis, double scale_value); // Scales the penguin's model
	void Scale(double x, double y, double z);
	void MoveByValue(Axis axis, double move_value); // Move the toy by a value (x + move_value)
	void MoveByValue(double x, double y, double z);
	void MoveCenterTo(Axis axis, double center_value); // Move the penguin's center to a point
	void MoveCenterTo(double x, double y, double z);
	void MoveCenter(double x, double y, double z); // Move the penguin even if it has rotation values
	CPoint GetCenter(); // Return the model center
	double GetCenter(Axis axis);
	double GetRotation(Axis axis); // Return the model rotation
	double GetScale(Axis axis); // Return the model scale
	void ResetRotation(Axis axis); // Reset the model rotation to 0
	void SetColor(int index, double red, double green, double blue); // Sets the toy color
	bool GetPlayed(); // Return the state of isPlayed
	void SetPlayed(bool state); // Set the state of isPlayed
	void Draw(); // Draws the penguin model
#pragma endregion
};