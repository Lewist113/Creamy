#pragma once
 
#ifdef CR_PLATFORM_WINDOWS


extern CreamEngine::Application* CreamEngine::CreateApplication();

int main(int argc, char** argv)
{
	CreamEngine::Log::Init();
	CR_CORE_FATAL("Stop what you're doing and listen!");
	CR_CORE_INFO("YOOOOOOOOO");

	auto app = CreamEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif