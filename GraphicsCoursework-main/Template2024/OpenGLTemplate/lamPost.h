#pragma once

#include "Common.h"
#include "VertexBufferObject.h"
#include "Texture.h"

class lamPost
{

public:
	//lamPost();
	//~lamPost();
	void Create(string filename);
	void Render();
	void Release();
private:
	UINT m_vao;
	//CVertexBufferObject m_vbo;
	CTexture m_texture;
	string m_directory;
	string m_filename;
	int m_numTriangles;
	std::vector<glm::vec3> trianglePoints;
	unsigned int m_vertexCount;

};

