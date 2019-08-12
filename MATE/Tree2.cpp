#include "Tree2.h"

#pragma region CONSTURCTOR
Tree2::Tree2(){
	Model_Tree();
	SetColor(0, 0.36, 0.2, 0.09);
	SetColor(1, 0.13, 0.545, 0.13);
	SetColor(2, 0.13, 0.545, 0.13);
	SetColor(3, 0.13, 0.545, 0.13);
}
#pragma endregion

#pragma region MODEL
void Tree2::Model_Tree(){
	log.ScaleModel(0.04, 0.4, 0.04);

	topLeafs.Scale(0.13, 0.2, 0.13);
	middleLeafs.Scale(0.2, 0.2, 0.2);
	bottomLeafs.Scale(0.3, 0.3, 0.3);

	topLeafs.MoveCenterTo(0, 0, -2);
	middleLeafs.MoveCenterTo(0, 0, -2);
	bottomLeafs.MoveCenterTo(0, 0, -2);

	topLeafs.MoveByValue(Y_AXIS, 0.2);
	middleLeafs.MoveByValue(Y_AXIS, 0.1);
	bottomLeafs.MoveByValue(Y_AXIS, -0.04);
	log.MoveModelCenter(0, 0, -2);

}
#pragma endregion

#pragma region ACTIONS
void Tree2::RotateSelf(Axis axis, double rotate_value){
	CPoint logCenter = log.GetModelCenter();

	logCenter.ScalePoint(-1, -1, -1);

	topLeafs.MoveByValue(logCenter);
	middleLeafs.MoveByValue(logCenter);
	bottomLeafs.MoveByValue(logCenter);
	log.MoveModel(logCenter);

	logCenter.ScalePoint(-1, -1, -1);

	log.RotateModel(axis, rotate_value);
	topLeafs.RotateSelf(axis, rotate_value);
	middleLeafs.RotateSelf(axis, rotate_value);
	bottomLeafs.RotateSelf(axis, rotate_value);

	log.MoveModel(logCenter);
	topLeafs.MoveByValue(logCenter);
	middleLeafs.MoveByValue(logCenter);
	bottomLeafs.MoveByValue(logCenter);
}
void Tree2::MoveByValue(Axis axis, double move_value){
	log.MoveModel(axis, move_value);
	topLeafs.MoveByValue(axis, move_value);
	middleLeafs.MoveByValue(axis, move_value);
	bottomLeafs.MoveByValue(axis, move_value);
}
void Tree2::MoveByValue(double x, double y, double z){
	MoveByValue(X_AXIS, x);
	MoveByValue(Y_AXIS, y);
	MoveByValue(Z_AXIS, z);
}
void Tree2::MoveCenterTo(Axis axis, double center_value){
	log.MoveModelCenter(axis, center_value);
	topLeafs.MoveCenterTo(axis, center_value);
	middleLeafs.MoveCenterTo(axis, center_value);
	bottomLeafs.MoveCenterTo(axis, center_value);
}
void Tree2::MoveCenterTo(double x, double y, double z){
	MoveCenterTo(X_AXIS, x);
	MoveCenterTo(Y_AXIS, y);
	MoveCenterTo(Z_AXIS, z);
}
void Tree2::SetColor(int index, double red, double green, double blue){
	switch (index){
	case 0:
		for (int i = 0; i < 4; i++)
			log.SetOnePolygonColor(i, red - (0.02 * i), green - (0.02 * i), blue - (0.02 * i));
		break;
	case 1:
		for (int i = 0; i < 5; i++)
			bottomLeafs.SetColor(i, red - (0.02 * i), green - (0.02 * i), blue - (0.02 * i));
		break;
	case 2:
		for (int i = 0; i < 5; i++)
			middleLeafs.SetColor(i, red - (0.02 * i), green - (0.02 * i), blue - (0.02 * i));
		break;
	case 3:
		for (int i = 0; i < 5; i++)
			topLeafs.SetColor(i, red - (0.02 * i), green - (0.02 * i), blue - (0.02 * i));
		break;
	default:
		log.SetModelColor(0.36, 0.2, 0.09);
		bottomLeafs.SetColor(0.13, 0.545, 0.13);
		middleLeafs.SetColor(0.13, 0.545, 0.13);
		topLeafs.SetColor(0.13, 0.545, 0.13);
	}
}
void Tree2::Draw(){
	log.DrawModel();
	topLeafs.Draw();
	middleLeafs.Draw();
	bottomLeafs.Draw();
}
#pragma endregion