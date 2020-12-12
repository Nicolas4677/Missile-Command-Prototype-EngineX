//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/UI/UIText.h"

UIText::UIText(int _fontID) :
	fontID(_fontID){

	myType = GameObjectType::UIText;
	text = "Text";

	myColor.mColor[0] = 128;
	myColor.mColor[1] = 128;
	myColor.mColor[2] = 128;
	myColor.mColor[3] = 255;
}

UIText::~UIText() {

}

void UIText::SetContent(std::string content) {

	text = content;
}

void UIText::SetFontID(int id) {

	fontID = id;
}

void UIText::SetColor(exColor color) {

	myColor = color;
}

void UIText::Update(float deltaTime) {

}


void UIText::Render(exEngineInterface& engine) {

	exVector2 pos = transform->GetPosition().ConvertToEngineType();

	engine.DrawText(fontID, pos, text.c_str(), myColor, -2);
}