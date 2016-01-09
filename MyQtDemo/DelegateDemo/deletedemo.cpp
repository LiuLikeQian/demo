#include "deletedemo.h"
#include "ui_deletedemo.h"
#include "itemdelegate.h"
#include <QMessageBox>

DeleteDemo::DeleteDemo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeleteDemo)
{
    ui->setupUi(this);
    num = 0;
    StandardItemModel = new QStandardItemModel(this);
    QStandardItem *Item = new QStandardItem(QString::number(num));
    Item->setFont(QFont("微软雅黑",14,1));
    Item->setSizeHint(QSize(450,60));

    StandardItemModel->appendRow(Item);

    pDelegate = new ItemDelegate(this);
    ui->listView->setItemDelegate(pDelegate);

    ui->listView->setSpacing(2);

    ui->listView->setModel(StandardItemModel);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //delegate send deletesignal,topsignal,downsignal,upsignal
    connect(pDelegate,SIGNAL(deleteItem(QModelIndex)),this,SLOT(deleteItem(QModelIndex)));
    connect(pDelegate,SIGNAL(topItem(QModelIndex)),this,SLOT(topItem(QModelIndex)));
    connect(pDelegate,SIGNAL(upItem(QModelIndex)),this,SLOT(upItem(QModelIndex)));
    connect(pDelegate,SIGNAL(downItem(QModelIndex)),this,SLOT(downItem(QModelIndex)));
    connect(ui->addBtn,SIGNAL(clicked(bool)),this,SLOT(addItemSlot()));

}

DeleteDemo::~DeleteDemo()
{
    delete ui;
}

void DeleteDemo::deleteItem(const QModelIndex &index)
{
    /*
    QModelIndex deletIndex = static_cast<QModelIndex> (index);
    int row = index.row();
    if(StandardItemModel->removeRow(row,deletIndex))
    {
        qDebug()<<"ok";
        qDebug()<<"删除成功"<<index.row();
        num--;
    }*/




    //StandardItemModel->removeRow(ui->listView->currentIndex().row(),index);
    //QStringlistmodel
    //StandardItemModel->removeRows(ui->listView->currentIndex().row(),1);

    //ui->listView->model()->removeRow(index.row());//解决！
    //qDebug()<<StandardItemModel->rowCount();//nice


    StandardItemModel->takeItem(index.row(),1);
    ui->listView->update(index);



}

void DeleteDemo::upItem(const QModelIndex &index)
{
    if(QMessageBox::question(this,"提示","确认要上移所选项吗？",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        //StandardItemModel->moveRow(index,index.row(),index,index.row()-1);

        qDebug()<<"移动成功";
    }
}

void DeleteDemo::downItem(const QModelIndex &index)
{
    /*
    if(QMessageBox::question(this,"提示","确认要下移所选项吗？",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        //StandardItemModel->moveRow(index,index.row(),index,index.row()+1);
        int row = index.row()+1;

        ui->listView->model()->removeRow(index.row());//删除解决！

        if(StandardItemModel->insertRow(row,index))
        {
            qDebug()<<"移动成功";
        }
    }*/

    num++;
    QStandardItem *Item = new QStandardItem(QString::number(num));

    Item->setFont(QFont("微软雅黑",14,1));
    Item->setSizeHint(QSize(450,60));

    StandardItemModel->appendRow(Item);

}

void DeleteDemo::topItem(const QModelIndex &index)
{
    if(QMessageBox::question(this,"提示","确认要顶置所选项吗？",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        qDebug()<<"移动成功";
    }
}

void DeleteDemo::addItemSlot()
{
    num++;
    QStandardItem *Item = new QStandardItem(QString::number(num));

    Item->setFont(QFont("微软雅黑",14,1));
    Item->setSizeHint(QSize(450,60));

    StandardItemModel->appendRow(Item);

}
