#include <GES.h>

#include <sstream>

#include <GES/Events/ApplicationEvent.h>
#include <GES/Events/KeyEvent.h>
#include <GES/Events/MouseEvent.h>

class ExampleLayer : public GES::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (GES::Input::IsKeyPressed(GES_KEY_TAB))
			GES_TRACE("Tab key is pressed (poll)!");
	}

	void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello, World!");
		ImGui::End();
	}

	void OnEvent(GES::Event& event) override
	{
		if (event.GetEventType() == GES::EventType::KeyPressed)
		{
			GES::KeyPressedEvent& e = (GES::KeyPressedEvent&)event;
			if (e.GetKeyCode() == GES_KEY_TAB)
				GES_TRACE("Tab key is pressed (event)!");
			GES_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public GES::Application
{
public:
	Sandbox()
	{
		ImGui::SetCurrentContext(GetImGuiContext());
		PushLayer(new ExampleLayer());
	}
};

GES::Application *GES::CreateApplication()
{
	return new Sandbox();
}
