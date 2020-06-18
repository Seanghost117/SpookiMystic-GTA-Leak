#pragma once

extern enum SubMenus;
typedef struct VECTOR2 {
	float x, y;
};
typedef struct VECTOR2_2 {
	float w, h;
};
typedef struct RGBAF {
	int r, g, b, a, f;
};
typedef struct RGBA {
	int r, g, b, a;
};
typedef struct RGB {
	int r, g, b;
};
namespace Menu {
	void OptionInfo(const std::string text);
	namespace Drawing {
		void Text(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center, bool rightAlign = false, bool outline = true);
		//void Title(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center);
		void Rect(RGBA rgba, VECTOR2 position, VECTOR2_2 size);
		void Sprite(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a);
	}
	namespace Settings {
		extern bool selectPressed;
		extern bool leftPressed;
		extern bool rightPressed;
		extern bool displayEnd;
		extern bool showplayerinfo;
		extern bool smoothscroll;
		extern bool animatedHeader;
		extern bool center;
		extern bool controllerinput;
		extern bool GlareOnOff;
		extern bool DrawGradientRect;
		extern int maxVisOptions;
		extern int currentOption;
		extern int optionCount;
		extern SubMenus currentMenu;
		extern int menuLevel;
		extern int optionsArray[1000];
		extern SubMenus menusArray[1000];
		extern int titleRectTexture;
		extern int ToggleTexture;
		extern RGBAF count;
		extern RGBAF titleText;
		extern RGBA titleRect;
		extern RGBAF breakText;
		extern RGBAF optionText;
		extern RGBA selectedText;
		extern RGBAF arrow;
		extern RGBAF integre;
		extern RGBA optionRect;
		extern RGBA scroller;
		extern RGBA line;
		extern RGBA primary;
		extern RGBA secondary;
		extern RGBAF selectedTextClrs;
		extern float menuX;
		extern float menuY;
		extern float menuXscale;
		extern float checkBoxPos;
		extern float testfloat;
		extern bool DrawTextOutline;
		extern int keyPressDelay;
		extern int keyPressPreviousTick;
		extern int keyPressDelay2;
		extern int keyPressPreviousTick2;
		extern int keyPressDelay3;
		extern int keyPressPreviousTick3;
		extern int openKey;
		extern int backKey;
		extern int upKey;
		extern int downKey;
		extern int leftKey;
		extern int rightKey;
		extern int selectKey;
		extern int arrowupKey;
		extern int arrowdownKey;
		extern int arrowleftKey;
		extern int arrowrightKey;
		extern int enterKey;
		extern int deleteKey;
		extern int openpress;
		extern int downpress;
		extern int uppress;
		extern int backpress;
		extern int click;
		extern int leftpress;
		extern int rightpress;
		extern float GlareXPos;
		extern int ScrollerR;
		extern int ScrollerG;
		extern int ScrollerB;
		extern int ScrollerA;
	}
	namespace MenuLevelHandler {
		void MoveMenu(SubMenus menu);
		void BackMenu();
	}
	namespace Checks {
		void Controlls();
	}
	namespace Tools {
		char* StringToChar(std::string string);
	}
	namespace Files {
		void WriteStringToIni(std::string string, std::string file, std::string app, std::string key);
		std::string ReadStringFromIni(std::string file, std::string app, std::string key);
		void WriteIntToIni(int intValue, std::string file, std::string app, std::string key);
		int ReadIntFromIni(std::string file, std::string app, std::string key);
		void WriteFloatToIni(float floatValue, std::string file, std::string app, std::string key);
		float ReadFloatFromIni(std::string file, std::string app, std::string key);
		void WriteBoolToIni(bool b00l, std::string file, std::string app, std::string key);
		bool ReadBoolFromIni(std::string file, std::string app, std::string key);
	}
	bool YTD(const std::string name);
	void Title(const char* title);
	void info(const char * title);
	void Vehicle(std::string texture1, std::string texture2);
	void Vehicle2(std::string texture1, std::string texture2);
	void Speedometer(char* text);
	void fps(char* text);
	void AddSmallTitle(char* text);
	void AddSmallInfo(char* text, short line);
	//void AddSmallTitle2(char* text);
	//void AddSmallInfo2(char* text, short line);
	//void AddSmallTitle3(char* text);
	//void AddSmallInfo3(char* text, short line);
	void End();
	bool Break(const char* option);
	bool Option(const char* option);
	bool Option(const char* option, std::function<void()> function);
	bool MenuOption(const char* option, SubMenus newSub);
	bool MenuOption(const char* option, SubMenus newSub, std::function<void()> function);
	bool Toggle(const char* option, bool& b00l);
	bool Toggle(const char* option, bool& b00l, std::function<void()> function);
	bool Int(const char* option, int& _int, int min, int max);
	bool Int(const char* option, int& _int, int min, int max, int step);
	bool Int(const char* option, int& _int, int min, int max, int step, std::function<void()> function);
	bool Float(const char* option, float& _float, int min, int max, float step = 0.01f);
	bool IntChar(const char * option, std::vector<char*> display, int & _int, int min, int max, int step = 1);
	//bool IntVector(const char* option, std::vector<int> Vector, int& position);
	//bool IntVector(const char* option, std::vector<int> Vector, int& position, std::function<void()> function);
	//bool FloatVector(const char* option, std::vector<float> Vector, int& position);
	//bool FloatVector(const char* option, std::vector<float> Vector, int& position, std::function<void()> function);
	//bool StringVector(const char* option, std::vector<std::string> Vector, int& position);
	//bool StringVector(const char* option, std::vector<std::string> Vector, int& position, std::function<void()> function);
	//bool StringVector(const char* option, std::vector<char*> Vector, int& position);
	//bool StringVector(const char* option, std::vector<char*> Vector, int& position, std::function<void()> function);
	//bool ListVector(const char * option, std::vector<char*> Vector, int & position);
}