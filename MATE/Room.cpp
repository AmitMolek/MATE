#include "Room.h"

Room::Room(){
	Walls();
	for (int i = 0; i < 4; i++){
		walls[0].MoveModelCenter(0, 0, -2);
	}
	walls[0].MoveModel(1, 0.2, -1);
}

void Room::Walls(){
	for (int i = 0; i < 3;i++){
		walls[i].ScaleModel(0.1, 2, 2);
		walls[i].SetModelColor(1, 1, 1);
	}
}

void Room::Draw(){
	for (int i = 0; i < 3; i++)
		walls[i].DrawModel();
}

void Room::RotateSelf(Axis axis, double rotate_value){
	walls[0].RotateSelfModel(axis, rotate_value);
}