//Hooking.cpp
#pragma once
#include "stdafx.h"

using namespace Memory;

ScriptThread*(*GetActiveThread)() = nullptr;
HMODULE _hmoduleDLL;
HANDLE mainFiber;
DWORD wakeAt;


//---------------------------- BYPASSES -----------------------------------------------------//

//twoBytes*										i_objBypass;
twoBytes*										model_spawn_bypass_info;
Bytes24*										model_check_bypass_info;


//-------------------------------------------------------------------------------------------//


std::vector<LPVOID>								Hooking::m_hooks;
uint64_t*										Hooking::m_frameCount;
threeBytes*										Hooking::m_infAmmo;
threeBytes*										Hooking::m_noReload;
fpDrawLine										Hooking::draw_line;
void*											Hooking::m_onlineName;
screenReso*										Hooking::m_resolution;
fpSetSessionTime								set_session_time_info;
fpIsDLCPresent									Hooking::is_DLC_present;
MemoryPool**									Hooking::m_entityPool;
fpGetPlayerAddress								Hooking::GetPlayerAddress;
fpAddressToEntity								Hooking::AddressToEntity;
fpSetSessionWeather								Hooking::set_session_weather;
fpCreateAmbientDrop								Hooking::create_ambient_pickup;
fpGetPlayerName									Hooking::get_player_name;
fpDrawRect										Hooking::draw_rect;
fpGetEventData									Hooking::get_event_data;
fpGetCurrentPedWeapon							Hooking::get_current_ped_weapon;
fpCreateVehicle									Hooking::create_vehicle;
fpSetVehicleOnGroundProperly					Hooking::set_vehicle_on_ground_properly;
fpSetVehicleMod									Hooking::set_vehicle_mod;
fpSetVehicleFixed								Hooking::set_vehicle_fixed;
fpNetworkSetInSpectatorMode						Hooking::network_set_in_spectator_mode;
fpGetPedLastWeaponImpactCoord					Hooking::get_ped_last_weapon_impact;
fpGiveDelayedWeaponToPed						Hooking::give_delayed_weapon_to_ped;
fpRemoveAllPedWeapons							Hooking::remove_all_ped_weapons;
fpGetChatPlayer									Hooking::get_chat_player;
fpNetworkHasControlOfEntity						Hooking::network_has_control_of_entity;
fpNetworkStartParticleFxNonLoopedAtCoord		Hooking::network_start_particle_fx_non_looped_at_coord;
fpNetworkRequestControlOfEntity					Hooking::network_request_control_of_entity;
fpIsVehicleSeatFree								Hooking::is_vehicle_seat_free;
fpAddOwnedExplosion								Hooking::add_owned_explosion;
fpClearPedTasksImmediately						Hooking::clear_ped_tasks_immediately;
fpSetVehicleDeformationFixed					Hooking::set_vehicle_deformation_fixed;
fpNetworkRequestControlOfNetworkId				Hooking::network_request_control_of_network_id;
fpNetworkGetNetworkIdFromEntity					Hooking::network_get_network_id_from_entity;
fpSetNetworkIdCanMigrate						Hooking::set_network_id_can_migrate;
fpAiTaskPlayAnim								Hooking::ai_task_play_anim;
fpPtrToHandle									Hooking::ptr_to_handle;
fpSetVehicleNumberPlateText						Hooking::set_vehicle_number_plate_text;
clockTime*										Hooking::ClockTime;
fpDrawSprite									Hooking::draw_sprite;
fpStatSetInt									Hooking::stat_set_int;
fpStatSetFloat									Hooking::stat_set_float;
fpStatSetBool									Hooking::stat_set_bool;
fpNetworkRequestControlOfEntity2				Hooking::network_request_control_of_entity2;
fpRequestModel									Hooking::request_model;
fpSetEntityHeading								Hooking::set_entity_heading;
fpGetEntityHeading								Hooking::get_entity_heading;
fpHasModelLoaded								Hooking::has_model_loaded;
twoBytes*										owned_explossion_bypass_info;
fpCreateObject									Hooking::create_object;
CReplayInterface*								Hooking::m_replayIntf;
fpGetGameplayCamRot								Hooking::get_gameplay_cam_rot;
fpGetGameplayCamCoord							Hooking::get_gameplay_cam_coord;
fpApplyForceToEntity							Hooking::apply_force_to_entity;
fpSetModelAsNoLongerNeeded						Hooking::set_model_as_no_longer_needed;

fpGetEntityPlayerIsFreeAimingAt					Hooking::get_entity_player_is_free_aiming_at;
fpGetVehiclePedIsIn								Hooking::get_vehicle_ped_is_in;
fpGetChatData									get_chat_data;
fpIsModelValid									Hooking::is_model_valid;




static eGameState* 											m_gameState;
static uint64_t												m_worldPtr;
static BlipList*											m_blipList;
static Hooking::NativeRegistrationNew**						m_registrationTable;
static std::unordered_map<uint64_t, Hooking::NativeHandler>	m_handlerCache;
static std::vector<LPVOID>									m_hookedNative;
static __int64**                                            m_globalPtr;

const int EVENT_COUNT = 83;
static std::vector<void*> EventPtr;
static char EventRestore[EVENT_COUNT] = {};


bool	Bytes24::empty()
{
	bool	r = true;
	for (int i = 0; i < 24; ++i)
		if (this->byte[i] != 0)
		{
			r = false;
			break;
		}
	return r;
}

bool	threeBytes::empty()
{
	bool	r = true;
	for (int i = 0; i < 3; ++i)
		if (this->byte[i] != 0)
		{
			r = false;
			break;
		}
	return r;
}

bool	twoBytes::empty()
{
	bool	r = true;
	for (int i = 0; i < 2; ++i)
		if (this->byte[i] != 0)
		{
			r = false;
			break;
		}
	return r;
}

/* Start Hooking */
void Hooking::Start(HMODULE hmoduleDLL)
{
	_hmoduleDLL = hmoduleDLL;
	Log::Init(hmoduleDLL);
	FindPatterns();
	FindPatternsLater();
	if (!InitializeHooks()) Cleanup();
}

BOOL Hooking::InitializeHooks()
{
	BOOL returnVal = TRUE;
	if (!iHook.Initialize()) {

		Log::Error("Failed to initialize InputHook");
		returnVal = FALSE;
	}

	if (MH_Initialize() != MH_OK) {
		Log::Error("MinHook failed to initialize");
		returnVal = FALSE;
	}

	if (!HookNatives()) {

		Log::Error("Failed to initialize NativeHooks");
		returnVal = FALSE;
	}

	return returnVal;
}

