#include "stdafx.h"
#include "Scene.h"

Scene::Scene() : m_viewport({0.0f, 0.0f, 0.0f, 0.0f})
{
	// TODO: Arrays + id's for them. Don't forget memory allocation for the scene in future.
}

Scene::~Scene()
{
	// TODO: Clean-up possible dynamically allocated things
}

void Scene::Init(Box viewport)
{
	m_viewport = viewport;

	float fov = 90.0f;
	float distancePlane = 1.0f / tanf(fov * 0.5f /  PI * 180.0f);
	float aspectRatio   = viewport.w / viewport.h;
	float zNear = 0.1f;
	float zFar  = 100.0f;
	
	m_projection = Matrix::Projection(distancePlane, aspectRatio, zNear, zFar);

	m_mesh = Mesh::Cube();
}

void Scene::Update(float deltaTime)
{
	static float elapsed = 0.0f;
	elapsed += deltaTime / 1000.0f;

	Matrix scaling = Matrix::Scale(Vector3(1.0f, 1.0f, 1.0f));
	Matrix rotation = Matrix::RotateX(elapsed) * Matrix::RotateY(elapsed);
	Matrix translation = Matrix::Translate(Vector3(0.0f, 0.0f, 0.0f));

	Matrix world = Matrix::Identity() * scaling * translation;

	Vector3 position = { 0.0f, 0.0f, 0.0f };
	Vector3 up	     = { 0.0f, 1.0f, 0.0f };
	Vector3 target   = { 0.0f, 0.0f, 1.0f };

	Matrix camera = Matrix::LookAt(position, target, up);
	Matrix view   = Matrix::QuickInverse(camera);

	std::vector<Triangle> raster;

	for (auto& triangle : m_mesh.triangles)
	{
		Triangle transformed;

		for (int i = 0; i < 3; i++)
			transformed.point[i] = world * triangle.point[i];

		Vector3 a = transformed.point[1] - transformed.point[0];
		Vector3 b = transformed.point[2] - transformed.point[0];
		Vector3 normal = a.Cross(b).Normalize();

		if (normal.Dot((transformed.point[0] - position).Normalize()) < 0.0f) {
			Triangle viewed, projected;

			for (int i = 0; i < 3; i++)
				viewed.point[i] = view * transformed.point[i];

			Vector3 offset = { 1.0f, 1.0f, 0.0f };

			for (int i = 0; i < 3; i++) {
				projected.point[i] = m_projection * viewed.point[i];
				float w = projected.point[i].w;
				assert(w != 0.0f);
				projected.point[i] = (projected.point[i] / w) + offset;
				projected.point[i].x *= m_viewport.w * 0.5f;
				projected.point[i].y *= m_viewport.h * 0.5f;
			}

			raster.push_back(projected);
		}
	}

	m_triangles = raster;
}

void Scene::Render()
{
#ifdef _DEBUG
	DrawBorder();
#endif // _DEBUG


	for (auto& triangle : m_triangles)
		triangle.Render();

	float x = m_viewport.w * 0.01f;
	float y = m_viewport.h * 0.95f;

	App::Print(x, y, "Scene::Render()");
}

void Scene::DrawBorder() const
{
	float r = 1.0f;
	float g = 0.5f;
	float b = 0.0f;

	float x = m_viewport.x + 1.0f;
	float y = m_viewport.y;
	float w = m_viewport.w;
	float h = m_viewport.h - 1.0f;

	App::DrawLine(x, y, x, h, r, g, b);
	App::DrawLine(x, h, w, h, r, g, b);
	App::DrawLine(w, h, w, y, r, g, b);
	App::DrawLine(w, y, x, y, r, g, b);
}

