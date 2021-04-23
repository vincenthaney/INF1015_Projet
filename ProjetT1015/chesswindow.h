#ifndef CHESSWINDOW_H
#define CHESSWINDOW_H

#pragma once
#include <QMainWindow>
#include <QMouseEvent>
#include "ui_chesswindow.h"
#include <QEvent>
#include "Structures.h"


QT_BEGIN_NAMESPACE
namespace Ui { class ChessWindow; }
QT_END_NAMESPACE

class ChessGameWindow : public QMainWindow
{
    Q_OBJECT

public:
    ChessGameWindow(Board& chessBoard, QWidget *parent = Q_NULLPTR);
    ~ChessGameWindow();

   //vctor<QLabel*> piecesVect = ;

	void mousePressEvent(QMouseEvent* mouseEvent)
	{

			isFirstClick = !isFirstClick;

			//if (isFirstClick)
			//	ui.wKing->setText("First click in : (" + QString::number(mouseEvent->x()) + ", " + QString::number(mouseEvent->y()) + ")");
   //             //ui.GROS_LABEL->setText("Second click in : (" + QString::number(mouseEvent->x()) + ", " + QString::number(mouseEvent->y()) + ")");
		

			emit clickedSignal(mouseEvent->x(), mouseEvent->y());
		
	}


signals:
    void clickedSignal(int x, int y);

public slots:
    
    void squareClickedPosition(int xMousePos, int yMousePos) {
       
    }


private:

    bool isFirstClick = false;

    Ui::ChessWindow ui;
    Board uiChessBoard;
};
#endif // CHESSWINDOW_H
