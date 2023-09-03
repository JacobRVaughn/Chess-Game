#pragma once

#define SPACE_COL_A 'a'

ref class SpaceLoc
{
	char col = 0;
	char row = 0;
	int colIndex = 0;
	int rowIndex = 0;

public:
	SpaceLoc(char, char); //This is the constructer 
	~SpaceLoc(); //This is the destructor 
	property char colProp {
		char get() {
			return col;
		}
		void set(char col_) {
			col = col_;
			colIndex = col - SPACE_COL_A; //finds the numerical index for current space location
		}
	}
	property char rowProp {
		char get() {
			return row;
		}
		void set(char row_) {
			row = row_;
			rowIndex = int(row) - 48 - 1;
		}
	}
	property int rowIndexProp {
		int get() {
			return rowIndex;
		}
	}
	property int colIndexProp {
		int get() {
			return colIndex;
		}
	}
	bool locEquals(SpaceLoc^ compareLoc);
};