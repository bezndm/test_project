#ifndef OPERATOR_TREE_H
#define OPERATOR_TREE_H

#include <QWidget>
#include <QTreeView>
#include <QStandardItemModel>
#include <QItemSelectionModel>

#include "Storage_Level/connect_database.h"
#include "Storage_Level/country_storage.h"
#include "Storage_Level/operator_storage.h"
#include "Storage_Level/manager_storage.h"

#include "GUI_level/operator_editor_update.h"
#include "GUI_level/operator_editor.h"
#include "GUI_level/close_button.h"
#include "GUI_level/buttonhoverwatcher.h"


const int COUNTRY_ROLE_MCC = 1001;
const int COUNTRY_ROLE_CODE = 1002;
const int COUNTRY_ROLE_NAME = 1003;
const int COUNTRY_ROLE_LENGTH = 1004;

const int OPERATOR_ROLE_MCC = 1005;
const int OPERATOR_ROLE_MNC = 1006;
const int OPERATOR_ROLE_NAME = 1007;

/*
const int ROLE_MCC = 1001;
const int ROLE_MNC = 1002;
const int ROLE_NAME = 1003;
const int ROLE_CODE = 1004;
const int ROLE_LENGTH = 1005;
*/

QT_BEGIN_NAMESPACE
class QListView;
class QTreeView;
class QGridLayout;
class QStandardItemModel;
class QItemSelection;
class QStandardItem;
class QMessageBox;
QT_END_NAMESPACE

class OperatorTree : public QWidget
{
    Q_OBJECT

public:
    OperatorTree(ConnectDatabase *database, QWidget *parent = nullptr);
    ~OperatorTree();



private:
    ManagerStorage *ptrManagerStorage;
    ConnectDatabase *ptrConnectDatabase;

    CountryStorage _countryStorage;
    OperatorStorage _operatorStorage;

    QStandardItemModel* standardModel;
    QTreeView *treeView;


    QStandardItem* rootNode;
    QStandardItem* parentItem;
    QStandardItem* childItem;

    OperatorEditor *ptrOperatorEditor;
    OperatorEditorUpdate *ptrOperatorEditorUpdate;
    ButtonHoverWatcher *ptrEditButton;


void generateTree(void);


 private slots:
    void slotEditButton();
    void slotEmpty(const QModelIndex&);
    void slotdoubleClicked(const QModelIndex &index);

    void updateTree(void);


};
#endif // OPERATOR_TREE_H
