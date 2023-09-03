#pragma once
#include <iostream>
#include <string>
#include "ChessPiece.h"


ref class King : public ChessPiece
{

public:
	King(String^, ChessPieceType _cp, BoardSpace^ _bs); //This is the constructer 
	~King(); //This is the destructor 

	virtual bool isValidMove(SpaceLoc^ currentLoc, SpaceLoc^ proposedLoc) override;
};

