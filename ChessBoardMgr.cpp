#include "pch.h"
#include "ChessBoardMgr.h"
#include "ChessPiece.h"
#include "wchar.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"

using namespace System::IO;
using namespace System::Runtime::InteropServices;
using namespace System::Windows::Forms;

ChessBoardMgr::ChessBoardMgr() {
	char colName = SPACE_COL_A;
	char rowName = SPACE_ROW_1;

	//create all spaces of the chessboards
	for (int column = 0; column < CHESS_BOARD_COLS; column++) {
		rowName = '1';
		spaces[column] = gcnew array< BoardSpace^>(CHESS_BOARD_ROWS);
		for (int row = 0; row < CHESS_BOARD_ROWS; row++) {
			spaces[column][row] = gcnew BoardSpace(colName,rowName);
			rowName += 1;
		}
		colName += 1;
	}
	
	//create white pieces
	wPieces[0] = gcnew Pawn("WhitePawn1", ChessPieceType::WhitePawn, spaces[SpaceColAIndex][SpaceRow2Index]);
	wPieces[1] = gcnew Pawn("WhitePawn2", ChessPieceType::WhitePawn, spaces[SpaceColBIndex][SpaceRow2Index]);
	wPieces[2] = gcnew Pawn("WhitePawn3", ChessPieceType::WhitePawn, spaces[SpaceColCIndex][SpaceRow2Index]);
	wPieces[3] = gcnew Pawn("WhitePawn4", ChessPieceType::WhitePawn, spaces[SpaceColDIndex][SpaceRow2Index]);
	wPieces[4] = gcnew Pawn("WhitePawn5", ChessPieceType::WhitePawn, spaces[SpaceColEIndex][SpaceRow2Index]);
	wPieces[5] = gcnew Pawn("WhitePawn6", ChessPieceType::WhitePawn, spaces[SpaceColFIndex][SpaceRow2Index]);
	wPieces[6] = gcnew Pawn("WhitePawn7", ChessPieceType::WhitePawn, spaces[SpaceColGIndex][SpaceRow2Index]);
	wPieces[7] = gcnew Pawn("WhitePawn8", ChessPieceType::WhitePawn, spaces[SpaceColHIndex][SpaceRow2Index]);
	wPieces[8] = gcnew Rook("WhiteRook1", ChessPieceType::WhiteRook, spaces[SpaceColAIndex][SpaceRow1Index]);
	wPieces[9] = gcnew Rook("WhiteRook2", ChessPieceType::WhiteRook, spaces[SpaceColHIndex][SpaceRow1Index]);
	wPieces[10] = gcnew Bishop("WhiteBishop1", ChessPieceType::WhiteBishop, spaces[SpaceColCIndex][SpaceRow1Index]);
	wPieces[11] = gcnew Bishop("WhiteBishop2", ChessPieceType::WhiteBishop, spaces[SpaceColFIndex][SpaceRow1Index]);
	wPieces[12] = gcnew King("WhiteKing", ChessPieceType::WhiteKing, spaces[SpaceColEIndex][SpaceRow1Index]);
	wPieces[13] = gcnew Queen("WhiteQueen", ChessPieceType::WhiteQueen, spaces[SpaceColDIndex][SpaceRow1Index]);
	wPieces[14] = gcnew Knight("WhiteKnight1", ChessPieceType::WhiteKnight, spaces[SpaceColBIndex][SpaceRow1Index]);
	wPieces[15] = gcnew Knight("WhiteKnight2", ChessPieceType::WhiteKnight, spaces[SpaceColGIndex][SpaceRow1Index]);
	//create black pieces
	bPieces[0] = gcnew Pawn("BlackPawn1", ChessPieceType::BlackPawn, spaces[SpaceColAIndex][SpaceRow7Index]);
	bPieces[1] = gcnew Pawn("BlackPawn2", ChessPieceType::BlackPawn, spaces[SpaceColBIndex][SpaceRow7Index]);
	bPieces[2] = gcnew Pawn("BlackPawn3", ChessPieceType::BlackPawn, spaces[SpaceColCIndex][SpaceRow7Index]);
	bPieces[3] = gcnew Pawn("BlackPawn4", ChessPieceType::BlackPawn, spaces[SpaceColDIndex][SpaceRow7Index]);
	bPieces[4] = gcnew Pawn("BlackPawn5", ChessPieceType::BlackPawn, spaces[SpaceColEIndex][SpaceRow7Index]);
	bPieces[5] = gcnew Pawn("BlackPawn6", ChessPieceType::BlackPawn, spaces[SpaceColFIndex][SpaceRow7Index]);
	bPieces[6] = gcnew Pawn("BlackPawn7", ChessPieceType::BlackPawn, spaces[SpaceColGIndex][SpaceRow7Index]);
	bPieces[7] = gcnew Pawn("BlackPawn8", ChessPieceType::BlackPawn, spaces[SpaceColHIndex][SpaceRow7Index]);
	bPieces[8] = gcnew Rook("BlackRook1", ChessPieceType::BlackRook, spaces[SpaceColAIndex][SpaceRow8Index]);
	bPieces[9] = gcnew Rook("BlackRook2", ChessPieceType::BlackRook, spaces[SpaceColHIndex][SpaceRow8Index]);
	bPieces[10] = gcnew Bishop("BlackBishop1", ChessPieceType::BlackBishop, spaces[SpaceColCIndex][SpaceRow8Index]);
	bPieces[11] = gcnew Bishop("BlackBishop2", ChessPieceType::BlackBishop, spaces[SpaceColFIndex][SpaceRow8Index]);
	bPieces[12] = gcnew King("BlackKing", ChessPieceType::BlackKing, spaces[SpaceColEIndex][SpaceRow8Index]);
	bPieces[13] = gcnew Queen("BlackQueen", ChessPieceType::BlackQueen, spaces[SpaceColDIndex][SpaceRow8Index]);
	bPieces[14] = gcnew Knight("BlackKnight1", ChessPieceType::BlackKnight, spaces[SpaceColBIndex][SpaceRow8Index]);
	bPieces[15] = gcnew Knight("BlackKnight2", ChessPieceType::BlackKnight, spaces[SpaceColGIndex][SpaceRow8Index]);
	//assign piece to a space for initial chessboard setup
	spaces[SpaceColAIndex][SpaceRow2Index]->pieceInSpace = wPieces[0]->getName();
	spaces[SpaceColBIndex][SpaceRow2Index]->pieceInSpace = wPieces[1]->getName();
	spaces[SpaceColCIndex][SpaceRow2Index]->pieceInSpace = wPieces[2]->getName();
	spaces[SpaceColDIndex][SpaceRow2Index]->pieceInSpace = wPieces[3]->getName();
	spaces[SpaceColEIndex][SpaceRow2Index]->pieceInSpace = wPieces[4]->getName();
	spaces[SpaceColFIndex][SpaceRow2Index]->pieceInSpace = wPieces[5]->getName();
	spaces[SpaceColGIndex][SpaceRow2Index]->pieceInSpace = wPieces[6]->getName();
	spaces[SpaceColHIndex][SpaceRow2Index]->pieceInSpace = wPieces[7]->getName();
	spaces[SpaceColAIndex][SpaceRow1Index]->pieceInSpace = wPieces[8]->getName();
	spaces[SpaceColHIndex][SpaceRow1Index]->pieceInSpace = wPieces[9]->getName();
	spaces[SpaceColCIndex][SpaceRow1Index]->pieceInSpace = wPieces[10]->getName();
	spaces[SpaceColFIndex][SpaceRow1Index]->pieceInSpace = wPieces[11]->getName();
	spaces[SpaceColEIndex][SpaceRow1Index]->pieceInSpace = wPieces[12]->getName();
	spaces[SpaceColDIndex][SpaceRow1Index]->pieceInSpace = wPieces[13]->getName();
	spaces[SpaceColBIndex][SpaceRow1Index]->pieceInSpace = wPieces[14]->getName();
	spaces[SpaceColGIndex][SpaceRow1Index]->pieceInSpace = wPieces[15]->getName();

	spaces[SpaceColAIndex][SpaceRow7Index]->pieceInSpace = bPieces[0]->getName();
	spaces[SpaceColBIndex][SpaceRow7Index]->pieceInSpace = bPieces[1]->getName();
	spaces[SpaceColCIndex][SpaceRow7Index]->pieceInSpace = bPieces[2]->getName();
	spaces[SpaceColDIndex][SpaceRow7Index]->pieceInSpace = bPieces[3]->getName();
	spaces[SpaceColEIndex][SpaceRow7Index]->pieceInSpace = bPieces[4]->getName();
	spaces[SpaceColFIndex][SpaceRow7Index]->pieceInSpace = bPieces[5]->getName();
	spaces[SpaceColGIndex][SpaceRow7Index]->pieceInSpace = bPieces[6]->getName();
	spaces[SpaceColHIndex][SpaceRow7Index]->pieceInSpace = bPieces[7]->getName();
	spaces[SpaceColAIndex][SpaceRow8Index]->pieceInSpace = bPieces[8]->getName();
	spaces[SpaceColHIndex][SpaceRow8Index]->pieceInSpace = bPieces[9]->getName();
	spaces[SpaceColCIndex][SpaceRow8Index]->pieceInSpace = bPieces[10]->getName();
	spaces[SpaceColFIndex][SpaceRow8Index]->pieceInSpace = bPieces[11]->getName();
	spaces[SpaceColEIndex][SpaceRow8Index]->pieceInSpace = bPieces[12]->getName();
	spaces[SpaceColDIndex][SpaceRow8Index]->pieceInSpace = bPieces[13]->getName();
	spaces[SpaceColBIndex][SpaceRow8Index]->pieceInSpace = bPieces[14]->getName();
	spaces[SpaceColGIndex][SpaceRow8Index]->pieceInSpace = bPieces[15]->getName();
}

