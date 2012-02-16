#include<QtGui>
#include<QWidget>
#include<QApplication>
#include<QFont>
#include<QtCore>
#include<QPushButton>
//#include"../../utils/SDLIncludeheader.h"
#include"Editor.h"

#ifndef MAIN
#define MAIN

int main(int argc,char** argv)
{
    QApplication app(argc,argv);
    QWidget window;
    Editor *e = new Editor;
    QPushButton *btn = new QPushButton("CLICK ME");
    btn->setFont(QFont("Arial",25,QFont::Bold));

    QGridLayout *layout =  new QGridLayout;
    layout->addWidget(e,0,0);
    layout->addWidget(btn,0,1,1,2);
    window.setLayout(layout);

    window.show();
    return app.exec();
}


#endif