template <typename T>
bool Native(DWORD64 hash, LPVOID hookFunction, T** trampoline)
{
	if (*reinterpret_cast<LPVOID*>(trampoline) != NULL)
		return true;
	auto originalFunction = Hooking::GetNativeHandler(hash);
	if (originalFunction != 0) {
		MH_STATUS createHookStatus = MH_CreateHook(originalFunction, hookFunction, reinterpret_cast<LPVOID*>(trampoline));
		if (((createHookStatus == MH_OK) || (createHookStatus == MH_ERROR_ALREADY_CREATED)) && (MH_EnableHook(originalFunction) == MH_OK))
		{
			m_hookedNative.push_back((LPVOID)originalFunction);
			DEBUGMSG("Hooked Native 0x%#p", hash);
			return true;
		}
	}

	return false;
}

uint64_t CMetaData::m_begin = 0;
uint64_t CMetaData::m_end = 0;
DWORD CMetaData::m_size = 0;

uint64_t CMetaData::begin()
{
	return m_begin;
}
uint64_t CMetaData::end()
{
	return m_end;
}
DWORD CMetaData::size()
{
	return m_size;
}

void CMetaData::init()
{
	if (m_begin && m_size)
		return;

	m_begin = (uint64_t)GetModuleHandleA(nullptr);
	const IMAGE_DOS_HEADER*	headerDos = (const IMAGE_DOS_HEADER*)m_begin;
	const IMAGE_NT_HEADERS*	headerNt = (const IMAGE_NT_HEADERS64*)((const BYTE*)headerDos + headerDos->e_lfanew);
	m_size = headerNt->OptionalHeader.SizeOfCode;
	m_end = m_begin + m_size;
	return;
}

fpIsDLCPresent	OG_IS_DLC_PRESENT = nullptr;
BOOL __cdecl HK_IS_DLC_PRESENT(DWORD a1)
{
	if (g_running) {
		static uint64_t	last = 0;
		uint64_t		cur = *Hooking::m_frameCount;
		if (last != cur)
		{
			last = cur;
			Hooking::onTickInit();
		}
	}
	else if (IsThreadAFiber()) {
		ConvertFiberToThread();
	}
	return OG_IS_DLC_PRESENT(a1);
}

fpGetChatData OG_GCD = nullptr;
__int64 __cdecl HK_GCD(__int64 a1, __int64 a2, __int64 a3, const char* origText, BOOL isTeam) {
	chat_cmd_func(a2, a3, origText, isTeam);
	return OG_GCD(a1, a2, a3, origText, isTeam);
}

fpGetEventData m_OriginalGetEventData = nullptr;
BOOL GED(__int64 a1, __int64 a2) {

	unsigned __int8 argsSize = *reinterpret_cast<DWORD*>(a1 + 548) / 8;
	__int64* args = reinterpret_cast<__int64*>(a1 + 112);
	unsigned __int8 sender = *reinterpret_cast<BYTE*>(a2 + 45);
	const auto senderName = get_player_name(sender);
	char bufLog[2048];
	int block = -1;

	/*[only kicks]*/
	if (nonHostKicksProtBool) {
		for (int i = 0; i < eventsidKicks.size(); i++) {
			if ((int)args[0] == eventsidKicks.at(i)) {

				if ((int)args[0] == KICK_4) {
					if ((int)args[3] >= 0 && (int)args[3] <= 110) break;
				}
				else if ((int)args[0] == KICK_6) {
					if ((int)args[2] >= 0 && (int)args[2] <= 49) break;
				}
				else if ((int)args[0] == KICK_7) {
					if ((int)args[3] == 0) break;
					if ((int)args[2] >= 0 && (int)args[2] <= 19) break;
				}
				else if ((int)args[0] == KICK_8) {
					if ((int)args[3] != 0) break;
					if ((int)args[2] >= 0 && (int)args[2] <= 19) break;
				}
				else if ((int)args[0] == KICK_9) {
					if ((int)args[3] == 0) break;
					if ((int)args[2] >= 0 && (int)args[2] <= 19) break;
				}
				else if ((int)args[0] == KICK_10) {
					if ((int)args[2] >= 0 && (int)args[2] <= 19) break;
				}
				else if ((int)args[0] == KICK_11) {
					if ((int)args[2] >= 0 && (int)args[2] <= 19) break;
				}
				else if ((int)args[0] == KICK_12) {
					if ((int)args[5] <= 35) break;
				}
				

				block = i + 100;
			}
		}
	}

	/*[other events]*/
	if (block == -1) {
		for (int i = 1; i < eventsid.size(); i++) {
			if ((int)args[0] == eventsid.at(i)) {
				if (camResetProtection) {
					if ((int)args[0] == RESET_CAM) {
						if ((int)args[2] == -1432407380) {
							block = i;
							break;
						}
					}
				}

				if (kickCarProtection) {
					if ((int)args[0] == KICK_FROM_CAR) {
						block = i;
						break;
					}
				}

				if (forceToNewLobbyProt) {
					if ((int)args[0] == FORCE_TO_NEW_SESSION) {
						block = i;
						break;
					}
				}

				if (transactionErrorProt) {
					if ((int)args[0] == TRANSACTION_FAIL) {
						block = i;
						break;
					}
				}

				if (ForceToMissionProt) {
					if ((int)args[0] == SEND_TO_JOB || (int)args[0] == SEND_TO_JOB_2) {
						block = i;
						break;
					}
				}

				if (InvitesProtection) {
					if ((int)args[0] == SEND_INVITES) {
						block = i;
						break;
					}
				}

				if (CeoBanProtection) {
					if ((int)args[0] == CEO_BAN) {
						block = i;
						break;
					}
				}

				if (CEOKickProtection) {
					if ((int)args[0] == CEO_KICK) {
						block = i;
						break;
					}
				}

				if (infLoadingProt) {
					if ((int)args[0] == TP_TO_APARTMENTS) {
						if ((int)args[5] > 114 || (int)args[5] < 0) {
							block = 0;
							break;
						}
					}
				}

				if (TpToAppsProtection) {
					if ((int)args[0] == TP_TO_APARTMENTS) {
						if ((int)args[5] <= 114 || (int)args[5] > -1) {
							block = i;
							break;
						}
					}
				}

				if (gtaBannerEffectProt) {
					if ((int)args[0] == GTA_BANNER_EFFECT) {
						block = i;
						break;
					}
				}

			}
		}
	}
	//here check log __int64
	if (block != -1)
		notifyMap("~r~%s Tried To Use: %s Event", senderName, block >= 100 ? eventsidListKicks[block - 100] : eventsidList[block]);

	if (block != -1 || blockAllScrictEvents) return true;
	return m_OriginalGetEventData(a1, a2);
}

