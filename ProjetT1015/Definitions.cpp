/*
* Projet1: Livrable 1
* \file   Definitions.cpp
* \authors Ania Ben Abdesselam (2010925), Vincent Haney (2108812)
* \date   12 avril 2021
* Créé 01 avril 2021
*/

#include "Structures.hpp"

size_t King::kingCount = 0;

Board::Board() {
    for (int xPosition : range(nSquares)) {
        for (int yPosition : range(nSquares)) {
            squares[xPosition][yPosition] = nullptr;
        }
    }
};

void Board::movePiece(Position newPos, Piece* piece) {
    (*piece).board = *this;
    if (piece->isMoveValid(newPos, (*this))) {
        squares[newPos.x][newPos.y] = piece;
        squares[piece->position.x][piece->position.y] = nullptr;
        (*piece).position.x = newPos.x;
        (*piece).position.y = newPos.y;
    }
}

void Board::addPiece(Piece* piece) {
    if ((*this)[(*piece).position] == nullptr) {
        squares[(*piece).position.x][(*piece).position.y] = piece;
    }
    else
    {
        cout << "La position n'est pas valide. Une pièce s'y trouve déjà.";
    }
}

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
    default:
        break;
    }
}


King::King(Position pos, Color col) : Piece(pos, col, kingPieceType) {
    try {
        if (kingCount < 2) {
            kingCount++;
        }
        else
        {
            throw 999;
        }
    }
    catch (int exception) {
        cout << "Error: " << exception << ": Too many kings in your kingdom ;)." <<endl;
        
    }
};
King::~King() {
    --kingCount;
};

bool King::isMoveValid(Position newPos, Board board) {

    int deltaX = newPos.x - position.x;
    int deltaY = newPos.y - position.y;
    bool isPositionValid = (abs(deltaX) == 1) || (abs(deltaY) == 1);

    if (isPositionValid) {
        if (board[newPos] == nullptr) {
            isPieceMoved = true;
            return isPieceMoved;
        }
        else
        {
            impossibleMove(pieceBlock, pieceType);
        }
    }
    else
    {
        impossibleMove(wrongMove, pieceType);
    }
    isPieceMoved = false;
}

Rook::Rook(Position pos, Color col) : Piece(pos, col, rookPieceType) {};

bool Rook::isMoveValid(Position newPos, Board board) {

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
                impossibleMove(pieceBlock, pieceType);
                isPieceMoved = false;
                return isPieceMoved;
            }
        }
        isPieceMoved = true;
        return isPieceMoved;
    }
    else
    {
        impossibleMove(wrongMove, pieceType);
    }
}

Bishop::Bishop(Position pos, Color col) : Piece(pos, col, bishopPieceType) {};

bool Bishop::isMoveValid(Position newPos, Board board) {
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
                impossibleMove(pieceBlock, pieceType);
                isPieceMoved = false;
                return isPieceMoved;
            }
        }
        isPieceMoved = true;
        return isPieceMoved;
    }
    else
    {
        impossibleMove(wrongMove, pieceType);
    }
}

//namespace MovementPieces {
//    Board::movePiece();
//}