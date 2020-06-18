#pragma once
#include "stdafx.h"

wstring s2ws(const std::string& str);

__int8 is_user_authed(std::string username, std::string password);
