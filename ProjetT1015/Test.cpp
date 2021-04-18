/*
* Projet1: Livrable 1
* \file   Test.hpp
* \authors Ania Ben Abdesselam (2010925), Vincent Haney (2108812)
* \date   12 avril 2021
* Créé 01 mars 2021
*/

#include "Structures.hpp"
#if __has_include("gtest/gtest.h")
#include "gtest/gtest.h"
#endif
#ifdef TEST

TEST(Tests, Roi) {

	//Tests Roi
	Position posInit1 = Position(1, 1);
	Position posFinal1= Position(0, 0);
	Color col = Color::Black;
	King king1 = King(posInit1, col);
	Board board1 = Board();
	board1.addPiece(&king1);
	board1.movePiece(posFinal1, &king1);
	EXPECT_EQ(king1.isPieceMoved, true);

	Position posInit2 = Position(1, 1);
	Position posFinal2 = Position(0, 1);
	King king2 = King(posInit2, col);
	Board board2 = Board();
	board2.addPiece(&king2);
	board2.movePiece(posFinal2, &king2);
	EXPECT_EQ(king2.isPieceMoved, true);

	Position posInit3 = Position(1, 1);
	Position posFinal3 = Position(0, 2);
	King king3 = King(posInit3, col);
	Board board3 = Board();
	board3.addPiece(&king3);
	board3.movePiece(posFinal3, &king3);
	EXPECT_EQ(king3.isPieceMoved, true);

	Position posInit4 = Position(1, 1);
	Position posFinal4 = Position(2, 0);
	King king4 = King(posInit4, col);
	Board board4 = Board();
	board4.addPiece(&king4);
	board4.movePiece(posFinal4, &king4);
	EXPECT_EQ(king4.isPieceMoved, true);

	Position posInit5 = Position(1, 1);
	Position posFinal5 = Position(2, 1);
	King king5 = King(posInit5, col);
	Board board5 = Board();
	board5.addPiece(&king5);
	board5.movePiece(posFinal5, &king5);
	EXPECT_EQ(king5.isPieceMoved, true);

	Position posInit6 = Position(1, 1);
	Position posFinal6 = Position(2, 2);
	King king6 = King(posInit6, col);
	Board board6 = Board();
	board6.addPiece(&king6);
	board6.movePiece(posFinal6, &king6);
	EXPECT_EQ(king6.isPieceMoved, true);

	Position posInit7 = Position(1, 1);
	Position posFinal7 = Position(1, 2);
	King king7 = King(posInit7, col);
	Board board7 = Board();
	board7.addPiece(&king7);
	board7.movePiece(posFinal7, &king7);
	EXPECT_EQ(king7.isPieceMoved, true);

	Position posInit8 = Position(1, 1);
	Position posFinal8 = Position(1, 0);
	King king8 = King(posInit8, col);
	Board board8 = Board();
	board8.addPiece(&king8);
	board8.movePiece(posFinal8, &king8);
	EXPECT_EQ(king8.isPieceMoved, true);


}
TEST(Tests, Fou) {

	//Tests Fou
	Position posInit = Position(4, 4);
	Position posFinal = Position(0, 0);
	Color col = Color::White;
	Bishop bishop = Bishop(posInit, col);
	Board board = Board();
	board.addPiece(&bishop);
	board.movePiece(posFinal, &bishop);
	EXPECT_EQ(bishop.isPieceMoved, true);


	Position posInit1 = Position(4, 4);
	Position posFinal1 = Position(6, 6);
	Bishop bishop1 = Bishop(posInit, col);
	Board board1 = Board();
	board1.addPiece(&bishop1);
	board1.movePiece(posFinal1, &bishop1);
	EXPECT_EQ(bishop1.isPieceMoved, true);


	Position posInit2 = Position(4, 4);
	Position posFinal2 = Position(2, 6);
	Bishop bishop2 = Bishop(posInit, col);
	Board board2 = Board();
	board2.addPiece(&bishop2);
	board2.movePiece(posFinal2, &bishop2);
	EXPECT_EQ(bishop2.isPieceMoved, true);


	Position posInit3 = Position(4, 4);
	Position posFinal3 = Position(1, 7);
	Bishop bishop3 = Bishop(posInit, col);
	Board board3 = Board();
	board3.addPiece(&bishop3);
	board3.movePiece(posFinal3, &bishop3);
	EXPECT_EQ(bishop3.isPieceMoved, true);

	Position posInit4 = Position(4, 4);
	Position posFinal4 = Position(7, 4);
	Bishop bishop4 = Bishop(posInit, col);
	Board board4 = Board();
	board4.addPiece(&bishop4);
	board4.movePiece(posFinal4, &bishop4);
	EXPECT_EQ(bishop4.isPieceMoved, false);

	Position posInit5 = Position(4, 4);
	Position posFinal5 = Position(6, 1);
	Bishop bishop5 = Bishop(posInit, col);
	Board board5 = Board();
	board5.addPiece(&bishop5);
	board5.movePiece(posFinal5, &bishop5);
	EXPECT_EQ(bishop5.isPieceMoved, false);
}

