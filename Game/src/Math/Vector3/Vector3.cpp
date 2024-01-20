#include "stdafx.h"

#include "Vector3.h"

Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f), w(1.0f)
{
}


Vector3::Vector3(float newX, float newY, float newZ) : x(newX), y(newY), z(newZ), w(1.0f) 
{
}

//Vector3& Vector3::operator=(const Vector3& other)
//{
//	this->x = other.x;
//	this->y = other.y;
//	this->z = other.z;
//	
//	return *this;
//}

Vector3 Vector3::operator+(const Vector3& other) const
{
	return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
}

Vector3& Vector3::operator+=(const Vector3& other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;

	return *this;
}

Vector3 Vector3::operator-(const Vector3& other) const
{
	return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
}

Vector3& Vector3::operator-=(const Vector3& other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;

	return *this;
}

Vector3 Vector3::operator*(float scalar) const
{
	return Vector3(this->x * scalar, this->y * scalar, this->z * scalar);
}

Vector3& Vector3::operator*=(float scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;

	return *this;
}

Vector3 Vector3::operator/(float scalar) const
{
	return Vector3(this->x / scalar, this->y / scalar, this->z / scalar);
}

Vector3& Vector3::operator/=(float scalar)
{
	this->x /= scalar;
	this->y /= scalar;
	this->z /= scalar;

	return *this;
}

bool Vector3::operator==(const Vector3& other) const
{
	return this->x == other.x && this->y == other.y && this->z == other.z;
}

bool Vector3::operator!=(const Vector3& other) const
{
	return this->x != other.x || this->y != other.y || this->z != other.z;
}

float Vector3::Length() const
{
	return sqrtf(x * x + y * y + z * z);
}

float Vector3::LengthSquared() const
{
	return x * x + y * y + z * z;
}

Vector3 Vector3::Normalize() const
{
	assert(this->LengthSquared() > 0);
	return *this / this->Length();
}

float Vector3::Dot(const Vector3& other) const
{
	return this->x * other.x + this->y * other.y + this->z * other.z;
}

Vector3 Vector3::Cross(const Vector3& other) const 
{
	return Vector3(
		this->y * other.z - other.y * this->z, 
		this->z * other.x - other.z * this->x, 
		this->x * other.y - other.x * this->y
	);
}

std::string Vector3::ToString() const 
{
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
}