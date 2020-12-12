//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Engine/Public/SDL.h"
#include "Game/Private/Transforms/Vector2.h"

//Class that wrapps the input of the players.
class Input {

public:
	static float GetPlayer1Vertical();
	static Uint32 GetMousePos(int* x, int* y);
	static Uint32 ClickStarted();

private:
	Input();
	~Input();
};