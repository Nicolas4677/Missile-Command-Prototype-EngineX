//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Player/Missile.h"

Missile::Missile(Vector2 _startPos, Vector2 _destination) :
	destination(_destination),
	startPos(_startPos) {

	currentPosValue = 0;
	hasExploded = false;
	hasReachedMax = false;
	hasReachedMin = false;
	speed = 450;

	transform->SetPosition(_startPos);


	startScale = Vector2(5, 5);
	explosionScale = Vector2(50, 50);

	transform->SetScale(startScale);

	myColor.mColor[0] = 170;
	myColor.mColor[1] = 90;
	myColor.mColor[2] = 200;
	myColor.mColor[3] = 255;

	circle = new Circle();
	collider = new CircleCollider(this, ColliderType::Circular);

	Physics* physics = Physics::GetInstance();
	physics->AddCollidable(collider);

	Vector2::SubstractVectors(direction, _startPos, _destination);
	direction.Normalize();

	myType = GameObjectType::Missile;
}

Missile::~Missile() {

}

void Missile::Update(float deltaTime) {

	Vector2 dir;
	Vector2::SubstractVectors(dir, transform->GetPosition(), destination);
	float distance = dir.GetMagnitude();

	//10 is just a threshold
	if (distance > 10) {

		Move(deltaTime);
	}
	else {
		
		//Executing the explosion, I do this by using a lerp
		if (currentScaleValue < 1 && !hasReachedMax) {

			currentScaleValue += deltaTime;

			hasReachedMax = currentScaleValue >= 1;
		}
		else if (currentScaleValue > 0 && hasReachedMax) {

			currentScaleValue -= deltaTime;

			hasReachedMin = currentScaleValue <= 0;
		}

		if (hasReachedMin) {
			
			Physics* physics = Physics::GetInstance();
			physics->RemoveCollidable(collider);
			isDestroyed = true;
		}
		Explode();
	}
}

void Missile::Render(exEngineInterface& engine) {

	circle->Render(engine, *transform, myColor);
}

void Missile::Move(float deltaTime) {

	Vector2 target;
	Vector2::MultiplyScalar(target, direction, speed * deltaTime);

	Vector2 pos;
	Vector2::AddVectors(pos, transform->GetPosition(), target);

	transform->SetPosition(pos);
}

void Missile::Explode() {

	Vector2 currentScale;
	Vector2::Lerp(currentScale, startScale, explosionScale, currentScaleValue);

	transform->SetScale(currentScale);
}

Collider* Missile::GetCollider() const {

	return collider;
}