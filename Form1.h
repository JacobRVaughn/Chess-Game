#pragma once
#include "ChessBoardMgr.h"
#include "SpaceLoc.h"
//#include <Windows.h>

#define SPACE_WIDTH 72
#define SPACE_HEIGHT 72

namespace CppCLRWinFormsProject {


	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// Summary for Form1
	public ref class Form1 : public System::Windows::Forms::Form
	{

	private: 

		//HWND handle;
		Point piecePoint;
		Point origPoint;
	private: System::Windows::Forms::TabControl^ tabMoves;



	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::TextBox^ tBMoves;

	private: System::Windows::Forms::TextBox^ infoTextBox;
		   ChessBoardMgr chessBoardMgr;


	public:
		Form1(void)
		{
			InitializeComponent();
			//TODO: Add the constructor code here
			chessBoardMgr.init(infoTextBox, tBMoves);
			//handle = FindWindowA(NULL, "Chess By Jacob");
			//char logData[200];
			//sprintf(logData, "formWidth = %d formHeight = %d", origPoint.X, origPoint.Y);
			//chessBoardMgr.log(this->Size.Width);
		}


	protected:
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	public: void control_MouseDown(Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		PictureBox^ pb = (PictureBox^)sender;

		piecePoint = Cursor->Position;
		origPoint = pb->Location;


		//if (e->Button == System::Windows::Forms::MouseButtons::Left) {

			
//			pb->Location = System::Drawing::Point(e->X, e->Y);
//			cout << "X = " << e->X << " Y = " << e->Y;
	//	}

	}
	public: void control_MouseMove(Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		PictureBox^ pb = (PictureBox^)sender;

		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			int px = Cursor->Position.X - piecePoint.X;
			int py = Cursor->Position.Y - piecePoint.Y;

			pb->Location = System::Drawing::Point(pb->Location.X + px, pb->Location.Y + py);

			piecePoint = Cursor->Position;
//			pb->Location = System::Drawing::Point(e->X, e->Y);
//			cout << "X = " << e->X << " Y = " << e->Y;
		}
	}
	public: void control_MouseUp(Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		PictureBox^ pb = (PictureBox^)sender;

		if (!chessBoardMgr.isActiveColor(pb->Name)) {
			pb->Location = origPoint;
			return;
		}
		if (pb->Location.X > chessboard->Image->Width) {
			pb->Location = origPoint;
			return;
		}
		if (pb->Location.Y > chessboard->Image->Height) {
			pb->Location = origPoint;
			return;
		}
		int iCol = (origPoint.X / SPACE_WIDTH);
		int iRow = (origPoint.Y / SPACE_HEIGHT);
		char logData[200];
		sprintf(logData, "origPoint.X = %d origPoint.Y = %d", origPoint.X, origPoint.Y);
		System::String^ data = gcnew System::String(logData);
		chessBoardMgr.log(data);
		
		//POINT* newPoint = new POINT;
		//ScreenToClient(handle, newPoint);

		int iColUp = (pb->Location.X / SPACE_WIDTH);
		int iRowUp = (pb->Location.Y / SPACE_HEIGHT);

		sprintf(logData, "piecePoint.X = %d piecePoint.Y = %d", pb->Location.X, pb->Location.Y);
		data = gcnew System::String(logData);
		chessBoardMgr.log(data);
		SpaceLoc^ slCurrentSpace = gcnew SpaceLoc(SPACE_COL_A + iCol, SPACE_ROW_8 - iRow);
		SpaceLoc^ slNewSpace = gcnew SpaceLoc(SPACE_COL_A + iColUp, SPACE_ROW_8 - iRowUp);
		int colDif = slNewSpace->colProp - slCurrentSpace->colProp;
		int rowDif = slNewSpace->rowProp - slCurrentSpace->rowProp;
		sprintf(logData, "colDif = %d rowDif = %d", colDif, rowDif);
		data = gcnew System::String(logData);
		chessBoardMgr.log(data);
		Console::WriteLine(data);
		if (chessBoardMgr.isValidMove(slCurrentSpace, slNewSpace)) {
			array<ChessPiece^>^ pieces = chessBoardMgr.arrayNonActivePiecesProp;

			if (pieces != nullptr) {
				for (int i = 0; i < MAX_NUM_PIECES; i++) {
					ChessPiece^ cp = pieces[i];
					if (pieces[i]->capturedProp) {
						if (pieces[i]->getName()->CompareTo("WhitePawn1") == 0) { //string comparison 
							whitePawn1->Visible = false;
						} 
						else if (pieces[i]->getName()->CompareTo("WhitePawn2") == 0) {
							whitePawn2->Visible = false;
						} 
						else if (pieces[i]->getName()->CompareTo("WhitePawn3") == 0) {
							whitePawn3->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("WhitePawn4") == 0) {
							whitePawn4->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("WhitePawn5") == 0) {
							whitePawn5->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("WhitePawn6") == 0) {
							whitePawn6->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("WhitePawn7") == 0) {
							whitePawn7->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("WhitePawn8") == 0) {
							whitePawn8->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("WhiteRook1") == 0) {
							whiteRook1->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("WhiteRook2") == 0) {
							whiteRook2->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("WhiteKnight1") == 0) {
							whiteKnight1->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("WhiteKnight2") == 0) {
							whiteKnight2->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("WhiteBishop1") == 0) {
							whiteBishop1->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("WhiteBishop2") == 0) {
							whiteBishop2->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("WhiteQueen") == 0) {
							whiteQueen->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("WhiteKing") == 0) {
							whiteKing->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("BlackPawn1") == 0) { //string comparison 
							blackPawn1->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("BlackPawn2") == 0) {
							blackPawn2->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("BlackPawn3") == 0) {
							blackPawn3->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("BlackPawn4") == 0) {
							blackPawn4->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("BlackPawn5") == 0) {
							blackPawn5->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("BlackPawn6") == 0) {
							blackPawn6->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("BlackPawn7") == 0) {
							blackPawn7->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("BlackPawn8") == 0) {
							blackPawn8->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("BlackRook1") == 0) {
							blackRook1->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("BlackRook2") == 0) {
							blackRook2->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("BlackKnight1") == 0) {
							blackKnight1->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("BlackKnight2") == 0) {
							blackKnight2->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("BlackBishop1") == 0) {
							blackBishop1->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("BlackBishop2") == 0) {
							blackBishop2->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("BlackQueen") == 0) {
							blackQueen->Visible = false;
						}
						else if (pieces[i]->getName()->CompareTo("BlackKing") == 0) {
							blackKing->Visible = false;
						}
					}
				}
			}
			ActivePlayer newAP = (chessBoardMgr.activeColorPlayer == ActivePlayer::Black) ? ActivePlayer::White : ActivePlayer::Black;
			chessBoardMgr.activeColorPlayer = newAP;
		}
		else {
			pb->Location = origPoint;
		}
	}
	public: System::Windows::Forms::PictureBox^ chessboard;
	protected:

