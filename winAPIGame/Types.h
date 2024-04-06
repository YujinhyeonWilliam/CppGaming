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

#pragma region Vector-related 

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

	float Cross(Vector other)
	{
		return x * other.y - y * other.x;
	}

	static Vector zero;
	static Vector one;
	float x = 0;
	float y = 0;
};

struct VectorInt
{
	VectorInt() {}
	VectorInt(int32 x, int32 y) : x(x), y(y) {}
	VectorInt(POINT pt) : x(static_cast<int32>(pt.x)), y(static_cast<int32>(pt.y)) {}

#pragma region Operators 

	VectorInt operator+(const VectorInt& other)
	{
		VectorInt ret;
		ret.x = x + other.x;
		ret.y = y + other.y;
		return ret;
	}

	VectorInt operator*(const VectorInt& other)
	{
		VectorInt ret;
		ret.x = x * other.x;
		ret.y = y * other.y;
		return ret;
	}

	VectorInt operator-(const VectorInt& other)
	{
		VectorInt ret;
		ret.x = x - other.x;
		ret.y = y - other.y;
		return ret;
	}

	VectorInt operator/(const VectorInt& other)
	{
		VectorInt ret;
		ret.x = x / other.x;
		ret.y = y / other.y;
		return ret;
	}

	VectorInt operator+(const int32 rhs)
	{
		VectorInt ret;
		ret.x = x + rhs;
		ret.y = y + rhs;
		return ret;
	}

	VectorInt operator-(const int32 rhs)
	{
		VectorInt ret;
		ret.x = x - rhs;
		ret.y = y - rhs;
		return ret;
	}

	VectorInt operator*(const int32 rhs)
	{
		VectorInt ret;
		ret.x = x * rhs;
		ret.y = y * rhs;
		return ret;
	}

	VectorInt operator/(const int32 rhs)
	{
		VectorInt ret;
		ret.x = x / rhs;
		ret.y = y / rhs;
		return ret;
	}

	void operator+=(const VectorInt& other)
	{
		x += other.x;
		y += other.y;
	}

	void operator-=(const VectorInt& other)
	{
		x -= other.x;
		y -= other.y;
	}

	void operator*=(const VectorInt& other)
	{
		x *= other.x;
		y *= other.y;
	}

	void operator/=(const VectorInt& other)
	{
		x /= other.x;
		y /= other.y;
	}

	void operator+=(const int32 rhs)
	{
		x += rhs;
		y += rhs;
	}

	void operator-=(const int32 rhs)
	{
		x -= rhs;
		y -= rhs;
	}

	void operator*=(const int32 rhs)
	{
		x *= rhs;
		y *= rhs;
	}

	void operator/=(const int32 rhs)
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

	float Dot(VectorInt other)
	{
		return x * other.x + y * other.y;
	}

	float Cross(VectorInt other)
	{
		return x * other.y - y * other.x;
	}

	static VectorInt zero;
	static VectorInt one;
	int32 x = 0;
	int32 y = 0;
};


#pragma region Inline variables

inline Vector Vector::zero = Vector(0.f, 0.f);
inline Vector Vector::one = Vector(1.f, 1.f);
inline VectorInt VectorInt::zero = VectorInt(0, 0);
inline VectorInt VectorInt::one = VectorInt(1, 1);

#pragma endregion

using Pos = Vector;
using Vector2D = Vector;
using Vector2DInt = VectorInt;

#pragma endregion
