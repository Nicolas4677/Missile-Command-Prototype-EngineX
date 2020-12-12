//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Transform.h"

Transform::Transform() {

	position = new Vector2(0.0f, 0.0f);
	scale = new Vector2(0.0f, 0.0f);
}

Transform::~Transform() {

}

Vector2 Transform::GetPosition() const {

	return *position;
}

void Transform::SetPosition(Vector2 position) {

	*this->position = position;
}

Vector2 Transform::GetScale() const {

	return *scale;
}

void Transform::SetScale(Vector2 scale) {

	*this->scale = scale;
}