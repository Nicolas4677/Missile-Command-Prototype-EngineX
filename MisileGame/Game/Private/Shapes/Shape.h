//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once
#include "Engine/Public/EngineInterface.h"
#include "Game/Private/Transforms/Transform.h"
#include "Engine/Public/EngineTypes.h"

//Base class that handles polymorphic calls.
//Shapes are renderable and acts as a component of a GO
class Shape {

public:
	virtual void Render(exEngineInterface& engine, Transform transform, exColor color) = 0;

	void SetLayer(int layer) {

		this->layer = layer;
	}

protected:
	Shape() {

		layer = 0;
	}

	virtual ~Shape() {

	}

	int layer;
};