	public: System::Windows::Forms::PictureBox^ blackRook1;
	public: System::Windows::Forms::PictureBox^ blackKnight1;
	public: System::Windows::Forms::PictureBox^ blackBishop1;
	public: System::Windows::Forms::PictureBox^ blackQueen;
	public: System::Windows::Forms::PictureBox^ blackKing;
	public: System::Windows::Forms::PictureBox^ blackBishop2;
	public: System::Windows::Forms::PictureBox^ blackKnight2;
	public: System::Windows::Forms::PictureBox^ blackRook2;
	public: System::Windows::Forms::PictureBox^ blackPawn1;
	public: System::Windows::Forms::PictureBox^ blackPawn2;
	public: System::Windows::Forms::PictureBox^ blackPawn3;
	public: System::Windows::Forms::PictureBox^ blackPawn4;
	public: System::Windows::Forms::PictureBox^ blackPawn5;
	public: System::Windows::Forms::PictureBox^ blackPawn6;
	public: System::Windows::Forms::PictureBox^ blackPawn7;
	public: System::Windows::Forms::PictureBox^ blackPawn8;
	public: System::Windows::Forms::PictureBox^ whiteRook1;
	public: System::Windows::Forms::PictureBox^ whiteKnight1;
	public: System::Windows::Forms::PictureBox^ whiteBishop1;
	public: System::Windows::Forms::PictureBox^ whiteQueen;
	public: System::Windows::Forms::PictureBox^ whiteKing;
	public: System::Windows::Forms::PictureBox^ whiteBishop2;
	public: System::Windows::Forms::PictureBox^ whiteKnight2;
	public: System::Windows::Forms::PictureBox^ whiteRook2;
	public: System::Windows::Forms::PictureBox^ whitePawn1;
	public: System::Windows::Forms::PictureBox^ whitePawn2;
	public: System::Windows::Forms::PictureBox^ whitePawn3;
	public: System::Windows::Forms::PictureBox^ whitePawn4;
	public: System::Windows::Forms::PictureBox^ whitePawn5;
	public: System::Windows::Forms::PictureBox^ whitePawn6;
	public: System::Windows::Forms::PictureBox^ whitePawn7;
	public: System::Windows::Forms::PictureBox^ whitePawn8;




