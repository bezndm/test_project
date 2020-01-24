#include "buttonhoverwatcher.h"


ButtonHoverWatcher::ButtonHoverWatcher(QWidget *parent) : QPushButton (parent)
{
    this->setMouseTracking(true);
    this->installEventFilter(this);
}

ButtonHoverWatcher::ButtonHoverWatcher(QString pathEnterIcon, QString pathLeaveIcon, QWidget *parent): QPushButton (parent)
{
    this->EnterIcon = new QIcon(pathEnterIcon);
    this->LeaveIcon = new QIcon(pathLeaveIcon);
    this->setIcon(*LeaveIcon);
    this->setMouseTracking(true);
    this->installEventFilter(this);
}

ButtonHoverWatcher::ButtonHoverWatcher(QIcon *ptrEnterIcon, QIcon *ptrLeaveIcon, QWidget *parent): QPushButton (parent)
{
    this->EnterIcon = ptrEnterIcon;
    this->LeaveIcon = ptrLeaveIcon;
    this->setIcon(*LeaveIcon);
    this->setMouseTracking(true);
    this->installEventFilter(this);
}



ButtonHoverWatcher::~ButtonHoverWatcher()
{
    delete this->EnterIcon;
    delete this->LeaveIcon;
}

void ButtonHoverWatcher::setEnterIcon(QIcon *ptrNewIcon)
{
    this->EnterIcon = ptrNewIcon;
}

void ButtonHoverWatcher::setLeaveIcon(QIcon *ptrNewIcon)
{
    this->LeaveIcon = ptrNewIcon;
}

void ButtonHoverWatcher::onEnterIcon(void)
{
    this->setIcon(*EnterIcon);
}

void ButtonHoverWatcher::onLeaveIcon(void)
{
    this->setIcon(*LeaveIcon);
}

bool ButtonHoverWatcher::eventFilter(QObject *watched, QEvent *event)
{

    if(watched == this)
    {

        if (event->type() == QEvent::Enter)
        {
            this->setIcon(*EnterIcon);
        }

        if (event->type() == QEvent::Leave)
        {
            this->setIcon(*LeaveIcon);
        }
    }

    return QWidget::eventFilter(watched, event);
}
