//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/Collision/Collider.h"

class CircleCollider : public Collider
{
public:
	//The transform of the game object that holds the collider
	CircleCollider(GameObject* gameObject, ColliderType type);
	~CircleCollider();

	virtual bool CalculateCollision(CollisionData& data) override;
};