bool Hooking::HookNatives()
{
	MH_STATUS status = MH_CreateHook(Hooking::is_DLC_present, HK_IS_DLC_PRESENT, (void**)&OG_IS_DLC_PRESENT);
	if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::is_DLC_present) != MH_OK)
		return false;
	Hooking::m_hooks.push_back(Hooking::is_DLC_present);

	status = MH_CreateHook(get_chat_data, HK_GCD, (void**)&OG_GCD);
	if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(get_chat_data) != MH_OK)
		return false;
	Hooking::m_hooks.push_back(get_chat_data);

	status = MH_CreateHook(Hooking::get_event_data, GED, (void**)&m_OriginalGetEventData);
	if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::get_event_data) != MH_OK)
		return false;
	Hooking::m_hooks.push_back(Hooking::get_event_data);

	return true;
}

void __stdcall ScriptFunction(LPVOID lpParameter)
{
	try {
		ScriptMain();
	}
	catch (...) {
		Log::Fatal("Failed scriptFiber");
	}
}

void Hooking::onTickInit()
{
	if (mainFiber == nullptr)
		mainFiber = ConvertThreadToFiber(nullptr);

	if (timeGetTime() < wakeAt)
		return;

	static HANDLE scriptFiber;
	if (scriptFiber)
		SwitchToFiber(scriptFiber);
	else
		scriptFiber = CreateFiber(NULL, ScriptFunction, nullptr);
}

void Hooking::FailPatterns(const char* name)
{
	char buf[4096];
	sprintf_s(buf, "finding %s", name);
	Log::Error(buf);
	Cleanup();
}

CPatternResult::CPatternResult(void* pVoid) :
	m_pVoid(pVoid)
{}
CPatternResult::CPatternResult(void* pVoid, void* pBegin, void* pEnd) :
	m_pVoid(pVoid),
	m_pBegin(pBegin),
	m_pEnd(pEnd)
{}
CPatternResult::~CPatternResult() {}

CPattern::CPattern(char* szByte, char* szMask) :
	m_szByte(szByte),
	m_szMask(szMask),
	m_bSet(false)
{}
CPattern::~CPattern() {}

CPattern&	CPattern::find(int i, uint64_t startAddress)
{
	match(i, startAddress, false);
	if (m_result.size() <= i)
		m_result.push_back(nullptr);
	return *this;
}

CPattern&	CPattern::virtual_find(int i, uint64_t startAddress)
{
	match(i, startAddress, true);
	if (m_result.size() <= i)
		m_result.push_back(nullptr);
	return *this;
}

CPatternResult	CPattern::get(int i)
{
	if (m_result.size() > i)
		return m_result[i];
	return nullptr;
}

bool	CPattern::match(int i, uint64_t startAddress, bool virt)
{
	if (m_bSet)
		return false;
	uint64_t	begin = 0;
	uint64_t	end = 0;
	if (!virt)
	{
		CMetaData::init();
		begin = CMetaData::begin() + startAddress;
		end = CMetaData::end();
		if (begin >= end)
			return false;
	}
	int		j = 0;
	do
	{
		if (virt)
			begin = virtual_find_pattern(startAddress, (BYTE*)m_szByte, m_szMask) + 1;
		else
			begin = find_pattern(begin, end, (BYTE*)m_szByte, m_szMask) + 1;
		if (begin == NULL)
			break;
		j++;
	} while (j < i);

	m_bSet = true;
	return true;
}

bool	CPattern::byte_compare(const BYTE* pData, const BYTE* btMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++btMask)
		if (*szMask == 'x' && *pData != *btMask)
			break;
	if ((*szMask) != 0)
		return false;
	return true;
}


uint64_t	CPattern::find_pattern(uint64_t address, uint64_t end, BYTE *btMask, char *szMask)
{
	size_t len = strlen(szMask) + 1;
	for (uint64_t i = 0; i < (end - address - len); i++)
	{
		BYTE*	ptr = (BYTE*)(address + i);
		if (byte_compare(ptr, btMask, szMask))
		{
			m_result.push_back(CPatternResult((void*)(address + i)));
			return address + i;
		}
	}
	return NULL;
}

uint64_t	CPattern::virtual_find_pattern(uint64_t address, BYTE *btMask, char *szMask)
{
	MEMORY_BASIC_INFORMATION mbi;
	char*	pStart = nullptr;
	char*	pEnd = nullptr;
	char*	res = nullptr;
	size_t	maskLen = strlen(szMask);

	while (res == nullptr && sizeof(mbi) == VirtualQuery(pEnd, &mbi, sizeof(mbi)))
	{
		pStart = pEnd;
		pEnd += mbi.RegionSize;
		if (mbi.Protect != PAGE_READWRITE || mbi.State != MEM_COMMIT)
			continue;

		for (int i = 0; pStart < pEnd - maskLen && res == nullptr; ++pStart)
		{
			if (byte_compare((BYTE*)pStart, btMask, szMask))
			{
				m_result.push_back(CPatternResult((void*)pStart, mbi.BaseAddress, pEnd));
				res = pStart;
			}
		}
		mbi = {};
	}
	return (uint64_t)res;
}

void	failPat(const char* name)
{
	Log::Fatal("Failed to find %s pattern.", name);
	exit(0);
}

template <typename T>
void	setPat
(
	const char*	name,
	char*		pat,
	char*		mask,
	T**			out,
	bool		rel,
	int			offset = 0,
	int			deref = 0,
	int			skip = 0
)
{
	T*	ptr = nullptr;
	CPattern pattern(pat, mask);

	pattern.find(1 + skip);

	if (rel)
		ptr = pattern.get(skip).get_rel<T>(offset);
	else
		ptr = pattern.get(skip).get<T>(offset);

	if (ptr == nullptr)
		failPat(name);
	else {
		while (true)
		{
			if (deref <= 0)
				break;
			ptr = *(T**)ptr;
			--deref;
		}
	}

	*out = ptr;
	return;
}

template <typename T>
void	setFn
(
	const char*	name,
	char*		pat,
	char*		mask,
	T*			out,
	int			skip = 0
)
{
	char*	ptr = nullptr;

	CPattern pattern(pat, mask);

	pattern.find(1 + skip);
	ptr = pattern.get(skip).get<char>(0);

	if (ptr == nullptr)
		failPat(name);
		
	*out = (T)ptr;
	return;
}

HANDLE steam = GetModuleHandleA("steam_api64.dll");

//here find sigs after game full loaded
void Hooking::FindPatternsLater() {
	if (!steam) {//social club

	

	}
	else {//steam

		
	}

	setPat<void>("name changer",
		"\x4C\x8B\x05\x00\x00\x00\x00\x4D\x85\xC0\x74\xE4",
		"xxx????xxxxx",
		&Hooking::m_onlineName,
		true,
		3,
		1);

	setFn<fpGetPlayerName>("get_player_name",
		"\x40\x53\x48\x83\xEC\x20\x80\x3D\x00\x00\x00\x00\x00\x8B\xD9\x74\x22",
		"xxxxxxxx?????xxxx",
		&Hooking::get_player_name);

	Log::Msg("L Pat Ready!");
}

