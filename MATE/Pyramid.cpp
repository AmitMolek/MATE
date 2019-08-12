#include "Pyramid.h"

#pragma region CONSTRUCTOR
Pyramid::Pyramid(){
	Model_Pyramid();
}
#pragma endregion

#pragma region MODEL
void Pyramid::Model_Pyramid(){
	pyramid.SetNumberOfPolygons(5);
	
	CPolygon polygon_in_pyramid(4);
	polygon_in_pyramid.SetOnePointCoordinates(0, 0, 1, 0);
	polygon_in_pyramid.SetOnePointCoordinates(1, 1, 1, 0);
	polygon_in_pyramid.SetOnePointCoordinates(2, 1, 1, 1);
	polygon_in_pyramid.SetOnePointCoordinates(3, 0, 1, 1);
	polygon_in_pyramid.SetPolygonColor(1, 0, 0);
	pyramid.SetOnePolygon(0, polygon_in_pyramid);

	polygon_in_pyramid.SetNumberOfPoints(3);
	polygon_in_pyramid.SetOnePointCoordinates(1, 0, 1, 0);
	polygon_in_pyramid.SetOnePointCoordinates(0, 1, 1, 0);
	polygon_in_pyramid.SetOnePointCoordinates(2, 0.5, 1.5, 0.5);
	polygon_in_pyramid.SetPolygonColor(1, 1, 0);
	pyramid.SetOnePolygon(1, polygon_in_pyramid);

	polygon_in_pyramid.SetOnePointCoordinates(1, 1, 1, 0);
	polygon_in_pyramid.SetOnePointCoordinates(0, 1, 1, 1);
	polygon_in_pyramid.SetOnePointCoordinates(2, 0.5, 1.5, 0.5);
	polygon_in_pyramid.SetPolygonColor(0, 1, 0);
	pyramid.SetOnePolygon(2, polygon_in_pyramid);

	polygon_in_pyramid.SetOnePointCoordinates(1, 1, 1, 1);
	polygon_in_pyramid.SetOnePointCoordinates(0, 0, 1, 1);
	polygon_in_pyramid.SetOnePointCoordinates(2, 0.5, 1.5, 0.5);
	polygon_in_pyramid.SetPolygonColor(0, 1, 1);
	pyramid.SetOnePolygon(3, polygon_in_pyramid);

	polygon_in_pyramid.SetOnePointCoordinates(1, 0, 1, 1);
	polygon_in_pyramid.SetOnePointCoordinates(0, 0, 1, 0);
	polygon_in_pyramid.SetOnePointCoordinates(2, 0.5, 1.5, 0.5);
	polygon_in_pyramid.SetPolygonColor(1, 1, 1);
	pyramid.SetOnePolygon(4, polygon_in_pyramid);
	pyramid.MoveModelCenter(0, 0, -2);
}
#pragma endregion

#pragma region ACTIONS
void Pyramid::MoveByValue(Axis axis, double move_value){
	pyramid.MoveModel(axis, move_value);
}
void Pyramid::MoveByValue(CPoint point){
	pyramid.MoveModel(point);
}
void Pyramid::MoveCenterTo(Axis axis, double center_value){
	pyramid.MoveModelCenter(axis, center_value);
}
void Pyramid::MoveCenterTo(double x, double y, double z){
	pyramid.MoveModelCenter(x, y, z);
}
void Pyramid::RotateSelf(Axis axis, double rotate_value){
	CPoint logCenter = pyramid.GetModelCenter();

	logCenter.ScalePoint(-1, -1, -1);

	pyramid.MoveModel(logCenter);

	logCenter.ScalePoint(-1, -1, -1);

	pyramid.RotateModel(axis, rotate_value);

	pyramid.MoveModel(logCenter);
}
void Pyramid::Scale(Axis axis, double scale_value){
	pyramid.ScaleModel(axis, scale_value);
}
void Pyramid::Scale(double scale_value_x, double scale_value_y, double scale_value_z){
	Scale(X_AXIS, scale_value_x);
	Scale(Y_AXIS, scale_value_y);
	Scale(Z_AXIS, scale_value_z);
}
void Pyramid::SetColor(double red, double green, double blue){
	pyramid.SetModelColor(red, green, blue);
}
void Pyramid::SetColor(int polygon_index, double red, double green, double blue){
	pyramid.SetOnePolygonColor(polygon_index, red, green, blue);
}
void Pyramid::Draw(){
	pyramid.DrawModel();
}
#pragma endregion