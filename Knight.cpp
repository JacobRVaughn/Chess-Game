#include "pch.h"
#include "Knight.h"

Knight::Knight(String^ _name, ChessPieceType _cp, BoardSpace^ _bs) {
	setName(_name);
	setPiece(_cp);
	setBoardSpace(_bs);
}

Knight::~Knight(void) {
}

bool Knight::isValidMove(SpaceLoc^ currentLoc, SpaceLoc^ proposedLoc)
{
	int colDif = proposedLoc->colProp - currentLoc->colProp;
	int rowDif = proposedLoc->rowProp - currentLoc->rowProp;

	if ((abs(colDif) == 1) && abs(rowDif) == 2) {
		return true;
	}
	if ((abs(colDif) == 2) && abs(rowDif) == 1) {
		return true;
	}
	return false;
}