#include "Game/Private/GameManagement/Physics.h"

Physics::Physics() {

	collidables = new std::vector<Collider*>();
}

Physics::~Physics() {

	collidables->clear();
	delete collidables;
}

void Physics::AddCollidable(Collider* collider) {

	collidables->push_back(collider);
	collider->SetCollidables(collidables);
}

void Physics::RemoveCollidable(Collider* collider) {

	for (unsigned int i = 0; i < collidables->size(); i++)
	{
		if (collidables->at(i) == collider) {

			collidables->erase(collidables->begin() + i);
		}
	}
}