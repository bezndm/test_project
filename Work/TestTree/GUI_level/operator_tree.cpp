#include "GUI_level/operator_tree.h"
#include <QtWidgets>




OperatorTree::OperatorTree(ConnectDatabase *database, QWidget *parent)
{
    QGridLayout *mainLayout = new QGridLayout;
    QHBoxLayout *lay = new QHBoxLayout;

    this->ptrConnectDatabase = database;
    this->ptrManagerStorage = new ManagerStorage(this->ptrConnectDatabase->database);


    this->ptrOperatorEditor = new OperatorEditor(this->ptrManagerStorage);
    this->ptrOperatorEditorUpdate = new OperatorEditorUpdate();

    this->parentItem = new QStandardItem;
    this->childItem = new QStandardItem;

    this->ptrManagerStorage->select_all_countries_from_lists();
    this->ptrManagerStorage->select_all_operators_from_lists();




    this->treeView = new QTreeView(this);
    this->standardModel = new QStandardItemModel;

    this->rootNode = new QStandardItem();
    this->rootNode = standardModel->invisibleRootItem();


    this->ptrEditButton = new ButtonHoverWatcher(":/Others_icons/blue_baseline-add-24px.svg", ":/Others_icons/baseline-add-24px.svg");

    this->ptrEditButton->setFixedSize(24,24);
    this->ptrEditButton->setFlat(true);
    this->ptrEditButton->setStyleSheet("QPushButton:hover"
                                        "{background-color: #ffffff; border-style: inset; }"
                                        "QPushButton:pressed"
                                        "{background-color: #ffffff; border-style: inset; }");

    this->ptrEditButton->setIconSize(QSize(24,24));


    this->generateTree();


    connect(this->ptrEditButton, SIGNAL(clicked()), this, SLOT(slotEditButton()));
    connect(this->treeView, SIGNAL( doubleClicked(const QModelIndex&) ), this, SLOT( slotdoubleClicked(const QModelIndex&) ) );

    connect(this->ptrOperatorEditorUpdate, SIGNAL(signalUpdateVisualTree()), this, SLOT(updateTree()));
    connect(this->ptrOperatorEditor, SIGNAL(signalUpdateVisualTree()), this, SLOT(updateTree()));



    this->treeView->setHeaderHidden(true);



    this->standardModel->setHeaderData(0, Qt::Horizontal, "");
    this->treeView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    this->treeView->header()->setStretchLastSection(false);
    this->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->treeView->setModel(this->standardModel);


    lay->setContentsMargins(0,0,35,25);

    lay->addWidget(ptrEditButton,1, Qt::AlignRight);

    mainLayout->addWidget(treeView,  1, 1, 1, 1);
    mainLayout->addLayout(lay,  1, 1, 1, 1, Qt::AlignBottom | Qt::AlignRight);


    setLayout(mainLayout);
    setWindowTitle(tr("Application"));
}


OperatorTree::~OperatorTree()
{

}




void OperatorTree::slotEditButton()
{
    this->ptrOperatorEditor->show();
}

void OperatorTree::slotEmpty(const QModelIndex &index)
{
    QMessageBox::information(nullptr, "Information", "Empty slot (int, int)");
    qDebug() << this->standardModel->data(index, OPERATOR_ROLE_MCC).toInt() << endl;
    qDebug() << this->standardModel->data(index, OPERATOR_ROLE_MNC).toInt() << endl;
}


void OperatorTree::slotdoubleClicked(const QModelIndex &index)
{
    if(index.parent().isValid())
    {
        _countryStorage.set_mcc(this->standardModel->data(index.parent(), COUNTRY_ROLE_MCC).toInt());
        _countryStorage.set_code(this->standardModel->data(index.parent(), COUNTRY_ROLE_CODE).toString());
        _countryStorage.set_name(this->standardModel->data(index.parent(), COUNTRY_ROLE_NAME).toString());
        _countryStorage.set_mnc_length(this->standardModel->data(index.parent(), COUNTRY_ROLE_LENGTH).toInt());

        _operatorStorage.set_name(this->standardModel->data(index, OPERATOR_ROLE_NAME).toString());
        _operatorStorage.set_mcc(this->standardModel->data(index, OPERATOR_ROLE_MCC).toString());
        _operatorStorage.set_mnc(this->standardModel->data(index, OPERATOR_ROLE_MNC).toString());


     //   qDebug() << "MCC    : " << standardModel->data(index.parent(), COUNTRY_ROLE_MCC).toInt() << endl;
     //   qDebug() << "CODE   : " << standardModel->data(index.parent(), COUNTRY_ROLE_CODE).toString() << endl;
     //   qDebug() << "NAME   : " << standardModel->data(index.parent(), COUNTRY_ROLE_NAME).toString() << endl;
     //   qDebug() << "LENGTH : " << standardModel->data(index.parent(), COUNTRY_ROLE_LENGTH).toInt() << endl;


     //   qDebug() << standardModel->data(index, OPERATOR_ROLE_NAME).toString() << endl;
     //   qDebug() << standardModel->data(index, OPERATOR_ROLE_MCC).toString() << endl;
     //   qDebug() << standardModel->data(index, OPERATOR_ROLE_MNC).toString() << endl;

        this->ptrOperatorEditorUpdate->UpdateOperatorEditor(_operatorStorage, _countryStorage);
    }
}



