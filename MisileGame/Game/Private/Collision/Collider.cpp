#include "Game/Private/Collision/Collider.h"

Collider::Collider(GameObject* gameObject, ColliderType type) {

	this->gameObject = gameObject;

	myType = type;
}

Collider::~Collider() {

}

GameObject* Collider::GetGO() const {

	return gameObject;
}

ColliderType Collider::GetType() const {

	return myType;
}

void Collider::SetCollidables(std::vector<Collider*>* _collidables) {

	collidables = _collidables;
}