#include "pch.h"
#include "Pawn.h"

using namespace System::Windows::Forms;

Pawn::Pawn(String^ _name, ChessPieceType _cp, BoardSpace^ _bs) {
	setName(_name);
	setPiece(_cp);
	setBoardSpace(_bs);
}

Pawn::~Pawn(void) {
}

bool Pawn::isValidMove(SpaceLoc^ currentLoc, SpaceLoc^ proposedLoc)
{
	int colDif = proposedLoc->colProp - currentLoc->colProp;
	int rowDif = proposedLoc->rowProp - currentLoc->rowProp;

	// default to white pawn moves
	int validRowDiff1 = 1;
	int validRowDiff2 = 2;
	if (getCp() == ChessPieceType::BlackPawn) {
		validRowDiff1 = -1;
		validRowDiff2 = -2;
	}

	this->captureMoveProp = false;
	if ((colDif == 0) && (rowDif == validRowDiff1)) {
		return true;
	}
	if ((colDif == 0) && ((rowDif == validRowDiff2) && (this->firstMoveProp))) {
		return true;
	}
	if (((colDif == 1) || (colDif == -1)) && ((rowDif == validRowDiff1))) {
		this->captureMoveProp = true;
		return true;
	}
	return false;
}
