//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Environment/Building.h"

Building::Building() {

	rectangle = new Rectangle();
	rectangle->SetLayer(-1);
	myType = GameObjectType::Building;
}

Building::~Building() {

}

void Building::Update(float deltaTime) {

}

void Building::Render(exEngineInterface& engine) {

	rectangle->Render(engine, *transform, myColor);
}