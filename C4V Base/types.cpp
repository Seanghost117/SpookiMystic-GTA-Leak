#include "stdafx.h"

float deg_to_rad(float deg)
{
	return deg * 3.141592653589793f / 180.f;
}

Vector3::Vector3(float X, float Y, float Z) :
	x(X),
	y(Y),
	z(Z)
{}
Vector3::Vector3(float X, int, float Y, int, float Z, int) :
	x(X),
	y(Y),
	z(Z)
{}
Vector3::Vector3(float v, int) :
	x(v),
	y(v),
	z(v)
{}
Vector3::Vector3(float v) :
	x(v),
	y(v),
	z(v)
{}
Vector3::Vector3() :
	x(0.f),
	y(0.f),
	z(0.f)
{}

v3::v3(float fx, float fy, float fz)
{
	x = fx;
	y = fy;
	z = fz;
}

v3&		v3::transformRotToDir()
{
	double	a = deg_to_rad(x),
		b = deg_to_rad(z),
		c = cos(a);
	x = (float)-(c * sin(b));
	y = (float)(c * cos(b));
	z = (float)sin(a);
	return *this;
}

v3&		v3::operator=(const v3& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	return *this;
}

v3&		v3::operator*=(const v3& rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	return *this;
}

v3&		v3::operator*=(const float rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	return *this;
}

v3&		v3::operator+=(const v3& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

v3&		v3::operator-=(const v3& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

