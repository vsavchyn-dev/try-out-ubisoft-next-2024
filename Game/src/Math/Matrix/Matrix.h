#pragma once

struct Vector3;

struct Matrix
{
	Matrix();

	float& operator()(int row, int col);

	Matrix operator*(const Matrix& other) const;

	Vector3 operator*(const Vector3& v) const;

	static Matrix Identity();
	static Matrix Translate(Vector3& v);
	static Matrix RotateX(float delta);
	static Matrix RotateY(float delta);
	static Matrix RotateZ(float delta);
	static Matrix Rotate(Vector3& v);
	static Matrix Projection(float distancePlane, float aspectRatio, float zNear, float zFar);
	static Matrix LookAt(Vector3& position, Vector3& target, Vector3& up);
	static Matrix Scale(Vector3& v);
	static Matrix QuickInverse(Matrix& m);

	std::string ToString() const;
private:
	float m[16];
};

