#include"Application.h"

Application::Application():Core()
{
    this->run();
}
int Application::execute()
{
    while(Running)
    {
     run();
     SDL_Delay(3000);
    }


}
void Application::loadPreviousConf(){}
void Application::setUp(){}
Application::~Application(){}


