#include "lamPost.h"

void lamPost::Create(string filename)
{

	m_texture.Load(filename);
	m_texture.SetSamplerObjectParameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	m_texture.SetSamplerObjectParameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	m_texture.SetSamplerObjectParameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
	m_texture.SetSamplerObjectParameter(GL_TEXTURE_WRAP_T, GL_REPEAT);

	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);
	// Create a VBO
	CVertexBufferObject vbo;
	vbo.Create();
	vbo.Bind();
	glm::vec2 t0 = glm::vec2(0, 0);
	glm::vec2 t1 = glm::vec2(1, 0);
	glm::vec2 t2 = glm::vec2(1, 1);
	glm::vec2 t3 = glm::vec2(0, 1);
	glm::vec3 normal(0.0f, 3.0f, 0.0f);

	trianglePoints.push_back(glm::vec3(0, 1, 0));
	trianglePoints.push_back(glm::vec3(60, 1, 0));
	trianglePoints.push_back(glm::vec3(0, 6, 0));
	trianglePoints.push_back(glm::vec3(60, 6, 0));
	trianglePoints.push_back(glm::vec3(0, 6, -5));
	trianglePoints.push_back(glm::vec3(60, 6, -5));

	trianglePoints.push_back(glm::vec3(0, 1, -5));
	trianglePoints.push_back(glm::vec3(60, 1, -5));

	trianglePoints.push_back(glm::vec3(0, 1, 0));
	trianglePoints.push_back(glm::vec3(60, 1, 0));

	vbo.AddData(&trianglePoints[0], sizeof(glm::vec3)); //could have used a loop this was just easier to visualise while coding.
	vbo.AddData(&t0, sizeof(glm::vec2));
	vbo.AddData(&normal, sizeof(glm::vec3));

	vbo.AddData(&trianglePoints[1], sizeof(glm::vec3));
	vbo.AddData(&t1, sizeof(glm::vec2));
	vbo.AddData(&normal, sizeof(glm::vec3));

	vbo.AddData(&trianglePoints[2], sizeof(glm::vec3));
	vbo.AddData(&t2, sizeof(glm::vec2));
	vbo.AddData(&normal, sizeof(glm::vec3));

	vbo.AddData(&trianglePoints[3], sizeof(glm::vec3));
	vbo.AddData(&t3, sizeof(glm::vec2));
	vbo.AddData(&normal, sizeof(glm::vec3));
	
	vbo.AddData(&trianglePoints[4], sizeof(glm::vec3));
	vbo.AddData(&t0, sizeof(glm::vec2));
	vbo.AddData(&normal, sizeof(glm::vec3));
	
	vbo.AddData(&trianglePoints[5], sizeof(glm::vec3));
	vbo.AddData(&t1, sizeof(glm::vec2));
	vbo.AddData(&normal, sizeof(glm::vec3));

	vbo.AddData(&trianglePoints[6], sizeof(glm::vec3));
	vbo.AddData(&t2, sizeof(glm::vec2));
	vbo.AddData(&normal, sizeof(glm::vec3));

	vbo.AddData(&trianglePoints[7], sizeof(glm::vec3));
	vbo.AddData(&t3, sizeof(glm::vec2));
	vbo.AddData(&normal, sizeof(glm::vec3));

	vbo.AddData(&trianglePoints[8], sizeof(glm::vec3));
	vbo.AddData(&t0, sizeof(glm::vec2));
	vbo.AddData(&normal, sizeof(glm::vec3));

	vbo.AddData(&trianglePoints[9], sizeof(glm::vec3));
	vbo.AddData(&t1, sizeof(glm::vec2));
	vbo.AddData(&normal, sizeof(glm::vec3));


	m_vertexCount = trianglePoints.size();

	// Upload the VBO to the GPU
	vbo.UploadDataToGPU(GL_STATIC_DRAW);
	// Set the vertex attribute locations
	GLsizei stride = 2 * sizeof(glm::vec3) + sizeof(glm::vec2);
	// Vertex positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, 0);
	// Texture coordinates
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, stride, (void*)sizeof(glm::vec3));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(glm::vec3)
		+ sizeof(glm::vec2)));

	glBindVertexArray(0);
}



void lamPost::Render() {
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	// Bind the VAO
	glBindVertexArray(m_vao);
	m_texture.Bind();

	// Set line width if supported
	glLineWidth(2.0f); // Adjust as needed

	glDrawArrays(GL_TRIANGLE_STRIP, 0, m_vertexCount);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	m_texture.Release();
	// Unbind the VAO
	glBindVertexArray(0);

}