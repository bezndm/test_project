#include "close_button.h"

CloseButton::CloseButton(QObject *parent, const QPixmap &closeIcon)
{
    if(m_closeIcon.isNull())
    {
        QPixmap pixmap(":/Others_icons/baseline-add-16px.svg");
        m_closeIcon = pixmap;
    }
}


QPoint CloseButton::closeIconPos(const QStyleOptionViewItem &option) const
{
    return QPoint(option.rect.right() - m_closeIcon.width() - margin,
                  (option.rect.center().y() + margin) - m_closeIcon.height()/2);
}

void CloseButton::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyledItemDelegate::paint(painter, option, index);
    if(index.parent().isValid() && (option.state & QStyle::State_MouseOver))
    {
        painter->drawPixmap(closeIconPos(option), m_closeIcon);
    }
}

QSize CloseButton::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSize size = QStyledItemDelegate::sizeHint(option, index);

    // Make some room for the close icon
    if(index.parent().isValid()) {
        size.rwidth() += m_closeIcon.width() + margin * 2;
        size.setHeight(qMax(size.height(), m_closeIcon.height() + margin * 2));
    }
    return size;
}

bool CloseButton::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    // Emit a signal when the icon is clicked
    if(index.parent().isValid() && event->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

        QRect closeButtonRect = m_closeIcon.rect().translated(closeIconPos(option));

        if(closeButtonRect.contains(mouseEvent->pos()))
        {
            emit this->signalButtonClicked(index);
        }
    }
    return false;
}

