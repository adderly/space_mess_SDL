#include"Application.h"

Application::Application()
{
   core = new Core();
   core->prepare();

}
void Application::draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
        glBegin(GL_QUADS);

        glVertex2f(10,10);
        glVertex2f(100,10);
        glVertex2f(100,100);
        glVertex2f(10,100);
        glEnd();


        //generator->evolveParticles();
        // if(menu->visible)drawMainMenu();

      //  SDL_GL_SwapBuffers();
}
int Application::execute()
{
    while(Running)
    {

        printf("%s",SDL_GetError());

       while(SDL_PollEvent(&event))
        {
             //   if(event.type == SDL_QUIT) Running = false;
               // if(event.type == SDL_MOUSEBUTTONDOWN) glClearColor(1,0,0,0);
                check(event);
        }
        glColor3f(1.0,0.0,0.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_QUADS);
        glVertex2f(10,10);
        glVertex2f(100,10);
        glVertex2f(100,100);
        glVertex2f(10,100);
        glEnd();
        core->draw();
        SDL_GL_SwapBuffers();
   //  SDL_Delay(3000);
    }

    cleanUp();

}

void Application::loadPreviousConf()
{

}
void Application::setUp()
{

}
void Application::cleanUp()
{
    SDL_Quit();
}

/*Events*/
void Application::check()
{
    for(core->d_tator = core->drawables.begin(); core->d_tator != core->drawables.end();core->d_tator++)
    {
        if((**core->d_tator).clickable)
        {
            if((**core->d_tator).isOver(getMouseX(),getMouseY()))
            {
                (**core->d_tator).setIsDefaultColor(false);
                (**core->d_tator).color[0] = 0;
                (**core->d_tator).color[1] = 0;
            }
        }

    }
}
void Application::check(SDL_Event& e)
{

           switch(e.type)
            {
                case SDL_QUIT:
                    Running = false;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    checkMouseDown(e);
                    break;
                case SDL_MOUSEBUTTONUP:
                        checkMouseUp(e);
                    break;
                case SDL_KEYDOWN:
                    break;
                case SDL_KEYUP:
                    break;
                default:
                    break;
            }
        check();



}
void Application::checkMouseDown(SDL_Event& e)
   {
       setMousePosition(e.button.x,e.button.y);
       switch(e.button.button)
       {
           case SDL_BUTTON_LEFT:
                MOUSE_LCLICK = true;
                break;
           case SDL_BUTTON_RIGHT:
                MOUSE_RCLICK = true;
                break;
            case SDL_BUTTON_MIDDLE:
                MOUSE_MCLICK = true;
                break;
       }
   }
void Application::checkMouseUp(SDL_Event& e)
   {
    setMousePosition(e.button.x,e.button.y);

       switch(e.button.button)
       {
           case SDL_BUTTON_LEFT:
                MOUSE_LCLICK = false;
                break;
           case SDL_BUTTON_RIGHT:
                MOUSE_RCLICK = false;
                break;
            case SDL_BUTTON_MIDDLE:
                MOUSE_MCLICK = false;
                break;
       }
   }
void Application::checkKeyDown(SDL_Event& e)
{
    switch(e.key.keysym.sym)
    {
        case SDLK_ESCAPE:
            Running = false;
            break;
        default:
        break;

    }
}
void Application::checkKeyUp(SDL_Event& e){}
void Application::trigger(){}
Application::~Application(){}


