#include<QMenu>
#include<QDebug>
#include<QtGui>
#include<QtOpenGL/QGLWidget>
#include<QtOpenGL/QtOpenGL>
#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>
#include<QSplitter>



class Editor: public QGLWidget
{
    Q_OBJECT
    SDL_Surface* screen;
    SDL_Event event;
    Mix_Music* music;


    public:
    Editor(QWidget *parent=0);
    void init();
    void setUp();
    void reshape(int x,int y);
    void clear();
    void draw();
    void paintGL();
    void checkEvents();
    void save();
    void createNew();
    ~Editor();
};