ChessBoardMgr::~ChessBoardMgr(void) {
	//in C++/CLI the compiler will destroy any memory allocated
}

void ChessBoardMgr::init(TextBox^ loggerTextBox_, TextBox^ movesTextBox) {
	logger->loggerTextBoxProp = loggerTextBox_;
	movesTextBoxProp = movesTextBox;
}

//provides a passthrough method to log any data
void ChessBoardMgr::log(String^ data) {
	logger->log(data);
}

//return true or false if name is the active player
bool ChessBoardMgr::isActiveColor(String^ name) {
	String^ sActivePlayer = (activeColorPlayer == ActivePlayer::Black) ? "black" : "white";
	return name->Contains(sActivePlayer);
}

//method for determining if a player move is valid
bool ChessBoardMgr::isValidMove(SpaceLoc^ currentLoc, SpaceLoc^ proposedLoc) {
	bool status = false;
	try {
		int iCol = currentLoc->colIndexProp; //retrieve the numerical index for current space location
		int iRow = currentLoc->rowIndexProp;
		BoardSpace^ proposedBS = spaces[proposedLoc->colIndexProp][proposedLoc->rowIndexProp];

		//Checking to ensure you are not capturing same color piece and return false for isValidMove if same color
		status = colorCheck(proposedBS);
		BoardSpace^ bs = spaces[iCol][iRow];

		//if no error and boardspace is valid
		if (status && bs != nullptr ) {
			
			String^ origSpace = bs->nameProp;
			array<ChessPiece^>^ pieces = nullptr;
			array<ChessPiece^>^ capturePieces = nullptr;
			String^ kingName = "";
			ChessPiece^ king = nullptr;
			if (activeColorPlayer == ActivePlayer::White) {
				pieces = wPieces;
				capturePieces = bPieces;
				kingName = gcnew String("WhiteKing");
			}
			else {
				pieces = bPieces;
				capturePieces = wPieces;
				kingName = gcnew String("BlackKing");
			}

			//Finds active king on the board
			king = findKing(pieces, kingName);

			ChessPiece^ cp = getSelectedPiece(pieces, bs);
			if (cp != nullptr) {

				if (validateMove(cp, currentLoc, proposedLoc)) {
					iCol = proposedLoc->colIndexProp; //finds the numerical index for current space location
					iRow = proposedLoc->rowIndexProp;

					if (status = pawnCaptureCheck(cp, spaces[iCol][iRow])) {
						if (status = kingMoveCheck(cp, capturePieces, proposedLoc)) {
							if (status = attackKingCheck(bs, king, spaces[iCol][iRow],
								cp, capturePieces, proposedLoc)) {
								System::String^ data = String::Format("L, Proposed Space Col #:  {0}, Proposed Space Row #, {1}\n",
									iCol, iRow);
								logger->log(data);
								bs = spaces[iCol][iRow];
								markPieceCaptured(bs, capturePieces);
								String^ output = String::Format("wPieceName: {0}, bsname: {1}\n", cp->getName(), bs->pieceInSpace); // String::Format
								logger->log(output);

								bs->pieceInSpace = cp->getName();

								setPawnFirstMove(cp);
								iMovesProp += 1;
								String^ sMoveData = String::Format("{0,3}.\t{1,13}\t{2}\t{3}", iMovesProp, bs->pieceInSpace, origSpace, bs->nameProp);
								tBMoves->AppendText(sMoveData + Environment::NewLine);
								cp->bsProp = bs;
							}
						}
					}
				}
			}
		}
	}
	catch (Exception^ e) {
		logger->log("Exception in isValidMove\n");
	}
	return status;
}

