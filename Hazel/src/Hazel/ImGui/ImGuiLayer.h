#pragma once

#include "Hazel/Layer.h"

#include "Hazel/Events/KeyEvent.h"
#include "Hazel/Events/MouseEvent.h"
#include "Hazel/Events/ApplicationEvent.h"

namespace Hazel
{
    class HAZEL_API ImGuiLayer : public Layer
    {
    public:
        
        ImGuiLayer();
        ~ImGuiLayer();

        void OnAttach();
        void OnDetach();
        void OnUpdate();
        void OnEvent(Event& event);
       

    private:
        float m_Time = 0.0f;
    };
}