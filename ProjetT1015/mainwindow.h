#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#include <QMainWindow>
#include "Structures.hpp"


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


private:
    Ui::ChessWindow *ui;
    Board chessBoard;
};
#endif // MAINWINDOW_H