bool ChessBoardMgr::isPathOccuppied(SpaceLoc^ currentLoc, SpaceLoc^ proposedLoc) {

	int iColIncr = 0; // defaulted to same column
	int iRowIncr = 0; // defaulted to same row
	SpaceLoc^ testLoc;
	bool bOccuppied = false;

	//determine col move direction
	if (currentLoc->colProp < proposedLoc->colProp) {
		iColIncr = 1;
	} else if (currentLoc->colProp > proposedLoc->colProp) {
		iColIncr = -1;
	}

	//determine row move direction
	if (currentLoc->rowProp < proposedLoc->rowProp) {
		iRowIncr = 1;
	}
	else if (currentLoc->rowProp > proposedLoc->rowProp) {
		iRowIncr = -1;
	}

	testLoc = gcnew SpaceLoc(currentLoc->colProp + iColIncr, currentLoc->rowProp + iRowIncr);

	int iSpaceCol;
	int iSpaceRow;

	while (!(testLoc->locEquals(proposedLoc))) {
		iSpaceCol = testLoc->colIndexProp; //retrieve the numerical index for current space location
		iSpaceRow = testLoc->rowIndexProp;
		if (spaces[iSpaceCol][iSpaceRow]->pieceInSpace != nullptr) {
			bOccuppied = true;
			break;
		}
  		testLoc->colProp += iColIncr;   
		testLoc->rowProp += iRowIncr;
	}
	return bOccuppied;
}

