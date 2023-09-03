#include "pch.h"
#include "King.h"

King::King(String^ _name, ChessPieceType _cp, BoardSpace^ _bs) {
	setName(_name);
	setPiece(_cp);
	setBoardSpace(_bs);
}

King::~King(void) {

}

bool King::isValidMove(SpaceLoc^ currentLoc, SpaceLoc^ proposedLoc)
{
	int colDif = proposedLoc->colProp - currentLoc->colProp;
	int rowDif = proposedLoc->rowProp - currentLoc->rowProp;

	if ((colDif == 0) && (rowDif != 0) && ((abs(rowDif) <= 1))) {
		return true;
	}
	if ((colDif != 0) && (rowDif == 0) && ((abs(colDif) <= 1))) {
		return true;
	}
	if ((colDif != 0) && (rowDif != 0) && ((abs(colDif) <= 1)) && ((abs(rowDif) <= 1))) {
		return true;
	}
	return false;
}