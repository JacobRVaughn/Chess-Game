#pragma once
#include <iostream>
#include <string>
#include "ChessPiece.h"


ref class Knight : public ChessPiece
{

public:
	Knight(String^, ChessPieceType _cp, BoardSpace^ _bs); //This is the constructer 
	~Knight(); //This is the destructor 

	virtual bool isValidMove(SpaceLoc^ currentLoc, SpaceLoc^ proposedLoc) override;
};
