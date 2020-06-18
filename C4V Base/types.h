#pragma once

typedef DWORD Void;
typedef DWORD Any;
typedef DWORD uint;
typedef DWORD Hash;
typedef int Entity;
typedef int Player;
typedef int FireId;
typedef int Ped;
typedef int Vehicle;
typedef int Cam;
typedef int CarGenerator;
typedef int Group;
typedef int Train;
typedef int Pickup;
typedef int Object;
typedef int Weapon;
typedef int Interior;
typedef int Blip;
typedef int Texture;
typedef int TextureDict;
typedef int CoverPoint;
typedef int Camera;
typedef int TaskSequence;
typedef int ColourIndex;
typedef int Sphere;
typedef int ScrHandle;

float deg_to_rad(float);

typedef class v2
{
public:
	float	x = 0,
		y = 0;
} v2;

typedef class v3
{
public:
	float	x = 0,
		y = 0,
		z = 0;

	v3() {}
	v3(float fx, float fy, float fz);

	v3&		v3::operator=(const v3& rhs);
	v3&		v3::operator*=(const v3& rhs);
	v3&		v3::operator*=(const float rhs);
	v3&		v3::operator+=(const v3& rhs);
	v3&		v3::operator-=(const v3& rhs);
	v3&		v3::transformRotToDir();
} v3;

inline bool operator==(const v3& lhs, const v3& rhs)
{
	if (lhs.x != rhs.x || lhs.y != rhs.y || lhs.z != rhs.z)
		return false;
	return true;
}

inline bool operator!=(const v3& lhs, const v3& rhs)
{
	return !operator==(lhs, rhs);
}

inline v3 operator-(v3 lhs, const v3& rhs)
{
	lhs -= rhs;
	return lhs;
}

inline v3 operator+(v3 lhs, const v3& rhs)
{
	lhs += rhs;
	return lhs;
}

inline v3 operator*(v3 lhs, const v3& rhs)
{
	lhs *= rhs;
	return lhs;
}

inline v3 operator*(v3 lhs, const float& rhs)
{
	lhs *= rhs;
	return lhs;
}

typedef v3 v3;

#pragma pack(push, 1)
typedef struct Vector3
{
	float x;
	DWORD _paddingx;
	float y;
	DWORD _paddingy;
	float z;
	DWORD _paddingz;

	operator v3() const
	{
		return v3(x, y, z);
	}

	Vector3(float, float, float);
	Vector3(float, int, float, int, float, int);
	Vector3(float, int);
	Vector3(float);
	Vector3();
} Vector3;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct
{
	float x;
	float y;
	float z;
} Vector3_t;
#pragma pack(pop)

struct MemoryPool
{
	uintptr_t ListAddr;
	char* BoolAdr;
	int MaxCount;
	int ItemSize;
};


struct Blip_t {
public:
	__int32 iID; //0x0000 
	__int8 iID2; //0x0004 
	char _0x0005[3];
	BYTE N000010FB; //0x0008 (80 = moves with player, some values will turn icon into map cursor and break it)
	char _0x0009[7];
	Vector3 coords;
	char _0x001C[6];
	BYTE bFocused; //0x0022   (Focused? 0100 0000)
	char _0x0023[5];
	char* szMessage; //0x0028 If not null, contains the string of whatever the blip says when selected.
	char _0x0030[16];
	int iIcon; //0x0040
	char _0x0044[4];
	DWORD dwColor; //0x0048 (Sometimes works?)
	char _0x004C[4];
	float fScale; //0x0050 
	__int16 iRotation; //0x0054 Heading
	BYTE bInfoIDType; //0x0056 GET_BLIP_INFO_ID_TYPE
	BYTE bZIndex; //0x0057 
	BYTE bDisplay; //0x0058  Also Visibility 0010
	BYTE bAlpha; //0x0059
};//Size=0x005A

struct BlipList {
public:
	Blip_t * m_Blips[1500]; //0x0000 

};//Size=0x2F18

typedef struct notifyMsg {//for tse event
	string output_name, flags;
} notifyMsg;