bool ChessBoardMgr::validateMove(ChessPiece^ piece, SpaceLoc^ currentLoc, SpaceLoc^ proposedLoc) {
	bool status = false;
	if (piece->isValidMove(currentLoc, proposedLoc)) {
		if ((piece->getCp() == ChessPieceType::WhiteKnight) || (piece->getCp() == ChessPieceType::BlackKnight)) {
			status = true;
		}
		else {
			status = (isPathOccuppied(currentLoc, proposedLoc)) ? false : true;
		}
	}
	return status;
}

//Checking to ensure you are not capturing same color piece and return false for isValidMove if same color
bool ChessBoardMgr::colorCheck(BoardSpace^ proposedBS) {
	bool status = true;
	if (proposedBS != nullptr) {
		if (proposedBS->pieceInSpace != nullptr) {
			if (proposedBS->pieceInSpace->Contains("White") && (activeColorPlayer == ActivePlayer::White) || 
				(proposedBS->pieceInSpace->Contains("Black") && (activeColorPlayer == ActivePlayer::Black))) {
				status = false;
			}
		}
	}
	else {
		logger->log("Invalid Condition, proposedBS is null\n");
		status = false;
	}
	return status;
}


ChessPiece^ ChessBoardMgr::findKing(array<ChessPiece^>^ pieces, String^ kingName) {
	ChessPiece^ king = nullptr;
	for (int piece = 0; piece < MAX_NUM_PIECES; piece++) {
		ChessPiece^ cp = pieces[piece];
		if (pieces[piece]->getName()->CompareTo(kingName) == 0) { //string comparison 
			king = pieces[piece];
			break;
		}
	}
	return king;
}
ChessPiece^ ChessBoardMgr::getSelectedPiece(array<ChessPiece^>^ pieces, BoardSpace^ bs) {
	ChessPiece^ selectedPiece = nullptr;
	for (int piece = 0; piece < MAX_NUM_PIECES; piece++) {
		ChessPiece^ cp = pieces[piece];
		if (cp != nullptr) {
			if (cp->capturedProp) {
				continue;
			}
			String^ output = String::Format("wPieceName: {0}, bsname: {1}\n", pieces[piece]->getName(), bs->pieceInSpace); // String::Format
			logger->log(output);

			// determine the space that was clicked by the mouse and then loop through the pieces to match to a piece to move
			if (pieces[piece]->getName()->CompareTo(bs->pieceInSpace) == 0) { //string comparison
				selectedPiece = pieces[piece];
				break;
			}
		}
	}
	if (selectedPiece == nullptr) {
		logger->log("ERROR: Unable to find selected piece");
	}
	return selectedPiece;
			
}

