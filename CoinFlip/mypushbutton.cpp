#include "mypushbutton.h"
#include <QPixmap>
#include <QPropertyAnimation>

MyPushButton::MyPushButton(QWidget *parent)
    : QPushButton{parent}
{}

MyPushButton::MyPushButton(QString normalImg, QString pressImg)
{
    this->normalImgPath = normalImg;
    this->pressedImgPath = pressImg;

    // 创建QPixmap对象
    QPixmap pixmap;
    // 判断是否能够正常加载显示的图片，若不能提示失败
    bool ret = pixmap.load(normalImgPath);
    if (!ret)
    {
        qDebug() << normalImg << "加载图片失败";
        return;
    }

    // 设置图片的固定尺寸
    this->setFixedSize(pixmap.width(), pixmap.height());

    // 设置不规则图片的样式表
    this->setStyleSheet("QPushButton{border:0px;}");

    // 设置图标
    this->setIcon(pixmap);

    // 设置图标大小
    this->setIconSize(QSize(pixmap.width(), pixmap.height()));
}

void MyPushButton::zoom1()
{
    // 创建动画对象
    QPropertyAnimation * animation1 = new QPropertyAnimation(this, "geometry");
    // 设置事件间隔，单位毫秒
    animation1->setDuration(200);
    // 设置起始位置
    animation1->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    // 创建结束位置
    animation1->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    // 设置缓和曲线,QEasingCurve::OutBounce为弹跳效果
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    // 开始执行动画
    animation1->start();
}

void MyPushButton::zoom2()
{
    // 创建动画对象
    QPropertyAnimation * animation1 = new QPropertyAnimation(this, "geometry");
    // 设置事件间隔，单位毫秒
    animation1->setDuration(200);
    // 设置起始位置
    animation1->setStartValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
    // 创建结束位置
    animation1->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    // 设置缓和曲线,QEasingCurve::OutBounce为弹跳效果
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    // 开始执行动画
    animation1->start();
}

// 鼠标点击事件
void MyPushButton::mousePressEvent(QMouseEvent * e)
{
    // 传入的按下图片不为空 说明需要有按下状态，切换图片
    if (this->pressedImgPath != "")
    {
        QPixmap pixmap;
        bool ret = pixmap.load(pressedImgPath);
        if (!ret)
        {
            qDebug() << pressedImgPath << "加载图片失败!";
        }

        this->setFixedSize(pixmap.width(), pixmap.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(), pixmap.height()));
    }

    // 交给父类执行按下事件
    return QPushButton::mousePressEvent(e);
}
// 鼠标释放事件
void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    // 传入的按下图片不为空 说明需要有按下状态，切换成初始图片
    if (this->pressedImgPath != "")
    {
        QPixmap pixmap;
        bool ret = pixmap.load(normalImgPath);
        if (!ret)
        {
            qDebug() << pressedImgPath << "加载图片失败!";
        }

        this->setFixedSize(pixmap.width(), pixmap.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(), pixmap.height()));
    }

    // 交给父类执行按下事件
    return QPushButton::mouseReleaseEvent(e);
}
