//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/DesignPatterns/Observer/Events/GO_CreationData.h"

GO_CreationData::GO_CreationData(GameObject* gameObject) : 
	createdGameObject(gameObject) {}


GO_CreationData::~GO_CreationData() {

}

GameObject* GO_CreationData::GetCreatedGO() const {

	return createdGameObject;
}