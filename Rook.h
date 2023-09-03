#pragma once
#include <iostream>
#include <string>
#include "ChessPiece.h"


ref class Rook : public ChessPiece
{

public:
	Rook(String^, ChessPieceType _cp,BoardSpace^ _bs); //This is the constructer 
	~Rook(); //This is the destructor 

	virtual bool isValidMove(SpaceLoc^ currentLoc, SpaceLoc^ proposedLoc) override;
};
