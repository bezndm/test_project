#ifndef OPERATOREDITOR_H
#define OPERATOREDITOR_H

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
class QHBoxLayout;
QT_END_NAMESPACE

class OperatorEditor : public QWidget
{
    Q_OBJECT
public:
    OperatorEditor(ManagerStorage *ptrManagerStorage, QWidget *parent = nullptr);
    ~OperatorEditor();



private:


    ConnectDatabase *ptrConnectDatabase;
    ManagerStorage *ptrManagerStorage;
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

    QString IconDefaultPath;
    QString IconOperatorPath;
    QString IconCountryPath;

    void headerOperatorEditor(void);
    void bodyOperatorEditor(void);
    void footerOperatorEditor(void);

    void fileIsValid(QString path);
    void fileIsValid2(QString path);
    void fileCountryIsValid(void);


signals:
    void signalUpdateVisualTree(void);


private slots:
    void SlotButtonSave();
    void SlotButtonClose();

    void nameChanged(const QString &);
    void mccChanged(const QString &);
    void mncChanged(const QString &);
};

#endif // OPERATOREDITOR_H
