/*
* Projet1: Livrable 1
* \file   Definitions.cpp
* \authors Ania Ben Abdesselam (2010925), Vincent Haney (2108812)
* \date   12 avril 2021
* Créé 01 avril 2021
*/

#include "Structures.h"

int King::kingCount = 0;


void Board::movePiece(Position newPos, Piece* piece) {
    Position initPos = piece->position;
    if (piece->isMoveValid(newPos, (*this))) {
        delete squares[newPos.x][newPos.y];
        squares[newPos.x][newPos.y] = piece;
        squares[piece->position.x][piece->position.y] = nullptr;
        piece->position = newPos;
        if (isKingCheck(piece->color).first) {
            squares[initPos.x][initPos.y] = piece;
            squares[newPos.x][newPos.y] = nullptr;
            piece->impossibleMove(Piece::ImpossibleMoves::checkedKing,'K');
            piece->position = initPos;
        }
        piece->isTest = false;
    }
    if (!(piece->position == initPos)) {
        cout << "Move successful" << endl;
    }
}


void Board::addPiece(ChessPiece piece, Position pos, Color col) {
    switch (piece) {
        case ChessPiece::King:
            try {
                if (King::kingCount < 2) {
                    King* king = new King(pos, col);
                    this->addPieceBoard(king);
                }
                else
                {
                    throw 69;
                }
            }
            catch (int exception) {
                cout << "Error: " << exception << ": Too many kings in your kingdom ;)." << endl;
            }
            break;

        case ChessPiece::Bishop:
            {
                Bishop* bishop = new Bishop(pos, col);
                this->addPieceBoard(bishop); 
            }
            break;

        case ChessPiece::Rook:
            {
                Rook* rook = new Rook(pos, col);
                this->addPieceBoard(rook);
            }
            break;
    }
};


void Board::addPieceBoard(Piece* piece) {

    if ((*this)[(*piece).position] == nullptr) {
        squares[(*piece).position.x][(*piece).position.y] = piece;
    }
    else
    {
        cout << "La position n'est pas valide. Une pièce s'y trouve déjà.";
    }
}


vector<pair<Position, Color>> Board::hasKings() {
    vector<pair<Position,Color>> tempVect;
    for (int i : range(nSquares)) {
        for (int j : range(nSquares)) {
            if (dynamic_cast<King*>(squares[i][j]) != NULL) {
                Position posTemp = Position(i, j);
                Color colorTemp = squares[i][j]->color;
                pair tempPair(posTemp, colorTemp);
                tempVect.push_back(tempPair);
            }
        }
    }
    return tempVect;
}


pair<bool,bool> Board::isKingCheck(Color pieceColor) {
    vector<pair<Position, Color>> kingPosVect = hasKings();
    pair<bool, bool> tempPair(false, false);
    if ( kingPosVect.size() > 0) {
        for (int k : range(kingPosVect.size())) {
            for (int i : range(nSquares)) {
                for (int j : range(nSquares)) {
                    bool isKingPos = (kingPosVect[k].first.x == i && kingPosVect[k].first.y == j);
                    if (!isKingPos) {
                        if (squares[i][j] != nullptr) {
                            squares[i][j]->isTest = true;
                            if ((squares[i][j]->isMoveValid(kingPosVect[k].first, (*this)))) {
                                if(squares[i][j]->color != kingPosVect[k].second){
                                    if(kingPosVect[k].second != pieceColor)
                                    tempPair.second = true;
                                    else {
                                        tempPair.first = true;
                                        return tempPair;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return tempPair;

    
}


Piece* Board::getPiece(Position pos) {
    return this->squares[pos.x][pos.y];
};


Piece::Piece(Position pos, Color col, char pType) : color(col), position(pos), pieceType(pType) {};


void Piece::impossibleMove(ImpossibleMoves imposMove, char pieceType) {
    switch (imposMove) {
    case wrongMove:
        cout << "This move is not legal." << endl;
        break;
    case pieceBlock:
        cout << "A piece is blocking the way." << endl;
        break;
    case pieceAlreadyThere:
        cout << "A piece is already at the given destination." << endl;
        break;
    case checkedKing:
        cout << "Cannot move there. Your king would be in check." << endl;
        break;
    default:
        break;
    }
}


King::King(Position pos, Color col) : Piece(pos, col, pieceType) {
    kingCount++;
};


King::~King() {
    --kingCount;
};


bool King::isMoveValid(Position newPos, Board& board) {


    int deltaX = newPos.x - position.x;
    int deltaY = newPos.y - position.y;
    bool isPositionValid = (abs(deltaX) == 1) || (abs(deltaY) == 1);

    if (!isPositionValid) {
        if (board[newPos] == nullptr) {
            isPieceMoved = true;
            return isPieceMoved;
        }
        else
        {
        
            if (board[newPos]->color != color) {
                isPieceMoved = true;
            }
            if (isTest == false) {
                impossibleMove(pieceBlock, pieceType);
            }
        }
    }
    else
    {
        impossibleMove(wrongMove, pieceType);
    }


    isPieceMoved = false;
}
char King::getPieceType() {
    return pieceType;
}

Rook::Rook(Position pos, Color col) : Piece(pos, col, rookPieceType) {};


bool Rook::isMoveValid(Position newPos, Board& board) {

    int deltaX = newPos.x - position.x;
    int deltaY = newPos.y - position.y;
    int iterX = 0;
    int iterY = 0;

    int iterStart;
    int iterEnd;

    Position startPosition = position;

    bool isPositionValid = (abs(deltaX) == 0) ^ (abs(deltaY) == 0);
    if (isPositionValid) {
        if (abs(deltaX) == 0) {
            if (newPos.y > position.y) {
                iterStart = position.y;
                iterEnd = newPos.y;
                iterX = 0;
                iterY = 1;
            }
            else
            {
                iterStart = newPos.y;
                iterEnd = position.y;
                iterX = 0;
                iterY = -1;
            }
        }
        else
        {
            if (newPos.x > position.x) {
                iterStart = position.x;
                iterEnd = newPos.x;
                iterX = 1;
                iterY = 0;
            }
            else
            {
                iterStart = newPos.x;
                iterEnd = position.x;
                iterX = -1;
                iterY = 0;
            }
        }
        for (iterStart; iterStart <= iterEnd; iterStart++) {
            startPosition.x += iterX;
            startPosition.y += iterY;
            
            if (board[startPosition] != nullptr) {
                bool isEnemyPieceAtEndPos = (iterStart == iterEnd) && (board[startPosition]->color != color);
                if (isEnemyPieceAtEndPos) {
                    isPieceMoved = true;
                }
                if (isTest == false) {
                    impossibleMove(pieceBlock, pieceType);
                    isPieceMoved = false;
                    return isPieceMoved;
                }
                isPieceMoved = false;
                return isPieceMoved;
            }
        }
    }
    else
    {
        impossibleMove(wrongMove, pieceType);
    }
}

char Bishop::getPieceType() {
    return pieceType;
}

Bishop::Bishop(Position pos, Color col) : Piece(pos, col, bishopPieceType) {};

bool Bishop::isMoveValid(Position newPos, Board& board) {
    int deltaX = newPos.x - position.x;
    int deltaY = newPos.y - position.y;

    int iterX = 0;
    int iterY = 0;

    int iterStart = position.x;
    int iterEnd = newPos.x;

    Position startPosition = position;

    bool isPositionValid = (abs(deltaX) == abs(deltaY)) && (abs(deltaX) >= 1);
    if (isPositionValid) {
        if (newPos.x > position.x) {
            if (newPos.y > position.y) {
                iterX = 1;
                iterY = 1;
            }
            else
            {
                iterX = 1;
                iterY = -1;
            }
        }
        else
        {
            if (newPos.y > position.y) {
                iterX = -1;
                iterY = 1;
            }
            else
            {
                iterX = -1;
                iterY = -1;
            }
        }
        for (iterStart; iterStart <= iterEnd; iterStart++) {
            startPosition.x += iterX;
            startPosition.y += iterY;
            if (board[startPosition] != nullptr) {
                bool isEnemyPieceAtEndPos = (iterStart == iterEnd) && (board[startPosition]->color != color);
                if (isEnemyPieceAtEndPos) {
                    isPieceMoved = true;
                }
                if (isTest == false) {
                    impossibleMove(pieceBlock, pieceType);
                    isPieceMoved = false;
                    return isPieceMoved;
                }
                isPieceMoved = false;
                return isPieceMoved;
            }
        }
        isPieceMoved = true;
        return isPieceMoved;
    }
    else
    {
        if (isTest == false) {
            impossibleMove(wrongMove, pieceType);
            isPieceMoved = false;
            return isPieceMoved;
        }
        isPieceMoved = false;
        return isPieceMoved;
    }
}

char Rook::getPieceType() {
    return pieceType;
}

//namespace MovementPieces {
//    Board::movePiece();
//}