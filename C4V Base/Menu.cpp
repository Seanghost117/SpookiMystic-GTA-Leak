#pragma once
#include "stdafx.h"
#include <iostream> 


char* menuVersion = "~r~ Spooki Ryd3rs 1% ~g~ Version: 1.4.1";

bool g_running =			  true;

bool spectate =				 false;
bool NeverWanted =			 false;
bool GodMod =				 false;
bool vehicleGodMod =		 false;
bool SuperJump =			 false;
bool ClownLoop =			 false;
bool fireworkloop =			 false;
bool alien1 =				 false;
bool alien2 =				 false;
bool electric =				 false;
bool watereffect =		   	 false;
bool smokeeffect =			 false;
bool ghostRider =			 false;
bool bloodeffect =			 false;
bool moneyeffect =			 false;
bool stars =				 false;
bool ESPbool =				 false;
bool ExplosiveMeele =		 false;
bool FastRun =				 false;
bool flyingcarbool =		 false;
bool bullsharkbool =		 false;
bool DropMoney =			 false;
bool FireLoop =				 false;
bool WaterLoop =			 false;
bool Freeze =				 false;
bool rainbowvehbool =		 false;
bool spawnincar =			  true;
bool spawnmaxed =			  true;
bool crashPlayerEvent =		 false;
bool spawnchrome =			 false;
bool spawnincar1 =			 false;
bool aimbotPlrbool =		 false;
bool aimbotAIbool =			 false;
bool onlinemoneygun2_5k =	 false;
bool spawnmaxed1 =			  true;
bool spawnchrome1 =			 false;
bool BusBullets =			 false;
bool ExplosiveAmmo =		 false;
bool notifyMsgAllCase =		 false;
bool FireAmmo =				 false;
bool noclipbool =			 false;
bool idlekickprot =			 false;
bool invisible =			 false;
bool noreloadbool =			 false;
bool infinityammobool =		 false;
bool nightvisionbool =		 false;
bool thermalvisionbool =	 false;
bool godmodpedbool =		 false;
bool hornboost =			 false;
bool localmoneygun2_5k =	 false;
bool superrunbool =			 false;
bool deletenearvehsbool =	 false;
bool boostnearvehbool =		 false;
bool offradar =				 false;
bool explodenearvehbool =	 false;
bool explodenearpedbool =	 false;
bool rainmoneybool =		 false;
bool airstrikegunbool =		 false;
bool oneshootkill =			 false;
bool slowMotion =			 false;	
bool boostweaponbool =		 false;
bool boostpunchbool =		 false;
bool deleteweaponbool =		 false;
bool teleportweaponbool =	 false;
bool explodewavebool =		 false;
bool antiafkkickbool =		 false;
bool remoteoffradar =		 false;
bool remotecopsblind =		 false;
bool allremoteoffradar =	 false;
bool allremotecopsblind =	 false;
bool allFlashMap =			 false;
bool allPlrResetCam =		 false;
bool resetCamPlr =			 false;
bool flashmap =				 false;
bool flashmapwithnotify =	 false;
bool autoToWaypoint =		 false;



//protections from scripted events
bool kickCarProtection = true;
bool camResetProtection = true;
bool forceToNewLobbyProt = true;
bool transactionErrorProt = true;
bool ForceToMissionProt = true;
bool InvitesProtection = false;
bool CeoBanProtection = true;
bool CEOKickProtection = true;
bool TpToAppsProtection = true;
bool nonHostKicksProtBool = true;
bool infLoadingProt = true;
bool blockAllScrictEvents = false;
bool gtaBannerEffectProt = true;

//chat cmd options
bool chatCMDTeam = false;
bool chatCMDAll = false;
bool chatCMDVehicles = false;
bool chatCMDWeapons = false;
bool chatCMDKickPlayers = false;
bool chatCMDGiveMoney = false;
unsigned __int8 chatCMDPlrMoney[32];
unsigned __int16 chatCMDPlrMoneyDelay[32];
unsigned __int16 chatCMDPlrMoneyValue[32];
unsigned __int8 chatCMDPlrMoneyRadius[32];
unsigned int chatCMDPlrMoneyTimers[32];

int animPed = 0;
int weaponPed = 0;
int localPlayerBulletsCount;
int fakemoneynotify;
int sendinvitesint;
int rpcharselectint;
int rp;
int inttime;
int TimePD0;
int TimePD1;
int TimePD2;
int TimePD3;
int TimePD4;
int TimePD5;
int TimePD6;
int TimePD7;
int TimePD8;
int TimePD9;
int TimePD10;
int TimePD11;
int TimePD12;
int TimePD13;
int TimePD14;
int TimePD15;
int TimePD16;
int TimePD17;
int TimePD18;
int TimePD19;
int LoadPlrInfoTimer;
int remoteCamResetTimer;
int resetCamPlrTimer;
int crashPlayerTimer;
int flashMapTimer;
int selectedModType;
int remoteOffRadarTimer;
int remotecopsBlindTimer;
int customBulletInt;
int allflashMapTimer;
int allremoteOffRadarTimer;
int allremotecopsBlindTimer;
int selectedPlayer;
int FLASH_MAP_HASH_ID = notificationmessagesids.at(91);

int noclipspeed = 1;
int headerToUse;
int vehWeaponint =	0;
int vehWeaponShootLastTime;
int plrInfoTimer;
int nameColorInt = 0;
int shootbulletint = 0;
int r = 255, g = 0, b = 0;

int moneyGunInt;

int moneyvalueint = 2500;
int moneydelayint = 400;

float PTFXscale = 1.2f;
float remoteEditEngine;
float remoteEditEngineT;
float MoveX;
float MoveY;
float MoveZ;
float roll1;
float yaw1;
float pitch1;

std::vector<Object> CrashObject;

void notifyMap(char * fmt, ...)
{
	char buf[2048] = { 0 };
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);

	char buff2[2048] = { 0 };
	sprintf_s(buff2, "%s", buf);

	UI::SET_TEXT_OUTLINE();
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(buff2);
	UI::_DRAW_NOTIFICATION(FALSE, FALSE);
}	void notifyMap(std::string str) { notifyMap(&str[0]); }

void Text(char* Text, float x, float y, float boxX, float boxY, float scale, int font, int align, int R, int G, int B, int A)
{
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(0.0, scale);
	UI::SET_TEXT_COLOUR(R, G, B, A);
	if (align >= 0)
		UI::SET_TEXT_JUSTIFICATION(align);
	//UI::SET_TEXT_OUTLINE();
	if (boxX != NULL || boxY != NULL)
		UI::SET_TEXT_WRAP(boxX, boxY);
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(Text);
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(x, y);
}

char* CharKeyboard(char* windowName = "", int maxInput = 21, char* defaultText = "") {
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "", "", defaultText, "", "", "", maxInput);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return "";
	return GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
}
int NumberKeyboard() {
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(1, "Give Value", "", "", "", "", "", 10);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return 0;
	return atof(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
}
void notifyleft(char* msg)
{
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(msg);
	UI::_DRAW_NOTIFICATION(2000, 1);
}

int GlobForNeverWanted(int plr) {
	return globalHandle(GLOBAL_FOR_REMOVE_WANTED_LEVEL + (1 + (plr * 614)) + 532).As<int>();
}

int IdkGlob_xxxxx_f_9() {
	return globalHandle(1651198 + 9).As<int>();
}

int IdkGlob_xxxxx_f_10() {
	return globalHandle(1651198 + 10).As<int>();
}

void antiAfkKick1()
{
	globalHandle(1373500).At(1165).As<int>() = -1;
	globalHandle(1373500).At(1149).As<int>() = -1;
}

void bullSharkTestosterone(bool toggle)
{
	globalHandle(2437549).At(3880).As<int>() = toggle ? NETWORK::GET_NETWORK_TIME() : 0;
}

void TpTo(Vector3 coords) {
	Entity e = player_ped_id();
	if (is_ped_in_any_vehicle(e)) {
		e = get_vehicle_ped_is_using(e);
	}
	set_entity_coords(e, coords.x, coords.y, coords.z, 0, 0, 1);
}

void ApplyForceToEntity(Entity e, float x, float y, float z)
{
	ENTITY::APPLY_FORCE_TO_ENTITY(e, 1, x, y, z, 0, 0, 0, 0, 1, 1, 1, 0, 1);
}

void vehicleBypass1_48(bool toggle) {
	globalHandle(4267883).As<bool>() = toggle;
	globalHandle(4267883).At(0).As<bool>() = toggle;
}

void unloadModel(Entity entity)
{
	ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&entity);
}

void ClearTasks(int plr)
{
	Hooking::clear_ped_tasks_immediately(get_player_ped(plr));
}

Vector3 GetCoordsFromCam(int distance)
{
	Vector3 rot;
	Vector3 coord;
	Hooking::get_gameplay_cam_rot(&rot, 2);
	Hooking::get_gameplay_cam_coord(&coord);

	float tZ = rot.z * 0.0174532924;
	float tX = rot.x * 0.0174532924;
	float num = std::abs(std::cos(tX));

	coord.x = coord.x + (-std::sin(tZ)) * (num + distance);
	coord.y = coord.y + (std::cos(tZ)) * (num + distance);
	coord.z = coord.z + std::sin(tX) * 8;

	return coord;
}

Vector3 addVector(Vector3 vector, Vector3 vector2) {
	vector.x += vector2.x;
	vector.y += vector2.y;
	vector.z += vector2.z;
	vector._paddingx += vector2._paddingx;
	vector._paddingy += vector2._paddingy;
	vector._paddingz += vector2._paddingz;
	return vector;
}

double DegreeToRadian(double n) {
	return n * 0.017453292519943295;
}

Vector3 RotationToDirection(Vector3 rot) {
	double num = DegreeToRadian(rot.z);
	double num2 = DegreeToRadian(rot.x);
	double val = cos(num2);
	double num3 = abs(val);
	rot.x = (float)(-(float)sin(num) * num3);
	rot.y = (float)(cos(num) * num3);
	rot.z = (float)sin(num2);
	return rot;

}

Vector3 multiplyVector(Vector3 vector, float inc) {
	vector.x *= inc;
	vector.y *= inc;
	vector.z *= inc;
	vector._paddingx *= inc;
	vector._paddingy *= inc;
	vector._paddingz *= inc;
	return vector;
}

char* charInput(char* Dispaytext = "Input", int maxInput = 21) {
	//Menu::Drawing::Rect({ 0, 0, 0, 210 }, { 0, 0 }, { 100, 50 });
	Menu::Drawing::Text(Dispaytext, { 255, 255, 255, 255, 6 }, { 0.09f, 0.035f }, { 0.45f, 0.45f }, false);
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "", "", "", "", "", "", maxInput);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return "";
	return GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();

}

Vector3	get_coords_infront_of_coords(Vector3 pos, Vector3 rot, float dist)
{
	Vector3 pos1 = multiplyVector(RotationToDirection(rot), dist);
	Vector3 newPos = { pos.x + pos1.x, pos.y + pos1.y, pos.z + pos1.z };
	return newPos;
}

void SetPedInVehicle(int pedToSet, int selectedPed, int veh = 0)
{
	if (!veh)
		veh = get_vehicle_ped_is_using(selectedPed);
	if (veh != NULL)
	{
		int Max = VEHICLE::GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS(veh);
		for (int SeatIndex = -1; SeatIndex <= Max; SeatIndex++)
		{
			if (Hooking::is_vehicle_seat_free(veh, SeatIndex, 0))
			{
				PED::SET_PED_INTO_VEHICLE(pedToSet, veh, SeatIndex);
				SeatIndex = Max + 1;
			}
		}
	}
	else
		notifyMap("~r~Player Isn't In Vehicle");
}
Vector3 rot_to_direction(Vector3*rot) {
	float radiansZ = rot->z*0.0174532924f;
	float radiansX = rot->x*0.0174532924f;
	float num = abs((float)cos((double)radiansX));
	Vector3 dir;
	dir.x = (float)((double)((float)(-(float)sin((double)radiansZ)))*(double)num);
	dir.y = (float)((double)((float)cos((double)radiansZ))*(double)num);
	dir.z = (float)sin((double)radiansX);
	return dir;
}

float get_distance(Vector3*pointA, Vector3*pointB) {
	float a_x = pointA->x;
	float a_y = pointA->y;
	float a_z = pointA->z;
	float b_x = pointB->x;
	float b_y = pointB->y;
	float b_z = pointB->z;
	double x_ba = (double)(b_x - a_x);
	double y_ba = (double)(b_y - a_y);
	double z_ba = (double)(b_z - a_z);
	double y_2 = y_ba * y_ba;
	double x_2 = x_ba * x_ba;
	double sum_2 = y_2 + x_2;
	return(float)sqrt(sum_2 + z_ba);
}

Vector3 v3ToVector3(v3 pos)
{
	return Vector3(pos.x, pos.y, pos.z);
}

v3 Vector3Tov3(Vector3 pos)
{
	return v3(pos.x, pos.y, pos.z);
}

Vector3 add(Vector3*vectorA, Vector3*vectorB) {
	Vector3 result;
	result.x = vectorA->x;
	result.y = vectorA->y;
	result.z = vectorA->z;
	result.x += vectorB->x;
	result.y += vectorB->y;
	result.z += vectorB->z;
	return result;
}

Vector3 multiply(Vector3*vector, float x) {
	Vector3 result;
	result.x = vector->x;
	result.y = vector->y;
	result.z = vector->z;
	result.x *= x;
	result.y *= x;
	result.z *= x;
	return result;
}

Hash $(std::string str)
{
	size_t len = str.size();
	unsigned int hash, i;
	for (hash = i = 0; i < len; ++i)
	{
		hash += tolower(str[i]);
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash;
}

bool is_cped_valid(__int64* cped)
{
	return cped != NULL && cped != nullptr && *(float*)(cped + 0x280) > 0;
}

__int64* get_player_cped(Ped cped) {
	if (!cped) return NULL;
	return handle_to_ptr<__int64>(cped);
}

bool is_player_dead(Player plr) {
	return !is_cped_valid(get_player_cped(get_player_ped(plr)));
}

void Spectate(bool toggle) {
	static int specAndSelPlr;
	specAndSelPlr != selectedPlayer ? specAndSelPlr = NULL : NULL;
	specAndSelPlr && toggle && !is_player_dead(player_id()) ? NULL : Hooking::network_set_in_spectator_mode(toggle && !is_player_dead(player_id()), get_player_ped(selectedPlayer)), specAndSelPlr += 100, specAndSelPlr = selectedPlayer && !is_player_dead(player_id());
	//return s;
}

void SetRank(int rpselectcharint, int rpvalue)
{
	if (!rpselectcharint) {
		Hooking::stat_set_int($("MP0_CHAR_SET_RP_GIFT_ADMIN"), Levels[(rp - 1)], 1);
		Hooking::stat_set_int($("MP1_CHAR_SET_RP_GIFT_ADMIN"), Levels[(rp - 1)], 1);
	}
	else if (rpselectcharint == 1)
		Hooking::stat_set_int($("MP0_CHAR_SET_RP_GIFT_ADMIN"), Levels[(rp - 1)], 1);
	else
		Hooking::stat_set_int($("MP1_CHAR_SET_RP_GIFT_ADMIN"), Levels[(rp - 1)], 1);
}


float degToRad(float degs)
{
	return degs * 3.141592653589793f / 180.f;
}

void noClip(bool toggle) {
	int e = player_ped_id();
	int veh = get_vehicle_ped_is_using(player_ped_id());
	if (veh)
		e = veh;
	Vector3 pos = get_entity_coords(e, false);
	set_entity_coords(e, pos.x, pos.y, pos.z, false, false, false);
	if (GetAsyncKeyState(VK_KEY_S)) {
		float fivef = .5f;
		float heading = get_entity_heading(e);
		float xVec = fivef * sin(degToRad(heading)) * -1.5f;
		float yVec = fivef * cos(degToRad(heading));
		set_entity_heading(e, heading);

		pos.x -= xVec, pos.y -= yVec;
		set_entity_coords(e, pos.x, pos.y, pos.z, false, false, false);
	}
	if (GetAsyncKeyState(VK_KEY_W)) {
		float fivef = .5f;
		float heading = get_entity_heading(e);
		float xVec = fivef * sin(degToRad(heading)) * -1.5f;
		float yVec = fivef * cos(degToRad(heading));
		set_entity_heading(e, heading);

		pos.x += xVec, pos.y += yVec;
		set_entity_coords(e, pos.x, pos.y, pos.z, false, false, false);
	}
	if (GetAsyncKeyState(VK_KEY_A)) {
		float fivef = .5f;
		float heading = get_entity_heading(e);
		set_entity_heading(e, heading + 0.5f);
	}
	if (GetAsyncKeyState(VK_KEY_D)) {
		float fivef = .5f;
		float heading = get_entity_heading(e);
		set_entity_heading(e, heading - 0.5f);
	}
	if (GetAsyncKeyState(VK_CONTROL)) {
		float heading = get_entity_heading(e);
		set_entity_heading(e, heading);

		pos.z -= 0.5f;
		set_entity_coords(e, pos.x, pos.y, pos.z, false, false, false);
	}
	if (GetAsyncKeyState(VK_SHIFT)) {
		float heading = get_entity_heading(e);
		set_entity_heading(e, heading);

		pos.z += 0.5f;
		set_entity_coords(e, pos.x, pos.y, pos.z, false, false, false);
	}
}

Vector3 WaypointCoords()
{
	static Vector3 zero;
	Vector3 coords;

	bool blipFound = false;
	// search for marker blip
	int blipIterator = UI::_GET_BLIP_INFO_ID_ITERATOR();
	for (Blip i = UI::GET_FIRST_BLIP_INFO_ID(blipIterator); UI::DOES_BLIP_EXIST(i) != 0; i = UI::GET_NEXT_BLIP_INFO_ID(blipIterator))
	{
		if (UI::GET_BLIP_INFO_ID_TYPE(i) == 4)
		{
			coords = UI::GET_BLIP_INFO_ID_COORD(i);
			blipFound = true;
			break;
		}
	}
	if (blipFound)
	{
		return coords;
	}

	return zero;
}

void fixVehicle(int selectedPlayer)
{
	//Log::Msg("start");
	int veh = get_vehicle_ped_is_using(get_player_ped(selectedPlayer));
	//Log::Msg("veh:", veh);
	if (veh)
	{
		Hooking::set_vehicle_fixed(veh);
		Hooking::set_vehicle_deformation_fixed(&veh);
		
		VEHICLE::SET_VEHICLE_DIRT_LEVEL(veh, 0);
	}
	else
		notifyMap("~r~Player Isn't In Vehicle");
}


void no_reload_toggle(bool toggle)
{
	static threeBytes	restore = { 0 };
	Hooking::nop_bytes(Hooking::m_noReload, restore, toggle);
}

void infinite_ammo_toggle(bool toggle)
{
	static threeBytes	restore = { 0 };
	Hooking::nop_bytes(Hooking::m_infAmmo, restore, toggle);
}


void moneyGun2_5k(Ped playerPed) {
	Hash moneyBagHash = 0x9CA6F755;
	{
		v3 coords;
		if (Hooking::get_ped_last_weapon_impact(playerPed, &coords))
		{
			Hooking::request_model(moneyBagHash);
			if (!Hooking::has_model_loaded(moneyBagHash)) {

			}
			else
			{
				Hooking::create_ambient_pickup(0xDE78F17E, &v3ToVector3(coords), 0, 2500, moneyBagHash, FALSE, TRUE);
				Hooking::set_model_as_no_longer_needed(moneyBagHash);
			}
		}
	}
}

void localspawnVehicleByName()
{
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(1, "FMMC_KEY_TIP8S", "", "", "", "", "", 20);
	while (true)
	{
		int Result = GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD();
		char* ResultString = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
		if (Result == 1)
		{
			if (!STREAMING::IS_MODEL_VALID($(ResultString)))
			{
				break;
			}
			Vector3 pos = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(player_ped_id(), 0.0f, 5.0f, 0.0f);
			
			Hooking::request_model($(ResultString));
			while (!Hooking::has_model_loaded($(ResultString)))
				WAIT(0);

			Vehicle vehicle = create_vehicle($(ResultString), pos, 1, true, false);
			vehicleBypass1_48(true);
			if (vehicle)
			{
				VEHICLE::SET_VEHICLE_IS_STOLEN(vehicle, false);
				VEHICLE::SET_VEHICLE_ENGINE_ON(vehicle, true, true, true);
			}
			if (spawnincar)
			{
				PED::SET_PED_INTO_VEHICLE(player_ped_id(), vehicle, -1);
			}
			if (spawnmaxed)
			{
				VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
				for (int i = 0; i < 50; i++)
				{
					Hooking::set_vehicle_mod(vehicle, i, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, i) - 1, false);
				}
			}
			if (spawnchrome)
				VEHICLE::SET_VEHICLE_COLOURS(vehicle, 120, 120);
			WAIT(150);
			unloadModel($(ResultString));
			DECORATOR::DECOR_SET_INT(vehicle, "MPBitset", (1 << 10));

			break;
		}
		else if (Result == 2)
		{
			break;
		}
		WAIT(0);
	}
}

void OffRadar(bool toggle)
{
	globalHandle(GLOBAL_FOR_OFF_RADAR_BOOL + 1 + player_id() * 416 + 200).As<bool>() = toggle;
	globalHandle(GLOBAL_FOR_OFF_RADAR_INT + 70).As<int>() = NETWORK::GET_NETWORK_TIME() + 1;
}

void update_vehicle_guns(char* weaponName)
{
	Ped playerPed = player_ped_id();

	if (GetAsyncKeyState(0x6B) && vehWeaponShootLastTime + 150 < GetTickCount() && is_ped_in_any_vehicle(playerPed))// num plus
	{
		Vehicle veh = get_vehicle_ped_is_using(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = $(weaponName);
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, 500);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, 500);

		vehWeaponShootLastTime = GetTickCount();
	}
}

void trap(int selectedPlayer)
{
	ClearTasks(selectedPlayer);
	Vector3 pos = get_player_coords(selectedPlayer);
	Object obj = create_object(0x392d62aa, pos.x, pos.y, pos.z - 1.f, true, false, false);
	ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&obj);
}

void rainMoneyCMD(int player, unsigned __int16 delay[], unsigned __int16 value[], unsigned int timers[]) {
	Hash moneyBagHash = 0x9CA6F755;
	if (!Hooking::has_model_loaded(moneyBagHash))
		Hooking::request_model(moneyBagHash);
	else if (timeGetTime() - timers[player] > delay[player]) {

		Vector3 coords = get_player_coords(player);
		coords.z += 10; coords.x += 5 - rand() % 10; coords.y += 5 - rand() % 10;

		Hooking::create_ambient_pickup(0xDE78F17E, &coords, 0, value[player], moneyBagHash, false, true);
		timers[player] = timeGetTime();
	}
}

void dropMoneyCircleCMD(int player, unsigned __int16 delay[], unsigned __int16 value[], unsigned int timers[], unsigned __int8 radius[]) {
	static Vector3 money;
	Hash moneyBagHash = 0x9CA6F755;
	Vector3 pos = get_player_coords(player);
	if (!Hooking::has_model_loaded(moneyBagHash)) {
		Hooking::request_model(moneyBagHash);
	}
	else if ((timeGetTime() - timers[player]) > delay[player]) {
		float randomValue = rand() % (radius[player] * 2);
		float moneyX = randomValue - radius[player];
		bool goesUp = rand() % 2;
		float Ydis = sqrt(radius[player] * radius[player] - (randomValue - radius[player]) * (randomValue - radius[player]));
		float moneyY = (goesUp ? Ydis : -Ydis);
		if (money.x || money.y) {
			money = { pos.x - moneyX, pos.y + moneyY, pos.z };
			Hooking::create_ambient_pickup(0xDE78F17E, &money, 0, value[player], moneyBagHash, false, true);
			money.x = 0, money.y = 0;
		}
		else {
			money = { pos.x + moneyY, pos.y - moneyX, pos.z };
			Hooking::create_ambient_pickup(0xDE78F17E, &money, 0, value[player], moneyBagHash, false, true);
		}
		timers[player] = timeGetTime();
	}
}

void chatcmddropmoney() {
	static bool reset;
	if (!chatCMDGiveMoney && !reset) {
		for (int x = 0; x < 32; x++) {
			chatCMDPlrMoney[x] = 0;
			chatCMDPlrMoneyDelay[x] = 80;
			chatCMDPlrMoneyValue[x] = 2500;
			chatCMDPlrMoneyRadius[x] = 5;
			reset = true;
		}
	}
	else {
		for (int x = 0; x < 32; x++) {
			if (chatCMDPlrMoney[x]) {
				if (chatCMDPlrMoney[x] == 1)
					rainMoneyCMD(x, chatCMDPlrMoneyDelay, chatCMDPlrMoneyValue, chatCMDPlrMoneyTimers);
				else if (chatCMDPlrMoney[x] == 2)
					dropMoneyCircleCMD(x, chatCMDPlrMoneyDelay, chatCMDPlrMoneyValue, chatCMDPlrMoneyTimers, chatCMDPlrMoneyRadius);
			}
		}
		reset = false;
	}
}

void SpawnVehicle(const char* VehName, int selectedPlayer, bool spawnincar, bool spawnmaxed, bool spawnchrome/*, bool spawngodmoded, bool opEnginePower*/) {
	Hash model = $(VehName);
	if (STREAMING::IS_MODEL_VALID(model))
	{
		Hooking::request_model(model);
		while (!Hooking::has_model_loaded(model)) WAIT(0);
		
		Vector3 coords = get_coords_infront_player(selectedPlayer, 5);
		
		int veh = create_vehicle(model, coords, 1, true, true);
		vehicleBypass1_48(true);
		NETWORK::NETWORK_FADE_IN_ENTITY(veh, 1);
		VEHICLE::SET_VEHICLE_IS_STOLEN(veh, false);
		VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, true);
		DECORATOR::DECOR_SET_INT(veh, "MPBitset", (1 << 10));
		if (spawnincar)
		{
			PED::SET_PED_INTO_VEHICLE(player_ped_id(), veh, -1);
		}
		if (spawnmaxed)
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			for (int i = 0; i < 50; i++)
			{
				Hooking::set_vehicle_mod(veh, i, VEHICLE::GET_NUM_VEHICLE_MODS(veh, i) - 1, false);
			}
		}
		if (spawnchrome) 
			VEHICLE::SET_VEHICLE_COLOURS(veh, 120, 120);
		WAIT(100);
		unloadModel(model);
	}
}

void UpgradVehicle(Vehicle veh)
{
	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
	VEHICLE::SET_VEHICLE_COLOURS(veh, 120, 120);
	VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh, 5);
	VEHICLE::TOGGLE_VEHICLE_MOD(veh, 18, 1);
	VEHICLE::TOGGLE_VEHICLE_MOD(veh, 22, 1);
	Hooking::set_vehicle_mod(veh, 16, 5, 0);
	Hooking::set_vehicle_mod(veh, 12, 2, 0);
	Hooking::set_vehicle_mod(veh, 11, 3, 0);
	Hooking::set_vehicle_mod(veh, 14, 14, 0);
	Hooking::set_vehicle_mod(veh, 15, 3, 0);
	Hooking::set_vehicle_mod(veh, 13, 2, 0);
	VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 6);
	VEHICLE::SET_VEHICLE_WINDOW_TINT(veh, 3);
	Hooking::set_vehicle_mod(veh, 23, 19, 1);
	Hooking::set_vehicle_mod(veh, 0, 1, 0);
	Hooking::set_vehicle_mod(veh, 1, 1, 0);
	Hooking::set_vehicle_mod(veh, 2, 1, 0);
	Hooking::set_vehicle_mod(veh, 3, 1, 0);
	Hooking::set_vehicle_mod(veh, 4, 1, 0);
	Hooking::set_vehicle_mod(veh, 5, 1, 0);
	Hooking::set_vehicle_mod(veh, 6, 1, 0);
	Hooking::set_vehicle_mod(veh, 7, 1, 0);
	Hooking::set_vehicle_mod(veh, 8, 1, 0);
	Hooking::set_vehicle_mod(veh, 9, 1, 0);
	Hooking::set_vehicle_mod(veh, 10, 1, 0);
}

void GiveAllWeapons(int selectedPlayer)
{
	for each (Hash weapon in weaponsList)
	{
		Hooking::give_delayed_weapon_to_ped(get_player_ped(selectedPlayer), weapon, 9999, true);
	}
}

void Invisibility(bool toggle)
{
	if (toggle)
		ENTITY::SET_ENTITY_VISIBLE(player_ped_id(), false, 0);
	else
		ENTITY::SET_ENTITY_VISIBLE(player_ped_id(), true, 0);
}

void nightvision(bool toggle)
{
	GRAPHICS::SET_NIGHTVISION(nightvisionbool);
}
void thermalvision(bool toggle)
{
	GRAPHICS::SET_SEETHROUGH(thermalvisionbool);
}

void explodepeds()
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;
	Ped *peds = new Ped[ArrSize];
	peds[0] = ElementAmount;
	int PedFound = PED::GET_PED_NEARBY_PEDS(player_ped_id(), peds, -1);
	for (int i = 0; i < PedFound; i++)
	{
		int OffsetID = i * 2 + 2;
		//RequestControlOfEntity(peds[OffsetID]);
		if (does_entity_exist(peds[OffsetID]) && player_ped_id() != peds[OffsetID])
		{
			Vector3 pos = get_entity_coords(peds[OffsetID], false);
			FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z, 0, 1000.f, true, false, 0.f);
		}
	}
	delete peds;
}

void explodenearbyvehicles()
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;
	Vehicle *vehs = new Vehicle[ArrSize];
	vehs[0] = ElementAmount;
	int VehFound = PED::GET_PED_NEARBY_VEHICLES(player_ped_id(), vehs);
	for (int i = 0; i < VehFound; i++)
	{
		int OffsetID = i * 2 + 2;
		if (vehs[OffsetID] != get_vehicle_ped_is_in(player_ped_id(), false))
		{
			//RequestControlOfEntity(vehs[OffsetID]);
			Vector3 coords = get_entity_coords(vehs[OffsetID], false);
			FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 0, 1000.f, true, false, 0.f);
		}
	}
	delete vehs;
}

void driftVehMode2() {
	static bool active;
	if (GetAsyncKeyState(VK_SHIFT)) {
		VEHICLE::SET_VEHICLE_REDUCE_GRIP(get_vehicle_ped_is_in(player_ped_id(), 0), 1);
		active = 1;
	}
	else if (active) {
		VEHICLE::SET_VEHICLE_REDUCE_GRIP(get_vehicle_ped_is_in(player_ped_id(), 0), 0);
		active = 0;
	}
}

