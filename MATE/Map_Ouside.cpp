#include "Map_Ouside.h"
#include "Common.h"

#pragma region CONSTRUCTOR
Map_Ouside::Map_Ouside(){
	Fences();
	Grass();
	Trees();
}
#pragma endregion

#pragma region MAP CREATION
void Map_Ouside::Fences(){
	double zPosition = -0.2;
	for (int i = 0; i < 10; i++){
		rightFence[i].MoveByValue(X_AXIS, 0.6);
		rightFence[i].RotateSelf(Y_AXIS, -90);
		rightFence[i].MoveByValue(Y_AXIS, -0.2);
		rightFence[i].MoveByValue(Z_AXIS, 0.8);
		rightFence[i].SetColor(0.35, 0.15, 0);

		leftFence[i].MoveByValue(X_AXIS, -0.6);
		leftFence[i].RotateSelf(Y_AXIS, 90);
		leftFence[i].MoveByValue(Y_AXIS, -0.2);
		leftFence[i].MoveByValue(Z_AXIS, 0.8);
		leftFence[i].SetColor(0.35, 0.15, 0);
	}
	for (int i = 0; i < 6; i++){
		ForwardFence[i].MoveByValue(Z_AXIS, -1.05);
		ForwardFence[i].MoveByValue(Y_AXIS, -0.2);
		ForwardFence[i].MoveByValue(X_AXIS, -0.5);
		ForwardFence[i].SetColor(0.35, 0.15, 0);
	}
	for (int i = 1; i < 10; i++){
		rightFence[i].MoveByValue(Z_AXIS, zPosition);
		leftFence[i].MoveByValue(Z_AXIS, zPosition);
		zPosition -= 0.2;
	}
	ForwardFence[1].MoveByValue(X_AXIS, 0.2);
	ForwardFence[2].MoveByValue(X_AXIS, 0.4);
	ForwardFence[3].MoveByValue(X_AXIS, 0.6);
	ForwardFence[4].MoveByValue(X_AXIS, 0.8);
	ForwardFence[5].MoveByValue(X_AXIS, 1);
}
void Map_Ouside::Grass(){
	grass.ScaleModel(16, 0.01, 25);
	grass.MoveModelCenter(0, 0.009, -2);
	grass.MoveModel(Y_AXIS, -0.3);
	//grass.SetModelColor(0, 0.2, 0);
	grass.SetModelColor(0, 0.392, 0);
}
void Map_Ouside::Trees(){
	trees[0].MoveByValue(0.7, 0, -0.5); trees[0].RotateSelf(Y_AXIS, 45);
	trees[1].MoveByValue(0.2, 0, -1.5); trees[1].RotateSelf(Y_AXIS, 35);
	trees[2].MoveByValue(-0.3, 0, -1.7); trees[2].RotateSelf(Y_AXIS, 68);
	trees[3].MoveByValue(-0.8, 0, -0.7);
	trees[4].MoveByValue(-0.7, 0, 0.5); trees[4].RotateSelf(Y_AXIS, 75);
	trees[5].MoveByValue(1, 0, -3); trees[5].RotateSelf(Y_AXIS, 90);
	trees[6].MoveByValue(2, 0, -3.5);
	trees[7].MoveByValue(1.7, 0, -1.7);
	trees[8].MoveByValue(-0.8, 0, -3); trees[8].RotateSelf(Y_AXIS, 10);
	trees[9].MoveByValue(-1.8, 0, -3); trees[9].RotateSelf(Y_AXIS, -45);

	trees2[0].MoveByValue(0.7, 0, -4.5);
	trees2[1].MoveByValue(-1.4, 0, -4);
	trees2[2].MoveByValue(0.85, 0, -0.05);
	trees2[3].MoveByValue(-2.8, 0, -5);
	trees2[4].MoveByValue(1.8, 0, -6);
}
#pragma endregion

#pragma region ACTIONS
void Map_Ouside::DrawMap(){
	grass.DrawModel();
	for (int i = 0; i < 10; i++){
		rightFence[i].Draw();
		leftFence[i].Draw();
		trees[i].Draw();
	}
	for (int i = 0; i < 6; i++)
		ForwardFence[i].Draw();
	for (int i = 0; i < 5; i++)
		trees2[i].Draw();
}
void Map_Ouside::MoveCenterTo(Axis axis, double center_value){
	grass.MoveModelCenter(axis, center_value);
	for (int i = 0; i < 10; i++){
		rightFence[i].MoveCenterTo(axis, center_value);
		leftFence[i].MoveCenterTo(axis, center_value);
		trees[i].MoveCenterTo(axis, center_value);
	}
	for (int i = 0; i < 6; i++)
		ForwardFence[i].MoveCenterTo(axis, center_value);
	for (int i = 0; i < 5; i++)
		trees2[i].MoveCenterTo(axis, center_value);
}
void Map_Ouside::MoveCenterTo(double x, double y, double z){
	grass.MoveModelCenter(x, y, z);
	for (int i = 0; i < 10; i++){
		rightFence[i].MoveCenterTo(x, y, z);
		leftFence[i].MoveCenterTo(x, y, z);
		trees[i].MoveCenterTo(x, y, z);
	}
	for (int i = 0; i < 6; i++)
		ForwardFence[i].MoveCenterTo(x, y, z);
	for (int i = 0; i < 5; i++)
		trees2[i].MoveCenterTo(x, y, z);
}
void Map_Ouside::RotateTrees(Axis axis, double rotate_value){
	for (int i = 0; i < 10; i++)
		trees[i].RotateSelf(Y_AXIS, RandNum(0, 360));
	for (int i = 0; i < 5; i++)
		trees2[i].RotateSelf(Y_AXIS, RandNum(0, 360));
}
#pragma endregion