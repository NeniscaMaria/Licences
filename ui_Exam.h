/********************************************************************************
** Form generated from reading UI file 'Exam.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAM_H
#define UI_EXAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExamClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget;
    QLabel *label;
    QListWidget *resultList;
    QHBoxLayout *horizontalLayout;
    QLineEdit *searchLine;
    QPushButton *pushButton;
    QPushButton *coordButton;
    QPushButton *pushButton_2;
    QPushButton *editButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *ExamClass)
    {
        if (ExamClass->objectName().isEmpty())
            ExamClass->setObjectName(QString::fromUtf8("ExamClass"));
        ExamClass->resize(600, 400);
        centralWidget = new QWidget(ExamClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        horizontalLayout_2->addWidget(listWidget);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        resultList = new QListWidget(centralWidget);
        resultList->setObjectName(QString::fromUtf8("resultList"));

        horizontalLayout_2->addWidget(resultList);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        searchLine = new QLineEdit(centralWidget);
        searchLine->setObjectName(QString::fromUtf8("searchLine"));

        horizontalLayout->addWidget(searchLine);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        coordButton = new QPushButton(centralWidget);
        coordButton->setObjectName(QString::fromUtf8("coordButton"));

        horizontalLayout->addWidget(coordButton);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        editButton = new QPushButton(centralWidget);
        editButton->setObjectName(QString::fromUtf8("editButton"));

        horizontalLayout->addWidget(editButton);


        verticalLayout->addLayout(horizontalLayout);

        ExamClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ExamClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        ExamClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ExamClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ExamClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ExamClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ExamClass->setStatusBar(statusBar);
        toolBar = new QToolBar(ExamClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        ExamClass->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(ExamClass);

        QMetaObject::connectSlotsByName(ExamClass);
    } // setupUi

    void retranslateUi(QMainWindow *ExamClass)
    {
        ExamClass->setWindowTitle(QApplication::translate("ExamClass", "Exam", nullptr));
        label->setText(QApplication::translate("ExamClass", ">>", nullptr));
        pushButton->setText(QApplication::translate("ExamClass", "Search", nullptr));
        coordButton->setText(QApplication::translate("ExamClass", "Make Coord", nullptr));
        pushButton_2->setText(QApplication::translate("ExamClass", "Approve", nullptr));
        editButton->setText(QApplication::translate("ExamClass", "Edit", nullptr));
        toolBar->setWindowTitle(QApplication::translate("ExamClass", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExamClass: public Ui_ExamClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAM_H
