/********************************************************************************
** Form generated from reading UI file 'smallwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMALLWIDGET_H
#define UI_SMALLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_smallWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;

    void setupUi(QWidget *smallWidget)
    {
        if (smallWidget->objectName().isEmpty())
            smallWidget->setObjectName("smallWidget");
        smallWidget->resize(229, 50);
        horizontalLayout = new QHBoxLayout(smallWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        spinBox = new QSpinBox(smallWidget);
        spinBox->setObjectName("spinBox");

        horizontalLayout->addWidget(spinBox);

        horizontalSlider = new QSlider(smallWidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);


        retranslateUi(smallWidget);

        QMetaObject::connectSlotsByName(smallWidget);
    } // setupUi

    void retranslateUi(QWidget *smallWidget)
    {
        smallWidget->setWindowTitle(QCoreApplication::translate("smallWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class smallWidget: public Ui_smallWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMALLWIDGET_H
