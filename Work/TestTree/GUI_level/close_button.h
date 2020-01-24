#ifndef CLOSEBUTTON_H
#define CLOSEBUTTON_H
#include <QObject>
#include <QtWidgets>
#include <Storage_Level/manager_storage.h>
#include <GUI_level/operator_editor_update.h>

class QStyledItemDelegate;

class CloseButton : public QStyledItemDelegate {
    Q_OBJECT
public:

    explicit CloseButton(QObject *parent = 0,
                         const QPixmap &closeIcon = QPixmap());

    QPoint closeIconPos(const QStyleOptionViewItem &option) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const;

    bool editorEvent(QEvent *event, QAbstractItemModel *model,
                     const QStyleOptionViewItem &option,
                     const QModelIndex &index);

signals:
    void signalButtonClicked(const QModelIndex&);
private:
    QPixmap m_closeIcon;

    static const int margin = 2; // pixels to keep arount the icon

    Q_DISABLE_COPY(CloseButton)
};





#endif // CLOSEBUTTON_H
