#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    explicit MyCoin(QWidget *parent = nullptr);

    MyCoin(QString butImg); // 代表图片路径

    int posX;   // x坐标
    int posY;   // y坐标
    bool flag;  // 正反标志

    void changeFlag();  // 改变标志，执行翻转效果
    QTimer * timer1;    // 正面翻反面，定时器
    QTimer * timer2;    // 反面翻正面，定时器
    int min = 1;    // 最小照片的索引
    int max = 8;    // 最大照片的索引

    bool isAnimation = false;   // 执行动画的标志
    bool notPress = false; // false = 能按，true = 不能按

    void mousePressEvent(QMouseEvent *e);
signals:
};

#endif // MYCOIN_H