void boostnearbyvehicles()
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;
	Vehicle *vehs = new Vehicle[ArrSize];
	vehs[0] = ElementAmount;
	int VehFound = PED::GET_PED_NEARBY_VEHICLES(player_ped_id(), vehs);
	for (int i = 0; i < VehFound; i++)
	{
		int OffsetID = i * 2 + 2;
		if (vehs[OffsetID] != get_vehicle_ped_is_in(player_ped_id(), false))
		{
			//RequestControlOfEntity(vehs[OffsetID]);
			ENTITY::APPLY_FORCE_TO_ENTITY(vehs[OffsetID], 1, 0, 200, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1);
		}
	}
	delete vehs;
}

void bodyguard(char* pedName) {
	Ped selectedplayer = get_player_ped(selectedPlayer);
	Vector3 pos = get_player_coords(selectedPlayer);
	Hash pedm = $(pedName);
	Hooking::request_model(pedm);
	while (!Hooking::has_model_loaded(pedm))
		WAIT(0);
	int my_group = PLAYER::GET_PLAYER_GROUP(selectedplayer);
	int Cped = create_ped(26, pedm, pos.x + rand() % 1, pos.y + rand() % 1, pos.z + 1, 0, 1, 1);
	if (Cped) {
		PED::SET_PED_AS_GROUP_LEADER(selectedplayer, my_group);
		PED::SET_PED_AS_GROUP_MEMBER(Cped, my_group);
		PED::SET_PED_NEVER_LEAVES_GROUP(Cped, my_group);
		PED::SET_PED_COMBAT_ABILITY(Cped, 100);
		if (weaponPed != 0) {
			Hooking::give_delayed_weapon_to_ped(Cped, $(weaponNames[weaponPed]), 9999, true);
			PED::SET_PED_CAN_SWITCH_WEAPON(Cped, true);
		}
		if (animPed != 0)
		{
			RequestControlOfEntity(Cped);
			STREAMING::REQUEST_ANIM_DICT(animDictList[animPed]);
			if (STREAMING::HAS_ANIM_DICT_LOADED((animDictList[animPed])))
				Hooking::ai_task_play_anim(Cped, animDictList[animPed], animNameList[animPed], 8.0f, 0.0f, -1, 120, 0, 0, 0, 0);
		}
		if (is_ped_in_any_vehicle(get_player_ped(selectedPlayer))) {
			SetPedInVehicle(Cped, get_player_ped(selectedPlayer));
		}
		if (godmodpedbool) {
			handle_to_ptr<CPed>(Cped)->btGodMode = 1;
		}
		Hooking::set_model_as_no_longer_needed(pedm);
	}
}

void enemy(char* pedName) {
	Ped selectedplayer = get_player_ped(selectedPlayer);
	Vector3 pos = get_player_coords(selectedPlayer);
	Hash pedm = $(pedName);
	Hooking::request_model(pedm);
	while (!Hooking::has_model_loaded(pedm))
		WAIT(0);
	int Cped = create_ped(26, pedm, pos.x + rand() % 1, pos.y + rand() % 1, pos.z + 1, 0, 1, 1);
	PED::SET_PED_COMBAT_ABILITY(Cped, 100);
	if (weaponPed != 0) {
		Hooking::give_delayed_weapon_to_ped(Cped, $(weaponNames[weaponPed]), 9999, true);
		PED::SET_PED_CAN_SWITCH_WEAPON(Cped, true);
	}
	AI::TASK_COMBAT_PED(Cped, selectedplayer, 1, 1);
	PED::SET_PED_ALERTNESS(Cped, 1);
	PED::SET_PED_COMBAT_RANGE(Cped, 2);
	PED::SET_PED_ALERTNESS(Cped, 3);
	if (animPed != 0)
	{
		RequestControlOfEntity(Cped);
		STREAMING::REQUEST_ANIM_DICT(animDictList[animPed]);
		if (STREAMING::HAS_ANIM_DICT_LOADED((animDictList[animPed])))
			Hooking::ai_task_play_anim(Cped, animDictList[animPed], animNameList[animPed], 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
	}
	if (is_ped_in_any_vehicle(get_player_ped(selectedPlayer))) {
		RequestControlOfEntity(Cped);
		SetPedInVehicle(Cped, get_player_ped(selectedPlayer));
	}
	if (godmodpedbool) {
		RequestControlOfEntity(Cped);
		handle_to_ptr<CPed>(Cped)->btGodMode = 1;
	}
	Hooking::set_model_as_no_longer_needed(pedm);
}

void deletenearbyvehicles()
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;
	Vehicle *vehs = new Vehicle[ArrSize];
	vehs[0] = ElementAmount;
	int VehFound = PED::GET_PED_NEARBY_VEHICLES(player_ped_id(), vehs);
	for (int i = 0; i < VehFound; i++)
	{
		int OffsetID = i * 2 + 2;
		if (vehs[OffsetID] != get_vehicle_ped_is_in(player_ped_id(), false))
		{
			//RequestControlOfEntity(vehs[OffsetID]);
			set_entity_coords(vehs[OffsetID], 6400.f, 6400.f, 0.f, false, false, false);
		}
	}
	delete vehs;
}

void AttachObject(const std::string& object, int selectedplayer) {
	const auto object_hash = $(const_cast<char*>(object.c_str()));

	if (STREAMING::IS_MODEL_IN_CDIMAGE(object_hash) && STREAMING::IS_MODEL_VALID(object_hash))
	{
		Hooking::request_model(object_hash);
		if (Hooking::has_model_loaded(object_hash))
		{
			Vector3 offset = { 0, 0, 0 };
			Vector3 rot = { 0, 0, 0 };
			const auto ped_position = get_player_coords(selectedplayer);
			auto object_to_attach = create_object(object_hash, ped_position.x, ped_position.y, ped_position.z, true, false, true);
			attach_entity_to_entity(object_to_attach, get_player_ped(selectedplayer), SKEL_Spine0, 0, 0, 0, 0, 0, 0, false, false, false, true, 2, true);
		}
	}
}

void flyingCarLoop()
{
	int veh = get_vehicle_ped_is_in(player_ped_id(), 0);
	if (veh)
	{
		if (VEHICLE::IS_THIS_MODEL_A_CAR(ENTITY::GET_ENTITY_MODEL(veh)) || VEHICLE::IS_THIS_MODEL_A_BOAT(ENTITY::GET_ENTITY_MODEL(veh)))
		{
			if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_VEH_FLY_THROTTLE_UP))
			{
				float Speed = ENTITY::GET_ENTITY_SPEED(veh) + 0.4;
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, Speed);
			}

			if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_VEH_FLY_YAW_LEFT) && (!VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(veh)))
			{
				Vector3 Rot = ENTITY::GET_ENTITY_ROTATION(veh, 2);
				Rot.z = Rot.z + 1.0;
				ENTITY::SET_ENTITY_ROTATION(veh, Rot.x, Rot.y, Rot.z, 2, 1);
			}

			if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_VEH_FLY_YAW_RIGHT) && (!VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(veh)))
			{
				Vector3 Rot = ENTITY::GET_ENTITY_ROTATION(veh, 2);
				Rot.z = Rot.z - 1.0;
				ENTITY::SET_ENTITY_ROTATION(veh, Rot.x, Rot.y, Rot.z, 2, 1);
			}
		}
	}
}

void RGBFade()
{
	if (r > 0 && b == 0) {
		r--;
		g++;
	}
	if (g > 0 && r == 0) {
		g--;
		b++;
	}
	if (b > 0 && g == 0) {
		r++;
		b--;
	}
}

std::string get_ingame_keyboard_result()
{
	std::string    r = "!!INVALID!!";
	if (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD())
	{
		char* pCh = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
		if (pCh != nullptr)
			r = pCh;
	}
	return r;
}

void PTFX(char* asset, char* effectName, int selectedPlayer)
{
	Vector3 pos = get_player_coords(selectedPlayer);
	Vector3 rot = { 0, 0, 0 };
	STREAMING::REQUEST_NAMED_PTFX_ASSET(asset);
	if (STREAMING::HAS_NAMED_PTFX_ASSET_LOADED(asset))
	{
		GRAPHICS::USE_PARTICLE_FX_ASSET(asset);
		Hooking::network_start_particle_fx_non_looped_at_coord(effectName, &pos, &rot, PTFXscale, false, false, false);
	}
}

void setplayername(std::string& name)
{
	size_t newLen = name.size() + 1;
	if (newLen <= 1 || newLen > 20)
		return;
	char    buffer[0x20] = {};
	char*    pSearch = (char*)Hooking::m_onlineName + 0x5C;
	size_t    curLen = strlen(pSearch) + 1;
	strncpy_s(buffer, pSearch, curLen);
	for (uint32_t i = 0, found = 0, match = 0; found < 4; ++pSearch)
	{
		if (*pSearch != buffer[i])
			goto LABEL_RESET;
		if (++match < curLen)
		{
			++i;
			continue;
		}
		strncpy_s(pSearch - i, newLen, &name[0], newLen);
		++found;
	LABEL_RESET:
		i = match = 0;
	}
	strncpy(Hooking::get_player_name(player_ped_id()), &name[0], newLen);
}

void NameChanger()
{
	std::string strC;
	CharKeyboard("", 21, "");
	strC = nameColor1[nameColorInt];
	std::string str = strC + get_ingame_keyboard_result();
	if (str != "!!INVALID!!" && str != "")
		setplayername(str);
}

int espr = 255;
int espg = 255;
int espb = 255;

void esp(int target) {
	if (target != player_id() && get_player_ped(target)) {
		Vector3 entitylocation = get_player_coords(target);
		Vector3 top1world = { entitylocation.x + 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z + .8f, NULL };
		Vector3 top2world = { entitylocation.x - 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z + .8f, NULL };
		Vector3 top3world = { entitylocation.x + 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z + .8f, NULL };
		Vector3 top4world = { entitylocation.x - 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z + .8f, NULL };
		Vector3 bottom1world = { entitylocation.x + 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z - .8f, NULL };
		Vector3 bottom2world = { entitylocation.x - 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z - .8f, NULL };
		Vector3 bottom3world = { entitylocation.x + 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z - .8f, NULL };
		Vector3 bottom4world = { entitylocation.x - 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z - .8f, NULL };
		Hooking::draw_line(&top1world, &top2world, espr, espg, espb, 255);
		Hooking::draw_line(&top2world, &top4world, espr, espg, espb, 255);
		Hooking::draw_line(&top4world, &top3world, espr, espg, espb, 255);
		Hooking::draw_line(&top1world, &top3world, espr, espg, espb, 255);
		Hooking::draw_line(&bottom1world, &bottom2world, espr, espg, espb, 255);
		Hooking::draw_line(&bottom2world, &bottom4world, espr, espg, espb, 255);
		Hooking::draw_line(&bottom3world, &bottom4world, espr, espg, espb, 255);
		Hooking::draw_line(&bottom3world, &bottom1world, espr, espg, espb, 255);
		Hooking::draw_line(&top1world, &bottom1world, espr, espg, espb, 255);
		Hooking::draw_line(&top2world, &bottom2world, espr, espg, espb, 255);
		Hooking::draw_line(&top3world, &bottom3world, espr, espg, espb, 255);
		Hooking::draw_line(&top4world, &bottom4world, espr, espg, espb, 255);
		Vector3 locationOne = get_player_coords(target);
		Vector3 locationTwo = get_player_coords(player_id());
		Hooking::draw_line(&locationOne, &locationTwo, espr, espg, espb, 255);
	}
}

void shootAtPed(Ped selectedPed)
{
	Vector3 Mouth = PED::GET_PED_BONE_COORDS(selectedPed, SKEL_Head, 0.1f, 0.0f, 0.0f);
	//PLAYER::DISABLE_PLAYER_FIRING(player_ped_id(), 1);
	Vector3 gameplayCam;
	Vector3 gameplayCamRot;
	Hooking::get_gameplay_cam_coord(&gameplayCam);
	Hooking::get_gameplay_cam_rot(&gameplayCamRot, 0);
	Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
	Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 1.0f)));
	Vector3 endCoords = Mouth;
	Hash weaponhash;
	Hooking::get_current_ped_weapon(player_ped_id(), &weaponhash, 1);
	GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(startCoords.x, startCoords.y, startCoords.z, endCoords.x, endCoords.y, endCoords.z, 50, 1, weaponhash, player_ped_id(), 1, 1, 0xbf800000);
}

inline bool notifyMsgCheckFlag(notifyMsg notifyMsgOut, string wantedflags) {
	for (int x = 0; x < wantedflags.length(); x++) {
		if (notifyMsgOut.flags.find(wantedflags.at(x)) != string::npos)
			return true;
	}
	return false;
}

bool isNear(Vector3 coords)
{
	Vector3 playerPosition = get_player_coords(player_id());
	return get_distance_between_coords(playerPosition, coords) < 200.0f;
}

void aimbotPlayers() {
	if (is_ped_shooting(NULL)) {
		for (int i = 0; i < 32; i++) {
			int playerHandle = get_player_ped(i);
			Vector3 p = get_player_coords(i);
			if (player_ped_id() && playerHandle && playerHandle != player_ped_id() && isNear(p)) {
				shootAtPed(playerHandle);
				Log::Msg("ok_done1");
			}
		}
	}
}

void aimbotAI()
{
	if (is_ped_shooting(NULL)) {
		const int ElementAmount = 1;
		const int ArrSize = ElementAmount * 2 + 2;
		Ped *peds = new Ped[ArrSize];
		peds[0] = ElementAmount;
		int PedFound = PED::GET_PED_NEARBY_PEDS(player_ped_id(), peds, -1);
		Log::Msg("ok_done2 ped: %i", PedFound);
		for (int i = 0; i < PedFound; i++)
		{
			int OffsetID = i * 2 + 2;
			if (does_entity_exist(peds[OffsetID]) && player_ped_id() != peds[OffsetID])
			{
				shootAtPed(peds[OffsetID]);
				Log::Msg("ok_done3");
			}
		}
		delete peds;
	}
}

void superRun()
{
	Ped playerPed = player_ped_id();
	if (AI::IS_PED_RUNNING(playerPed) || AI::IS_PED_SPRINTING(playerPed) && !PED::IS_PED_RUNNING_RAGDOLL_TASK(playerPed))
	{
		ENTITY::APPLY_FORCE_TO_ENTITY(playerPed, 1, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, TRUE, TRUE, TRUE, FALSE, TRUE);
	}
}

void giveweapmk2(int selectedPlayer)
{
	if (does_entity_exist(get_player_ped(selectedPlayer))) {
		for each (Hash weapon in weaponListmk2)
		{
			Hooking::give_delayed_weapon_to_ped(get_player_ped(selectedPlayer), weapon, 9999, true);
		}
	}
}

void PTFXCALLBoneless(char* call1, char* name, int bone, int selectedPlayer) {
	Ped Pped = get_player_ped(selectedPlayer);
	float fx = 0.1f;

	STREAMING::REQUEST_NAMED_PTFX_ASSET(call1);
	if (STREAMING::HAS_NAMED_PTFX_ASSET_LOADED(call1)) {
		GRAPHICS::USE_PARTICLE_FX_ASSET(call1);
		Vector3 pos = PED::GET_PED_BONE_COORDS(Pped, bone, 0.f, 0.f, 0.f);
		Vector3 rot = { 0, 0, 0 };
		Hooking::network_start_particle_fx_non_looped_at_coord(name, &pos, &rot, fx, 1, 1, 1);
	}
}

void carfade(bool toggle)
{
	Entity e = get_vehicle_ped_is_using(player_ped_id());
	if (toggle && e)
	{
		RGBFade();
		//RequestControlOfEntity(e);
		VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(e, r, g, b);
		VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(e, r, g, b);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(e, r, g, b);
	}
}

float Get3DDistance(Vector3 a, Vector3 b)
{
	float x = pow((a.x - b.x), 2);
	float y = pow((a.y - b.y), 2);
	float z = pow((a.z - b.z), 2);
	return sqrt(x + y + z);
}


void TpToWaypoint()
{
	Vector3 coords = WaypointCoords();

	if (coords.x == 0 && coords.y == 0)
	{
		notifyMap("~r~Waypoint Not Found", 0);
		return;
	}

	Entity e = player_ped_id();
	if (is_ped_in_any_vehicle(e))
	{
		e = get_vehicle_ped_is_using(e);
	}

	bool groundFound = false;
	static float groundCheckHeight[] =
	{ 100.0, 150.0, 50.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0 };
	for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
	{
		Vector3 pos = { coords.x, coords.y, groundCheckHeight[i] };
		set_entity_coords(e, pos, 0, 0, 1);
		//set_entity_coords(e, coords.x, coords.y, groundCheckHeight[i], 0, 0, 1);
		WAIT(100);
		if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(coords.x, coords.y, groundCheckHeight[i], &coords.z, 0))
		{
			groundFound = true;
			coords.z += 3.0;
			break;
		}
	}

	if (!groundFound)
	{
		coords.z = 0;
	}

	TpTo(coords);
}

void TpForward(int dist)
{
	Vector3 coords = get_coords_infront_player(player_id(), dist);

	Entity e = player_ped_id();
	if (is_ped_in_any_vehicle(e))
	{
		e = get_vehicle_ped_is_using(e);
	}

	bool groundFound = false;
	static float groundCheckHeight[] =
	{ 100.0, 150.0, 50.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0 };
	for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
	{
		Vector3 pos = { coords.x, coords.y, groundCheckHeight[i] };
		set_entity_coords(e, pos, 0, 0, 1);
		//set_entity_coords(e, coords.x, coords.y, groundCheckHeight[i], 0, 0, 1);
		WAIT(100);
		if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(coords.x, coords.y, groundCheckHeight[i], &coords.z, 0))
		{
			groundFound = true;
			coords.z += 3.0;
			break;
		}
	}

	if (!groundFound)
	{
		coords.z = 0;
	}

	TpTo(coords);
}

void BoostPlayerVehicle(Ped pedId, int boost, bool isVisible, bool isAudible, float boostSpeed)
{
	int vehicle = get_vehicle_ped_is_using(pedId);
	if (vehicle) {
		Vector3 pos = { 0, boostSpeed, 0 };
		Vector3 rot = { 0, 0, 0 };
		if (boost == 1)// forwaard
			//Hooking::apply_force_to_entity(vehicle, 1, &pos, &rot, 1, 1, 1, 1, 1, 1);
			ENTITY::APPLY_FORCE_TO_ENTITY(vehicle, 1, 0, boostSpeed, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1);
		if (boost == 2)//backward
			ENTITY::APPLY_FORCE_TO_ENTITY(vehicle, 1, 0, -boostSpeed, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1);
		if (boost == 3)//slingshot
			ENTITY::APPLY_FORCE_TO_ENTITY(vehicle, 1, 0, 0, boostSpeed, 0, 0, 0, 1, 1, 1, 1, 1, 1);
		if (boost == 4)//bunnyhop
			ENTITY::APPLY_FORCE_TO_ENTITY(vehicle, 1, 0, 0, boostSpeed, 0, 0, 0, 1, 1, 1, 1, 1, 1);

		if (isVisible)
			GRAPHICS::_START_SCREEN_EFFECT("RaceTurbo", 0, false);
		if (isAudible)
			AUDIO::PLAY_SOUND_FRONTEND(-1, "formation_active", "formation_flying_blips_soundset", false);
	}
	else
		notifyMap("Player Isn't In Any Vehicle.");
}

void rainMoney(int selectedPlayer)
{
	Hash moneyBagHash = 0x9CA6F755;
	if (!Hooking::has_model_loaded(moneyBagHash))
		Hooking::request_model(moneyBagHash);
	else if (timeGetTime() - TimePD3 > moneydelayint) {

		Vector3 coords = get_player_coords(selectedPlayer);
		coords.z += 10; coords.x += 5 - rand() % 10; coords.y += 5 - rand() % 10;

		Hooking::create_ambient_pickup(0xDE78F17E, &coords, 0, moneyvalueint, moneyBagHash, false, true);
		Hooking::set_model_as_no_longer_needed(moneyBagHash);
		TimePD3 = timeGetTime();
	}
}

void clearanim()
{
	Hooking::clear_ped_tasks_immediately(player_ped_id());
}

void doAnimation(char* anim, char* animid)
{
	STREAMING::REQUEST_ANIM_DICT(anim);
	while (!STREAMING::HAS_ANIM_DICT_LOADED((anim))) WAIT(0);
	Hooking::clear_ped_tasks_immediately(player_ped_id());
	Hooking::ai_task_play_anim(player_ped_id(), anim, animid, 8.0f, 0.0f, -1, 1, 0, 0, 0, 0);

}

bool kickPlayer(int selectedPlayer, int type) {
	if (type == -2) { 
		DWORD64 args[3] = { FORCE_TO_NEW_SESSION, selectedPlayer, GlobForNeverWanted(selectedPlayer) };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 3, 1 << selectedPlayer);
	}
	if (type == -1) {	//auto trigger all kicks [>=1]
		if (kickPlayer(selectedPlayer, 0)) notifyMap("host kicked");
		else {
			for (int x = 45; x <= 1; x--) {
				kickPlayer(selectedPlayer, x);
			}
		}
	}
	else if (type == 0) {
		NETWORK::NETWORK_SESSION_KICK_PLAYER(selectedPlayer);
		return true;
	}
	else if (type == 1) {
		DWORD64 args[4] = { KICK_1, selectedPlayer };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 2) {
		DWORD64 args[3] = { KICK_2, selectedPlayer };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 3, 1 << selectedPlayer);
	}
	else if (type == 3) {
		DWORD64 args[4] = { KICK_3, selectedPlayer };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 4) {
		DWORD64 args[5] = { KICK_4, selectedPlayer, 0, 111 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 5, 1 << selectedPlayer);
	}
	else if (type == 5) {
		DWORD64 args[3] = { KICK_5, selectedPlayer };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 3, 1 << selectedPlayer);
	}
	else if (type == 6) {
		DWORD64 args[4] = { KICK_6, selectedPlayer, 50 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 7) {
		DWORD64 args[4] = { KICK_7, selectedPlayer, 20, 1 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 8) {
		DWORD64 args[4] = { KICK_8, selectedPlayer, 20 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 9) {
		DWORD64 args[4] = { KICK_9, selectedPlayer, 20, 1 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 10) {
		DWORD64 args[4] = { KICK_10, selectedPlayer, 20 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 11) {
		DWORD64 args[4] = { KICK_11, selectedPlayer, 20 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 12) {
		DWORD64 args[6] = { KICK_12, selectedPlayer, 0, 0, 0, 36 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 6, 1 << selectedPlayer);
	}
	else if (type == 13) {
		DWORD64 args[3] = { KICK_13, selectedPlayer, 36 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 3, 1 << selectedPlayer);
	}
	else if (type == 14) {
		DWORD64 args[3] = { KICK_14, selectedPlayer, -4294967260/*36*/ };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 3, 1 << selectedPlayer);
	}
	else if (type == 15) {
		DWORD64 args[4] = { KICK_15, selectedPlayer, 32 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 16) {
		DWORD64 args[5] = { KICK_16, selectedPlayer, 0, 0, 32 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 5, 1 << selectedPlayer);
	}
	else if (type == 17) {
		DWORD64 args[5] = { KICK_17, selectedPlayer, 0, 0, 32 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 5, 1 << selectedPlayer);
	}
	else if (type == 18) {
		DWORD64 args[5] = { KICK_18, selectedPlayer, 4 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 5, 1 << selectedPlayer);
	}
	else if (type == 19) {
		DWORD64 args[5] = { KICK_19, selectedPlayer, 7 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 5, 1 << selectedPlayer);
	}
	else if (type == 20) {
		DWORD64 args[6] = { KICK_20, selectedPlayer, 0, 59 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 6, 1 << selectedPlayer);
	}
	else if (type == 21) {
		DWORD64 args[5] = { KICK_21, selectedPlayer, 0, 59 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 5, 1 << selectedPlayer);
	}
	else if (type == 22) {
		DWORD64 args[4] = { KICK_22, selectedPlayer, 0, 59 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 23) {
		DWORD64 args[4] = { KICK_23, selectedPlayer, 62 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 24) {
		DWORD64 args[4] = { KICK_24, selectedPlayer, 0, 26 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 25) {
		DWORD64 args[5] = { KICK_25, selectedPlayer, 0, 26 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 5, 1 << selectedPlayer);
	}
	else if (type == 26) {
		DWORD64 args[4] = { KICK_26, selectedPlayer, 0, 26 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 27) {
		DWORD64 args[3] = { KICK_27, selectedPlayer, 3 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 3, 1 << selectedPlayer);
	}
	else if (type == 28) {
		DWORD64 args[24] = { KICK_28, selectedPlayer, 180 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 24, 1 << selectedPlayer);
	}
	else if (type == 29) {
		DWORD64 args[5] = { KICK_29, selectedPlayer, 64 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 5, 1 << selectedPlayer);
	}
	else if (type == 30) {
		DWORD64 args[3] = { KICK_30, selectedPlayer, 32 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 3, 1 << selectedPlayer);
	}
	else if (type == 31) {
		DWORD64 args[4] = { KICK_31, selectedPlayer, 62 };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 32) {
		DWORD64 args[18] = { KICK_32, selectedPlayer };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 18, 1 << selectedPlayer);
	}
	else if (type == 33) {
		DWORD64 args[3] = { KICK_33, selectedPlayer };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 3, 1 << selectedPlayer);
	}
	else if (type == 34) {
		DWORD64 args[13] = { KICK_34, selectedPlayer, 123 }; //fix
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 13, 1 << selectedPlayer);
	}
	else if (type == 35) {
		DWORD64 args1[4] = { KICK_35, selectedPlayer };
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args1, 4, 1 << selectedPlayer);
	}
	else if (type == 36) {
		DWORD64 args[21];
		*args = KICK_36;
		args[1] = selectedPlayer;
		args[19] = 125;
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 21, 1 << selectedPlayer);
	}
	else if (type == 37) {
	DWORD64 args[4] = { KICK_37, selectedPlayer, 1, 124 };//need check false alarm
	SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 38) {
	DWORD64 args[10] = { KICK_38, selectedPlayer, 1, 10000, 32/*n0*/, 0, 1, 46, 1, 40 };
	SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 10, 1 << selectedPlayer);
	}
	else if (type == 39) {
	DWORD64 args[10] = { KICK_39, selectedPlayer, 1, 10000, 32, 0, 1, 36, 1, 40 };
	SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 10, 1 << selectedPlayer);
	}
	else if (type == 40) {	
	DWORD64 args[25];
	*args = KICK_40, args[1] = selectedPlayer, args[2] = 180;
	args[24] = GlobForNeverWanted(selectedPlayer);
	SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 25, 1 << selectedPlayer);
	}
}

void boostWeapon(int plr, bool punch, bool weapon)
{
	v3 pos;
	Entity ent;
	Hash weaponHash;
	if (Hooking::get_ped_last_weapon_impact(player_ped_id(), &pos)) {
		Hooking::get_current_ped_weapon(get_player_ped(plr), &weaponHash, 1);
		if ((weapon && (weaponHash != 2725352035)) || (punch && (weaponHash == 2725352035))) {
			Hooking::get_entity_player_is_free_aiming_at(plr, &ent);
			if (ent && is_entity(ent))
			{
				float heading = get_entity_heading(get_player_ped(plr));
				Vector3 pos = { 0, 1, 0 };
				Vector3 rot = { 0, 0, 0 };
				if (ENTITY::IS_ENTITY_A_PED(ent) && is_ped_in_any_vehicle(ent)) {
					ent = get_vehicle_ped_is_using(ent);
				}
				RequestControlOfEntity(ent);
				set_entity_heading(ent, heading);
				ENTITY::APPLY_FORCE_TO_ENTITY(ent, 1, 0, 200, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1);
				//Hooking::apply_force_to_entity(ent, 1, &pos, &rot, 1, 1, 1, 1, 0, 1);
			}
		}
	}
}

void buzzardAttack(int selectedPlayer)
{
	Hash weapHashList[4] = { 0x46B89C8E, 0x166218FF, 0xB1CA77B1, 0x42BF8A85 };
	int Pped = get_player_ped(selectedPlayer);
	int model = $("buzzard");
	Hooking::request_model($("buzzard"));
	while (!Hooking::has_model_loaded($("buzzard"))) WAIT(0);
	Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Pped, GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(-50, 50), GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(-50, 50), GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(25, 75));
	int vehattackers = create_vehicle($("buzzard"), coords, 0, 1, 0);
	Hooking::request_model($("s_m_y_blackops_01"));
	while (!Hooking::has_model_loaded($("s_m_y_blackops_01"))) WAIT(0);
	Vector3 Pedcoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Pped, 6.0, 0.0, 0.0);
	for (int x = 0; x < 4; x++) {
		int attackerPed = create_ped(21, $("s_m_y_blackops_01"), Pedcoords.x, Pedcoords.y, Pedcoords.z, 1, 1, 0);
		if (attackerPed)
		{
			PED::SET_PED_INTO_VEHICLE(attackerPed, vehattackers, x - 1);
			AI::TASK_COMBAT_PED(attackerPed, Pped, 0, 0x10);
			Hooking::give_delayed_weapon_to_ped(attackerPed, weapHashList[x], 9999, 1);
			PED::SET_PED_CAN_SWITCH_WEAPON(attackerPed, 1);
			PED::SET_PED_KEEP_TASK(attackerPed, true);
			PED::SET_PED_ALERTNESS(attackerPed, 3);
			if (x == 0) {
				VEHICLE::SET_VEHICLE_DOORS_LOCKED(vehattackers, true);
				VEHICLE::SET_VEHICLE_ENGINE_ON(vehattackers, true, true, true);
				VEHICLE::SET_HELI_BLADES_FULL_SPEED(vehattackers);
				AI::TASK_PLANE_CHASE(attackerPed, Pped, 0, 0, 50);
			}
		}
	}
}

//void boostWeapon(int plr, bool punch, bool weapon)
//{
//	v3 pos;
//	Entity ent;
//	Hash weaponHash;
//	if (Hooking::get_ped_last_weapon_impact(player_ped_id(), &pos)) {
//		Hooking::get_current_ped_weapon(get_player_ped(plr), &weaponHash, 1);
//		if ((weapon && (weaponHash != 2725352035)) || (punch && (weaponHash == 2725352035))) {
//			//Hooking::get_entity_player_is_free_aiming_at(plr, &ent);
//			int ent = VEHICLE::GET_CLOSEST_VEHICLE(pos.x, pos.y, pos.z, 5.0f, 0, 70);
//			if (is_entity(ent))
//			{
//				float heading = get_entity_heading(get_player_ped(plr));
//				Vector3 pos = { 0, 1, 0 };
//				Vector3 rot = { 0, 0, 0 };
//				if (ENTITY::IS_ENTITY_A_PED(ent) && is_ped_in_any_vehicle(ent)) {
//					ent = get_vehicle_ped_is_using(ent);
//				}
//				RequestControlOfEntity(ent);
//				set_entity_heading(ent, heading);
//				ENTITY::APPLY_FORCE_TO_ENTITY(ent, 1, 0, 200, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1);
//				//Hooking::apply_force_to_entity(ent, 1, &pos, &rot, 1, 1, 1, 1, 0, 1);
//			}
//		}
//	}
//}

