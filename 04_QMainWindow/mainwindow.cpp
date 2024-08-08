#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QDebug>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 重置窗口大小
    resize(600, 400);

    // 菜单栏，只能最多有一个
    // 菜单栏创建
    QMenuBar * m_bar = menuBar();
    // 将菜单栏放入到窗口中
    setMenuBar(m_bar);

    // 创建菜单
    QMenu * m_fileMenu = m_bar->addMenu("文件");
    QMenu * m_editMenu = m_bar->addMenu("编辑");

    // 创建菜单项
    QAction * newAction = m_fileMenu->addAction("新建");
    // 添加分隔符
    m_fileMenu->addSeparator();
    QAction * openAction = m_fileMenu->addAction("打开");


    // 工具栏
    // 可以有多个
    QToolBar * m_toolBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea, m_toolBar);

    // 后期设置 只允许 左右停靠
    m_toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);

    // 设置浮动
    m_toolBar->setFloatable(true);

    // 设置移动（总开关）
    m_toolBar->setMovable(true);

    // 工具栏中可以设置内容
    m_toolBar->addAction(newAction);
    m_toolBar->addSeparator();
    m_toolBar->addAction(openAction);
    // 工具栏中添加控件
    QPushButton * m_btn = new QPushButton("aa", this);
    m_toolBar->addWidget(m_btn);


    // 状态栏 最多有一个
    QStatusBar * m_stBar = statusBar();
    // 设置到窗口中
    setStatusBar(m_stBar);
    // 放标签控件
    QLabel * m_label = new QLabel("提示信息", this);
    m_stBar->addWidget(m_label);

    QLabel * m_label2 = new QLabel("右侧提示信息", this);
    m_stBar->addPermanentWidget(m_label2);


    // 铆接部件（浮动窗口）可以有多个
    QDockWidget * m_dockWidget = new QDockWidget("浮动", this);
    addDockWidget(Qt::BottomDockWidgetArea, m_dockWidget);
    // 设置后期停靠区域， 只允许上下
    m_dockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

    // 设置中心部件 只能有一个
    QTextEdit * m_edit = new QTextEdit(this);
    setCentralWidget(m_edit);
}

MainWindow::~MainWindow() {}
