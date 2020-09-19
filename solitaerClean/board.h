#pragma once

static const pos_t BORDER_SIZE = 1;
static const pos_t HEIGHT_WITHOUT_BORDER = 7;
static const pos_t ROW_SIZE_WITHOUT_BORDER = 7;
static const pos_t ROW_SIZE = ROW_SIZE_WITHOUT_BORDER + BORDER_SIZE;
static const pos_t HEIGHT = HEIGHT_WITHOUT_BORDER + 2 * BORDER_SIZE;
static const pos_t BOARD_SIZE = ROW_SIZE * HEIGHT;
static const pos_t NORTH = ROW_SIZE;
static const pos_t SOUTH = -NORTH;
static const pos_t EAST = 1;
static const pos_t WEST = -EAST;
typedef Pos<ROW_SIZE, BORDER_SIZE> BoardPos;


class Board {
public:
	Board(std::string initializer) {
		init(initializer);
	}

   /**
	* sets a move
	* @param from one dimensional board position
	* @param direction direction of the move
	*/
	void doMove(Move move) {
		set(move.getPos(), EMPTY);
		set(move.getPos() + move.getDir(), EMPTY);
		set(move.getPos() + move.getDir() * 2, PIECE);
		pieceAmount--;
	}

	/**
	 * checks, if a move is valid
	 * @param move move to check
	 */
	bool isValidMove(Move move) const {
		return
			get(move.getPos()) == PIECE &&
			get(move.getPos() + move.getDir()) == PIECE &&
			get(move.getPos() + 2 * move.getDir()) == EMPTY;
	}

	/**
	* Checks, if the current board is a success
	* One piece is left
	* @param perfectSolution true, if a perfect solution is required
	*/
	bool isSuccess(bool perfectSolution) const {
		return (pieceAmount == 1) && (!perfectSolution || (get(lastPinPos) == PIECE));
	}


	/**
	* Prints the board
	*/
	void print(Move nextMove = Move()) const {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		BoardPos moveStartPos = nextMove.getPos();
		BoardPos moveInbetween = moveStartPos + nextMove.getDir();
		BoardPos moveTargetPos = moveStartPos + 2 * nextMove.getDir();
		for (pos_t y = HEIGHT_WITHOUT_BORDER - 1; y >= 0; y--) {
			for (pos_t x = 0; x < ROW_SIZE_WITHOUT_BORDER; x++) {
				BoardPos curPos = BoardPos(x, y);
				if (moveStartPos == curPos || moveInbetween == curPos || moveTargetPos == curPos) {
					SetConsoleTextAttribute(hConsole, 10);
				}
				else {
					SetConsoleTextAttribute(hConsole, 7);
				}
				std::cout << boardFieldToChar(get(curPos));
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	/**
	 * Sets the required pos of the last pin
	 */
	void setLastPinPos(BoardPos pos) {
		lastPinPos = pos;
	}

	void set(BoardPos pos, field_t value) {
		boardFields[pos] = value;
	}

	field_t get(BoardPos pos) const {
		return boardFields[pos];
	}

private:

	/**
	* Initializes the board by a string
	*/
	void init(std::string boardString) {
		boardFields.fill(BORDER);
		pieceAmount = 0;
		int charPos = 0;
		for (pos_t y = HEIGHT_WITHOUT_BORDER - 1; y >= 0; y--) {
			for (pos_t x = 0; x < ROW_SIZE_WITHOUT_BORDER; x++) {
				BoardPos curPos = BoardPos(x, y);
				field_t field = charToBoardField(boardString[charPos]);
				set(curPos, field);
				if (field == PIECE) {
					pieceAmount++;
				}
				if (field == EMPTY) {
					setLastPinPos(curPos);
				}
				charPos++;
			}
		}
	}


private:
	std::array<field_t, BOARD_SIZE> boardFields;
	int pieceAmount;
	BoardPos lastPinPos;

};
