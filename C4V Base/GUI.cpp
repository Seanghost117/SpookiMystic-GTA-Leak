#include "stdafx.h"


float prevf;
int prevOption = 0;
float ScrollerSpeed = 1.f;


void Menu::Drawing::Text(const char * text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center, bool rightAlign, bool outline)
{
	UI::SET_TEXT_CENTRE(center);
	UI::SET_TEXT_COLOUR(rgbaf.r, rgbaf.g, rgbaf.b, rgbaf.a);
	UI::SET_TEXT_FONT(rgbaf.f);
	UI::SET_TEXT_SCALE(size.w, size.h);
	if (outline && Menu::Settings::DrawTextOutline) {
		UI::SET_TEXT_DROPSHADOW(1, 0, 0, 0, 0);
		UI::SET_TEXT_EDGE(1, 0, 0, 0, 0);
		UI::SET_TEXT_OUTLINE();
	}
	if (rightAlign) {
		UI::SET_TEXT_RIGHT_JUSTIFY(TRUE);
		UI::SET_TEXT_WRAP(Menu::Settings::menuX, Menu::Settings::menuX + 0.085f);
	}
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char*)text);
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(position.x, position.y);
}

void Menu::Drawing::Sprite(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
	if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED((char*)Streamedtexture.c_str()))
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT((char*)Streamedtexture.c_str(), false);
	else
		Hooking::draw_sprite((char*)Streamedtexture.c_str(), (char*)textureName.c_str(), x, y, width, height, rotation, r, g, b, a);
}

void Menu::Drawing::Rect(RGBA rgba, VECTOR2 position, VECTOR2_2 size)
{
	Hooking::draw_rect(position.x, position.y, size.w, size.h, rgba.r, rgba.g, rgba.b, rgba.a);
}

static fpFileRegister file_register = (fpFileRegister)(Memory::pattern("48 89 5C 24 ? 48 89 6C 24 ? 48 89 7C 24 ? 41 54 41 56 41 57 48 83 EC 50 48 8B EA 4C 8B FA 48 8B D9 4D 85 C9").count(1).get(0).get<decltype(file_register)>());

bool FileExists(const std::string& fileName)
{
	struct stat buffer;
	return (stat(fileName.c_str(), &buffer) == 0);//maybe wrong
}

bool Menu::YTD(const std::string name)
{
	std::string path = "Spooki Ryd3rs/";
	const std::string fullPath = path + name;

	int textureID;
	if (FileExists(fullPath)) {
		file_register(&textureID, fullPath.c_str(), true, name.c_str(), false);
		return true;
	}
	return false;
}

static void smoothscroll(int* prev, const int cur)
{
	if (prevf == NULL)
		prevf = *prev * 0.035f + Menu::Settings::menuY + 0.0415f;
	const auto curf = cur * 0.035f + Menu::Settings::menuY + 0.0415f;
	if (Menu::Settings::currentOption <= Menu::Settings::maxVisOptions && Menu::Settings::optionCount <= Menu::Settings::maxVisOptions)
	{
		if (*prev != cur)
		{
			if (prevf < curf)
			{
				if (prevf + ScrollerSpeed > curf)
					prevf = prevf + (curf - prevf);
				else
					prevf = prevf + ScrollerSpeed;
				Hooking::draw_rect(Menu::Settings::menuX, prevf, Menu::Settings::menuXscale - 0.000f, 0.035f, Menu::Settings::ScrollerR, Menu::Settings::ScrollerG, Menu::Settings::ScrollerB, Menu::Settings::ScrollerA);
				if (prevf >= curf)
				{
					prevf = curf;
					*prev = cur;
				}
			}
			if (prevf > curf)
			{
				if (prevf - ScrollerSpeed < curf)
					prevf = prevf - (prevf - curf);
				prevf = prevf - ScrollerSpeed;
				Hooking::draw_rect(Menu::Settings::menuX, prevf, Menu::Settings::menuXscale - 0.000f, 0.035f, Menu::Settings::ScrollerR, Menu::Settings::ScrollerG, Menu::Settings::ScrollerB, Menu::Settings::ScrollerA);
				if (prevf <= curf)
				{
					prevf = curf;
					*prev = cur;
				}
			}
		}
		else
		{
			*prev = cur;
			Hooking::draw_rect(Menu::Settings::menuX, cur * 0.035f + Menu::Settings::menuY + 0.0415f, Menu::Settings::menuXscale - 0.000f, 0.035f, Menu::Settings::ScrollerR, Menu::Settings::ScrollerG, Menu::Settings::ScrollerB, Menu::Settings::ScrollerA);
		}
	}
	else if ((Menu::Settings::optionCount > (Menu::Settings::currentOption - Menu::Settings::maxVisOptions)) && Menu::Settings::optionCount <= Menu::Settings::currentOption)
	{
		Hooking::draw_rect(Menu::Settings::menuX, ((Menu::Settings::optionCount - (Menu::Settings::currentOption - Menu::Settings::maxVisOptions)) * 0.035f + Menu::Settings::menuY + 0.0415f), Menu::Settings::menuXscale - 0.000f, 0.035f, Menu::Settings::ScrollerR, Menu::Settings::ScrollerG, Menu::Settings::ScrollerB, Menu::Settings::ScrollerA);
	}
}


