#include "mainwindow.h"
#include "ui_mainwindowtest.h"

#include <QGridLayout>


ChessWindow::ChessWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChessWindow)
{
    ui->setupUi(this);
    chessBoard = Board();

    auto layout = new QGridLayout();

}

ChessWindow::~ChessWindow()
{
   delete ui;
}

