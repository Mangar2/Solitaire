#pragma once

class Statistic {
public:
	Statistic() {
	}

	void reset() {
		movesSearched = 0;
		solutionsFound = 0;
		timeControl.StoreStartTime();
	}

	/**
	* Prints a search statistic
	*/
	void print(bool verbose = false) {
		movesSearched++;
		if (movesSearched % 10000000ULL == 0 || verbose) {
			std::cout << movesSearched << " moves searched" << std::endl;
			std::cout << solutionsFound << " solutions found" << std::endl;
			uint64_t timeDiff = timeControl.GetCurrentTimeDiff();
			uint64_t secondsSearched = timeDiff / 1000;
			uint64_t millis = timeDiff % 1000;
			uint64_t positionsPerSecond = timeDiff > 0 ? (movesSearched * 1000ULL) / timeDiff : 0;
			std::cout << secondsSearched << "." << millis << " seconds searched (" << positionsPerSecond << " positions per second)" << std::endl << std::endl;
		}
	}

	StdTimeControl timeControl;
	uint64_t movesSearched;
	uint64_t solutionsFound;
};