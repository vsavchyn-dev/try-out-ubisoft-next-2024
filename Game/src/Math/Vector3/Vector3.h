#pragma once

struct Vector3
{
	float x, y, z, w = 1.0f;

	Vector3();

	Vector3(float x, float y, float z);

	//Vector3& operator=(const Vector3& other);
	
	Vector3  operator+(const Vector3 &other) const;

	Vector3& operator+=(const Vector3& other);

	Vector3  operator-(const Vector3& other) const;

	Vector3& operator-=(const Vector3& other);

	Vector3  operator*(float scalar) const;

	Vector3& operator*=(float scalar);

	Vector3  operator/(float scalar) const;

	Vector3& operator/=(float scalar);

	bool operator==(const Vector3& other) const;

	bool operator!=(const Vector3& other) const;

	float Length() const;

	float LengthSquared() const;

	Vector3 Normalize() const;

	float Dot(const Vector3& other) const;

	Vector3 Cross(const Vector3& other) const;

	std::string ToString() const;
};

