#pragma once
 
#ifdef CR_PLATFORM_WINDOWS


extern CreamEngine::Application* CreamEngine::CreateApplication();

int main(int argc, char** argv)
{
	CreamEngine::Log::Init();

	auto app = CreamEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif