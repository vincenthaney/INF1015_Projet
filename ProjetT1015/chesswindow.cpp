
#include "chesswindow.h"
#include "ui_chesswindow.h"


ChessGameWindow::ChessGameWindow(Board& chessBoard, QWidget* parent)
    : QMainWindow(parent), uiChessBoard(chessBoard)
{

    ui.setupUi(this);

    bool connectMouse = connect(this, SIGNAL(clickedSignal(int, int)), this, SLOT(squareClickedPosition(int, int)));
    Q_ASSERT(connectMouse);//fait tout chier si connection est pourrie
}

ChessGameWindow::~ChessGameWindow(){}

