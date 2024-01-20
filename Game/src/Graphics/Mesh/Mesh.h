#pragma once

#include "Graphics/Triangle/Triangle.h"

struct Mesh
{
	std::vector<Triangle> triangles;

	static Mesh Cube();
};