//here find sigs before full load
void Hooking::FindPatterns()
{

	auto p_activeThread = pattern("E8 ? ? ? ? 48 8B 88 10 01 00 00");
	auto p_blipList = pattern("4C 8D 05 ? ? ? ? 0F B7 C1");
	auto p_fixVector3Result = pattern("83 79 18 00 48 8B D1 74 4A FF 4A 18");
	auto p_gameLegals = pattern("72 1F E8 ? ? ? ? 8B 0D");
	auto p_gameLogos = pattern("70 6C 61 74 66 6F 72 6D 3A");
	auto p_gameState = pattern("83 3D ? ? ? ? ? 8A D9 74 0A");
	
	//auto p_modelSpawn = pattern("48 8B C8 FF 52 30 84 C0 74 05 48"); // detected
	auto p_nativeTable = pattern("76 32 48 8B 53 40 48 8D 0D");
	auto p_worldPtr = pattern("48 8B 05 ? ? ? ? 45 ? ? ? ? 48 8B 48 08 48 85 C9 74 07");
	//auto p_playerCountPTR = pattern("48 8B 0D ? ? ? ? E8 ? ? ? ? 48 8B C8 E8 ? ? ? ? 48 8B CF");
	auto p_globalPtr = pattern("4C 8D 05 ? ? ? ? 4D 8B 08 4D 85 C9 74 11");
	auto p_eventHook = pattern("48 83 EC 28 E8 ? ? ? ? 48 8B 0D ? ? ? ? 4C 8D 0D ? ? ? ? 4C 8D 05 ? ? ? ? BA 03");

	if (steam) {	//steam only

		//setFn<fpGetEntityPlayerIsFreeAimingAt>("get_entity_player_is_free_aiming_at",
		//	"\x48\x89\x5C\x24\x00\x48\x89\x7C\x24\x00\x48\x8D\x64\x24\x00\x48\x83\xEC\x20\x48\x8B\xFA\xB2\x01\x33\xDB\xE9\x00\x00\x00\x00\x48",
		//	"xxxx?xxxx?xxxx?xxxxxxxxxxxx????x",
		//	&Hooking::get_entity_player_is_free_aiming_at);
	
	}
	else {		//sc only
		
		//setFn<fpGetEntityPlayerIsFreeAimingAt>("get_entity_player_is_free_aiming_at",
		//	"\x48\x89\x5C\x24\x00\x48\x89\x7C\x24\x00\x48\x8D\x64\x24\x00\x48\x83\xEC\x20\xE9\x00\x00\x00\x00\x48\x8B\x41",
		//	"xxxx?xxxx?xxxx?xxxxx????xxx",
		//	&Hooking::get_entity_player_is_free_aiming_at);
	
	}


	//-----------------------------BYPASSES----------------------------//

	setPat<twoBytes>("oebypass",
		"\x3B\xF8\x40\x0F\x94\xC7",
		"xxxxxx",
		&owned_explossion_bypass_info,
		false);

	setPat <twoBytes>("msbypass",
		"\xD8\x48\x85\xC0\x74\x12\x48\x8B\x10\x48\x8B\xC8\xFF\x52\x30\x84\xC0\x74\x05",
		"xxxxxxxxxxxxxxxxxxx",
		&model_spawn_bypass_info,
		false,
		17);

	setPat <Bytes24>("mcbypass",
		"\xCE\x33\xC1\x0F\xBA\xF0\x1D\x8B\xC8\x33\x4D\x67",
		"xxxxxxxxxxxx",
		&model_check_bypass_info,
		false,
		40);

	//------------------------------------------------------------------//


	setFn<fpGetEntityHeading>("get_entity_heading",
		"\x48\x83\xEC\x38\x0F\x29\x74\x24\x00\xE9\x00\x00\x00\x00",
		"xxxxxxxx?x????",
		&Hooking::get_entity_heading);

	setPat<uint64_t>("frame count",
		"\x8B\x15\x00\x00\x00\x00\x41\xFF\xCF",
		"xx????xxx",
		&Hooking::m_frameCount,
		true,
		2);
	setFn<fpIsDLCPresent>("is_DLC_present",
		"\x84\xC0\x74\x0D\x8D\x53\x0C",
		"xxxxxxx",
		//"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x81\xF9\x00\x00\x00\x00",
		//"xxxx?xxxxxxx????",
		&Hooking::is_DLC_present);


	setFn<fpGetEventData>("get_event_data",
		"\x40\x53\x48\x81\xEC\x00\x00\x00\x00\x44\x8B\x81\x00\x00\x00\x00",
		"xxxxx????xxx????",
		&Hooking::get_event_data);

	setFn<fpAddOwnedExplosion>("add_owned_explosion",
		"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x4C\x89\x70\x20\x55\x48\x8D\x68\xB9\x48\x81\xEC\xF0\x00\x00\x00\x0F\x29\x70\xE8\x41\x8B\xD8",
		"xxxxxxxxxxxxxxxxxxxxxxxxxxxx???xxxxxxx",
		&Hooking::add_owned_explosion);

	setFn<fpGetPlayerAddress>("get_player_address",
		"\x40\x53\x48\x83\xEC\x20\x33\xDB\x38\x1D\x00\x00\x00\x00\x74\x1C",
		"xxxxxxxxxx????xx",
		&Hooking::GetPlayerAddress);

	setFn<fpNetworkHasControlOfEntity>("network_has_control_of_entity",
		"\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x1F\x48\x8B\x88\x00\x00\x00\x00\x48\x85\xC9\x74\x0F",
		"xxxxx????xxxxxxxx????xxxxx",
		&Hooking::network_has_control_of_entity);

	setFn<fpNetworkRequestControlOfEntity>("network_request_control_of_entity",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x8B\xD9\xE8\x00\x00\x00\x00\x84\xC0",
		"xxxx?xxxxxxxx????xx",
		&Hooking::network_request_control_of_entity);

	setFn<fpNetworkStartParticleFxNonLoopedAtCoord>("network_start_particle_fx_non_looped_at_coord",
		"\x48\x83\xEC\x78\x8A\x84\x24\x00\x00\x00\x00\x4D\x8B\xC8\x4C\x8B\xC2\x88\x44\x24\x60\x33\xC0\x88\x44\x24\x58",
		"xxxxxxx????xxxxxxxxxxxxxxxx",
		&Hooking::network_start_particle_fx_non_looped_at_coord);

	setFn<fpDrawSprite>("draw_sprite",
		"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x57\x48\x81\xEC\x00\x00\x00\x00\x0F\x29\x70\xE8\x0F\x29\x78\xD8\x48\x8B\xF2\x48\x8B\xD9\x0F\x28\xFA\x0F\x28\xF3\xE8\x00\x00\x00\x00\x80\xBC\x24",
		"xxxxxxxxxxxxxxxxxxx????xxxxxxxxxxxxxxxxxxxxx????xx",
		&Hooking::draw_sprite);

	setPat<MemoryPool*>("entity pool",
		"\x4C\x8B\x0D\x00\x00\x00\x00\x44\x8B\xC1\x49\x8B\x41\x08",
		"xxx????xxxxxxx",
		&Hooking::m_entityPool,
		true,
		3);

	setPat<CReplayInterface>("replay interface",
		"\x48\x8D\x0D\x00\x00\x00\x00\x48\x8B\xD7\xE8\x00\x00\x00\x00\x48\x8D\x0D\x00\x00\x00\x00\x8A\xD8\xE8\x00\x00\x00\x00\x84\xDB\x75\x13\x48\x8D\x0D\x00\x00\x00\x00",
		"xxx????xxxx????xxx????xxx????xxxxxxx????", 
		&Hooking::m_replayIntf,
		true, 
		3,
		1);

	setFn<fpGetCurrentPedWeapon>("get_current_ped_weapon",
		"\x40\x53\x48\x83\xEC\x20\x48\x8B\xDA\xE8\x00\x00\x00\x00\x33\xC9",
		"xxxxxxxxxx????xx",
		&Hooking::get_current_ped_weapon);

	setFn<fpIsModelValid>("is_model_valid",
		"\x48\x83\xEC\x28\x8B\x44\x24\x38\x48\x8D\x54\x24\x00\xC7\x44\x24\x00\x00\x00\x00\x00",
		"xxxxxxxxxxxx?xxx?????",
		&Hooking::is_model_valid);

	setFn<fpCreateVehicle>("create_vehicle",
		"\x48\x89\x5C\x24\x00\x55\x56\x57\x41\x54\x41\x55\x41\x56\x41\x57\x48\x8B\xEC\x48\x83\xEC\x50\xF3\x0F\x10\x02",
		"xxxx?xxxxxxxxxxxxxxxxxxxxxx",
		&Hooking::create_vehicle);

	setFn<fpRequestModel>("request_model",
		"\x48\x89\x5C\x24\x00\x48\x89\x7C\x24\x00\x55\x48\x8B\xEC\x48\x83\xEC\x50\x8B\x45\x18",
		"xxxx?xxxx?xxxxxxxxxxx",
		&Hooking::request_model);

	setFn<fpAddressToEntity>("address_to_entity",
		"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x8B\x15\x00\x00\x00\x00\x48\x8B\xF9\x48\x83\xC1\x10\x33\xDB",
		"xxxx?xxxx?xxxxxxx????xxxxxxxxx",
		&Hooking::AddressToEntity);

	setFn<fpHasModelLoaded>("has_model_loaded",
		"\x48\x89\x7C\x24\x00\x55\x48\x8B\xEC\x48\x83\xEC\x20\x8B\x45\x18\xBF",
		"xxxx?xxxxxxxxxxxx",
		&Hooking::has_model_loaded);

	setFn<fpGetChatPlayer>("GCP",
		"\x48\x8B\xD1\x48\x8B\x0D\x00\x00\x00\x00\x41\xB0\x01\xE9",
		"xxxxxx????xxxx",
		&Hooking::get_chat_player);

	setFn<fpGetChatData>("GCD",
		"\x4D\x85\xC9\x0F\x84\x00\x00\x00\x00\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x4C\x89\x48\x20\x55\x41\x54\x41\x55\x41\x56\x41\x57\x48\x8D\xA8",
		"xxxxx????xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
		&get_chat_data);

	setFn<fpCreateObject>("create_object",
		"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x4C\x89\x60\x20\x55\x41\x55\x41\x56\x48\x8D\x68\xD9",
		"xxxxxxxxxxxxxxxxxxxxxxxxxxxx",
		&Hooking::create_object);

	setFn<fpSetVehicleNumberPlateText>("set_vehicle_number_plate_text",
		"\x40\x53\x48\x83\xEC\x20\x48\x8B\xDA\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x10\x48\x8B\x48\x48",
		"xxxxxxxxxx????xxxxxxxxx",
		&Hooking::set_vehicle_number_plate_text);

	setFn<fpGetPedLastWeaponImpactCoord>("get_ped_last_weapon_impact",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x33\xDB\x48\x8B\xFA\x48\x89\x5A\x04",
		"xxxx?xxxxxxxxxxxxxx",
		&Hooking::get_ped_last_weapon_impact);

	setFn<fpStatSetInt>("stat_set_int",
		"\x89\x54\x24\x10\x55\x53\x56\x57\x41\x57",
		"xxxxxxxxxx",
		&Hooking::stat_set_int);

	setFn<fpStatSetFloat>("stat_set_float",
		"\x48\x89\x5C\x24\x00\xF3\x0F\x11\x4C\x24\x00\x57\x48\x83\xEC\x40",
		"xxxx?xxxxx?xxxxx",
		&Hooking::stat_set_float);

	setFn<fpStatSetBool>("stat_set_bool",
		"\x48\x89\x5C\x24\x00\x88\x54\x24\x10\x57\x48\x83\xEC\x40",
		"xxxx?xxxxxxxxx",
		&Hooking::stat_set_bool);

	setFn<fpDrawRect>("draw_rect",
		"\x48\x8B\xC4\x48\x89\x58\x08\x57\x48\x83\xEC\x70\x48\x63\x0D\x00\x00\x00\x00\x0F",
		"xxxxxxxxxxxxxxx????x",
		&Hooking::draw_rect);

	setFn<fpDrawLine>("draw_line",
		"\x40\x53\x48\x83\xEC\x40\xF3\x0F\x10\x09\xF3\x0F\x10\x41\x00\xF3\x0F\x10\x51\x00\x45\x8B\xD0\xBB",
		"xxxxxxxxxxxxxx?xxxx?xxxx",
		&Hooking::draw_line,
		1);

	setPat<screenReso>("resolution",
		"\x8B\x0D\x00\x00\x00\x00\x49\x8D\x56\x28",
		"xx????xxxx",
		&Hooking::m_resolution,
		true,
		2);

	setFn<fpSetVehicleMod>("set_vehicle_mod",
		"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x56\x57\x41\x56\x48\x83\xEC\x30\x41\x8A\xE9",
		"xxxx?xxxx?xxxxxxxxxxx",
		&Hooking::set_vehicle_mod);

	setFn<fpNetworkRequestControlOfEntity2>("network_request_control_of_entity2",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x33\xFF\x48\x8B\xD9\x48\x85\xC9\x74\x08\x48\x8B\x01\xFF\x50\x68\xEB\x07\x48\x8D\x05\x00\x00\x00\x00",
		"xxxx?xxxxxxxxxxxxxxxxxxxxxxxxxx????",
		&Hooking::network_request_control_of_entity2);

	setPat<clockTime>("CT",
		"\x48\x8D\x0D\x00\x00\x00\x00\x8B\xFA\xE8\x00\x00\x00\x00\x44\x8D\x0C\x5B",
		"xxx????xxx????xxxx",
		&Hooking::ClockTime,
		true,
		3);

	setFn<fpGiveDelayedWeaponToPed>("give_delayed_weapon_to_ped",
		"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x30\x41\x8A\xE9\x41\x8B\xF0\x8B\xFA\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x63",
		"xxxx?xxxx?xxxx?xxxxxxxxxxxxxx????xxxxxxxx",
		&Hooking::give_delayed_weapon_to_ped);

	setFn<fpSetVehicleFixed>("set_vehicle_fixed",
		"\x40\x53\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x28\x4C\x8B\x10",
		"xxxxxxx????xxxxxxxxxxx",
		&Hooking::set_vehicle_fixed);

	setFn<fpIsVehicleSeatFree>("is_vehicle_seat_free",
		"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x41\x56\x41\x57\x48\x83\xEC\x20\x45\x8A\xF8",
		"xxxx?xxxx?xxxx?xxxxxxxxxxxx",
		&Hooking::is_vehicle_seat_free);

	setFn<fpClearPedTasksImmediately>("clear_ped_tasks_immediately",
		"\x40\x53\x48\x83\xEC\x30\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x0F\x84",
		"xxxxxxx????xxxxxxxx",
		&Hooking::clear_ped_tasks_immediately);

	setFn<fpNetworkSetInSpectatorMode>("network_set_in_spectator_mode",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xF8\x84\xC9",
		"xxxx?xxxxxxxxxx",
		&Hooking::network_set_in_spectator_mode);

	setFn<fpSetSessionWeather>("set_session_weather",
		"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x30\x40\x8A\xE9",
		"xxxx?xxxx?xxxx?xxxxxxxx",
		&Hooking::set_session_weather);

	setFn<fpSetSessionTime>("set_session_time_info",
		"\x48\x89\x5C\x24\x08\x57\x48\x83\xEC\x20\x8B\xF9\x48\x8B\x0D\x00\x00\x00\x00\x48\x8B\xDA\x33\xD2\xE9\x00\x00\x00\x00",
		"xxxxxxxxxxxxxxx????xxxxxx????",
		&set_session_time_info);

	setFn<fpSetVehicleDeformationFixed>("set_vehicle_deformation_fixed",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x40\x48\x83\xB9\x00\x00\x00\x00\x00\x48\x8B\xD9",
		"xxxx?xxxxxxxx?????xxx",
		&Hooking::set_vehicle_deformation_fixed);

	setFn<fpAiTaskPlayAnim>("ai_task_play_anim",
		"\x48\x81\xEC\x00\x00\x00\x00\x44\x8B\x8C\x24",
		"xxx????xxxx",
		&Hooking::ai_task_play_anim);

	setFn<fpGetGameplayCamRot>("get_gameplay_cam_rot",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x30\x8B\xDA\x48\x8B\xF9\xE8\x00\x00\x00\x00\x48\x8D\x4C\x24\x00\x48\x8D\x90\x00\x00\x00\x00",
		"xxxx?xxxxxxxxxxx????xxxx?xxx????",
		&Hooking::get_gameplay_cam_rot);

	setFn<fpGetGameplayCamCoord>("get_gameplay_cam_coord",
		"\x40\x53\x48\x83\xEC\x20\x48\x8B\xD9\xE8\x00\x00\x00\x00\x8B\x90\x00\x00\x00\x00",
		"xxxxxxxxxx????xx????",
		&Hooking::get_gameplay_cam_coord);
		
	setFn<fpCreateAmbientPickup>("create_ambient_pickup",
		"\x48\x8B\xC4\x48\x89\x58\x10\x48\x89\x70\x18\x48\x89\x78\x20\x55\x41\x54\x41\x55\x41\x56\x41\x57\x48\x8D\x68\xC1\x48\x81\xEC\x00\x00\x00\x00\x45\x8B\xF9\x41\x8B\xF0\x4C\x8B\xEA\xE8\x00\x00\x00\x00\x0F\xB7\x0D\x00\x00\x00\x00\x33\xFF\x44\x8B\xC7\x44\x8B\xD7\x44\x8B\xE0\x85\xC9\x7E\x1C\x48\x8B\x1D\x00\x00\x00\x00",
		"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx????xxxxxxxxxx????xxx????xxxxxxxxxxxxxxxxxx????",
		&Hooking::create_ambient_pickup);
	
	setFn<fpSetModelAsNoLongerNeeded>("set_model_as_no_longer_needed",
		"\x40\x53\x48\x83\xEC\x30\x48\x8D\x54\x24\x00\x8B\xD9",
		"xxxxxxxxxx?xx",
		&Hooking::set_model_as_no_longer_needed);

	char * c_location = nullptr;
	void * v_location = nullptr;

	Sleep(5000);

	Log::Msg("Getting Game State...");
	c_location = p_gameState.count(1).get(0).get<char>(2);
	c_location == nullptr ? FailPatterns("gameState") : m_gameState = reinterpret_cast<decltype(m_gameState)>(c_location + *(int32_t*)c_location + 5);

	Log::Msg("Getting vector3 result fixer func...");
	v_location = p_fixVector3Result.count(1).get(0).get<void>(0);
	if (v_location != nullptr) scrNativeCallContext::SetVectorResults = (void(*)(scrNativeCallContext*))(v_location);

	Log::Msg("Getting native registration table...");
	c_location = p_nativeTable.count(1).get(0).get<char>(9);
	c_location == nullptr ? FailPatterns("native registration table") : m_registrationTable = reinterpret_cast<decltype(m_registrationTable)>(c_location + *(int32_t*)c_location + 4);

	Log::Msg("Getting World Pointer...");
	c_location = p_worldPtr.count(1).get(0).get<char>(0);
	c_location == nullptr ? FailPatterns("world Pointer") : m_worldPtr = reinterpret_cast<uint64_t>(c_location) + *reinterpret_cast<int*>(reinterpret_cast<uint64_t>(c_location) + 3) + 7;

	Log::Msg("Getting Blip List...");
	c_location = p_blipList.count(1).get(0).get<char>(0);
	c_location == nullptr ? FailPatterns("blip List") : m_blipList = (BlipList*)(c_location + *reinterpret_cast<int*>(c_location + 3) + 7);


	Log::Msg("Getting active script thread...");
	c_location = p_activeThread.count(1).get(0).get<char>(1);
	c_location == nullptr ? FailPatterns("Active Script Thread") : GetActiveThread = reinterpret_cast<decltype(GetActiveThread)>(c_location + *(int32_t*)c_location + 4);

	Log::Msg("Getting World Pointer...");
	c_location = p_globalPtr.count(1).get(0).get<char>(0);
	__int64 patternAddr = NULL;
	c_location == nullptr ? FailPatterns("globalTable") : patternAddr = reinterpret_cast<decltype(patternAddr)>(c_location);
	m_globalPtr = (__int64**)(patternAddr + *(int*)(patternAddr + 3) + 7);

	Log::Msg("Getting Event Hook...");
	if ((c_location = p_eventHook.count(1).get(0).get<char>(0)))
	{
		int i = 0, j = 0, matches = 0, found = 0;
		char* pattern = "\x4C\x8D\x05";
		while (found != EVENT_COUNT)
		{
			if (c_location[i] == pattern[j])
			{
				if (++matches == 3)
				{
					EventPtr.push_back((void*)(reinterpret_cast<uint64_t>(c_location + i - j) + *reinterpret_cast<int*>(c_location + i + 1) + 7));
					found++;
					j = matches = 0;
				}
				j++;
			}
			else
			{
				matches = j = 0;
			}
			i++;
		}
	}

	Log::Msg("Initializing Natives...");
	CrossMapping::initNativeMap();


	Log::Msg("Checking if GTA V is ready...");
	while (*m_gameState != GameStatePlaying) {
		Sleep(200);
	}
	Log::Msg("GTA V ready!");
}

