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
	checkAlphabet("ABC", "ABC", checker.MAX_SCORE_ALPHA);
	checkAlphabet("ABC", "ABCBA", checker.MAX_SCORE_ALPHA);
	checkAlphabet("ABCAB", "ABC", checker.MAX_SCORE_ALPHA);
	checkAlphabet("A", "AAA", checker.MAX_SCORE_ALPHA);
}

TEST_F(SimilarityCheckFixture, AlphaScore_Score0) {
	checkAlphabet("ABC", "DEF", 0);
}

TEST_F(SimilarityCheckFixture, AlphaScore_ScorePartial) {
	checkAlphabet("ABCD", "DB", checker.MAX_SCORE_ALPHA / 4 * 2);
	checkAlphabet("ABD", "DC", checker.MAX_SCORE_ALPHA / 4 * 1);
	checkAlphabet("ABDC", "ADC", checker.MAX_SCORE_ALPHA / 4 * 3);
	checkAlphabet("ABDCE", "A", checker.MAX_SCORE_ALPHA / 5 * 1);
	checkAlphabet("ABDCE", "AB", checker.MAX_SCORE_ALPHA / 5 * 2);
	checkAlphabet("ABDCE", "ACB", checker.MAX_SCORE_ALPHA / 5 * 3);
	checkAlphabet("ABDCE", "ADCB", checker.MAX_SCORE_ALPHA / 5 * 4);
}