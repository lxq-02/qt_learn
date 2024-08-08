#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "mycoin.h"

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int);

    int levelIndex;     // 成员变量 记录关卡索引

    int gameArray[4][4];    // 二维数组数据 维护每个关卡的具体数据
    MyCoin * coinBtn[4][4];    // 金币按钮数组

    bool isWin = true;  // 是否胜利

    // 设置背景
    void paintEvent(QPaintEvent *);
signals:
    void chooseSceneBack();
};

#endif // PLAYSCENE_H