void TPWeapon()
{
	v3 pos;
	if (Hooking::get_ped_last_weapon_impact(player_ped_id(), &pos))
	{
		TpTo(v3ToVector3(pos));
	}
}

void airStrikeGun()
{
	int playerPed = 0;
	v3 coords;
	if (Hooking::get_ped_last_weapon_impact(player_ped_id(), &coords))
	{
		coords = v3ToVector3(coords);
		Hash airStrike = $("WEAPON_AIRSTRIKE_ROCKET");
		WEAPON::REQUEST_WEAPON_ASSET(airStrike, 31, false);
		while (!WEAPON::HAS_WEAPON_ASSET_LOADED(airStrike))
			WAIT(0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x, coords.y, coords.z + 30.f, coords.x, coords.y, coords.z, 250, 1, airStrike, playerPed, 1, 0, 0xbf800000);
	}
}

void drawstring(char* text, float X, float Y) {}

bool SpeedoBool = false;
bool MPH = true;
bool PlateMPH = true;
void Speedometer()
{
	float speed = ENTITY::GET_ENTITY_SPEED(get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID())) * 3.6f;

	if (MPH)
		speed = speed * .621f;
	char msg[0xFF];
	if (MPH)
	{
		sprintf_s(msg, "%i", (int)speed);
	}
	else
	{
		sprintf_s(msg, "%i", (int)speed);
	}
	drawstring(msg, .50f, .05f);
	if (PlateMPH)
	{
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), msg);
	}
}

void stealOutfit()
{

	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Ped theirPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);

	for (int i = 0; i < 12; i++)
	{
		PED::SET_PED_COMPONENT_VARIATION(playerPed, i, PED::GET_PED_DRAWABLE_VARIATION(theirPed, i),
			PED::GET_PED_TEXTURE_VARIATION(theirPed, i),
			PED::GET_PED_PALETTE_VARIATION(theirPed, i));
		for (int i = 0; i < 2; i++)
		{
			WAIT(0);
		}
	}
}

bool SV = false;
void sv(bool toggle)
{

	auto playerPed = PLAYER::PLAYER_PED_ID();
	static bool start_supervis;
	float s = std::distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(playerPed, true)) + 5.25;
	auto h = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerPed, PED::GET_PED_BONE_INDEX(playerPed, SKEL_Head));
	float end = std::distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true)) + 1000.0;
	if (PED::IS_PED_ON_FOOT(playerPed) && IsKeyPressed(VK_LBUTTON))
	{
		if (start_supervis) {
			Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
			start_supervis = false;
		}
		WEAPON::SET_CURRENT_PED_WEAPON(playerPed, $("WEAPON_UNARMED"), 1);
		ENTITY::SET_ENTITY_ROTATION(playerPed, 0, 0, CAM::GET_GAMEPLAY_CAM_ROT(0).z, 1, true);

		auto war = $("WEAPON_RAILGUN");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(war))
		{
			WEAPON::REQUEST_WEAPON_ASSET(war, 31, false);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(war))
				WAIT(0);
		}
		Vector3 startCoords = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), s));
		Vector3 endCoords = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), end));
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(startCoords.x, startCoords.y, startCoords.z, endCoords.x, endCoords.y, endCoords.z, 250, 1, war, playerPed, 1, 0, -1.0);
		Hooking::give_delayed_weapon_to_ped(playerPed, war, 1, 0);
		auto camrot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		auto camdir = rot_to_direction(&camrot);
		Vector3 start = ENTITY::GET_ENTITY_COORDS(WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID()), 1);

		Vector3 end = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&camdir, 10.f));
		if (does_entity_exist(WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID())) && CONTROLS::IS_CONTROL_PRESSED(2, INPUT_AIM))
			Hooking::draw_line(&start, &end, 255, 0, 0, 255);
	}
	else {
		start_supervis = true;
	}


}

/*void CageAll()
{
		for (int i = 0; i < 32; i++)
		{


			Player playerHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			Hash crashall = $("v_proc2_temp");
			Hooking::request_model(crashall);
			while (!Hooking::has_model_loaded(crashall)) WAIT(0);
			if (does_entity_exist(playerHandle))
			{
				if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID()) continue;
				{
					Object crashall2 = create_object(crashall, 0, 0, 0, true, true, false);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(crashall2, playerHandle, PED::GET_PED_BONE_INDEX(playerHandle, SKEL_Spine_Root), 0.0, 0.0, 0.0, 0.0, 90.0, 0, false, false, false, false, 2, true);
				}
				Hooking::set_model_as_no_longer_needed(crashall);

			}
		}
}*/

bool antiReport;
bool antiKick;
bool antiFreeze;
bool antiAttachment;
bool antiExplosion;
bool antiSound;
bool antiStars;
bool antiStats;

void AntiReport(bool t) {
	//Hooking::defuseEvent(PLAYER_CARD_STAT_EVENT, t);
	Hooking::defuseEvent(REPORT_MYSELF_EVENT, t);
	Hooking::defuseEvent(REPORT_CASH_SPAWN_EVENT, t);
}
void AntiKick(bool t) {
	//Hooking::defuseEvent(REMOTE_SCRIPT_LEAVE_EVENT, t);
	Hooking::defuseEvent(KICK_VOTES_EVENT, t);
	globalHandle(1377446).At(594).As<int>() = 594; //SP kick
	globalHandle(1377446).At(595).As<int>() = 595; //kick
	globalHandle(1382674).At(584).As<int>() = 584;
}
void AntiFreeze(bool t) {
	Hooking::defuseEvent(RAGDOLL_REQUEST_EVENT, t);
	Hooking::defuseEvent(INCIDENT_ENTITY_EVENT, t);
	Hooking::defuseEvent(CLEAR_AREA_EVENT, t);
	Hooking::defuseEvent(CLEAR_RECTANGLE_AREA_EVENT, t);
	Hooking::defuseEvent(NETWORK_CLEAR_PED_TASKS_EVENT, t);
	Hooking::defuseEvent(NETWORK_SOUND_CAR_HORN_EVENT, t);
	Hooking::defuseEvent(NETWORK_PLAY_SOUND_EVENT, t);
	Hooking::defuseEvent(NETWORK_STOP_SOUND_EVENT, t);
	Hooking::defuseEvent(NETWORK_PLAY_AIRDEFENSE_FIRE_EVENT, t);
}
void AntiAttachment(bool t) {
	Hooking::defuseEvent(REQUEST_DETACHMENT_EVENT, t);
	char* objects[136] = { "prop_bskball_01", "PROP_MP_RAMP_03", "PROP_MP_RAMP_02", "PROP_MP_RAMP_01", "PROP_JETSKI_RAMP_01", "PROP_WATER_RAMP_03", "PROP_VEND_SNAK_01", "PROP_TRI_START_BANNER", "PROP_TRI_FINISH_BANNER", "PROP_TEMP_BLOCK_BLOCKER", "PROP_SLUICEGATEL", "PROP_SKIP_08A", "PROP_SAM_01", "PROP_RUB_CONT_01B", "PROP_ROADCONE01A", "PROP_MP_ARROW_BARRIER_01", "PROP_HOTEL_CLOCK_01", "PROP_LIFEBLURB_02", "PROP_COFFIN_02B", "PROP_MP_NUM_1", "PROP_MP_NUM_2", "PROP_MP_NUM_3", "PROP_MP_NUM_4", "PROP_MP_NUM_5", "PROP_MP_NUM_6", "PROP_MP_NUM_7", "PROP_MP_NUM_8", "PROP_MP_NUM_9", "prop_xmas_tree_int", "prop_bumper_car_01", "prop_beer_neon_01", "prop_space_rifle", "prop_dummy_01", "prop_rub_trolley01a", "prop_wheelchair_01_s", "PROP_CS_KATANA_01", "PROP_CS_DILDO_01", "prop_armchair_01", "prop_bin_04a", "prop_chair_01a", "prop_dog_cage_01", "prop_dummy_plane", "prop_golf_bag_01", "prop_arcade_01", "hei_prop_heist_emp", "prop_alien_egg_01", "prop_air_towbar_01", "hei_prop_heist_tug", "prop_air_luggtrolley", "PROP_CUP_SAUCER_01", "prop_wheelchair_01", "prop_ld_toilet_01", "prop_acc_guitar_01", "prop_bank_vaultdoor", "p_v_43_safe_s", "p_spinning_anus_s", "prop_can_canoe", "prop_air_woodsteps", "Prop_weed_01", "prop_a_trailer_door_01", "prop_apple_box_01", "prop_air_fueltrail1", "prop_barrel_02a", "prop_barrel_float_1", "prop_barrier_wat_03b", "prop_air_fueltrail2", "prop_air_propeller01", "prop_windmill_01", "prop_Ld_ferris_wheel", "p_tram_crash_s", "p_oil_slick_01", "p_ld_stinger_s", "p_ld_soc_ball_01", "prop_juicestand", "p_oil_pjack_01_s", "prop_barbell_01", "prop_barbell_100kg", "p_parachute1_s", "p_cablecar_s", "prop_beach_fire", "prop_lev_des_barge_02", "prop_lev_des_barge_01", "prop_a_base_bars_01", "prop_beach_bars_01", "prop_air_bigradar", "prop_weed_pallet", "prop_artifact_01", "prop_attache_case_01", "prop_large_gold", "prop_roller_car_01", "prop_water_corpse_01", "prop_water_corpse_02", "prop_dummy_01", "prop_atm_01", "hei_prop_carrier_docklight_01", "hei_prop_carrier_liferafts", "hei_prop_carrier_ord_03", "hei_prop_carrier_defense_02", "hei_prop_carrier_defense_01", "hei_prop_carrier_radar_1", "hei_prop_carrier_radar_2", "hei_prop_hei_bust_01", "hei_prop_wall_alarm_on", "hei_prop_wall_light_10a_cr", "prop_afsign_amun", "prop_afsign_vbike", "prop_aircon_l_01", "prop_aircon_l_02", "prop_aircon_l_03", "prop_aircon_l_04", "prop_airhockey_01", "prop_air_bagloader", "prop_air_blastfence_01", "prop_air_blastfence_02", "prop_air_cargo_01a", "prop_air_chock_01", "prop_air_chock_03", "prop_air_gasbogey_01", "prop_air_generator_03", "prop_air_stair_02", "prop_amb_40oz_02", "prop_amb_40oz_03", "prop_amb_beer_bottle", "prop_amb_donut", "prop_amb_handbag_01", "prop_amp_01", "prop_anim_cash_pile_02", "prop_asteroid_01", "prop_arm_wrestle_01", "prop_ballistic_shield", "prop_bank_shutter", "prop_barier_conc_02b", "prop_barier_conc_05a", "prop_barrel_01a", "prop_bar_stool_01", "prop_basejump_target_01" };
	for (int i = 0; i < 5; i++) {
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		GAMEPLAY::CLEAR_AREA_OF_PEDS(coords.x, coords.y, coords.z, 2, 0);
		GAMEPLAY::CLEAR_AREA_OF_OBJECTS(coords.x, coords.y, coords.z, 2, 0);
		GAMEPLAY::CLEAR_AREA_OF_VEHICLES(coords.x, coords.y, coords.z, 2, 0, 0, 0, 0, 0);
		for (int i = 0; i < 136; i++) {
			Object obj = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(coords.x, coords.y, coords.z, 4.0, $(objects[i]), 0, 0, 1);

			if (does_entity_exist(obj) && ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(obj, PLAYER::PLAYER_PED_ID())) {
				RequestControlOfEntity(obj);
				int netID = Hooking::network_get_network_id_from_entity(obj);
				Hooking::set_network_id_can_migrate(netID, 1);
				ENTITY::DETACH_ENTITY(obj, 1, 1);
				if (Hooking::network_has_control_of_entity(obj)) {
					ENTITY::SET_ENTITY_AS_MISSION_ENTITY(obj, 1, 1);
					ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&obj);
					ENTITY::DELETE_ENTITY(&obj);
				}
			}
		}
	}
}

void customBullets(int type)
{
	Ped PedID = player_ped_id();
	v3 pos;
	Hooking::get_ped_last_weapon_impact(PedID, &pos);
	Ped player = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_PED_ID());
	FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z, type, 5.f, true, false, 0.f);
}

void AntiExplosion(bool t) {
	Hooking::defuseEvent(FIRE_EVENT, t);
	Hooking::defuseEvent(EXPLOSION_EVENT, t);
	Hooking::defuseEvent(REQUEST_PHONE_EXPLOSION_EVENT, t);
	Hooking::defuseEvent(BLOW_UP_VEHICLE_EVENT, t);
}
void AntiSound(bool t) {
	Hooking::defuseEvent(NETWORK_SOUND_CAR_HORN_EVENT, t);
	Hooking::defuseEvent(NETWORK_PLAY_SOUND_EVENT, t);
	Hooking::defuseEvent(NETWORK_STOP_SOUND_EVENT, t);
	Hooking::defuseEvent(NETWORK_PLAY_AIRDEFENSE_FIRE_EVENT, t);
}
void AntiStars(bool t) {
	Hooking::defuseEvent(ALTER_WANTED_LEVEL_EVENT, t);
}
void AntiStat(bool t) {
	Hooking::defuseEvent(NETWORK_BANK_REQUEST_EVENT, t);
	Hooking::defuseEvent(NETWORK_INCREMENT_STAT_EVENT, t);
}

void changemod(int type, int index)
{
	Vehicle veh = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
	if (index == -1)
	{
		VEHICLE::REMOVE_VEHICLE_MOD(veh, type);
	}
	else
	{
		Hooking::set_vehicle_mod(veh, type, index, false);
	}
}

bool DriveWater = false;
void driveWater(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	DWORD model = ENTITY::GET_ENTITY_MODEL(veh);
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
	float height = 0;
	WATER::_SET_WAVES_INTENSITY(height);
	if ((!(VEHICLE::IS_THIS_MODEL_A_PLANE(ENTITY::GET_ENTITY_MODEL(veh)))) && WATER::GET_WATER_HEIGHT_NO_WAVES(pos.x, pos.y, pos.z, &height)) {
		Object container = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(pos.x, pos.y, pos.z, 4.0, $("prop_container_ld2"), 0, 0, 1);
		if (does_entity_exist(container) && height > -50.0f) {
			Vector3 pRot = ENTITY::GET_ENTITY_ROTATION(playerPed, 0);
			if (is_ped_in_any_vehicle(playerPed)) pRot = ENTITY::GET_ENTITY_ROTATION(veh, 0);
			RequestControlOfEntity(container);
			set_entity_coords(container, pos.x, pos.y, height - 1.5f, 0, 0, 0);
			ENTITY::SET_ENTITY_ROTATION(container, 0, 0, pRot.z, 0, 1);
			Vector3 containerCoords = ENTITY::GET_ENTITY_COORDS(container, 1);
			if (pos.z < containerCoords.z) {
				if (!is_ped_in_any_vehicle(playerPed)) {
					set_entity_coords(playerPed, pos.x, pos.y, containerCoords.z + 2.0f, 0, 0, 0);
				}
				else {
					RequestControlOfEntity(veh);
					Vector3 vehc = ENTITY::GET_ENTITY_COORDS(veh, 1);
					set_entity_coords(veh, vehc.x, vehc.y, containerCoords.z + 2.0f, 0, 0, 0);
				}
			}
		}
		else {
			Hash model = $("prop_container_ld2");
			Hooking::request_model(model);
			while (!Hooking::has_model_loaded(model)) WAIT(0);
			container = create_object(model, pos.x, pos.y, pos.z, 1, 1, 0);
			RequestControlOfEntity(container);
			ENTITY::FREEZE_ENTITY_POSITION(container, 1);
			ENTITY::SET_ENTITY_ALPHA(container, 0, 1);
			ENTITY::SET_ENTITY_VISIBLE(container, 0, 0);
		}
	}
	else {
		Object container = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(pos.x, pos.y, pos.z, 4.0, $("prop_container_ld2"), 0, 0, 1);
		if (does_entity_exist(container)) {
			RequestControlOfEntity(container);
			set_entity_coords(container, 0, 0, -1000.0f, 0, 0, 0);
			WAIT(10);
			ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&container);
			ENTITY::DELETE_ENTITY(&container);
			WATER::_RESET_CURRENT_INTENSITY(); //_RESET_WAVES_INTENSITY();
		}
	}
}

vector<Vehicle> lastSeenVehicles;
int TimeDelayUpdateVEHS;
bool UpgradeVehicles;
inline void update_nearby_vehicles(Ped playerPed, int count)
{
	const int numElements = count;
	const int arrSize = numElements * 2 + 2;

	Vehicle* vehs = new Vehicle[arrSize];
	vehs[0] = numElements;
	int found = PED::GET_PED_NEARBY_VEHICLES(playerPed, vehs);

	for (int i = 0; i < found; i++)
	{
		int offsettedID = i * 2 + 2;

		if (!does_entity_exist(vehs[offsettedID]))
		{
			continue;
		}

		Vehicle xveh = vehs[offsettedID];
		lastSeenVehicles.push_back(vehs[offsettedID]);
	}
	delete vehs;
}

bool grav_target_locked = false;
bool GravityGun = false;
void gravityGun(bool toggle)
{
	Entity EntityTarget;
	DWORD equippedWeapon;
	Hooking::get_current_ped_weapon(PLAYER::PLAYER_PED_ID(), &equippedWeapon, 1);
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	Vector3 rot;
	Hooking::get_gameplay_cam_rot(&rot, 2);
	Vector3 dir = RotationToDirection(rot);
	Vector3 camPosition;
	Hooking::get_gameplay_cam_coord(&camPosition);
	Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	float spawnDistance = get_distance(&camPosition, &playerPosition);
	spawnDistance += 6;
	Vector3 spawnPosition = add(&camPosition, &multiply(&dir, spawnDistance));


	Player tempPed = PLAYER::PLAYER_ID();

	if (grav_target_locked) //  FIXED, it is, it's using detected natives ok can you find other native for it? No, because only this one is working for it, you need to find signature for it.
	{
		if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget) && GetAsyncKeyState(VK_RBUTTON))
		{
			Vector3 EntityTargetPos = ENTITY::GET_ENTITY_COORDS(EntityTarget, 0);
			PLAYER::DISABLE_PLAYER_FIRING(tempPed, true);
			if (ENTITY::IS_ENTITY_A_PED(EntityTarget) &&is_ped_in_any_vehicle(EntityTarget))
			{
				EntityTarget = PED::GET_VEHICLE_PED_IS_IN(EntityTarget, 0);
			}

			RequestControlOfEntity(EntityTarget);

			if (ENTITY::IS_ENTITY_A_VEHICLE(EntityTarget))
				ENTITY::SET_ENTITY_HEADING(
					EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));

			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(EntityTarget, spawnPosition.x, spawnPosition.y, spawnPosition.z, 0, 0, 0);

			if (GetAsyncKeyState(VK_LBUTTON))
			{
				ENTITY::SET_ENTITY_HEADING(EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));
				ENTITY::APPLY_FORCE_TO_ENTITY(EntityTarget, 1, dir.x * 10000.0f, dir.y * 10000.0f, dir.z * 10000.0f, 0.0f, 0.0f,
					0.0f, 0, 0, 1, 1, 0, 1);
				grav_target_locked = false;
				PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
			}
		}
	}
	if (!PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
	{
		grav_target_locked = true;
		PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
	}

}

void playerinfo() {
	
		Player player = selectedPlayer;
		Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);

		char* rockstarID;
		int NETWORK_HANDLE[76];
		NETWORK::NETWORK_HANDLE_FROM_PLAYER(player, &NETWORK_HANDLE[0], 13);
		if (NETWORK::NETWORK_IS_HANDLE_VALID(&NETWORK_HANDLE[0], 13)) {
			rockstarID = NETWORK::NETWORK_MEMBER_ID_FROM_GAMER_HANDLE(&NETWORK_HANDLE[0]);
		}
		else {
			rockstarID = "~r~Unknown";
		}
		char* name = PLAYER::GET_PLAYER_NAME(player);
		int money = globalHandle(1589819).At(player, 818).At(211).At(3).As<int>();
		int rp = globalHandle(1589819).At(player, 818).At(211).At(5).As<int>();
		int earnings = globalHandle(1589819).At(player, 818).At(211).At(56).As<int>();
		int rank = globalHandle(1589819).At(player, 818).At(211).At(6).As<int>();
		int kills = globalHandle(1589819).At(player, 818).At(211).At(28).As<int>();
		int handle = globalHandle(1589819).At(player, 818).At(211).At(56).As<int>();
		int handle2 = globalHandle(1589819).At(player, 818).At(211).At(3).As<int>();
		int bankMoney = handle - 10 - handle2 + (5 * 1 + 3 + 2);
		int deaths = globalHandle(1589819).At(player, 818).At(211).At(29).As<int>();
		int tempMoney = globalHandle(1589819).At(player, 818).At(211).At(3).As<int>();
		int death = globalHandle(1589819).At(player, 818).At(211).At(20).As<int>();
		int deathlost = globalHandle(1589819).At(player, 818).At(211).At(21).As<int>();
		int races = globalHandle(1589819).At(player, 818).At(211).At(15).As<int>();
		int raceslost = globalHandle(1589819).At(player, 818).At(211).At(16).As<int>();
		float kd = globalHandle(1589819).At(player, 818).At(211).At(26).As<float>();  // so i use for stealth money the transactions globals from benny garage , after used stealth benny garage not work anymorehm can i look?
		ostringstream Money, RP, Rank, Kills, Deaths, KD, Earnings, Money1, Moneybank, Golf, EXP, Races, Raceslost, Miss, Death, Deathlost, ridkek, Name;
		//ostringstream ridkek; ridkek << "Rockstar ID:~s~ " << rockstarID;

		Vector3 __coords = ENTITY::GET_ENTITY_COORDS(ped, 0);
		char buf[0x80]; snprintf(buf, sizeof(buf), "X: ~g~%f", __coords.x);
		char buf1[0x80]; snprintf(buf1, sizeof(buf1), "~s~Y: ~g~%f", __coords.y);
		char buf2[0x80]; snprintf(buf2, sizeof(buf2), "~s~Z: ~g~%f", __coords.z);

		string money2 = to_string(tempMoney);
		int insertPosition = money2.length() - 3;
		while (insertPosition > 0) {
			money2.insert(insertPosition, ",");
			insertPosition -= 3;
		}



		if (!NETWORK::NETWORK_IS_PLAYER_CONNECTED(player)) {
			Name << "~W~Name: ~s~ N/A";
			Money << "~w~Cash:~s~ N/A";
			Money1 << "~w~Cash:~s~ $";
			Moneybank << "~w~Bank Cash:~s~ $";
			RP << "~w~RP:~s~ N/A";
			Rank << "~w~Rank:~s~ N/A";
			Kills << "~w~Kills:~s~ N/A";
			Deaths << "~w~Deaths:~s~ N/A";
			KD << "~w~KD Ratio:~s~ N/A";
			Earnings << "~w~Total Earnings:~s~ N/A";
			Races << "~w~Total Races Won:~s~~b~ N/A";
			Raceslost << "~w~Total Races Lost:~s~~b~ N/A";
			Death << "~w~Total Deathmatch Won:~s~~b~ N/A";
			Deathlost << "~w~Total Deathmatch Lost:~s~~b~ N/A";
			ridkek << "~w~R ID:~s~~b~ N/A";
			//  //__ipbuf << "~w~ IP::~s~ N/A";
			// 
		}
		else {
			Name << "~w~Name: ~s~~r~" << name;
			Money << "~w~Cash:~s~ $" << money;
			Money1 << "~w~Cash:~s~ $" << money2;
			Moneybank << "~w~Bank Cash:~s~ $" << bankMoney;
			RP << "~w~RP:~s~ " << rp;
			Rank << "~w~Rank:~s~ " << rank;
			Kills << "~w~Kills:~s~ " << kills;
			Deaths << "~w~Deaths:~s~ " << deaths;
			KD << "~w~KD Ratio:~s~ " << kd;
			Earnings << "~t~Total Earnings:~s~ $" << earnings;
			Races << "~w~Total Races Won:~s~~b~ " << races;
			Raceslost << "~w~Total Races Lost:~s~~b~" << raceslost;
			Death << "~w~Total Deathmatch Won:~s~~b~" << death;
			Deathlost << "~w~Total Deathmatch Lost:~s~~b~" << deathlost;
			ridkek << "~w~R ID:~s~~b~" << rockstarID;
			//ostringstream ridkek; ridkek << "Rockstar ID:~s~ " << rockstarID;

		}



		float health = ENTITY::GET_ENTITY_HEALTH(ped);
		float maxHealth = ENTITY::GET_ENTITY_MAX_HEALTH(ped);
		float healthPercent = health * 100 / maxHealth;
		ostringstream Health; Health << "Health:~s~ " << healthPercent;
		float armor = PED::GET_PED_ARMOUR(ped);
		float maxArmor = PLAYER::GET_PLAYER_MAX_ARMOUR(player);
		float armorPercent = armor * 100 / maxArmor;
		ostringstream Armor; Armor << "Armor:~s~ " << armorPercent;
		bool alive = !is_player_dead(selectedPlayer);
		char* aliveStatus;
		if (alive) aliveStatus = "Yes"; else aliveStatus = "No";
		ostringstream Alive; Alive << "Alive:~s~ " << aliveStatus;
		bool inVehicle = is_ped_in_any_vehicle(ped);
		ostringstream VehicleModel; VehicleModel << "Vehicle:~s~ ";
		ostringstream Speed; Speed << "Speed:~s~ ";
		ostringstream IsInAVehicle; IsInAVehicle << "In Vehicle:~s~ ";
		if (inVehicle) {
			IsInAVehicle << "Yes";
			Hash vehHash = ENTITY::GET_ENTITY_MODEL(PED::GET_VEHICLE_PED_IS_IN(ped, 0));
			VehicleModel << UI::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(vehHash));
			float vehSpeed = ENTITY::GET_ENTITY_SPEED(PED::GET_VEHICLE_PED_IS_IN(ped, 0));
			float vehSpeedConverted;
			vehSpeedConverted = round(vehSpeed * 1.6);
			Speed << vehSpeedConverted << " KM/H";
		}
		else {
			IsInAVehicle << "No";
			float speed = round(ENTITY::GET_ENTITY_SPEED(ped) * 100) / 100;
			Speed << speed << " M/S";
			VehicleModel << "--------";
		}

		ostringstream WantedLevel; WantedLevel << "Wanted Level:~s~ " << PLAYER::GET_PLAYER_WANTED_LEVEL(player);
		ostringstream Weapon; Weapon << "Weapon: ~s~";
		Hash weaponHash;
		if (Hooking::get_current_ped_weapon(ped, &weaponHash, 1)) {
			char* weaponName;
			if (weaponHash == 2725352035) {
				weaponName = "Unarmed";
			}
			else if (weaponHash == 2578778090) {
				weaponName = "Knife";
			}
			else if (weaponHash == 0x678B81B1) {
				weaponName = "Nightstick";
			}
			else if (weaponHash == 0x4E875F73) {
				weaponName = "Hammer";
			}
			else if (weaponHash == 0x958A4A8F) {
				weaponName = "Bat";
			}
			else if (weaponHash == 0x440E4788) {
				weaponName = "GolfClub";
			}
			else if (weaponHash == 0x84BD7BFD) {
				weaponName = "Crowbar";
			}
			else if (weaponHash == 0x1B06D571) {
				weaponName = "Pistol";
			}
			else if (weaponHash == 0x5EF9FEC4) {
				weaponName = "Combat Pistol";
			}
			else if (weaponHash == 0x22D8FE39) {
				weaponName = "AP Pistol";
			}
			else if (weaponHash == 0x99AEEB3B) {
				weaponName = "Pistol 50";
			}
			else if (weaponHash == 0x13532244) {
				weaponName = "Micro SMG";
			}
			else if (weaponHash == 0x2BE6766B) {
				weaponName = "SMG";
			}
			else if (weaponHash == 0xEFE7E2DF) {
				weaponName = "Assault SMG";
			}
			else if (weaponHash == 0xBFEFFF6D) {
				weaponName = "Assault Riffle";
			}
			else if (weaponHash == 0x83BF0278) {
				weaponName = "Carbine Riffle";
			}
			else if (weaponHash == 0xAF113F99) {
				weaponName = "Advanced Riffle";
			}
			else if (weaponHash == 0x9D07F764) {
				weaponName = "MG";
			}
			else if (weaponHash == 0x7FD62962) {
				weaponName = "Combat MG";
			}
			else if (weaponHash == 0x1D073A89) {
				weaponName = "Pump Shotgun";
			}
			else if (weaponHash == 0x7846A318) {
				weaponName = "Sawed-Off Shotgun";
			}
			else if (weaponHash == 0xE284C527) {
				weaponName = "Assault Shotgun";
			}
			else if (weaponHash == 0x9D61E50F) {
				weaponName = "Bullpup Shotgun";
			}
			else if (weaponHash == 0x3656C8C1) {
				weaponName = "Stun Gun";
			}
			else if (weaponHash == 0x05FC3C11) {
				weaponName = "Sniper Rifle";
			}
			else if (weaponHash == 0x0C472FE2) {
				weaponName = "Heavy Sniper";
			}
			else if (weaponHash == 0xA284510B) {
				weaponName = "Grenade Launcher";
			}
			else if (weaponHash == 0x4DD2DC56) {
				weaponName = "Smoke Grenade Launcher";
			}
			else if (weaponHash == 0xB1CA77B1) {
				weaponName = "RPG";
			}
			else if (weaponHash == 0x42BF8A85) {
				weaponName = "Minigun";
			}
			else if (weaponHash == 0x93E220BD) {
				weaponName = "Grenade";
			}
			else if (weaponHash == 0x2C3731D9) {
				weaponName = "Sticky Bomb";
			}
			else if (weaponHash == 0xFDBC8A50) {
				weaponName = "Smoke Grenade";
			}
			else if (weaponHash == 0xA0973D5E) {
				weaponName = "BZGas";
			}
			else if (weaponHash == 0x24B17070) {
				weaponName = "Molotov";
			}
			else if (weaponHash == 0x060EC506) {
				weaponName = "Fire Extinguisher";
			}
			else if (weaponHash == 0x34A67B97) {
				weaponName = "Petrol Can";
			}
			else if (weaponHash == 0xFDBADCED) {
				weaponName = "Digital scanner";
			}
			else if (weaponHash == 0x88C78EB7) {
				weaponName = "Briefcase";
			}
			else if (weaponHash == 0x23C9F95C) {
				weaponName = "Ball";
			}
			else if (weaponHash == 0x497FACC3) {
				weaponName = "Flare";
			}
			else if (weaponHash == 0xF9E6AA4B) {
				weaponName = "Bottle";
			}
			else if (weaponHash == 0x61012683) {
				weaponName = "Gusenberg";
			}
			else if (weaponHash == 0xC0A3098D) {
				weaponName = "Special Carabine";
			}
			else if (weaponHash == 0xD205520E) {
				weaponName = "Heavy Pistol";
			}
			else if (weaponHash == 0xBFD21232) {
				weaponName = "SNS Pistol";
			}
			else if (weaponHash == 0x7F229F94) {
				weaponName = "Bullpup Rifle";
			}
			else if (weaponHash == 0x92A27487) {
				weaponName = "Dagger";
			}
			else if (weaponHash == 0x083839C4) {
				weaponName = "Vintage Pistol";
			}
			else if (weaponHash == 0x7F7497E5) {
				weaponName = "Firework";
			}
			else if (weaponHash == 0xA89CB99E) {
				weaponName = "Musket";
			}
			else if (weaponHash == 0x3AABBBAA) {
				weaponName = "Heavy Shotgun";
			}
			else if (weaponHash == 0xC734385A) {
				weaponName = "Marksman Rifle";
			}
			else if (weaponHash == 0x63AB0442) {
				weaponName = "Homing Launcher";
			}
			else if (weaponHash == 0xAB564B93) {
				weaponName = "Proximity Mine";
			}
			else if (weaponHash == 0x787F0BB) {
				weaponName = "Snowball";
			}
			else if (weaponHash == 0x47757124) {
				weaponName = "Flare Gun";
			}
			else if (weaponHash == 0xE232C28C) {
				weaponName = "Garbage Bag";
			}
			else if (weaponHash == 0xD04C944D) {
				weaponName = "Handcuffs";
			}
			else if (weaponHash == 0x0A3D4D34) {
				weaponName = "Combat PDW";
			}
			else if (weaponHash == 0xDC4DB296) {
				weaponName = "Marksman Pistol";
			}
			else if (weaponHash == 0xD8DF3C3C) {
				weaponName = "Brass Knuckles";
			}
			else if (weaponHash == 0x6D544C99) {
				weaponName = "Railgun";
			}
			else {
				weaponName = "Unarmed";
			}
			Weapon << weaponName;


		}
		else Weapon << "Unarmed";

		Vector3 coords = ENTITY::GET_ENTITY_COORDS(ped, 1);
		ostringstream Zone; Zone << "Zone: ~s~" << UI::_GET_LABEL_TEXT(ZONE::GET_NAME_OF_ZONE(coords.x, coords.y, coords.z));

		char ipBuf[32] = {};
		static auto nigNog = (std::uintptr_t(*)(int))(Memory::pattern("40 53 48 83 EC 20 33 DB 38 1D ? ? ? ? 74 1C").count(1).get(0).get<void>(0));
		auto nigger = nigNog(player);



		if (!NETWORK::NETWORK_IS_PLAYER_CONNECTED(player)) {

			for (int i = 0; i < 3; i++)
			{
				if (nigger)
				{
					auto faggot = *(uintptr_t*)(nigger + 0x10b8);
					if (faggot)
					{


						auto ip = (BYTE*)(faggot + 0x44);
						std::snprintf(ipBuf, sizeof(ipBuf) - 1, "~r~IP: ~s~Hide", i);

					}
				}

			}

		}
		else {

			if (nigger)
			{
				auto faggot = *(uintptr_t*)(nigger + 0x10b8);
				if (faggot)
				{
					auto ip = (BYTE*)(faggot + 0x44);
					std::snprintf(ipBuf, sizeof(ipBuf) - 1, "~r~IP: %u.%u.%u.%u", ip[3], ip[2], ip[1], *ip);

				}
			}

		}
		std::string isModder = "~r~No";

		//DWORD playerPtr = Hooking::get_player_address(player);
		//bool is_in_godmode = Memory::get_value<bool>({ playerPtr, 0x189 });

		//if (isPlayerModder(player)) {
		//	isModder = "~g~Yes";
		//}
		//else {
		//	isModder = "~r~No";
		//}
		ostringstream NigNog; NigNog << "Modder: ~s~ " << isModder;
		Menu::AddSmallInfo((char*)Deaths.str().c_str(), 0);
		Menu::AddSmallInfo((char*)KD.str().c_str(), 1);
		Menu::AddSmallInfo(ipBuf, 2);
		Menu::AddSmallInfo(buf, 3);
		Menu::AddSmallInfo(buf1, 4);
		Menu::AddSmallInfo(buf2, 5);
		Menu::AddSmallInfo((char*)Earnings.str().c_str(), 6);
		//Menu::AddSmallInfo((char*)Money1.str().c_str(), 7);
		Menu::AddSmallInfo((char*)Death.str().c_str(), 7);
		Menu::AddSmallInfo((char*)Deathlost.str().c_str(), 8);
		Menu::AddSmallInfo((char*)Races.str().c_str(), 9);
		Menu::AddSmallInfo((char*)ridkek.str().c_str(), 10);
		Menu::AddSmallInfo((char*)NigNog.str().c_str(), 11);

}

