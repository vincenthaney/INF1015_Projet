/*
* Projet1: Livrable 1
* \file   main.cpp
* \authors Ania Ben Abdesselam (2010925), Vincent Haney (2108812)
* \date   12 avril 2021
* Créé 01 avril 2021
*/

#pragma region "Bibliothèques"//{
#pragma once
//#include "Test.cpp"
#include <qapplication.h>
#include "mainwindow.h"
#include "Structures.hpp"
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


#if __has_include("bibliotheque_cours.hpp")
#include "bibliotheque_cours.hpp"
#define BIBLIOTHEQUE_COURS_INCLUS
using bibliotheque_cours::cdbg;
#else
auto& cdbg = clog;
#endif

#if __has_include("verification_allocation.hpp")
#include "verification_allocation.hpp"
#include "debogage_memoire.hpp"  //NOTE: Incompatible avec le "placement new", ne pas utiliser cette entête si vous utilisez ce type de "new" dans les lignes qui suivent cette inclusion.
#endif

void initialiserBibliothequeCours([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
#ifdef BIBLIOTHEQUE_COURS_INCLUS
	bibliotheque_cours::activerCouleursAnsi();  // Permet sous Windows les "ANSI escape code" pour changer de couleurs https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac les supportent normalement par défaut.
#endif
}

using namespace std;
using namespace std::literals;


#pragma endregion//}


int main(int argc, char* argv[]) {
	//::testing::InitGoogleTest(&argc, argv);
	//return RUN_ALL_TESTS();


	Position pos1 = Position(1, 1);
	Position pos2 = Position(1, 2);
	Position pos3 = Position(1, 3);
	Color white = Color::White;
	Color black = Color::Black;

	//King wKing = King(pos1, white);

	//King bKing = King(pos2, black);

	//King nKing = King(pos3, black);

	//King* wKing = King::addKing(pos1, white);

	//King* bKing = King::addKing(pos2, black);

	//King* nKing = King::addKing(pos3, white);



	Board board = Board();

	board.addPiece(ChessPiece::King, pos1, white);
	board.addPiece(ChessPiece::King, pos2, white);
	board.addPiece(ChessPiece::King, pos3, white);

	QApplication a(argc, argv);
	ChessWindow w;
	w.show();
	return a.exec();


}
