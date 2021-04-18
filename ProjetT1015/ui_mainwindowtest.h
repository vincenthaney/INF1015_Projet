#pragma once
/********************************************************************************
** Form generated from reading UI file 'mainwindowQRYlNB.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWQRYLNB_H
#define MAINWINDOWQRYLNB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget* centralwidget;
    QLabel* label;
    QMenuBar* menubar;
    QStatusBar* statusbar;
    
    const int MAIN_WINDOW_SIZE = 400;

    void setupUi(QMainWindow* MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        
        MainWindow->resize(MAIN_WINDOW_SIZE, MAIN_WINDOW_SIZE);
       
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, MAIN_WINDOW_SIZE, MAIN_WINDOW_SIZE));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../Pictures/Chess_Board.svg.png")));
        label->setScaledContents(true);
        label->setTextInteractionFlags(Qt::NoTextInteraction);
        MainWindow->setCentralWidget(centralwidget);
        
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 642, 21));
        MainWindow->setMenuBar(menubar);

        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow* MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("Chess Game", "Chess Game", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChessWindow : public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWQRYLNB_H
