//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Player/Player.h"

Player::Player() {

	transform->SetPosition(Vector2(Screen::GetWidth() * 0.5f, 550));
	myType = GameObjectType::Player;
}

Player::~Player() {

}

void Player::Update(float deltaTime) {

	int x = 0;
	int y = 0;

	if (Input::ClickStarted() & Input::GetMousePos(&x, &y)) {

		//Shooting too fast can cause a problem on the vector, which will not be able to...
		//... delete all the missiles in time
		Missile* missile = ShootTowards(Vector2(x, y));

		GO_CreationData* data = new GO_CreationData(missile);

		Notify(data);
	}
}