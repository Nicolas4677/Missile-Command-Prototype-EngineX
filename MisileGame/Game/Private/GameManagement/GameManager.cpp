//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameManagement/GameManager.h"

GameManager::GameManager() {

	cities = new std::vector<City*>();
	timer = 0;
	timeBetweenSpawns = 3;
	textHasBeenDisplayed = false;

	srand(time(NULL));
}

GameManager::~GameManager() {

}

void GameManager::Update(float deltaTime) {

	//Generating enemies with a delay in between
	if (timer >= timeBetweenSpawns) {

		if (cities->size() > 0) {

			CreateEnemy();
		}
		else {

			//Text displayed when the player loses
			if (!textHasBeenDisplayed) {

				CreateText("You Lose!", Vector2(400, 200));

				textHasBeenDisplayed = true;
			}
		}
		timer = 0;
	}
	else {

		timer += deltaTime;
	}

	std::vector<int> indexesToDelete;

	for (unsigned int i = 0; i < cities->size(); i++)
	{
		if (cities->at(i)->IsDestroyed()) {

			indexesToDelete.push_back(i);
		}
	}

	int erasedElements = 0;
	for (unsigned int i = 0; i < indexesToDelete.size(); i++)
	{
		int index = indexesToDelete.at(i);

		City* gameObject = cities->at(index);

		cities->erase(cities->begin() + index - erasedElements);
		erasedElements++;
	}
}

void GameManager::Render(exEngineInterface& engine) {

}

void GameManager::Initialize() {

	//setting up level
	exColor color;
	color.mColor[0] = 90;
	color.mColor[1] = 150;
	color.mColor[2] = 200;
	color.mColor[3] = 255;

	CreateCity(Vector2(100, 530), color);
	CreateCity(Vector2(200, 530), color);
	CreateCity(Vector2(300, 530), color);
	CreateCity(Vector2(500, 530), color);
	CreateCity(Vector2(600, 530), color);
	CreateCity(Vector2(700, 530), color);
}

void GameManager::CreateCity(Vector2 position, exColor color) {

	City* city = new City();
	city->SetPosition(position);
	city->SetBuildingsColor(color);

	cities->push_back(city);

	GO_CreationData* data = new GO_CreationData(city);

	Notify(data);

	delete data;
}

void GameManager::CreateEnemy() {

	City* city = GetRandomCity();

	float x = rand() % (int)Screen::GetWidth();

	Enemy* enemy = new Enemy(city, Vector2(x, 0));

	GO_CreationData* data = new GO_CreationData(enemy);

	Notify(data);

	delete data;
}

void GameManager::CreateText(std::string content, Vector2 position) {

	UIText* text = new UIText(0);
	text->SetContent(content);
	text->GetTransform().SetPosition(position);

	GO_CreationData* data = new GO_CreationData(text);

	Notify(data);

	delete data;

}

City* GameManager::GetRandomCity() const {

	return cities->at(rand() % cities->size());
}