void OperatorTree::generateTree()
{
    for(int i = 0; i < ptrManagerStorage->listCountryStorage.length(); i++)
    {
        this->parentItem = new QStandardItem(QIcon(":Countries/" + static_cast<CountryStorage>(ptrManagerStorage->listCountryStorage.at(i)).get_code() + ".png"),static_cast<CountryStorage>(ptrManagerStorage->listCountryStorage.at(i)).get_name());

        this->parentItem->setData(static_cast<CountryStorage>(this->ptrManagerStorage->listCountryStorage.at(i)).get_name(), COUNTRY_ROLE_NAME);
        this->parentItem->setData(static_cast<CountryStorage>(this->ptrManagerStorage->listCountryStorage.at(i)).get_mcc(), COUNTRY_ROLE_MCC);
        this->parentItem->setData(static_cast<CountryStorage>(this->ptrManagerStorage->listCountryStorage.at(i)).get_code(), COUNTRY_ROLE_CODE);
        this->parentItem->setData(static_cast<CountryStorage>(this->ptrManagerStorage->listCountryStorage.at(i)).get_mnc_length(), COUNTRY_ROLE_LENGTH);

        this->rootNode->appendRow(parentItem);

        for(int j = 0; j < this->ptrManagerStorage->listOperatorStorage.length(); j++)
        {
            if(static_cast<CountryStorage>(ptrManagerStorage->listCountryStorage.at(i)).get_mcc() == static_cast<OperatorStorage>(this->ptrManagerStorage->listOperatorStorage.at(j)).get_mcc().toInt())
            {
                this->childItem = new QStandardItem(QIcon(":Operators/" + static_cast<OperatorStorage>(this->ptrManagerStorage->listOperatorStorage.at(j)).get_mcc() + "_" + static_cast<OperatorStorage>(this->ptrManagerStorage->listOperatorStorage.at(j)).get_mnc() + ".png"),static_cast<OperatorStorage>(this->ptrManagerStorage->listOperatorStorage.at(j)).get_name() + "(" + static_cast<OperatorStorage>(this->ptrManagerStorage->listOperatorStorage.at(j)).get_mcc() + ", " + static_cast<OperatorStorage>(this->ptrManagerStorage->listOperatorStorage.at(j)).get_mnc() + ")");

                this->childItem->setData(static_cast<OperatorStorage>(this->ptrManagerStorage->listOperatorStorage.at(j)).get_mcc(), OPERATOR_ROLE_MCC);
                this->childItem->setData(static_cast<OperatorStorage>(this->ptrManagerStorage->listOperatorStorage.at(j)).get_mnc(), OPERATOR_ROLE_MNC);
                this->childItem->setData(static_cast<OperatorStorage>(this->ptrManagerStorage->listOperatorStorage.at(j)).get_name(), OPERATOR_ROLE_NAME);

                this->parentItem->appendRow(this->childItem);

                CloseButton *ptrButtonClose = new CloseButton( this );
                this->treeView->setItemDelegateForRow( j, ptrButtonClose );

                connect(ptrButtonClose, SIGNAL(signalButtonClicked(const QModelIndex&)), this, SLOT(slotEmpty(const QModelIndex&)) );
            }
        }
    }
}


void OperatorTree::updateTree(void)
{
    this->ptrManagerStorage->listCountryStorage.clear();
    this->ptrManagerStorage->listOperatorStorage.clear();

    this->standardModel->removeRows(0, standardModel->rowCount());

    this->ptrManagerStorage->select_all_countries_from_lists();
    this->ptrManagerStorage->select_all_operators_from_lists();

    this->generateTree();
}
