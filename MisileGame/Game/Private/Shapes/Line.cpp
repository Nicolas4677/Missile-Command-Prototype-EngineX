//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/Shapes/Line.h"

Line::Line() {

}

Line::~Line() {

}

//Drawing a line between two position
void Line::Render(exEngineInterface& engine, Vector2 pointA, Vector2 pointB, exColor color) {

	exVector2 point1 = pointA.ConvertToEngineType();
	exVector2 point2 = pointB.ConvertToEngineType();
	 
	engine.DrawLine(point1, point2, color, layer);
}

void Line::SetLayer(int layer) {

	this->layer = layer;
}