bool flyPlayerBool;
void flyPlayer()
{
	Hash hash = $("GADGET_PARACHUTE");

	PLAYER::SET_PLAYER_INVINCIBLE(PLAYER::PLAYER_ID(), true);
	Hooking::give_delayed_weapon_to_ped(player_ped_id(), hash, 1, 1);
	PED::SET_PED_TO_RAGDOLL_WITH_FALL(PLAYER::PLAYER_PED_ID(), 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);

	if (ENTITY::IS_ENTITY_IN_AIR(PLAYER::PLAYER_PED_ID()) && !PED::IS_PED_RAGDOLL(PLAYER::PLAYER_PED_ID()))
	{
		if (GetAsyncKeyState(0x53)) // S key
		{
			ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 3, 0, 0);
		}
		if (GetAsyncKeyState(0x57)) // W key
		{
			ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 3, 6, 0);
		}
		if (GetAsyncKeyState(VK_SHIFT)) //VK_SHIFT
		{
			ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 6, 0, 0);
		}
		if (GetAsyncKeyState(VK_SPACE)) //Space Key
		{
			ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 9, 9, 9);
		}
	}
}

bool RapidFire = false;
void rapidfire(bool toggle)
{
	Player playerPed = player_ped_id();
	if (!is_ped_in_any_vehicle(playerPed)) {
		PLAYER::DISABLE_PLAYER_FIRING(playerPed, 1);
		Vector3 gameplayCam;
		Hooking::get_gameplay_cam_coord(&gameplayCam);
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
		Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 1.0f)));
		Vector3 endCoords = addVector(startCoords, multiplyVector(gameplayCamDirection, 500.0f));
		Hash weaponhash;
		Hooking::get_current_ped_weapon(playerPed, &weaponhash, 1);
		if (CONTROLS::IS_CONTROL_PRESSED(2, 208) || (GetKeyState(VK_LBUTTON) & 0x8000)) {
			PED::SET_PED_SHOOTS_AT_COORD(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::GET_PLAYER_INDEX()), endCoords.x, endCoords.y, endCoords.z, true);
			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(startCoords.x, startCoords.y, startCoords.z, endCoords.x, endCoords.y, endCoords.z, 50, 1, weaponhash, playerPed, 1, 1, 0xbf800000);
		}
	}
}

bool NoRagdoll = false;
void noragdoll(bool toggle)
{
	PED::SET_PED_RAGDOLL_ON_COLLISION(player_ped_id(), !toggle);
	PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(player_ped_id(), !toggle);
	PED::SET_PED_CAN_RAGDOLL(player_ped_id(), !toggle);
}

void Features()
{
	if (noclipbool)
		noClip(true);

	if (rainbowvehbool)
		carfade(rainbowvehbool);

	if (NeverWanted)
	{
		/*if (Memory::get_value<float>({ 0x08, 0x10B8, 0x71C }) != 0.f)
			Memory::set_value({ 0x08, 0x10B8, 0x71C }, 0.f);*/

		if (Memory::get_value<DWORD>({ 0x08, 0x10B8, 0x848 }) > 0)
			Memory::set_value<DWORD>({ 0x08, 0x10B8, 0x848 }, 0);
	}
	/*else
	{
		if (Memory::get_value<float>({ 0x08, 0x10B8, 0x71C }) != 1.0f)
			Memory::set_value({ 0x08, 0x10B8, 0x71C }, 1.0f);
	}*/

	if (GodMod)
		Memory::set_value<BYTE>({ 0x08, 0x189 }, 0x01);
	else
		Memory::set_value<BYTE>({ 0x08, 0x189 }, 0x00);

	DWORD dwValue = 0;

	if (ExplosiveAmmo)
		dwValue |= 1 << 11;

	if (FireAmmo)
		dwValue |= 1 << 12;

	if (ExplosiveMeele)
		dwValue |= 1 << 13;

	if (SuperJump)
		dwValue |= 1 << 14;

	if (Memory::get_value<DWORD>({ 0x08, 0x10B8, 0x1F8 }) != dwValue)
		Memory::set_value({ 0x08, 0x10B8, 0x1F8 }, dwValue);

	if (FastRun)
		Memory::set_value({ 0x08, 0x10B8, 0x14C }, 1.8f);
	else
		Memory::set_value({ 0x08, 0x10B8, 0x14C }, 1.f);

	if (rainmoneybool) 
		rainMoney(selectedPlayer);

	if (aimbotAIbool)
		aimbotAI();

	if (SV)
		sv(1);

	if (antiReport)
		AntiReport(true);

	if (antiStats)
		AntiStat(true);

	if (antiStars)
		AntiStars(true);

	if (RapidFire)
		rapidfire(true);

	if (antiSound)
		AntiSound(true);

	if (antiExplosion)
		AntiExplosion(true);

	if (antiAttachment)
		AntiAttachment(true);

	if (antiFreeze)
		AntiFreeze(true);

	if (antiKick)
		AntiKick(true);


	if (vehWeaponint != 0)
		update_vehicle_guns(weaponCar[vehWeaponint]);

	if (aimbotPlrbool) {
		aimbotPlayers();
	}

	if (superrunbool)
		superRun();

	if (flyPlayerBool)
		flyPlayer();

	if (UpgradeVehicles) {
		if ((timeGetTime() - TimeDelayUpdateVEHS) > 1500) {
			update_nearby_vehicles(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::GET_PLAYER_INDEX()), 10);
			TimeDelayUpdateVEHS = timeGetTime();
		}
		if (!lastSeenVehicles.empty()) {
			for (int i = 0; i < lastSeenVehicles.size(); i++) {
				VEHICLE::SET_VEHICLE_MOD_KIT(lastSeenVehicles[i], 0);
				for (int i = 0; i < 50; i++)
				{
					Hooking::set_vehicle_mod(lastSeenVehicles[i], i, VEHICLE::GET_NUM_VEHICLE_MODS(lastSeenVehicles[i], i) - 1, false);
				}
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(lastSeenVehicles[i], "RATACAXD");

			}
			lastSeenVehicles.clear();
		}
	}

	if (airstrikegunbool)
		airStrikeGun();

	blackHole::tick();

	if (watereffect) {
		PTFXCALLBoneless("scr_fbi5a", "scr_fbi5_ped_water_splash", 0x796e, selectedPlayer);
		PTFXCALLBoneless("scr_fbi5a", "scr_fbi5_ped_water_splash", 0x8cbd, selectedPlayer);
		PTFXCALLBoneless("scr_fbi5a", "scr_fbi5_ped_water_splash", 0xdead, selectedPlayer);
	}
	if (bloodeffect) {
		PTFXCALLBoneless("scr_finalec2", "scr_finale2_blood_entry", 0x796e, selectedPlayer);
		PTFXCALLBoneless("scr_finalec2", "scr_finale2_blood_entry", 0x8cbd, selectedPlayer);
		PTFXCALLBoneless("scr_finalec2", "scr_finale2_blood_entry", 0xdead, selectedPlayer);
	}
	if (smokeeffect) {
		PTFXCALLBoneless("scr_familyscenem", "scr_meth_pipe_smoke", 0x796e, selectedPlayer);
		PTFXCALLBoneless("scr_familyscenem", "scr_meth_pipe_smoke", 0x8cbd, selectedPlayer);
		PTFXCALLBoneless("scr_familyscenem", "scr_meth_pipe_smoke", 0xdead, selectedPlayer);
	}
	if (moneyeffect) {
		PTFXCALLBoneless("scr_rcbarry2", "scr_clown_death", 0x796e, selectedPlayer);
		PTFXCALLBoneless("scr_rcbarry2", "scr_clown_death", 0x8cbd, selectedPlayer);
		PTFXCALLBoneless("scr_rcbarry2", "scr_clown_death", 0xdead, selectedPlayer);
	}
	if (ClownLoop) {
		PTFXCALLBoneless("scr_rcbarry2", "scr_clown_appears", 0x796e, selectedPlayer);
		PTFXCALLBoneless("scr_rcbarry2", "scr_clown_appears", 0x8cbd, selectedPlayer);
		PTFXCALLBoneless("scr_rcbarry2", "scr_clown_appears", 0xdead, selectedPlayer);
	}
	if (fireworkloop) {
		PTFXCALLBoneless("scr_indep_fireworks", "scr_indep_firework_trailburst", 0x796e, selectedPlayer);
		PTFXCALLBoneless("scr_indep_fireworks", "scr_indep_firework_trailburst", 0x8cbd, selectedPlayer);
		PTFXCALLBoneless("scr_indep_fireworks", "scr_indep_firework_trailburst", 0xdead, selectedPlayer);
	}
	if (alien1) {
		PTFXCALLBoneless("scr_rcbarry1", "scr_alien_disintegrate", 0x796e, selectedPlayer);
		PTFXCALLBoneless("scr_rcbarry1", "scr_alien_disintegrate", 0x8cbd, selectedPlayer);
		PTFXCALLBoneless("scr_rcbarry1", "scr_alien_disintegrate", 0xdead, selectedPlayer);
	}
	if (alien2) {
		PTFXCALLBoneless("scr_rcbarry1", "scr_alien_teleport", 0x796e, selectedPlayer);
		PTFXCALLBoneless("scr_rcbarry1", "scr_alien_teleport", 0x8cbd, selectedPlayer);
		PTFXCALLBoneless("scr_rcbarry1", "scr_alien_teleport", 0xdead, selectedPlayer);
	}
	if (electric) {
		PTFXCALLBoneless("scr_agencyheistb", "scr_agency3b_elec_box", 0x796e, selectedPlayer);
		PTFXCALLBoneless("scr_agencyheistb", "scr_agency3b_elec_box", 0x8cbd, selectedPlayer);
		PTFXCALLBoneless("scr_agencyheistb", "scr_agency3b_elec_box", 0xdead, selectedPlayer);
	}
	if (stars) {
		PTFXCALLBoneless("scr_rcbarry2", "scr_clown_bul", 0x796e, selectedPlayer);
		PTFXCALLBoneless("scr_rcbarry2", "scr_clown_bul", 0x8cbd, selectedPlayer);
		PTFXCALLBoneless("scr_rcbarry2", "scr_clown_bul", 0xdead, selectedPlayer);
	}
	if (ghostRider) {
		PTFXCALLBoneless("scr_agencyheist", "scr_fbi_dd_breach_smoke", 0x796e, selectedPlayer);
		PTFXCALLBoneless("scr_agencyheist", "scr_fbi_dd_breach_smoke", 0x8cbd, selectedPlayer);
		PTFXCALLBoneless("scr_agencyheist", "scr_fbi_dd_breach_smoke", 0xdead, selectedPlayer);
	}

	Speedometer();

	if (localmoneygun2_5k)
		moneyGun2_5k(player_ped_id());

	if (onlinemoneygun2_5k)
		moneyGun2_5k(get_player_ped(selectedPlayer));

	if (GravityGun)
		gravityGun(1);

	if (boostweaponbool || boostpunchbool)
		boostWeapon(player_id(), boostpunchbool, boostweaponbool);

	if (teleportweaponbool)
		TPWeapon();

	if (resetCamPlr) {
		if (timeGetTime() - resetCamPlrTimer > 500) {
			DWORD64 args[3] = { RESET_CAM, selectedPlayer, RESET_CAM_HASH_ID };
			SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 3, 1 << selectedPlayer);
			resetCamPlrTimer = timeGetTime();
		}
	}

	if (allPlrResetCam) {
		if (timeGetTime() - remoteCamResetTimer > 500) {
			for (int z = 0; z < 32; z++) {
				if (!get_player_ped(z)) continue;
				if (player_id() != z) {
					DWORD64 args[3] = { RESET_CAM, selectedPlayer, RESET_CAM_HASH_ID };
					SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 3, 1 << selectedPlayer);
				}
			}
			remoteCamResetTimer = timeGetTime();
		}
	}

	/*if (crashPlayerEvent) {
		spectate = false, Spectate(false);
		Vector3 pos = get_player_coords(selectedPlayer);

		for (int i = 0; i < blacklistedObjects.size(); i++) {
			Object tempObject = create_object(blacklistedObjects[i], pos.x, pos.y, pos.z, true, false, false);
			attach_entity_to_entity(tempObject, get_player_ped(selectedPlayer), SKEL_Spine0, 0, 0, 0, 0, 0, 0, false, false, false, true, 2, true);
			CrashObject.push_back(tempObject);
		}

		if (GetTickCount() > 650 + crashPlayerTimer) {
			for (int i = 0; i < CrashObject.size(); i++) {
				ENTITY::DETACH_ENTITY(CrashObject.at(i), 1, 0);
				set_entity_coords(CrashObject.at(i), { 6400.f, 6400.f, 0.f }, 0, 0, 0);
				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(CrashObject.at(i), 1, 1);
				ENTITY::DELETE_ENTITY(&CrashObject.at(i));
			}
			CrashObject.clear();
			notifyMap("~g~Crashing! Wait A Few Seconds...");
			crashPlayerEvent = false;
		}
	}*/

	if (allremoteoffradar) {
		if (timeGetTime() - allremoteOffRadarTimer > 600) {
			for (int x = 0; x < 32; x++) {
				if (!get_player_ped(x)) continue;
				if (player_id() == x) continue;
				DWORD64 args[7] = {
					REMOTE_OFF_RADAR, x, NETWORK::GET_NETWORK_TIME() + 1, 0, 1, 1,
					GlobForNeverWanted(x)
				};
				SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 7, 1 << x);
			}
			allremoteOffRadarTimer = timeGetTime();
		}
	}

	if (DriveWater) 
		driveWater(DriveWater);

	if (ESPbool) {
		for (int x = 0; x < 32; x++)
		{
			if (x != player_id() && is_cped_valid(get_player_cped(get_player_ped(x))))
				esp(x);
		}
	}

	if (allremotecopsblind) {
		if (timeGetTime() - allremotecopsBlindTimer > 600) {
			for (int x = 0; x < 32; x++) {
				if (!get_player_ped(x)) continue;
				if (player_id() == x) continue;
				DWORD64 args[7] = {
					REMOTE_COPS_BLIND_EYE, x, 0, 0, 1, 1,
					GlobForNeverWanted(x)
				};
				SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 7, 1 << x);
			}
		}
		allremotecopsBlindTimer = timeGetTime();
	}

	if (flyingcarbool) {
		flyingCarLoop();
	}

	if (remotecopsblind) {
		if (timeGetTime() - remotecopsBlindTimer > 600) {
			DWORD64 args[7] = { REMOTE_COPS_BLIND_EYE, selectedPlayer, 0, 0, 1, 1, GlobForNeverWanted(selectedPlayer) };
			SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 7, 1 << selectedPlayer);
			remotecopsBlindTimer = timeGetTime();
		}
	}

	if (offradar)
	{
		if ((timeGetTime() - TimePD4) > 30000) {
			OffRadar(true);
			TimePD4 = timeGetTime();
		}
	}

	if (flashmap) {
		if (timeGetTime() - flashMapTimer > 200) {
			DWORD64 args[14] = { SEND_NOTIFICATION_MESSAGES, selectedPlayer, FLASH_MAP_HASH_ID };
			SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 14, 1 << selectedPlayer);
			flashMapTimer = timeGetTime();
		}
	}

	if (allFlashMap) {
		if (timeGetTime() - allflashMapTimer > 500) {
			for (int x = 0; x < 32; x++) {
				if (!get_player_ped(x)) continue;
				if (player_id() == x) continue;
				DWORD64 args[14] = { SEND_NOTIFICATION_MESSAGES, x, FLASH_MAP_HASH_ID };
				SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 14, 1 << x);
				flashMapTimer = timeGetTime();
			}
			allflashMapTimer = timeGetTime();
		}
	}

	if (autoToWaypoint)
		IsKeyPressed(VK_F12) ? TpToWaypoint() : NULL;

	if (boostnearvehbool)
		boostnearbyvehicles();
	
	if (GetTickCount() > 350 + TimePD2)
		Spectate(spectate);

	if (idlekickprot)
		antiAfkKick1();

	if (customBulletInt)
		customBullets(customBulletInt);

	if (localmoneygun2_5k)
		moneyGun2_5k(player_ped_id());

	if (deletenearvehsbool)
		deletenearbyvehicles();

	if (FireLoop)
	{
		Vector3 pos = get_player_coords(selectedPlayer);
		FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z - 1.f, 30, 248.9f, true, false, 1.1f);
	}

	if (WaterLoop)
	{
		Vector3 pos = get_player_coords(selectedPlayer);
		FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z - 1.f, 13, 248.9f, true, false, 1.1f);
	}

	chatcmddropmoney();

	if (invisible)
		Invisibility(true);

	if (Freeze)
		ClearTasks(selectedPlayer);

	if (explodenearvehbool)
		explodenearbyvehicles();

	if (explodenearpedbool)
		explodepeds();

	if (hornboost)
		if (PLAYER::IS_PLAYER_PRESSING_HORN(player_id()))
			BoostPlayerVehicle(player_ped_id(), 1, false, false, 70);

}

string username = "";
string password = "";
bool no_firstTime = 0;

void checkIniFile() {
	username = Menu::Files::ReadStringFromIni("Spooki Ryd3rs/SpookiSettings.ini", "Auth", "username");
	password = Menu::Files::ReadStringFromIni("Spooki Ryd3rs/SpookiSettings.ini", "Auth", "password");
	no_firstTime = Menu::Files::ReadBoolFromIni("Spooki Ryd3rs/SpookiSettings.ini", "Auth", "no_first_time");

	//headerToUse = Menu::Files::ReadIntFromIni("Spooki Ryd3rs/SpookiSettings.ini", "GUI", "menu_header");
	//Log::Msg("ok16");
	//Menu::Settings::animatedHeader = !Menu::Files::ReadBoolFromIni("Spooki Ryd3rs/SpookiSettings.ini", "GUI", "simple_header");
}

int versUsed = 1;
//1 LITE orange
//2 VIP yellow
//3 PREMIUM purple