float Menu::Settings::checkBoxPos = 0.949f;
float Menu::Settings::menuX = 0.85f;
float Menu::Settings::menuY = 0.100f;
float Menu::Settings::menuXscale = 0.19f;
bool Menu::Settings::DrawTextOutline = false;
bool Menu::Settings::selectPressed = false;
bool Menu::Settings::leftPressed = false;
bool Menu::Settings::rightPressed = false;
bool Menu::Settings::displayEnd = true;
bool Menu::Settings::showplayerinfo = true;
bool Menu::Settings::smoothscroll = false;
bool Menu::Settings::animatedHeader = true;

int Menu::Settings::maxVisOptions = 13;
int Menu::Settings::currentOption = 0;
int Menu::Settings::optionCount = 0;

SubMenus Menu::Settings::currentMenu;
SubMenus Menu::Settings::menusArray[1000];

int Menu::Settings::menuLevel = 0;
int Menu::Settings::optionsArray[1000];


int Menu::Settings::titleRectTexture = 1;
int Menu::Settings::ToggleTexture = 1;
int Menu::Settings::ScrollerR = 255;
int Menu::Settings::ScrollerG = 250;
int Menu::Settings::ScrollerB = 250;
int Menu::Settings::ScrollerA = 200;
RGBAF Menu::Settings::count{ 255, 255, 255, 255, 6 };
RGBAF Menu::Settings::titleText{ 30, 135, 175, 255, 1 };
RGBA Menu::Settings::titleRect{ 255, 255, 255, 255 };
RGBAF Menu::Settings::optionText{ 255, 255, 255, 255, 6 };
RGBAF Menu::Settings::breakText{ 255, 255, 255, 255, 1 };
RGBAF Menu::Settings::arrow{ 0, 0, 0, 255, 3 };
RGBA Menu::Settings::optionRect{ 0, 0, 0, 200 };//background
RGBA Menu::Settings::scroller{ 255, 255, 255, 200 };
RGBAF Menu::Settings::integre{ 255, 255, 255, 255, 0 };//intChar
RGBA Menu::Settings::line{ 255, 0, 0, 200 };
RGBA Menu::Settings::primary{ 255, 0, 0 };
RGBA Menu::Settings::secondary{ 0, 255, 0 };
RGBAF Menu::Settings::selectedTextClrs{ 0, 0, 0, 255, 6 };

int current_frame = -1;
int current_frame1 = -1;

string current_header = "";
string SpookiRyd3rsLogo = "";

void Menu::Title(const char * title)
{
	if (Settings::animatedHeader) {
		static auto ticker = GetTickCount();
		if ((GetTickCount() - ticker) >= 30) {
			if (!headerToUse) {
				if (++current_frame > 40)
					current_frame = 0;
				current_header = (current_frame < 10 ? "frame_0" : "frame_") + std::to_string(current_frame) + "_delay-0";
				SpookiRyd3rsLogo = "SpookiRyd3rsLogo1";
			}
			else if (headerToUse == 1) {
				if (++current_frame1 > 179)
					current_frame1 = 0;
				if (current_frame1 < 10)
					current_header = "frame_00";
				else if (current_frame1 < 100)
					current_header = "frame_0";
				else
					current_header = "frame_";
				current_header += std::to_string(current_frame1) + "_delay-0";
				SpookiRyd3rsLogo = "SpookiRyd3rsLogo2";
			}
			ticker = GetTickCount();
		}
		/*static __int8 counter;
		static int timerH;
		string tx = (counter < 10 ? "frame_0" : "frame_") + std::to_string(counter) + "_delay-0.05s";
		if (timeGetTime() - timerH > 30) {
			timerH = timeGetTime();
			counter++;
		}*/
			
		//Drawing::Text(title, Settings::titleText, { Settings::menuX, 0.095f }, { 0.85f, 0.85f }, true);
		Drawing::Sprite(SpookiRyd3rsLogo, current_header, Settings::menuX, Settings::menuY + 0.0175f, Menu::Settings::menuXscale, 0.085f, 0, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, 200);
	}
	else {
		Drawing::Text(title, Settings::titleText, { Settings::menuX, 0.095f }, { 0.85f, 0.85f }, true);
		Drawing::Sprite("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", Settings::menuX, Settings::menuY + 0.0175f, Menu::Settings::menuXscale, 0.085f, 0, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, 255);
	}
	
	//MOBILE::DESTROY_MOBILE_PHONE();//sound still works :(
	CAM::SET_CINEMATIC_BUTTON_ACTIVE(0);
	UI::HIDE_HELP_TEXT_THIS_FRAME();
	CAM::SET_CINEMATIC_BUTTON_ACTIVE(0);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(10);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(6);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(7);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(9);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(8);
	/*CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_NEXT_CAMERA, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_CHARACTER_WHEEL, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MULTIPLAYER_INFO, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_PHONE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_ALTERNATE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_CIN_CAM, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MAP_POI, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_PHONE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_RADIO_WHEEL, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_HEADLIGHT, true);*/
}

