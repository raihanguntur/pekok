#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cstdio>
#include <cstring>
#include <d3d11.h>
#include <d3d11.h>
#include <dxgi.h>
#include <cmath>
#include <DirectXMath.h>
#define xstr(a) rstr(a)
#define rstr(a) #a
#define AAVERSION 6
#define AABUILDVER 1107
#ifdef AADEBUG
#define AABUILDMODE Debug
#elif AARELEASE
#define AABUILDMODE Release
#endif
//#define AASTEALER
//#define AAPUBLICMODE
#pragma warning(disable : 4099)
struct Vector3
{
public:
    float x, y, z;
    Vector3()
    {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }
    Vector3(float v)
    {
        this->x = v;
        this->y = v;
        this->z = v;
    }
    Vector3(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    Vector3(const Vector3& rhs)
    {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
    }
    //Vector3(const Vector2& rhs)
    //{
    //    this->x = rhs.x;
    //    this->y = rhs.y;
    //    this->z = 0;
    //}
    //Vector2 ToVector2()
    //{
    //    return Vector2{ x, y };
    //}
};
struct Vector2
{
public:
    float x, y;
    Vector2()
    {
        this->x = 0;
        this->y = 0;
    }
    Vector2(float v)
    {
        this->x = v;
        this->y = v;
    }
    Vector2(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    Vector2(const Vector2& rhs)
    {
        this->x = rhs.x;
        this->y = rhs.y;
    }
    Vector2(const Vector3& rhs)
    {
        this->x = rhs.x;
        this->y = rhs.y;
    }
    float Distance(const Vector2& rhs)
    {
        Vector2 difference = Vector2{ this->x - rhs.x, this->y - rhs.y };
        return sqrt((difference.x * difference.x) + (difference.y * difference.y));
    }
    float Magnitude()
    {
        return sqrt(this->x * this->x + this->y * this->y);
    }
    float Dot(const Vector2& rhs)
    {
        return this->x * rhs.x + this->y * rhs.y;
    }
    float Cross(const Vector2& rhs)
    {
        return this->x * rhs.y + this->y * rhs.x;
    }
    Vector2 normalize()
    {
        float mag = sqrt(this->x * this->x + this->y * this->y);
        return Vector2{ this->x / mag, this->y / mag };
    }
    Vector2 operator+(const Vector2& rhs)
    {
        return { this->x + rhs.x, this->y + rhs.y };
    }
    Vector2 operator+=(const Vector2& rhs)
    {
        return { this->x += rhs.x, this->y += rhs.y };
    }

    Vector2 operator-(const Vector2& rhs)
    {
        return { this->x - rhs.x, this->y - rhs.y };
    }
    Vector2 operator-=(const Vector2& rhs)
    {
        return { this->x -= rhs.x, this->y -= rhs.y };
    }

    Vector2 operator*(const Vector2& rhs)
    {
        return { this->x * rhs.x, this->y * rhs.y };
    }
    Vector2 operator*=(const Vector2& rhs)
    {
        return { this->x *= rhs.x, this->y *= rhs.y };
    }

    Vector2 operator/(const Vector2& rhs)
    {
        return { this->x / rhs.x, this->y / rhs.y };
    }
    Vector2 operator/=(const Vector2& rhs)
    {
        return { this->x /= rhs.x, this->y /= rhs.y };
    }

    Vector2 operator+(const float& rhs)
    {
        return { this->x + rhs, this->y + rhs };
    }
    Vector2 friend operator+(const float& lhs, const Vector2& rhs)
    {
        return { rhs.x + lhs, rhs.y + lhs };
    }
    Vector2 operator+=(const float& rhs)
    {
        return { this->x += rhs, this->y += rhs };
    }

    Vector2 operator-(const float& rhs)
    {
        return { this->x - rhs, this->y - rhs };
    }
    Vector2 friend operator-(const float& lhs, const Vector2& rhs)
    {
        return { rhs.x - lhs, rhs.y - lhs };
    }
    Vector2 operator-=(const float& rhs)
    {
        return { this->x -= rhs, this->y -= rhs };
    }

    Vector2 operator*(const float& rhs)
    {
        return { this->x * rhs, this->y * rhs };
    }
    Vector2 friend operator*(const float& lhs, const Vector2& rhs)
    {
        return { rhs.x * lhs, rhs.y * lhs };
    }
    Vector2 operator*=(const float& rhs)
    {
        return { this->x *= rhs, this->y *= rhs };
    }

    Vector2 operator/(const float& rhs)
    {
        return { this->x / rhs, this->y / rhs };
    }
    Vector2 friend operator/(const float& lhs, const Vector2& rhs)
    {
        return { rhs.x / lhs, rhs.y / lhs };
    }
    Vector2 operator/=(const float& rhs)
    {
        return { this->x /= rhs, this->y /= rhs };
    }

    bool operator==(const Vector2& rhs)
    {
        return this->x == rhs.x && this->y == rhs.y;
    }
    bool operator!=(const Vector2& rhs)
    {
        return this->x != rhs.x || this->y != rhs.y;
    }

    bool operator>(const Vector2& rhs)
    {
        return this->x > rhs.x && this->y > rhs.y;
    }
    bool operator<(const Vector2& rhs)
    {
        return this->x < rhs.x&& this->y < rhs.y;
    }

    bool operator>=(const Vector2& rhs)
    {
        return this->x >= rhs.x && this->y >= rhs.y;
    }
    bool operator<=(const Vector2& rhs)
    {
        return this->x <= rhs.x && this->y <= rhs.y;
    }
};
struct Vector2i
{
	int x, y;
	inline float Distance(Vector2i other)
	{
		Vector2i difference = Vector2i{ this->x - other.x, this->y - other.y };
		return sqrt((difference.x * difference.x) + (difference.y * difference.y));
	}
	bool operator==(const Vector2i& other) const
	{
		return (this->x == other.x) && (this->y == other.y);
	}
	inline bool operator!=(const Vector2i& other)
	{
		return (this->x != other.x) || (this->y != other.y);
	}
	inline bool operator<(const Vector2i& other)
	{
		return (this->x < other.x) && (this->y < other.y);
	}
	inline bool operator>(const Vector2i& other)
	{
		return (this->x > other.x) && (this->y > other.y);
	}
	inline bool operator<=(const Vector2i& other)
	{
		return (this->x <= other.x) && (this->y <= other.y);
	}
	inline bool operator>=(const Vector2i& other)
	{
		return (this->x >= other.x) && (this->y >= other.y);
	}
};
struct Vector4
{
	float x, y, z, w;
};