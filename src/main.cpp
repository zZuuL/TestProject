#include <QApplication>
#include <QFontDatabase>
#include <QResource>
#include <QDebug>

#include <QThread>

#include "console.h"
#include "testproject.h"

#define INVALID_FONT_ID -1

inline void init()
{
    QFont font(":/fonts/Terminus.ttf");
    font.setPointSize(12);
    QApplication::setFont(font);
    Console::init();
}

int main(int argc, char** argv/*, char** envp*/)
{
    QApplication app(argc, argv);
    init();

    TestProject testproject;
    
    /*
    * do something!
    */

    return app.exec();
}
