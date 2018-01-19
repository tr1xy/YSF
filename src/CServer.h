#ifndef YSF_CSERVER_H
#define YSF_CSERVER_H

#include "CSingleton.h"
#include "CPool.h"
#include "CPlayerData.h"

class CServer : public CSingleton<CServer>
{
public:
	CNetGame &NetGame;
	CBoundedPool<CPlayerPool, CPlayer*, MAX_PLAYERS, &CPlayerPool::pPlayer, &CPlayerPool::bIsPlayerConnected, &CPlayerPool::dwPlayerPoolSize, CPlayerData> PlayerPool;
	CBoundedPool<CVehiclePool, CVehicle*, MAX_VEHICLES, &CVehiclePool::pVehicle, &CVehiclePool::bVehicleSlotState, &CVehiclePool::dwVehiclePoolSize> VehiclePool;
	CBoundedPool<CActorPool, CActor*, MAX_ACTORS, &CActorPool::pActor, &CActorPool::bValidActor, &CActorPool::dwActorPoolSize> ActorPool;
	CSlotPool<CObjectPool, CObject*, MAX_OBJECTS, &CObjectPool::pObjects, &CObjectPool::bObjectSlotState> ObjectPool;
	CSlotPool<CPickupPool, tPickup, MAX_PICKUPS, &CPickupPool::Pickup, &CPickupPool::bActive> PickupPool;
	CSlotPool<CMenuPool, CMenu*, MAX_MENUS, &CMenuPool::pMenu, &CMenuPool::bIsCreated> MenuPool;
	CSlotPool<C3DTextPool, C3DText, MAX_3DTEXT_GLOBAL, &C3DTextPool::TextLabels, &C3DTextPool::bIsCreated> Text3DPool;
	CSlotPool<CTextDrawPool, CTextdraw*, MAX_TEXT_DRAWS, &CTextDrawPool::TextDraw, &CTextDrawPool::bSlotState> TextDrawPool;
	CSlotPool<CSAMPGangZonePool, float[4], MAX_GANG_ZONES, &CSAMPGangZonePool::fGangZone, &CSAMPGangZonePool::bSlotState> GangZonePool;

	CServer(CNetGame &netGame);
};

#endif
