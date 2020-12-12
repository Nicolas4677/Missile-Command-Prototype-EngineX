//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/GameObject.h"
#include "Game/Private/Shapes/Rectangle.h"
#include "Game/Private/GameObjects/Player/Missile.h"

class Cannon : public GameObject
{
public:
	Cannon();
	~Cannon();

	virtual void Update(float deltaTime) override;
	virtual void Render(exEngineInterface& engine) override;

protected:
	Missile* ShootTowards(Vector2 position);

	Rectangle* rectangle;

};