bool ChessBoardMgr::pawnCaptureCheck(ChessPiece^ cp, BoardSpace^ bs) {
	bool status = true;
	if ((cp->getCp() == ChessPieceType::WhitePawn) || (cp->getCp() == ChessPieceType::BlackPawn)) {
		Pawn^ pawnPiece = (Pawn^)cp;
		if (pawnPiece->captureMoveProp) {
			if (!bs->pieceInSpace) {
				status = false;  // can only capture if space is occupied
			}
		}
	}
	return status;
}

bool ChessBoardMgr::kingMoveCheck(ChessPiece^ cp, array<ChessPiece^>^ capturePieces, SpaceLoc^ proposedLoc) {
	//Verify the king can not move to squares protected by opposite color pieces
	bool status = true;
	Pawn^ pawnPiece = nullptr;
	if ((cp->getCp() == ChessPieceType::WhiteKing) || (cp->getCp() == ChessPieceType::BlackKing)) {
		for (int piece = 0; piece < MAX_NUM_PIECES; piece++) {
			ChessPiece^ cp2 = capturePieces[piece];
			if (cp2->capturedProp) {
				continue;
			}
			if ((cp2->getCp() == ChessPieceType::WhitePawn) || (cp2->getCp() == ChessPieceType::BlackPawn)) {
				pawnPiece = (Pawn^)cp2;
				if (pawnPiece->isValidMove(cp2->bsProp->slProp, proposedLoc)) {
					if (!pawnPiece->captureMoveProp) {
						continue;
					}
				}
				if (pawnPiece->captureMoveProp) {
					status = false;
					break;
				}
			}
			if (validateMove(cp2, cp2->bsProp->slProp, proposedLoc)) {
				logger->log("Unable to move king to protected square");
				status = false;
				break;
			}
		}
	}
	return status;
}

bool ChessBoardMgr::attackKingCheck(BoardSpace^ bs, ChessPiece^ king, BoardSpace^ kingBS, 
	ChessPiece^ cp, array<ChessPiece^>^ capturePieces, SpaceLoc^ proposedLoc) {
	bool status = true;
	// moves piece temporarily to proposed location to see if any opposite color pieces could then attack the king
	String^ storedPiece = bs->pieceInSpace;
	Pawn^ pawnPiece = nullptr;
	bs->pieceInSpace = nullptr;
	BoardSpace^ storedBs = king->bsProp;
	if ((cp->getCp() == ChessPieceType::WhiteKing) || (cp->getCp() == ChessPieceType::BlackKing)) {
		king->bsProp = kingBS;
	}
	for (int piece = 0; piece < MAX_NUM_PIECES; piece++) {
		ChessPiece^ cp2 = capturePieces[piece];
		if (cp2->capturedProp) {
			continue;
		}
		if ((cp2->getCp() == ChessPieceType::WhitePawn) || (cp2->getCp() == ChessPieceType::BlackPawn)) {
			pawnPiece = (Pawn^)cp2;
			if (!pawnPiece->captureMoveProp) {
				continue;
			}
		}
		if (validateMove(cp2, cp2->bsProp->slProp, king->bsProp->slProp)) {

			if (proposedLoc->locEquals(cp2->bsProp->slProp)) {
				break;
			}
			logger->log("Unable to move because piece is pinned to king");
			bs->pieceInSpace = storedPiece;
			king->bsProp = storedBs;
			status = false;
			break;
		}
	}
	return status;
}

void ChessBoardMgr::markPieceCaptured(BoardSpace^ bs, array<ChessPiece^>^ capturePieces) {
	if (bs->pieceInSpace != nullptr) {
		for (int i = 0; i < MAX_NUM_PIECES; i++) {
			ChessPiece^ ccp = capturePieces[i];
			if (ccp->capturedProp) {
				continue;
			}
			if (ccp != nullptr) {
				// find piece in space to mark as captured
				if (capturePieces[i]->getName()->CompareTo(bs->pieceInSpace) == 0) { //string comparison 
					capturePieces[i]->capturedProp = true;
				}
			}
		}
	}
}

void ChessBoardMgr::setPawnFirstMove(ChessPiece^ cp) {
	if ((cp->getCp() == ChessPieceType::WhitePawn) || (cp->getCp() == ChessPieceType::BlackPawn)) {
		Pawn^ pawnPiece = (Pawn^)cp;
		pawnPiece->firstMoveProp = false;
	}
}