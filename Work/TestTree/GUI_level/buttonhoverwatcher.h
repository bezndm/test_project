#ifndef BUTTONHOVERWATCHER_H
#define BUTTONHOVERWATCHER_H

#include <QPushButton>
#include <QEvent>
#include <QObject>
#include <QWidget>

class ButtonHoverWatcher : public QPushButton
{
    Q_OBJECT

public:
    explicit ButtonHoverWatcher(QWidget *parent = nullptr);
    explicit ButtonHoverWatcher(QString pathEnterIcon, QString pathLeaveIcon, QWidget *parent = nullptr);
    explicit ButtonHoverWatcher(QIcon *ptrEnterIcon, QIcon *ptrLeaveIcon, QWidget *parent = nullptr);
    ~ButtonHoverWatcher(void);
    void setEnterIcon(QIcon *ptrNewIcon);
    void setLeaveIcon(QIcon *ptrNewIcon);

    void onEnterIcon(void);
    void onLeaveIcon(void);
private:
    QIcon *EnterIcon;
    QIcon *LeaveIcon;

protected:
    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // BUTTONHOVERWATCHER_H
