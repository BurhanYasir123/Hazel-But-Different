#include <Hazel.h>

class ExampleLayer : public Hazel::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		HZ_INFO("ExampleLayer::Update");

	}

	void OnEvent(Hazel::Event& event) override
	{
		HZ_TRACE("{0}", event);
	}

};

class Sandbox : public Hazel::Application
{
public:
	Sandbox()
	{
		PushLayer(new Hazel::OpenGLLayer());
		PushLayer(new ExampleLayer());
		PushOverlay(new Hazel::ImGuiLayer());
		HZ_CORE_INFO("Sandbox Application Created");
	}

	~Sandbox()
	{

	}

};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}