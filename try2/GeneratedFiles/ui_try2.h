/********************************************************************************
** Form generated from reading UI file 'try2.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRY2_H
#define UI_TRY2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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

class Ui_try2Class
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *taskListWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *taskDescriptionEdit;
    QPushButton *addButton;
    QPushButton *removeButton_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *startButton;
    QPushButton *closeButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *try2Class)
    {
        if (try2Class->objectName().isEmpty())
            try2Class->setObjectName(QStringLiteral("try2Class"));
        try2Class->resize(426, 423);
        centralWidget = new QWidget(try2Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 381, 331));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        taskListWidget = new QListWidget(layoutWidget);
        taskListWidget->setObjectName(QStringLiteral("taskListWidget"));

        verticalLayout->addWidget(taskListWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        taskDescriptionEdit = new QLineEdit(layoutWidget);
        taskDescriptionEdit->setObjectName(QStringLiteral("taskDescriptionEdit"));

        horizontalLayout->addWidget(taskDescriptionEdit);

        addButton = new QPushButton(layoutWidget);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout->addWidget(addButton);

        removeButton_2 = new QPushButton(layoutWidget);
        removeButton_2->setObjectName(QStringLiteral("removeButton_2"));

        horizontalLayout->addWidget(removeButton_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        startButton = new QPushButton(layoutWidget);
        startButton->setObjectName(QStringLiteral("startButton"));

        horizontalLayout_2->addWidget(startButton);

        closeButton = new QPushButton(layoutWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        horizontalLayout_2->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout_2);

        try2Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(try2Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 426, 26));
        try2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(try2Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        try2Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(try2Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        try2Class->setStatusBar(statusBar);

        retranslateUi(try2Class);

        QMetaObject::connectSlotsByName(try2Class);
    } // setupUi

    void retranslateUi(QMainWindow *try2Class)
    {
        try2Class->setWindowTitle(QApplication::translate("try2Class", "try2", 0));
        addButton->setText(QApplication::translate("try2Class", "add", 0));
        removeButton_2->setText(QApplication::translate("try2Class", "remove", 0));
        startButton->setText(QApplication::translate("try2Class", "Start", 0));
        closeButton->setText(QApplication::translate("try2Class", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class try2Class: public Ui_try2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRY2_H
