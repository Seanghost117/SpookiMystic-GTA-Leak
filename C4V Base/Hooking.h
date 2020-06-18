#pragma once

typedef BOOL(__cdecl* fpIsDLCPresent)(DWORD a1);
typedef __int64(__cdecl* fpGetPlayerAddress)(Player);
typedef Entity(__cdecl* fpAddressToEntity)(__int64);
typedef uint32_t*(*__cdecl fpFileRegister)(int*, const char*, bool, const char*, bool);
typedef BOOL(__cdecl* fpGetEventData)(__int64 a1, __int64 a2);
typedef BOOL(__cdecl* fpCreateAmbientDrop)(DWORD pickupHash, Vector3* pos, int unk0, int value, DWORD modelHash, bool unk1, bool unk2);
typedef char*	(__cdecl* fpGetPlayerName)(Player player);
typedef bool(__cdecl* fpGetPedLastWeaponImpactCoord)(Ped ped, v3* out);
typedef bool(__cdecl* fpAddOwnedExplosion)(Ped ped, Vector3* pos, int type, float dmgScale, bool isAudible, bool isInvis, float fCamShake);
typedef void(__cdecl* fpDrawRect)(float x, float y, float width, float height, int r, int g, int b, int a);
typedef Vehicle(__cdecl* fpCreateVehicle)(Hash model, Vector3* pos, float heading, BOOL networked, BOOL unk2);
typedef bool(__cdecl* fpSetVehicleOnGroundProperly)(Vehicle vehicle, int unk0);
typedef bool(__cdecl* fpSetVehicleMod)(Vehicle vehicle, int modType, int modIndex, bool customTires);
typedef void(__cdecl* fpGiveDelayedWeaponToPed)(Ped ped, DWORD hash, int ammoCount, BOOL equipNow);
typedef bool(__cdecl* fpRemoveAllPedWeapons)(Ped ped);
typedef Entity(__cdecl* fpPtrToHandle)(void* entity);
typedef void(__cdecl* fpDrawSprite)(const char* textureDict, const char* textureName, float screenX, float screenY, float width, float height, float heading, int red, int green, int blue, int alpha);
typedef void(__cdecl* fpSetVehicleModKit)(Vehicle vehicle, int modKit);
typedef BOOL(__cdecl* fpIsModelValid)(Hash model);
typedef bool(__cdecl* fpNetworkSetInSpectatorMode)(bool toggle, Ped ped);
typedef bool(__cdecl* fpGetCurrentPedWeapon)(Ped ped, Hash* weaponHash, BOOL p2);
typedef bool(__cdecl* fpRequestModel)(Hash model);
typedef bool(__cdecl* fpHasModelLoaded)(Hash model);
typedef __int64(__cdecl* fpGetChatPlayer)(__int64 a1, __int64 a2, __int64 a3);
typedef char*(__cdecl* fpSetExplosionEvent)(__int64 a1, __int64 a2);
//typedef void(__cdecl* fpSetEntityInvincible)(Entity entity, bool toggle);
typedef void(__cdecl* fpDrawLine)(Vector3* pos1, Vector3* pos2, int r, int g, int b, int a);
typedef bool(__cdecl* fpNetworkStartParticleFxNonLoopedAtCoord)(char* effectName, Vector3 *pos, Vector3 *rot, float scale, bool xAxis, bool yAxis, bool zAxis);
typedef bool(__cdecl* fpNetworkRequestControlOfEntity)(Entity entity);
typedef bool(__cdecl* fpNetworkHasControlOfEntity)(Entity entity);
typedef char*(__cdecl* fpSetSessionWeather)(bool visibleToEveryone, int weatherId, int arg3, int arg4);
typedef bool(__cdecl* fpIsVehicleSeatFree)(Vehicle vehicle, int seatId, bool unk0);
typedef int(__cdecl* fpClearPedTasksImmediately)(Ped ped);
typedef void(__cdecl* fpSetVehicleFixed)(Vehicle vehicle);
typedef void(__cdecl* fpSetSessionTime)(int a1, int a2);
typedef BOOL(__cdecl* fpStatSetInt)(DWORD hash, int value, BOOL save);
typedef BOOL(__cdecl* fpStatSetFloat)(DWORD hash, float value, BOOL save);
typedef BOOL(__cdecl* fpStatSetBool)(DWORD hash, BOOL value, BOOL save);
typedef void(__cdecl* fpSetVehicleNumberPlateText)(Vehicle vehicle, char* plateText);
typedef void(__cdecl* fpSetVehicleDeformationFixed)(Vehicle* pVehicle);
typedef bool(__cdecl* fpNetworkRequestControlOfNetworkId)(int netId);
typedef int(__cdecl* fpNetworkGetNetworkIdFromEntity)(Entity entity);
typedef void(__cdecl* fpSetNetworkIdCanMigrate)(int netId, bool toggle);
typedef BOOL(__cdecl* fpAiTaskPlayAnim)(Ped ped, char* dict, char* anim, float speed, float speedMult, int duration, int flg, float playRate, BOOL lockX, BOOL lockY, BOOL lockZ);
typedef bool(__cdecl* fpNetworkRequestControlOfEntity2)(__int64 entity);
typedef void(__cdecl* fpSetEntityHeading)(Entity entity, float heading);
typedef float(__cdecl* fpGetEntityHeading)(Entity entity);
typedef bool(__cdecl* fpApplyForceToEntity)(Entity entity, int forceType, Vector3* pos, Vector3* rot, int boneindex, bool isDirRel, bool ignoreUpVec, bool isForceRel, bool unk1, bool unk2);
typedef bool(__cdecl* fpGetEntityPlayerIsFreeAimingAt)(Player player, Entity* entity);
typedef BOOL(__cdecl* fpCreateObject)(Hash model, float x, float y, float z, bool offset, int unk0, int unk1, Object* out, bool isNetworked, bool unk2, bool dynamic);
typedef BOOL(__cdecl* fpSetModelAsNoLongerNeeded)(DWORD hash);
typedef BOOL(__cdecl* fpCreateAmbientPickup)(DWORD pickupHash, Vector3* pos, int unk0, int value, DWORD modelHash, bool unk1, bool unk2);
typedef Vector3*(__cdecl* fpGetGameplayCamRot)(Vector3* out, uint32_t unk1);
typedef Vector3*(__cdecl* fpGetGameplayCamCoord)(Vector3* out);

