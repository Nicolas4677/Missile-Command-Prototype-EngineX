//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/GameObject.h"
#include "Game/Private/Collision/ColliderType.h"
#include "Game/Private/Collision/CollisionCalculator.h"
#include "Game/Private/Collision/CollisionData.h"

#include <vector>

//A collider class which allows inheritance to its childs.
//This allows me to use the other colliders functionality in a polymorphic way
class Collider {

public:

	virtual bool CalculateCollision(CollisionData& data) = 0;

	GameObject* GetGO() const;

	ColliderType GetType() const;

	void SetCollidables(std::vector<Collider*>* _collidables);


protected:
	Collider(GameObject* transform, ColliderType type);
	virtual ~Collider();

	ColliderType myType;

	Vector2 normal;

	GameObject* gameObject;
	std::vector<Collider*>* collidables;
};