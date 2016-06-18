#ifndef WinnerCombination_h__
#define WinnerCombination_h__

#include <string>

namespace GameLogic
{
	static const char* winnerCombination [] =
	{
		"012", "345", "678",
		"036", "147", "258",
		"048", "246", "489"
	};

	static const unsigned int countWinnerCombination = 9;

/*	static const std::string line1 = "012";
	static const std::string line2 = "345";
	static const std::string line3 = "678";
	
	static const std::string column1 = "036";
	static const std::string column2 = "147";
	static const std::string column3 = "258";

	static const std::string diagonal1 = "048";
	static const std::string diagonal12 = "246";
	static const std::string diagonal13 = "489";*/
}

#endif // WinnerCombination_h__