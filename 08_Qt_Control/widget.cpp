#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 利用listWidget写诗
    // QListWidgetItem * item = new QListWidgetItem("锄禾日当午");
    // item->setTextAlignment(Qt::AlignCenter);
    // // 将一行诗放入到listWidget控件中
    // ui->listWidget->addItem(item);

    // QStringList List<String>
    QStringList list;
    list << "锄禾日当午" << "汗滴禾下土" << "谁知盘中餐" << "粒粒皆辛苦";
    ui->listWidget->addItems(list);
}

Widget::~Widget()
{
    delete ui;
}
