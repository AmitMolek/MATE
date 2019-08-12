#include "CCube.h"

class Poop{
#pragma region CONSTRUCTOR
public:
	Poop(); // Constructor
#pragma endregion

#pragma region VARS
	double rotationX, rotationY, rotationZ; // Save the poop rotation values
	double scaleX, scaleY, scaleZ; // Save the poop scale values
private:
	bool isPoop; // Save the state of the poop, if the penguin has pooped it is will be equal True
#pragma endregion

#pragma region MODEL
private:
	CCube lowerCube, middleCube, higherCube;

	void Model_Scale(); // Scales the model
	void Model_lowerPoop(); // Create the model's lower poop
	void Model_middlePoop(); // Create the model's middle poop
	void Model_higherPoop(); // Create the model's higher poop
public:
	void Model(); // Calls the Model Creations function
#pragma endregion

#pragma region ACTIONS
public:
	void RotateSelf(Axis axis, double rotate_value); // Rotates the model by axis without moving
	void RotateSelf(double x, double y, double z);
	void ResetRotation(Axis axis); // Reset the model rotation
	void Scale(Axis axis, double scale_value); // Scales the model
	void Scale(double x, double y, double z);
	void MoveByValue(Axis axis, double move_value); // Moves the model by value (x + move_value)
	void MoveCenterTo(Axis axis, double center_value); // Moves the model center to center_value
	void MoveCenterTo(double x, double y, double z);
	void MoveCenter(double x, double y, double z); // Reset the model rotation then moves the model center to the x, y, z
	void MoveLayer(Axis axis, double move_value, int layer_index); // Moves one layer(layer_index) by value (x + move_value)
	void SetColor(int index, double red, double green, double blue); // Sets the poop color
	void Bigger(int penguin_age); // Makes the poop bigger
	void Pooping(); // When the penguin poops , sets isPoop to true
	void Clean(); // When the player clean the poop, sets isPoop the false
	bool isPooped(); // Return the value of isPoop
	void Draw(); // Draws the poop
#pragma endregion
};