//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/GameObject.h"

GameObject::GameObject() {

	transform = new Transform();

	isDestroyed = false;
}

GameObject::~GameObject() {

	delete transform;
}

void GameObject::SetColor(exColor color) {

	myColor = color;
}

Transform& GameObject::GetTransform() const {

	return *transform;
}

GameObjectType GameObject::GetType() const {

	return myType;
}

void GameObject::SetDestroyedState(bool state) {

	isDestroyed = state;
}

bool GameObject::IsDestroyed() const {

	return isDestroyed;
}