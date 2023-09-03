#include "pch.h"
#include "ChessBoardLogger.h"

using namespace System;

ChessBoardLogger::ChessBoardLogger() {

	cgLog = File::Create("C:\\Users\\kjvau\\OneDrive\\Documents\\Debug\\log.txt");
	sw = gcnew StreamWriter(cgLog);
}

ChessBoardLogger::~ChessBoardLogger(void) {
	sw->AutoFlush;
	sw->Close();
	cgLog->Close();
}


void ChessBoardLogger::log(String^ data) {
	sw->WriteLine(data);
	sw->AutoFlush;
	if (loggerTextBox != nullptr) {
		loggerTextBox->AppendText(data + Environment::NewLine);
	}
}