typedef void(__cdecl* fpSetEntityAsMissionEntity)(Entity entity, BOOL p1, BOOL p2);
typedef Vehicle(__cdecl* fpGetVehiclePedIsIn)(Ped ped, bool lastVehicle);
typedef __int64(__cdecl* fpGetChatData)(__int64 a1, __int64 a2, __int64 a3, const char* origText, BOOL a5);



class ViewPort
{
public:
	char _0x0000[0x24C];
	float fViewMatrix[0x10];
};//Size=0x028C

#pragma pack(push, 1)

struct Bytes24
{
	BYTE	byte[24];

	bool	empty();
};

struct threeBytes
{
	BYTE	byte[3];

	bool	empty();
};

struct twoBytes
{
	BYTE	byte[2];

	bool	empty();
};

struct screenReso
{
	uint32_t	w,
		h;
};

struct objectHash
{
	DWORD*	ptr;
	DWORD	hash;
};

struct clockTime
{
	int hour;
	int minute;
	int second;
};

// reclass.h
class CCameraInterface
{
public:
	char pad_0x0000[0x248]; //0x0000

}; //Size=0x0248

class CVehHandle
{
public:
	void* pCVehicle; //0x0000 
	__int32 iHandle;
	char _pad0[0x4];

}; //Size=0x0010

class CObjectInterface
{
public:
	char pad_0x0000[0x158]; //0x0000
	__int64 pCObjectList; //0x0158 
	__int32 iMaxObjects; //0x0160 
	char pad_0x0164[0x4]; //0x0164
	__int32 iCurObjects; //0x0168 
	char pad_0x016C[0x5C]; //0x016C

}; //Size=0x01C8