bool Menu::Option(const char * option)
{
	Settings::optionCount++;
	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
	{
		!onThis ? Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.09f, (Settings::optionCount)*0.035f + Settings::menuY + 0.025f }, { 0.45f, 0.45f }, false) : NULL;
		onThis ? Drawing::Text(option, Settings::selectedTextClrs, { Settings::menuX - 0.09f, (Settings::optionCount)*0.035f + Settings::menuY + 0.025f }, { 0.45f, 0.45f }, false) : NULL;
		Drawing::Rect(Settings::optionRect, { Settings::menuX, (Settings::optionCount)*0.035f + Settings::menuY + 0.0415f }, { Menu::Settings::menuXscale, 0.035f });
		if (!Settings::smoothscroll)
		{
			onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX, (Settings::optionCount)*0.035f + Settings::menuY + 0.0415f }, { Menu::Settings::menuXscale, 0.035f }) : NULL;
		}
	}
	else if (Settings::optionCount > (Settings::currentOption - Settings::maxVisOptions) && Settings::optionCount <= Settings::currentOption)
	{
		!onThis ? Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.09f, (Settings::optionCount - (Settings::currentOption - Settings::maxVisOptions))*0.035f + Settings::menuY + 0.025f }, { 0.45f, 0.45f }, false) : NULL;
		onThis ? Drawing::Text(option, Settings::selectedTextClrs, { Settings::menuX - 0.09f, (Settings::optionCount - (Settings::currentOption - Settings::maxVisOptions))*0.035f + Settings::menuY + 0.025f }, { 0.45f, 0.45f }, false) : NULL;
		Drawing::Rect(Settings::optionRect, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - Settings::maxVisOptions))*0.035f + Settings::menuY + 0.0415f }, { Menu::Settings::menuXscale, 0.035f });
		if (!Settings::smoothscroll)
		{
			onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - Settings::maxVisOptions))*0.035f + Settings::menuY + 0.0415f }, { Menu::Settings::menuXscale, 0.035f }) : NULL;
		}
	}
	if (Menu::Settings::smoothscroll)
	{
		onThis ? smoothscroll(&prevOption, Menu::Settings::currentOption) : NULL;
	}

	if (Settings::currentOption == Settings::optionCount)
	{
		if (Settings::selectPressed)
		{
			return true;
		}
	}
	return false;
}
bool Menu::Option(const char * option, std::function<void()> function)
{
	Option(option);
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	return false;
}

