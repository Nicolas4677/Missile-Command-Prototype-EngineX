//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Player/Cannon.h"

Cannon::Cannon() {

	transform->SetScale(Vector2(10, 20));

	myColor.mColor[0] = 255;
	myColor.mColor[1] = 255;
	myColor.mColor[2] = 255;
	myColor.mColor[3] = 255;

	rectangle = new Rectangle();
	myType = GameObjectType::Cannon;
}

Cannon::~Cannon() {

}

void Cannon::Update(float deltaTime) {

}

void Cannon::Render(exEngineInterface& engine) {

	rectangle->Render(engine, *transform, myColor);
}

Missile* Cannon::ShootTowards(Vector2 position) {

	Missile* missile = new Missile(transform->GetPosition(), position);

	return missile;
}