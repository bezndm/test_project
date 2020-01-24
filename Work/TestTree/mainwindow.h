#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>


#include "Storage_Level/connect_database.h"
#include "GUI_level/operator_tree.h"

QT_BEGIN_NAMESPACE
class QGridLayout;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    OperatorTree    *ptrOperatorTree;
    ConnectDatabase *ptrConnectDatabase;

};
#endif // MAINWINDOW_H

