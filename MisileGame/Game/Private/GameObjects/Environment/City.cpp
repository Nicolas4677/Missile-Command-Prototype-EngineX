//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Environment/City.h"

City::City() {

	Vector2 scale(20, 10);
	transform->SetScale(scale);

	float buildingWidth = scale.GetX() / 3.0f;
	
	//Setting up the buildings
	building1 = new Building();
	building1->GetTransform().SetScale(Vector2(buildingWidth, scale.GetY()));

	building2 = new Building();
	building2->GetTransform().SetScale(Vector2(buildingWidth, scale.GetY()));

	building3 = new Building();
	building3->GetTransform().SetScale(Vector2(buildingWidth, scale.GetY()));

	exploted = false;
	myType = GameObjectType::City;
}

City::~City() {

	delete building1;
	delete building2;
	delete building3;
}

void City::Update(float deltaTime) {

	building1->Update(deltaTime);
	building2->Update(deltaTime);
	building3->Update(deltaTime);
}

void City::Render(exEngineInterface& engine) {

	building1->Render(engine);
	building2->Render(engine);
	building3->Render(engine);
}

void City::SetPosition(Vector2 position) {

	//Since the position of the buildings must be relative to the city, I...
	//Have to calculate their position based on the position of the city
	transform->SetPosition(position);

	float halfWidth = transform->GetScale().GetX();

	Vector2 pos(position.GetX() - halfWidth, position.GetY());
	building1->GetTransform().SetPosition(pos);

	pos = Vector2(position.GetX(), position.GetY());
	building2->GetTransform().SetPosition(pos);

	pos = Vector2(position.GetX() + halfWidth, position.GetY());
	building3->GetTransform().SetPosition(pos);
}

void City::SetBuildingsColor(exColor color) {

	building1->SetColor(color);
	building2->SetColor(color);
	building3->SetColor(color);
}