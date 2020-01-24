#include "operator_editor.h"
#include <QtWidgets>

OperatorEditor::OperatorEditor(ManagerStorage *ptrManagerStorage, QWidget *parent) : QWidget(parent)
{
    this->ptrManagerStorage = ptrManagerStorage;

    IconDefaultPath = ":/Others_icons/question.png";


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

    connect(lineEditName, &QLineEdit::textChanged, this, &OperatorEditor::nameChanged);
    connect(lineEditMcc, &QLineEdit::textChanged, this, &OperatorEditor::mccChanged);
    connect(lineEditMnc, &QLineEdit::textChanged, this, &OperatorEditor::mncChanged);
}


OperatorEditor::~OperatorEditor()
{

}

void OperatorEditor::headerOperatorEditor(void)
{    
    hbLayout = new QHBoxLayout;

    firstIcon = new QLabel();
    lableWindowName = new QLabel("Operator editor");

    lableWindowName->setFont(QFont("Times", 10, 100, 0));

    QPixmap myPixmap( IconDefaultPath );
    firstIcon->setPixmap( myPixmap );

    hbLayout->addWidget(firstIcon, 1, Qt::AlignLeft);
    hbLayout->addWidget(lableWindowName, 2);
}

void OperatorEditor::bodyOperatorEditor(void)
{
    layout = new QGridLayout;
    labelName = new QLabel(tr("Name"));
    labelMcc = new QLabel(tr("MCC"));
    labelMnc = new QLabel(tr("MNC"));

    lineEditName = new QLineEdit;
    lineEditMcc = new QLineEdit;
    lineEditMnc = new QLineEdit;

    secondIcon = new QLabel();
    QPixmap myPixmap( ":/Others_icons/question.png" );
    secondIcon->setPixmap( myPixmap );

    layout->addWidget(labelName,  1, 1, 1, 1);
    layout->addWidget(lineEditName,  1, 2, 1, 2);
    layout->addWidget(labelMcc,  2, 1, 1, 1);
    layout->addWidget(lineEditMcc,  2, 2, 1, 1);
    layout->addWidget(secondIcon,  2, 3, 1, 1);

    layout->addWidget(labelMnc,  3, 1, 1, 1);
    layout->addWidget(lineEditMnc,  3, 2, 1, 2);
}

void OperatorEditor::footerOperatorEditor(void)
{
    buttonSave = new QPushButton(tr("Save"));
    buttonCancel = new QPushButton(tr("Cancel"));

    buttonBox = new QDialogButtonBox(Qt::Horizontal);
    buttonBox->addButton(buttonSave, QDialogButtonBox::ActionRole);
    buttonBox->addButton(buttonCancel, QDialogButtonBox::ActionRole);
}

void OperatorEditor::SlotButtonClose()
{
    OperatorEditor::close();
}


void OperatorEditor::SlotButtonSave()
{
    ptrManagerStorage->insert_operator(_operatorStorage);

    emit signalUpdateVisualTree();

    OperatorEditor::close();
}


void OperatorEditor::nameChanged(const QString &)
{
    _operatorStorage.set_name(lineEditName->text());
}

void OperatorEditor::mccChanged(const QString &)
{
    _operatorStorage.set_mcc(lineEditMcc->text());

    for(int i = 0; i < ptrManagerStorage->listCountryStorage.length(); i++)
    {
        CountryStorage tempStorage = (this->ptrManagerStorage->listCountryStorage.at(i));
        if(_operatorStorage.get_mcc().toInt() == tempStorage.get_mcc())
        {
            IconCountryPath = ":/Countries/" + tempStorage.get_code() + ".png";

            QFileInfo File(IconCountryPath);
            if(!File.exists())
            {
                secondIcon->setPixmap( IconDefaultPath );
            }

            else if(File.isReadable())
            {
                secondIcon->setPixmap( IconCountryPath );
            }

            break;
        }

    }


    this->fileIsValid(IconOperatorPath);
}

void OperatorEditor::mncChanged(const QString &)
{
    _operatorStorage.set_mnc(lineEditMnc->text());
    IconOperatorPath = ":/Operators/" + _operatorStorage.get_mcc() + "_" + _operatorStorage.get_mnc() + ".png";
    this->fileIsValid(IconOperatorPath);
}


void OperatorEditor::fileIsValid(QString path)
{
    QFileInfo File(path);
    if(!File.exists())
    {
        firstIcon->setPixmap( IconDefaultPath );
    }

    else if(File.isReadable())
    {
        firstIcon->setPixmap( path );
    }
}
