
#include <Cream.h>

class Sandbox : public CreamEngine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

CreamEngine::Application* CreamEngine::CreateApplication()
{ 
	return new Sandbox();
}