#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimerEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    // 重写定时器事件
    void timerEvent(QTimerEvent *ev);

    int id1;    // 定时器1的唯一标识符
    int id2;    // 定时器2的唯一标识符

    // 重写事件过滤器的事件
    bool eventFilter(QObject *, QEvent *);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
