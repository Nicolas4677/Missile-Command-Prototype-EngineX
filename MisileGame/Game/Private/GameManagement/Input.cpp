//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameManagement/Input.h"

Input::Input() {

}

Input::~Input() {

}

float Input::GetPlayer1Vertical() {

	int nKeys = 0;
	const Uint8 *pState = SDL_GetKeyboardState(&nKeys);



	if (pState[SDL_SCANCODE_W]) {

		return -1;
	}
	else if (pState[SDL_SCANCODE_S]) {

		return 1;
	}
	else {

		return 0;
	}
}

Uint32 Input::GetMousePos(int* x, int* y) {

	Uint32 mouseState = SDL_GetMouseState(x, y);
	return mouseState;
}

Uint32 Input::ClickStarted() {

	return SDL_MOUSEBUTTONDOWN;
}