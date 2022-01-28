#include <Cream.h>

class ExampleLayer : public CreamEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		
		if (CreamEngine::Input::IsKeyPressed(CR_KEY_TAB))
			CR_TRACE("Tab key is pressed"); 
	}

	void OnEvent(CreamEngine::Event& event) override
	{
		if (event.GetEventType() == CreamEngine::EventType::KeyPressed)
		{
			CreamEngine::KeyPressedEvent& e = (CreamEngine::KeyPressedEvent&)event; 
			CR_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};



class Sandbox : public CreamEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new CreamEngine::ImGuiLayer());
	}

	~Sandbox()
	{

	}	

};

CreamEngine::Application* CreamEngine::CreateApplication()
{ 
	return new Sandbox();
}