#include"Editor.h"

Editor::Editor(QWidget* parent ):QGLWidget(parent)
{
    QPushButton* btn =  new QPushButton("oh yeah");
    QFrame* frame =  new QFrame;
    QSplitter *spl1 = new QSplitter(Qt::Vertical, this);
    spl1->addWidget(frame);
    spl1->addWidget(btn);


    init();
    setUp();
    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
    music = Mix_LoadMUS("sound.wav");
    Mix_PlayMusic(music,-1);
}
Editor::~Editor()
{
    SDL_Quit();
}
void Editor::createNew()
{

}
void Editor::clear()
{

}
void Editor::init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) <0)
    {

        quick_exit(-1);
    }
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

    //screen = SDL_SetVideoMode(680,400,32,SDL_SWSURFACE|SDL_OPENGL);
}
void Editor::paintGL()
{
    checkEvents();
    draw();
}
void Editor::setUp()
{
      glClearColor(1,1,1,1);
      glMatrixMode(GL_PROJECTION);
      glViewport(0,0,680,400);
      //gluPerspective(45.0,680/460,1.0,500.0);
      glMatrixMode(GL_MODELVIEW);
      glDisable(GL_DEPTH_TEST);
      glLoadIdentity();
      glShadeModel(GL_SMOOTH);
      glOrtho(0,680,400,0,-1,1);
      glEnable(GL_TEXTURE_2D);
      glEnable(GL_ALPHA);
      QPushButton *btn = new QPushButton("");
}
void Editor::reshape(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glViewport(0,0,w,h);
    glLoadIdentity();
    //gluPerspective(45.0,680/460,1.0,500.0);
    glOrtho(0,w,h,0,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}
void Editor::checkEvents()
{
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_KEYUP)
        {
            quick_exit(-1);
        }
    }


}
void Editor::save(){}
void Editor::draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4ub(255,255,0,0);
    glBegin(GL_QUADS);
        glVertex2f(0,0);
        glVertex2f(100,0);
        glVertex2f(100,100);
        glVertex2f(0,100);
    glEnd();
    SDL_GL_SwapBuffers();
}



