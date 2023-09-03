#include "pch.h"
#include "BoardSpace.h"

BoardSpace::BoardSpace(char colName, char rowName) {
	char spaceName[3] = "";
	sprintf(spaceName, "%c%c", colName, rowName);
	name = gcnew String(spaceName);
	slProp = gcnew SpaceLoc(colName, rowName);
}

BoardSpace::~BoardSpace(void) {
}
