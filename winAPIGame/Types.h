#pragma once
#include <cmath>
#include <windows.h>

using int8		= __int8;
using int16		= __int16;
using int32		= __int32;
using int64		= __int64;

using uint8		= unsigned __int8;
using uint16	= unsigned __int16;
using uint32	= unsigned __int32;
using uint64	= unsigned __int64;

struct Stat
{
	int32 hp = 0;
	int32 maxHp = 0;
	float speed = 0;
};


struct Vector
{
	Vector(){}
	Vector(float x, float y) : x(x), y(y) {}
	Vector(POINT pt) : x(static_cast<float>(pt.x)), y(static_cast<float>(pt.y)) {}

#pragma region Operators 

	Vector operator+(const Vector& other)
	{
		Vector ret;
		ret.x = x + other.x;
		ret.y = y + other.y;
		return ret;
	}

	Vector operator*(const Vector& other)
	{
		Vector ret;
		ret.x = x * other.x;
		ret.y = y * other.y;
		return ret;
	}

	Vector operator-(const Vector& other)
	{
		Vector ret;
		ret.x = x - other.x;
		ret.y = y - other.y;
		return ret;
	}

	Vector operator/(const Vector& other)
	{
		Vector ret;
		ret.x = x / other.x;
		ret.y = y / other.y;
		return ret;
	}
	
	Vector operator+(const float rhs)
	{
		Vector ret;
		ret.x = x + rhs;
		ret.y = y + rhs;
		return ret;
	}
	
	Vector operator-(const float rhs)
	{
		Vector ret;
		ret.x = x - rhs;
		ret.y = y - rhs;
		return ret;
	}
	
	Vector operator*(const float rhs)
	{
		Vector ret;
		ret.x = x * rhs;
		ret.y = y * rhs;
		return ret;
	}
	
	Vector operator/(const float rhs)
	{
		Vector ret;
		ret.x = x / rhs;
		ret.y = y / rhs;
		return ret;
	}

	void operator+=(const Vector& other)
	{
		x += other.x;
		y += other.y;
	}

	void operator-=(const Vector& other)
	{
		x -= other.x;
		y -= other.y;
	}

	void operator*=(const Vector& other)
	{
		x *= other.x;
		y *= other.y;
	}

	void operator/=(const Vector& other)
	{
		x /= other.x;
		y /= other.y;
	}

	void operator+=(float rhs)
	{
		x += rhs;
		y += rhs;
	}

	void operator-=(const float rhs)
	{
		x -= rhs;
		y -= rhs;
	}

	void operator*=(float rhs)
	{
		x *= rhs;
		y *= rhs;
	}

	void operator/=(const float rhs)
	{
		x /= rhs;
		y /= rhs;
	}

#pragma endregion

	/// <summary>
	/// Unity : sqrMagnitude
	/// </summary>
	/// <returns></returns>
	float LengthSquared() const
	{
		return x * x + y * y;
	}

	/// <summary>
	/// Unity : Magnitude
	/// </summary>
	/// <returns></returns>
	float Length() const
	{
		return ::sqrt(LengthSquared());
	}

	void Normalize()
	{
		float length = Length();

		if (length < 0.000000001f)
			return;

		x /= length;
		y /= length;
	}

	Vector normalized() const
	{
		Vector result{ x, y };
		float length = result.Length();
		if (length < 0.000000001f)
			return Vector::zero;

		result.x /= length;
		result.y /= length;
		return result;
	}

	float Dot(Vector other)
	{
		return x * other.x + y * other.y;
	}


	static Vector zero;
	static Vector one;
	float x = 0;
	float y = 0;
};

inline Vector Vector::zero = Vector(0, 0);
inline Vector Vector::one = Vector(1, 1);

using Pos = Vector;