class CVehicleInterface
{
public:
	char pad_0x0000[0x180]; //0x0000
	CVehHandle* VehList; //0x0180 
	__int32 iMaxVehicles; //0x0188 
	char pad_0x018C[0x4]; //0x018C
	__int32 iCurVehicles; //0x0190 
	char pad_0x0194[0x74]; //0x0194
}; //Size=0x0208

class CPedInterface
{
public:
	char pad_0x0000[0x100]; //0x0000
	__int64 PedLIst; //0x0100 
	__int32 iMaxPeds; //0x0108 
	char pad_0x010C[0x4]; //0x010C
	__int32 iCurPeds; //0x0110 
	char pad_0x0114[0x34]; //0x0114


}; //Size=0x0148


class CPickupInterface
{
public:
	char pad_0x0000[0x100]; //0x0000
	__int64 pCPickupList; //0x0100 
	__int32 iMaxPickups; //0x0108 
	char pad_0x010C[0x4]; //0x010C
	__int32 iCurPickups; //0x0110 


}; //Size=0x0114

class CReplayInterface
{
public:
	void* N000006F5; //0x0000 
	CCameraInterface* pCCameraInterface; //0x0008 
	CVehicleInterface* pCVehicleInterface; //0x0010 
	CPedInterface* pCPedInterface; //0x0018 
	CPickupInterface* pCPickupInterface; //0x0020 
	CObjectInterface* pCObjectInterface; //0x0028 

}; //Size=0x0030

#pragma pack(pop)

class Hooking
{
private:
	static BOOL InitializeHooks();
	static void FindPatterns();
	static void FindPatternsLater();
	static void FailPatterns(const char* name);

public:
	static HMODULE hmodule;
	static fpFileRegister									m_fileregister;
	static std::vector<LPVOID>								m_hooks;
	static void*											m_onlineName;
	static uint64_t*										m_frameCount;
	static threeBytes*										m_infAmmo;
	static threeBytes*										m_noReload;
	static screenReso*										m_resolution;
	static fpDrawLine										draw_line;
	static fpIsDLCPresent									is_DLC_present;
	static fpGetPlayerAddress								GetPlayerAddress;
	static fpAddressToEntity								AddressToEntity;
	static MemoryPool**										m_entityPool;
	//static fpSetEntityAsMissionEntity						set_entity_as_mission_entity;
	static fpCreateAmbientDrop								create_ambient_pickup;
	static fpGetPlayerName									get_player_name;
	static fpDrawRect										draw_rect;
	static fpCreateVehicle									create_vehicle;
	static fpSetVehicleNumberPlateText						set_vehicle_number_plate_text;
	static fpGetEventData									get_event_data;
	static fpSetVehicleOnGroundProperly						set_vehicle_on_ground_properly;
	static fpNetworkStartParticleFxNonLoopedAtCoord			network_start_particle_fx_non_looped_at_coord;
	static fpSetVehicleMod									set_vehicle_mod;
	static fpStatSetInt										stat_set_int;
	static fpStatSetFloat									stat_set_float;
	static fpStatSetBool									stat_set_bool;
	static fpSetEntityHeading								set_entity_heading;
	static fpGetEntityHeading								get_entity_heading;
	static fpGetPedLastWeaponImpactCoord					get_ped_last_weapon_impact;
	static fpGiveDelayedWeaponToPed							give_delayed_weapon_to_ped;
	static fpRemoveAllPedWeapons							remove_all_ped_weapons;
	static fpNetworkHasControlOfEntity						network_has_control_of_entity;
	static fpNetworkRequestControlOfEntity					network_request_control_of_entity;
	static fpSetVehicleFixed								set_vehicle_fixed;
	static fpClearPedTasksImmediately						clear_ped_tasks_immediately;
	static fpIsVehicleSeatFree								is_vehicle_seat_free;
	static fpSetVehicleDeformationFixed						set_vehicle_deformation_fixed;
	static fpNetworkRequestControlOfNetworkId				network_request_control_of_network_id;
	static fpNetworkGetNetworkIdFromEntity					network_get_network_id_from_entity;
	static fpAddOwnedExplosion								add_owned_explosion;
	static fpSetNetworkIdCanMigrate							set_network_id_can_migrate;
	static fpAiTaskPlayAnim									ai_task_play_anim;
	static fpSetSessionWeather								set_session_weather;
	static clockTime*										ClockTime;
	static fpPtrToHandle									ptr_to_handle;
	static fpNetworkRequestControlOfEntity2					network_request_control_of_entity2;
	static fpIsModelValid									is_model_valid;
	static fpDrawSprite										draw_sprite;
	static fpGetCurrentPedWeapon							get_current_ped_weapon;
	static fpRequestModel									request_model;
	static CReplayInterface*								m_replayIntf;
	static fpHasModelLoaded									has_model_loaded;
	static fpCreateObject									create_object;
	//static fpDeleteObject									delete_object;
	static fpGetGameplayCamRot								get_gameplay_cam_rot;
	static fpGetGameplayCamCoord							get_gameplay_cam_coord;
	static fpApplyForceToEntity								apply_force_to_entity;
	static fpSetModelAsNoLongerNeeded						set_model_as_no_longer_needed;
	//static fpSetEntityAlpha								set_entity_alpha;
	static fpGetEntityPlayerIsFreeAimingAt					get_entity_player_is_free_aiming_at;
	//static fpDeleteVehicle									delete_vehicle;
	static fpGetVehiclePedIsIn								get_vehicle_ped_is_in;
	static fpNetworkSetInSpectatorMode						network_set_in_spectator_mode;
	static fpGetChatPlayer									get_chat_player;

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


