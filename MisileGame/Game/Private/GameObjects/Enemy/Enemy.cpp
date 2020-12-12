//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Enemy/Enemy.h"

Enemy::Enemy(City* _city, Vector2 _startPos) : 
	target(_city),
	startPos(_startPos) {

	targetPos = _city->GetTransform().GetPosition();

	line = new Line();

	speed = 0.5f;
	posValue = 0;

	collider = new CircleCollider(this, ColliderType::Circular);
	Physics* physics  = Physics::GetInstance();

	myColor.mColor[0] = 255;
	myColor.mColor[1] = 255;
	myColor.mColor[2] = 255;
	myColor.mColor[3] = 255;

	physics->AddCollidable(collider);
	myType = GameObjectType::Enemy;
}

Enemy::~Enemy() {

	delete line;
}

void Enemy::Update(float deltaTime) {

	//The enemy moves with a lerp, the renderized line ies between the starting point and....
	//... the current position of the enemy
	if (posValue < 1) {

		posValue += deltaTime * speed;

		Move();

		CollisionData data;

		if (collider->CalculateCollision(data)) {

			GameObject& other = data.GetOther();

			if (other.GetType() == GameObjectType::Missile) {

				isDestroyed = true;
			}
			else if (other.GetType() == GameObjectType::City) {

				other.SetDestroyedState(true);
				isDestroyed = true;
			}
		}
	}
	else {

		target->SetDestroyedState(true);
		isDestroyed = true;
	}

	if (isDestroyed) {

		Physics* physics = Physics::GetInstance();
		physics->RemoveCollidable(collider);
	}
}

void Enemy::Render(exEngineInterface& engine) {

	line->Render(engine, startPos, transform->GetPosition(), myColor);
}

void Enemy::Move() {

	Vector2 currentPos;
	Vector2::Lerp(currentPos, startPos, targetPos, posValue);

	transform->SetPosition(currentPos);
}