TEST(Tests, Tour) {

	Position posInit = Position(4, 4);
	Position posFinal = Position(4, 7);
	Color col = Color::White;
	Rook rook = Rook(posInit, col);
	Board board = Board();
	board.addPiece(&rook);
	board.movePiece(posFinal, &rook);
	EXPECT_EQ(rook.isPieceMoved, true);

	Position posInit1 = Position(4, 4);
	Position posFinal1 = Position(7, 4);
	Rook rook1 = Rook(posInit1, col);
	Board board1 = Board();
	board1.addPiece(&rook1);
	board1.movePiece(posFinal1, &rook1);
	EXPECT_EQ(rook1.isPieceMoved, true);

	Position posInit2 = Position(4, 4);
	Position posFinal2 = Position(4, 0);
	Rook rook2 = Rook(posInit1, col);
	Board board2 = Board();
	board2.addPiece(&rook2);
	board2.movePiece(posFinal2, &rook2);
	EXPECT_EQ(rook2.isPieceMoved, true);

	Position posInit3 = Position(4, 4);
	Position posFinal3 = Position(1, 4);
	Rook rook3 = Rook(posInit3, col);
	Board board3 = Board();
	board3.addPiece(&rook3);
	board3.movePiece(posFinal3, &rook3);
	EXPECT_EQ(rook3.isPieceMoved, true);

	Position posInit4 = Position(4, 4);
	Position posFinal4 = Position(4, 7);
	Rook rook4 = Rook(posInit4, col);
	Board board4 = Board();
	board4.addPiece(&rook4);
	board4.movePiece(posFinal4, &rook4);
	EXPECT_EQ(rook4.isPieceMoved, true);

	Position posInit5 = Position(4, 4);
	Position posFinal5 = Position(0, 0);
	Rook rook5 = Rook(posInit5, col);
	Board board5 = Board();
	board5.addPiece(&rook5);
	board5.movePiece(posFinal5, &rook5);
	EXPECT_EQ(rook5.isPieceMoved, false);

	Position posInit6 = Position(4, 4);
	Position posFinal6 = Position(1, 7);
	Rook rook6 = Rook(posInit6, col);
	Board board6 = Board();
	board6.addPiece(&rook6);
	board6.movePiece(posFinal6, &rook6);
	EXPECT_EQ(rook6.isPieceMoved, false);

}

//TEST(Calc, operations) {
//	
//	EXPECT_EQ(calc.obtenirValeur(), 143 + 218);
//	EXPECT_EQ(calc.obtenirValeur(), 143 - 218);
//}
//
//TEST(Calc, changement_operation) {
//	
//	EXPECT_EQ(calc.obtenirValeur(), 143 - 218);
//	EXPECT_EQ(calc.obtenirValeur(), 143 + 218);
//}

#endif