	static void Start(HMODULE hmoduleDLL);
	static void Cleanup();
	//static void unHook();
	static eGameState GetGameState();
	static BlipList* GetBlipList();
	static uint64_t getWorldPtr();
	static void onTickInit();
	static bool HookNatives();
	static __int64** getGlobalPtr();
	//static bool GED(__int64 a1, __int64 *a2);
	// Native function handler type
	static void defuseEvent(RockstarEvent e, bool toggle);
	typedef void(__cdecl * NativeHandler)(scrNativeCallContext * context);
	struct NativeRegistrationNew
	{
		uint64_t nextRegistration1;
		uint64_t nextRegistration2;
		Hooking::NativeHandler handlers[7];
		uint32_t numEntries1;
		uint32_t numEntries2;
		uint64_t hashes;

		inline NativeRegistrationNew* getNextRegistration()
		{
			uintptr_t result;
			auto v5 = reinterpret_cast<uintptr_t>(&nextRegistration1);
			auto v12 = 2i64;
			auto v13 = v5 ^ nextRegistration2;
			auto v14 = (char *)&result - v5;
			do
			{
				*(DWORD*)&v14[v5] = v13 ^ *(DWORD*)v5;
				v5 += 4i64;
				--v12;
			} while (v12);

			return reinterpret_cast<NativeRegistrationNew*>(result);
		}

		inline uint32_t getNumEntries()
		{
			return ((uintptr_t)&numEntries1) ^ numEntries1 ^ numEntries2;
		}

		inline uint64_t getHash(uint32_t index)
		{

			auto naddr = 16 * index + reinterpret_cast<uintptr_t>(&nextRegistration1) + 0x54;
			auto v8 = 2i64;
			uint64_t nResult;
			auto v11 = (char *)&nResult - naddr;
			auto v10 = naddr ^  *(DWORD*)(naddr + 8);
			do
			{
				*(DWORD *)&v11[naddr] = v10 ^ *(DWORD*)(naddr);
				naddr += 4i64;
				--v8;
			} while (v8);

			return nResult;
		}
	};
	static NativeHandler GetNativeHandler(uint64_t origHash);
	
	template <typename T>
	static void nop_bytes(T* address, T& restore, bool toggle)
	{
		if (toggle)
		{
			if (restore.empty())
				restore = *address;

			memset(address, 0x90, sizeof(T));
		}
		else if (!restore.empty())
			memcpy_s(address, sizeof(address), restore.byte, sizeof(T));
	}

