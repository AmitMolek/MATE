#include "FenceWall.h"

FenceWall::FenceWall(){
	Model_FenceWall();
}

void FenceWall::Model_FenceWall(){
	
}

void FenceWall::Draw(){
	for (int i = 0; i < 4; i++)
		fence[i].DrawModel();
}