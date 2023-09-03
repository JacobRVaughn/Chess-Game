#include "pch.h"
#include "Bishop.h"

Bishop::Bishop(String^ _name, ChessPieceType _cp, BoardSpace^ _bs) {
	setName(_name);
	setPiece(_cp);
	setBoardSpace(_bs);
}

Bishop::~Bishop(void) {
}

bool Bishop::isValidMove(SpaceLoc^ currentLoc, SpaceLoc^ proposedLoc)
{
	int colDif = proposedLoc->colProp - currentLoc->colProp;
	int rowDif = proposedLoc->rowProp - currentLoc->rowProp;

	if ((colDif != 0) && (rowDif != 0) && (abs(colDif) == abs(rowDif))) {
		return true;
	}
	return false;
}