#include "hzpch.h"
#include "OpenGLLayer.h"
#include "Hazel/Renderer/Renderer.h"
#include <glad/glad.h>
#include "GLFW/glfw3.h"

namespace Hazel
{
	OpenGLLayer::OpenGLLayer()
        : Layer("OpenGLLayer")
    {
    }

    OpenGLLayer::~OpenGLLayer()
    {
    }
    
    void OpenGLLayer::OnAttach()
    {		
		static const GLfloat g_vertex_buffer_data[] = {
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.0f,  0.5f, 0.0f,
		};
		
		vertexbuffer = HazelRenderer.CreateVertexBuffer(g_vertex_buffer_data, sizeof(g_vertex_buffer_data));
		
		ProgramID = HazelRenderer.LoadShaders(HZ_DEFAULT_SHADERS, HZ_DEFAULT_SHADERS);
    }

    void OpenGLLayer::OnDetach()
    {
        //delete HazelRenderer;
    }

    void OpenGLLayer::OnUpdate()
    {
		glClearColor(0, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		
		HazelRenderer.DrawSimpleTriangle(vertexbuffer, ProgramID);
    }
    
    void OpenGLLayer::OnEvent(Event& event)
    {

    }
}