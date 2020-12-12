//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.cpp
// implementation of MyGame, an implementation of exGameInterface
//
//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/Game.h"

#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h"

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* gWindowName = "Sample EngineX Game";

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::MyGame()
	: mEngine( nullptr )
{

	fontID = 0;
	gameObjects = new std::vector<GameObject*>();
	GameManager::CreateInstance();

	GameManager* gameManager = GameManager::GetInstance();

	//With this, the Game now will be notified whenever the GameManager creates a GameObject
	gameManager->AddListener(this);
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::~MyGame()
{
	//Removing all the used memory
	Physics::DestroyInstance();
	GameManager::DestroyInstance();

	for (unsigned int i = 0; i < gameObjects->size(); i++)
	{
		GameObject* gameObject = gameObjects->at(i);
		DestroyBasedOnType(gameObject);
	}

	gameObjects->clear();
	delete gameObjects;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Initialize( exEngineInterface* pEngine )
{
	mEngine = pEngine;
	//Default font
	fontID = mEngine->LoadFont("afternight.ttf", 32);

	Ground* ground = new Ground();
	Player* player = new Player();

	player->AddListener(this);

	Physics::CreateInstance();
	GameManager* gameManager = GameManager::GetInstance();

	gameManager->Initialize();

	gameObjects->push_back(ground);
	gameObjects->push_back(player);
	gameObjects->push_back(gameManager);
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* MyGame::GetWindowName() const
{
	return gWindowName;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::GetClearColor( exColor& color ) const
{
	color.mColor[0] = 0;
	color.mColor[1] = 0;
	color.mColor[2] = 0;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEvent( SDL_Event* pEvent )
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEventsConsumed()
{
	int nKeys = 0;
	const Uint8 *pState = SDL_GetKeyboardState( &nKeys );
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Run( float fDeltaT )
{
	std::vector<int> gameObjectsToRemove;

	for (unsigned int i = 0; i < gameObjects->size(); i++)
	{
		if (GameObject* gameObject = gameObjects->at(i))
		{

			//Updating an rendering all GOs
			//Sometimes, when removing the missiles from the gameobjects vector, the element...
			//... gets deleted from memory but not from the vector, so the program fails because...
			//... of a null reference, but this usually happens when too much missiles are spawned too fast

			gameObject->Update(fDeltaT);
			gameObject->Render(*mEngine);

			//Adding an element the list of removables
			if (gameObject->IsDestroyed()) {

				gameObjectsToRemove.push_back(i);
			}
		}
	}

	//Remmoving and deleting GOs
	int erasedElements = 0;
	for (unsigned int i = 0; i < gameObjectsToRemove.size(); i++)
	{
		int index = gameObjectsToRemove.at(i);

		GameObject* gameObject = gameObjects->at(index);

		gameObjects->erase(gameObjects->begin() + index - erasedElements);
		DestroyBasedOnType(gameObject);
		erasedElements++;
	}

	gameObjectsToRemove.clear();
}

void MyGame::DestroyBasedOnType(GameObject* gameObject) {

	GameObjectType type = gameObject->GetType();

	if (type == GameObjectType::Ground) {

		Ground* ground = static_cast<Ground*>(gameObject);
		delete ground;
	}
	else if (type == GameObjectType::City) {

		City* city = static_cast<City*>(gameObject);
		delete city;
	}
	else if (type == GameObjectType::Building) {

		Building* city = static_cast<Building*>(gameObject);
		delete city;
	}
	else if (type == GameObjectType::Missile) {

		Missile* city = static_cast<Missile*>(gameObject);
		delete city;
	}
	else if (type == GameObjectType::Cannon) {

		Cannon* city = static_cast<Cannon*>(gameObject);
		delete city;
	}
	else if (type == GameObjectType::Player) {

		Player* city = static_cast<Player*>(gameObject);
		delete city;
	}
	else if (type == GameObjectType::Enemy) {

		Enemy* city = static_cast<Enemy*>(gameObject);
		delete city;
	}
	else if (type == GameObjectType::UIText) {

		UIText* city = static_cast<UIText*>(gameObject);
		delete city;
	}
}

//Handling the notification of a recently created game object
void MyGame::OnNotify(EventData* data) {

	GO_CreationData* GOData = static_cast<GO_CreationData*>(data);

	GameObject* gameObject = GOData->GetCreatedGO();
	gameObjects->push_back(gameObject);

	//I hardcoded this because of time matters. I needed a reference of the...
	//...engine interface in order to be able to load a font inside the UIText
	if (gameObject->GetType() == GameObjectType::UIText) {

		UIText* text = static_cast<UIText*>(gameObject);
		text->SetFontID(fontID);
	}
}