void Hooking::defuseEvent(RockstarEvent e, bool toggle)
{
	static const unsigned char retn = 0xC3;
	char* p = (char*)EventPtr[e];
	if (toggle)
	{
		if (EventRestore[e] == 0)
			EventRestore[e] = p[0];
		*p = retn;
	}
	else
	{
		if (EventRestore[e] != 0)
			*p = EventRestore[e];
	}
}

static Hooking::NativeHandler _Handler(uint64_t origHash)
{
	uint64_t newHash = CrossMapping::MapNative(origHash);
	if (newHash == 0)
	{
		return nullptr;
	}

	Hooking::NativeRegistrationNew * table = m_registrationTable[newHash & 0xFF];

	for (; table; table = table->getNextRegistration())
	{
		for (uint32_t i = 0; i < table->getNumEntries(); i++)
		{
			if (newHash == table->getHash(i))
			{
				return table->handlers[i];
			}
		}
	}
	return nullptr;
}

Hooking::NativeHandler Hooking::GetNativeHandler(uint64_t origHash)
{
	auto& handler = m_handlerCache[origHash];

	if (handler == nullptr)
	{
		handler = _Handler(origHash);
	}

	return handler;
}

eGameState Hooking::GetGameState()
{
	return *m_gameState;
}

BlipList * Hooking::GetBlipList()
{
	return m_blipList;
}

