#include "pch.h"
#include "../SimilarityChecker/checker.cpp"

class SimilarityCheckFixture : public testing::Test {
public:
	SimilarityChecker checker;

	void checkValidity(string str1, string str2) {
		try {
			checker.setStrings(str1, str2);
			checker.checkAlpha();
			FAIL();
		}
		catch (invalid_argument e) {
			// PASS
		}
	}

	void checkAlphabet(string str1, string str2, int expectScore) {
		checker.setStrings(str1, str2);
		int score = checker.checkAlpha();
		EXPECT_EQ(score, expectScore);
	}
};

TEST_F(SimilarityCheckFixture, AlphaScore_InvalidInput_LowerCase) {
	checkValidity("abc", "edf");
	checkValidity("ABC", "EDf");
	checkValidity("ABc", "EDF");
	checkValidity("ABc", "EDF");
};

TEST_F(SimilarityCheckFixture, AlphaScore_InvalidInput_NonAlpha) {
	checkValidity("123", "EDF");
	checkValidity("ABC", "123");
	checkValidity("AB!", "DEF");
	checkValidity("ABC", "D(F");
	checkValidity("AB,", "D'F");
}

TEST_F(SimilarityCheckFixture, AlphaScore_ScoreMax) {
	checkAlphabet("ABC", "ABC", 40);
	checkAlphabet("ABC", "ABCBA", 40);
	checkAlphabet("ABCAB", "ABC", 40);
	checkAlphabet("A", "AAA", 40);
}