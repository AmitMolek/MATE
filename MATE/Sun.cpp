#include "Sun.h"

#pragma region CONSTRUCTOR
Sun::Sun(){
	Model_Sun();
}
#pragma endregion

#pragma region MODEL
void Sun::Model_Sun(){
	sun.ScaleModel(0.5, 0.5, 0.5);
	SetColor(1, 1, 0);
}
#pragma endregion

#pragma region ACTIONS
CPoint Sun::GetCenter(){
	return sun.GetModelCenter();
}
void Sun::RotateSelf(Axis axis, double rotate_value){
	CPoint sunCenter = sun.GetModelCenter();

	sunCenter.ScalePoint(-1, -1, -1);

	sun.MoveModel(sunCenter);

	sunCenter.ScalePoint(-1, -1, -1);

	sun.RotateModel(axis, rotate_value);

	sun.MoveModel(sunCenter);
}
void Sun::Rotate(Axis axis, double rotate_value){
	sun.RotateModel(axis, rotate_value);
}
void Sun::Rotate(double x, double y, double z){
	Rotate(X_AXIS, x);
	Rotate(Y_AXIS, y);
	Rotate(Z_AXIS, z);
}
void Sun::MoveByValue(Axis axis, double move_value){
	sun.MoveModel(axis, move_value);
}
void Sun::MoveByValue(double x, double y, double z){
	sun.MoveModel(x, y, z);
}
void Sun::MoveCenterTo(Axis axis, double center_value){
	sun.MoveModelCenter(axis, center_value);
}
void Sun::MoveCenterTo(double x, double y, double z){
	sun.MoveModelCenter(x, y, z);
}
void Sun::SetColor(double red, double green, double blue){
	sun.SetModelColor(red, green, blue);
	for (int i = 1; i < 5; i++)
		sun.SetOnePolygonColor(i, red - (0.1 * i), green - (0.1 * i), blue - (0.1 * i));
}
void Sun::Draw(){
	sun.DrawModel();
}
#pragma endregion