#include "itemdelegate.h"
#include <QPainter>
#include <QMouseEvent>
#include <QStyledItemDelegate>
#include <QToolTip>
#include <QApplication>
#include <QStyle>
#include <QEvent>
#include <QMessageBox>
#include <QDebug>

ItemDelegate::ItemDelegate(QObject *parent)
    :QStyledItemDelegate(parent)
{

}



void ItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItem viewOption(option);//用来在视图中画一个item

    //viewOption.state这个变量保存在绘制控件时使用的样式标志

    if(viewOption.state & QStyle::State_HasFocus)//后者用于指示该控件是否有焦点
    {
        viewOption.state = viewOption.state ^ QStyle::State_HasFocus;
    }

    QStyledItemDelegate::paint(painter,viewOption,index);//使用painter和style选项来渲染项目索引所指定的项。

    int height = (viewOption.rect.height())/2;
    QPixmap pixmap = QPixmap(":/image/del.png");

    QPixmap image = QPixmap(":/image/top.png");

    QPixmap Photo = QPixmap(":/image/down.png");

    QPixmap picure = QPixmap(":/image/up.png");

    QPixmap numimage = QPixmap(":/image/number.png");
    QPixmap codeimage = QPixmap(":/image/codenum.png");
    QPixmap showimage = QPixmap(":/image/photo");

    //绘制控件区域以及大小长度宽度
    QRect decorationRect = QRect(viewOption.rect.left() + viewOption.rect.width() -50, viewOption.rect.top() + height - 20,40,40);
    QRect ImageRect = QRect(viewOption.rect.left() + viewOption.rect.width() -110, viewOption.rect.top() + height - 20,40,40);
    QRect PhotoRect = QRect(viewOption.rect.left() + viewOption.rect.width() -170, viewOption.rect.top() + height - 20,40,40);
    QRect picureRect = QRect(viewOption.rect.left() + viewOption.rect.width() -230, viewOption.rect.top() + height - 20,40,40);

    QRect numRect = QRect(viewOption.rect.left() + viewOption.rect.width() -450, viewOption.rect.top() + height - 20,40,40);
    QRect codeRect = QRect(viewOption.rect.left() + viewOption.rect.width() -345, viewOption.rect.top() + height - 15,95,30);
    QRect showRect = QRect(viewOption.rect.left() + viewOption.rect.width() -400, viewOption.rect.top() + height - 20,40,40);
    //在上述区域画出对应的图片
    painter->drawPixmap(decorationRect,pixmap);
    painter->drawPixmap(ImageRect,image);
    painter->drawPixmap(PhotoRect,Photo);
    painter->drawPixmap(picureRect,picure);

    painter->drawPixmap(codeRect,codeimage);
    painter->drawPixmap(showRect,showimage);
    painter->drawPixmap(numRect,numimage);


}

bool ItemDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    //获得矩形区域高-9的一半
    int height = (option.rect.height() - 9) / 2;

    //构造一个矩形区域
    QRect decorationRect = QRect(option.rect.left() + option.rect.width() - 50, option.rect.top() + height-20, 40, 40);
    QRect UpRect = QRect(option.rect.left() + option.rect.width() - 110, option.rect.top() + height-20, 40, 40);
    QRect downRect = QRect(option.rect.left() + option.rect.width() - 170, option.rect.top() + height-20, 40, 40);
    QRect topRect = QRect(option.rect.left() + option.rect.width() - 230, option.rect.top() + height-20, 40, 40);

    QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);//将事件转换为鼠标事件


    //判断当前事件是鼠标按钮事件，并且鼠标位置是属于当前矩形范围内，就发送deleteItem信号
    if (event->type() == QEvent::MouseButtonPress && decorationRect.contains(mouseEvent->pos()))
    {
        emit deleteItem(index);
        qDebug()<<"delete";
    }
    else if(event->type() == QEvent::MouseButtonPress && UpRect.contains(mouseEvent->pos()))
    {
        emit upItem(index);
        qDebug()<<"up";
    }
    else if(event->type() == QEvent::MouseButtonPress && downRect.contains(mouseEvent->pos()))
    {
        emit downItem(index);
        qDebug()<<"down";
    }
    else if(event->type() == QEvent::MouseButtonPress && topRect.contains(mouseEvent->pos()))
    {
        emit topItem(index);
        qDebug()<<"top";
    }


    return QStyledItemDelegate::editorEvent(event, model, option, index);


}