	template <typename T>
	static void set_tunable(int index, T value)
	{
		globalHandle(262145).At(index).As<T>() = value;
	}
};

void WAIT(DWORD ms);

enum eThreadState
{
	ThreadStateIdle = 0x0,
	ThreadStateRunning = 0x1,
	ThreadStateKilled = 0x2,
	ThreadState3 = 0x3,
	ThreadState4 = 0x4,
};

struct scrThreadContext
{
	int ThreadID;
	int ScriptHash;
	eThreadState State;
	int _IP;
	int FrameSP;
	int _SPP;
	float TimerA;
	float TimerB;
	int TimerC;
	int _mUnk1;
	int _mUnk2;
	int _f2C;
	int _f30;
	int _f34;
	int _f38;
	int _f3C;
	int _f40;
	int _f44;
	int _f48;
	int _f4C;
	int _f50;
	int pad1;
	int pad2;
	int pad3;
	int _set1;
	int pad[17];
};

struct scrThread
{
	void *vTable;
	scrThreadContext m_ctx;
	void *m_pStack;
	void *pad;
	void *pad2;
	const char *m_pszExitMessage;
};

struct ScriptThread : scrThread
{
	const char Name[64];
	void *m_pScriptHandler;
	const char gta_pad2[40];
	const char flag1;
	const char m_networkFlag;
	bool bool1;
	bool bool2;
	bool bool3;
	bool bool4;
	bool bool5;
	bool bool6;
	bool bool7;
	bool bool8;
	bool bool9;
	bool bool10;
	bool bool11;
	bool bool12;
	const char gta_pad3[10];
};

/*
//CPatternResult
*/

class CPatternResult
{
public:
	CPatternResult(void* pVoid);
	CPatternResult(void* pVoid, void* pBegin, void* pEnd);
	~CPatternResult();

	template <typename rT>
	rT*	get(int offset = 0)
	{
		rT*	ret = nullptr;
		if (m_pVoid != nullptr)
			ret = reinterpret_cast<rT*>(reinterpret_cast<char*>(m_pVoid) + offset);
		return ret;
	}

	template <typename rT>
	rT* get_rel(int offset = 0)
	{
		rT*		result = nullptr;
		int32_t	rel;
		char*	ptr = get<char>(offset);

		if (ptr == nullptr)
			goto LABEL_RETURN;

		rel = *(int32_t*)ptr;
		result = reinterpret_cast<rT*>(ptr + rel + sizeof(rel));

	LABEL_RETURN:
		return result;
	}

	template <typename rT>
	rT*	section_begin()
	{
		return reinterpret_cast<rT*>(m_pBegin);
	}

	template <typename rT>
	rT*	section_end()
	{
		return reinterpret_cast<rT*>(m_pEnd);
	}


protected:
	void*	m_pVoid = nullptr;
	void*	m_pBegin = nullptr;
	void*	m_pEnd = nullptr;
};

class CMetaData
{
public:
	static uint64_t	begin();
	static uint64_t	end();
	static DWORD	size();
	static void		init();
private:
	static uint64_t	m_begin;
	static uint64_t	m_end;
	static DWORD	m_size;
};

class CEntity
{
public:
	char pad_0x0000[0xD0]; //0x0000
	__int64 LowLevelHandle; //0x00D0 
}; //Size=0x0016

