#include "Toy_Rabbid.h"

#pragma region CONSTRUCTOR
Toy_Rabbid::Toy_Rabbid(){
	rotationX = rotationY = rotationZ = 0;
	scaleX = scaleY = scaleZ = 1;
	isPlayed = false;
	Model_Scale();
	Model();
	SetColor(0, 1, 1, 1);
}
#pragma endregion

#pragma region MODEL
void Toy_Rabbid::Model_Scale(){
	body.ScaleModel(0.05, 0.07, 0.04);
	head.ScaleModel(0.045, 0.043, 0.036);
	stomach.ScaleModel(0.040, 0.043, 0.01);
	for (int i = 0; i < 2; i++){
		hands[i].ScaleModel(0.02, 0.025, 0.02);
		legs[i].ScaleModel(0.017, 0.025, 0.02);
		ears[i].ScaleModel(0.017, 0.04, 0.007);
		eyes[i].ScaleModel(0.015, 0.015, 0.007);
		pupils[i].ScaleModel(0.0075, 0.0075, 0.0003);
	}
}
void Toy_Rabbid::Model_Body(){
	
}
void Toy_Rabbid::Model_Stomach(){
	stomach.MoveModel(Z_AXIS, 0.02 * scaleZ);
	stomach.MoveModel(Y_AXIS, -0.005 * scaleY);
}
void Toy_Rabbid::Model_Hands(){
	for (int i = 0; i < 2; i++){
		hands[i].MoveModel(Y_AXIS, 0.019 * scaleY);
	}
	hands[0].RotateSelfModel(Z_AXIS, 45);
	hands[1].RotateSelfModel(Z_AXIS, -45);
	hands[0].MoveModel(X_AXIS, 0.03 * scaleX);
	hands[1].MoveModel(X_AXIS, -0.03 * scaleX);
}
void Toy_Rabbid::Model_Head(){
	head.MoveModel(Y_AXIS, 0.056 * scaleY);
}
void Toy_Rabbid::Model_Legs(){
	for (int i = 0; i < 2; i++){
		legs[i].MoveModel(Y_AXIS, -0.048 * scaleY);
	}
	legs[0].MoveModel(X_AXIS, 0.013 * scaleX);
	legs[1].MoveModel(X_AXIS, -0.013 * scaleX);
}
void Toy_Rabbid::Model_Ears(){
	for (int i = 0; i < 2; i++){
		ears[i].MoveModel(Y_AXIS, 0.085 * scaleY);
	}
	ears[0].RotateSelfModel(Z_AXIS, -10);
	ears[1].RotateSelfModel(Z_AXIS, 10);
	ears[0].MoveModel(X_AXIS, 0.013 * scaleX);
	ears[1].MoveModel(X_AXIS, -0.013 * scaleX);
}
void Toy_Rabbid::Model_Eyes(){
	for (int i = 0; i < 2; i++){
		eyes[i].MoveModel(Z_AXIS, 0.017 * scaleZ);
		eyes[i].MoveModel(Y_AXIS, 0.057 * scaleY);
	}
	eyes[0].MoveModel(X_AXIS, 0.012 * scaleX);
	eyes[1].MoveModel(X_AXIS, -0.012 * scaleX);
}
void Toy_Rabbid::Model_Pupils(){
	for (int i = 0; i < 2; i++){
		pupils[i].MoveModel(Z_AXIS, 0.021 * scaleZ);
		pupils[i].MoveModel(Y_AXIS, 0.057 * scaleY);
	}
	pupils[0].MoveModel(X_AXIS, 0.012 * scaleX);
	pupils[1].MoveModel(X_AXIS, -0.012 * scaleX);
}
void Toy_Rabbid::Model(){
	Model_Body();
	Model_Head();
	Model_Hands();
	Model_Stomach();
	Model_Legs();
	Model_Ears();
	Model_Eyes();
	Model_Pupils();
}
#pragma endregion

