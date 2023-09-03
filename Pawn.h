#pragma once
#include <iostream>
#include <string>
#include "ChessPiece.h"


ref class Pawn : public ChessPiece
{
	bool firstMove = true;
	bool captureMove = false;

public:
	Pawn(String^, ChessPieceType _cp, BoardSpace^ _bs); //This is the constructer 
	~Pawn(); //This is the destructor 


	property bool firstMoveProp {
		bool get() {
			return firstMove;
		}
		void set(bool firstMove_) {
			firstMove = firstMove_;
		}
	}
	property bool captureMoveProp {
		bool get() {
			return captureMove;
		}
		void set(bool captureMove_) {
			captureMove = captureMove_;
		}
	}

	virtual bool isValidMove(SpaceLoc^ currentLoc, SpaceLoc^ proposedLoc) override;
};

