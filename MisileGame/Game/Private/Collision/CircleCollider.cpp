//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/Collision/CircleCollider.h"

CircleCollider::CircleCollider(GameObject* gameObject, ColliderType _type) :
	Collider(gameObject, _type) {}

CircleCollider::~CircleCollider() {

}

//Same functionality than the AABB but this one applies other ecuations en diferent situations
bool CircleCollider::CalculateCollision(CollisionData& data) {

	bool isColliding = false;
	for (unsigned int i = 0; i < collidables->size(); i++)
	{
		if (collidables->at(i) == nullptr) continue;
		Collider* currentCollider = collidables->at(i);
		Transform& currentTransform = currentCollider->GetGO()->GetTransform();

		if (currentCollider == this) continue;


		switch (currentCollider->GetType())
		{
		case ColliderType::AABB:
			isColliding = CollisionCalculator::CircleToRectangle(gameObject->GetTransform(), currentTransform);
			break;

		case ColliderType::Circular:
			isColliding = CollisionCalculator::CircleToCircle(gameObject->GetTransform(), currentTransform);

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