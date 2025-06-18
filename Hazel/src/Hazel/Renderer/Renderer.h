#pragma once

#include "GLFW/glfw3.h"

namespace Hazel
{
	class Renderer
	{
	public:
		Renderer();
		~Renderer();
		
		GLuint CreateVertexBuffer(const GLfloat* verticies, GLsizeiptr size);
		GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);
		
		void DrawSimpleTriangle(GLuint VertexBuffer, GLuint ProgramID);
		
	};
}