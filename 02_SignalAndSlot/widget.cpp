#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

// Teacher 类 老师类
// Student 类 学生类
// 下课后，老师会触发一个信号，饿了，学生响应信号，请客吃饭

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建一个老师对象
    this->zt = new Teacher(this);

    // 创建一个学生对象
    this->st = new Student(this);

    // 老师饿了 学生请客的连接
    // connect(zt, &Teacher::Hungry, st, &Student::treat);
    // 连接带参数的信号和槽
    // 函数 -》 地址
    // 函数指针 -》 函数地址
    void (Teacher:: *teacherSignal)(QString) = &Teacher::Hungry;
    void (Student:: *studentSlot)(QString) = &Student::treat;
    connect(zt, teacherSignal, st, studentSlot);

    // 调用下课函数
    classIsOver();

    // 点击一个 下课的按钮，再触发下课
    QPushButton * btn = new QPushButton("下课", this);
    // 充值窗口大小
    this->resize(600, 400);

    // 点击按钮，触发下课
    // connect(btn, &QPushButton::clicked, this, &Widget::classIsOver);

    // 无参信号和槽连接
    void (Teacher:: *teacherSignal2)(void) = &Teacher::Hungry;
    //void (Student:: *studentSlot2)(void) = &Student::treat;
    //connect(zt, teacherSignal2, st, studentSlot2);

    // 信号连接信号
    connect(btn, &QPushButton::clicked, zt, teacherSignal2);

    // 断开信号
    //disconnect(zt, teacherSignal2, st, studentSlot2);

    // Qt4版本以前的信号和槽连接方式
    // 利用Qt4信号槽 连接无参版本
    // Qt4版本 底层SIGNAL("Hungry")，是根据字符串匹配的，所以不需要看参数
    connect(zt, SIGNAL(Hungry()), st, SLOT(treat()));
    // Qt4版本有点：参数直观 缺点：类型不做检测
    // Qt5以上 支持Qt4的版本写法，反之不支持

    // [=](){
    //     btn->setText("aaaa");
    // }();

    // 利用lambda表达式 实现点击按钮，关闭窗口
    QPushButton * btn2 = new QPushButton;
    btn2->setText("关闭");
    btn2->move(100, 0);
    btn2->setParent(this);
    connect(btn2, &QPushButton::clicked, this, [=](){
        //this->close();
        // emit zt->Hungry("宫保鸡丁");
        btn2->setText("aaa");
    });


}

void Widget::classIsOver()
{
    // 下课函数，调用后 触发老师饿了的信号
    // emit zt->Hungry();
    emit zt->Hungry("宫保鸡丁");
}


Widget::~Widget()
{
    delete ui;
}
