//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/DesignPatterns/Observer/EventData.h"
#include "Game/Private/GameObjects/GameObject.h"

//This class inherits from EventData in order to be able to be sent through the notification
class GO_CreationData : public EventData
{
public:
	GO_CreationData(GameObject* gameObject);
	~GO_CreationData();

	GameObject* GetCreatedGO() const;

private:
	GameObject* createdGameObject;
};