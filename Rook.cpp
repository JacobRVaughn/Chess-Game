#include "pch.h"
#include "Rook.h"

Rook::Rook(String^ _name, ChessPieceType _cp,BoardSpace^ _bs) {
	setName(_name);
	setPiece(_cp);
	setBoardSpace(_bs);
}

Rook::~Rook(void) {
}

bool Rook::isValidMove(SpaceLoc^ currentLoc, SpaceLoc^ proposedLoc)
{
	int colDif = proposedLoc->colProp - currentLoc->colProp;
	int rowDif = proposedLoc->rowProp - currentLoc->rowProp;
	
	if ((colDif == 0) && (rowDif != 0)) {
		return true;
	}
	if ((colDif != 0) && (rowDif == 0)) {
		return true;
	}

	//MessageBox::Show(L"Returning false", L"C", MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation);
	return false;
}