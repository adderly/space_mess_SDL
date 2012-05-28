#include "Core.h"

Core::Core()
{
    this->eventTrigger =  new EventTriggerer();
    this->render = new Graphics::Render();
}
int Core::run()
{
    eventTrigger->check(this->event);
    render->draw();
}
Core::~Core(){}

