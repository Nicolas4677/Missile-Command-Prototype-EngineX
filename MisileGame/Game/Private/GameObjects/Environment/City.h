//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/GameObject.h"
#include "Game/Private/Shapes/Rectangle.h"
#include "Game/Private/GameObjects/Environment/Building.h"

#include <vector>

class City : public GameObject
{
public:
	City();
	~City();

	virtual void Update(float deltaTime) override;
	virtual void Render(exEngineInterface& engine) override;

	void SetPosition(Vector2 position);
	void SetBuildingsColor(exColor color);

private:
	Building* building1;
	Building* building2;
	Building* building3;

	bool exploted;
};