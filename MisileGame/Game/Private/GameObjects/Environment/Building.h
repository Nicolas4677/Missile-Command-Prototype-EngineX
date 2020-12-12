//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/GameObject.h"
#include "Game/Private/Shapes/Rectangle.h"

class Building : public GameObject
{
public:
	Building();
	~Building();

	virtual void Update(float deltaTime) override;
	virtual void Render(exEngineInterface& engine) override;

private:
	Rectangle* rectangle;
};