#pragma once

#include "Graphics/Mesh/Mesh.h"
#include "Math/Matrix/Matrix.h"

struct Box 
{
	float x, y, w, h;
};

class Scene
{
	Box m_viewport;
	Mesh m_mesh;
	Matrix m_projection;

	std::vector<Triangle> m_triangles;

public:
	Scene();
	~Scene();

	void Init(Box viewport);
	void Update(float deltaTime);
	void Render();
#ifdef _DEBUG
	void DrawBorder() const;
#endif // _DEBUG
};

