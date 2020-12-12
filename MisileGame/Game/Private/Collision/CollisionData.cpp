//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/Collision/CollisionData.h"

CollisionData::CollisionData() {

}

CollisionData::~CollisionData() {

}

void CollisionData::SetOther(GameObject* gameObject) {

	other = gameObject;
}

GameObject& CollisionData::GetOther() const {

	return *other;
}