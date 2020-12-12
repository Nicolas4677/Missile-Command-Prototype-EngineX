//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/DesignPatterns/Singleton.h"
#include "Game/Private/Collision/Collider.h"
#include <vector>

//Gives a global access to colliders in order to be able to calculate collision between them...
//... and the rest of colliders on the level
class Physics : public Singleton<Physics>
{
	friend class Singleton<Physics>;

public:

	void AddCollidable(Collider* collider);
	void RemoveCollidable(Collider* collider);

private:
	Physics();
	~Physics();

	std::vector<Collider*>* collidables;
};

Physics* Singleton<Physics>::instance = nullptr;