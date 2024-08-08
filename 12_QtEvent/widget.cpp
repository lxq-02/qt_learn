#include "widget.h"
#include "ui_widget.h"
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 启动定时器
    id1 = startTimer(1000);    // 参数1 间隔 单位 间隔

    id2 = startTimer(2000);

    // 定时器第二种方式
    QTimer * timer = new QTimer(this);
    // 启动定时器
    timer->start(500);

    connect(timer, &QTimer::timeout, [=](){
        static int num = 1;
        // label_4每隔0.5秒+1
        ui->label_4->setText(QString::number(num++));
    });


    // 点击暂停按钮，实现定时器停止
    connect(ui->btn, &QPushButton::clicked, [=](){
        timer->stop();
    });


    // 给label1安装事件过滤器
    // 步骤1,安装事件过滤器
    ui->label->installEventFilter(this);
    // 步骤2 重写 eventfilter事件
}

Widget::~Widget()
{
    delete ui;
}


// 重写定时器事件
void Widget::timerEvent(QTimerEvent *ev)
{
    if (ev->timerId() == id1)
    {
        static int num = 1;
        // label_2每隔1秒+1
        ui->label_2->setText(QString::number(num++));
    }

    if (ev->timerId() == id2)
    {
        // label3 每隔2秒 + 1
        static int num2 = 1;
        // label_3每隔1秒+1
        ui->label_3->setText(QString::number(num2++));

    }
}

// 重写事件过滤器的事件
bool Widget::eventFilter(QObject * obj, QEvent * e)
{
    if (obj == ui->label)
    {
        if (e->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent * ev = static_cast<QMouseEvent*>(e);
            QString str = QString("事件过滤器中，鼠标按下了x = %1 y = %2 globalx = %3 globaly = %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
            qDebug() << str;

            return true;
        }

    }

    // 其他默认处理
    return QWidget::eventFilter(obj, e);
}
