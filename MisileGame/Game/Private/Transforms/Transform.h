//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Vector2.h"

//Includes the transforms of a GO.
//This is a primary component of a GO
class Transform
{
public:
	Transform();
	~Transform();

	Vector2 GetPosition() const;
	void SetPosition(Vector2 position);

	Vector2 GetScale() const;
	void SetScale(Vector2 vector2);


private:
	Vector2* position;
	Vector2* scale;
};