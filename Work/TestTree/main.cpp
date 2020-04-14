#include "mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;

    window.setMinimumWidth(500);
    window.setMaximumSize(1920,1080);
    window.resize(600,700);
    // 1 commit
    // 2 commit
    window.show();

    return app.exec();
}
