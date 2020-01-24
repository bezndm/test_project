#ifndef OPERATOREDITORUPDATE_H
#define OPERATOREDITORUPDATE_H

#include <QObject>
#include <QWidget>
#include "Storage_Level/operator_storage.h"
#include "Storage_Level/country_storage.h"
#include "Storage_Level/connect_database.h"
#include "Storage_Level/manager_storage.h"


QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
class QLineEdit;
class QGridLayout;
class QDialogButtonBox;
class QFormLayout;
class QHBoxLayout;
QT_END_NAMESPACE

class OperatorEditorUpdate : public QWidget
{
    Q_OBJECT
public:
    OperatorEditorUpdate(QWidget *parent = nullptr);
    ~OperatorEditorUpdate();

    void UpdateOperatorEditor(OperatorStorage _operatorStorage, CountryStorage _countryStorage);

private:

    ManagerStorage *ptrManagerStorage;
    ConnectDatabase *ptrConnectDatabase;

    CountryStorage _countryStorage;
    OperatorStorage _operatorStorage;

    QLabel *firstIcon;
    QLabel *secondIcon;

    QLabel *lableWindowName;

    QLabel *labelName;
    QLineEdit *lineEditName;
    QLabel *labelMcc;
    QLineEdit *lineEditMcc;
    QLabel *labelMnc;
    QLineEdit *lineEditMnc;

    QPushButton *buttonSave;
    QPushButton *buttonCancel;

    QGridLayout *lay;
    QGridLayout *layout;

    QHBoxLayout *hbLayout;

    QDialogButtonBox *buttonBox;

    void headerOperatorEditor(void);
    void bodyOperatorEditor(void);
    void footerOperatorEditor(void);

signals:
    void signalUpdateVisualTree();

public slots:


private slots:
    void SlotButtonSave();
    void SlotButtonClose();

};



#endif // OPERATOREDITORUPDATE_H
