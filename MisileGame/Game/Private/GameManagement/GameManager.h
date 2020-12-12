//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/DesignPatterns/Singleton.h"
#include "Game/Private/GameObjects/GameObject.h"
#include "Game/Private/DesignPatterns/Observer/Notifier.h"
#include "Game/Private/DesignPatterns/Observer/Events/GO_CreationData.h"
#include "Game/Private/GameObjects/Environment/City.h"
#include "Game/Private/GameObjects/Enemy/Enemy.h"
#include "Game/Private/GameObjects/UI/UIText.h"

#include <vector>
#include <stdlib.h>
#include <time.h>
#include <string>


class GameManager : public Singleton<GameManager>, public GameObject, public Notifier
{
	friend class Singleton<GameManager>;

public:

	virtual void Update(float deltaTime) override;
	virtual void Render(exEngineInterface& engine) override;

	void Initialize();
	void CreateCity(Vector2 position, exColor color);
	void CreateEnemy();
	void CreateText(std::string content, Vector2 position);

private:
	GameManager();
	~GameManager();

	City* GetRandomCity() const;

	std::vector<City*>* cities;

	float timer;
	float timeBetweenSpawns;

	bool textHasBeenDisplayed;
};

GameManager* Singleton<GameManager>::instance = nullptr;