#include "pch.h"
#include "SpaceLoc.h"


SpaceLoc::SpaceLoc(char col_, char row_) {
	colProp = col_;
	rowProp = row_;
}

SpaceLoc::~SpaceLoc(void) {
}

bool SpaceLoc::locEquals(SpaceLoc^ compareLoc){
	return ((col == compareLoc->colProp) && (row == compareLoc->rowProp)) ? true : false;
}