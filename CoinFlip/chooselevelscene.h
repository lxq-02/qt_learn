#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include "playscene.h"
#include "mypushbutton.h"

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

    // 重写绘图事件
    void paintEvent(QPaintEvent *);

    // 游戏场景指针
    PlayScene *pScene = NULL;
    MyPushButton * menuBtn = NULL;
signals:
    // 自定义信号 告诉主场景，我返回了
    void chooseSceneBack();
};

#endif // CHOOSELEVELSCENE_H