uint64_t Hooking::getWorldPtr()
{
	return m_worldPtr;
}

void WAIT(DWORD ms)
{
	wakeAt = timeGetTime() + ms;
	SwitchToFiber(mainFiber);
}

void Hooking::Cleanup()
{
	Log::Msg("Cleaning up hooks");
	for (int i = 0; i < m_hooks.size(); i++)
		if (MH_DisableHook(m_hooks[i]) != MH_OK && MH_RemoveHook(m_hooks[i]) != MH_OK)
			Log::Error("Failed to unhook a sig");
	//std::this_thread::sleep_for(std::chrono::milliseconds(500));
	MH_Uninitialize();

	FreeLibraryAndExitThread(static_cast<HMODULE>(_hmoduleDLL), 0);
}


//----------------------BYPASSES-----------------------//

void owned_explossion_bypass(bool toggle)
{
	constexpr twoBytes patched = { 0x39, 0xDB };
	constexpr twoBytes restore = { 0x3B, 0xF8 };
	if (owned_explossion_bypass_info == nullptr)
		return;
	*owned_explossion_bypass_info = toggle ? patched : restore;
}

bool model_spawn_bypass(bool toggle)
{
	constexpr twoBytes patched = { 0x90, 0x90 };
	constexpr twoBytes restore = { 0x74, 0x05 };
	if (model_spawn_bypass_info == nullptr)
		return NULL;
	*model_spawn_bypass_info = toggle ? patched : restore;
	return true;
}

