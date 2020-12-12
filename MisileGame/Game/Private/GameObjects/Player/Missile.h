//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/GameObject.h"
#include "Game/Private/Shapes/Circle.h"
#include "Game/Private/Collision/CircleCollider.h"
#include "Game/Private/GameManagement/Physics.h"

class Missile : public GameObject
{
public:
	Missile(Vector2 startPos, Vector2 destination);
	~Missile();

	virtual void Update(float deltaTime) override;
	virtual void Render(exEngineInterface& engine) override;

	void Move(float deltaTime);
	void Explode();

	Collider* GetCollider() const;

private:
	Circle* circle;
	CircleCollider* collider;

	Vector2 startPos;
	Vector2 destination;
	Vector2 direction;

	Vector2 startScale;
	Vector2 explosionScale;

	float currentPosValue;
	float currentScaleValue;
	float speed;

	bool hasExploded;
	bool hasReachedMax;
	bool hasReachedMin;
};