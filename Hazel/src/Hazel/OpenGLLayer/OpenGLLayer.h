#pragma once

#include "Hazel/Layer.h"
#include "GLFW/glfw3.h"

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

    private:
        GLFWwindow* m_window = nullptr;
    };
}