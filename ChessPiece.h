#pragma once
#include <iostream>
#include <string>
#include "SpaceLoc.h"
#include "BoardSpace.h"

using namespace System;

enum class ChessPieceType { BlackPawn, BlackKnight, BlackBishop, BlackRook, BlackQueen, BlackKing, WhitePawn, WhiteKnight, WhiteBishop, WhiteRook, WhiteQueen, WhiteKing, Empty };

ref class ChessPiece //abstract class for all chess pieces
{

	String^ name = "";
	ChessPieceType cp = ChessPieceType::Empty;
	BoardSpace^ bs = nullptr;
	Boolean captured = false;

public:

	void setPiece(ChessPieceType cp_) {
		cp = cp_;
	}

	void setName(String^ name_) {
		name = name_;
	}

	void setBoardSpace(BoardSpace^ bs_) {
		bs = bs_;
	}

	property Boolean capturedProp {
		Boolean get() {
			return captured;
		}
		void set(Boolean capturedProp_) {
			captured = capturedProp_;
		}
	}
	property BoardSpace^ bsProp {
		BoardSpace^ get() {
			return bs;
		}
		void set(BoardSpace^ bsProp_) {
			bs = bsProp_;
		}
	}

	String^ getName() {
		return name;
	}
	ChessPieceType getCp() {
		return cp;
	}

	virtual bool isValidMove(SpaceLoc^ currentLoc, SpaceLoc^ proposedLoc) {
		return false;
	}; // pure virtual function
};