#include "hzpch.h"
#include "ImGuiLayer.h"
#include "Hazel/Layer.h"
#include "Hazel/Application.h"
#include "Hazel/Core.h"
#include "imgui.h"
#include "GLFW/glfw3.h"
#include "Platform/OpenGL/imgui_impl_opengl3.h"
#include "Platform/OpenGL/imgui_impl_glfw.h"

#include "Hazel/Events/KeyEvent.h"
#include "Hazel/Events/MouseEvent.h"
#include "Hazel/Events/ApplicationEvent.h"

namespace Hazel
{
    ImGuiLayer::ImGuiLayer()
        : Layer("imGuiLayer")
    {
    }

    ImGuiLayer::~ImGuiLayer()
    {
    }
    
    void ImGuiLayer::OnAttach()
    {
        ImGui::CreateContext();
        ImGui::StyleColorsDark();

        ImGuiIO& io = ImGui::GetIO();

        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        //io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        // io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

        GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetWindowObject());

        ImGui_ImplOpenGL3_Init("#version 330");
        ImGui_ImplGlfw_InitForOpenGL(window, true);

    }

    void ImGuiLayer::OnDetach()
    {
        // Cleanup ImGui layer
    }

    void ImGuiLayer::OnUpdate()
    {
		HZ_PROFILE();
        ImGuiIO& io = ImGui::GetIO();
        Application& app = Application::Get();
        io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

        float time = (float)glfwGetTime();
        io.DeltaTime = m_Time > 0.0 ? (time - m_Time) : (1.0f / 60.0f);
        m_Time = time; 

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        static bool show = true;
        
        //ImGui::ShowDemoWindow(&show);

        if(ImGui::Begin("Main"))
        {
            ImGui::Text("%.3f FPS, %.1fms",(1000/(io.DeltaTime*1000)), io.DeltaTime*1000);
			
			ImGui::Button("Hi");
        }
        ImGui::End();


        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
    
    void ImGuiLayer::OnEvent(Event& event)
    {
        
    }
    
}