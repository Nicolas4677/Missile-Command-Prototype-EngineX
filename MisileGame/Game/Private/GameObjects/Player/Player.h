//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/Player/Cannon.h"
#include "Game/Private/GameManagement/Input.h"
#include "Game/Private/DesignPatterns/Observer/Notifier.h"
#include "Game/Private/DesignPatterns/Observer/Events/GO_CreationData.h"

//Since the player instantiates new Missiles, there must be a way to tell the...
//...engine that those GOs must be renderized and updated, so here I use the...
//...observer pattern to do that.
class Player : public Cannon, public Notifier
{
public:
	Player();
	~Player();

	virtual void Update(float deltaTime) override;
};