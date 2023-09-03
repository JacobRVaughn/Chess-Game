#pragma once
#include <iostream>
#include <string>
#include "SpaceLoc.h"

#define SPACE_ROW_1 '1'
#define SPACE_ROW_8 '8'

enum SpaceCol { SpaceColAIndex, SpaceColBIndex, SpaceColCIndex, SpaceColDIndex, SpaceColEIndex, SpaceColFIndex, SpaceColGIndex, SpaceColHIndex};
enum SpaceRow { SpaceRow1Index, SpaceRow2Index, SpaceRow3Index, SpaceRow4Index, SpaceRow5Index, SpaceRow6Index, SpaceRow7Index, SpaceRow8Index };

using namespace System;

ref class BoardSpace
{

	String^ name = nullptr;
	String^ cp = nullptr;
	SpaceLoc^ sl = nullptr;

public:
	BoardSpace(char colName, char rowName); //This is the constructer 
	~BoardSpace(); //This is the destructor 

	property String^ nameProp {
		String^ get() {
			return name;
		}
		void set(String^ name_) {
			name = name_;
		}
	}
	property String^ pieceInSpace {
		String^ get() {
			return cp;
		}
		void set(String^ cp_) {
			cp = cp_;
		}
	} 
	property SpaceLoc^ slProp {
		SpaceLoc^ get() {
			return sl;
		}
		void set(SpaceLoc^ slProp_) {
			sl = slProp_;
		}
	}
};
