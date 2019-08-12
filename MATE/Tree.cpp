#include "Tree.h"

#pragma region CONSTURCTOR
Tree::Tree(){
	Model_Tree();
	SetColor(0, 0.36, 0.2, 0.09);
	SetColor(1, 0.13, 0.545, 0.13);
}
#pragma endregion

#pragma region MODEL
void Tree::Model_Tree(){
	log.ScaleModel(0.04, 0.4, 0.04);
	Leafs.Scale(0.2, 0.75, 0.2);
	Leafs.MoveCenterTo(0, 0, -2);
	Leafs.MoveByValue(Y_AXIS, 0);
	log.MoveModelCenter(0, 0, -2);
	log.MoveModelCenter(0, 0, -2);
}
#pragma endregion

#pragma region ACTIONS
void Tree::RotateSelf(Axis axis, double rotate_value){
	CPoint logCenter = log.GetModelCenter();

	logCenter.ScalePoint(-1, -1, -1);

	Leafs.MoveByValue(logCenter);
	log.MoveModel(logCenter);

	logCenter.ScalePoint(-1, -1, -1);

	log.RotateModel(axis, rotate_value);
	Leafs.RotateSelf(axis, rotate_value);

	log.MoveModel(logCenter);
	Leafs.MoveByValue(logCenter);
}
void Tree::MoveByValue(Axis axis, double move_value){
	log.MoveModel(axis, move_value);
	Leafs.MoveByValue(axis, move_value);
}
void Tree::MoveByValue(double x, double y, double z){
	MoveByValue(X_AXIS, x);
	MoveByValue(Y_AXIS, y);
	MoveByValue(Z_AXIS, z);
}
void Tree::MoveCenterTo(Axis axis, double center_value){
	log.MoveModelCenter(axis, center_value);
	Leafs.MoveCenterTo(axis, center_value);
}
void Tree::MoveCenterTo(double x, double y, double z){
	log.MoveModelCenter(x, y, z);
	Leafs.MoveCenterTo(x, y, z);
}
void Tree::SetColor(int index, double red, double green, double blue){
	switch (index){
	case 0:
		for (int i = 0; i < 4; i++)
			log.SetOnePolygonColor(i, red - (0.02 * i), green - (0.02 * i), blue - (0.02 * i));
		break;
	case 1:
		for (int i = 0; i < 5; i++)
			Leafs.SetColor(i, red - (0.02 * i), green - (0.02 * i), blue - (0.02 * i));
		break;
	default:
		log.SetModelColor(0.36, 0.2, 0.09);
		Leafs.SetColor(0.13, 0.545, 0.13);
	}
}
void Tree::Draw(){
	log.DrawModel();
	Leafs.Draw();
}
#pragma endregion