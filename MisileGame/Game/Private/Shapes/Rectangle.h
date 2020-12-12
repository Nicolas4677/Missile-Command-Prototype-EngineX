//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/Shapes/Shape.h"

//Includes the logic for rendering a rectangle/square
class Rectangle : public Shape {

public:
	Rectangle();
	~Rectangle();

	virtual void Render(exEngineInterface& engine, Transform transform, exColor color) override;
};