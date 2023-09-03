#pragma once
#include <iostream>
#include <string>
#include "ChessPiece.h"


ref class Queen : public ChessPiece
{

public:
	Queen(String^, ChessPieceType _cp, BoardSpace^ _bs); //This is the constructer 
	~Queen(); //This is the destructor 

	virtual bool isValidMove(SpaceLoc^ currentLoc, SpaceLoc^ proposedLoc) override;
};