int wantedLvlInt;
void main() {
	Menu::YTD("SpookiRyd3rsLogo1.ytd");
	Menu::YTD("SpookiRyd3rsLogo2.ytd");

	notifyMap("~f~ Spooki Ryd3rs 1%% Loaded");
	checkIniFile();

	if (!no_firstTime) {
LABEL_TRYAGAIN:
		username = CharKeyboard("Username", 21, "");
		password = CharKeyboard("Password", 21, "");

LABEL_LOGIN:
		versUsed = is_user_authed(username, password);
		static bool askAgain = false;
		if (!askAgain && versUsed == 1 && no_firstTime) {
			askAgain = true;
			goto LABEL_TRYAGAIN;
		}
		Log::Msg("%i", versUsed);
		if (versUsed <= 0) { //error / user not exist
			Log::Fatal("Failed Login - Contact Spooki Ryd3rs Support");
			//goto LABEL_TRYAGAIN; for tests
			exit(0);
			/*notifyMap("~r~Log In Failed! Want try again manually? ~g~y/n");
			WAIT(300);
			char* tryAgain = CharKeyboard();
			if (tryAgain == "y" || tryAgain == "Y") goto LABEL_TRYAGAIN;
			exit(0);*/
		}
		else {
			WAIT(0);
			Menu::Files::WriteStringToIni(username, "Spooki Ryd3rs/SpookiSettings.ini", "Auth", "username");
			Menu::Files::WriteStringToIni(password, "Spooki Ryd3rs/SpookiSettings.ini", "Auth", "password");
			Menu::Files::WriteBoolToIni(true, "Spooki Ryd3rs/SpookiSettings.ini", "Auth", "no_first_time");
		}
	}
	else {
		goto LABEL_LOGIN;
	}

	if (!(versUsed - 2))
		notifyMap("~y~ Spooki Ryd3rs 1%% VIP");
	else if (!(versUsed - 3))
		notifyMap("~p~ Spooki Ryd3rs 1%% PREMIUM");
	else
		notifyMap("~o~ Spooki Ryd3rs 1%% LITE");

	//username = CharKeyboard("Username", 21, "");
	//password = CharKeyboard("Password", 21, "");

	//notifyMap("%i", is_user_authed(username, password));

	Log::Msg("Starting Auth Process - Welcome to Spooki Ryd3rs");

	while (true) {
		Menu::Checks::Controlls();
		Features();
	
		switch (Menu::Settings::currentMenu) {
		case mainmenu:
		{
			Menu::Title("Spooki Ryd3rs 1% Premium");
		
			if (Menu::MenuOption("Self Options", self)) {}
			if (Menu::MenuOption("Online", online)) {}
			if (Menu::MenuOption("Teleport", teleport)) {}
			if (Menu::MenuOption("Weapon", weapon)) {}
			if (Menu::MenuOption("Vehicle", vehicle)) {}

			if (versUsed != 1) {
				if (Menu::MenuOption("~y~Protections[VIP]", protections)) {}
			}
			else {//turn off prot
				antiReport = false;
				antiKick = false;
				antiFreeze = false;
				antiAttachment = false;
				antiExplosion = false;
				antiSound = false;
				antiStars = false;
				antiStats = false;
				idlekickprot = false;
				blockAllScrictEvents = false;
				nonHostKicksProtBool = false;
				forceToNewLobbyProt = false;
				TpToAppsProtection = false;
				infLoadingProt = false;
				transactionErrorProt = false;
				ForceToMissionProt = false;
				InvitesProtection = false;
				CeoBanProtection = false;
				CEOKickProtection = false;
				kickCarProtection = false;
				camResetProtection = false;
				gtaBannerEffectProt = false;
			}

			if (versUsed != 1) {
				if (Menu::MenuOption("~y~Recovery[VIP]", recovery)) {}
			}
			if (Menu::MenuOption("Misc", misc)) {}
			if (Menu::MenuOption("Credits", Credits)) {}
			if (Menu::MenuOption("Settings", settings)) {}
		
		}
	
		break;

#pragma region Menu

		case self:
		{
			Menu::Title("Self Options");
			

			if (Menu::MenuOption("Model Changer", modelchanger)) {}

			if (Menu::MenuOption("Animations", animation)) {}

			if (Menu::Toggle("God Mode", GodMod)) {}

			if (Menu::Toggle("Never Wanted", NeverWanted)) {}

			if (Menu::Int("Wanted Level", wantedLvlInt, 0, 5) && !NeverWanted)
				Memory::set_value<DWORD>({ 0x08, 0x10B8, 0x848 }, wantedLvlInt);

			if (versUsed == 3) {
				if (Menu::Toggle("~p~Fly Mode[PREMIUM]", flyPlayerBool)) {}
			}

			if (Menu::Toggle("Invisible", invisible)) {
				!invisible ? Invisibility(0) : NULL;
			}

			if (versUsed == 3) {
				if (Menu::Toggle("~p~Super Vision[PREMIUM]", SV)) {}
			}

			if (Menu::Toggle("Off Radar", offradar)) {
				if (!offradar) OffRadar(false);
				else TimePD4 = 0;
			}
	
			if (Menu::Toggle("Run Fast", FastRun)) {}

			if (Menu::Toggle("Super Run", superrunbool)) {}

			if (Menu::Toggle("Explosive Meele", ExplosiveMeele)) {}

			if (Menu::Toggle("Super Jump", SuperJump)) {}

			if (Menu::Toggle("No Clip", noclipbool)) {}

			if (Menu::Toggle("no ragdoll", NoRagdoll))
				noragdoll(NoRagdoll);

			if (Menu::Option("Full Health"))
				Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_ENTITY_HEALTH }, 328);

			if (Menu::Option("Full Armor"))
				Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_ARMOR }, 50);

			if (versUsed == 3) {
				if (Menu::Option("~p~Drop Ammo[PREMIUM]"))
				{
					globalHandle(2528542).At(824).As<int>() = 1;
				}
				if (Menu::Option("~p~Boat Pickup[PREMIUM]"))
				{
					globalHandle(2528542).At(825).As<int>() = 1;
				}
				if (Menu::Option("~p~Requestr Heli[PREMIUM]"))
				{
					globalHandle(2528542).At(826).As<int>() = 1;
				}
				if (Menu::Option("~p~Airstrike[PREMIUM]"))
				{
					globalHandle(2528542).At(4380).As<int>() = 1;
				}

				if (Menu::Toggle("~p~Bull Shark Testosterone[PREMIUM]", bullsharkbool)) {
					bullSharkTestosterone(bullsharkbool);
				}
			}

			if (Menu::Option("Random Outfit"))
				PED::SET_PED_RANDOM_COMPONENT_VARIATION(player_ped_id(), true);

			if (Menu::Option("Cleaner"))
			{
				PED::CLEAR_PED_BLOOD_DAMAGE(player_ped_id());
				PED::RESET_PED_VISIBLE_DAMAGE(player_ped_id());
			}

			if (Menu::Option("~r~Suicide"))
				Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_ENTITY_HEALTH }, 0);

		}
		break;

		case modelchanger:
		{
			Menu::Title("Model Changer");
			if (Menu::Option("~f~Rainbow Textures"))
			{
				PED::SET_PED_DEFAULT_COMPONENT_VARIATION(player_ped_id());
				Ped Pped = player_ped_id();
				for (int componentId = 0; componentId < 11; componentId++) {
					int drawableId = PED::GET_PED_DRAWABLE_VARIATION(Pped, componentId);
					PED::GET_PED_TEXTURE_VARIATION(Pped, componentId);
					int textureId = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(Pped, componentId, drawableId);
					PED::SET_PED_COMPONENT_VARIATION(player_ped_id(), componentId, drawableId, textureId, 0);
				}
			}
			/*for (int i = 0; i < pedModels.size(); i++)
			{
				if (Menu::Option(pedModels[i]))
				{
					DWORD model = $(pedModels[i]);
					Hooking::request_model(model);
					while (!Hooking::has_model_loaded(model)) WAIT(0);
					PLAYER::SET_PLAYER_MODEL(player_id(), model);
					PED::SET_PED_DEFAULT_COMPONENT_VARIATION(player_ped_id());
					WAIT(10);
					unloadModel(model);
					WAIT(10);
				}
			}*/
		}
		break;

		case animation:
		{
			Menu::Title("Animations");
			if (Menu::MenuOption("Scenarios", scenarios)) {}

			if (Menu::Option("Clear Animation")) { clearanim(); }
			for (int x = 1; x < animOutputList.size(); x++) {
				if (Menu::Option(animOutputList[x])) 
					doAnimation(animDictList[x], animNameList[x]);
			}
		}
		break;

		case onlineeffects:
		{
			Menu::Title("Effects");

			if (Menu::Toggle("Lightning", moneyeffect)) {}
			if (Menu::Toggle("Clown Effects", ClownLoop)) {}
			if (Menu::Toggle("Firework", fireworkloop)) {}
			if (Menu::Toggle("Alien 1", alien1)) {}
			if (Menu::Toggle("Alien 2", alien2)) {}
			if (Menu::Toggle("Electric", electric)) {}
			if (Menu::Toggle("Water Splash", watereffect)) {}
			if (Menu::Toggle("Smoke", smokeeffect)) {}
			if (Menu::Toggle("stars", stars)) {}
			if (Menu::Toggle("Ghost Rider", ghostRider)) {}

			if (Menu::Float("Particle Size", PTFXscale, 0.01f, 3.5f, 0.1)) {}
			for (int x = 1; x < PTFXOutputNameList.size(); x++) {
				if (Menu::Option(PTFXOutputNameList[x]))
					PTFX(PTFXAssetsList[x], PTFXNamesList[x], selectedPlayer);
			}
		}
		break;

		case scenarios:
		{
			Menu::Title("Scenarios");
			if (Menu::Option("Kill Animation")) Hooking::clear_ped_tasks_immediately(player_ped_id());
			if (Menu::Option("Paparizzi")) AI::TASK_START_SCENARIO_IN_PLACE(player_ped_id(), "WORLD_HUMAN_PAPARAZZI", 0, true);
			if (Menu::Option("Drug Dealer")) AI::TASK_START_SCENARIO_IN_PLACE(player_ped_id(), "WORLD_HUMAN_DRUG_DEALER_HARD", 0, true);
			if (Menu::Option("Drinking Coffee")) AI::TASK_START_SCENARIO_IN_PLACE(player_ped_id(), "WORLD_HUMAN_AA_COFFEE", 0, true);
			if (Menu::Option("Playing Instruments")) AI::TASK_START_SCENARIO_IN_PLACE(player_ped_id(), "WORLD_HUMAN_MUSICIAN", 0, true);
			if (Menu::Option("Flexing")) AI::TASK_START_SCENARIO_IN_PLACE(player_ped_id(), "WORLD_HUMAN_MUSCLE_FLEX", 0, true);
			if (Menu::Option("Jogging")) AI::TASK_START_SCENARIO_IN_PLACE(player_ped_id(), "WORLD_HUMAN_JOG_STANDING", 0, true);
			if (Menu::Option("Binoculars")) AI::TASK_START_SCENARIO_IN_PLACE(player_ped_id(), "WORLD_HUMAN_BINOCULARS", 0, true);
			if (Menu::Option("Clipboard")) AI::TASK_START_SCENARIO_IN_PLACE(player_ped_id(), "WORLD_HUMAN_CLIPBOARD", 0, true);
			if (Menu::Option("Bench Press")) AI::TASK_START_SCENARIO_IN_PLACE(player_ped_id(), "PROP_HUMAN_SEAT_MUSCLE_BENCH_PRESS", 0, true);
			if (Menu::Option("Chin Ups")) AI::TASK_START_SCENARIO_IN_PLACE(player_ped_id(), "PROP_HUMAN_MUSCLE_CHIN_UPS", 0, true);
			if (Menu::Option("BBQ")) AI::TASK_START_SCENARIO_IN_PLACE(player_ped_id(), "PROP_HUMAN_BBQ", 0, true);
			if (Menu::Option("Superhero")) AI::TASK_START_SCENARIO_IN_PLACE(player_ped_id(), "WORLD_HUMAN_SUPERHERO", 0, true);
			if (Menu::Option("Fishing")) AI::TASK_START_SCENARIO_IN_PLACE(player_ped_id(), "WORLD_HUMAN_STAND_FISHING", 0, true);
			if (Menu::Option("Security")) AI::TASK_START_SCENARIO_IN_PLACE(player_ped_id(), "WORLD_HUMAN_SECURITY_SHINE_TORCH", 0, true);
			if (Menu::Option("Leaf Blower")) AI::TASK_START_SCENARIO_IN_PLACE(player_ped_id(), "WORLD_HUMAN_GARDENER_LEAF_BLOWER", 0, true);
			if (Menu::Option("Film Shocking")) AI::TASK_START_SCENARIO_IN_PLACE(player_ped_id(), "WORLD_HUMAN_MOBILE_FILM_SHOCKING", 0, true);
			if (Menu::Option("Idle Cop")) AI::TASK_START_SCENARIO_IN_PLACE(player_ped_id(), "WORLD_HUMAN_COP_IDLES", 0, true);
			if (Menu::Option("Drinking")) AI::TASK_START_SCENARIO_IN_PLACE(player_ped_id(), "WORLD_HUMAN_DRINKING", 0, true);
			if (Menu::Option("Golf Player")) AI::TASK_START_SCENARIO_IN_PLACE(player_ped_id(), "WORLD_HUMAN_GOLF_PLAYER", 0, true);
			if (Menu::Option("Welding")) AI::TASK_START_SCENARIO_IN_PLACE(player_ped_id(), "WORLD_HUMAN_WELDING", 0, true);
			if (Menu::Option("Smoking Pot")) AI::TASK_START_SCENARIO_IN_PLACE(player_ped_id(), "WORLD_HUMAN_SMOKING_POT", 0, true);
			if (Menu::Option("Hammering")) AI::TASK_START_SCENARIO_IN_PLACE(player_ped_id(), "WORLD_HUMAN_HAMMERING", 0, true);
			if (Menu::Option("Tennis")) AI::TASK_START_SCENARIO_IN_PLACE(player_ped_id(), "WORLD_HUMAN_TENNIS_PLAYER", 0, true);
			if (Menu::Option("Drilling")) AI::TASK_START_SCENARIO_IN_PLACE(player_ped_id(), "WORLD_HUMAN_CONST_DRILL", 0, true);
		}
		break;

		/*case onlinechatcmd:
		{
			Menu::Title("Chat Commands");

			if (Menu::Toggle("All Chat", chatCMDAll)) {}
			if (Menu::Toggle("Team/Organization Chat", chatCMDTeam)) {}

			if (Menu::Toggle("Give Weapons", chatCMDWeapons)) {}
			if (Menu::Toggle("Give Money", chatCMDGiveMoney)) {}
		}
		break;*/

		case online:
		{
			Menu::Title("Online Options");
			if (Menu::MenuOption("Player List", onlinelist)) {}
			if (Menu::MenuOption("All Players", allonline)) {}
			if (versUsed != 1) {
				if (Menu::MenuOption("~y~Chat Commands[VIP]", onlinechatcmd)) {}
			}
			if (Menu::MenuOption("Session Weather - Time", weather)) {}
			Menu::IntChar("Name Color", nameColor, nameColorInt, 0, nameColor.size() - 1);
			if (Menu::Option("Name Changer")) {
				notifyMap("~g~ To Set The New Name Do It Offline");
				notifyMap("~g~ if y want add color, select color first and then type the new name");
				NameChanger();
			}
			if (Menu::Toggle("ESP Box", ESPbool)) {}

		}
		break;

		case allonline:
		{
			Menu::Title("All Players");

			if (Menu::MenuOption("Send Notifications", allnotificationmessages)) { notifyMsgAllCase = false; }
			if (Menu::MenuOption("Teleport To Apartment", allappartments)) {}

			//if (Menu::Toggle("Low FPS / Reset Camera", allPlrResetCam)) {}
			//if (Menu::Toggle("Off Radar All", allremoteoffradar)) {}
			//if (Menu::Toggle("Cops Blind Eye All", allremotecopsblind)) {}

			if (Menu::Toggle("Flash Minimap", allFlashMap)) {}

			if (Menu::Option("Remove Wanted Level")) {
				for (int z = 0; z < 32; z++) {
					if (player_id() != z) {
						DWORD64 args[3] = { REMOVE_WANTED_LEVEL, z, GlobForNeverWanted(z) };
						SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 3, 1 << z);
					}
				}
			}

			if (versUsed == 3) {
				if (Menu::Option("~p~Cage All[PREMIUM]")) {
					//CageAll();
				}
			}
			
			/*if (Menu::Option("Kick From Car")) {
				for (int z = 0; z < 32; z++) {
					if (player_id() != z) {
						ClearTasks(z);
					}
				}
			}*/

			if (Menu::IntChar("Send Invites", inviteSpamTypes, sendinvitesint, 0, inviteSpamTypes.size() - 1)) {
				if (IsKeyPressed(VK_NUMPAD5)) {
					for (int z = 0; z < 32; z++) {
						if (z != player_id()) {
							DWORD64 args[3] = { SEND_INVITES, z, inviteSpamTypesInt[sendinvitesint] };
							SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 4, 1 << z);
						}
					}
				}
			}

			if (Menu::Option("Force To Mission")) {
				for (int z = 0; z < 32; z++) {
					if (z != player_id()) {
						DWORD64 args[4] = { SEND_TO_JOB, z, 0, 0 };
						SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 4, 1 << z);
					}
				}
			}
			if (Menu::Option("Transaction Fail Screen")) {
				for (int z = 0; z < 32; z++) {
					if (z != player_id()) {
						std::uint64_t args[8] = { TRANSACTION_FAIL, z, 10000, 0, 0, GlobForNeverWanted(z), IdkGlob_xxxxx_f_9(), IdkGlob_xxxxx_f_10() };
						SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 8, 1 << z);
					}
				}
			}

			if (Menu::Option("Stop And Kick From Car")) {
				for (int z = 0; z < 32; z++) {
					if (player_id() != z) {
						DWORD64 args[2] = { KICK_FROM_CAR, z };
						SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 2, 1 << z);
					}
				}
			}

			if (Menu::Option("~r~Airstrike")) {
				for (int z = 0; z < 32; z++) {
					if (z != player_id()) {
						ClearTasks(z);
						Vector3 Coords = get_player_coords(z);
						GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(Coords.x, Coords.y, Coords.z + 30, Coords.x, Coords.y, Coords.z, 250, 0, $("VEHICLE_WEAPON_SPACE_ROCKET"), 0, 1, 1, 0xbf800000);
					}
				}
			}

			if (Menu::Option("Set 10k Bounty To All")) {
				for (int z = 0; z < 32; z++) {
					if (player_id() == z) continue;
					for (int i = 0; i < 32; i++) {
						DWORD64 args[22] = { SET_BOUNTY, i, z, 0, 10000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, IdkGlob_xxxxx_f_9(), IdkGlob_xxxxx_f_10() };
						SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 22, 1 << i);
					}
				}
			}

			if (Menu::Option("~r~Force To SP")) {
				for (int z = 0; z < 32; z++) {
					if (z != player_id()) {
						kickPlayer(z, 12);
						kickPlayer(z, 11);
						kickPlayer(z, 8);
						kickPlayer(z, 36);
					}
				}
			}

			if (Menu::Option("CEO Kick")) {
				for (int z = 0; z < 32; z++) {
					if (z != player_id()) {
						DWORD64 args[4] = { CEO_KICK, z, 1, 5 };
						SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 4, 1 << z);
					}
				}
			}

			if (Menu::Option("CEO Ban")) {
				for (int z = 0; z < 32; z++) {
					if (z != player_id()) {
						DWORD64 args[4] = { CEO_BAN, z, 1, 5 };
						SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 4, 1 << z);
					}
				}
			}

		}
		break;

		case onlinelist:
		{
			Menu::Title("Online Players");
			for (int i = 0; i < 32; i++) {
				if (does_entity_exist(get_player_ped(i))) {
					char oPlayer[256];
					sprintf_s(oPlayer, "%s", get_player_name(i));
					if (Menu::MenuOption(oPlayer, onlineoptions)) selectedPlayer = i;
				}
			}
		}
		break;

		case notificationmessages:
		{
			Menu::Title("Send Notifications");

			/*if (!notifyMsgAllCase)
				playerinfo();*/

			if (Menu::Toggle("Flash Map With Notifications", flashmapwithnotify)) {}

			if (Menu::MenuOption("All Notifications", notifymsgall)) {}
			if (Menu::MenuOption("Notifications With Fake Money", notifymsgfakemoney)) {}
			if (Menu::MenuOption("Notifications Showing Other Players Name", notifymsgotherplrnames)) {}
			if (Menu::MenuOption("Notifications Showing Only Your Name", notifymsglocalname)) {}
			if (Menu::MenuOption("Notifications Not Showing Any Players Name", notifymsgnonames)) {}
			if (Menu::MenuOption("Notifications For CEO", notifymsgorg)) {}
			if (Menu::MenuOption("Banner Effect Notifications", notifymsgbannereffect)) {}

		}
		break;

		case notifymsgall:
		{
			Menu::Title("All Notifications");

			/*if (!notifyMsgAllCase)
				loadPlayerInfo(selectedPlayer);*/

			if (Menu::IntChar("~f~Custom Fake Money", customfakemoneynotification, fakemoneynotify, 0, customfakemoneynotification.size() - 1, 2)) {
				int Mnum = NumberKeyboard();
				for (int y = 0; y < 32; y++) {
					if (!notifyMsgAllCase) y = 33;
					if (!get_player_ped(y == 33 ? selectedPlayer : y)) continue;

					DWORD64 args[14] = { SEND_NOTIFICATION_MESSAGES, y == 33 ? selectedPlayer : y, atoi(customfakemoneynotification.at(fakemoneynotify + 1)), Mnum };
					SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 14, 1 << (y == 33 ? selectedPlayer : y));
					if (flashmapwithnotify) {
						DWORD64 args[14] = { SEND_NOTIFICATION_MESSAGES, y == 33 ? selectedPlayer : y, FLASH_MAP_HASH_ID, 44,44,44,44,44,44,44,44,44,44,44 };
						SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 14, 1 << (y == 33 ? selectedPlayer : y));
					}
				}
			}

			for (int x = 0; x < notificationmessagesoutput.size(); x++) {
				if (notifyMsgCheckFlag(notificationmessagesoutput.at(x), "de")) continue;
				if (Menu::Option(notificationmessagesoutput.at(x).output_name.c_str())) {
					std::vector<int> playerslist;
					for (int y = 0; y < 32; y++) {
						if (get_player_ped(y))
							playerslist.push_back(y);
					}

					for (int y = 0; y < 32; y++) {
						if (!notifyMsgAllCase) y = 33;
						if (!get_player_ped(y == 33 ? selectedPlayer : y)) continue;

						DWORD64 args[14] = { SEND_NOTIFICATION_MESSAGES, y == 33 ? selectedPlayer : y, notificationmessagesids[x], 123456789 - rand() % 123456789, playerslist.at(rand() % playerslist.size()), playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()), };
						SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 14, 1 << (y == 33 ? selectedPlayer : y));
						if (flashmapwithnotify) {
							DWORD64 args[14] = { SEND_NOTIFICATION_MESSAGES, y == 33 ? selectedPlayer : y, FLASH_MAP_HASH_ID, playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1) };
							SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 14, 1 << (y == 33 ? selectedPlayer : y));
						}
					}
				}
			}
		}
		break;

		case notifymsgfakemoney:
		{
			Menu::Title("Notifications With Money");

			/*if (!notifyMsgAllCase)
				loadPlayerInfo(selectedPlayer);*/

			if (Menu::IntChar("~f~Custom Fake Money", customfakemoneynotification, fakemoneynotify, 0, customfakemoneynotification.size() - 1, 2)) {
				int Mnum = NumberKeyboard();
				for (int y = 0; y < 32; y++) {
					if (!notifyMsgAllCase) y = 33;
					if (!get_player_ped(y == 33 ? selectedPlayer : y)) continue;

					DWORD64 args[14] = { SEND_NOTIFICATION_MESSAGES, y == 33 ? selectedPlayer : y, atoi(customfakemoneynotification.at(fakemoneynotify + 1)), Mnum };
					SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 14, 1 << (y == 33 ? selectedPlayer : y));
					if (flashmapwithnotify) {
						DWORD64 args[14] = { SEND_NOTIFICATION_MESSAGES, y == 33 ? selectedPlayer : y, FLASH_MAP_HASH_ID, 44,44,44,44,44,44,44,44,44,44,44 };
						SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 14, 1 << (y == 33 ? selectedPlayer : y));
					}
				}
			}

			for (int x = 0; x < notificationmessagesoutput.size(); x++) {
				if (!notifyMsgCheckFlag(notificationmessagesoutput.at(x), "$")) continue; //fix
				if (Menu::Option(notificationmessagesoutput.at(x).output_name.c_str())) {
					std::vector<int> playerslist;
					for (int y = 0; y < 32; y++) {
						if (get_player_ped(y))
							playerslist.push_back(y);
					}

					for (int y = 0; y < 32; y++) {
						if (!notifyMsgAllCase) y = 33;
						if (!get_player_ped(y == 33 ? selectedPlayer : y)) continue;

						DWORD64 args[14] = { SEND_NOTIFICATION_MESSAGES, y == 33 ? selectedPlayer : y, notificationmessagesids[x], 123456789 - rand() % 123456789, playerslist.at(rand() % playerslist.size()), playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()), };
						SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 14, 1 << (y == 33 ? selectedPlayer : y));
						if (flashmapwithnotify) {
							DWORD64 args[14] = { SEND_NOTIFICATION_MESSAGES, y == 33 ? selectedPlayer : y, FLASH_MAP_HASH_ID, playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1) };
							SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 14, 1 << (y == 33 ? selectedPlayer : y));
						}
					}
				}
			}
		}
		break;

		case notifymsgotherplrnames:
		{
			Menu::Title("Notifications With Players Names");

			/*if (!notifyMsgAllCase)
				loadPlayerInfo(selectedPlayer);*/

			for (int x = 0; x < notificationmessagesoutput.size(); x++) {
				if (notifyMsgCheckFlag(notificationmessagesoutput.at(x), "delno")) continue;
				if (Menu::Option(notificationmessagesoutput.at(x).output_name.c_str())) {
					std::vector<int> playerslist;
					for (int y = 0; y < 32; y++) {
						if (get_player_ped(y))
							playerslist.push_back(y);
					}

					for (int y = 0; y < 32; y++) {
						if (!notifyMsgAllCase) y = 33;
						if (!get_player_ped(y == 33 ? selectedPlayer : y)) continue;

						DWORD64 args[14] = { SEND_NOTIFICATION_MESSAGES, y == 33 ? selectedPlayer : y, notificationmessagesids[x], 123456789 - rand() % 123456789, playerslist.at(rand() % playerslist.size()), playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()), };
						SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 14, 1 << (y == 33 ? selectedPlayer : y));
						if (flashmapwithnotify) {
							DWORD64 args[14] = { SEND_NOTIFICATION_MESSAGES, y == 33 ? selectedPlayer : y, FLASH_MAP_HASH_ID, playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1) };
							SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 14, 1 << (y == 33 ? selectedPlayer : y));
						}
					}
				}
			}
		}
		break;

		case notifymsglocalname:
		{
			Menu::Title("Notifications With Your Name");

			/*if (!notifyMsgAllCase)
				loadPlayerInfo(selectedPlayer);*/

			for (int x = 0; x < notificationmessagesoutput.size(); x++) {
				if (!notifyMsgCheckFlag(notificationmessagesoutput.at(x), "l")) continue;
				if (Menu::Option(notificationmessagesoutput.at(x).output_name.c_str())) {
					std::vector<int> playerslist;
					for (int y = 0; y < 32; y++) {
						if (get_player_ped(y))
							playerslist.push_back(y);
					}

					for (int y = 0; y < 32; y++) {
						if (!notifyMsgAllCase) y = 33;
						if (!get_player_ped(y == 33 ? selectedPlayer : y)) continue;

						DWORD64 args[14] = { SEND_NOTIFICATION_MESSAGES, y == 33 ? selectedPlayer : y, notificationmessagesids[x], 123456789 - rand() % 123456789, playerslist.at(rand() % playerslist.size()), playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()), };
						SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 14, 1 << (y == 33 ? selectedPlayer : y));
						if (flashmapwithnotify) {
							DWORD64 args[14] = { SEND_NOTIFICATION_MESSAGES, y == 33 ? selectedPlayer : y, FLASH_MAP_HASH_ID, playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1) };
							SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 14, 1 << (y == 33 ? selectedPlayer : y));
						}
					}
				}
			}
		}
		break;

		case notifymsgnonames:
		{
			Menu::Title("Notifications With No Names");

			/*if (!notifyMsgAllCase)
				loadPlayerInfo(selectedPlayer);*/

			for (int x = 0; x < notificationmessagesoutput.size(); x++) {
				if (!notifyMsgCheckFlag(notificationmessagesoutput.at(x), "n")) continue;
				if (Menu::Option(notificationmessagesoutput.at(x).output_name.c_str())) {
					std::vector<int> playerslist;
					for (int y = 0; y < 32; y++) {
						if (get_player_ped(y))
							playerslist.push_back(y);
					}

					for (int y = 0; y < 32; y++) {
						if (!notifyMsgAllCase) y = 33;
						if (!get_player_ped(y == 33 ? selectedPlayer : y)) continue;

						DWORD64 args[14] = { SEND_NOTIFICATION_MESSAGES, y == 33 ? selectedPlayer : y, notificationmessagesids[x], 123456789 - rand() % 123456789, playerslist.at(rand() % playerslist.size()), playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()), };
						SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 14, 1 << (y == 33 ? selectedPlayer : y));
						if (flashmapwithnotify) {
							DWORD64 args[14] = { SEND_NOTIFICATION_MESSAGES, y == 33 ? selectedPlayer : y, FLASH_MAP_HASH_ID, playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1) };
							SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 14, 1 << (y == 33 ? selectedPlayer : y));
						}
					}
				}
			}
		}
		break;

		case notifymsgorg:
		{
			Menu::Title("Notifications For CEO");

			/*if (!notifyMsgAllCase)
				loadPlayerInfo(selectedPlayer);*/

			for (int x = 0; x < notificationmessagesoutput.size(); x++) {
				if (!notifyMsgCheckFlag(notificationmessagesoutput.at(x), "o")) continue;
				if (Menu::Option(notificationmessagesoutput.at(x).output_name.c_str())) {
					std::vector<int> playerslist;
					for (int y = 0; y < 32; y++) {
						if (get_player_ped(y))
							playerslist.push_back(y);
					}

					for (int y = 0; y < 32; y++) {
						if (!notifyMsgAllCase) y = 33;
						if (!get_player_ped(y == 33 ? selectedPlayer : y)) continue;

						DWORD64 args[14] = { SEND_NOTIFICATION_MESSAGES, y == 33 ? selectedPlayer : y, notificationmessagesids[x], 123456789 - rand() % 123456789, playerslist.at(rand() % playerslist.size()), playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()), };
						SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 14, 1 << (y == 33 ? selectedPlayer : y));
						if (flashmapwithnotify) {
							DWORD64 args[14] = { SEND_NOTIFICATION_MESSAGES, y == 33 ? selectedPlayer : y, FLASH_MAP_HASH_ID, playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1) };
							SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 14, 1 << (y == 33 ? selectedPlayer : y));
						}
					}
				}
			}
		}
		break;

		case notifymsgbannereffect:
		{
			Menu::Title("Notifications With Effect");

			/*if (!notifyMsgAllCase)
				loadPlayerInfo(selectedPlayer);*/

			for (int x = 0; x < notificationmessagesoutput.size(); x++) {
				if (!notifyMsgCheckFlag(notificationmessagesoutput.at(x), "c")) continue;
				if (Menu::Option(notificationmessagesoutput.at(x).output_name.c_str())) {
					std::vector<int> playerslist;
					for (int y = 0; y < 32; y++) {
						if (get_player_ped(y))
							playerslist.push_back(y);
					}

					for (int y = 0; y < 32; y++) {
						if (!notifyMsgAllCase) y = 33;
						if (!get_player_ped(y == 33 ? selectedPlayer : y)) continue;

						DWORD64 args[14] = { SEND_NOTIFICATION_MESSAGES, y == 33 ? selectedPlayer : y, notificationmessagesids[x], 123456789 - rand() % 123456789, playerslist.at(rand() % playerslist.size()), playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()),  playerslist.at(rand() % playerslist.size()), };
						SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 14, 1 << (y == 33 ? selectedPlayer : y));
						if (flashmapwithnotify) {
							DWORD64 args[14] = { SEND_NOTIFICATION_MESSAGES, y == 33 ? selectedPlayer : y, FLASH_MAP_HASH_ID, playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1),playerslist.at(playerslist.size() - 1) };
							SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 14, 1 << (y == 33 ? selectedPlayer : y));
						}
					}
				}
			}
		}
		break;

		case allappartments:
		{
			Menu::Title("Teleport To Apartments");
			for (int x = 0; x < appartments.size(); x++) {
				if (Menu::Option(appartments.at(x))) {
					for (int y = 0; y < 32; y++) {
						if (get_player_ped(y) && player_id() != y) {
							DWORD64 arguments[9] = { TP_TO_APARTMENTS, y, y, -1, 1, x, 1, 1, 1 };
							SCRIPT::TRIGGER_SCRIPT_EVENT(1, arguments, 9, 1 << y);
						}
					}
				}
			}
		}
		break;

		case onlineoptions:
		{
			playerinfo();
			Menu::Title(get_player_name(selectedPlayer));

			if (Menu::Toggle("Spectate", spectate)) {
				!spectate ? Spectate(0) : NULL;
			}

			if (Menu::MenuOption("~g~Nice Options", onlineniceoptions)) {}
			if (Menu::MenuOption("~r~Abuse Options", onlineabuseoptions)) {}
			if (Menu::MenuOption("Send Notifications", notificationmessages)) { notifyMsgAllCase = true; }
			if (Menu::MenuOption("Effects On Player", onlineeffects)) {}
			if (Menu::MenuOption("Attach Objects", onlineattachobjects)) {}
			if (Menu::MenuOption("Send Peds", onlinesendpeds)) {}

			if (versUsed != 1) {

				if (Menu::Option("~y~Ram Player [VIP]")) {
					float offset;
					Hash vehmodel = $("TAXI"); //This is the vehicle the player will get ramed with, you can change it to any vehicle. Planes too
					Hooking::request_model(vehmodel);

					while (!Hooking::has_model_loaded(vehmodel)) WAIT(0);
					Vector3 pCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 0.0, -10.0, 0.0);

					if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
					{
						Vector3 dim1, dim2;
						GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

						offset = dim2.y * 1.6;

						Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer));
						float rot = (ENTITY::GET_ENTITY_ROTATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 0)).z;

						Vector3 pos = { pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), pCoords.z };

						Vehicle veh = create_vehicle(vehmodel, pos, rot, 1, 1);

						//VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
						ENTITY::SET_ENTITY_VISIBLE(veh, true, 0);
						VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 700.0);
					}

				}
			}

			if (versUsed == 3) {
				if (Menu::Option("~p~Send Attack Buzzard [PREMIUM]")) {
					buzzardAttack(selectedPlayer);
				}
			}

			if (Menu::Toggle("Flash Map", flashmap)) {}

			/*if (Menu::Option("Set 10k Bounty On Player")) {
				for (int i = 0; i < 32; i++) {
					DWORD64 args[22] = { SET_BOUNTY, i, selectedPlayer, 0, 10000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, IdkGlob_xxxxx_f_9(), IdkGlob_xxxxx_f_10() };
					SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 22, 1 << i);
				}
			}*/

			if (Menu::Option("Teleport To Player")) {
				Vector3 p = get_player_coords(selectedPlayer);
				TpTo(p);
			}

			if (Menu::Option("Steal Outfit")) {
				stealOutfit();
			}

			
			if (Menu::Option("Teleport In Vehicle")) {
				Vector3 p = get_player_coords(selectedPlayer);
				TpTo(p);
				WAIT(400);
				SetPedInVehicle(player_ped_id(), get_player_ped(selectedPlayer));
			}
		}
		break;

		case onlinesendpeds:
		{
			Menu::Title("Send Ped");

			if (Menu::IntChar("Ped Animation", animOutputList, animPed, 0, animOutputList.size() - 1)) {}
			if (Menu::IntChar("Ped Weapon", weaponNames1, weaponPed, 0, 17)) {}
			if (Menu::Toggle("Spawn God Modded", godmodpedbool)) {}
			if (Menu::Option("Clone Player"))
			{
				int clone = PED::CLONE_PED(get_player_ped(selectedPlayer), 1, 1, 1);
				if (weaponPed != 0) {
					Hooking::give_delayed_weapon_to_ped(clone, $(weaponNames[weaponPed]), 9999, true);
					PED::SET_PED_CAN_SWITCH_WEAPON(clone, true);
				}
				if (is_ped_in_any_vehicle(get_player_ped(selectedPlayer))) {
					RequestControlOfEntity(clone);
					SetPedInVehicle(clone, get_player_ped(selectedPlayer));
				}
				if (animPed != 0)
				{
					RequestControlOfEntity(clone);
					STREAMING::REQUEST_ANIM_DICT(animDictList[animPed]);
					if (STREAMING::HAS_ANIM_DICT_LOADED((animDictList[animPed])))
						Hooking::ai_task_play_anim(clone, animDictList[animPed], animNameList[animPed], 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
				}
				if (godmodpedbool) {
					RequestControlOfEntity(clone);
					handle_to_ptr<CPed>(clone)->btGodMode = 1;
				}
				ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&clone);
			}
			if (Menu::Option("Send BodyGuard"))
				bodyguard("u_m_m_jesus_01");
			if (Menu::Option("Send Enemy"))
				enemy("u_m_y_pogo_01");
			if (Menu::Option("Send Topless Girl"))
			{
				Vector3 pos = get_player_coords(selectedPlayer);
				bodyguard("A_F_Y_Topless_01");
			}
			if (Menu::Option("Send Mountain Lion"))
			{
				Vector3 pos = get_player_coords(selectedPlayer);
				bodyguard("A_C_MtLion");
			}
			if (Menu::Option("Send Chimp"))
			{
				Vector3 pos = get_player_coords(selectedPlayer);
				enemy("A_C_Chimp");
			}
			if (Menu::Option("Send Dog"))
			{
				Vector3 pos = get_player_coords(selectedPlayer);
				bodyguard("a_c_chop");
			}
			if (Menu::Option("Send Swat"))
			{
				Vector3 pos = get_player_coords(selectedPlayer);
				enemy("S_M_Y_Swat_01");
			}

			if (Menu::Option("Denise"))
	
				{
					bodyguard("ig_denise_p");
				}
			if (Menu::Option("Tonya"))
	
				{
					bodyguard( "csb_tonya");
				}
			if (Menu::Option("Bride"))
	
				{
					bodyguard("csb_bride");
				}
			if (Menu::Option("Kerry Mcintosh"))
	
				{
					bodyguard("ig_kerrymcintosh");
				}
			if (Menu::Option("Michelle"))
	
				{
					bodyguard("cs_michelle");
				}
			if (Menu::Option("Tanisha"))
	
				{
					bodyguard( "cs_tanisha");
				}
			if (Menu::Option("Hooker")) 
	
				{
					bodyguard("s_f_y_hooker_03");
				}
			if (Menu::Option("Promourn"))
	
				{
					bodyguard( "u_f_m_promourn_01");
				}
			if (Menu::Option("Spy Actress"))
	
				{
					bodyguard("u_f_y_spyactress");
				}
			if (Menu::Option("Bevhills"))
				{
					bodyguard( "a_f_y_bevhills_01");
				}
			if (Menu::Option("Genhot"))
				{
					bodyguard( "a_f_y_genhot_01");
				}
			if (Menu::Option("Anita"))
	
				{
					bodyguard("csb_anita");
				}
			if (Menu::Option("Imporage"))
	
				{
					bodyguard("u_m_y_Imporage");
				}
			if (Menu::Option("Justin"))
	
				{
					bodyguard("u_m_y_Justin");
				}
			if (Menu::Option("Alien"))
				{
					bodyguard("s_m_m_movalien_01");
				}
			if (Menu::Option("Zombie"))
				{
					bodyguard("u_m_y_zombie_01");
				}
			if (Menu::Option("Sheriff"))
				{
					bodyguard("s_f_y_sheriff_01");
				}
			if (Menu::Option("Swat"))
	
				{
					bodyguard( "s_m_y_swat_01");
				}

		}
		break;

		case onlineattachobjects:
		{
			Menu::Title("Attach Objects");

			if (Menu::Option("~g~ Delete All Objects")) {
				for (int i = 0; i < 3; i++) {
					Vector3 coords = get_player_coords(selectedPlayer);
					GAMEPLAY::CLEAR_AREA_OF_PEDS(coords.x, coords.y, coords.z, 2, 0);
					GAMEPLAY::CLEAR_AREA_OF_OBJECTS(coords.x, coords.y, coords.z, 2, 0);
					GAMEPLAY::CLEAR_AREA_OF_VEHICLES(coords.x, coords.y, coords.z, 2, 0, 0, 0, 0, 0);
					for (int i = 0; i < objects.size(); i++) {
						Object obj = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(coords.x, coords.y, coords.z, 4.0, $(objects[i]), 0, 0, 1);
						if (does_entity_exist(obj) && ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(obj, get_player_ped(selectedPlayer))) {
							if (ForcedRequestControlOfEntity(obj)) {
								ENTITY::DETACH_ENTITY(obj, 1, 1);
								ENTITY::SET_ENTITY_AS_MISSION_ENTITY(obj, 1, 1);
								ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&obj);
								ENTITY::DELETE_ENTITY(&obj);
							}
						}
					}
				}
			}

			if (Menu::Option("Big Railgun"))
			{
				AttachObject("hei_prop_carrier_defense_02", selectedPlayer);
			}
			if (Menu::Option("Train"))
			{
				AttachObject("p_tram_crash_s", selectedPlayer);
			}
			if (Menu::Option("Plate"))
			{
				AttachObject("p_oil_slick_01", selectedPlayer);
			}
			if (Menu::Option("ATM"))
			{
				AttachObject("prop_atm_01", selectedPlayer);
			}
			if (Menu::Option("Big Orange"))
			{
				AttachObject("prop_juicestand", selectedPlayer);
			}
			if (Menu::Option("~r~ Attach FIRE"))
			{
				AttachObject("prop_beach_fire", selectedPlayer);
			}
		}
		break;

		case onlineniceoptions:
		{
			Menu::Title("Nice Options");
		
			if (Menu::Option("Remove All Attachment Objects")) {
				for (int i = 0; i < 3; i++) {
					Vector3 coords = get_player_coords(selectedPlayer);
					GAMEPLAY::CLEAR_AREA_OF_PEDS(coords.x, coords.y, coords.z, 2, 0);
					GAMEPLAY::CLEAR_AREA_OF_OBJECTS(coords.x, coords.y, coords.z, 2, 0);
					GAMEPLAY::CLEAR_AREA_OF_VEHICLES(coords.x, coords.y, coords.z, 2, 0, 0, 0, 0, 0);
					for (int i = 0; i < objects.size(); i++) {
						Object obj = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(coords.x, coords.y, coords.z, 4.0, $(objects[i]), 0, 0, 1);
						if (does_entity_exist(obj) && ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(obj, get_player_ped(selectedPlayer))) {
							if (ForcedRequestControlOfEntity(obj)) {
								ENTITY::DETACH_ENTITY(obj, 1, 1);
								ENTITY::SET_ENTITY_AS_MISSION_ENTITY(obj, 1, 1);
								ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&obj);
								ENTITY::DELETE_ENTITY(&obj);
							}
						}
					}
				}
			}
			
			if (Menu::Option("Allow Player Save The Vehicle ~r~RISKY")) {
				DECORATOR::DECOR_SET_INT(get_vehicle_ped_is_in(get_player_ped(selectedPlayer), 1), "Player_Vehicle", NETWORK::_NETWORK_HASH_FROM_PLAYER_HANDLE(selectedPlayer));
			}

			if (Menu::Float("Edit Vehicle Speed", remoteEditEngine, -200, 300, 10)) {
				if (IsKeyPressed(VK_NUMPAD5)) {
					int veh = get_vehicle_ped_is_in(get_player_ped(selectedPlayer), 1);
					veh ? ForcedRequestControlOfEntity(veh) ? VEHICLE::_SET_VEHICLE_ENGINE_POWER_MULTIPLIER(veh, remoteEditEngine) :
						notifyMap("~r~Failed") : notifyMap("~r~Player Isn't In Vehicle");
				}
			}

			if (Menu::Float("Edit Vehicle Power", remoteEditEngineT, -200, 300, 10)) {
				if (IsKeyPressed(VK_NUMPAD5)) {
					int veh = get_vehicle_ped_is_in(get_player_ped(selectedPlayer), 1);
					veh ? ForcedRequestControlOfEntity(veh) ? VEHICLE::_SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER(veh, remoteEditEngineT) :
						notifyMap("~r~Failed") : notifyMap("~r~Player Isn't In Vehicle");
				}
			}

			if (Menu::Option("Remove Wanted Level")) {
				DWORD64 args[3] = { REMOVE_WANTED_LEVEL, selectedPlayer, GlobForNeverWanted(selectedPlayer) };
				SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 3, 1 << selectedPlayer);
			}

			/*if (Menu::Toggle("Money Rain 2.5k", rainmoneybool)) {}
			
			if (versUsed != 1) {
				if (Menu::Toggle("~y~Give Money Gun 2.5k[VIP]", onlinemoneygun2_5k)) {}
			}*/

		/*	if (Menu::Option("Give 10k Money As CEO")) {
				static bool b = 0;
				if (!b)
					notifyMap("~g~You Must Be CEO And The Player You Want Give Money Should Be In Your Organization"), b = 1;
				DWORD64 args[8] = { CEO_10K_MONEY, selectedPlayer, 20000, -1292453789, 1, GlobForNeverWanted(selectedPlayer), IdkGlob_xxxxx_f_9(), IdkGlob_xxxxx_f_10() };
				SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 8, 1 << selectedPlayer);
			}*/

			if (Menu::Option("Give All Weapons"))
				GiveAllWeapons(selectedPlayer);

			if (Menu::Option("Give All mk2 Weapons"))
				giveweapmk2(selectedPlayer);
		}
		break;

		case onlineabuseoptions:
		{
			Menu::Title("Abuse Options");

			if (Menu::Toggle("Fire Loop", FireLoop)) {}
			if (Menu::Toggle("Water Loop", WaterLoop)) {}
			if (Menu::Toggle("Freeze", Freeze)) {}

			if (Menu::Option("Destroy PERSONAL Veh")) {
				DWORD64 args[3] = { DESTROY_PERSONAL_VEHICLE, selectedPlayer, selectedPlayer };
				SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 3, 1 << selectedPlayer);
			}

			if (Menu::Option("Kick From Car")) 
				ClearTasks(selectedPlayer);

			if (Menu::Option("Kick Player")) {
				kickPlayer(selectedPlayer, 0);
				kickPlayer(selectedPlayer, -2);
				for (int x = 1; x < 7; x++) {
					kickPlayer(selectedPlayer, x);
				}
			}

			if (Menu::Option("Kick Player v2")) {
				kickPlayer(selectedPlayer, 0);
				kickPlayer(selectedPlayer, -2);
				for (int x = 7; x < 13; x++) {
					kickPlayer(selectedPlayer, x);
				}
			}

			if (Menu::Option("Kick Player v3")) {
				kickPlayer(selectedPlayer, 36);
				kickPlayer(selectedPlayer, 40);
				kickPlayer(selectedPlayer, 38);
				kickPlayer(selectedPlayer, 16);
			}

			if (Menu::Option("Insta Crash")) {
				crashPlayerTimer = GetTickCount();
				crashPlayerEvent = true;
			}

			if (Menu::Option("Silent Kill Player")) {
				Vector3 pos = get_player_coords(selectedPlayer);
				Ped pPed = get_player_ped(selectedPlayer);
				add_owned_explossion(pPed, { pos.x, pos.y, pos.z + 5.f }, 29, 0, 1, 0);
				add_owned_explossion(pPed, { pos.x + 10.f, pos.y, pos.z + 5.f }, 29, 0, 1, 0);
				add_owned_explossion(pPed, { pos.x - 10.f, pos.y, pos.z + 5.f }, 29, 0, 1, 0);
				add_owned_explossion(pPed, { pos.x, pos.y + 10.f, pos.z + 5.f }, 29, 0, 1, 0);
				add_owned_explossion(pPed, { pos.x, pos.y - 10.f, pos.z + 5.f }, 29, 0, 1, 0);
			}
			if (Menu::Option("Airstrike")) {
				Vector3 Coords = get_player_coords(selectedPlayer);
				Coords.z += 15;
				GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(Coords.x, Coords.y, Coords.z + 35, Coords.x, Coords.y, Coords.z, 250, 1, $("VEHICLE_WEAPON_SPACE_ROCKET"), get_player_ped(selectedPlayer), 1, 1, 0xbf800000);
				GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(Coords.x, Coords.y, Coords.z + 30, Coords.x, Coords.y, Coords.z, 250, 0, $("VEHICLE_WEAPON_SPACE_ROCKET"), 0, 1, 1, 0xbf800000);
				GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(Coords.x, Coords.y, Coords.z + 55, Coords.x, Coords.y, Coords.z, 100, false, 0xF8A3939F, get_player_ped(selectedPlayer), true, true, 0xbf800000);
			}

			if (Menu::Option("Blame Kill")) {
				int Playerped = get_player_ped(selectedPlayer);
				for (int x = 0; x < 32; x++) {
					if (get_player_ped(x) && x != player_id() && x != selectedPlayer) {
						Vector3 playerPos = get_player_coords(x);
						add_owned_explossion(Playerped, playerPos, 1, true, false, 2.f);
					}
				}
			}

			if (Menu::Option("Silent Blame Kill")) {
				int Playerped = get_player_ped(selectedPlayer);
				for (int x = 0; x < 32; x++) {
					if (get_player_ped(x) && x != player_id() && x != selectedPlayer) {
						Vector3 playerPos = get_player_coords(x);
						add_owned_explossion(Playerped, playerPos, 1, false, true, 0.f);
					}
				}
			}

			if (Menu::Option("Trap In Cage")) {
				ClearTasks(selectedPlayer);
				WAIT(100);
				trap(selectedPlayer);
			}

			if (Menu::Option("Send To Job")) {
				DWORD64 args[4] = { SEND_TO_JOB, selectedPlayer, 0, 0 };
				SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 4, 1 << selectedPlayer);
			}

			if (Menu::Option("Force To Mission")) {
				DWORD64 args[4] = { SEND_TO_JOB_2, selectedPlayer, 0, 0 };
				SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 4, 1 << selectedPlayer);
			}

			if (Menu::Option("Transaction Error")) {
				std::uint64_t args[8] = { TRANSACTION_FAIL, selectedPlayer, 10000, 0, 0, GlobForNeverWanted(selectedPlayer), IdkGlob_xxxxx_f_9(), IdkGlob_xxxxx_f_10() };
				SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 8, 1 << selectedPlayer);
			}

			if (Menu::Option("GTA Banner Effect")) {
				DWORD64 args[4] = { GTA_BANNER_EFFECT, selectedPlayer, 0, 0 };
				SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 4, 1 << selectedPlayer);
			}

			if (Menu::IntChar("Send Invites", inviteSpamTypes, sendinvitesint, 0, inviteSpamTypes.size() - 1)) {
				if (IsKeyPressed(VK_NUMPAD5)) {
					DWORD64 args[3] = { SEND_INVITES, selectedPlayer, inviteSpamTypesInt[sendinvitesint] };
					SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 4, 1 << selectedPlayer);
				}
			}

			if (Menu::Option("Tp To Eclipse Tower")) {
				DWORD64 arguments[9] = { TP_TO_APARTMENTS, selectedPlayer, 1, -1, 1, 1, 0, 0, 0 };
				SCRIPT::TRIGGER_SCRIPT_EVENT(1, arguments, 9, 1 << selectedPlayer);
			}

			if (Menu::Option("CEO Kick")) {
				uint64_t args[4];
				args[0] = CEO_KICK;
				args[1] = selectedPlayer;
				args[2] = 1;
				args[3] = 5;
				SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 4, 1 << selectedPlayer);
			}

			if (Menu::Option("CEO Ban")) {
				uint64_t args[4];
				args[0] = CEO_BAN;
				args[1] = selectedPlayer;
				args[2] = 1;
				args[3] = 5;
				SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 4, 1 << selectedPlayer);

			}

			if (Menu::Option("Infinite Loading")) {
				DWORD64 args[9] = { TP_TO_APARTMENTS, selectedPlayer, 0, -1, 1, 115, 0, 0, 0 };
				SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 9, 1 << selectedPlayer);
			}

		}
		break;

		case protections:
		{
			Menu::Title("Protections");
		
			//if (Menu::Toggle("Anti Report", antiReport)) {}
			//if (Menu::Toggle("Anti Kick", antiKick)) {}
			if (Menu::Toggle("Anti Freeze", antiFreeze)) {}
			if (Menu::Toggle("Anti Attach", antiAttachment)) {}
			if (Menu::Toggle("Anti Explosion", antiExplosion)) {}
			if (Menu::Toggle("Anti Sound", antiSound)) {}
			if (Menu::Toggle("Anti Stars", antiStars)) {}
			if (Menu::Toggle("Anti Stat", antiStats)) {}

			if (Menu::Toggle("Anti AFK Kick", idlekickprot)) {}

			if (Menu::Toggle("Block All Scripted Events", blockAllScrictEvents)) {}

			if (Menu::Toggle("Non Host Kicks", nonHostKicksProtBool)) {}

			if (Menu::Toggle("Force To New Lobby", forceToNewLobbyProt)) {}

			if (Menu::Toggle("Teleport", TpToAppsProtection)) {}

			if (Menu::Toggle("Infinity Loading", infLoadingProt)) {}

			if (Menu::Toggle("Transaction Error", transactionErrorProt)) {}

			if (Menu::Toggle("Force To Missions", ForceToMissionProt)) {}

			if (Menu::Toggle("Recieve Invites", InvitesProtection)) {}

			if (Menu::Toggle("Securoserv Ban", CeoBanProtection)) {}

			if (Menu::Toggle("securoserv Kick", CEOKickProtection)) {}

			if (Menu::Toggle("Stop And Kick From Car", kickCarProtection)) {}

			if (Menu::Toggle("Camera Reset", camResetProtection)) {}

			if (Menu::Toggle("GTA Banner Effect", gtaBannerEffectProt)) {}

		}
		break;


		case misc:
		{
			Menu::Title("Misc");

			if (Menu::Toggle("Blackhole", blackHole::var::toggle)) {}

			if (Menu::Float("Blackhole X", blackHole::var::blackholeX, 0, 999, 5)) {}
			if (Menu::Float("Blackhole Y", blackHole::var::blackholeY, 0, 999, 5)) {}
			if (Menu::Float("Blackhole Z", blackHole::var::blackholeZ, 0, 999, 5)) {}

			if (Menu::Option("Set Current Position")) {
				blackHole::setCurrentPos();
			}
			
			if (Menu::Toggle("Delete Nearby Vehicles", deletenearvehsbool)) {}
			if (Menu::Toggle("Boost Nearby Vehicles", boostnearvehbool)) {}
			if (Menu::Toggle("Explode Nearby Vehicles", explodenearvehbool)) {}
			if (Menu::Toggle("Explode Nearby Peds", explodenearpedbool)) {}
		
			if (Menu::Option("Reset Wave Intensity"))
			{
				WATER::_RESET_CURRENT_INTENSITY;
			}
			if (Menu::Option("Flash Minimap"))
			{
				UI::FLASH_MINIMAP_DISPLAY();
			}
			if (Menu::Toggle("Slow Motion", slowMotion))
			{
				if (slowMotion) { GAMEPLAY::SET_TIME_SCALE(0.6f); }
				else { GAMEPLAY::SET_TIME_SCALE(1.f); }
			}
			
		}
		break;

		case teleport:
		{
			Menu::Title("Teleport");

			if (Menu::MenuOption("IPLs", ipl)) {}

			if (Menu::Toggle("Auto TP To Waypoint (F12)", autoToWaypoint)) {}
			
			static int tpForw;
			if (Menu::Int("Forward", tpForw, 1, 10)) {
				if (IsKeyPressed(VK_NUMPAD5)) {
					TpForward(tpForw);
				}
			}

			if (Menu::Option("Island")) {
				Vector3 Coords;
				Coords.x = 336.158; Coords.y = 4373.934; Coords.z = 64.46;
				TpTo(Coords);
			}
			if (Menu::Option("Island 2")) {
				Vector3 Coords;
				Coords.x = 229.7106; Coords.y = 7408.79; Coords.z = 17.4348;
				TpTo(Coords);
			}
			if (Menu::Option("Island 3")) {
				Vector3 Coords;
				Coords.x = 3675.20483; Coords.y = 4945.6969; Coords.z = 17.12285;
				TpTo(Coords);
			}
			if (Menu::Option("Boat Under Water")) {
				Vector3 Coords;
				Coords.x = 3156.38355; Coords.y = -355.16663; Coords.z = -20.09742;
				TpTo(Coords);
			}
			if (Menu::Option("Cave In Sea")) {
				Vector3 Coords;
				Coords.x = 3067.58; Coords.y = 2212.25; Coords.z = 3.00;
				TpTo(Coords);
			}
			if (Menu::Option("On Object In Sea")) {
				Vector3 Coords;
				Coords.x = 3067.58; Coords.y = 2212.25; Coords.z = 3.00;
				TpTo(Coords);
			}
			if (Menu::Option("Galileo Observatory")) {
				Vector3 Coords;
				Coords.x = -430.905; Coords.y = 1135.2722; Coords.z = 325.904;
				TpTo(Coords);
			}
			if (Menu::Option("Vinewood Sign")) {
				Vector3 Coords;
				Coords.x = 719.30; Coords.y = 1204.76; Coords.z = 325.88;
				TpTo(Coords);
			}
			if (Menu::Option("Beach")) {
				Vector3 Coords;
				Coords.x = -256.43; Coords.y = 6569.93; Coords.z = 2.66;
				TpTo(Coords);
			}
			if (Menu::Option("Mine Shaft")) {
				Vector3 Coords;
				Coords.x = -604.92; Coords.y = 2113.95; Coords.z = 127.11;
				TpTo(Coords);
			}
			if (Menu::Option("Ghost Girl")) {
				Vector3 Coords;
				Coords.x = 3102.46f; Coords.y = 5554.84f; Coords.z = 189.56;
				TpTo(Coords);
			}
			if (Menu::Option("Mount Chiliad")) {
				Vector3 Coords;
				Coords.x = 496.75f; Coords.y = 5591.17f; Coords.z = 795.03f;
				TpTo(Coords);
			}
			if (Menu::Option("On A Built")) {
				Vector3 Coords;
				Coords.x = 477.9694; Coords.y = -87.9033; Coords.z = 117.6340;
				TpTo(Coords);
			}
			if (Menu::Option("Maze Bank")) {
				Vector3 Coords;
				Coords.x = -74.94243; Coords.y = -818.63446; Coords.z = 326.174347;
				TpTo(Coords);
			}
			if (Menu::Option("Military Base")) {
				Vector3 Coords;
				Coords.x = -2012.8470f; Coords.y = 2956.5270f; Coords.z = 32.8101f;
				TpTo(Coords);
			}
			if (Menu::Option("Zancudo Tower")) {
				Vector3 Coords;
				Coords.x = -2356.0940; Coords.y = 3248.645; Coords.z = 101.4505;
				TpTo(Coords);
			}
			if (Menu::Option("Mask Shop")) {
				Vector3 Coords;
				Coords.x = -1338.16;
				Coords.y = -1278.11;
				Coords.z = 4.87;
				TpTo(Coords);
			}
			if (Menu::Option("LSC")) {
				Vector3 Coords;
				Coords.x = -373.01; Coords.y = -124.91; Coords.z = 38.31;
				TpTo(Coords);
			}
			if (Menu::Option("Ammunation")) {
				Vector3 Coords;
				Coords.x = 247.3652; Coords.y = -45.8777; Coords.z = 69.9411;
				TpTo(Coords);
			}
			if (Menu::Option("Airport")) {
				Vector3 Coords;
				Coords.x = -1102.2910f; Coords.y = -2894.5160f; Coords.z = 13.9467f;
				TpTo(Coords);
			}
			if (Menu::Option("Clothes Store")) {
				Vector3 Coords;
				Coords.x = -718.91; Coords.y = -158.16; Coords.z = 37.00;
				TpTo(Coords);
			}
			if (Menu::Option("Waterfall")) {
				Vector3 Coords;
				Coords.x = -597.9525f; Coords.y = 4475.2910f; Coords.z = 25.6890f;
				TpTo(Coords);
			}
			if (Menu::Option("FIB")) {
				Vector3 Coords;
				Coords.x = 135.5220f; Coords.y = -749.0003f; Coords.z = 260.0000f;
				TpTo(Coords);
			}
			if (Menu::Option("Human Labs")) {
				Vector3 Coords;
				Coords.x = 3617.231f; Coords.y = 3739.871f; Coords.z = 28.6901f;
				TpTo(Coords);
			}
			if (Menu::Option("MMI")) {
				Vector3 Coords;
				Coords.x = -222.1977; Coords.y = -1185.8500; Coords.z = 23.0294;
				TpTo(Coords);
			}
			if (Menu::Option("Sandy Shores Airfield")) {
				Vector3 Coords;
				Coords.x = 1741.4960f; Coords.y = 3269.2570f; Coords.z = 41.6014f;
				TpTo(Coords);
			}
			if (Menu::Option("Custom Coords (x,y,z)"))
			{
				Vector3 pos = { (float)NumberKeyboard() , (float)NumberKeyboard() , (float)NumberKeyboard() };
				TpTo(pos);
			}

			if (Menu::Option("Get Coords")) {
				Vector3 p = get_entity_coords(get_player_ped(selectedPlayer), 1);
				notifyMap("~f~x = %f", p.x);
				notifyMap("~o~y = %f", p.y);
				notifyMap("~g~z = %f", p.z);
			}

		}
		break;

		case moddedveh:
		{
			Menu::Title("Modded Vehicles");

			if (Menu::Option("6x6 War RC")) {
				moddedVeh6x6Monster(player_id(), spawnincar, 0);
			}
			if (Menu::Option("BIG Dick Truck")) {
				moddedvehBigOrangeDick(player_id(), spawnincar, 0);
			}
			if (Menu::Option("Gas Cyclinder")) {
				gasCylinderMK2(player_id(), spawnincar, 0);
			}
		}
		break;

		case ipl:
		{
			Menu::Title("IPLs");
			if (Menu::Option("North Yankton")) {
				STREAMING::REQUEST_IPL("prologue01");
				STREAMING::REQUEST_IPL("Prologue01c");
				STREAMING::REQUEST_IPL("Prologue01d");
				STREAMING::REQUEST_IPL("Prologue01e");
				STREAMING::REQUEST_IPL("Prologue01f");
				STREAMING::REQUEST_IPL("Prologue01g");
				STREAMING::REQUEST_IPL("prologue01h");
				STREAMING::REQUEST_IPL("prologue01i");
				STREAMING::REQUEST_IPL("prologue01j");
				STREAMING::REQUEST_IPL("prologue01k");
				STREAMING::REQUEST_IPL("prologue01z");
				STREAMING::REQUEST_IPL("prologue02");
				STREAMING::REQUEST_IPL("prologue03");
				STREAMING::REQUEST_IPL("prologue03b");
				STREAMING::REQUEST_IPL("prologue03_grv_cov");
				STREAMING::REQUEST_IPL("prologue03_grv_dug");
				STREAMING::REQUEST_IPL("prologue03_grv_fun");
				STREAMING::REQUEST_IPL("prologue04");
				STREAMING::REQUEST_IPL("prologue04b");
				STREAMING::REQUEST_IPL("prologue04_cover");
				STREAMING::REQUEST_IPL("prologue05");
				STREAMING::REQUEST_IPL("prologue05b");
				STREAMING::REQUEST_IPL("prologue06");
				STREAMING::REQUEST_IPL("prologue06b");
				STREAMING::REQUEST_IPL("prologue06_int");
				STREAMING::REQUEST_IPL("prologuerd");
				STREAMING::REQUEST_IPL("prologuerdb");
				STREAMING::REQUEST_IPL("prologue_DistantLights");
				STREAMING::REQUEST_IPL("prologue_grv_torch");
				STREAMING::REQUEST_IPL("prologue_m2_door");
				STREAMING::REQUEST_IPL("prologue_LODLights");
				STREAMING::REQUEST_IPL("DES_ProTree_start");
				Vector3 Coords;
				Coords.x = 3595.39673f; Coords.y = -4893.727f; Coords.z = 115.838394f;
				TpTo(Coords);
			}
			if (Menu::Option("Porn Yacht")) {
				STREAMING::REQUEST_IPL("smboat");
				Vector3 Coords;
				Coords.x = -2045.8f; Coords.y = -1031.2f; Coords.z = 11.9f;
				TpTo(Coords);
			}
			if (Menu::Option("Aircraft Carrier")) {
				STREAMING::REQUEST_IPL("hei_carrier");
				STREAMING::REQUEST_IPL("hei_carrier_DistantLights");
				STREAMING::REQUEST_IPL("hei_Carrier_int1");
				STREAMING::REQUEST_IPL("hei_Carrier_int2");
				STREAMING::REQUEST_IPL("hei_Carrier_int3");
				STREAMING::REQUEST_IPL("hei_Carrier_int4");
				STREAMING::REQUEST_IPL("hei_Carrier_int5");
				STREAMING::REQUEST_IPL("hei_Carrier_int6");
				STREAMING::REQUEST_IPL("hei_carrier_LODLights");
				Vector3 Coords;
				Coords.x = 3069.330f; Coords.y = -4632.4f; Coords.z = 15.043f;
				TpTo(Coords);
			}
			if (Menu::Option("Sunken Cargoship")) {
				STREAMING::REQUEST_IPL("sunkcargoship");
				Vector3 Coords;
				Coords.x = -162.8918f; Coords.y = -2365.769f; Coords.z = 0.0f;
				TpTo(Coords);
			}
			if (Menu::Option("Hospital")) {
				STREAMING::REQUEST_IPL("RC12B_HospitalInterior");
				STREAMING::REQUEST_IPL("RC12B_Destroyed");
				Vector3 Coords;
				Coords.x = 356.8f; Coords.y = -590.1f; Coords.z = 43.3f;
				TpTo(Coords);
			}
			if (Menu::Option("Oneil Farm")) {
				STREAMING::REMOVE_IPL("farm_burnt");
				STREAMING::REMOVE_IPL("farm_burnt_props");
				STREAMING::REQUEST_IPL("farm");
				STREAMING::REQUEST_IPL("farm_props");
				STREAMING::REQUEST_IPL("farmint");
				STREAMING::REQUEST_IPL("farmint_cap");
				Vector3 Coords;
				Coords.x = 2441.2f; Coords.y = 4968.5f; Coords.z = 51.7f;
				TpTo(Coords);
			}
			if (Menu::Option("Life Invader Office")) {
				STREAMING::REQUEST_IPL("facelobby");
				STREAMING::REQUEST_IPL("facelobbyfake");
				Vector3 Coords;
				Coords.x = -1047.9f; Coords.y = -233.0f; Coords.z = 39.0f;
				TpTo(Coords);
			}
			if (Menu::Option("Cargoship")) {
				STREAMING::REQUEST_IPL("cargoship");
				Vector3 Coords;
				Coords.x = -162.8918f; Coords.y = -2365.769f; Coords.z = 9.3192f;
				TpTo(Coords);
			}
			if (Menu::Option("Jewelry Store")) {
				STREAMING::REQUEST_IPL("jewel2fake");
				STREAMING::REQUEST_IPL("post_hiest_unload");
				STREAMING::REQUEST_IPL("bh1_16_refurb");
				Vector3 Coords;
				Coords.x = -630.4f; Coords.y = -236.7f; Coords.z = 40.0f;
				TpTo(Coords);
			}
			if (Menu::Option("Morgue")) {
				STREAMING::REQUEST_IPL("Coroner_Int_on");
				Vector3 Coords;
				Coords.x = 244.9f; Coords.y = -1374.7f; Coords.z = 39.5f;
				TpTo(Coords);
			}

		}
		break;

		case weapon:
		{
			Menu::Title("Weapon");

			Menu::Toggle("~b~Night Vision", nightvisionbool);
				if (nightvisionbool)
					nightvision(true);

			Menu::Toggle("~b~Thermal Vision", thermalvisionbool);
			if (thermalvisionbool)
				thermalvision(true);

			if (versUsed == 3) {
				if (Menu::Toggle("~p~Gravity Gun[PREMIUM]", GravityGun)) {}
			}
				
			if (versUsed == 3) {
				if (Menu::Int("~p~Custom Bullets [0 = OFF][PREMIUM]", customBulletInt, 0, 32)) {}
			}

			if (versUsed != 1) {
				if (Menu::Toggle("~y~Rapid Fire[VIP]", RapidFire)) {}
			}

			if (Menu::Toggle("Explosive Ammo", ExplosiveAmmo)) {}
			if (Menu::Toggle("Fire Ammo", FireAmmo)) {}
			if (Menu::Toggle("Airstrike Weapon", airstrikegunbool)) {}
			//if (Menu::Toggle("Boost Weapon", boostweaponbool)) {}
			//if (Menu::Toggle("Boost punch", boostpunchbool)) {}
			if (Menu::Toggle("Teleport Weapon", teleportweaponbool)) {}

			if (Menu::Toggle("Aimbot Players", aimbotPlrbool)) {}
			if (Menu::Toggle("Aimbot Peds", aimbotAIbool)) {}

			if (versUsed != 1) {
				if (Menu::Toggle("~y~Money Gun 2,5k[VIP]", localmoneygun2_5k)) {}
			}
			if (Menu::Toggle("One Shoot Kill", oneshootkill)) {
				int OSKValue; oneshootkill ? OSKValue = 10000.0f : OSKValue = 1.0f;
				Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_WEAPON_MANAGER, OFFSET_WEAPON_CURRENT, OFFSET_WEAPON_BULLET_DMG }, OSKValue);
			}
			if (Menu::Toggle("No Reload", noreloadbool))
				no_reload_toggle(noreloadbool);
			if (Menu::Toggle("Infinite Ammo", infinityammobool))
				infinite_ammo_toggle(infinityammobool);
	
			
			if (Menu::Option("Give All Weapons"))
			{
				for each (Hash weapon in weaponsList)
				{
					WEAPON::GIVE_WEAPON_TO_PED(player_ped_id(), weapon, 9999, false, true);
				}
			}
			if (Menu::Option("Give Mk2 Weapons"))
				giveweapmk2(player_id());
		}
		break;

		case recovery:
		{
			Menu::Title("Recovery");
			
			Menu::IntChar("Select Character (RP)", rpCorrectionChar, rpcharselectint, 0, rpCorrectionChar.size() - 1);
			if (Menu::Int("RP Correction", rp, 0, 8000)) {
				notifyMap("if you choose this option with value 0 y can set rank manually");
				if (IsKeyPressed(VK_NUMPAD5)) {
					if (rp == 0)
						rp = NumberKeyboard();
					SetRank(rpcharselectint, rp);
					notifyMap("~g~Change Session");
				}
			}

			if (Menu::Option("Full Recovery")) {
				Hooking::stat_set_int($("MP0_SCRIPT_INCREASE_STAM"), 100, 0);
				Hooking::stat_set_int($("MP0_SCRIPT_INCREASE_STRN"), 100, 0);
				Hooking::stat_set_int($("MP0_SCRIPT_INCREASE_LUNG"), 100, 0);
				Hooking::stat_set_int($("MP0_SCRIPT_INCREASE_DRIV"), 100, 0);
				Hooking::stat_set_int($("MP0_SCRIPT_INCREASE_FLY"), 100, 0);
				Hooking::stat_set_int($("MP0_SCRIPT_INCREASE_SHO"), 100, 0);
				Hooking::stat_set_int($("MP0_SCRIPT_INCREASE_STL"), 100, 0);

				Hooking::stat_set_int($("MP0_tattoo_fm_unlocks_1"), -1, 1);
				Hooking::stat_set_int($("MP0_tattoo_fm_unlocks_2"), -1, 1);
				Hooking::stat_set_int($("MP0_tattoo_fm_unlocks_3"), -1, 1);
				Hooking::stat_set_int($("MP0_tattoo_fm_unlocks_4"), -1, 1);
				Hooking::stat_set_int($("MP0_tattoo_fm_unlocks_5"), -1, 1);
				Hooking::stat_set_int($("MP0_tattoo_fm_unlocks_6"), -1, 1);
				Hooking::stat_set_int($("MP0_tattoo_fm_unlocks_7"), -1, 1);
				Hooking::stat_set_int($("MP0_tattoo_fm_unlocks_8"), -1, 1);
				Hooking::stat_set_int($("MP0_tattoo_fm_unlocks_9"), -1, 1);
				Hooking::stat_set_int($("MP0_tattoo_fm_unlocks_10"), -1, 1);
				Hooking::stat_set_int($("MP0_tattoo_fm_unlocks_11"), -1, 1);
				Hooking::stat_set_int($("MP0_tattoo_fm_unlocks_12"), -1, 1);

				Hooking::stat_set_bool($("MP0_AWD_FMRACEWORLDRECHOLDER"), 1, 0);
				Hooking::stat_set_int($("MP0_AWD_ENEMYDRIVEBYKILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_USJS_COMPLETED"), 50, 0);
				Hooking::stat_set_int($("MP0_USJS_FOUND"), 50, 0);
				Hooking::stat_set_bool($("MP0_AWD_FMWINALLRACEMODES"), 1, 0);
				Hooking::stat_set_bool($("MP0_AWD_FMWINEVERYGAMEMODE"), 1, 0);
				Hooking::stat_set_int($("MP0_DB_PLAYER_KILLS"), 1000, 0);
				Hooking::stat_set_int($("MP0_KILLS_PLAYERS"), 1000, 0);
				Hooking::stat_set_int($("MP0_AWD_FMHORDWAVESSURVIVE"), 21, 0);
				Hooking::stat_set_int($("MP0_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, 0);
				Hooking::stat_set_int($("MP0_AWD_FM_TDM_MVP"), 60, 0);
				Hooking::stat_set_int($("MP0_AWD_HOLD_UP_SHOPS"), 20, 0);
				Hooking::stat_set_int($("MP0_AWD_RACES_WON"), 101, 0);
				Hooking::stat_set_int($("MP0_AWD_NO_ARMWRESTLING_WINS"), 21, 0);
				Hooking::stat_set_bool($("MP0_AWD_FMATTGANGHQ"), 1, 0);
				Hooking::stat_set_int($("MP0_AWD_FMBBETWIN"), 50000, 0);
				Hooking::stat_set_int($("MP0_AWD_FM_DM_WINS"), 51, 0);
				Hooking::stat_set_bool($("MP0_AWD_FMFULLYMODDEDCAR"), 1, 0);
				Hooking::stat_set_int($("MP0_AWD_FM_DM_TOTALKILLS"), 500, 0);
				Hooking::stat_set_int($("MP0_MPPLY_DM_TOTAL_DEATHS"), 412, 0);
				Hooking::stat_set_int($("MP0_MPPLY_TIMES_FINISH_DM_TOP_3"), 36, 0);
				Hooking::stat_set_int($("MP0_PLAYER_HEADSHOTS"), 623, 0);
				Hooking::stat_set_int($("MP0_AWD_FM_DM_WINS"), 63, 0);
				Hooking::stat_set_int($("MP0_AWD_FM_TDM_WINS"), 13, 0);
				Hooking::stat_set_int($("MP0_AWD_FM_GTA_RACES_WON"), 12, 0);
				Hooking::stat_set_int($("MP0_AWD_FM_GOLF_WON"), 2, 0);
				Hooking::stat_set_int($("MP0_AWD_FM_SHOOTRANG_TG_WON"), 2, 0);
				Hooking::stat_set_int($("MP0_AWD_FM_SHOOTRANG_RT_WON"), 2, 0);
				Hooking::stat_set_int($("MP0_AWD_FM_SHOOTRANG_CT_WON"), 2, 0);
				Hooking::stat_set_int($("MP0_AWD_FM_SHOOTRANG_GRAN_WON"), 2, 0);
				Hooking::stat_set_int($("MP0_AWD_FM_TENNIS_WON"), 2, 0);
				Hooking::stat_set_int($("MP0_MPPLY_TENNIS_MATCHES_WON"), 2, 0);
				Hooking::stat_set_int($("MP0_MPPLY_TOTAL_TDEATHMATCH_WON"), 63, 0);
				Hooking::stat_set_int($("MP0_MPPLY_TOTAL_RACES_WON"), 101, 0);
				Hooking::stat_set_int($("MP0_MPPLY_TOTAL_DEATHMATCH_LOST"), 23, 0);
				Hooking::stat_set_int($("MP0_MPPLY_TOTAL_RACES_LOST"), 36, 0);
				Hooking::stat_set_int($("MP0_AWD_25_KILLS_STICKYBOMBS"), 50, 0);
				Hooking::stat_set_int($("MP0_AWD_50_KILLS_GRENADES"), 50, 0);
				Hooking::stat_set_int($("MP0_GRENADE_ENEMY_KILLS"), 50, 0);
				Hooking::stat_set_int($("MP0_AWD_20_KILLS_MELEE"), 50, 0);
				Hooking::stat_set_int($("MP0_MOLOTOV_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_CMBTPISTOL_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_PISTOL50_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_APPISTOL_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_MICROSMG_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_SMG_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_ASLTSMG_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_ASLTRIFLE_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_CRBNRIFLE_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_ADVRIFLE_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_MG_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_CMBTMG_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_ASLTMG_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_PUMP_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_SAWNOFF_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_BULLPUP_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_ASLTSHTGN_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_SNIPERRFL_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_HVYSNIPER_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_GRNLAUNCH_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_RPG_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_MINIGUNS_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_GRENADE_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_SMKGRENADE_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_STKYBMB_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int($("MP0_MOLOTOV_ENEMY_KILLS"), 600, 0);

				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_FEET_1"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_HAIR"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_HAIR_1"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_HAIR_2"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_HAIR_3"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_HAIR_4"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_HAIR_5"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_HAIR_6"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_HAIR_7"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_JBIB"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_JBIB_1"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_JBIB_2"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_JBIB_3"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_JBIB_4"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_JBIB_5"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_JBIB_6"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_JBIB_7"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_LEGS"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_LEGS_1"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_LEGS_2"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_LEGS_3"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_LEGS_4"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_LEGS_5"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_LEGS_6"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_LEGS_7"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_FEET"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_FEET_1"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_FEET_2"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_FEET_3"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_FEET_4"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_FEET_5"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_FEET_6"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_FEET_7"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_BERD"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_BERD_1"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_BERD_2"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_BERD_3"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_BERD_4"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_BERD_5"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_BERD_6"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_BERD_7"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_PROPS"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_PROPS_1"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_PROPS_2"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_PROPS_3"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_PROPS_4"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_PROPS_5"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_PROPS_6"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_PROPS_7"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_PROPS_8"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_PROPS_9"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_PROPS_10"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_OUTFIT"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_HAIR"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_HAIR_1"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_HAIR_2"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_HAIR_3"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_HAIR_4"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_HAIR_5"), -1, 1);;
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_HAIR_6"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_HAIR_7"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_JBIB"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_JBIB_1"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_JBIB_2"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_JBIB_3"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_JBIB_4"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_JBIB_5"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_JBIB_6"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_JBIB_7"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_LEGS"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_LEGS_1"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_LEGS_2"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_LEGS_3"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_LEGS_4"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_LEGS_5"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_LEGS_6"), -1, 1);;
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_LEGS_7"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_FEET"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_FEET_1"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_FEET_2"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_FEET_3"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_FEET_4"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_FEET_5"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_FEET_6"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_FEET_7"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_BERD"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_BERD_1"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_BERD_2"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_BERD_3"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_BERD_4"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_BERD_5"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_BERD_6"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_BERD_7"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_PROPS"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_PROPS_1"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_PROPS_2"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_PROPS_3"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_PROPS_4"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_PROPS_5"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_PROPS_6"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_PROPS_7"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_PROPS_8"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_PROPS_9"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_PROPS_10"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_OUTFIT"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_TORSO"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_SPECIAL"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_SPECIAL_1"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_SPECIAL_2"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_SPECIAL_3"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_SPECIAL_4"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_SPECIAL_5"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_SPECIAL_6"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_SPECIAL_7"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_SPECIAL2"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_SPECIAL2_1"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_DECL"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_TEETH"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_TEETH_1"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_AVAILABLE_TEETH_2"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_TORSO"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_SPECIAL"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_SPECIAL_1"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_SPECIAL_2"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_SPECIAL_3"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_SPECIAL_4"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_SPECIAL_5"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_SPECIAL_6"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_SPECIAL_7"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_SPECIAL2"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_SPECIAL2_1"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_DECL"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_TEETH"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_TEETH_1"), -1, 1);
				Hooking::stat_set_int($("MP0_CLTHS_ACQUIRED_TEETH_2"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_0"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_1"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_2"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_3"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_4"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_5"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_6"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_7"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_8"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_9"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_10"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_11"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_12"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_13"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_14"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_15"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_16"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_17"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_18"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_19"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_21"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_22"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_23"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_24"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_24"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_25"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_26"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_27"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_28"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_29"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_30"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_31"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_32"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_33"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_34"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_35"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_36"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_37"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_38"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_39"), -1, 1);
				Hooking::stat_set_int($("MP0_DLC_APPAREL_ACQUIRED_40"), -1, 1);
				Hooking::stat_set_int($("MP0_ADMIN_CLOTHES_GV_BS_1"), -1, 1);
				Hooking::stat_set_int($("MP0_ADMIN_CLOTHES_GV_BS_2"), -1, 1);
				Hooking::stat_set_int($("MP0_ADMIN_CLOTHES_GV_BS_3"), -1, 1);
				Hooking::stat_set_int($("MP0_ADMIN_CLOTHES_GV_BS_4"), -1, 1);
				Hooking::stat_set_int($("MP0_ADMIN_CLOTHES_GV_BS_5"), -1, 1);
				Hooking::stat_set_int($("MP0_ADMIN_CLOTHES_GV_BS_6"), -1, 1);
				Hooking::stat_set_int($("MP0_ADMIN_CLOTHES_GV_BS_7"), -1, 1);
				Hooking::stat_set_int($("MP0_ADMIN_CLOTHES_GV_BS_8"), -1, 1);
				Hooking::stat_set_int($("MP0_ADMIN_CLOTHES_GV_BS_9"), -1, 1);
				Hooking::stat_set_int($("MP0_ADMIN_CLOTHES_GV_BS_10"), -1, 1);
				Hooking::stat_set_int($("MP0_ADMIN_CLOTHES_GV_BS_11"), -1, 1);
				Hooking::stat_set_int($("MP0_ADMIN_CLOTHES_GV_BS_12"), -1, 1);
				Hooking::stat_set_int($("MP0_ADMIN_CLOTHES_GV_BS_13"), -1, 1);
				Hooking::stat_set_int($("MP0_ADMIN_CLOTHES_GV_BS_1"), -1, 1);
				Hooking::stat_set_int($("MP0_ADMIN_CLOTHES_GV_BS_10"), -1, 1);
				Hooking::stat_set_int($("MP0_ADMIN_CLOTHES_GV_BS_11"), -1, 1);
				Hooking::stat_set_int($("MP0_ADMIN_CLOTHES_GV_BS_12"), -1, 1);
			}
			if (Menu::Option("Unlock LSC")) {
				Hooking::stat_set_bool($("MP0_AWD_FMRACEWORLDRECHOLDER"), 1, true);
				Hooking::stat_set_int($("MP0_AWD_ENEMYDRIVEBYKILLS"), 600, true);
				Hooking::stat_set_int($("MP0_USJS_COMPLETED"), 50, true);
				Hooking::stat_set_int($("MP0_USJS_FOUND"), 50, true);
				Hooking::stat_set_bool($("MP0_AWD_FMWINALLRACEMODES"), 1, true);
				Hooking::stat_set_bool($("MP0_AWD_FMWINEVERYGAMEMODE"), 1, true);
				Hooking::stat_set_int($("MP0_DB_PLAYER_KILLS"), 1000, true);
				Hooking::stat_set_int($("MP0_KILLS_PLAYERS"), 1000, true);
				Hooking::stat_set_int($("MP0_AWD_FMHORDWAVESSURVIVE"), 21, true);
				Hooking::stat_set_int($("MP0_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, true);
				Hooking::stat_set_int($("MP0_AWD_FM_TDM_MVP"), 60, true);
				Hooking::stat_set_int($("MP0_AWD_HOLD_UP_SHOPS"), 20, true);
				Hooking::stat_set_int($("MP0_AWD_RACES_WON"), 101, true);
				Hooking::stat_set_int($("MP0_AWD_NO_ARMWRESTLING_WINS"), 21, true);
				Hooking::stat_set_bool($("MP0_AWD_FMATTGANGHQ"), 1, true);
				Hooking::stat_set_int($("MP0_AWD_FMBBETWIN"), 50000, true);
				Hooking::stat_set_int($("MP0_AWD_FM_DM_WINS"), 51, true);
				Hooking::stat_set_bool($("MP0_AWD_FMFULLYMODDEDCAR"), 1, true);
				Hooking::stat_set_int($("MP0_AWD_FM_DM_TOTALKILLS"), 500, true);
				Hooking::stat_set_int($("MP0_MPPLY_DM_TOTAL_DEATHS"), 412, true);
				Hooking::stat_set_int($("MP0_MPPLY_TIMES_FINISH_DM_TOP_3"), 36, true);
				Hooking::stat_set_int($("MP0_PLAYER_HEADSHOTS"), 623, true);
				Hooking::stat_set_int($("MP0_AWD_FM_DM_WINS"), 63, true);
				Hooking::stat_set_int($("MP0_AWD_FM_TDM_WINS"), 13, true);
				Hooking::stat_set_int($("MP0_AWD_FM_GTA_RACES_WON"), 12, true);
				Hooking::stat_set_int($("MP0_AWD_FM_GOLF_WON"), 2, true);
				Hooking::stat_set_int($("MP0_AWD_FM_SHOOTRANG_TG_WON"), 2, true);
				Hooking::stat_set_int($("MP0_AWD_FM_SHOOTRANG_RT_WON"), 2, true);
				Hooking::stat_set_int($("MP0_AWD_FM_SHOOTRANG_CT_WON"), 2, true);
				Hooking::stat_set_int($("MP0_AWD_FM_SHOOTRANG_GRAN_WON"), 2, true);
				Hooking::stat_set_int($("MP0_AWD_FM_TENNIS_WON"), 2, true);
				Hooking::stat_set_int($("MP0_MPPLY_TENNIS_MATCHES_WON"), 2, true);
				Hooking::stat_set_int($("MP0_MPPLY_TOTAL_TDEATHMATCH_WON"), 63, true);
				Hooking::stat_set_int($("MP0_MPPLY_TOTAL_RACES_WON"), 101, true);
				Hooking::stat_set_int($("MP0_MPPLY_TOTAL_DEATHMATCH_LOST"), 23, true);
				Hooking::stat_set_int($("MP0_MPPLY_TOTAL_RACES_LOST"), 36, true);
				Hooking::stat_set_int($("MP0_AWD_25_KILLS_STICKYBOMBS"), 50, true);
				Hooking::stat_set_int($("MP0_AWD_50_KILLS_GRENADES"), 50, true);
				Hooking::stat_set_int($("MP0_GRENADE_ENEMY_KILLS "), 50, true);
				Hooking::stat_set_int($("MP0_AWD_20_KILLS_MELEE"), 50, true);
				Hooking::stat_set_bool($("MP1_AWD_FMRACEWORLDRECHOLDER"), 1, true);
				Hooking::stat_set_int($("MP1_AWD_ENEMYDRIVEBYKILLS"), 600, true);
				Hooking::stat_set_int($("MP1_USJS_COMPLETED"), 50, true);
				Hooking::stat_set_int($("MP1_USJS_FOUND"), 50, true);
				Hooking::stat_set_bool($("MP1_AWD_FMWINALLRACEMODES"), 1, true);
				Hooking::stat_set_bool($("MP1_AWD_FMWINEVERYGAMEMODE"), 1, true);
				Hooking::stat_set_int($("MP1_DB_PLAYER_KILLS"), 1000, true);
				Hooking::stat_set_int($("MP1_KILLS_PLAYERS"), 1000, true);
				Hooking::stat_set_int($("MP1_AWD_FMHORDWAVESSURVIVE"), 21, true);
				Hooking::stat_set_int($("MP1_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, true);
				Hooking::stat_set_int($("MP1_AWD_FM_TDM_MVP"), 60, true);
				Hooking::stat_set_int($("MP1_AWD_HOLD_UP_SHOPS"), 20, true);
				Hooking::stat_set_int($("MP1_AWD_RACES_WON"), 101, true);
				Hooking::stat_set_int($("MP1_AWD_NO_ARMWRESTLING_WINS"), 21, true);
				Hooking::stat_set_bool($("MP1_AWD_FMATTGANGHQ"), 1, true);
				Hooking::stat_set_int($("MP1_AWD_FMBBETWIN"), 50000, true);
				Hooking::stat_set_int($("MP1_AWD_FM_DM_WINS"), 51, true);
				Hooking::stat_set_bool($("MP1_AWD_FMFULLYMODDEDCAR"), 1, true);
				Hooking::stat_set_int($("MP1_AWD_FM_DM_TOTALKILLS"), 500, true);
				Hooking::stat_set_int($("MP1_MPPLY_DM_TOTAL_DEATHS"), 412, true);
				Hooking::stat_set_int($("MP1_MPPLY_TIMES_FINISH_DM_TOP_3"), 36, true);
				Hooking::stat_set_int($("MP1_PLAYER_HEADSHOTS"), 623, true);
				Hooking::stat_set_int($("MP1_AWD_FM_DM_WINS"), 63, true);
				Hooking::stat_set_int($("MP1_AWD_FM_TDM_WINS"), 13, true);
				Hooking::stat_set_int($("MP1_AWD_FM_GTA_RACES_WON"), 12, true);
				Hooking::stat_set_int($("MP1_AWD_FM_GOLF_WON"), 2, true);
				Hooking::stat_set_int($("MP1_AWD_FM_SHOOTRANG_TG_WON"), 2, true);
				Hooking::stat_set_int($("MP1_AWD_FM_SHOOTRANG_RT_WON"), 2, true);
				Hooking::stat_set_int($("MP1_AWD_FM_SHOOTRANG_CT_WON"), 2, true);
				Hooking::stat_set_int($("MP1_AWD_FM_SHOOTRANG_GRAN_WON"), 2, true);
				Hooking::stat_set_int($("MP1_AWD_FM_TENNIS_WON"), 2, true);
				Hooking::stat_set_int($("MP1_MPPLY_TENNIS_MATCHES_WON"), 2, true);
				Hooking::stat_set_int($("MP1_MPPLY_TOTAL_TDEATHMATCH_WON"), 63, true);
				Hooking::stat_set_int($("MP1_MPPLY_TOTAL_RACES_WON"), 101, true);
				Hooking::stat_set_int($("MP1_MPPLY_TOTAL_DEATHMATCH_LOST"), 23, true);
				Hooking::stat_set_int($("MP1_MPPLY_TOTAL_RACES_LOST"), 36, true);
				Hooking::stat_set_int($("MP1_AWD_25_KILLS_STICKYBOMBS"), 50, true);
				Hooking::stat_set_int($("MP1_AWD_50_KILLS_GRENADES"), 50, true);
				Hooking::stat_set_int($("MP1_GRENADE_ENEMY_KILLS "), 50, true);
				Hooking::stat_set_int($("MP1_AWD_20_KILLS_MELEE"), 50, true);
				Hooking::stat_set_bool($("MP2_AWD_FMRACEWORLDRECHOLDER"), 1, true);
				Hooking::stat_set_int($("MP2_AWD_ENEMYDRIVEBYKILLS"), 600, true);
				Hooking::stat_set_int($("MP2_USJS_COMPLETED"), 50, true);
				Hooking::stat_set_int($("MP2_USJS_FOUND"), 50, true);
				Hooking::stat_set_bool($("MP2_AWD_FMWINALLRACEMODES"), 1, true);
				Hooking::stat_set_bool($("MP2_AWD_FMWINEVERYGAMEMODE"), 1, true);
				Hooking::stat_set_int($("MP2_DB_PLAYER_KILLS"), 1000, true);
				Hooking::stat_set_int($("MP2_KILLS_PLAYERS"), 1000, true);
				Hooking::stat_set_int($("MP2_AWD_FMHORDWAVESSURVIVE"), 21, true);
				Hooking::stat_set_int($("MP2_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, true);
				Hooking::stat_set_int($("MP2_AWD_FM_TDM_MVP"), 60, true);
				Hooking::stat_set_int($("MP2_AWD_HOLD_UP_SHOPS"), 20, true);
				Hooking::stat_set_int($("MP2_AWD_RACES_WON"), 101, true);
				Hooking::stat_set_int($("MP2_AWD_NO_ARMWRESTLING_WINS"), 21, true);
				Hooking::stat_set_bool($("MP2_AWD_FMATTGANGHQ"), 1, true);
				Hooking::stat_set_int($("MP2_AWD_FMBBETWIN"), 50000, true);
				Hooking::stat_set_int($("MP2_AWD_FM_DM_WINS"), 51, true);
				Hooking::stat_set_bool($("MP2_AWD_FMFULLYMODDEDCAR"), 1, true);
				Hooking::stat_set_int($("MP2_AWD_FM_DM_TOTALKILLS"), 500, true);
				Hooking::stat_set_int($("MP2_MPPLY_DM_TOTAL_DEATHS"), 412, true);
				Hooking::stat_set_int($("MP2_MPPLY_TIMES_FINISH_DM_TOP_3"), 36, true);
				Hooking::stat_set_int($("MP2_PLAYER_HEADSHOTS"), 623, true);
				Hooking::stat_set_int($("MP2_AWD_FM_DM_WINS"), 63, true);
				Hooking::stat_set_int($("MP2_AWD_FM_TDM_WINS"), 13, true);
				Hooking::stat_set_int($("MP2_AWD_FM_GTA_RACES_WON"), 12, true);
				Hooking::stat_set_int($("MP2_AWD_FM_GOLF_WON"), 2, true);
				Hooking::stat_set_int($("MP2_AWD_FM_SHOOTRANG_TG_WON"), 2, true);
				Hooking::stat_set_int($("MP2_AWD_FM_SHOOTRANG_RT_WON"), 2, true);
				Hooking::stat_set_int($("MP2_AWD_FM_SHOOTRANG_CT_WON"), 2, true);
				Hooking::stat_set_int($("MP2_AWD_FM_SHOOTRANG_GRAN_WON"), 2, true);
				Hooking::stat_set_int($("MP2_AWD_FM_TENNIS_WON"), 2, true);
				Hooking::stat_set_int($("MP2_MPPLY_TENNIS_MATCHES_WON"), 2, true);
				Hooking::stat_set_int($("MP2_MPPLY_TOTAL_TDEATHMATCH_WON"), 63, true);
				Hooking::stat_set_int($("MP2_MPPLY_TOTAL_RACES_WON"), 101, true);
				Hooking::stat_set_int($("MP2_MPPLY_TOTAL_DEATHMATCH_LOST"), 23, true);
				Hooking::stat_set_int($("MP2_MPPLY_TOTAL_RACES_LOST"), 36, true);
				Hooking::stat_set_int($("MP2_AWD_25_KILLS_STICKYBOMBS"), 50, true);
				Hooking::stat_set_int($("MP2_AWD_50_KILLS_GRENADES"), 50, true);
				Hooking::stat_set_int($("MP2_GRENADE_ENEMY_KILLS "), 50, true);
				Hooking::stat_set_int($("MP2_AWD_20_KILLS_MELEE"), 50, true);
			}

			/*if (Menu::Option("Bunker Unlocks")) {
				globalHandle(262145 + 21366).As<bool>() = true;
			}*/

			/*if (Menu::Option("Add Money 15 Million")) {
				globalHandle(4264315).At(1).As<int>() = 2147483646;
				globalHandle(4264315).At(2).As<int>() = 15000000;
				globalHandle(4264315).At(3).As<int>() = -1586170317;
				globalHandle(4264315).At(5).As<int>() = NULL;
				globalHandle(4264315).At(6).As<int>() = NULL;
				globalHandle(4264315).At(7).As<int>() = 2147483647;
			}*/

			if (Menu::Option("Clear Badsport Stats")) {
				Hooking::stat_set_float($("MPPLY_OVERALL_BADSPORT"), 0.0f, TRUE);
				Hooking::stat_set_int($("MPPLY_DESTROYED_PVEHICLES"), 0, TRUE);
				Hooking::stat_set_int($("MPPLY_BADSPORT_MESSAGE"), 0, TRUE);
			}

		}
		break;

		case lscmain:
		{
			Vehicle veh = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
			int ModType = VehicleModArmor;
			if (VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType) > 0)
				if (Menu::MenuOption("Armor", lscarmor)) { selectedModType = VehicleModArmor; }
			Vehicle veh1 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
			int ModType2 = VehicleModFrame;
			if (VEHICLE::GET_NUM_VEHICLE_MODS(veh1, ModType2) > 0)
				if (Menu::MenuOption("Bodywork", lscbody)) { selectedModType = VehicleModFrame; }
			Vehicle veh2 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
			int ModType3 = VehicleModBrakes;
			if (VEHICLE::GET_NUM_VEHICLE_MODS(veh2, ModType3) > 0)
				if (Menu::MenuOption("Brakes", lscbrakes)) { selectedModType = VehicleModBrakes; }

			Vehicle veh3 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
			int ModType4 = VehicleModFrontBumper;
			if (VEHICLE::GET_NUM_VEHICLE_MODS(veh3, ModType4) > 0)
				if (Menu::MenuOption("Bumper (Front)", lscfbumper))
				{
					selectedModType = VehicleModFrontBumper;
				}

			Vehicle veh4 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
			int ModType5 = VehicleModRearBumper;
			if (VEHICLE::GET_NUM_VEHICLE_MODS(veh4, ModType5) > 0)
				if (Menu::MenuOption("Bumper (Rear)", lscrbumper))
				{
					selectedModType = VehicleModRearBumper;
				}
			Vehicle veh6 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
			int ModType7 = VehicleModEngine;
			if (VEHICLE::GET_NUM_VEHICLE_MODS(veh6, ModType7) > 0)
				if (Menu::MenuOption("Engine", lscengine))
				{
					selectedModType = VehicleModEngine;
				}

			Vehicle veh7 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
			int ModType8 = VehicleModExhaust;
			if (VEHICLE::GET_NUM_VEHICLE_MODS(veh7, ModType8) > 0)
				if (Menu::MenuOption("Exhaust", lscexhaust))
				{
					selectedModType = VehicleModExhaust;
				}

			Vehicle veh8 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
			int ModType9 = VehicleModSpoilers;
			if (VEHICLE::GET_NUM_VEHICLE_MODS(veh8, ModType9) > 0)
				if (Menu::MenuOption("Spoiler", lscspoiler))
				{
					selectedModType = VehicleModSpoilers;
				}

			Vehicle veh9 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
			int ModType10 = VehicleModSideSkirt;
			if (VEHICLE::GET_NUM_VEHICLE_MODS(veh9, ModType10) > 0)
				if (Menu::MenuOption("Side Skirt", lscskirt))
				{
					selectedModType = VehicleModSideSkirt;
				}

			Vehicle veh10 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
			int ModType11 = VehicleModGrille;
			if (VEHICLE::GET_NUM_VEHICLE_MODS(veh10, ModType11) > 0)
				if (Menu::MenuOption("Grille", lscgrille))
				{
					selectedModType = VehicleModGrille;
				}

			Vehicle veh11 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
			int ModType12 = VehicleModHood;
			if (VEHICLE::GET_NUM_VEHICLE_MODS(veh11, ModType12) > 0)
				if (Menu::MenuOption("Hood", lschood))
				{
					selectedModType = VehicleModHood;
				}


			Vehicle veh12 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
			int ModType13 = VehicleModFender;
			if (VEHICLE::GET_NUM_VEHICLE_MODS(veh12, ModType13) > 0)
				if (Menu::MenuOption("Fender", lscfender))
				{
					selectedModType = VehicleModFender;
				}

			Vehicle veh13 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
			int ModType14 = VehicleModRightFender;
			if (VEHICLE::GET_NUM_VEHICLE_MODS(veh13, ModType14) > 0)
				if (Menu::MenuOption("Right Fender", lscrfender))
				{
					selectedModType = VehicleModRightFender;
				}

			Vehicle veh14 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
			int ModType15 = VehicleModRoof;
			if (VEHICLE::GET_NUM_VEHICLE_MODS(veh14, ModType15) > 0)
				if (Menu::MenuOption("Roof", lscroof))
				{
					selectedModType = VehicleModRoof;
				}

			Vehicle veh15 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
			int ModType16 = VehicleModTransmission;
			if (VEHICLE::GET_NUM_VEHICLE_MODS(veh15, ModType16) > 0)
				if (Menu::MenuOption("Transmission", lsctransmission))
				{
					selectedModType = VehicleModTransmission;
				}

			Vehicle veh16 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
			int ModType17 = VehicleModHorns;
			if (VEHICLE::GET_NUM_VEHICLE_MODS(veh16, ModType17) > 0)
				if (Menu::MenuOption("Horns", lschorn))
				{
					selectedModType = VehicleModHorns;
				}

			Vehicle veh17 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
			int ModType18 = VehicleModSuspension;
			if (VEHICLE::GET_NUM_VEHICLE_MODS(veh17, ModType18) > 0)
				if (Menu::MenuOption("Suspension", lscsuspension))
				{
					selectedModType = VehicleModSuspension;
				}

			Vehicle veh24 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
			int ModType25 = VehicleModFrontWheels;
			if (VEHICLE::GET_NUM_VEHICLE_MODS(veh24, ModType25) > 0)
				if (Menu::MenuOption("Front Wheels", lscwheels))
				{
					selectedModType = VehicleModFrontWheels;
				}

			Vehicle veh25 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
			int ModType26 = VehicleModBackWheels;
			if (VEHICLE::GET_NUM_VEHICLE_MODS(veh25, ModType26) > 0)
				if (Menu::MenuOption("Back Wheels", lscbwheels))
				{
					selectedModType = VehicleModBackWheels;
				}
		}
		break;

		
			case lscarmor:
			{
				Vehicle veh = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
				int ModType = VehicleModArmor;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType);

				if(Menu::Option("None"))
					{
						changemod(ModType, -1);

					}
				if(Menu::Option("Armor Upgrade 20%"))

					{
						changemod(ModType, 0);

					}
				if(Menu::Option("Armor Upgrade 40%"))
					
					{
						changemod(ModType, 1);

					}
				if(Menu::Option("Armor Upgrade 60%"))
					
					{
						changemod(ModType, 2);

					}
				if(Menu::Option("Armor Upgrade 80%"))
					
					{
						changemod(ModType, 3);

					}
				if(Menu::Option("Armor Upgrade 100%"))
					
					{
						changemod(ModType, 4);

					}
			}
			break;
			case lscbody:
			{
				Vehicle veh1 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
				int ModType2 = VehicleModFrame;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh1, ModType2);

				if(Menu::Option("None"))
					{
						changemod(ModType2, -1);

					}
				for (int i = 0; i < amount; i++)
				{
					if(Menu::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh1, ModType2, i))))
						{
							changemod(ModType2, i);

						}
				}


			}
			break;
			case lscbrakes:
			{
				Vehicle veh2 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
				int ModType3 = VehicleModBrakes;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh2, ModType3);

				if(Menu::Option("None"))
					
					{
						changemod(ModType3, -1);

					}
				if(Menu::Option("Street Brakes")) 
					
					{
						changemod(ModType3, 0);

					}
				if(Menu::Option("Sport Brakes"))
					
					{
						changemod(ModType3, 1);

					}
				if(Menu::Option("Race Brakes")) 
					
					{
						changemod(ModType3, 2);

					}

			}
			break;
			case lscfbumper:
			{
				Vehicle veh3 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
				int ModType4 = VehicleModFrontBumper;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh3, ModType4);

				if(Menu::Option("None) None"))
			
					{
						changemod(ModType4, -1);

					}
				for (int i = 0; i < amount; i++)
				{
					if(Menu::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh3, ModType4, i))))
						{
							changemod(ModType4, i);

						}
				}

			}
			break;
			case lscrbumper:
			{
				Vehicle veh4 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
				int ModType5 = VehicleModRearBumper;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh4, ModType5);

				if(Menu::Option("None) None"))
					{
						changemod(ModType5, -1);

					}
				for (int i = 0; i < amount; i++)
				{
					if(Menu::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh4, ModType5, i))))
						{
							changemod(ModType5, i);

						}
				}

			}
			break;
			case lscengine:
			{
				Vehicle veh5 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
				int ModType6 = VehicleModEngine;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh5, ModType6);

				if(Menu::Option("None) None"))
					
					{
						changemod(ModType6, -1);

					}
				if(Menu::Option("Level 1) Level 1"))
					
					{
						changemod(ModType6, 0);

					}
				if(Menu::Option("Level 2) Level 2"))
					
					{
						changemod(ModType6, 1);

					}
				if(Menu::Option("Level 3) Level 3"))
					
					{
						changemod(ModType6, 2);

					}
				if(Menu::Option("Level 4) Level 4"))
					
					{
						changemod(ModType6, 3);

					}

			}
			break;

			case lscexhaust:
			{
				Vehicle veh7 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
				int ModType8 = VehicleModExhaust;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh7, ModType8);

				if(Menu::Option("None) None"))
					
					{
						changemod(ModType8, -1);

					}
				for (int i = 0; i < amount; i++)
				{
					if(Menu::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh7, ModType8, i))))
						{
							changemod(ModType8, i);

						}
				}

			}
			break;
			case lscspoiler:
			{
				Vehicle veh8 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
				int ModType9 = VehicleModSpoilers;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh8, ModType9);

				if(Menu::Option("None) None"))
					
					{
						changemod(ModType9, -1);

					}
				for (int i = 0; i < amount; i++)
				{
					if(Menu::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh8, ModType9, i))))
					
						{
							changemod(ModType9, i);

						}
				}

			}
			break;
			case lscskirt:
			{
				Vehicle veh9 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
				int ModType10 = VehicleModSideSkirt;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh9, ModType10);

				if(Menu::Option("None) None"))
				
					{
						changemod(ModType10, -1);

					}
				for (int i = 0; i < amount; i++)
				{
					if(Menu::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh9, ModType10, i))))
						{
							changemod(ModType10, i);

						}
				}

			}
			break;
			case lscgrille:
			{
				Vehicle veh10 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
				int ModType11 = VehicleModGrille;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh10, ModType11);

				if(Menu::Option("None) None"))
				
					{
						changemod(ModType11, -1);

					}
				for (int i = 0; i < amount; i++)
				{
					if(Menu::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh10, ModType11, i))))
						{
							changemod(ModType11, i);

						}
				}

			}
			break;
			case lschood:
			{
				Vehicle veh11 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
				int ModType12 = VehicleModHood;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh11, ModType12);

				if(Menu::Option("None) None"))
					{
						changemod(ModType12, -1);

					}
				for (int i = 0; i < amount; i++)
				{
					if(Menu::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh11, ModType12, i))))
						{
							changemod(ModType12, i);

						}
				}

			}
			break;
			case lscfender:
			{
				Vehicle veh12 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
				int ModType13 = VehicleModFender;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh12, ModType13);

				if(Menu::Option("None) None"))
			
					{
						changemod(ModType13, -1);

					}
				for (int i = 0; i < amount; i++)
				{
					if(Menu::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh12, ModType13, i))))
						{
							changemod(ModType13, i);

						}
				}

			}
			break;
			case lscrfender:
			{
				Vehicle veh13 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
				int ModType14 = VehicleModRightFender;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh13, ModType14);

				if(Menu::Option("None) None"))
	
					{
						changemod(ModType14, -1);

					}
				for (int i = 0; i < amount; i++)
				{
					if(Menu::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh13, ModType14, i))))
						{
							changemod(ModType14, i);

						}
				}

			}
			break;
			case lscroof:
			{
				Vehicle veh14 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
				int ModType15 = VehicleModRoof;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh14, ModType15);

				if(Menu::Option("None) None"))
		
					{
						changemod(ModType15, -1);

					}
				for (int i = 0; i < amount; i++)
				{
					if(Menu::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh14, ModType15, i))))
						{
							changemod(ModType15, i);

						}
				}

			}
			break;
			case lsctransmission:
			{
				Vehicle veh15 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
				int ModType16 = VehicleModTransmission;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh15, ModType16);

				if(Menu::Option("None) None"))
			
					{
						changemod(ModType16, -1);

					}
				for (int i = 0; i < amount; i++)
				{
					if(Menu::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh15, ModType16, i))))
						{
							changemod(ModType16, i);

						}
				}

			}
			break;
			case lschorn:
			{
				Vehicle veh16 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
				int ModType17 = VehicleModHorns;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh16, ModType17);

				if(Menu::Option("None) None"))
			
					{
						changemod(ModType17, -1);

					}
				for (int i = 0; i < amount; i++)
				{
					if(Menu::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh16, ModType17, i))))
						{
							changemod(ModType17, i);

						}
				}

			}
			break;
			case lscsuspension:
			{
				Vehicle veh17 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
				int ModType18 = VehicleModSuspension;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh17, ModType18);

				if(Menu::Option("None) None"))
			
					{
						changemod(ModType18, -1);

					}
				for (int i = 0; i < amount; i++)
				{
					if(Menu::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh17, ModType18, i))))
						{
							changemod(ModType18, i);

						}
				}

			}
			break;
			case lscwheels:
			{
				Vehicle veh24 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
				int ModType25 = VehicleModFrontWheels;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh24, ModType25);

				if(Menu::Option("None) None"))
				
					{
						changemod(ModType25, -1);

					}
				for (int i = 0; i < amount; i++)
				{
					if(Menu::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh24, ModType25, i))))
						{
							changemod(ModType25, i);

						}
				}

			}
			break;
			case lscbwheels:
			{
				Vehicle veh25 = get_vehicle_ped_is_using(PLAYER::PLAYER_PED_ID());
				int ModType26 = VehicleModBackWheels;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh25, ModType26);

				if(Menu::Option("None) None"))
			
					{
						changemod(ModType26, -1);

					}
				for (int i = 0; i < amount; i++)
				{
					if(Menu::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh25, ModType26, i))))
						{
							changemod(ModType26, i);

						}
				}

			}
			break;

		case weather:
		{
			Menu::Title("Weather Options");

			Menu::Break("Session Time");
			if (Menu::Int("Select Hour", inttime, 0, 23)) {}
			if (Menu::Option("Set Time")) {
				set_session_time(inttime);
			}

			Menu::Break("Session Weather");
			if (Menu::Option("Extra Sunny")) { Hooking::set_session_weather(1, 0, 76, 0); }
			if (Menu::Option("Clear")) { Hooking::set_session_weather(1, 1, 76, 0); }
			if (Menu::Option("Clouds")) { Hooking::set_session_weather(1, 2, 76, 0); }
			if (Menu::Option("Smog")) { Hooking::set_session_weather(1, 3, 76, 0); }
			if (Menu::Option("Foggy")) { Hooking::set_session_weather(1, 4, 76, 0); }
			if (Menu::Option("Overcast")) { Hooking::set_session_weather(1, 5, 76, 0); }
			if (Menu::Option("Rain")) { Hooking::set_session_weather(1, 6, 76, 0); }
			if (Menu::Option("Thunder")) { Hooking::set_session_weather(1, 7, 76, 0); }
			if (Menu::Option("Clearing")) { Hooking::set_session_weather(1, 8, 76, 0); }
			if (Menu::Option("Neutral")) { Hooking::set_session_weather(1, 9, 76, 0); }
			if (Menu::Option("Snow")) { Hooking::set_session_weather(1, 10, 76, 0); }
			if (Menu::Option("Blizzard")) { Hooking::set_session_weather(1, 11, 76, 0); }
			if (Menu::Option("SnowLight")) { Hooking::set_session_weather(1, 12, 76, 0); }
			if (Menu::Option("XMas")) { Hooking::set_session_weather(1, 13, 76, 0); }
			if (Menu::Option("Halloween")) { Hooking::set_session_weather(1, 14, 76, 0); }
			if (Menu::Option("Black Screen")) { Hooking::set_session_weather(1, 15, 76, 0); }
		}
		break;

		case vehicle:
		{
			Menu::Title("Vehicle");
		
			if (Menu::MenuOption("Vehicle Spawner", localvehspawner)) {}
			
			if (versUsed != 1) {
				if (Menu::MenuOption("~y~LSC[VIP]", lscmain)) {}
			}

			if (Menu::Toggle("Vehicle GodMode", vehicleGodMod)) {
				if (vehicleGodMod)
					Memory::set_value({ 0x08, 0xD28, 0x189 }, 0x01);
				else
					Memory::set_value({ 0x08, 0xD28, 0x189 }, 0x00);
			}

			if (Menu::Toggle("Upgrade Vehicles", UpgradeVehicles)) {}
			
			if (versUsed == 3) {
				if (Menu::Toggle("~p~Drive on water[PREMIUM]", DriveWater)) {}
			}

			if (Menu::Toggle("Speedomenter", SpeedoBool)) {}

			if (Menu::Toggle("Speedomenter Plate", PlateMPH)) {}
			
			if (Menu::Toggle("Rainbow Vehicle", rainbowvehbool)) {}
			
			if (Menu::Toggle("Horn Boost", hornboost)) {}
				
			if (Menu::IntChar("Vehicle Weapons", weaponCar1, vehWeaponint, 0, 8))
				notifyMap("~g~Fire With '+' Key (Numpad)");

			if (Menu::Float("Edit Engine Power", remoteEditEngine, -200, 600, 10)) {
				if (IsKeyPressed(VK_NUMPAD5)) {
					int veh = get_vehicle_ped_is_in(get_player_ped(player_id()), 1);
					veh ? ForcedRequestControlOfEntity(veh) ? VEHICLE::_SET_VEHICLE_ENGINE_POWER_MULTIPLIER(veh, remoteEditEngine) :
						notifyMap("~r~Failed") : notifyMap("~r~Player Isn't In Vehicle");
				}
			}

			if (Menu::Float("Edit Engine Torque", remoteEditEngineT, -200, 600, 10)) {
				if (IsKeyPressed(VK_NUMPAD5)) {
					int veh = get_vehicle_ped_is_in(get_player_ped(player_id()), 1);
					veh ? ForcedRequestControlOfEntity(veh) ? VEHICLE::_SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER(veh, remoteEditEngineT) :
						notifyMap("~r~Failed") : notifyMap("~r~Player Isn't In Vehicle");
				}
			}

			if (Menu::Toggle("Flying Car", flyingcarbool)) {}

			if (Menu::Option("Change Plate Number")) {
				int veh = get_vehicle_ped_is_using(player_ped_id());
				if (veh != NULL) {
					char* text = CharKeyboard();
					Hooking::set_vehicle_number_plate_text(veh, text);
				}
				else
					notifyMap("~r~You Aren't In Vehicle");
			}
			if (Menu::Option("Front Flip")) {
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 6.0f, 0, -2.0f, 0, true, true, true, true, false, true);
			}
			if (Menu::Option("Double Front Flip")) {
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 12.0f, 0, -4.0f, 0, true, true, true, true, false, true);
			}
			if (Menu::Option("Side Flip")) {
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 6.0f, 5.0f, 2.0f, 0, true, true, true, true, false, true);
			}
			if (Menu::Option("Back Flip")) {
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 6.0f, 0, 2.0f, 0, true, true, true, true, false, true);
			}
			if (Menu::Option("Double Back Flip")) {
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 12.0f, 0, 4.0f, 0, true, true, true, true, false, true);
			}
			if (Menu::Option("Kick Flip")) {
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 5.0f, 2.0f, 0, 0, true, true, true, true, false, true);
			}
			if (Menu::Option("Heel Flip")) {
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 5.0f, -2.0f, 0, 0, true, true, true, true, false, true);
			}
			if (Menu::Option("Bunny Hop")) {
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 7.0f, 0, 0, 0, true, true, true, true, false, true);
			}
			if (Menu::Option("Launch Up")) {
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 40.0f, 0, 0, 0, true, true, true, true, false, true);
			}
			if (Menu::Option("Crush Vehicle")) {
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, -40.0f, 0, 0, 0, true, true, true, true, false, true);
			}
			if (Menu::Option("Fix Vehicle"))
				fixVehicle(player_id());
			if (Menu::Option("Upgrade Vehicle"))
				UpgradVehicle(get_vehicle_ped_is_using(player_ped_id()));
			if (Menu::Option("Boost Forward"))
				BoostPlayerVehicle(player_ped_id(), 1, true, true, 100);
			if (Menu::Option("Boost Backward"))
				BoostPlayerVehicle(player_ped_id(), 2, true, true, 100);
			if (Menu::Option("Bunnyhop"))
				BoostPlayerVehicle(player_ped_id(), 4, true, true, 100);
		}
		break;

		case onlinevehsettings: {
			Menu::Title("Spawn Settings");
			Menu::Toggle("TP To Player With The Car", spawnincar1);
			Menu::Toggle("Spawn Maxed", spawnmaxed1);
			Menu::Toggle("Spawn Chrome", spawnchrome1);

		}
		break;

		case localvehsettings: {
			Menu::Title("Spawn Settings");
			Menu::Toggle("Spawn in Car", spawnincar);
			Menu::Toggle("Spawn Maxed", spawnmaxed);
			Menu::Toggle("Spawn Chrome", spawnchrome);
		}
		break;

		case localvehspawner: {

			Menu::Title("Vehicle Spawner");
			if (Menu::MenuOption("~g~ Settings", localvehsettings)) {}
			if (Menu::Option("Custom Input"))
				localspawnVehicleByName();

			if (Menu::MenuOption("Modded Vehicles", moddedveh)) {}
			if (Menu::MenuOption("1.48 DLC", cars148)) {}
			if (Menu::MenuOption("1.46 DLC", cars146)) {}
			if (Menu::MenuOption("1.44 DLC", cars144)) {}
			if (Menu::MenuOption("1.43 DLC", cars143)) {}
			if (Menu::MenuOption("Super", Super)) {}
			if (Menu::MenuOption("Sports", Sports)) {}
			if (Menu::MenuOption("Sport Classic", SportClassic)) {}
			if (Menu::MenuOption("Offroad", Offroad)) {}
			if (Menu::MenuOption("Sedans", Sedans)) {}
			if (Menu::MenuOption("Coupes", Coupes)) {}
			if (Menu::MenuOption("Muscle", Muscle)) {}
			if (Menu::MenuOption("Boats", Boats)) {}
			if (Menu::MenuOption("Commercial", Commercial)) {}
			if (Menu::MenuOption("Compacts", Compacts)) {}
			if (Menu::MenuOption("Cycles", Cycles)) {}
			if (Menu::MenuOption("Emergency", Emergency)) {}
			if (Menu::MenuOption("Helicopters", Helicopters)) {}
			if (Menu::MenuOption("Industrial", Industrial)) {}
			if (Menu::MenuOption("Military", Military)) {}
			if (Menu::MenuOption("Motorcycles", Motorcycles)) {}
			if (Menu::MenuOption("Planes", Planes)) {}
			if (Menu::MenuOption("Service", Service)) {}
			if (Menu::MenuOption("SUV", SUV)) {}
			if (Menu::MenuOption("Trailer", Trailer)) {}
			if (Menu::MenuOption("Trains", Trains)) {}
			if (Menu::MenuOption("Utility", Utility)) {}
			if (Menu::MenuOption("Vans", Vans)) {}
		}
		break;

		case cars148: {
			Menu::Title("1.48 Casino");
			for (auto car : cars148_1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
		break;
		case cars146: {
			Menu::Title("1.46 After Hours");
			for (auto car : cars146_1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case cars144: {
			Menu::Title("1.44 After Hours");
			for (auto car : cars144_1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case cars143: {
			Menu::Title("1.43 Super Sports");
			for (auto car : cars143_1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case cars142: {
			Menu::Title("1.42 Doomsday");
			for (auto car : cars142_1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case Super: {
			Menu::Title("Super");
			for (auto car : Super1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case Sports: {
			Menu::Title("Sports");
			for (auto car : Sports1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case SportClassic: {
			Menu::Title("Sports Classic");
			for (auto car : SportsClassics1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case Offroad: {
			Menu::Title("Offroad");
			for (auto car : OffRoad1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case Sedans: {
			Menu::Title("Sedans");
			for (auto car : Sedans1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case Coupes: {
			Menu::Title("Coupes");
			for (auto car : Coupes1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case Muscle: {
			Menu::Title("Muscle");
			for (auto car : Muscle1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case Boats: {
			Menu::Title("Boats");
			for (auto car : Boats1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case Commercial: {
			Menu::Title("Commercial");
			for (auto car : Commercial1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case Compacts: {
			Menu::Title("Compacts");
			for (auto car : Compacts1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case Cycles: {
			Menu::Title("Cycles");
			for (auto car : Cycles1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case Emergency: {
			Menu::Title("Emergency");
			for (auto car : Emergency1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case Helicopters: {
			Menu::Title("Helicopters");
			for (auto car : Helicopters1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case Industrial: {
			Menu::Title("Industrial");
			for (auto car : Industrial1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case Military: {
			Menu::Title("Military");
			for (auto car : Military1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case Motorcycles: {
			Menu::Title("Motorcycles");
			for (auto car : Motorcycles1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case Planes: {
			Menu::Title("Planes");
			for (auto car : Planes1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case Service: {
			Menu::Title("Service");
			for (auto car : Service1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case SUV: {
			Menu::Title("SUV");
			for (auto car : SUVs1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case Trailer: {
			Menu::Title("Trailer");
			for (auto car : Trailer1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case Trains: {
			Menu::Title("Trains");
			for (auto car : Trains1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case Utility: {
			Menu::Title("Utility");
			for (auto car : Utility1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
			break;
		case Vans: {
			Menu::Title("Vans");
			for (auto car : Vans1) { Menu::Option(car, [car] { SpawnVehicle(car, player_id(), spawnincar, spawnmaxed, spawnchrome); }); }}
		break;
		
#pragma endregion




#pragma region Settings Menu
		case settings:
		{
			Menu::Title("Settings");
			if (Menu::Option("Unhook The Menu"))
				g_running = false;

			if (Menu::Toggle("Animated Header", Menu::Settings::animatedHeader)) {
				//Menu::Files::WriteBoolToIni(!Menu::Settings::animatedHeader, "Spooki Ryd3rs/SpookiSettings.ini", "GUI", "dont_use_animated_header");
			}

			if (Menu::Settings::animatedHeader) {
				if (Menu::IntChar("Choose Header", menuHeaderNames, headerToUse, 0, menuHeaderNames.size() - 1)) {
					//notifyMap("~g~Saved!");
					//Menu::Files::WriteIntToIni(headerToUse, "Spooki Ryd3rs/SpookiSettings.ini", "GUI", "menu_header");
				}
			}
			
			if (Menu::MenuOption("Colors ~b~>", settingstheme)) {}
			if (Menu::Int("Scroll Delay", Menu::Settings::keyPressDelay2, 1, 200))
			{
				if (IsKeyPressed(VK_NUMPAD5)) {
					Menu::Settings::keyPressDelay2 = NumberKeyboard();
				}
			}
			if (Menu::Int("Int Delay", Menu::Settings::keyPressDelay3, 1, 200))
			{
				if (IsKeyPressed(VK_NUMPAD5)) {
					Menu::Settings::keyPressDelay3 = NumberKeyboard();
				}
			}
			Menu::Option("~HUD_COLOUR_GOLD~Social Club Account:");
			Menu::Option(get_player_name(player_id()));
			if (Menu::MenuOption("~r~Kill Game", exitgta)) {}
		}
		break;

		case Credits:
		{
			Menu::Title("Credits");
			Menu::Option("~o~Owner : ~b~Unidentified");
			Menu::Option("~o~Owner : ~b~Punk ModZz");
			Menu::Option("~o~Dev : ~b~Giannis");
			Menu::Option(menuVersion);
		
		}
		break;

		case exitgta:
		{
			Menu::Title("Exit GTA V");
			if (Menu::Option("Yes")) exit(0);
		}
		break;
		case settingstheme:
		{
			Menu::Title("Colors");
			if (Menu::MenuOption("Theme Loader ~b~>", themeloader)) {}
			if (Menu::MenuOption("Title Background ~b~>", settingstitlerect)) {}
			if (Menu::MenuOption("Selection Box ~b~>", settingsscroller)) {}
			if (Menu::MenuOption("Option Text ~b~>", settingsoptiontext)) {}
			if (Menu::Option("MenuX plus")) {
				if (Menu::Settings::menuX < 0.81f) Menu::Settings::menuX += 0.01f;
			}
			if (Menu::Option("MenuX minus")) {
				if (Menu::Settings::menuX > 0.17f) Menu::Settings::menuX -= 0.01f;
			}
		}
		break;
		case themeloader:
		{
			Menu::Title("Theme Colors");
			if (Menu::Option("Red Theme")) {
				Menu::Settings::titleRect = { 100, 0, 0, 255 };
				Menu::Settings::scroller = { 100, 0, 0, 255 };
			}
			if (Menu::Option("Blue Theme")) {
				Menu::Settings::titleRect = { 0, 0, 200, 255 };
				Menu::Settings::scroller = { 0, 0, 200, 255 };
			}
			if (Menu::Option("Green Theme")) {
				Menu::Settings::titleRect = { 0, 180, 0, 255 };
				Menu::Settings::scroller = { 0, 0, 180, 255 };
			}
			if (Menu::Option("Load Default Theme")) {
				Menu::Settings::titleText = { 255, 255, 255, 255, 7 };
				Menu::Settings::titleRect = { 100, 0, 0, 255 };
				Menu::Settings::scroller = { 100, 0, 0, 255 };
				Menu::Settings::optionText = { 255, 255, 255, 255, 0 };
				Menu::Settings::optionRect = { 0, 0, 0, 110 };
			}
		}
		break;
		case settingstitlerect:
		{
			Menu::Title("Title Rect");
			if (Menu::Int("Red", Menu::Settings::titleRect.r, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5)) {
					Menu::Settings::titleRect.r = NumberKeyboard();
				}
			}
			if (Menu::Int("Green", Menu::Settings::titleRect.g, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5)) {
					Menu::Settings::titleRect.g = NumberKeyboard();
				}
			}
			if (Menu::Int("Blue", Menu::Settings::titleRect.b, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5)) {
					Menu::Settings::titleRect.b = NumberKeyboard();
				}
			}
			if (Menu::Int("Opacity", Menu::Settings::titleRect.a, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5)) {
					Menu::Settings::titleRect.a = NumberKeyboard();
				}
			}
		}
		break;
		case settingsoptiontext:
		{
			Menu::Title("Option Text");
			if (Menu::Int("Red", Menu::Settings::optionText.r, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5)) {
					Menu::Settings::optionText.r = NumberKeyboard();
				}
			}
			if (Menu::Int("Green", Menu::Settings::optionText.g, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5)) {
					Menu::Settings::optionText.g = NumberKeyboard();
				}
			}
			if (Menu::Int("Blue", Menu::Settings::optionText.b, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5)) {
					Menu::Settings::optionText.b = NumberKeyboard();
				}
			}
			if (Menu::Int("Opacity", Menu::Settings::optionText.a, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5)) {
					Menu::Settings::optionText.a = NumberKeyboard();
				}
			}
			if (Menu::MenuOption("Font ~b~>", font)) {}
		}
		break;
		case font:
		{
			Menu::Title("Font");
			if (Menu::Option("Chalet London")) { Menu::Settings::optionText.f = 0; }
			if (Menu::Option("House Script")) { Menu::Settings::optionText.f = 1; }
			if (Menu::Option("Monospace")) { Menu::Settings::optionText.f = 2; }
			if (Menu::Option("Wing Dings")) { Menu::Settings::optionText.f = 3; }
			if (Menu::Option("Chalet Comprime Cologne")) { Menu::Settings::optionText.f = 4; }
			if (Menu::Option("Pricedown")) { Menu::Settings::optionText.f = 7; }
		}
		break;
		case settingsscroller:
		{
			Menu::Title("Scroller");
			if (Menu::Int("Red", Menu::Settings::scroller.r, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5)) {
					Menu::Settings::scroller.r = NumberKeyboard();
				}
			}
			if (Menu::Int("Green", Menu::Settings::scroller.g, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5)) {
					Menu::Settings::scroller.g = NumberKeyboard();
				}
			}
			if (Menu::Int("Blue", Menu::Settings::scroller.b, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5)) {
					Menu::Settings::scroller.b = NumberKeyboard();
				}
			}
			if (Menu::Int("Opacity", Menu::Settings::scroller.a, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5)) {
					Menu::Settings::scroller.a = NumberKeyboard();
				}
			}
		}
		break;
#pragma endregion
		}
		localPlayerBulletsCount = get_ammo_in_clip();
		Menu::End();
		WAIT(0);
	}

}


void ScriptMain() {
	srand(GetTickCount());
	main();
}
