#pragma once

enum field_t {
	EMPTY = 0,
	PIECE = 1,
	BORDER = 2
};

/**
* converts a character to a board field entry
*/
field_t charToBoardField(char fieldChar) {
	switch (fieldChar) {
	case 'O': return PIECE;
	case '.': return EMPTY;
	default: return BORDER;
	}
}

/**
* converts a board field entry to a character
*/
char boardFieldToChar(field_t boardField) {
	switch (boardField) {
	case PIECE: return 'O';
	case EMPTY: return '.';
	case BORDER: return ' ';
	default: return 'X';
	}
}