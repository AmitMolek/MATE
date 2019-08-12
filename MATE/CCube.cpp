#include "CCube.h"
#include "CSquare.h"

CCube::CCube(void)
{
	SetNumberOfPolygons(6);

	CSquare square_in_cube;
	
	// forward polygon
	square_in_cube.MovePolygonCenter(0.5, 0.5, 1);
	square_in_cube.SetPolygonColor(0, 0.3, 0.7);
	SetOnePolygon(0, square_in_cube);

	// right polygon
	square_in_cube.RotatePolygon(Y_AXIS, 90);
	square_in_cube.MovePolygonCenter(1, 0.5, 0.5);
	square_in_cube.SetPolygonColor(0.4, 0, 0.7);
	SetOnePolygon(1, square_in_cube);

	// back polygon
	square_in_cube.RotatePolygon(Y_AXIS, 90);
	square_in_cube.MovePolygonCenter(0.5, 0.5, 0);
	square_in_cube.SetPolygonColor(0.4, 0.8, 0);
	SetOnePolygon(2, square_in_cube);

	// left polygon
	square_in_cube.RotatePolygon(Y_AXIS, 90);
	square_in_cube.MovePolygonCenter(0, 0.5, 0.5);
	square_in_cube.SetPolygonColor(0, 0, 0);
	SetOnePolygon(3, square_in_cube);

	// down polygon
	square_in_cube.RotatePolygon(Z_AXIS, 90);
	square_in_cube.MovePolygonCenter(X_AXIS, 0.5);
	square_in_cube.SetPolygonColor(1, 0.5, 0.2);
	SetOnePolygon(4, square_in_cube);

	// up polygon
	square_in_cube.RotatePolygon(Z_AXIS, 180);
	square_in_cube.MovePolygon(1, 1, 0);
	square_in_cube.SetPolygonColor(1, 1, 1);
	SetOnePolygon(5, square_in_cube);
}

