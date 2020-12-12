//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

//All the types of the colliders. This allows me to check the type of the colliders...
//... to be able to apply the specific ecuation for the specific situation
enum class ColliderType : unsigned short {

	AABB,
	Circular,
	None
};