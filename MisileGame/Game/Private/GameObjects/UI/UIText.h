//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/GameObject.h"
#include <string>

//A base class to be able to render text just by instantiating this object
class UIText : public GameObject
{
public:
	UIText(int fontID);
	~UIText();

	virtual void Update(float deltaTime) override;
	virtual void Render(exEngineInterface& engine) override;

	void SetContent(std::string content);
	void SetFontID(int id);
	void SetColor(exColor color);

private:
	std::string text;
	int fontID;
	exColor myColor;
};