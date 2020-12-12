//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/Collision/AABBCollider.h"

AABBCollider::AABBCollider(GameObject* _gameObject, ColliderType _type) :
	Collider(_gameObject, _type) {}

AABBCollider::~AABBCollider() {

}

bool AABBCollider::CalculateCollision(CollisionData& data) {

	bool isColliding = false;
	for (unsigned int i = 0; i < collidables->size(); i++)
	{
		if (collidables->at(i) == nullptr) continue;
		Collider* currentCollider = collidables->at(i);

		//avoiding to check collision with itself
		if (currentCollider == this) continue;

		//Applying different collision ecuation depending on the types of the colliders
		switch (currentCollider->GetType())
		{
		case ColliderType::AABB:
			isColliding = CollisionCalculator::RectangleToRectangle(gameObject->GetTransform(), 
																	currentCollider->GetGO()->GetTransform());
			break;

		case ColliderType::Circular:
			isColliding = CollisionCalculator::CircleToRectangle(currentCollider->GetGO()->GetTransform(), 
																gameObject->GetTransform());
			break;

		default:
			isColliding = false;
			break;
		}

		if (isColliding) {

			data.SetOther(currentCollider->GetGO());
			break;
		}
	}

	return isColliding;
}