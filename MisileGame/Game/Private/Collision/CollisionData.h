//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/GameObject.h"

class CollisionData
{
public:
	CollisionData();
	~CollisionData();

	void SetOther(GameObject* collider);
	GameObject& GetOther() const;

private:
	GameObject* other;
};