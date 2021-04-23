/*
* Projet1: Livrable 1
* \file   Structures.hpp
* \authors Ania Ben Abdesselam (2010925), Vincent Haney (2108812)
* \date   12 avril 2021
* Créé 01 mars 2021
*/

#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <gsl/span>
#include <cppitertools/range.hpp>
#include <cppitertools/enumerate.hpp>
#include <utility>
#include <qapplication.h>
#include <QGridLayout>
#include <vector>
#include <iterator>


using namespace std;
using namespace std::literals;
using namespace iter;
using namespace gsl;


class Piece;

const int nSquares = 8;
const int NUMBER_OF_EXCEPTIONS = 1;

enum class Color { Black, White};

enum class ChessPiece { King, Rook, Bishop };


struct Position {
    uint8_t x;
    uint8_t y;
    Position() = default;
    Position(uint8_t posX, uint8_t posY) {

        bool isPositionValid = (0 <= posX) && (posX < 8) && (0 <= posY) && (posY < 8);

        if (isPositionValid) {
            x = posX;
            y = posY;
        }
        else
        {
            cout << "La case (" << posX << ", " << posY << ") n'existe pas" << endl;
        }
    };
    ~Position() = default;

    bool operator==(const Position& pos) const {
        if ((this->x == pos.x) && (this->y == pos.y)) {
            return true;
        }
        else {
            return false;
        }
    }

};


class Board:public QObject
{
    Q_OBJECT
public:
    //Board();
    //Board(const Board& board);
    //~Board();


    Board() {
        for (int xPosition : range(nSquares)) {
            for (int yPosition : range(nSquares)) {
                squares[xPosition][yPosition] = nullptr;
            }
        }
    };


    Board(const Board& board) {
        for (int xPosition : range(nSquares)) {
            for (int yPosition : range(nSquares)) {
                squares[xPosition][yPosition] = board.squares[xPosition][yPosition];
            }
        }
    }


    ~Board() {
        for (int xPosition : range(nSquares)) {
            for (int yPosition : range(nSquares)) {
                if (squares[xPosition][yPosition] != nullptr) {
                    delete squares[xPosition][yPosition];
                    squares[xPosition][yPosition] = nullptr;
                }
            }
        }
    }


    Piece* squares[nSquares][nSquares];
    void movePiece(Position newPos, Piece* piece);
    pair<bool, bool>  isKingCheck(Color col);
    void addPieceBoard(Piece* piece);
    void addPiece(ChessPiece piece, Position pos, Color col);
    vector<pair<Position, Color>> hasKings();
    Piece* getPiece(Position pos);
    Piece* operator[](Position position) {
        return squares[position.x][position.y];
    };

};


class Piece: public QObject
{
    Q_OBJECT
public:
    Color color;
    Position position;
    char pieceType = '%';
    bool isPieceMoved = false;
    bool isTest = false;

    Piece(Position pos, Color col, char pType);

    enum ImpossibleMoves { wrongMove, pieceBlock, pieceAlreadyThere, checkedKing };
    void impossibleMove(ImpossibleMoves imposMove, char pieceType);
    virtual char getPieceType() = 0;
    virtual bool isMoveValid(Position newPos, Board& board) = 0;
    virtual ~Piece()=default;

};


class King :public Piece
{
public:
    const char pieceType = 'K';
    ~King();
    static int kingCount;
    //bool isKingCheck = false;
    bool isMoveValid(Position newPos, Board& board) override;
    char getPieceType() override;

    friend Board;
private:
    King(Position pos, Color col);
};


//class Queen :public Piece
//{
//public:
//    const char queenPieceType = 'Q';
//    Queen(Position pos, Color col) : Piece(pos, col, queenPieceType) {};
//    ~Queen() = default;
//};


class Rook :public Piece
{
public:
    const char rookPieceType = 'R';
    Rook(Position pos, Color col);
    ~Rook() = default;
    char getPieceType() override;
    bool isMoveValid(Position newPos, Board& board) override;
};


//class Knight :public Piece
//{
//public:
//    const char knightPieceType = 'N';
//    Knight(Position pos, Color col) : Piece(pos, col, knightPieceType) {};
//    ~Knight() = default;
//    void move(Position newPos) override {
//
//    }
//};


class Bishop :public Piece
{
public:
    const char bishopPieceType = 'B';
    Bishop(Position pos, Color col);
    ~Bishop() = default;
    char getPieceType() override;
    bool isMoveValid(Position newPos, Board& board) override;
};


//class Pawn :public Piece
//{
//public:
//    const char pawnPieceType = 'P';
//    Pawn(Position pos, Color col) : Piece(pos, col, pawnPieceType) {};
//    ~Pawn() = default;
//    void move(Position newPos) override {
//
//    }
//};






