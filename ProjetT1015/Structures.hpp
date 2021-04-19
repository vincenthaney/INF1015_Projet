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

using namespace std;
using namespace std::literals;
using namespace iter;
using namespace gsl;


class Piece;

const int nSquares = 8;
const int NUMBER_OF_EXCEPTIONS = 1;

enum class Color { Black, White };

enum class ChessPiece {King, Rook, Bishop};


struct Position {
    int x;
    int y;
    Position() = default;
    Position(int posX, int posY) {

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

};


class Board
{
public:
    Board();
    ~Board() = default;
    Piece* squares[nSquares][nSquares];
    void movePiece(Position newPos, Piece* piece);
    void addPieceBoard(Piece* piece);
    void addPiece(ChessPiece piece, Position pos, Color col);
    Piece* operator[](Position position) {
        return squares[position.x][position.y];
    };
};


class Piece
{
public:
    Color color;
    Position position;
    char pieceType = '%';
    Board board;
    bool isPieceMoved = false;
    Piece(Position pos, Color col, char pType);

    enum ImpossibleMoves { wrongMove, pieceBlock, pieceAlreadyThere };

    void impossibleMove(ImpossibleMoves imposMove, char pieceType);

    virtual bool isMoveValid(Position newPos, Board board) = 0;
    virtual ~Piece() = default;
  
};


class King :public Piece
{
public:
    const char kingPieceType = 'K';

    ~King();
    static int kingCount;
    bool isMoveValid(Position newPos, Board board) override;
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
    bool isMoveValid(Position newPos, Board board) override;
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
    bool isMoveValid(Position newPos, Board board) override;
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





