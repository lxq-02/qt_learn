#include "chooselevelscene.h"
#include "mypushbutton.h"
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include <QSoundEffect>

ChooseLevelScene::ChooseLevelScene(QWidget *parent)
    : QMainWindow{parent}
{
    // 设置固定的大小
    this->setFixedSize(320, 588);

    // 设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));

    // 设置窗口标题
    this->setWindowTitle("选择关卡");

    // 创建菜单栏
    QMenuBar * bar = this->menuBar();
    this->setMenuBar(bar);

    // 创建开始菜单
    QMenu * startMenu = bar->addMenu("开始");

    // 创建按钮菜单项
    QAction * quitAction = startMenu->addAction("退出");

    // 点击退出，退出游戏
    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });

    // 返回按钮
    MyPushButton *closeBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    closeBtn->setParent(this);
    closeBtn->move(this->width() - closeBtn->width(), this->height() - closeBtn->height());
    // 返回按钮音效
    QSoundEffect * backSound = new QSoundEffect(this);
    backSound->setSource(QUrl::fromLocalFile(":/res/BackButtonSound.wav"));

    // 点击返回
    connect(closeBtn, &MyPushButton::clicked, [=](){
        backSound->play();
        // 告诉主场景 我返回了
        QTimer::singleShot(500, this, [=](){
            this->hide();
            // 触发自定义信号，关闭自身，该信号写道signals下做声明
            emit this->chooseSceneBack();
        });
    });

    // 选择关卡按钮音效
    QSoundEffect * chooseSound = new QSoundEffect(this);
    chooseSound->setSource(QUrl::fromLocalFile(":/res/TapButtonSound.wav"));

    // 创建关卡按钮
    for (int i = 0; i < 20; i++)
    {
        menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25 + (i % 4) * 70, 130 + (i/4) * 70);

        // 监听选择关卡按钮的信号槽
        connect(menuBtn, &MyPushButton::clicked, [=](){
            chooseSound->play();

            QString str = QString("您选择的是第 %1 关").arg(i + 1);
            qDebug() << str;

            // 进入到游戏场景
            if (pScene == NULL)
            {
                this->hide();   // 将选关场景隐藏掉
                // 将选择的关卡号 传入给PlayerScene 创建游戏场景
                pScene = new PlayScene(i + 1);
                pScene->setGeometry(this->geometry());
                pScene->show();     // 显示游戏

                // PlayScene的返回按钮监听，删除该Scene并且将指针指向空
                connect(pScene, &PlayScene::chooseSceneBack, [=](){
                    this->setGeometry(pScene->geometry());
                    this->show();
                    delete pScene;
                    pScene = NULL;
                });
            }
        });

        // 按钮上显示的文字
        QLabel * label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(), menuBtn->height());
        label->setText(QString::number(i+1));
        label->setAlignment(Qt::AlignHCenter |Qt::AlignVCenter);    // 设置居中
        label->move(25 + (i % 4) * 70, 130 + (i / 4) * 70);
        // 鼠标事件穿透,防止标签挡着按钮 51号属性
        label->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    }


}

void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    // 加载标题
    pix.load(":/res/Title.png");
    painter.drawPixmap(this->width() * 0.5 - pix.width() * 0.5, 30, pix.width(), pix.height(), pix);
}
