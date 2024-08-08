#include "mylabel.h"
#include <QDebug>

myLabel::myLabel(QWidget *parent)
    : QLabel{parent}
{
    // 设置鼠标追踪状态
    setMouseTracking(true);
}

// 鼠标进入事件
void myLabel::enterEvent(QEnterEvent *event)
{
    //qDebug() << "鼠标进入了";
}

// 鼠标离开事件
void myLabel::leaveEvent(QEvent *)
{
    //qDebug() << "鼠标离开了";
}

// 鼠标移动
void myLabel::mouseMoveEvent(QMouseEvent *ev)
{

    // 当鼠标左键按下 提示信息
    //if (ev->buttons() & Qt::LeftButton)
    {
        QString str = QString("鼠标移动了x = %1 y = %2 globalx = %3 globaly = %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    }
}

// 鼠标按下
void myLabel::mousePressEvent(QMouseEvent *ev)
{
    // 当鼠标左键按下 提示信息
    //if (ev->button() == Qt::LeftButton)
    {
        QString str = QString("鼠标按下了x = %1 y = %2 globalx = %3 globaly = %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    }
}

// 鼠标释放
void myLabel::mouseReleaseEvent(QMouseEvent *ev)
{

    // 当鼠标左键按下 提示信息
    //if (ev->button() == Qt::LeftButton)
    {
        QString str = QString("鼠标释放了x = %1 y = %2 globalx = %3 globaly = %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    }

}

// 通过event事件分发器 拦截 鼠标按下事件
bool myLabel::event(QEvent * e)
{
    // 如果是鼠标按下，在event事件分发中做拦截操作
    if (e->type() == QEvent::MouseButtonPress || e->type() == QEvent::MouseButtonDblClick)
    {
        QMouseEvent * ev = static_cast<QMouseEvent*>(e);
        QString str = QString("鼠标   按下了x = %1 y = %2 globalx = %3 globaly = %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    }

    // 其他事件 交给父类处理 默认处理
    return QLabel::event(e);
}
