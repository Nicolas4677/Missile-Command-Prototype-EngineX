//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once
#include "Game/Private/Transforms/Transform.h"
#include "Game/Private/Math.h"
#include "Game/Private/Collision/CollisionData.h"

class CollisionCalculator
{
public:
	//All collision cases required for the game
	static bool PointToCircle(Vector2 point, Transform circleA);
	static bool PointToRectangle(Vector2 point, Transform rectangleA);
	static bool CircleToCircle(Transform circleA, Transform circleB);
	static bool CircleToRectangle(Transform circleA, Transform rectangleB);
	static bool RectangleToRectangle(Transform rectangleA, Transform rectangleB);

private:
	CollisionCalculator() {

	}
	~CollisionCalculator() {

	}

};