	public:
	public:
	public:
	protected:

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->chessboard = (gcnew System::Windows::Forms::PictureBox());
			this->blackRook1 = (gcnew System::Windows::Forms::PictureBox());
			this->blackKnight1 = (gcnew System::Windows::Forms::PictureBox());
			this->blackBishop1 = (gcnew System::Windows::Forms::PictureBox());
			this->blackQueen = (gcnew System::Windows::Forms::PictureBox());
			this->blackKing = (gcnew System::Windows::Forms::PictureBox());
			this->blackBishop2 = (gcnew System::Windows::Forms::PictureBox());
			this->blackKnight2 = (gcnew System::Windows::Forms::PictureBox());
			this->blackRook2 = (gcnew System::Windows::Forms::PictureBox());
			this->blackPawn1 = (gcnew System::Windows::Forms::PictureBox());
			this->blackPawn2 = (gcnew System::Windows::Forms::PictureBox());
			this->blackPawn3 = (gcnew System::Windows::Forms::PictureBox());
			this->blackPawn4 = (gcnew System::Windows::Forms::PictureBox());
			this->blackPawn5 = (gcnew System::Windows::Forms::PictureBox());
			this->blackPawn6 = (gcnew System::Windows::Forms::PictureBox());
			this->blackPawn7 = (gcnew System::Windows::Forms::PictureBox());
			this->blackPawn8 = (gcnew System::Windows::Forms::PictureBox());
			this->whiteRook1 = (gcnew System::Windows::Forms::PictureBox());
			this->whiteKnight1 = (gcnew System::Windows::Forms::PictureBox());
			this->whiteBishop1 = (gcnew System::Windows::Forms::PictureBox());
			this->whiteQueen = (gcnew System::Windows::Forms::PictureBox());
			this->whiteKing = (gcnew System::Windows::Forms::PictureBox());
			this->whiteBishop2 = (gcnew System::Windows::Forms::PictureBox());
			this->whiteKnight2 = (gcnew System::Windows::Forms::PictureBox());
			this->whiteRook2 = (gcnew System::Windows::Forms::PictureBox());
			this->whitePawn1 = (gcnew System::Windows::Forms::PictureBox());
			this->whitePawn2 = (gcnew System::Windows::Forms::PictureBox());
			this->whitePawn3 = (gcnew System::Windows::Forms::PictureBox());
			this->whitePawn4 = (gcnew System::Windows::Forms::PictureBox());
			this->whitePawn5 = (gcnew System::Windows::Forms::PictureBox());
			this->whitePawn6 = (gcnew System::Windows::Forms::PictureBox());
			this->whitePawn7 = (gcnew System::Windows::Forms::PictureBox());
			this->whitePawn8 = (gcnew System::Windows::Forms::PictureBox());
			this->tabMoves = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tBMoves = (gcnew System::Windows::Forms::TextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->infoTextBox = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chessboard))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackRook1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackKnight1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackBishop1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackQueen))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackKing))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackBishop2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackKnight2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackRook2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteRook1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteKnight1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteBishop1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteQueen))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteKing))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteBishop2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteKnight2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteRook2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn8))->BeginInit();
			this->tabMoves->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->SuspendLayout();
			// 
			// chessboard
			// 
			this->chessboard->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->chessboard->Location = System::Drawing::Point(12, 12);
			this->chessboard->MaximumSize = System::Drawing::Size(768, 720);
			this->chessboard->MinimumSize = System::Drawing::Size(768, 720);
			this->chessboard->Name = L"chessboard";
			this->chessboard->Size = System::Drawing::Size(768, 720);
			this->chessboard->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->chessboard->TabIndex = 0;
			this->chessboard->TabStop = false;
			this->chessboard->Click += gcnew System::EventHandler(this, &Form1::chessboard_Click);
			// 
			// blackRook1
			// 
			this->blackRook1->Location = System::Drawing::Point(12, 18);
			this->blackRook1->Name = L"blackRook1";
			this->blackRook1->Size = System::Drawing::Size(96, 90);
			this->blackRook1->TabIndex = 1;
			this->blackRook1->TabStop = false;
			this->blackRook1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->blackRook1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->blackRook1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// blackKnight1
			// 
			this->blackKnight1->Location = System::Drawing::Point(111, 18);
			this->blackKnight1->Name = L"blackKnight1";
			this->blackKnight1->Size = System::Drawing::Size(96, 90);
			this->blackKnight1->TabIndex = 2;
			this->blackKnight1->TabStop = false;
			this->blackKnight1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->blackKnight1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->blackKnight1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// blackBishop1
			// 
			this->blackBishop1->Location = System::Drawing::Point(213, 18);
			this->blackBishop1->Name = L"blackBishop1";
			this->blackBishop1->Size = System::Drawing::Size(96, 90);
			this->blackBishop1->TabIndex = 3;
			this->blackBishop1->TabStop = false;
			this->blackBishop1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->blackBishop1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->blackBishop1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// blackQueen
			// 
			this->blackQueen->Location = System::Drawing::Point(306, 18);
			this->blackQueen->Name = L"blackQueen";
			this->blackQueen->Size = System::Drawing::Size(96, 90);
			this->blackQueen->TabIndex = 4;
			this->blackQueen->TabStop = false;
			this->blackQueen->Click += gcnew System::EventHandler(this, &Form1::blackQueen_Click);
			this->blackQueen->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->blackQueen->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->blackQueen->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// blackKing
			// 
			this->blackKing->Location = System::Drawing::Point(398, 18);
			this->blackKing->Name = L"blackKing";
			this->blackKing->Size = System::Drawing::Size(96, 90);
			this->blackKing->TabIndex = 5;
			this->blackKing->TabStop = false;
			this->blackKing->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->blackKing->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->blackKing->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// blackBishop2
			// 
			this->blackBishop2->Location = System::Drawing::Point(500, 18);
			this->blackBishop2->Name = L"blackBishop2";
			this->blackBishop2->Size = System::Drawing::Size(96, 90);
			this->blackBishop2->TabIndex = 6;
			this->blackBishop2->TabStop = false;
			this->blackBishop2->Click += gcnew System::EventHandler(this, &Form1::blackBishop2_Click);
			this->blackBishop2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->blackBishop2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->blackBishop2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// blackKnight2
			// 
			this->blackKnight2->Location = System::Drawing::Point(592, 18);
			this->blackKnight2->Name = L"blackKnight2";
			this->blackKnight2->Size = System::Drawing::Size(96, 90);
			this->blackKnight2->TabIndex = 7;
			this->blackKnight2->TabStop = false;
			this->blackKnight2->Click += gcnew System::EventHandler(this, &Form1::blackKnight2_Click);
			this->blackKnight2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->blackKnight2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->blackKnight2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// blackRook2
			// 
			this->blackRook2->Location = System::Drawing::Point(684, 18);
			this->blackRook2->Name = L"blackRook2";
			this->blackRook2->Size = System::Drawing::Size(96, 90);
			this->blackRook2->TabIndex = 8;
			this->blackRook2->TabStop = false;
			this->blackRook2->Click += gcnew System::EventHandler(this, &Form1::blackRook2_Click);
			this->blackRook2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->blackRook2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->blackRook2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// blackPawn1
			// 
			this->blackPawn1->Location = System::Drawing::Point(12, 114);
			this->blackPawn1->Name = L"blackPawn1";
			this->blackPawn1->Size = System::Drawing::Size(96, 90);
			this->blackPawn1->TabIndex = 9;
			this->blackPawn1->TabStop = false;
			this->blackPawn1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->blackPawn1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->blackPawn1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// blackPawn2
			// 
			this->blackPawn2->Location = System::Drawing::Point(111, 114);
			this->blackPawn2->Name = L"blackPawn2";
			this->blackPawn2->Size = System::Drawing::Size(96, 90);
			this->blackPawn2->TabIndex = 10;
			this->blackPawn2->TabStop = false;
			this->blackPawn2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->blackPawn2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->blackPawn2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// blackPawn3
			// 
			this->blackPawn3->Location = System::Drawing::Point(213, 114);
			this->blackPawn3->Name = L"blackPawn3";
			this->blackPawn3->Size = System::Drawing::Size(96, 90);
			this->blackPawn3->TabIndex = 11;
			this->blackPawn3->TabStop = false;
			this->blackPawn3->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->blackPawn3->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->blackPawn3->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// blackPawn4
			// 
			this->blackPawn4->Location = System::Drawing::Point(306, 114);
			this->blackPawn4->Name = L"blackPawn4";
			this->blackPawn4->Size = System::Drawing::Size(96, 90);
			this->blackPawn4->TabIndex = 12;
			this->blackPawn4->TabStop = false;
			this->blackPawn4->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->blackPawn4->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->blackPawn4->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// blackPawn5
			// 
			this->blackPawn5->Location = System::Drawing::Point(398, 114);
			this->blackPawn5->Name = L"blackPawn5";
			this->blackPawn5->Size = System::Drawing::Size(96, 90);
			this->blackPawn5->TabIndex = 13;
			this->blackPawn5->TabStop = false;
			this->blackPawn5->Click += gcnew System::EventHandler(this, &Form1::pictureBox5_Click);
			this->blackPawn5->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->blackPawn5->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->blackPawn5->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// blackPawn6
			// 
			this->blackPawn6->Location = System::Drawing::Point(500, 114);
			this->blackPawn6->Name = L"blackPawn6";
			this->blackPawn6->Size = System::Drawing::Size(96, 90);
			this->blackPawn6->TabIndex = 14;
			this->blackPawn6->TabStop = false;
			this->blackPawn6->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->blackPawn6->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->blackPawn6->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// blackPawn7
			// 
			this->blackPawn7->Location = System::Drawing::Point(592, 114);
			this->blackPawn7->Name = L"blackPawn7";
			this->blackPawn7->Size = System::Drawing::Size(96, 90);
			this->blackPawn7->TabIndex = 15;
			this->blackPawn7->TabStop = false;
			this->blackPawn7->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->blackPawn7->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->blackPawn7->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// blackPawn8
			// 
			this->blackPawn8->Location = System::Drawing::Point(684, 114);
			this->blackPawn8->Name = L"blackPawn8";
			this->blackPawn8->Size = System::Drawing::Size(96, 90);
			this->blackPawn8->TabIndex = 16;
			this->blackPawn8->TabStop = false;
			this->blackPawn8->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->blackPawn8->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->blackPawn8->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// whiteRook1
			// 
			this->whiteRook1->Location = System::Drawing::Point(12, 636);
			this->whiteRook1->Name = L"whiteRook1";
			this->whiteRook1->Size = System::Drawing::Size(96, 90);
			this->whiteRook1->TabIndex = 17;
			this->whiteRook1->TabStop = false;
			this->whiteRook1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->whiteRook1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->whiteRook1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// whiteKnight1
			// 
			this->whiteKnight1->Location = System::Drawing::Point(114, 636);
			this->whiteKnight1->Name = L"whiteKnight1";
			this->whiteKnight1->Size = System::Drawing::Size(96, 90);
			this->whiteKnight1->TabIndex = 18;
			this->whiteKnight1->TabStop = false;
			this->whiteKnight1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->whiteKnight1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->whiteKnight1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// whiteBishop1
			// 
			this->whiteBishop1->Location = System::Drawing::Point(213, 636);
			this->whiteBishop1->Name = L"whiteBishop1";
			this->whiteBishop1->Size = System::Drawing::Size(96, 90);
			this->whiteBishop1->TabIndex = 19;
			this->whiteBishop1->TabStop = false;
			this->whiteBishop1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->whiteBishop1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->whiteBishop1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// whiteQueen
			// 
			this->whiteQueen->Location = System::Drawing::Point(306, 636);
			this->whiteQueen->Name = L"whiteQueen";
			this->whiteQueen->Size = System::Drawing::Size(96, 90);
			this->whiteQueen->TabIndex = 20;
			this->whiteQueen->TabStop = false;
			this->whiteQueen->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->whiteQueen->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->whiteQueen->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// whiteKing
			// 
			this->whiteKing->Location = System::Drawing::Point(398, 636);
			this->whiteKing->Name = L"whiteKing";
			this->whiteKing->Size = System::Drawing::Size(96, 90);
			this->whiteKing->TabIndex = 21;
			this->whiteKing->TabStop = false;
			this->whiteKing->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->whiteKing->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->whiteKing->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// whiteBishop2
			// 
			this->whiteBishop2->Location = System::Drawing::Point(500, 636);
			this->whiteBishop2->Name = L"whiteBishop2";
			this->whiteBishop2->Size = System::Drawing::Size(96, 90);
			this->whiteBishop2->TabIndex = 22;
			this->whiteBishop2->TabStop = false;
			this->whiteBishop2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->whiteBishop2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->whiteBishop2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// whiteKnight2
			// 
			this->whiteKnight2->Location = System::Drawing::Point(592, 636);
			this->whiteKnight2->Name = L"whiteKnight2";
			this->whiteKnight2->Size = System::Drawing::Size(96, 90);
			this->whiteKnight2->TabIndex = 23;
			this->whiteKnight2->TabStop = false;
			this->whiteKnight2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->whiteKnight2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->whiteKnight2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// whiteRook2
			// 
			this->whiteRook2->Location = System::Drawing::Point(684, 636);
			this->whiteRook2->Name = L"whiteRook2";
			this->whiteRook2->Size = System::Drawing::Size(96, 90);
			this->whiteRook2->TabIndex = 24;
			this->whiteRook2->TabStop = false;
			this->whiteRook2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->whiteRook2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->whiteRook2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// whitePawn1
			// 
			this->whitePawn1->Location = System::Drawing::Point(12, 544);
			this->whitePawn1->Name = L"whitePawn1";
			this->whitePawn1->Size = System::Drawing::Size(96, 90);
			this->whitePawn1->TabIndex = 25;
			this->whitePawn1->TabStop = false;
			this->whitePawn1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->whitePawn1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->whitePawn1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// whitePawn2
			// 
			this->whitePawn2->Location = System::Drawing::Point(114, 544);
			this->whitePawn2->Name = L"whitePawn2";
			this->whitePawn2->Size = System::Drawing::Size(96, 90);
			this->whitePawn2->TabIndex = 26;
			this->whitePawn2->TabStop = false;
			this->whitePawn2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->whitePawn2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->whitePawn2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// whitePawn3
			// 
			this->whitePawn3->Location = System::Drawing::Point(213, 544);
			this->whitePawn3->Name = L"whitePawn3";
			this->whitePawn3->Size = System::Drawing::Size(96, 90);
			this->whitePawn3->TabIndex = 27;
			this->whitePawn3->TabStop = false;
			this->whitePawn3->Click += gcnew System::EventHandler(this, &Form1::whitePawn3_Click);
			this->whitePawn3->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->whitePawn3->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->whitePawn3->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// whitePawn4
			// 
			this->whitePawn4->Location = System::Drawing::Point(306, 544);
			this->whitePawn4->Name = L"whitePawn4";
			this->whitePawn4->Size = System::Drawing::Size(96, 90);
			this->whitePawn4->TabIndex = 28;
			this->whitePawn4->TabStop = false;
			this->whitePawn4->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->whitePawn4->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->whitePawn4->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// whitePawn5
			// 
			this->whitePawn5->Location = System::Drawing::Point(398, 544);
			this->whitePawn5->Name = L"whitePawn5";
			this->whitePawn5->Size = System::Drawing::Size(96, 90);
			this->whitePawn5->TabIndex = 29;
			this->whitePawn5->TabStop = false;
			this->whitePawn5->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->whitePawn5->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->whitePawn5->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// whitePawn6
			// 
			this->whitePawn6->Location = System::Drawing::Point(500, 544);
			this->whitePawn6->Name = L"whitePawn6";
			this->whitePawn6->Size = System::Drawing::Size(96, 90);
			this->whitePawn6->TabIndex = 30;
			this->whitePawn6->TabStop = false;
			this->whitePawn6->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->whitePawn6->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->whitePawn6->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// whitePawn7
			// 
			this->whitePawn7->Location = System::Drawing::Point(592, 544);
			this->whitePawn7->Name = L"whitePawn7";
			this->whitePawn7->Size = System::Drawing::Size(96, 90);
			this->whitePawn7->TabIndex = 31;
			this->whitePawn7->TabStop = false;
			this->whitePawn7->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->whitePawn7->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->whitePawn7->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// whitePawn8
			// 
			this->whitePawn8->Location = System::Drawing::Point(684, 544);
			this->whitePawn8->Name = L"whitePawn8";
			this->whitePawn8->Size = System::Drawing::Size(96, 90);
			this->whitePawn8->TabIndex = 32;
			this->whitePawn8->TabStop = false;
			this->whitePawn8->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseDown);
			this->whitePawn8->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseMove);
			this->whitePawn8->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::control_MouseUp);
			// 
			// tabMoves
			// 
			this->tabMoves->Controls->Add(this->tabPage1);
			this->tabMoves->Controls->Add(this->tabPage2);
			this->tabMoves->Controls->Add(this->tabPage3);
			this->tabMoves->Location = System::Drawing::Point(862, 18);
			this->tabMoves->Name = L"tabMoves";
			this->tabMoves->SelectedIndex = 0;
			this->tabMoves->Size = System::Drawing::Size(420, 714);
			this->tabMoves->TabIndex = 33;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->tBMoves);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(412, 685);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Moves";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &Form1::tabPage1_Click);
			// 
			// tBMoves
			// 
			this->tBMoves->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tBMoves->Location = System::Drawing::Point(6, 6);
			this->tBMoves->Multiline = true;
			this->tBMoves->Name = L"tBMoves";
			this->tBMoves->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->tBMoves->Size = System::Drawing::Size(400, 673);
			this->tBMoves->TabIndex = 0;
			this->tBMoves->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(412, 685);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Player Stats";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->infoTextBox);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(412, 685);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Info";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// infoTextBox
			// 
			this->infoTextBox->Location = System::Drawing::Point(3, 3);
			this->infoTextBox->Multiline = true;
			this->infoTextBox->Name = L"infoTextBox";
			this->infoTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->infoTextBox->Size = System::Drawing::Size(406, 679);
			this->infoTextBox->TabIndex = 34;
			this->infoTextBox->Text = L"\"ChessBoard Game is Starting\\n\"";
			this->infoTextBox->TextChanged += gcnew System::EventHandler(this, &Form1::infoTextBox_TextChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1315, 809);
			this->Controls->Add(this->tabMoves);
			this->Controls->Add(this->whitePawn8);
			this->Controls->Add(this->whitePawn7);
			this->Controls->Add(this->whitePawn6);
			this->Controls->Add(this->whitePawn5);
			this->Controls->Add(this->whitePawn4);
			this->Controls->Add(this->whitePawn3);
			this->Controls->Add(this->whitePawn2);
			this->Controls->Add(this->whitePawn1);
			this->Controls->Add(this->whiteRook2);
			this->Controls->Add(this->whiteKnight2);
			this->Controls->Add(this->whiteBishop2);
			this->Controls->Add(this->whiteKing);
			this->Controls->Add(this->whiteQueen);
			this->Controls->Add(this->whiteBishop1);
			this->Controls->Add(this->whiteKnight1);
			this->Controls->Add(this->whiteRook1);
			this->Controls->Add(this->blackPawn8);
			this->Controls->Add(this->blackPawn7);
			this->Controls->Add(this->blackPawn6);
			this->Controls->Add(this->blackPawn5);
			this->Controls->Add(this->blackPawn4);
			this->Controls->Add(this->blackPawn3);
			this->Controls->Add(this->blackPawn2);
			this->Controls->Add(this->blackPawn1);
			this->Controls->Add(this->blackRook2);
			this->Controls->Add(this->blackKnight2);
			this->Controls->Add(this->blackBishop2);
			this->Controls->Add(this->blackKing);
			this->Controls->Add(this->blackQueen);
			this->Controls->Add(this->blackBishop1);
			this->Controls->Add(this->blackKnight1);
			this->Controls->Add(this->blackRook1);
			this->Controls->Add(this->chessboard);
			this->Name = L"Form1";
			this->Text = L"Chess By Jacob";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chessboard))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackRook1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackKnight1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackBishop1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackQueen))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackKing))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackBishop2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackKnight2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackRook2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteRook1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteKnight1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteBishop1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteQueen))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteKing))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteBishop2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteKnight2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteRook2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn8))->EndInit();
			this->tabMoves->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void boardPanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void blackQueen_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void blackBishop2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void blackRook2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox5_Click(System::Object^ sender, System::EventArgs^ e) {
}
public: System::Void drawBoard() {
	chessboard->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\Chessboard.png");
	

	//Black Pieces Drawing
	blackRook1->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\BlackRook.png");
	blackKnight1->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\BlackKnight.png");
	blackBishop1->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\BlackBishop.png");
	blackQueen->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\BlackQueen.png");
	blackKing->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\BlackKing.png");
	blackBishop2->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\BlackBishop.png");
	blackKnight2->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\BlackKnight.png");
	blackRook2->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\BlackRook.png");
	blackPawn1->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\BlackPawn.png");
	blackPawn2->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\BlackPawn.png");
	blackPawn3->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\BlackPawn.png");
	blackPawn4->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\BlackPawn.png");
	blackPawn5->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\BlackPawn.png");
	blackPawn6->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\BlackPawn.png");
	blackPawn7->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\BlackPawn.png");
	blackPawn8->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\BlackPawn.png");
	//White Pieces Drawing
	whiteRook1->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\WhiteRook.png");
	whiteKnight1->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\WhiteKnight.png");
	whiteBishop1->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\WhiteBishop.png");
	whiteQueen->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\WhiteQueen.png");
	whiteKing->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\WhiteKing.png");
	whiteBishop2->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\WhiteBishop.png");
	whiteKnight2->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\WhiteKnight.png");
	whiteRook2->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\WhiteRook.png");
	whitePawn1->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\WhitePawn.png");
	whitePawn2->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\WhitePawn.png");
	whitePawn3->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\WhitePawn.png");
	whitePawn4->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\WhitePawn.png");
	whitePawn5->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\WhitePawn.png");
	whitePawn6->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\WhitePawn.png");
	whitePawn7->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\WhitePawn.png");
	whitePawn8->Image = System::Drawing::Image::FromFile(L"C:\\Users\\kjvau\\OneDrive\\Pictures\\Screenshots\\WhitePawn.png");
}
private: System::Void blackRook1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
}
private: System::Void chessboard_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void whitePawn3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void blackKnight2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tabPage1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void infoTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