bool model_check_bypass(bool toggle)
{
	constexpr Bytes24 patched = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
		0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
		0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };

	constexpr Bytes24 restore = { 0x48, 0x85, 0xC0, 0x0F, 0x84, 0x99,
		0x02, 0x00, 0x00, 0x8B, 0x48, 0x50, 0xC1, 0xE9, 0x04, 0xF6,
		0xC1, 0x01, 0x0F, 0x84, 0x8A, 0x02, 0x00, 0x00 };
	if (model_check_bypass_info == nullptr)
		return NULL;
	*model_check_bypass_info = toggle ? patched : restore;
	return true;
}

//-----------------------------------------------------//

__int64** Hooking::getGlobalPtr()
{
	return m_globalPtr;
}

uintptr_t	get_address_of_item_in_pool(MemoryPool* pool, int handle)
{
	if (pool == nullptr)
		return 0;

	int index = handle >> 8;
	int flag = pool->BoolAdr[index];

	if (flag & 0x80 || flag != (handle & 0xFF))
		return 0;

	return pool->ListAddr + index * pool->ItemSize;
}

Ped player_ped_id()
{
	return PLAYER::PLAYER_PED_ID();
}

Ped get_player_ped(Player player)
{
	const auto addr = Hooking::GetPlayerAddress(player);

	if (addr) {
		return Hooking::AddressToEntity(addr);
	}
	return NULL;
}

Player player_id()
{
	for (int i = 0; i < 32; i++) {
		if (get_player_ped(i) == player_ped_id())
			return i;
	}
	return NULL;
}

Vector3 get_player_coords(Player plr)
{
	if (get_player_ped(plr))
	{
		return get_entity_coords(get_player_ped(plr), 1);
	}
	return NULL;
}

Vector3 get_coords_infront_player(Player plr, float dist)
{
	Vector3 r = get_player_coords(plr);
	float	heading = get_entity_heading(get_player_ped(plr));
	r.x += dist * sin(deg_to_rad(heading)) * -1,
		r.y += dist * cos(deg_to_rad(heading));
	return r;
}

char* get_player_name(Player plr) { return PLAYER::GET_PLAYER_NAME(plr); }

bool RequestControlOfEntity(Entity entity)
{
	int tryes = 0;
	while (!Hooking::network_has_control_of_entity(entity) && tryes++ <= 15)
		Hooking::network_request_control_of_entity(entity);
	return Hooking::network_has_control_of_entity(entity);
}