bool Menu::Break(const char * option)
{
	Settings::optionCount++;
	//bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
	{
		Drawing::Text(option, Settings::breakText, { Settings::menuX, (Settings::optionCount)*0.035f + Settings::menuY + 0.025f }, { 0.45f, 0.45f }, true);
		Drawing::Rect(Settings::optionRect, { Settings::menuX, (Settings::optionCount)*0.035f + Settings::menuY + 0.0415f }, { Menu::Settings::menuXscale, 0.035f });
	}
	else if (Settings::optionCount > (Settings::currentOption - Settings::maxVisOptions) && Settings::optionCount <= Settings::currentOption)
	{
		Drawing::Text(option, Settings::breakText, { Settings::menuX, (Settings::optionCount - (Settings::currentOption - Settings::maxVisOptions))*0.035f + Settings::menuY + 0.025f }, { 0.45f, 0.45f }, true);
		Drawing::Rect(Settings::optionRect, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - Settings::maxVisOptions))*0.035f + Settings::menuY + 0.0415f }, { Menu::Settings::menuXscale, 0.035f });
	}
	return false;
}
bool Menu::MenuOption(const char * option, SubMenus newSub)
{
	Option(option);
	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text("~c~>~r~>", Menu::Settings::optionText, { Settings::menuX + 0.078f, (Settings::optionCount)*0.035f + Settings::menuY + 0.025f }, { 0.45f, 0.45f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text("~c~>~r~>", Menu::Settings::optionText, { Settings::menuX + 0.078f, (Settings::optionCount - (Settings::currentOption - Settings::maxVisOptions))*0.035f + Settings::menuY + 0.025f }, { 0.45f, 0.45f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		MenuLevelHandler::MoveMenu(newSub);
		return true;
	}
	return false;
}
bool Menu::MenuOption(const char * option, SubMenus newSub, std::function<void()> function)
{
	MenuOption(option, newSub);
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	return false;
}
bool Menu::Toggle(const char * option, bool & b00l)
{
	Option(option);
	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Sprite("shared", b00l ? "medaldot_32" : "emptydot_32", (Settings::menuX + 0.078f), (Settings::optionCount * 0.035f + Settings::menuY + 0.042f), 0.015f, 0.027f, 255, b00l ? 0 : 210, b00l ? 255 : 0, b00l ? 30 : 0, 250);//it was 0
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Sprite("shared", b00l ? "medaldot_32" : "emptydot_32", (Settings::menuX + 0.078f), ((Settings::optionCount - (Settings::currentOption - Settings::maxVisOptions))* 0.035f + Settings::menuY + 0.042f), 0.015f, 0.027f, 255, b00l ? 0 : 210, b00l ? 255 : 0, b00l ? 30 : 0, 255);
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		b00l ^= 1;
		return true;
	}
	return false;
}
bool Menu::Toggle(const char * option, bool & b00l, std::function<void()> function)
{
	Toggle(option, b00l);
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	return false;
}

bool Menu::Int(const char * option, int & _int, int min, int max)
{
	return Menu::Int(option, _int, min, max, 1);
}

bool Menu::Int(const char * option, int & _int, int min, int max, int step)
{
	Option(option);
	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::leftPressed) {
			_int < max ? _int += step : _int = min;
		}
		else if (Settings::rightPressed) {
			_int >= min ? _int -= step : _int = max;
		}
		_int < min ? _int = max : _int > max ? _int = min : NULL;
	}
	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		onThis?
		Drawing::Text(Tools::StringToChar("<" + std::to_string(_int) + "/" + std::to_string(max) + ">"), Menu::Settings::selectedTextClrs, { Settings::menuX + 0.077f, Settings::optionCount * 0.035f + Settings::menuY + 0.030f }, { 0.32f, 0.32f }, true, true, true):
		Drawing::Text(Tools::StringToChar("<" + std::to_string(_int) + "/" + std::to_string(max) + ">"), Menu::Settings::optionText, { Settings::menuX + 0.077f, Settings::optionCount * 0.035f + Settings::menuY + 0.030f }, { 0.32f, 0.32f }, true, true, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		onThis ? 
		Drawing::Text(Tools::StringToChar("<" + std::to_string(_int) + "/" + std::to_string(max) + ">"), Menu::Settings::selectedTextClrs, { Settings::menuX + 0.077f, (Settings::optionCount - (Settings::currentOption - Settings::maxVisOptions))*0.035f + Settings::menuY + 0.030f }, { 0.32f, 0.32f }, true, true, true):
		Drawing::Text(Tools::StringToChar("<" + std::to_string(_int) + "/" + std::to_string(max) + ">"), Menu::Settings::optionText, { Settings::menuX + 0.077f, (Settings::optionCount - (Settings::currentOption - Settings::maxVisOptions))*0.035f + Settings::menuY + 0.030f }, { 0.32f, 0.32f }, true, true, true);
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}

bool Menu::Int(const char * option, int & _int, int min, int max, int step, std::function<void()> function)
{
	Int(option, _int, min, max, step);
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}
#pragma warning(disable: 4244)
bool Menu::Float(const char * option, float & _float, int min, int max, float step)
{
	Option(option);
	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::rightPressed) {
			_float <= min ? _float = max : _float -= step;
		}
		else if (Settings::leftPressed) {
			_float >= max ? _float = min : _float += step;
		}
		_float < min ? _float = max : _float > max ? _float = min : NULL;
	}
	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions) {
		std::string currStr = std::to_string(_float);
		onThis?
		Drawing::Text(Tools::StringToChar("<" + currStr.substr(0, (currStr.length() - 4)) + "/" + std::to_string(max) + ">"), Menu::Settings::selectedTextClrs, { Settings::menuX + 0.073f, Settings::optionCount * 0.035f + Settings::menuY + 0.030f }, { 0.32f, 0.32f }, true, true, true):
		Drawing::Text(Tools::StringToChar("<" + currStr.substr(0, (currStr.length() - 4)) + "/" + std::to_string(max) + ">"), Menu::Settings::optionText, { Settings::menuX + 0.073f, Settings::optionCount * 0.035f + Settings::menuY + 0.030f }, { 0.32f, 0.32f }, true, true, true);
	}
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption) {
		std::string currStr = std::to_string(_float);
		onThis?
		Drawing::Text(Tools::StringToChar("<" + currStr.substr(0, (currStr.length() - 4)) + "/" + std::to_string(max) + ">"), Menu::Settings::selectedTextClrs, { Settings::menuX + 0.073f, (Settings::optionCount - (Settings::currentOption - Settings::maxVisOptions))*0.035f + Settings::menuY + 0.030f }, { 0.32f, 0.32f }, true, true, true):
		Drawing::Text(Tools::StringToChar("<" + currStr.substr(0, (currStr.length() - 4)) + "/" + std::to_string(max) + ">"), Menu::Settings::optionText, { Settings::menuX + 0.073f, (Settings::optionCount - (Settings::currentOption - Settings::maxVisOptions))*0.035f + Settings::menuY + 0.030f }, { 0.32f, 0.32f }, true, true, true);
	}
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}

