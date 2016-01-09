#ifndef ITEMDELEGATE_H
#define ITEMDELEGATE_H
#include <QStyledItemDelegate>
#include <QModelIndex>
class ItemDelegate : public QStyledItemDelegate
{   
    Q_OBJECT
signals:
    void deleteItem(const QModelIndex &index);
    void upItem(const QModelIndex &index);
    void downItem(const QModelIndex &index);
    void topItem(const QModelIndex &index);
public:
    ItemDelegate(QObject *parent = 0);
    virtual ~ItemDelegate(){}
    void paint(QPainter * painter,const QStyleOptionViewItem & option,const QModelIndex & index) const;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);
};

#endif // ITEMDELEGATE_H
