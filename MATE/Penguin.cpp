#include "Penguin.h"
#include "iostream"
#include "cmath" 

#pragma region CONSTRUCTOR
Penguin::Penguin(void){
	head.SetModelColor(0, 0, 0);
	body.SetModelColor(0.85, 0.85, 0.85);
	beak.SetModelColor(1, 0.501, 0);
	for (int i = 0; i < 2; i++){
		hands[i].SetModelColor(0, 0, 0);
		legs[i].SetModelColor(1, 0.501, 0);
		eyes[i].SetModelColor(1, 1, 1);
		pupils[i].SetModelColor(0, 0, 0);
	}
	posX = posY = posZ = 0;
	age = 0;
	sleep = health = 100;
	clean = fun = hunger = 10;
	sick = false;
	name = "Penguin";
	rotationX = rotationY = rotationZ = 0;
	scaleX = scaleY = scaleZ = 1;
	Model_Scale();
	Model();
}
#pragma endregion

#pragma region MODEL
void Penguin::Model_Scale(){
	head.ScaleModel(0.1, 0.075, 0.08);
	body.ScaleModel(0.1, 0.15, 0.08);
	beak.ScaleModel(0.07, 0.025, 0.025);
	for (int i = 0; i < 2; i++){
		hands[i].ScaleModel(0.03, 0.11, 0.05);
		legs[i].ScaleModel(0.04, 0.011, 0.1);
		eyes[i].ScaleModel(0.028, 0.028, 0.002);
		pupils[i].ScaleModel(0.01, 0.01, 0.002);
	}
}
void Penguin::Model_Head(){
	head.MoveModel(Y_AXIS, 0.112 * scaleY);
}
void Penguin::Model_Body(){

}
void Penguin::Model_Hands(){
	// 0 - right hand | 1 - left hand

	for (int i = 0; i < 2; i++){
		hands[i].MoveModel(Y_AXIS, 0.02 * scaleY);
	}
	hands[0].MoveModel(X_AXIS, 0.05 * scaleX);
	hands[1].MoveModel(X_AXIS, -0.05 * scaleX);
}
void Penguin::Model_Legs(){
	// 0 - right leg | 1 - left leg

	for (int i = 0; i < 2; i++){
		legs[i].MoveModel(0, -0.08 * scaleY, 0.01 * scaleZ);
	}
	legs[0].MoveModel(X_AXIS, 0.03 * scaleX);
	legs[1].MoveModel(X_AXIS, -0.03 * scaleX);
}
void Penguin::Model_Eyes(){
	// 0 - right eye | 1 - left eye

	for (int i = 0; i < 2; i++){
		eyes[i].MoveModel(0, 0.12 * scaleY, 0.04 * scaleZ);
	}
	eyes[0].MoveModel(X_AXIS, 0.02 * scaleX);
	eyes[1].MoveModel(X_AXIS, -0.02 * scaleX);
}
void Penguin::Model_Pupils(){
	// 0 - right pupil | 1 - left pupil

	for (int i = 0; i < 2; i++){
		pupils[i].MoveModel(0, 0.12 * scaleY, 0.041 * scaleZ);
	}
	pupils[0].MoveModel(X_AXIS, 0.02 * scaleX);
	pupils[1].MoveModel(X_AXIS, -0.02 * scaleX);
}
void Penguin::Model_Beak(){
	beak.MoveModel(Y_AXIS, 0.112 * scaleY);
	beak.MoveModel(0, -0.03 * scaleY, 0.05 * scaleZ);
}
void Penguin::Model(){
	Model_Body();
	Model_Head();
	Model_Beak();
	Model_Hands();
	Model_Legs();
	Model_Eyes();
	Model_Pupils();
}
#pragma endregion

