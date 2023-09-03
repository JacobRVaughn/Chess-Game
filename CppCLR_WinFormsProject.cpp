#include "pch.h"
#include <iostream>

using namespace System;


// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

#include "Form1.h"
#include "ChessBoardMgr.h"

using namespace System::Windows::Forms;



[STAThread]
int main()
{

  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  
  CppCLRWinFormsProject::Form1^ cgForm = gcnew CppCLRWinFormsProject::Form1();


  cgForm->drawBoard();


  //cgForm->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(cgForm, &CppCLRWinFormsProject::Form1::control_MouseDown);
  //cgForm->chessboard->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(cgForm, &CppCLRWinFormsProject::Form1::control_MouseDown);
  //cgForm->chessboard->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(cgForm, &CppCLRWinFormsProject::Form1::control_MouseMove);
/*public: System::Windows::Forms::PictureBox^ blackKnight1;
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
*/
  Application::Run(cgForm);

  return 0;
}