bool Menu::IntChar(const char* option, std::vector<char*> display, int& _int, int min, int max, int step)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::leftPressed) {
			_int < max ? _int += step : _int = min;
		}
		if (Settings::rightPressed) {
			_int > min ? _int -= step : _int = max;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar((std::string)display.at(_int)), Settings::integre, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.128f }, { 0.30f, 0.30f }, false, true, false);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar((std::string)display.at(_int)), Settings::integre, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - Settings::maxVisOptions)) * 0.035f + 0.128f }, { 0.30f, 0.30f }, false, true, false);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed && Settings::selectPressed) return true;
	return false;
}
#pragma warning(default: 4244)
#pragma warning(disable: 4267)
/*bool Menu::IntVector(const char * option, std::vector<int> Vector, int & position)
{
	Option(option);
	if (Settings::optionCount == Settings::currentOption) {
		int max = Vector.size() - 1;
		int min = 0;
		if (Settings::leftPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::rightPressed) {
			position < max ? position++ : position = min;
		}
	}
	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + Settings::menuY + 0.025f }, { 0.5f, 0.5f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { 0.5f, 0.5f }, true);
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::IntVector(const char * option, std::vector<int> Vector, int & position, std::function<void()> function)
{
	IntVector(option, Vector, position);
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}
bool Menu::FloatVector(const char * option, std::vector<float> Vector, int & position)
{
	Option(option);
	if (Settings::optionCount == Settings::currentOption) {
		size_t max = Vector.size() - 1;
		int min = 0;
		if (Settings::leftPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::rightPressed) {
			position < max ? position++ : position = min;
		}
	}
	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.125f }, { 0.5f, 0.5f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { 0.5f, 0.5f }, true);
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::FloatVector(const char * option, std::vector<float> Vector, int & position, std::function<void()> function)
{
	FloatVector(option, Vector, position);
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}
bool Menu::StringVector(const char * option, std::vector<std::string> Vector, int & position)
{
	Option(option);
	if (Settings::optionCount == Settings::currentOption) {
		size_t max = Vector.size() - 1;
		int min = 0;
		if (Settings::leftPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::rightPressed) {
			position < max ? position++ : position = min;
		}
	}
	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar((Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.125f }, { 0.5f, 0.5f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar((Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { 0.5f, 0.5f }, true);
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::StringVector(const char * option, std::vector<std::string> Vector, int & position, std::function<void()> function)
{
	StringVector(option, Vector, position);
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}
bool Menu::StringVector(const char * option, std::vector<char*> Vector, int & position)
{
	Option(option);
	if (Settings::optionCount == Settings::currentOption) {
		size_t max = Vector.size() - 1;
		int min = 0;
		if (Settings::leftPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::rightPressed) {
			position < max ? position++ : position = min;
		}
	}
	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(((Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.125f }, { 0.5f, 0.5f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(((Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { 0.5f, 0.5f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
#pragma warning(default: 4267)
bool Menu::StringVector(const char * option, std::vector<char*> Vector, int & position, std::function<void()> function)
{
	StringVector(option, Vector, position);
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}
bool Menu::ListVector(const char * option, std::vector<char*> Vector, int & position)
{
	constexpr static const VECTOR2_2 textSize = { 0.45f, 0.45f };
	bool onThis = Settings::currentOption == Settings::optionCount + 1 ? true : false;
	Option("");
	if (Settings::optionCount == Settings::currentOption) {
		size_t max = Vector.size() - 1;
		int min = 0;
		if (Settings::rightPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::leftPressed) {
			position < max ? position++ : position = min;
		}
	}
	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions) {
		std::string SelectedChar
			= UI::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Vector[position])));
		if (SelectedChar == "NULL") SelectedChar = Vector[position];
		UI::SET_TEXT_COLOUR(255, 255, 255, 255);
		UI::SET_TEXT_FONT(6);
		UI::SET_TEXT_SCALE(textSize.w, textSize.h);
		UI::SET_TEXT_CENTRE(false);
		if (Menu::Settings::DrawTextOutline) {
			UI::SET_TEXT_DROPSHADOW(1, 0, 0, 0, 0);
			UI::SET_TEXT_EDGE(1, 0, 0, 0, 0);
			UI::SET_TEXT_OUTLINE();
		}
		UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
		std::string s = option;
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(Tools::StringToChar(s + " <" + SelectedChar + ">"));
		UI::END_TEXT_COMMAND_DISPLAY_TEXT(Settings::menuX - 0.09f, Settings::optionCount * 0.035f + Settings::menuY + 0.025f);
	}
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption) {
		std::string SelectedChar
			= UI::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Vector[position])));
		if (SelectedChar == "NULL") SelectedChar = Vector[position];
		UI::SET_TEXT_COLOUR(255, 255, 255, 255);
		UI::SET_TEXT_FONT(6);
		UI::SET_TEXT_SCALE(textSize.w, textSize.h);
		UI::SET_TEXT_CENTRE(false);
		UI::SET_TEXT_DROPSHADOW(1, 0, 0, 0, 0);
		UI::SET_TEXT_EDGE(1, 0, 0, 0, 0);
		UI::SET_TEXT_OUTLINE();
		UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
		std::string s = option;
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(Tools::StringToChar(s + " <" + SelectedChar + ">"));
		UI::END_TEXT_COMMAND_DISPLAY_TEXT(Settings::menuX - 0.09f, (Settings::optionCount - (Settings::currentOption - Settings::maxVisOptions))*0.035f + Settings::menuY + 0.025f);
	}
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return false;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return false;
	return false;
}*/