#pragma region ACTIONS
void Penguin::RotateSelf(Axis axis, double rotate_value){
	CPoint bodyCenter = body.GetModelCenter();

	bodyCenter.ScalePoint(-1, -1, -1);

	body.MoveModel(bodyCenter);
	head.MoveModel(bodyCenter);
	beak.MoveModel(bodyCenter);
	for (int i = 0; i < 2; i++){
		hands[i].MoveModel(bodyCenter);
		legs[i].MoveModel(bodyCenter);
		eyes[i].MoveModel(bodyCenter);
		pupils[i].MoveModel(bodyCenter);
	}

	bodyCenter.ScalePoint(-1, -1, -1);

	body.RotateModel(axis, rotate_value);
	head.RotateModel(axis, rotate_value);
	beak.RotateModel(axis, rotate_value);
	for (int i = 0; i < 2; i++){
		hands[i].RotateModel(axis, rotate_value);
		legs[i].RotateModel(axis, rotate_value);
		eyes[i].RotateModel(axis, rotate_value);
		pupils[i].RotateModel(axis, rotate_value);
	}

	body.MoveModel(bodyCenter);
	head.MoveModel(bodyCenter);
	beak.MoveModel(bodyCenter);
	for (int i = 0; i < 2; i++){
		hands[i].MoveModel(bodyCenter);
		legs[i].MoveModel(bodyCenter);
		eyes[i].MoveModel(bodyCenter);
		pupils[i].MoveModel(bodyCenter);
	}
	if (axis == X_AXIS) rotationX += rotate_value;
	if (axis == Y_AXIS) rotationY += rotate_value;
	if (axis == Z_AXIS) rotationZ += rotate_value;
}
void Penguin::RotateSelf(double x, double y, double z){
	RotateSelf(X_AXIS, x);
	RotateSelf(Y_AXIS, y);
	RotateSelf(Z_AXIS, z);
}
void Penguin::Scale(Axis axis, double scale_value){
	CPoint bodyCenter = body.GetModelCenter();

	bodyCenter.ScalePoint(-1, -1, -1);

	body.MoveModel(bodyCenter);
	head.MoveModel(bodyCenter);
	beak.MoveModel(bodyCenter);
	for (int i = 0; i < 2; i++){
		hands[i].MoveModel(bodyCenter);
		legs[i].MoveModel(bodyCenter);
		eyes[i].MoveModel(bodyCenter);
		pupils[i].MoveModel(bodyCenter);
	}

	bodyCenter.ScalePoint(-1, -1, -1);

	body.ScaleModel(axis, scale_value);
	head.ScaleModel(axis, scale_value);
	beak.ScaleModel(axis, scale_value);
	for (int i = 0; i < 2; i++){
		hands[i].ScaleModel(axis, scale_value);
		legs[i].ScaleModel(axis, scale_value);
		eyes[i].ScaleModel(axis, scale_value);
		pupils[i].ScaleModel(axis, scale_value);
	}

	body.MoveModel(bodyCenter);
	head.MoveModel(bodyCenter);
	beak.MoveModel(bodyCenter);
	for (int i = 0; i < 2; i++){
		hands[i].MoveModel(bodyCenter);
		legs[i].MoveModel(bodyCenter);
		eyes[i].MoveModel(bodyCenter);
		pupils[i].MoveModel(bodyCenter);
	}
	if (axis == X_AXIS) scaleX *= scale_value;
	if (axis == Y_AXIS) scaleY *= scale_value;
	if (axis == Z_AXIS) scaleZ *= scale_value;
}
void Penguin::Scale(double x, double y, double z){
	Scale(X_AXIS, x);
	Scale(Y_AXIS, y);
	Scale(Z_AXIS, z);
}
void Penguin::ScaleAndMoveToCenter(double x, double y, double z, double xScale, double yScale, double zScale){
	Scale(xScale, yScale, zScale);
	MoveCenter(x, y, z);
}
void Penguin::MoveByValue(Axis axis, double move_value){
	body.MoveModel(axis, move_value);
	head.MoveModel(axis, move_value);
	beak.MoveModel(axis, move_value);

	for (int i = 0; i < 2; i++){
		hands[i].MoveModel(axis, move_value);
		legs[i].MoveModel(axis, move_value);
		eyes[i].MoveModel(axis, move_value);
		pupils[i].MoveModel(axis, move_value);
	}
	if (axis == X_AXIS) posX += move_value;
	if (axis == Y_AXIS) posY += move_value;
	if (axis == Z_AXIS) posZ += move_value;
}
void Penguin::MoveByValue(double x, double y, double z){
	MoveByValue(X_AXIS, x);
	MoveByValue(Y_AXIS, y);
	MoveByValue(Z_AXIS, z);
}
void Penguin::MoveByValue(CPoint point){
	body.MoveModel(point);
	head.MoveModel(point);
	beak.MoveModel(point);

	for (int i = 0; i < 2; i++){
		hands[i].MoveModel(point);
		legs[i].MoveModel(point);
		eyes[i].MoveModel(point);
		pupils[i].MoveModel(point);
	}
}
void Penguin::MoveCenterTo(Axis axis, double center_value){
	body.MoveModelCenter(axis, center_value);
	head.MoveModelCenter(axis, center_value);
	beak.MoveModelCenter(axis, center_value);
	for (int i = 0; i < 2; i++){
		hands[i].MoveModelCenter(axis, center_value);
		legs[i].MoveModelCenter(axis, center_value);
		eyes[i].MoveModelCenter(axis, center_value);
		pupils[i].MoveModelCenter(axis, center_value);
	}
	Model();
	if (axis == X_AXIS) posX = center_value;
	if (axis == Y_AXIS) posY = center_value;
	if (axis == Z_AXIS) posZ = center_value;
}
void Penguin::MoveCenterTo(CPoint center_point){
	MoveCenterTo(center_point.GetCoordinate(X_AXIS), 
				 center_point.GetCoordinate(Y_AXIS),
				 center_point.GetCoordinate(Z_AXIS));
}
void Penguin::MoveCenterTo(double x, double y, double z){
	body.MoveModelCenter(x, y, z);
	head.MoveModelCenter(x, y, z);
	beak.MoveModelCenter(x, y, z);
	for (int i = 0; i < 2; i++){
		hands[i].MoveModelCenter(x, y, z);
		legs[i].MoveModelCenter(x, y, z);
		eyes[i].MoveModelCenter(x, y, z);
		pupils[i].MoveModelCenter(x, y, z);
	}
	Model();
	posX = x;
	posY = y;
	posZ = z;
}
CPoint Penguin::GetCenter(){
	return body.GetModelCenter();
}
double Penguin::GetCenter(Axis axis){
	return body.GetModelCenter().GetCoordinate(axis);
}
double Penguin::GetRotation(Axis axis){
	if (axis == X_AXIS) return rotationX;
	if (axis == Y_AXIS) return rotationY;
	if (axis == Z_AXIS) return rotationZ;
}
double Penguin::GetScale(Axis axis){
	if (axis == X_AXIS) return scaleX;
	if (axis == Y_AXIS) return scaleY;
	if (axis == Z_AXIS) return scaleZ;
}
void Penguin::ResetRotation(Axis axis){
	switch(axis){
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
void Penguin::MoveCenter(double x, double y, double z){
	double rotX = rotationX, rotY = rotationY, rotZ = rotationZ;
	ResetRotation(X_AXIS);
	ResetRotation(Y_AXIS);
	ResetRotation(Z_AXIS);
	MoveCenterTo(x, y, z);
	RotateSelf(rotX, rotY, rotZ);
}
double Penguin::GetPos(Axis axis){
	if (axis == X_AXIS) return posX;
	if (axis == Y_AXIS) return posY;
	if (axis == Z_AXIS) return posZ;
}
void Penguin::SetPos(){
	MoveCenter(posX, posY, posZ);
}
void Penguin::Draw(){
	body.DrawModel();
	head.DrawModel();
	beak.DrawModel();
	for (int i = 0; i < 2; i++){
		hands[i].DrawModel();
		legs[i].DrawModel();
		eyes[i].DrawModel();
		pupils[i].DrawModel();
	}
}
#pragma endregion

#pragma region ACTIONS-MODEL
void Penguin::Blink_Open(){
	for (int i = 0; i < 2; i++)
		eyes[i].SetModelColor(1, 1, 1);
}
void Penguin::Blink_Close(){
	for (int i = 0; i < 2; i++)
		eyes[i].SetModelColor(0, 0, 0);
}
void Penguin::Grow(){
	CPoint body_center = body.GetModelCenter();
	Scale(1.1, 1.1, 1.1);
	MoveCenter(body_center.GetCoordinate(X_AXIS), body_center.GetCoordinate(Y_AXIS), body_center.GetCoordinate(Z_AXIS));
}
void Penguin::GrowAge(){
	if (age < 4) Grow();
	switch (age){
	case 10:
		Grow();
		break;
	case 20:
		Grow();
		break;
	case 30:
		Grow();
		break;
	case 40:
		Grow(); // Change this to make the penguin old
		break;
	}
}
#pragma endregion

#pragma region STATS
void Penguin::SetName(char* Name){
	name = Name;
}
char* Penguin::GetName(){
	return name;
}
#pragma endregion