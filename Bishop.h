#pragma once
#include <iostream>
#include <string>
#include "ChessPiece.h"


ref class Bishop : public ChessPiece
{

public:
	Bishop(String^, ChessPieceType _cp, BoardSpace^ _bs); //This is the constructer 
	~Bishop(); //This is the destructor 

	virtual bool isValidMove(SpaceLoc^ currentLoc, SpaceLoc^ proposedLoc) override;
};
