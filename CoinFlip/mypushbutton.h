#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);

    // normalImg 正常显示的图片
    // pressImg 按下后显示的图片，默认为空
    MyPushButton(QString normalImg, QString pressImg = "");

    QString normalImgPath;  // 默认显示图片路径
    QString pressedImgPath; // 按下后显示图片路径

    // 弹跳效果
    void zoom1();   // 向下跳跃
    void zoom2();   // 向上跳跃

    // 鼠标点击事件
    void mousePressEvent(QMouseEvent * e);
    // 鼠标释放事件
    void mouseReleaseEvent(QMouseEvent * e);
signals:
};

#endif // MYPUSHBUTTON_H
