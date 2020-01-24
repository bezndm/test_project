#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    this->ptrConnectDatabase = new ConnectDatabase();
    this->ptrOperatorTree = new OperatorTree(this->ptrConnectDatabase);

    auto central = new QWidget;
    QGridLayout *mainLayout = new QGridLayout();

    mainLayout->addWidget(this->ptrOperatorTree,  1, 1, 1, 1);

    central->setLayout(mainLayout);
    setCentralWidget(central);

    setWindowTitle(tr("Test Application"));
}

MainWindow::~MainWindow()
{

}







