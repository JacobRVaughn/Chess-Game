#include "pch.h"
#include "Queen.h"

Queen::Queen(String^ _name, ChessPieceType _cp, BoardSpace^ _bs) {
	setName(_name);
	setPiece(_cp);
	setBoardSpace(_bs);
}

Queen::~Queen(void) {
}

bool Queen::isValidMove(SpaceLoc^ currentLoc, SpaceLoc^ proposedLoc)
{
	int colDif = proposedLoc->colProp - currentLoc->colProp;
	int rowDif = proposedLoc->rowProp - currentLoc->rowProp;

	if ((colDif == 0) && (rowDif != 0)) {
		return true;
	}
	if ((colDif != 0) && (rowDif == 0)) {
		return true;
	}
	if ((colDif != 0) && (rowDif != 0) && (abs(colDif) == abs(rowDif))) {
		return true;
	}
	return false;
}