#pragma once

#include "BoardSpace.h"
#include "ActivePlayer.h"
#include "ChessPiece.h"
#include "ChessBoardLogger.h"

#define CHESS_BOARD_COLS 8
#define CHESS_BOARD_ROWS 8
#define MAX_NUM_PIECES 16

using namespace System;
using namespace System::IO;

ref class ChessBoardMgr
{
private:
	ChessBoardLogger^ logger = gcnew ChessBoardLogger();
	array<array<BoardSpace^>^> ^ spaces  = gcnew array<array<BoardSpace^>^>(CHESS_BOARD_COLS);
	ActivePlayer aPlayer = ActivePlayer::White;
	array<ChessPiece^>^ wPieces = gcnew array<ChessPiece^>(MAX_NUM_PIECES);
	array<ChessPiece^>^ bPieces = gcnew array<ChessPiece^>(MAX_NUM_PIECES);
	TextBox^ tBMoves;
	int iMoves = 0;

public:
	ChessBoardMgr(); //This is the constructer 
	~ChessBoardMgr(); //This is the destructor 
	void init(TextBox^ loggerTextBox, TextBox^ movesTextBox);
	void log(String^ data);

	//property ActivePlayer get_ActivePlayer;

	property TextBox^ movesTextBoxProp {
		TextBox^ get() {
			return tBMoves;
		}
		void set(TextBox^ movesTextBox_) {
			tBMoves = movesTextBox_;
		}
	}

	property int iMovesProp {
		int get() {
			return iMoves;
		}
		void set(int iMoves_) {
			iMoves = iMoves_;
		}
	}
	property array<ChessPiece^>^ arrayNonActivePiecesProp {
		array<ChessPiece^>^ get() {
			return (aPlayer == ActivePlayer::White) ? bPieces : wPieces;
		}
	}
	property ActivePlayer activeColorPlayer {
		ActivePlayer get() {
			return aPlayer;
		}
		void set(ActivePlayer ap) {
			aPlayer = ap;
		}
	}
	bool isActiveColor(String^ name);
	bool isValidMove(SpaceLoc^ currentLoc, SpaceLoc^ proposedLoc);
	bool ChessBoardMgr::isPathOccuppied(SpaceLoc^ currentLoc, SpaceLoc^ proposedLoc);
	bool ChessBoardMgr::validateMove(ChessPiece^ piece, SpaceLoc^ currentLoc, SpaceLoc^ proposedLoc);
	bool ChessBoardMgr::colorCheck(BoardSpace^ proposedBS);
	ChessPiece^ ChessBoardMgr::findKing(array<ChessPiece^>^ pieces, String^ kingName);
	ChessPiece^ ChessBoardMgr::getSelectedPiece(array<ChessPiece^>^ pieces, BoardSpace^ bs);
	bool ChessBoardMgr::pawnCaptureCheck(ChessPiece^ cp, BoardSpace^ bs);
	bool ChessBoardMgr::kingMoveCheck(ChessPiece^ cp, array<ChessPiece^>^ capturePieces, SpaceLoc^ proposedLoc);
	bool ChessBoardMgr::attackKingCheck(BoardSpace^ bs, ChessPiece^ king, BoardSpace^ kingBS,
		ChessPiece^ cp, array<ChessPiece^>^ capturePieces, SpaceLoc^ proposedLoc);
	void ChessBoardMgr::markPieceCaptured(BoardSpace^ bs, array<ChessPiece^>^ capturePieces);
	void ChessBoardMgr::setPawnFirstMove(ChessPiece^ cp);
};



