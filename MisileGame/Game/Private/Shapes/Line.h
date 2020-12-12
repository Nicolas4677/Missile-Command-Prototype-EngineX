//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/Shapes/Shape.h"

//A component of a GameObject that handles the renderization of a line
class Line
{
public:
	Line();
	~Line();

	void Render(exEngineInterface& engine, Vector2 pointA, Vector2 pointB, exColor color);

	void SetLayer(int layer);

private:
	int layer;
};