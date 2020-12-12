//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.h
// definition of MyGame, an implementation of exGameInterface
//

#include "Game/Public/GameInterface.h"
#include "Engine/Public/EngineTypes.h"

#include "Game/Private/DesignPatterns/Observer/Observer.h"
#include "Game/Private/DesignPatterns/Observer/Events/GO_CreationData.h"

#include "Game/Private/GameObjects/GameObject.h"
#include "Game/Private/GameObjects/GameObjectType.h"
#include "Game/Private/GameObjects/Environment/Ground.h"
#include "Game/Private/GameObjects/Player/Player.h"
#include "Game/Private/GameObjects/UI/UIText.h"

#include "Game/Private/GameManagement/GameManager.h"
#include "Game/Private/GameManagement/Physics.h"

#include <vector>

//-----------------------------------------------------------------
//-----------------------------------------------------------------

class MyGame : public exGameInterface, public Observer
{
public:

								MyGame();
	virtual						~MyGame();

	virtual void				Initialize( exEngineInterface* pEngine );

	virtual const char*			GetWindowName() const;
	virtual void				GetClearColor( exColor& color ) const;

	virtual void				OnEvent( SDL_Event* pEvent );
	virtual void				OnEventsConsumed();

	virtual void				Run( float fDeltaT );

	virtual void OnNotify(EventData* data) override;
	
private:

	void						DestroyBasedOnType(GameObject* gameObject);

	exEngineInterface*			mEngine;

	int							fontID;

	std::vector<GameObject*>*	gameObjects;
};
