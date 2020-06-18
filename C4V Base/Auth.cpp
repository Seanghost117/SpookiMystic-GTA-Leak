#pragma once
#include "stdafx.h"
#include <codecvt>
#include <string>

#define URL L"http://auth.spookimystic.com/db_auth.php" 

wstring s2ws(const std::string& str)
{
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	return converterX.from_bytes(str);
}

int makeHash[100];
bool checkHash(std::wstring text) {
	for (int x = 0; x < text.length(); x++) {
		if (makeHash[x] != (int)text.at(x)) return false;
	}
	return true;
}

__int8 is_user_authed(std::string username, std::string password)
{
	char hwid[4096];
	// total physical memory
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	sprintf_s(hwid, "%I64i", statex.ullTotalPhys / 1024);

	// volume information
	TCHAR volumename[MAX_PATH + 1] = { 0 };
	TCHAR filesystemname[MAX_PATH + 1] = { 0 };
	DWORD serialnumber = 0, maxcomponentlen = 0, filesystemflags = 0;
	GetVolumeInformation(_T("C:\\"), volumename, ARRAYSIZE(volumename), &serialnumber, &maxcomponentlen, &filesystemflags, filesystemname, ARRAYSIZE(filesystemname));
	sprintf_s(hwid, "%s%li%ws%li", hwid, serialnumber, filesystemname, maxcomponentlen);

	// computer name
	TCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName) / sizeof(computerName[0]);
	GetComputerName(computerName, &size);
	sprintf_s(hwid, "%s%ws", hwid, computerName);

	net::requests m_request(L"menu", false);
	char idk[6890];
	sprintf_s(idk, "http://auth.spookimystic.com/db_auth.php?username=%s&pkey=%s&hwid=%s", username.c_str(), password.c_str(), (sw::sha512::calculate(hwid)).c_str());
	std::string idk2(idk);
	//std::wstring answer = m_request.Post(false, URL, "?username=%s&pkey=%s&hwid=%s", username.c_str(), password.c_str(), (sw::sha512::calculate(hwid)).c_str());
	std::wstring answer = m_request.Get(0, (wchar_t*)std::wstring(idk2.begin(), idk2.end()).c_str());

	std::string ans(answer.begin(), answer.end());
	//Log::Msg("%s", ans.c_str());

	
	for (int a = 0; a < answer.length(); a++) { //convert server answer from wstring to int(hash)
		makeHash[a] = (int)answer.at(a);
	}

	//**NOT TYPED**
	if (checkHash(L"UNSUPN")) return -1; //USERNAME
	if (checkHash(L"PNSUPN")) return -2; //PASSWORD
	if (checkHash(L"HNSHN")) return -3; //HWID (code error)

	//**LOG IN NOT MATCH**
	if (checkHash(L"UN")) return -4; //HWID (code error)
	if (checkHash(L"UPN")) return -5; //USERNAME/PASSWORD

	//**LOG IN SUCCESSFUL / CHECK VERSION**
	if (checkHash(L"S")) return 1; //SUB
	if (checkHash(L"V")) return 2; //VIP
	if (checkHash(L"P")) return 3; //PREMIUM

	//**LOG IN NOT EXIT**
	if (checkHash(L"N")) return -6; //NO MEMBER

	return 0; //other errors
}

