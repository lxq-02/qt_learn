/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "mylabel.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    myLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *btn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(514, 422);
        label = new myLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 80, 281, 61));
        label->setFrameShape(QFrame::Shape::Box);
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 190, 271, 51));
        label_2->setFrameShape(QFrame::Shape::Panel);
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 280, 271, 16));
        label_3->setFrameShape(QFrame::Shape::Panel);
        label_4 = new QLabel(Widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 340, 261, 16));
        label_4->setFrameShape(QFrame::Shape::Panel);
        label_4->setFrameShadow(QFrame::Shadow::Sunken);
        btn = new QPushButton(Widget);
        btn->setObjectName("btn");
        btn->setGeometry(QRect(350, 340, 75, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        btn->setText(QCoreApplication::translate("Widget", "\346\232\202\345\201\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
