#include "hzpch.h"
#include "GLFW/glfw3.h"

#include "Hazel/OpenGLLayer/OpenGLLayer.h"
#include <glad/glad.h>

namespace Hazel
{
    OpenGLLayer::OpenGLLayer()
    {
    }

    OpenGLLayer::~OpenGLLayer()
    {
    }

    void OpenGLLayer::OnAttach()
    {
        
    }
    void OpenGLLayer::OnUpdate()
    {
        glClearColor(1, 0, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void OpenGLLayer::OnDetach()
    {
        
    }
}