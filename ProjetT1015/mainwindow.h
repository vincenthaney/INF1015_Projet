#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#include <QMainWindow>
#include "Structures.h"


QT_BEGIN_NAMESPACE
namespace Ui { class ChessWindow; }
QT_END_NAMESPACE

class ChessWindow : public QMainWindow
{
    Q_OBJECT

public:
    ChessWindow(QWidget *parent = nullptr);
    ~ChessWindow();
public slots:
    void fonction(int x, int y);


private:
    Ui::ChessWindow *ui;
    Board chessBoard;
};
#endif // MAINWINDOW_H