class CPed
{
public:
	char pad_0x0000[0x28]; //0x0000
	BYTE btEntityType; //0x0028 
	char pad_0x0029[0x3]; //0x0029
	BYTE btInvisible; //0x002C 
	char pad_0x002D[0x1]; //0x002D
	BYTE btFreezeMomentum; //0x002E 
	char pad_0x002F[0x1]; //0x002F
	CEntity* pCNavigation; //0x0030 
	char pax_0x0038[0x10]; //0x0038
	CEntity*	pCPedStyle; //0x0048
	char pad_0x0038[0x40]; //0x0050
	v3 v3VisualPos; //0x0090 
	char pad_0x009C[0xED]; //0x009C
	BYTE btGodMode; //0x0189 
	char pad_0x018A[0xF6]; //0x018A
	float fHealth; //0x0280 
	char pad_0x0284[0x1C]; //0x0284
	float fHealthMax; //0x02A0 
	char pad_0x02A4[0x4]; //0x02A4
	CEntity* pCAttacker; //0x02A8 
	char pad_0x02B0[0x70]; //0x02B0
	v3 v3Velocity; //0x0320 
	char pad_0x032C[0x9FC]; //0x032C
	CEntity* pCVehicleLast; //0x0D28 
	char pad_0x0D30[0x378]; //0x0D30
	BYTE btNoRagdoll; //0x10A8 
	char pad_0x10A9[0xF]; //0x10A9
	CEntity* pCPlayerInfo; //0x10B8 
	char pad_0x10C0[0x8]; //0x10C0
	CEntity* pCWeaponManager; //0x10C8 
	char pad_0x10D0[0x31C]; //0x10D0
	BYTE btSeatBelt; //0x13EC 
	char pad_0x13ED[0xB]; //0x13ED
	BYTE btSeatbeltWindshield; //0x13F8 
	char pad_0x13F9[0x1]; //0x13F9
	BYTE btCanSwitchWeapons;
	char pad_0x13FB[0x5];
	BYTE btForcedAim; //0x1400 
	BYTE N00000936; //0x1401 
	BYTE N00000939; //0x1402 
	BYTE N00000937; //0x1403 
	char pad_0x1404[0x67]; //0x1404
	BYTE btIsInVehicle; //0x146B 
	char pad_0x146C[0x44]; //0x146C
	float fArmor; //0x14B0 
	char pad_0x14B4[0x20]; //0x14B4
	float fFatiguedHealthThreshold; //0x14D4 
	float fInjuredHealthThreshold; //0x14D8 
	float fDyingHealthThreshold; //0x14DC 
	float fHurtHealthThreshold; //0x14E0 
	char pad_0x14E4[0xC]; //0x14E4
	CEntity* pCVehicleLast2; //0x14F0 
	char pad_0x14F8[0xDC]; //0x14F8
	__int32 iCash; //0x15D4 

//entity type 3 = car, 4 = ped
	bool isGod()
	{
		return((btGodMode & 0x01) || fHurtHealthThreshold < 0.f);
	}

	bool isInvisible()
	{
		return (btInvisible & 0x01) ? true : false;
	}

	bool hasFrozenMomentum()
	{
		return (btFreezeMomentum & 0x02) ? true : false;
	}

	bool canBeRagdolled()
	{
		return (btNoRagdoll & 0x20) ? false : true;
	}

	bool hasSeatbelt()
	{
		return (btSeatBelt & 0x01) ? true : false;
	}

	bool hasSeatbeltWindshield()
	{
		return (btSeatbeltWindshield & 0x10) ? true : false;
	}

	bool isInVehicle()
	{
		return (btIsInVehicle & 0x10) ? false : true;
	}

	void giveHealth()
	{
		if (fHealth < fHealthMax)
			fHealth = fHealthMax;
		if (fArmor < 50.f)
			fArmor = 50.f;
	}
	void killPlr()
	{
		fHealth = 0;
	}

	void giveHealth(float value)
	{
		value += fHealth;
		if (value <= fHealthMax)
			fHealth = value;
		else if (fHealth < fHealthMax)
			fHealth = fHealthMax;
	}

	void setForcedAim(bool toggle)
	{
		btForcedAim ^= (btForcedAim ^ -(char)toggle) & 0x20;
	}
}; //Size=0x15D8

template <typename rT>
rT*    handle_to_ptr(int handle)
{
	uintptr_t    ptr = get_address_of_item_in_pool(*Hooking::m_entityPool, handle);
	if (ptr == 0)
		return nullptr;
	return *reinterpret_cast<rT**>(ptr + 8);
}

/*
//CPattern
*/
template <std::size_t CharCount>
struct ConstexprJooat
{
	char data[CharCount];

