//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Environment/Ground.h"

Ground::Ground() {

	rectangle = new Rectangle();

	Vector2 position(Screen::GetWidth() * 0.5f, Screen::GetHeight() - 30);
	transform->SetPosition(position);

	Vector2 scale(400, 30);
	transform->SetScale(scale);

	myColor.mColor[0] = 200;
	myColor.mColor[1] = 170;
	myColor.mColor[2] = 90;
	myColor.mColor[3] = 255;

	myType = GameObjectType::Ground;
}

Ground::~Ground() {

	delete rectangle;
}

void Ground::Update(float deltaTime) {

}

void Ground::Render(exEngineInterface& engine) {

	rectangle->Render(engine, *transform, myColor);
}