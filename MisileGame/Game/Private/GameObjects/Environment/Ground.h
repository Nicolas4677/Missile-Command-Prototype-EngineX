//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/GameObject.h"
#include "Game/Private/Shapes/Rectangle.h"

//The ground of the level
class Ground : public GameObject
{
public:
	Ground();
	~Ground();

	virtual void Update(float deltaTime) override;
	virtual void Render(exEngineInterface& engine) override;

private:

	Rectangle* rectangle;
};