#include "mycoin.h"
#include <QTimer>

MyCoin::MyCoin(QWidget *parent)
    : QPushButton{parent}
{}

MyCoin::MyCoin(QString butImg) // 代表图片路径
{
    QPixmap pixmap;
    bool ret = pixmap.load(butImg);
    if (!ret)
    {
        qDebug() << butImg << "加载图片失败！";
    }

    this->setFixedSize(pixmap.width(), pixmap.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(), pixmap.height()));


    // 初始化定时器
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    // 监听正面翻转的信号槽，翻转金币
    connect(timer1, &QTimer::timeout, [=](){
        QPixmap pixmap;
        QString str = QString(":/res/Coin000%1.png").arg(this->min++);
        pixmap.load(str);
        this->setFixedSize(pixmap.width(), pixmap.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(), pixmap.height()));
        if (this->min > this->max)  // 如果大于最大值，重置最小值，并停止定时器
        {
            this->min = 1;
            this->isAnimation = false;  // 停止做动画
            timer1->stop();
        }
    });

    // 监听反面翻转的信号槽
    connect(timer2, &QTimer::timeout, [=](){
        QPixmap pixmap;
        QString str = QString(":/res/Coin000%1.png").arg(this->max--);
        pixmap.load(str);
        this->setFixedSize(pixmap.width(), pixmap.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(), pixmap.height()));
        if (this->max < this->min)  // 如果小于最小值，重置最大值，并停止定时器
        {
            this->max = 8;
            this->isAnimation = false;  // 停止做动画
            timer2->stop();
        }
    });
}

void MyCoin::changeFlag()  // 改变标志，执行翻转效果
{
    if (this->flag) // 如果是正面
    {
        timer1->start(30);
        this->isAnimation = true;   // 开始做动画
        this->flag = false;
    }
    else    // 如果是反面
    {
        timer2->start(30);
        this->isAnimation = true;   // 开始做动画
        this->flag = true;
    }

}

// 重写按下
void MyCoin::mousePressEvent(QMouseEvent *e)
{
    // 正在做动画翻转，或者禁止按压，不执行
    if (this->isAnimation || notPress == true)
    {
        return;
    }
    else
    {
        return QPushButton::mousePressEvent(e);
    }
}