#pragma region ACTIONS
void Toy_Rabbid::RotateSelf(Axis axis, double rotate_value){
	CPoint bodyCenter = body.GetModelCenter();

	bodyCenter.ScalePoint(-1, -1, -1);

	body.MoveModel(bodyCenter);
	head.MoveModel(bodyCenter);
	stomach.MoveModel(bodyCenter);
	for (int i = 0; i < 2; i++){
		hands[i].MoveModel(bodyCenter);
		legs[i].MoveModel(bodyCenter);
		eyes[i].MoveModel(bodyCenter);
		pupils[i].MoveModel(bodyCenter);
		ears[i].MoveModel(bodyCenter);
	}

	bodyCenter.ScalePoint(-1, -1, -1);

	body.RotateModel(axis, rotate_value);
	head.RotateModel(axis, rotate_value);
	stomach.RotateModel(axis, rotate_value);
	for (int i = 0; i < 2; i++){
		hands[i].RotateModel(axis, rotate_value);
		legs[i].RotateModel(axis, rotate_value);
		eyes[i].RotateModel(axis, rotate_value);
		pupils[i].RotateModel(axis, rotate_value);
		ears[i].RotateModel(axis, rotate_value);
	}

	body.MoveModel(bodyCenter);
	head.MoveModel(bodyCenter);
	stomach.MoveModel(bodyCenter);
	for (int i = 0; i < 2; i++){
		hands[i].MoveModel(bodyCenter);
		legs[i].MoveModel(bodyCenter);
		eyes[i].MoveModel(bodyCenter);
		pupils[i].MoveModel(bodyCenter);
		ears[i].MoveModel(bodyCenter);
	}
	if (axis == X_AXIS) rotationX += rotate_value;
	if (axis == Y_AXIS) rotationY += rotate_value;
	if (axis == Z_AXIS) rotationZ += rotate_value;
}
void Toy_Rabbid::RotateSelf(double x, double y, double z){
	RotateSelf(X_AXIS, x);
	RotateSelf(Y_AXIS, y);
	RotateSelf(Z_AXIS, z);
}
void Toy_Rabbid::Scale(Axis axis, double scale_value){
	CPoint bodyCenter = body.GetModelCenter();

	bodyCenter.ScalePoint(-1, -1, -1);

	body.MoveModel(bodyCenter);
	head.MoveModel(bodyCenter);
	stomach.MoveModel(bodyCenter);
	for (int i = 0; i < 2; i++){
		hands[i].MoveModel(bodyCenter);
		legs[i].MoveModel(bodyCenter);
		eyes[i].MoveModel(bodyCenter);
		pupils[i].MoveModel(bodyCenter);
		ears[i].MoveModel(bodyCenter);
	}

	bodyCenter.ScalePoint(-1, -1, -1);

	body.ScaleModel(axis, scale_value);
	head.ScaleModel(axis, scale_value);
	stomach.ScaleModel(axis, scale_value);
	for (int i = 0; i < 2; i++){
		hands[i].ScaleModel(axis, scale_value);
		legs[i].ScaleModel(axis, scale_value);
		eyes[i].ScaleModel(axis, scale_value);
		pupils[i].ScaleModel(axis, scale_value);
		ears[i].ScaleModel(axis, scale_value);
	}

	body.MoveModel(bodyCenter);
	head.MoveModel(bodyCenter);
	stomach.MoveModel(bodyCenter);
	for (int i = 0; i < 2; i++){
		hands[i].MoveModel(bodyCenter);
		legs[i].MoveModel(bodyCenter);
		eyes[i].MoveModel(bodyCenter);
		pupils[i].MoveModel(bodyCenter);
		ears[i].MoveModel(bodyCenter);
	}
	if (axis == X_AXIS) scaleX *= scale_value;
	if (axis == Y_AXIS) scaleY *= scale_value;
	if (axis == Z_AXIS) scaleZ *= scale_value;
}
void Toy_Rabbid::Scale(double x, double y, double z){
	Scale(X_AXIS, x);
	Scale(Y_AXIS, y);
	Scale(Z_AXIS, z);
}
void Toy_Rabbid::MoveByValue(Axis axis, double move_value){
	body.MoveModel(axis, move_value);
	head.MoveModel(axis, move_value);
	stomach.MoveModel(axis, move_value);

	for (int i = 0; i < 2; i++){
		hands[i].MoveModel(axis, move_value);
		legs[i].MoveModel(axis, move_value);
		eyes[i].MoveModel(axis, move_value);
		pupils[i].MoveModel(axis, move_value);
		ears[i].MoveModel(axis, move_value);
	}
}
void Toy_Rabbid::MoveByValue(double x, double y, double z){
	MoveByValue(X_AXIS, x);
	MoveByValue(Y_AXIS, y);
	MoveByValue(Z_AXIS, z);
}
void Toy_Rabbid::MoveCenterTo(Axis axis, double center_value){
	body.MoveModelCenter(axis, center_value);
	head.MoveModelCenter(axis, center_value);
	stomach.MoveModelCenter(axis, center_value);
	for (int i = 0; i < 2; i++){
		hands[i].MoveModelCenter(axis, center_value);
		legs[i].MoveModelCenter(axis, center_value);
		eyes[i].MoveModelCenter(axis, center_value);
		pupils[i].MoveModelCenter(axis, center_value);
		ears[i].MoveModelCenter(axis, center_value);
	}
	Model();
}
void Toy_Rabbid::MoveCenterTo(double x, double y, double z){
	body.MoveModelCenter(x, y, z);
	head.MoveModelCenter(x, y, z);
	stomach.MoveModelCenter(x, y, z);
	for (int i = 0; i < 2; i++){
		hands[i].MoveModelCenter(x, y, z);
		legs[i].MoveModelCenter(x, y, z);
		eyes[i].MoveModelCenter(x, y, z);
		pupils[i].MoveModelCenter(x, y, z);
		ears[i].MoveModelCenter(x, y, z);
	}
	Model();
}
void Toy_Rabbid::MoveCenter(double x, double y, double z){
	double rotX = rotationX, rotY = rotationY, rotZ = rotationZ;
	ResetRotation(X_AXIS);
	ResetRotation(Y_AXIS);
	ResetRotation(Z_AXIS);
	MoveCenterTo(x, y, z);
	RotateSelf(rotX, rotY, rotZ);
}
CPoint Toy_Rabbid::GetCenter(){
	return body.GetModelCenter();
}
double Toy_Rabbid::GetCenter(Axis axis){
	return body.GetModelCenter().GetCoordinate(axis);
}
double Toy_Rabbid::GetRotation(Axis axis){
	if (axis == X_AXIS) return rotationX;
	if (axis == Y_AXIS) return rotationY;
	if (axis == Z_AXIS) return rotationZ;
}
double Toy_Rabbid::GetScale(Axis axis){
	if (axis == X_AXIS) return scaleX;
	if (axis == Y_AXIS) return scaleY;
	if (axis == Z_AXIS) return scaleZ;
}
void Toy_Rabbid::ResetRotation(Axis axis){
	switch (axis){
	case X_AXIS:
		RotateSelf(X_AXIS, -rotationX);
		break;
	case Y_AXIS:
		RotateSelf(Y_AXIS, -rotationY);
		break;
	case Z_AXIS:
		RotateSelf(Z_AXIS, -rotationZ);
		break;
	}
}
void Toy_Rabbid::SetColor(int index, double red, double green, double blue){
	switch (index){
	case 0:
		for (int i = 0; i < 6; i++){
			body.SetOnePolygonColor(i, 0.9 - (0.04 * i), 0.9 - (0.04 * i), 0.9 - (0.04 * i));
			head.SetOnePolygonColor(i, 1 - (0.04 * i), 1 - (0.04 * i), 1 - (0.04 * i));
			stomach.SetOnePolygonColor(i, 1 - (0.04 * i), 0.8 - (0.04 * i), 0.6 - (0.04 * i));
			for (int j = 0; j < 2; j++){
				hands[j].SetOnePolygonColor(i, 1 - (0.04 * i), 1 - (0.04 * i), 1 - (0.04 * i));
				legs[j].SetOnePolygonColor(i, 1 - (0.04 * i), 1 - (0.04 * i), 1 - (0.04 * i));
				ears[j].SetOnePolygonColor(i, 1 - (0.04 * i), 1 - (0.04 * i), 1 - (0.04 * i));
				eyes[j].SetOnePolygonColor(i, 1 - (0.04 * i), 1 - (0.04 * i), 1 - (0.04 * i));
				hands[j].SetOnePolygonColor(4, 1, 0.8, 0.6);
				legs[j].SetOnePolygonColor(4, 1, 0.8, 0.6);
				ears[j].SetOnePolygonColor(0, 1, 0.8, 0.6);
				eyes[j].SetOnePolygonColor(0, 0.95, 0.95, 0.95);
				pupils[j].SetModelColor(0, 0.8, 0.8);
			}
		}
		break;
	case 1:
		for (int i = 0; i < 6; i++){
			body.SetOnePolygonColor(i, red - (0.04 * i), green - (0.04 * i), blue - (0.04 * i));
			head.SetOnePolygonColor(i, red - (0.04 * i), green - (0.04 * i), blue - (0.04 * i));
			for (int j = 0; j < 2; j++){
				hands[j].SetOnePolygonColor(i, red - (0.04 * i), green - (0.04 * i), blue - (0.04 * i));
				legs[j].SetOnePolygonColor(i, red - (0.04 * i), green - (0.04 * i), blue - (0.04 * i));
				ears[j].SetOnePolygonColor(i, red - (0.04 * i), green - (0.04 * i), blue - (0.04 * i));
				hands[j].SetOnePolygonColor(4, 1, 0.8, 0.6);
				legs[j].SetOnePolygonColor(4, 1, 0.8, 0.6);
				ears[j].SetOnePolygonColor(0, 1, 0.8, 0.6);
				pupils[j].SetModelColor(red, green, blue);
			}
		}
		break;
	default:
		for (int i = 0; i < 6; i++){
			body.SetOnePolygonColor(i, 0.9 - (0.04 * i), 0.9 - (0.04 * i), 0.9 - (0.04 * i));
			head.SetOnePolygonColor(i, 1 - (0.04 * i), 1 - (0.04 * i), 1 - (0.04 * i));
			stomach.SetOnePolygonColor(i, 1 - (0.04 * i), 0.8 - (0.04 * i), 0.6 - (0.04 * i));
			for (int j = 0; j < 2; j++){
				hands[j].SetOnePolygonColor(i, 1 - (0.04 * i), 1 - (0.04 * i), 1 - (0.04 * i));
				legs[j].SetOnePolygonColor(i, 1 - (0.04 * i), 1 - (0.04 * i), 1 - (0.04 * i));
				ears[j].SetOnePolygonColor(i, 1 - (0.04 * i), 1 - (0.04 * i), 1 - (0.04 * i));
				eyes[j].SetOnePolygonColor(i, 1 - (0.04 * i), 1 - (0.04 * i), 1 - (0.04 * i));
				hands[j].SetOnePolygonColor(4, 1, 0.8, 0.6);
				legs[j].SetOnePolygonColor(4, 1, 0.8, 0.6);
				ears[j].SetOnePolygonColor(0, 1, 0.8, 0.6);
				eyes[j].SetOnePolygonColor(0, 0.95, 0.95, 0.95);
				pupils[j].SetModelColor(0, 0.8, 0.8);
			}
		}
	}
}
bool Toy_Rabbid::GetPlayed(){
	return isPlayed;
}
void Toy_Rabbid::SetPlayed(bool state){
	isPlayed = state;
}
void Toy_Rabbid::Draw(){
	body.DrawModel();
	head.DrawModel();
	stomach.DrawModel();
	for (int i = 0; i < 2; i++){
		hands[i].DrawModel();
		legs[i].DrawModel();
		eyes[i].DrawModel();
		pupils[i].DrawModel();
		ears[i].DrawModel();
	}
}
#pragma endregion