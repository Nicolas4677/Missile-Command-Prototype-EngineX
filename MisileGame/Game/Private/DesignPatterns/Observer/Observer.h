//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/DesignPatterns/Observer/EventData.h"

//Classes that inherits from this one can get notified of specific events
class Observer
{
public:
	virtual void OnNotify(EventData* data) = 0;

protected:
	Observer() {

	}

	virtual ~Observer() {

	}
};