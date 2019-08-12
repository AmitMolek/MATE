#include "CCube.h"

class FenceWall{
#pragma region CONSTRUCTOR
public:
	FenceWall();
#pragma endregion

#pragma region MODEL
private:
	CCube fence[4];

	void Model_FenceWall();
#pragma endregion

#pragma region ACTIONS
public:
	void RotateSelf(Axis axis, double rotate_value);
	void MoveByValue(Axis axis, double move_value);
	void MoveCenterTo(Axis axis, double center_value);
	void MoveCenterTo(double x, double y, double z);
	void SetColor(double red, double green, double blue);
	void SetColor(int index, double red, double green, double blue);
	void Draw();
#pragma endregion

};