#ifndef DELETEDEMO_H
#define DELETEDEMO_H

#include <QWidget>
#include <QDebug>
#include <QModelIndex>
#include "itemdelegate.h"
#include <QStandardItem>
#include <QStandardItemModel>
#include <QStyleOptionViewItem>

namespace Ui {
class DeleteDemo;
}

class DeleteDemo : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteDemo(QWidget *parent = 0);
    ~DeleteDemo();
    int num;

private:
    Ui::DeleteDemo *ui;
    ItemDelegate *pDelegate;
    QStandardItemModel *StandardItemModel;


private slots:
    void deleteItem(const QModelIndex &index);
    void upItem(const QModelIndex &index);
    void downItem(const QModelIndex &index);
    void topItem(const QModelIndex &index);

    void addItemSlot();
};

#endif // DELETEDEMO_H
