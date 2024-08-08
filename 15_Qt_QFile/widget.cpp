#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>
#include <QTextCodec>
#include <QFileInfo>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 点击选取文件的按钮，弹出对话框
    connect(ui->pushButton, &QPushButton::clicked, [=](){

        QString path = QFileDialog::getOpenFileName(this, "打开文件", "C:\\Users\\Administrator\\Desktop");
        // 将路径放入到lineEdit中
        ui->lineEdit->setText(path);

        // 编码格式类
        //QTextCodec * codec = QTextCodec::codecForName("gbk");

        // 读取内容 放入到textEdit中
        // QFile默认支持的格式是utf-8
        QFile file(path);   // 参数就是读取文件的路径
        // 设置打开方式
        file.open(QIODevice::ReadOnly);

        // QByteArray array = file.readAll();

        QByteArray array;
        while (!file.atEnd())
        {
            array += file.readLine();     // 按行读
        }
        // 将读取到的数据 放入到textEdit中
        ui->textEdit->setText(array);
        // ui->textEdit->setText(codec->toUnicode((array)));

        // 对文件对象进行关闭
        file.close();

        // // 进行写入
        // file.open(QIODevice::Append);   // 用追加的方式进行写
        // file.write("aaaaaaa");
        // file.close();

        // QFileInfo 文件消息类
        QFileInfo info(path);

        qDebug() << "大小：" << info.size() << " 后缀名：" << info.suffix() << " 文件名称:" << info.fileName();
    });

}

Widget::~Widget()
{
    delete ui;
}
