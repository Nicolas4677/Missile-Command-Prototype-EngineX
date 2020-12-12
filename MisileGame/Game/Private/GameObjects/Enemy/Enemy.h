//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/GameObject.h"
#include "Game/Private/GameObjects/Environment/City.h"
#include "Game/Private/Shapes/Line.h"
#include "Game/Private/Collision/CircleCollider.h"
#include "Game/Private/GameManagement/Physics.h""

class Enemy : public GameObject
{
public:
	Enemy (City* city, Vector2 startPos);
	~Enemy ();

	virtual void Update(float deltaTime) override;
	virtual void Render(exEngineInterface& engine) override;

	void Move();

private:
	Vector2 startPos;

	Vector2 targetPos;
	City* target;

	Line* line;

	float speed;
	float posValue;

	CircleCollider* collider;
};