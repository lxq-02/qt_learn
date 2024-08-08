#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , m_newWindow(new QWidget)  // 去掉this，是一个独立的窗口
{
    ui->setupUi(this);

    resize(600, 400);

    QPushButton * m_btnOpen = new QPushButton;
    m_btnOpen->setParent(this);
    m_btnOpen->setText("打开");
    m_btnOpen->move(200, 200);

    QPushButton *m_btnClose = new QPushButton;
    m_btnClose->setParent(this);
    m_btnClose->setText("关闭");
    m_btnClose->move(400, 200);

    connect(m_btnOpen, &QPushButton::clicked, m_newWindow, &QWidget::show);
    connect(m_btnClose, &QPushButton::clicked, m_newWindow, &QWidget::close);
}

Widget::~Widget()
{
    delete ui;
}
