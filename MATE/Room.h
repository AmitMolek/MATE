#include "CCube.h"

class Room{
public:
	Room();

private:
	CCube walls[3];

	void Walls();

public:
	void Draw();
	void RoomMoveCenter();
	void RotateSelf(Axis axis, double rotate_value);
};