#include "Bowl.h"
#include "Common.h"

#pragma region CTOR
Bowl::Bowl(){
	rotationX = rotationY = rotationZ = 0;
	scaleX = scaleY = scaleZ = 1;
	foodAmount = 5;
	Model_Scale();
	Model();
}
#pragma endregion

#pragma region MODEL CREATION
void Bowl::Model_Scale(){
	floor.ScaleModel(0.2, 0.03, 0.2);
	food.ScaleModel(0.15, 0.001, 0.15);
	for (int i = 0; i < 4; i++){
		walls[i].ScaleModel(0.03, 0.07, 0.2);
	}
}
void Bowl::Model_Floor(){
	for (int i = 0; i < 6; i++)
		floor.SetOnePolygonColor(i, 0.142 + (0.1 * i), 0.142 + (0.1 * i), 0.142 + (0.1 * i));
}
void Bowl::Model_Walls(){
	for (int i = 0; i < 4; i++){
		walls[i].MoveModel(Y_AXIS, 0.05 * scaleY);
		for (int j = 0; j < 6; j++)
			walls[i].SetOnePolygonColor(j, 0.142 + (0.1 * j), 0.142 + (0.1 * j), 0.142 + (0.1 * j));
	}

	walls[0].MoveModel(X_AXIS, 0.0846 * scaleX);
	walls[1].MoveModel(X_AXIS, -0.0846 * scaleX);
	walls[2].RotateSelfModel(Y_AXIS, 45);
	walls[2].MoveModel(Z_AXIS, -0.0846 * scaleZ);
	walls[3].RotateSelfModel(Y_AXIS, -45);
	walls[3].MoveModel(Z_AXIS, 0.0846 * scaleZ);
}
void Bowl::Model_Food(){
	food.MoveModel(Y_AXIS, 0.085 * scaleY);
	food.SetModelColor(0.6, 0.298, 0);
}
void Bowl::Model(){
	Model_Floor();
	Model_Walls();
	Model_Food();
}
#pragma endregion

#pragma region MOVEMENT
void Bowl::MoveByValue(Axis axis, double move_value){
	floor.MoveModel(axis, move_value);
	food.MoveModel(axis, move_value);
	for (int i = 0; i < 4; i++)
		walls[i].MoveModel(axis, move_value);
}
void Bowl::MoveByValue(double x, double y, double z){
	MoveByValue(X_AXIS, x);
	MoveByValue(Y_AXIS, y);
	MoveByValue(Z_AXIS, z);
}
void Bowl::MoveCenterTo(Axis axis, double center_value){
	floor.MoveModelCenter(axis, center_value);
	food.MoveModelCenter(axis, center_value);
	for (int i = 0; i < 4; i++){
		walls[i].MoveModelCenter(axis, center_value);
	}
	Model();
}
void Bowl::MoveCenterTo(double x, double y, double z){
	floor.MoveModelCenter(x, y, z);
	food.MoveModelCenter(x, y, z);
	for (int i = 0; i < 4; i++){
		walls[i].MoveModelCenter(x, y, z);
	}
	Model();
}
#pragma endregion

#pragma region MODEL ACTIONS
void Bowl::RotateSelf(Axis axis, double rotate_value){
	CPoint bodyCenter = floor.GetModelCenter();

	bodyCenter.ScalePoint(-1, -1, -1);

	floor.MoveModel(bodyCenter);
	food.MoveModel(bodyCenter);
	for (int i = 0; i < 4; i++){
		walls[i].MoveModel(bodyCenter);
	}

	bodyCenter.ScalePoint(-1, -1, -1);

	floor.RotateModel(axis, rotate_value);
	food.RotateModel(axis, rotate_value);
	for (int i = 0; i < 4; i++){
		walls[i].RotateModel(axis, rotate_value);
	}

	floor.MoveModel(bodyCenter);
	food.MoveModel(bodyCenter);
	for (int i = 0; i < 4; i++){
		walls[i].MoveModel(bodyCenter);
	}
	if (axis == X_AXIS) rotationX += rotate_value;
	if (axis == Y_AXIS) rotationY += rotate_value;
	if (axis == Z_AXIS) rotationZ += rotate_value;
}
void Bowl::Scale(Axis axis, double scale_value){
	CPoint bodyCenter = floor.GetModelCenter();

	bodyCenter.ScalePoint(-1, -1, -1);

	floor.MoveModel(bodyCenter);
	food.MoveModel(bodyCenter);
	for (int i = 0; i < 4; i++){
		walls[i].MoveModel(bodyCenter);
	}

	bodyCenter.ScalePoint(-1, -1, -1);

	floor.ScaleModel(axis, scale_value);
	food.ScaleModel(axis, scale_value);
	for (int i = 0; i < 4; i++){
		walls[i].ScaleModel(axis, scale_value);
	}

	floor.MoveModel(bodyCenter);
	food.MoveModel(bodyCenter);
	for (int i = 0; i < 4; i++){
		walls[i].MoveModel(bodyCenter);
	}
	if (axis == X_AXIS) scaleX *= scale_value;
	if (axis == Y_AXIS) scaleY *= scale_value;
	if (axis == Z_AXIS) scaleZ *= scale_value;
}
void Bowl::Scale(double x, double y, double z){
	Scale(X_AXIS, x);
	Scale(Y_AXIS, y);
	Scale(Z_AXIS, z);
}
#pragma endregion

#pragma region GET FUNCTIONS
CPoint Bowl::GetCenter(){
	return floor.GetModelCenter();
}
double Bowl::GetCenter(Axis axis){
	return floor.GetModelCenter().GetCoordinate(axis);
}
double Bowl::GetRotation(Axis axis){
	if (axis == X_AXIS) return rotationX;
	if (axis == Y_AXIS) return rotationY;
	if (axis == Z_AXIS) return rotationZ;
}
double Bowl::GetScale(Axis axis){
	if (axis == X_AXIS) return scaleX;
	if (axis == Y_AXIS) return scaleY;
	if (axis == Z_AXIS) return scaleZ;
}
int Bowl::AmountLeft(){
	return foodAmount;
}
#pragma endregion

#pragma region FOOD
void Bowl::Fill(){
	food.MoveModel(Y_AXIS, 0.001);
	foodAmount++;
}
bool Bowl::Eat(){
	if (foodAmount > 0){
		foodAmount--;
		MinVarValue(foodAmount, 0);
		MaxVarValue(foodAmount, 5);
		food.MoveModel(Y_AXIS, -0.001);
		return true;
	}
	else return false;
}
#pragma endregion

#pragma region DRAW
void Bowl::Draw(){
	floor.DrawModel();
	if (AmountLeft() > 0)
		food.DrawModel();
	for (int i = 0; i < 4; i++)
		walls[i].DrawModel();
}
#pragma endregion