int get_ammo_in_clip() {
	return steam?
	*reinterpret_cast<int*>(Memory::get_base_offsetted(0x1C48ECC)):
	*reinterpret_cast<int*>(Memory::get_base_offsetted(0x1C44DFC));
}

bool is_ped_shooting(int ped) {
	if (GetKeyState(VK_LBUTTON)) {
		return localPlayerBulletsCount > get_ammo_in_clip();
	}
	return false;
}

bool ForcedRequestControlOfEntity(Entity entity) {
	if (!does_entity_exist(entity)) return NULL;
	else {
		int tryes = 0;
		__int64 handle = handle_to_ptr<CEntity>(entity)->LowLevelHandle;
		while (tryes++ <= 49) {
			if (!Hooking::network_has_control_of_entity(entity)) {
				Hooking::network_request_control_of_entity2(handle);
				WAIT(15 + rand() % 50);
			}
			else
				return true;
		}
	}
	return false;
}

Vector3 get_entity_coords(Entity entity, bool alive) {
	return ENTITY::GET_ENTITY_COORDS(entity, alive);
	//return Hooking::get_entity_coords(entity, alive);//steam not works
}

void set_entity_coords(Entity entity, float Xpos, float Ypos, float Zpos, bool Xaxis, bool Yaxis, bool Zaxis) {
	Vector3 pos = { Xpos, Ypos, Zpos };
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(entity, Xpos, Ypos, Zpos, Xaxis, Yaxis, Zaxis);
	//Hooking::set_entity_coords(entity, &pos, Xaxis, Yaxis, Zaxis);
}

void set_entity_coords(Entity entity, Vector3 coords, bool Xaxis, bool Yaxis, bool Zaxis) {
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(entity, coords.x, coords.y, coords.z, Xaxis, Yaxis, Zaxis);
	//Hooking::set_entity_coords(entity, &coords, Xaxis, Yaxis, Zaxis);
}

bool does_entity_exist(Entity entity){
	if (entity)
		return handle_to_ptr<__int64>(entity) != nullptr;
	return false;
}

Vehicle get_vehicle_ped_is_in(Ped pedID, bool lastVehicle)
{
	return PED::GET_VEHICLE_PED_IS_IN(pedID, lastVehicle);
	//return Hooking::get_vehicle_ped_is_in(pedID, lastVehicle);
}

void add_owned_explossion(int selectedPed, Vector3 pos, int type, bool isAudable, bool isInvisible, float camShake, float damage)
{
	owned_explossion_bypass(true);
	Hooking::add_owned_explosion(selectedPed, &pos, type, damage, isAudable, isInvisible, camShake);
	owned_explossion_bypass(false);
}

Vehicle get_vehicle_ped_is_using(Ped pedID)
{
	return PED::GET_VEHICLE_PED_IS_IN(pedID, 0);
	//return Hooking::get_vehicle_ped_is_in(pedID, 0);
}

bool is_ped_in_any_vehicle(Ped pedID)
{
	return PED::GET_VEHICLE_PED_IS_IN(pedID, 0);
	
}

Vehicle create_vehicle(Hash model, Vector3 pos, float heading, BOOL networked = 1, BOOL unk2 = 0) {
	while(!Hooking::has_model_loaded(model)) Hooking::request_model(model), WAIT(50);
	model_spawn_bypass(true);
	Vehicle veh = Hooking::create_vehicle(model, &pos, heading, networked, unk2);
	model_spawn_bypass(false);
	return veh;
}

Ped create_ped(int pedType, Hash modelHash, float x, float y, float z, float heading, bool isNetworked, bool thisScriptCheck) {
	while (!Hooking::has_model_loaded(modelHash)) Hooking::request_model(modelHash), WAIT(50);
	model_spawn_bypass(true), model_check_bypass(true);
	Ped pedHandle = PED::CREATE_PED(pedType, modelHash, x, y, z, heading, isNetworked, thisScriptCheck);
	model_spawn_bypass(false), model_check_bypass(false);
	return pedHandle;
}

Object create_object(Hash modelHash, float x, float y, float z, BOOL isNetwork, BOOL thisScriptCheck, BOOL dynamic) {
	while (!Hooking::has_model_loaded(modelHash)) Hooking::request_model(modelHash), WAIT(50);
	Object obj;
	model_check_bypass(true);
	Hooking::create_object(modelHash, x, y, z, 1, 1, 0, &obj, isNetwork, 1, dynamic);
	model_check_bypass(false);
	return obj;
}

Object create_object(Hash modelHash, Vector3 pos, BOOL isNetwork, BOOL thisScriptCheck, BOOL dynamic) {
	while (!Hooking::has_model_loaded(modelHash)) Hooking::request_model(modelHash), WAIT(50);
	Object obj;
	model_check_bypass(true);
	Hooking::create_object(modelHash, pos.x, pos.y, pos.z, 1, 1, 0, &obj, isNetwork, 1, dynamic);
	model_check_bypass(false);
	return obj;
}

void set_session_time(int hour) {
	Hooking::ClockTime->hour = hour;
	Hooking::ClockTime->minute = 0;
	Hooking::ClockTime->second = 1;
	set_session_time_info(4, 0);
}

void attach_entity_to_entity(Entity entity1, Entity entity2, int boneIndex, float xPos, float yPos, float zPos, float xRot, float yRot, float zRot, BOOL p9, BOOL useSoftPinning, BOOL collision, BOOL isPed, int vertexIndex, BOOL fixedRot) {
	Vector3 pos = { xPos, yPos, zPos };
	Vector3 rot = { xRot, yRot, zRot };
	ENTITY::ATTACH_ENTITY_TO_ENTITY(entity1, entity2, boneIndex, pos.x, pos.y, pos.z, rot.x, rot.y, rot.z, p9, useSoftPinning, collision, isPed, vertexIndex, fixedRot);
	//Hooking::attach_entity_to_entity(entity1, entity2, boneIndex, &pos, &rot, p9, useSoftPinning, collision, isPed, vertexIndex, fixedRot, false);
}

bool is_entity(Entity entity)
{
	__int64* pPed = handle_to_ptr<__int64>(entity);
	return pPed != nullptr;
}

void set_entity_heading(Entity entity, float heading) {
	ENTITY::SET_ENTITY_HEADING(entity, heading);
	//Hooking::set_entity_heading(entity, heading);
}

float get_entity_heading(Entity entity) {
	return ENTITY::GET_ENTITY_HEADING(entity);
}

float get_distance_between_coords(Vector3 vec1, Vector3 vec2) {
	Vector3 vec = {
		vec1.x - vec2.x,
		vec1.y - vec2.y,
		vec1.z - vec2.z,
	};
	return sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z);
}