//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Engine/Public/EngineInterface.h"
#include "Game/Private/Transforms/Transform.h"
#include "Game/Private/GameObjects/GameObjectType.h"
#include "Game/Private/GameManagement/Screen.h"

class GameObject
{
public:

	virtual void Update(float deltaTime) = 0;
	virtual void Render(exEngineInterface& engine) = 0;

	void SetColor(exColor color);

	Transform& GetTransform() const;
	GameObjectType GetType() const;

	void SetDestroyedState(bool state);
	bool IsDestroyed() const;

protected:
	GameObject();

	virtual ~GameObject();

	Transform* transform;

	GameObjectType myType;
	exColor myColor;
	bool isDestroyed;	//Defines if the gameobject is going to be destroyed at the end of the frame
};