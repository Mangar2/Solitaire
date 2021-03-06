// solitaerClean.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StdTimeControl.h"
#include "pos.h"
#include "field.h"
#include "move.h"
#include "boardinitializer.h"
#include "board.h"
#include "statistic.h"

enum solution : bool { 
	perfect = true, 
	ordinary = false 
};
typedef std::array<BoardPos, 4> directions_t;

class Search {

public:
	Search(Board board, directions_t directions) 
		: _startBoard(board), _directions(directions), _perfectSolution(false), _stop(false)
	{}

	/**
	 * Start the search for a soltuion
	 */
	void start(bool perfectSolution) {
		_perfectSolution = perfectSolution;
		_stop = false;
		_statistic.reset();
		searchBoardRec(_startBoard, 0);
	}

    /**
     * tries all moves in the current board position
     */
	void searchBoardRec(Board& board, int depth = 0) {
		for (BoardPos pos = BoardPos(0, 0); pos <= BoardPos(6, 6); pos++) {
			/*
			if (board.get(pos) != PIECE) {
				continue;
			}
			*/
			for (auto& dir : _directions) {
				if (_stop) {
					return;
				}
				const Move move(pos, dir);
				if (board.isValidMove(move)) {
					searchMove(board, move, depth);
				}
			}
		}
	}

private:
	/**
	 * Prints the solution
	 */
	void printSolution(int depth) {
		Board solutionBoard = _startBoard;
		solutionBoard.print(_moves[0]);
		for (uint64_t i = 0; i <= depth; i++) {
			solutionBoard.doMove(_moves[i]);
			solutionBoard.print(_moves[i + 1]);
		}
	}

	/**
	 * Stores the current move in a list of moves from start position
	 */
	void storeMove(Move move, int depth) {
		_moves[depth] = move;
	}

    /**
     * Sets the move and searches the position after the move
	 * @param board solitaire board
	 * @param move move to set to the board
	 * @param depth search depth (amount of moves made from starting position)
     */
	void searchMove(Board board, Move move, int depth) {
		_statistic.print();
		board.doMove(move);
		storeMove(move, depth);
		// board.print(move);

		if (board.isSuccess(_perfectSolution)) {
			_statistic.solutionsFound++;
			if (_statistic.solutionsFound == 1) {
				// printSolution(depth);
				_statistic.print(true);
				// _stop = true;
			}
		}
		searchBoardRec(board, depth + 1);
	}

	Statistic _statistic;
	std::array<Move, 64> _moves;
	Board _startBoard;
	directions_t _directions;
	bool _perfectSolution;
	bool _stop;
};

int main()
{
	directions_t searchOrder = { EAST, NORTH, WEST, SOUTH }; // { SOUTH, EAST, NORTH, WEST } 

	Board board(englishBoard);
	board.setLastPinPos(BoardPos(3, 3));
	Search search(board, searchOrder);
	search.start(solution::perfect);
    return 0;
}



