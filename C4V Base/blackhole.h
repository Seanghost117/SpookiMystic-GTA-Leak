#pragma once

// blackhole.h
class blackHole {
public:
	class var {
	public:
		static float blackholeX;
		static float blackholeY;
		static float blackholeZ;
		static std::vector<uint32_t> vehicles;
		static bool toggle;
	};

	static void initialize();
	static void tick();
	static void setCurrentPos();
};