	template <std::size_t... Indices>
	constexpr ConstexprJooat(const char* str, std::index_sequence<Indices...>) :
		data{ (str[Indices])... }
	{
	}

	constexpr std::uint32_t GetHash()
	{
		std::uint32_t hash = 0;

		for (std::size_t i = 0; i < CharCount; ++i)
		{
			hash += tolower(data[i]);
			hash += (hash << 10);
			hash ^= (hash >> 6);
		}

		hash += (hash << 3);
		hash ^= (hash >> 11);
		hash += (hash << 15);

		return hash;
	}
};

typedef	std::vector<CPatternResult>	vec_result;
class CPattern
{
public:
	CPattern(char* szByte, char* szMask);
	~CPattern();

	CPattern&		find(int i = 0, uint64_t startAddress = 0);		//scans for i patterns
	CPattern&		virtual_find(int i = 0, uint64_t startAddress = 0);
	CPatternResult	get(int i);				//returns result i

protected:
	char*			m_szByte;
	char*			m_szMask;
	bool			m_bSet;
	vec_result		m_result;

	bool		match(int i = 0, uint64_t startAddress = 0, bool virt = false);
	bool		byte_compare(const BYTE* pData, const BYTE* btMask, const char* szMask);
	uint64_t	find_pattern(uint64_t i64Address, uint64_t end, BYTE *btMask, char *szMask);
	uint64_t	virtual_find_pattern(uint64_t address, BYTE *btMask, char *szMask);

};


Ped player_ped_id();
Ped get_player_ped(Player plr);
uintptr_t get_address_of_item_in_pool(MemoryPool* pool, int handle);
Player player_id();
bool is_entity(Entity entity);
Vector3 get_player_coords(Player plr);
Vector3 get_coords_infront_player(Player plr, float dist);
char* get_player_name(Player plr);
void add_owned_explossion(int selectedPed, Vector3 pos, int type, bool isAudable, bool isInvisible, float camShake, float damage = 120.f);
bool RequestControlOfEntity(Entity entity);
Vector3 get_entity_coords(Entity entity, bool alive);
void set_entity_coords(Entity entity, float Xpos, float Ypos, float Zpos, bool Xaxis, bool Yaxis, bool Zaxis);
void set_entity_coords(Entity entity, Vector3 coords, bool Xaxis, bool Yaxis, bool Zaxis);
bool does_entity_exist(Entity entity);
Vehicle get_vehicle_ped_is_in(Ped pedID, bool lastVehicle);
Vehicle get_vehicle_ped_is_using(Ped pedID);
bool is_ped_in_any_vehicle(Ped pedID);
//bool is_player_dead(Player plr);
Vehicle create_vehicle(Hash model, Vector3 pos, float heading, BOOL networked, BOOL unk2);
Ped create_ped(int pedType, Hash modelHash, float x, float y, float z, float heading, bool isNetworked, bool thisScriptCheck);
Object create_object(Hash modelHash, float x, float y, float z, BOOL isNetwork, BOOL thisScriptCheck, BOOL dynamic);
Object create_object(Hash modelHash, Vector3 pos, BOOL isNetwork, BOOL thisScriptCheck, BOOL dynamic);
void set_session_time(int hour);
bool ForcedRequestControlOfEntity(Entity entity);
void attach_entity_to_entity(Entity entity1, Entity entity2, int boneIndex, float xPos, float yPos, float zPos, float xRot, float yRot, float zRot, BOOL p9, BOOL useSoftPinning, BOOL collision, BOOL isPed, int vertexIndex, BOOL fixedRot);
void set_entity_heading(Entity entity, float heading);
float get_entity_heading(Entity entity);
int get_ammo_in_clip();
bool is_ped_shooting(int ped = 0);
//void attach_entity_to_entity(Entity entity1, Entity entity2, int boneIndex, float xPos, float yPos, float zPos, float xRot, float yRot, float zRot, BOOL p9, BOOL useSoftPinning, BOOL collision, BOOL isPed, int vertexIndex, BOOL fixedRot);

float get_distance_between_coords(Vector3 vec1, Vector3 vec2);

