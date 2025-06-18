#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Hazel/Layer.h"
#include "Hazel/Renderer/Renderer.h"

namespace Hazel
{
	class HAZEL_API OpenGLLayer : public Layer
	{
	public:
		OpenGLLayer();
        ~OpenGLLayer();

        void OnAttach();
        void OnDetach();
        void OnUpdate();
        void OnEvent(Event& event);
		
		Renderer HazelRenderer;
		GLuint vertexbuffer;
		GLuint ProgramID;
	};
}