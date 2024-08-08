#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QEvent>
#include <QMouseEvent>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = nullptr);

    // 鼠标进入事件
    void enterEvent(QEnterEvent *event);

    // 鼠标离开事件
    void leaveEvent(QEvent *);

    // 鼠标按下
    virtual void mouseMoveEvent(QMouseEvent *ev) ;
    // 鼠标释放
    virtual void mousePressEvent(QMouseEvent *ev) ;
    // 鼠标移动
    virtual void mouseReleaseEvent(QMouseEvent *ev) ;

    // 通过event事件分发器 拦截 鼠标按下事件
    bool event(QEvent * e);
signals:
};

#endif // MYLABEL_H