void Menu::info(const char * info)
{
	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
	{
		if (bool onThis = true) { Drawing::Text(info, Settings::optionText, { Settings::menuX - 0.100f, (Settings::maxVisOptions + 1) * 0.035f + 0.1600f }, { 0.25f, 0.25f }, false); }
	}
	else if (Settings::optionCount > (Settings::currentOption - Settings::maxVisOptions) && Settings::optionCount <= Settings::currentOption)
	{
		if (bool onThis = true) { Drawing::Text(info, Settings::optionText, { Settings::menuX - 0.100f, (Settings::optionCount - (Settings::currentOption - Settings::maxVisOptions))*0.035f + 0.1300f }, { 0.25f, 0.25f }, false); }
	}
}
void PlaySoundFrontend_default(char* sound_name)
{
	AUDIO::PLAY_SOUND_FRONTEND(-1, sound_name, "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
}
void PlaySoundFrontend_default2(char* sound_name)
{
	AUDIO::PLAY_SOUND_FRONTEND(-1, sound_name, "DLC_HEIST_BIOLAB_PREP_HACKING_SOUNDS", 0);
}
int Menu::Settings::keyPressDelay = 200;
int Menu::Settings::keyPressPreviousTick = GetTickCount();
int Menu::Settings::keyPressDelay2 = 100;
int Menu::Settings::keyPressPreviousTick2 = GetTickCount();
int Menu::Settings::keyPressDelay3 = 140;
int Menu::Settings::keyPressPreviousTick3 = GetTickCount();
int Menu::Settings::openKey = VK_MULTIPLY;
int Menu::Settings::backKey = VK_NUMPAD0;
int Menu::Settings::upKey = VK_NUMPAD8;
int Menu::Settings::downKey = VK_NUMPAD2;
int Menu::Settings::leftKey = VK_NUMPAD4;
int Menu::Settings::rightKey = VK_NUMPAD6;
int Menu::Settings::selectKey = VK_NUMPAD5;
int Menu::Settings::arrowupKey = VK_UP;
int Menu::Settings::arrowdownKey = VK_DOWN;
int Menu::Settings::arrowleftKey = VK_LEFT;
int Menu::Settings::arrowrightKey = VK_RIGHT;
int Menu::Settings::enterKey = VK_RETURN;
int Menu::Settings::deleteKey = VK_BACK;
#pragma endregion
bool Menu::Settings::controllerinput = false;
void Menu::Checks::Controlls()
{
	Settings::selectPressed = false;
	Settings::leftPressed = false;
	Settings::rightPressed = false;
	if (GetTickCount() - Settings::keyPressPreviousTick > Settings::keyPressDelay) {
		if (GetTickCount() - Settings::keyPressPreviousTick2 > Settings::keyPressDelay2) {
			if (GetTickCount() - Settings::keyPressPreviousTick3 > Settings::keyPressDelay3) {
				if (IsKeyPressed(VK_MULTIPLY) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlScriptRB) && CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight) && Settings::controllerinput) {
					Settings::menuLevel == 0 ? MenuLevelHandler::MoveMenu(SubMenus::mainmenu) : Settings::menuLevel == 1 ? MenuLevelHandler::BackMenu() : NULL;
					Settings::keyPressPreviousTick = GetTickCount();
					prevOption = 1;
				}
				else if (IsKeyPressed(VK_NUMPAD0) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendCancel) && Settings::controllerinput) {
					prevOption = 1;
					Settings::menuLevel > 0 ? MenuLevelHandler::BackMenu() : NULL;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("BACK");

					Settings::keyPressPreviousTick = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD8) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendUp) && Settings::controllerinput) {
					Settings::currentOption > 1 ? Settings::currentOption-- : Settings::currentOption = Settings::optionCount;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("NAV_UP_DOWN");

					Settings::keyPressPreviousTick2 = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD2) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendDown) && Settings::controllerinput) {
					Settings::currentOption < Settings::optionCount ? Settings::currentOption++ : Settings::currentOption = 1;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("NAV_UP_DOWN");

					Settings::keyPressPreviousTick2 = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD6) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight) && Settings::controllerinput) {
					Settings::leftPressed = true;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("NAV_UP_DOWN");

					Settings::keyPressPreviousTick3 = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD4) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneLeft) && Settings::controllerinput) {
					Settings::rightPressed = true;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("NAV_UP_DOWN");

					Settings::keyPressPreviousTick3 = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept) && Settings::controllerinput) {
					Settings::selectPressed = true;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("SELECT");

					Settings::keyPressPreviousTick = GetTickCount();
				}
			}
		}
	}
	Settings::optionCount = 0;
}
#pragma warning(default : 4018)
void Menu::MenuLevelHandler::MoveMenu(SubMenus menu)
{
	Settings::menusArray[Settings::menuLevel] = Settings::currentMenu;
	Settings::optionsArray[Settings::menuLevel] = Settings::currentOption;
	Settings::menuLevel++;
	Settings::currentMenu = menu;
	Settings::currentOption = 1;
}
void Menu::MenuLevelHandler::BackMenu()
{
	Settings::menuLevel--;
	Settings::currentMenu = Settings::menusArray[Settings::menuLevel];
	Settings::currentOption = Settings::optionsArray[Settings::menuLevel];
}
char * Menu::Tools::StringToChar(std::string string)
{
	return _strdup(string.c_str());
}
void Menu::Files::WriteStringToIni(std::string string, std::string file, std::string app, std::string key)
{
	WritePrivateProfileStringA(app.c_str(), key.c_str(), string.c_str(), file.c_str());
}
std::string Menu::Files::ReadStringFromIni(std::string file, std::string app, std::string key)
{
	char buf[100];
	GetPrivateProfileStringA(app.c_str(), key.c_str(), "none", buf, 100, file.c_str());
	return (std::string)buf;
}
void Menu::Files::WriteIntToIni(int intValue, std::string file, std::string app, std::string key)
{
	WriteStringToIni(std::to_string(intValue), file, app, key);
}
int Menu::Files::ReadIntFromIni(std::string file, std::string app, std::string key)
{
	return std::stoi(ReadStringFromIni(file, app, key));
}
void Menu::Files::WriteFloatToIni(float floatValue, std::string file, std::string app, std::string key)
{
	WriteStringToIni((std::to_string(floatValue)), file, app, key);
}
float Menu::Files::ReadFloatFromIni(std::string file, std::string app, std::string key)
{
	return std::stof(ReadStringFromIni(file, app, key));
}
void Menu::Files::WriteBoolToIni(bool b00l, std::string file, std::string app, std::string key)
{
	WriteStringToIni(b00l ? "true" : "false", file, app, key);
}
bool Menu::Files::ReadBoolFromIni(std::string file, std::string app, std::string key)
{
	return ReadStringFromIni(file, app, key) == "true" ? true : false;
}
void Menu::Vehicle(std::string texture1, std::string texture2)
{
	Menu::Drawing::Sprite(texture1, texture2, Menu::Settings::menuX + 0.24f, 0.2f, 0.11f, 0.11f, 0, 255, 255, 255, 255);
}
void Menu::Vehicle2(std::string texture1, std::string texture2)
{
	Menu::Drawing::Sprite(texture1, texture2, Menu::Settings::menuX + 0.24f, 0.5f, 0.16f, 0.11f, 0, 255, 255, 255, 255);
}
void Menu::Speedometer(char* text)
{
	Drawing::Text(text, Settings::titleText, { 0.84f, 0.8800f }, { 0.70f, 0.70f }, false);
}
void Menu::fps(char* text)
{
	Drawing::Text(text, Settings::optionText, { 0.84f, 0.050f }, { 0.70f, 0.70f }, false);
}
void Menu::AddSmallTitle(char* text)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX + 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Sprite("CommonMenu", "", Settings::menuX + 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
	else
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX - 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Sprite("CommonMenu", "", Settings::menuX - 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
}
void Menu::AddSmallInfo(char* text, short line)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.175f, ((16 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 16 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX + 0.120f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
	else
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.175f, ((16 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 16 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX - 0.228f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
}
/*void Menu::AddSmallTitle2(char* text)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX + 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Sprite("CommonMenu", "", Settings::menuX + 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
	else
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX - 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Sprite("CommonMenu", "", Settings::menuX - 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
}
void Menu::AddSmallInfo2(char* text, short line)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (line == 1) {
			////////{
			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.175f, ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 13 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX + 0.120f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
	else
	{
		if (line == 1)
		{
			Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.175f, ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 13 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX - 0.228f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
}
void Menu::AddSmallTitle3(char* text)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX + 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Sprite("CommonMenu", "", Settings::menuX + 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
	else
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX - 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Sprite("CommonMenu", "", Settings::menuX - 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
}
void Menu::AddSmallInfo3(char* text, short line)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (line == 1)
		{
			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.175f, ((11 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 11 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX + 0.120f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
	else
	{
		if (line == 1)
		{
			Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.175f, ((11 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 11 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX - 0.228f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
}*/
void Menu::End()
{
	if (Menu::Settings::displayEnd)
	{
		int opcount = Settings::optionCount;
		int currop = Settings::currentOption;
		if (opcount >= Settings::maxVisOptions)
		{
			Drawing::Rect({ 40, 40, 40, 200 }, { Settings::menuX, (Settings::maxVisOptions + 1) * 0.035f + Settings::menuY + 0.0365f }, { Menu::Settings::menuXscale, 0.025f });
			Drawing::Sprite("commonmenu", "shop_arrows_upanddown", Settings::menuX, ((Settings::maxVisOptions + 1) * 0.035f + Settings::menuY + 0.036f), 0.02f, 0.035f, 180, Settings::line.r, Settings::line.g, Settings::line.b, Settings::line.a);
		}
		else if (opcount > 0)
		{
			Drawing::Rect({ 40, 40, 40, 200 }, { Settings::menuX, (Settings::optionCount + 1) * 0.035f + Settings::menuY + 0.0365f }, { Menu::Settings::menuXscale, 0.025f });
			Drawing::Sprite("commonmenu", "shop_arrows_upanddown", Settings::menuX, ((Settings::optionCount + 1) * 0.035f + Settings::menuY + 0.036f), 0.020f, 0.035f, 180, Settings::line.r, Settings::line.g, Settings::line.b, Settings::line.a);
		}
	}
}

void Menu::OptionInfo(const std::string text) {
	auto currentOPtion = Settings::currentOption;
	auto optionCount = Settings::optionCount;
	VECTOR2 position = { Settings::menuX, (optionCount + 2) * 0.035f + Settings::menuY + 0.0547f };
	VECTOR2 t_position = { Settings::menuX - 0.09f, (optionCount + 2) * 0.035f + Settings::menuY + 0.0410f };
	VECTOR2_2 size = { Settings::menuXscale, 0.035f };
	if (!GAMEPLAY::IS_STRING_NULL_OR_EMPTY(const_cast<char*>((char*)text.c_str()))) {
		Drawing::Rect({ 0, 0, 0, 175 }, position, size);
		Drawing::Text(const_cast<char*>((char*)text.c_str()), { 255, 255, 255, 255, 4 }, t_position, { 0.41f, 0.41f }, false, false, false);
	}
}