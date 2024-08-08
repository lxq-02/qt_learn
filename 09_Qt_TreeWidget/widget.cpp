#include "widget.h"
#include "ui_widget.h"
#include <QTreeWidgetItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // treeWidget树控件的使用

    // 设置水平头
    ui->treeWidget->setHeaderLabels(QStringList() << "英雄" << "英雄简介");

    QTreeWidgetItem * liItem = new QTreeWidgetItem(QStringList() << "力量");
    QTreeWidgetItem * minItem = new QTreeWidgetItem(QStringList() << "敏捷");
    QTreeWidgetItem * zhiItem = new QTreeWidgetItem(QStringList() << "智慧");

    // 加载顶层节点
    ui->treeWidget->addTopLevelItem(liItem);
    ui->treeWidget->addTopLevelItem(minItem);
    ui->treeWidget->addTopLevelItem(zhiItem);

    // 追加子节点
    QStringList heroL1;
    heroL1 << "钢背猪" << "前排坦克能在吸收伤害的同时造成可观的范围输出";
    QTreeWidgetItem * li = new QTreeWidgetItem(heroL1);
    liItem->addChild(li);
}

Widget::~Widget()
{
    delete ui;
}
