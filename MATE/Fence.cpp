#include "Fence.h"

#pragma region CONSTRUCTOR
Fence::Fence(){
	Model_Fence();
}
#pragma endregion

#pragma region MODEL
void Fence::Model_Fence(){
	//0 - rightVertical | 1 - leftVertical | 2 - upHori | 3 - downHori

	fence[0].ScaleModel(0.02, 0.15, 0.02);
	fence[1].ScaleModel(0.02, 0.15, 0.02);
	fence[2].ScaleModel(0.2, 0.02, 0.02);
	fence[3].ScaleModel(0.2, 0.02, 0.02);

	MoveCenterTo(0, 0, -2);

	fence[0].MoveModel(X_AXIS, 0.04);
	fence[1].MoveModel(X_AXIS, -0.04);
	fence[2].MoveModel(Y_AXIS, 0.05);
}
#pragma endregion

#pragma region ACTIONS
void Fence::MoveByValue(Axis axis, double move_value){
	for (int i = 0; i < 4;i++){
		fence[i].MoveModel(axis, move_value);
	}
}
void Fence::MoveCenterTo(Axis axis, double center_value){
	for (int i = 0; i < 4; i++)
		fence[i].MoveModelCenter(axis, center_value);
}
void Fence::MoveCenterTo(double x, double y, double z){
	for (int i = 0; i < 4; i++)
		fence[i].MoveModelCenter(x, y, z);
}
void Fence::RotateSelf(Axis axis, double rotate_value){
	CPoint rightPole = fence[2].GetModelCenter();

	rightPole.ScalePoint(-1, -1, -1);

	for (int i = 0; i < 4; i++)
		fence[i].MoveModel(rightPole);

	rightPole.ScalePoint(-1, -1, -1);

	for (int i = 0; i < 4; i++)
		fence[i].RotateModel(axis, rotate_value);

	for (int i = 0; i < 4; i++)
		fence[i].MoveModel(rightPole);
}
void Fence::SetColor(double red, double green, double blue){
	for (int i = 0; i < 2; i++)
		fence[i].SetModelColor(red, green, blue);

	for (int i = 2; i < 4; i++)
		fence[i].SetModelColor(red - 0.05, green - 0.05, blue - 0.05);

	for (int i = 0; i < 4; i++){
		fence[i].SetOnePolygonColor(3, red- 0.09, green - 0.09, blue - 0.09);
		fence[i].SetOnePolygonColor(1, red - 0.09, green - 0.09, blue - 0.09);
	}
}
void Fence::Draw(){
	for (int i = 0; i < 4; i++)
		fence[i].DrawModel();
}
#pragma endregion

