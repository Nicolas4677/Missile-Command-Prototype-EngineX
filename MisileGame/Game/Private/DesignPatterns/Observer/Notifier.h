//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/DesignPatterns/Observer/Observer.h"
#include "Game/Private/DesignPatterns/Observer/EventData.h"

#include <vector>

//Classes that inherits from this class are able to notify observers "subscribed"...
//... to an event
class Notifier
{
public:

	void AddListener(Observer* observer);
	void RemoveListener(Observer* observer);

protected:
	Notifier();
	virtual ~Notifier();

	void Notify(EventData* data) const;

	std::vector<Observer*>* observers;
};