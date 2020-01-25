#include "operator_editor_update.h"
#include <QtWidgets>
#include <QDebug>

OperatorEditorUpdate::OperatorEditorUpdate(QWidget *parent) : QWidget(parent)
{
    QSqlDatabase *ptrDatabase = new QSqlDatabase;
    this->ptrManagerStorage = new ManagerStorage(ptrDatabase);


    headerOperatorEditor();
    bodyOperatorEditor();
    footerOperatorEditor();

    QGridLayout *mainLayout = new QGridLayout;

    mainLayout->addLayout(hbLayout,  1, 1, 1, 1);
    mainLayout->addLayout(layout,  2, 1, 1, 1);
    mainLayout->addWidget(buttonBox,  3, 1, 1, 1);


    this->setMinimumWidth(250);
    this->setMaximumWidth(250);

    this->setMinimumHeight(150);
    this->setMaximumHeight(150);

    setLayout(mainLayout);
    setWindowTitle(tr("Application name"));

    connect(buttonSave, SIGNAL(clicked()), this, SLOT(SlotButtonSave()));
    connect(buttonCancel, SIGNAL(clicked()), this, SLOT(SlotButtonClose()));
}

OperatorEditorUpdate::~OperatorEditorUpdate()
{

}



void OperatorEditorUpdate::headerOperatorEditor(void)
{
    hbLayout = new QHBoxLayout;

    firstIcon = new QLabel();
    lableWindowName = new QLabel("Operator editor");

    lableWindowName->setFont(QFont("Times", 10, 100, 0));

    QPixmap myPixmap( ":/Operators/734_6.png" );
    firstIcon->setPixmap( myPixmap );

    hbLayout->addWidget(firstIcon, 1, Qt::AlignLeft);
    hbLayout->addWidget(lableWindowName, 2);

}

void OperatorEditorUpdate::bodyOperatorEditor(void)
{
    layout = new QGridLayout;
    labelName = new QLabel(tr("Name"));
    labelMcc = new QLabel(tr("MCC"));
    labelMnc = new QLabel(tr("MNC"));

    lineEditName = new QLineEdit;
    lineEditMcc = new QLineEdit;
    lineEditMnc = new QLineEdit;

    lineEditMcc->setReadOnly(true);
    lineEditMnc->setReadOnly(true);


    secondIcon = new QLabel();
    QPixmap myPixmap( ":/Countries/AD.png" );
    secondIcon->setPixmap( myPixmap );

    layout->addWidget(labelName,  1, 1, 1, 1);
    layout->addWidget(lineEditName,  1, 2, 1, 2);
    layout->addWidget(labelMcc,  2, 1, 1, 1);
    layout->addWidget(lineEditMcc,  2, 2, 1, 1);
    layout->addWidget(secondIcon,  2, 3, 1, 1);

    layout->addWidget(labelMnc,  3, 1, 1, 1);
    layout->addWidget(lineEditMnc,  3, 2, 1, 2);
}

void OperatorEditorUpdate::footerOperatorEditor(void)
{
    buttonSave = new QPushButton(tr("Save"));
    buttonCancel = new QPushButton(tr("Cancel"));

    buttonBox = new QDialogButtonBox(Qt::Horizontal);
    buttonBox->addButton(buttonSave, QDialogButtonBox::ActionRole);
    buttonBox->addButton(buttonCancel, QDialogButtonBox::ActionRole);
}





void OperatorEditorUpdate::UpdateOperatorEditor(OperatorStorage _operatorStorage, CountryStorage _countryStorage)
{
    QString pixmapOperator = ":/Operators/" + _operatorStorage.get_mcc() + "_" + _operatorStorage.get_mnc() + ".png";
    QString pixmapCountries = ":/Countries/" + _countryStorage.get_code() + ".png";

    qDebug() << pixmapCountries;

    firstIcon->setPixmap( pixmapOperator );
    secondIcon->setPixmap( pixmapCountries );
    lineEditName->setText(tr("%1").arg(_operatorStorage.get_name()));
    lineEditMcc->setText(tr("%1").arg(_operatorStorage.get_mcc()));
    lineEditMnc->setText(tr("%1").arg(_operatorStorage.get_mnc()));

    OperatorEditorUpdate::show();
}


void OperatorEditorUpdate::SlotButtonSave()
{
        OperatorEditorUpdate::close();
    _operatorStorage.set_name(lineEditName->text());
    _operatorStorage.set_mcc(lineEditMcc->text());
    _operatorStorage.set_mnc(lineEditMnc->text());

    ptrManagerStorage->update_operator(_operatorStorage);


    emit signalUpdateVisualTree();



}

void OperatorEditorUpdate::SlotButtonClose()
{
    OperatorEditorUpdate::close();
}


