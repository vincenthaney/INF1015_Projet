
#include "mainwindow.h"
#include "ui_mainwindowtest.h"
//#include "Structures.h"
#include <QGridLayout>


ChessWindow::ChessWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChessWindow)
{
    ui->setupUi(this);
    //QGridLayout chessBoard;

    //QGridLayout* layout = new QGridLayout();

    //layout->addLayout(chessBoard);




}

ChessWindow::~ChessWindow()
{
   delete ui;
}

void ChessWindow::fonction(int x, int y) {
    cout << "x =  " << x << endl;
    cout << "y =  " << y << endl;
}
