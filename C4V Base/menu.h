#pragma once

extern bool g_running;

extern void notifyMap(char * fmt, ...);
extern int selectedPlayer;
void ScriptMain();
extern int NumberKeyboard();
extern Vector3 addVector(Vector3 vector, Vector3 vector2);
extern char* Status;
extern std::string connstring;
extern void Text(char* Text, float x, float y, float boxX, float boxY, float scale, int font, int align, int R, int G, int B, int A);
extern int localPlayerBulletsCount;
void SpawnVehicle(const char* VehName, int selectedPlayer, bool spawnincar, bool spawnmaxed, bool spawnchrome);
void GiveAllWeapons(int selectedPlayer);
Hash $(std::string str);
extern int headerToUse;

//protections from scripted events
extern bool kickCarProtection;
extern bool camResetProtection;
extern bool forceToNewLobbyProt;
extern bool transactionErrorProt;
extern bool ForceToMissionProt;
extern bool InvitesProtection;
extern bool CeoBanProtection;
extern bool CEOKickProtection;
extern bool TpToAppsProtection;
extern bool nonHostKicksProtBool;
extern bool infLoadingProt;
extern bool blockAllScrictEvents;
extern bool gtaBannerEffectProt;

//chat cmd options
extern bool chatCMDTeam;
extern bool chatCMDAll;
extern bool chatCMDVehicles;
extern bool chatCMDWeapons;
extern bool chatCMDKickPlayers;
extern bool chatCMDGiveMoney;
extern unsigned __int8 chatCMDPlrMoney[32];
extern unsigned __int16 chatCMDPlrMoneyDelay[32];
extern unsigned __int16 chatCMDPlrMoneyValue[32];
extern unsigned __int8 chatCMDPlrMoneyRadius[32];
extern unsigned int chatCMDPlrMoneyTimers[32];