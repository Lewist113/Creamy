#pragma once
 
#ifdef CR_PLATFORM_WINDOWS


extern CreamEngine::Application* CreamEngine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = CreamEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif