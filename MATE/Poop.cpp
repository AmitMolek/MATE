#include "Poop.h"

#pragma region CONSTRUCTOR
	Poop::Poop(){
		rotationX = rotationY = rotationZ = 0;
		scaleX = scaleY = scaleZ = 1;
		isPoop = false;
		Model_Scale();
		Scale(0.08, 0.08, 0.08);
		Model();
	}
#pragma endregion

#pragma region MODEL
	void Poop::Model_Scale(){
		lowerCube.ScaleModel(0.3, 0.08, 0.3);
		middleCube.ScaleModel(0.2, 0.07, 0.2);
		higherCube.ScaleModel(0.1, 0.06, 0.1);
	}
	void Poop::Model_lowerPoop(){
		SetColor(0, 0.2, 0.098, 0);
	}
	void Poop::Model_middlePoop(){
		SetColor(1, 0.2, 0.098, 0);
		middleCube.MoveModel(Y_AXIS, 0.07 * scaleY);
	}
	void Poop::Model_higherPoop(){
		SetColor(2, 0.2, 0.098, 0);
		higherCube.MoveModel(Y_AXIS, 0.13 * scaleY);
	}
	void Poop::Model(){
		Model_lowerPoop();
		Model_middlePoop();
		Model_higherPoop();
	}
#pragma endregion

#pragma region ACTIONS
	void Poop::RotateSelf(Axis axis, double rotate_value){
		CPoint bodyCenter = lowerCube.GetModelCenter();

		bodyCenter.ScalePoint(-1, -1, -1);

		lowerCube.MoveModel(bodyCenter);
		middleCube.MoveModel(bodyCenter);
		higherCube.MoveModel(bodyCenter);

		bodyCenter.ScalePoint(-1, -1, -1);

		lowerCube.RotateModel(axis, rotate_value);
		middleCube.RotateModel(axis, rotate_value);
		higherCube.RotateModel(axis, rotate_value);

		lowerCube.MoveModel(bodyCenter);
		middleCube.MoveModel(bodyCenter);
		higherCube.MoveModel(bodyCenter);

		if (axis == X_AXIS) rotationX += rotate_value;
		if (axis == Y_AXIS) rotationY += rotate_value;
		if (axis == Z_AXIS) rotationZ += rotate_value;
	}
	void Poop::RotateSelf(double x, double y, double z){
		RotateSelf(X_AXIS, x);
		RotateSelf(Y_AXIS, y);
		RotateSelf(Z_AXIS, z);
	}
	void Poop::ResetRotation(Axis axis){
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
	void Poop::Scale(Axis axis, double scale_value){
		CPoint bodyCenter = lowerCube.GetModelCenter();

		bodyCenter.ScalePoint(-1, -1, -1);

		lowerCube.MoveModel(bodyCenter);
		middleCube.MoveModel(bodyCenter);
		higherCube.MoveModel(bodyCenter);

		bodyCenter.ScalePoint(-1, -1, -1);

		lowerCube.ScaleModel(axis, scale_value);
		middleCube.ScaleModel(axis, scale_value);
		higherCube.ScaleModel(axis, scale_value);

		lowerCube.MoveModel(bodyCenter);
		middleCube.MoveModel(bodyCenter);
		higherCube.MoveModel(bodyCenter);

		if (axis == X_AXIS) scaleX *= scale_value;
		if (axis == Y_AXIS) scaleY *= scale_value;
		if (axis == Z_AXIS) scaleZ *= scale_value;
	}
	void Poop::Scale(double x, double y, double z){
		Scale(X_AXIS, x);
		Scale(Y_AXIS, y);
		Scale(Z_AXIS, z);
	}
	void Poop::MoveByValue(Axis axis, double move_value){
		lowerCube.MoveModel(axis, move_value);
		middleCube.MoveModel(axis, move_value);
		higherCube.MoveModel(axis, move_value);
	}
	void Poop::MoveCenterTo(Axis axis, double center_value){
		lowerCube.MoveModelCenter(axis, center_value);
		middleCube.MoveModelCenter(axis, center_value);
		higherCube.MoveModelCenter(axis, center_value);
		Model();
	}
	void Poop::MoveCenterTo(double x, double y, double z){
		lowerCube.MoveModelCenter(x, y, z);
		middleCube.MoveModelCenter(x, y, z);
		higherCube.MoveModelCenter(x, y, z);
		Model();
	}
	void Poop::MoveCenter(double x, double y, double z){
		double rotX = rotationX, rotY = rotationY, rotZ = rotationZ;
		ResetRotation(X_AXIS);
		ResetRotation(Y_AXIS);
		ResetRotation(Z_AXIS);
		MoveCenterTo(x, y, z);
		RotateSelf(rotX, rotY, rotZ);
	}
	void Poop::MoveLayer(Axis axis, double move_value, int layer_index){
		switch (layer_index){
		case 0:
			lowerCube.MoveModel(axis, move_value);
			break;
		case 1:
			middleCube.MoveModel(axis, move_value);
			break;
		case 2:
			higherCube.MoveModel(axis, move_value);
			break;
		}
	}
	void Poop::SetColor(int index, double red, double green, double blue){
		switch (index){
		case 0:
			for (int i = 0; i < 6; i++)
				lowerCube.SetOnePolygonColor(i, red - (0.02 * i), green - (0.02 * i), blue - (0.02 * i));
			break;
		case 1:
			for (int i = 0; i < 6; i++)
				middleCube.SetOnePolygonColor(i, red - (0.02 * i), green - (0.02 * i), blue - (0.02 * i));
			break;
		case 2:
			for (int i = 0; i < 6; i++)
				higherCube.SetOnePolygonColor(i, red - (0.02 * i), green - (0.02 * i), blue - (0.02 * i));
			break;
		default:
			lowerCube.SetModelColor(0.2, 0.098, 0);
			middleCube.SetModelColor(0.2, 0.098, 0);
			higherCube.SetModelColor(0.2, 0.098, 0);
		}
	}
	void Poop::Bigger(int penguin_age){
		CPoint body_center = lowerCube.GetModelCenter();
		if (penguin_age < 4) Scale(1.03, 1.03, 1.03);
		switch (penguin_age){
		case 10:
			Scale(1.1, 1.1, 1.1);
			break;
		case 20:
			Scale(1.1, 1.1, 1.1);
			break;
		case 30:
			Scale(1.2, 1.2, 1.2);
			break;
		case 40:
			Scale(1.25, 1.25, 1.25);
			break;
		}
		MoveCenterTo(body_center.GetCoordinate(X_AXIS), body_center.GetCoordinate(Y_AXIS), body_center.GetCoordinate(Z_AXIS));
	}
	void Poop::Pooping(){
		isPoop = true;
	}
	void Poop::Clean(){
		isPoop = false;
	}
	bool Poop::isPooped(){
		return isPoop;
	}
	void Poop::Draw(){
		lowerCube.DrawModel();
		middleCube.DrawModel();
		higherCube.DrawModel();
	}
#pragma endregion