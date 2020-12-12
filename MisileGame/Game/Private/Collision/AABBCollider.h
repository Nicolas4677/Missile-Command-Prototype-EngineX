//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/Collision/Collider.h"

class AABBCollider : public Collider {

public:
	//The transform of the game object that holds the collider
	AABBCollider(GameObject* transform, ColliderType type);
	~AABBCollider();

	//Returns data of the collision int data
	virtual bool CalculateCollision(CollisionData& other) override;

};