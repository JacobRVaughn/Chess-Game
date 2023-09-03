#pragma once

#include <fstream>

using namespace System::Windows::Forms;
using namespace System;
using namespace System::IO;

ref class ChessBoardLogger
{
private:
	FileStream^ cgLog;
	StreamWriter^ sw;
	TextBox^ loggerTextBox;

public:
	ChessBoardLogger(); //This is the constructer 
	~ChessBoardLogger(); //This is the destructor 
	void log(String^ data);

	property TextBox^ loggerTextBoxProp {
		TextBox^ get() {
			return loggerTextBox;
		}
		void set(TextBox^ loggerTextBox_) {
			loggerTextBox = loggerTextBox_;
		}
	}

};